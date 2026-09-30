use num_traits::{Num, WrappingAdd};
use std::fmt::Debug;

/// Trait that the field types defined in CompressedCapability (Length, Offset, Addr) have to implement.
/// This asserts that a) they're numeric, b) they support Default/Copy/Clone/Debug so that CcxCap can derive these.
pub trait NumType: Default + Num + WrappingAdd + Copy + Clone + Debug + PartialOrd + Ord {}
impl NumType for u32 {}
impl NumType for u64 {}
impl NumType for u128 {}
impl NumType for i32 {}
impl NumType for i64 {}
impl NumType for i128 {}

/// Value which can be converted to T (a NumType).
/// Must also be Default/Copy/Clone/Debug, so CcxCap can derive these.
pub trait FfiNumType<T>: Default + Copy + Clone + Debug + Into<T> + From<T> {}
impl FfiNumType<u64> for u64 {}
impl FfiNumType<i64> for i64 {}
/// We assume the C representation of `u128` is identical to the Rust representation.
/// See [crate::c_funcs] documentation.
impl FfiNumType<u128> for u128 {}
/// We assume the C representation of `i128` is identical to the Rust representation.
/// See [crate::c_funcs] documentation.
impl FfiNumType<i128> for i128 {}

/// Trait defining an Rust version of the public API for a specific capability type.
/// A type X implementing CompressedCapability is equivalent to the API provided by `cheri_compressed_cap_X.h` in C,
/// where `ccx_cap_t` is equivalent to [CcxCap].
///
/// It is not recommended to call the trait functions directly.
/// Instead, use one of the [crate::wrappers].
pub trait CompressedCapability: Sized + Copy + Clone {
    /// ccx_length_t Rust-land equivalent - should be a superset of Addr
    type Length: NumType + From<Self::Addr>;
    /// ccx_offset_t Rust-land equivalent - should be a superset of Addr
    type Offset: NumType + From<Self::Addr>;
    /// ccx_addr_t equivalent
    type Addr: NumType + Into<Self::Offset> + Into<Self::Length>;

    /// ccx_length_t C-land equivalent - should have a memory layout identical to the C ccx_length_t.
    /// This is separate from Length because for 128-bit types the Rust and C versions may not look the same.
    /// In practice, we just assume they are the same (see [crate::c_funcs] documentation).
    type FfiLength: FfiNumType<Self::Length>;
    /// ccx_offset_t C-land equivalent - should have a memory layout identical to the C ccx_offset_t.
    /// See [Self::FfiLength] for an explanation.
    type FfiOffset: FfiNumType<Self::Offset>;

    /// CCX_PERM_GLOBAL equivalent
    /// These are the same for 64 and 128bit, but should be overridden for Morello-128
    const PERM_GLOBAL: u32 = (1 << 0);
    const PERM_EXECUTE: u32 = (1 << 1);
    const PERM_LOAD: u32 = (1 << 2);
    const PERM_STORE: u32 = (1 << 3);
    const PERM_LOAD_CAP: u32 = (1 << 4);
    const PERM_STORE_CAP: u32 = (1 << 5);
    const PERM_STORE_LOCAL: u32 = (1 << 6);
    const PERM_SEAL: u32 = (1 << 7);
    const PERM_CINVOKE: u32 = (1 << 8);
    const PERM_UNSEAL: u32 = (1 << 9);
    const PERM_ACCESS_SYS_REGS: u32 = (1 << 10);
    const PERM_SETCID: u32 = (1 << 11);

    const MAX_REPRESENTABLE_OTYPE: u32;
    /// CCX_OTYPE_UNSEALED equivalent
    const OTYPE_UNSEALED: u32;
    const OTYPE_SENTRY: u32;
    const OTYPE_RESERVED2: u32;
    const OTYPE_RESERVED3: u32;
    const MAX_UNRESERVED_OTYPE: u32;

    // Adapted, Rust-safe version of the C API
    // Should be defined by building a wrapper around a linked C function

    /// Generate the `pesbt` bits for a capability (the top bits, which encode permissions, object type, compressed bounds, etc.)
    /// This transformation can be undone with [Self::decompress_raw].
    ///
    /// This is presumably intended for storing compressed capabilities in e.g. registers.
    /// Its counterpart for storing compressed capabilities in memory is [Self::compress_mem].
    fn compress_raw(src_cap: &CcxCap<Self>) -> Self::Addr;

    /// Decompress a (pesbt, cursor) pair into a capability.
    /// This transformation can be undone with [Self::compress_raw].
    fn decompress_raw(pesbt: Self::Addr, cursor: Self::Addr, tag: bool) -> CcxCap<Self>;

    /// Generate the `pesbt` bits for a capability (the top bits, which encode permissions, object type, compressed bounds, etc.)
    /// This transformation can be undone with [Self::decompress_mem].
    ///
    /// This is presumably intended for storing compressed capabilities in memory.
    /// It is equivalent to calling [Self::compress_raw] and XOR-ing the result with a "null mask".
    /// Presumably this transformation prevents all-zero data from being interpreted as a capability?
    fn compress_mem(src_cap: &CcxCap<Self>) -> Self::Addr;

    /// Decompress a (pesbt, cursor) pair into a capability.
    /// This transformation can be undone with [Self::compress_mem].
    ///
    /// This is equivalent to XOR-ing the pesbt with a "null mask" and calling [Self::decompress_raw].
    /// Presumably the null mask prevents all-zero data from being interpreted as a capability?
    fn decompress_mem(pesbt: Self::Addr, cursor: Self::Addr, tag: bool) -> CcxCap<Self>;

    /* Getters */

    /// Gets the user/software-defined permissions from the [CcxCap::cr_pesbt] field
    ///
    /// Counterpart: [Self::update_uperms]
    fn get_uperms(cap: &CcxCap<Self>) -> u32;

    /// Gets the hardware-defined permissions from the [CcxCap::cr_pesbt] field
    ///
    /// Counterpart: [Self::update_perms]
    fn get_perms(cap: &CcxCap<Self>) -> u32;

    /// Gets the object type from the [CcxCap::cr_pesbt] field
    ///
    /// Counterpart: [Self::update_otype]
    fn get_otype(cap: &CcxCap<Self>) -> u32;

    /// Gets the reserved bits from the [CcxCap::cr_pesbt] field
    ///
    /// Counterpart: [Self::update_reserved]
    fn get_reserved(cap: &CcxCap<Self>) -> u8;

    /// Gets the flags from the [CcxCap::cr_pesbt] field
    ///
    /// Counterpart: [Self::update_flags]
    fn get_flags(cap: &CcxCap<Self>) -> u8;

    /*
    Updaters

    The C API updaters all use Self::Addr for the type of `value`.
    I've changed these to use the types from corresponding `get` functions.
    */

    /// Updates the user/software-defined permissions field in [CcxCap::cr_pesbt]
    ///
    /// Counterpart: [Self::get_uperms]
    fn update_uperms(cap: &mut CcxCap<Self>, value: u32);

    /// Updates the hardware-defined permissions field in [CcxCap::cr_pesbt]
    ///
    /// Counterpart: [Self::get_perms]
    fn update_perms(cap: &mut CcxCap<Self>, value: u32);

    /// Updates the object type field in [CcxCap::cr_pesbt]
    ///
    /// Counterpart: [Self::get_otype]
    fn update_otype(cap: &mut CcxCap<Self>, value: u32);

    /// Updates the reserved field in [CcxCap::cr_pesbt]
    ///
    /// Counterpart: [Self::get_reserved]
    fn update_reserved(cap: &mut CcxCap<Self>, value: u8);

    /// Updates the flags field in [CcxCap::cr_pesbt]
    ///
    /// Counterpart: [Self::get_flags]
    fn update_flags(cap: &mut CcxCap<Self>, value: u8);

    /* Misc */

    /// Extracts the floating-point encoded bounds from [CcxCap::cr_pesbt]
    fn extract_bounds_bits(pesbt: Self::Addr) -> CcxBoundsBits;

    /// Sets the capability bounds to bounds that encompass ((cursor), (cursor+req_len)).
    /// Because a floating-point representation is used for bounds, it may not be able to set (req_base, req_top) exactly.
    /// In this case it will return False.
    ///
    /// Updates [CcxCap::cr_pesbt], [CcxCap::_cr_top], [CcxCap::cr_base]
    fn set_bounds(cap: &mut CcxCap<Self>, req_len: Self::Length) -> bool;

    /// Check if the range ([CcxCap::cr_base], [CcxCap::_cr_top]) can be encoded exactly with the floating-point encoding
    fn is_representable_cap_exact(cap: &CcxCap<Self>) -> bool;

    /// Check if a capability with the parameters `sealed, base, length, cursor` would be representable if the cursor were updated to `new_cursor`.
    fn is_representable_new_addr(
        sealed: bool,
        base: Self::Addr,
        length: Self::Length,
        cursor: Self::Addr,
        new_cursor: Self::Addr,
    ) -> bool;

    /// Generate a capability for `base, top, cursor` with the maximum available permissions.
    /// Panics if the bounds are not exactly representable
    fn make_max_perms_cap(base: Self::Addr, cursor: Self::Addr, top: Self::Length) -> CcxCap<Self>;

    /// Get the minimum representable length greater than or equal to `length`.
    ///
    /// If `get_representable_length(l) == l` then bounds of length `l` are exactly representable (if properly aligned).
    ///
    /// See also [Self::get_required_alignment], [Self::get_alignment_mask].
    fn get_representable_length(length: Self::Length) -> Self::Length;

    /// Get the alignment required for bounds of some `length` to be exactly represented.
    ///
    /// See also [Self::get_representable_length], [Self::get_alignment_mask].
    fn get_required_alignment(length: Self::Length) -> Self::Length;

    /// Get a mask which aligns a bounds of some `length` to be exactly representable.
    ///
    /// See also [Self::get_representable_length], [Self::get_required_alignment].
    fn get_alignment_mask(length: Self::Length) -> Self::Length;
}

#[repr(C, align(16))]
#[derive(Copy, Clone)]
/// Structure matching the C type `_cc_N(cap)`.
/// Field order and layout is binary-compatible with the C version,
/// assuming the C preprocessor macro `_CC_REVERSE_PESBT_CURSOR_ORDER` is *not* defined.
///
/// This is a plain-old-data type. It only supplies getters and setters, and does *not* guarantee any safety/correctness.
/// For example, there are no added assertions or checks if you set the cursor to a value outside the bounds.
/// However, the C FFI functions from [CompressedCapability] may have their own asserts.
/// These are documented where possible.
///
/// *For a safe interface, use one of the [crate::wrappers]*
pub struct CcxCap<T: CompressedCapability> {
    /// The bottom half of the capability as stored in memory.
    ///
    /// If [Self::cr_tag] is 1, this is the capability's "cursor" i.e. the address it's actually pointing to.
    _cr_cursor: T::Addr,

    /// The top half of the capability as stored in memory.
    ///
    /// If [Self::cr_tag] is 1, this is the compressed capability metadata (permissions, otype, bounds, etc.).
    cr_pesbt: T::Addr,

    /// The top of this capability's valid address range.
    /// Derived from [Self::cr_pesbt].
    /// As long as [Self::cr_tag] is 1, the getter/setter will ensure it matches.
    _cr_top: T::FfiLength,
    /// The base of this capability's valid address range.
    /// Derived from [Self::cr_pesbt].
    /// As long as [Self::cr_tag] is 1, the getter/setter will ensure it matches.
    cr_base: T::Addr,
    /// Tag - if 1, this is a valid capability, 0 it's just plain data
    cr_tag: u8,
    /// 0 (false) if the bounds decode step was given an invalid capability.
    /// Should be 1 (true) for all non-Morello capabilities.
    cr_bounds_valid: u8,
    /// The exponent used for storing the bounds.
    /// Stored from various places, only used in Morello-exclusive function cap_bounds_uses_value().
    cr_exp: u8,
    /// "Additional data stored by the caller."
    /// Seemingly completely unused, essentially padding.
    cr_extra: u8,
}

/// Implements getters and setters similar to the C++-only member functions in the header.
impl<T: CompressedCapability> CcxCap<T> {
    /// Returns a `(tag, [cursor, pesbt])` tuple that represents all data required to
    /// store a capability in a register.
    ///
    /// To store capabilities in memory, see [Self::mem_representation]
    pub fn reg_representation(&self) -> (bool, [T::Addr; 2]) {
        // This should be equal to self.cr_pesbt, the compress_raw function just returns that.
        // We use this function in case that behaviour changes in the future, and for consistency with mem_representation.
        let compressed_pesbt = T::compress_raw(self);
        (self.tag(), [self._cr_cursor, compressed_pesbt])
    }

    /// Returns a `(tag, [cursor, pesbt])` tuple that represents all data required to
    /// store a capability in memory.
    ///
    /// To store capabilities in a register, see [Self::reg_representation]
    pub fn mem_representation(&self) -> (bool, [T::Addr; 2]) {
        // This should be equal to (self.cr_pesbt ^ SOME_XOR_MASK)
        let compressed_pesbt = T::compress_mem(self);
        (self.tag(), [self._cr_cursor, compressed_pesbt])
    }

    pub fn tag(&self) -> bool {
        // cr_tag is interpreted as a boolean with C rules
        self.cr_tag != 0
    }
    pub fn set_tag(&mut self, tag: bool) {
        self.cr_tag = if tag { 1 } else { 0 };
    }

    pub fn base(&self) -> T::Addr {
        self.cr_base
    }
    pub fn top(&self) -> T::Length {
        self._cr_top.into()
    }
    pub fn bounds(&self) -> (T::Addr, T::Length) {
        (self.base(), self.top())
    }
    /// Sets the base and top of this capability using C FFI function [CompressedCapability::set_bounds].
    /// Updates the PESBT field correspondingly.
    /// Zeroes tag if out of bounds.
    /// On non-Morello platforms, will fail with an assertion error if [Self::tag()] is not set.
    pub fn set_bounds_unchecked(&mut self, req_len: T::Length) -> bool {
        T::set_bounds(self, req_len)
    }

    pub fn extract_bounds_bits(&self) -> CcxBoundsBits {
        T::extract_bounds_bits(self.cr_pesbt)
    }

    pub fn address(&self) -> T::Addr {
        self._cr_cursor
    }
    pub fn set_address_unchecked(&mut self, addr: T::Addr) {
        self._cr_cursor = addr;
    }

    pub fn offset(&self) -> T::Offset {
        let cursor: T::Offset = self._cr_cursor.into();
        let base: T::Offset = self.cr_base.into();
        (cursor - base).into()
    }
    // TODO top64

    pub fn length(&self) -> T::Length {
        let top: T::Length = self._cr_top.into();
        let base: T::Length = self.cr_base.into();
        (top - base).into()
    }
    // TODO length64

    pub fn software_permissions(&self) -> u32 {
        T::get_uperms(self)
    }
    pub fn set_software_permissions(&mut self, uperms: u32) {
        T::update_uperms(self, uperms)
    }

    pub fn permissions(&self) -> u32 {
        T::get_perms(self)
    }
    pub fn set_permissions(&mut self, perms: u32) {
        T::update_perms(self, perms)
    }

    pub fn otype(&self) -> u32 {
        T::get_otype(self)
    }
    pub fn is_sealed(&self) -> bool {
        self.otype() != T::OTYPE_UNSEALED
    }
    pub fn set_otype(&mut self, otype: u32) {
        T::update_otype(self, otype)
    }

    pub fn reserved_bits(&self) -> u8 {
        T::get_reserved(self)
    }
    pub fn set_reserved_bits(&mut self, bits: u8) {
        T::update_reserved(self, bits)
    }

    pub fn flags(&self) -> u8 {
        T::get_flags(self)
    }
    pub fn set_flags(&mut self, flags: u8) {
        T::update_flags(self, flags)
    }

    /// Helper function for easily calling FFI function [CompressedCapability::is_representable_cap_exact]
    /// on this capability.
    /// Assertions are present in the C code, but should never be triggered.
    pub fn is_exact(&self) -> bool {
        T::is_representable_cap_exact(self)
    }
    /// Helper function for easily calling FFI function [CompressedCapability::is_representable_new_addr]
    /// on this capability.
    /// Assertions are present in the C code, but should never be triggered.
    pub fn is_representable_with_new_addr(&self, new_addr: T::Addr) -> bool {
        T::is_representable_new_addr(
            self.is_sealed(),
            self.base(),
            self.length(),
            self.address(),
            new_addr,
        )
    }
}
/// Implements `operator==` from cheri_compressed_cap_common.h
impl<T: CompressedCapability> PartialEq for CcxCap<T> {
    fn eq(&self, other: &Self) -> bool {
        self.cr_tag == other.cr_tag
            && self._cr_cursor == other._cr_cursor
            && self.cr_pesbt == other.cr_pesbt
    }
}
impl<T: CompressedCapability> Eq for CcxCap<T> {}
/// Equivalent to initialization pattern used in tests:
/// ```c
/// ccx_cap_t value;
/// memset(&value, 0, sizeof(value));
/// ```
///
/// cc64.rs doesn't pick it up when it was automatically #[derive]-d, so it's manually implemented here
impl<T: CompressedCapability> Default for CcxCap<T> {
    fn default() -> Self {
        CcxCap {
            // Use Default::default for the associated types (Addr, Length, Offset)
            // Rust doesn't have enough information to know they are numbers
            _cr_cursor: Default::default(),
            cr_pesbt: Default::default(),
            _cr_top: Default::default(),
            cr_base: Default::default(),
            cr_tag: 0,
            cr_bounds_valid: 0,
            cr_exp: 0,
            cr_extra: 0,
        }
    }
}
/// Debug printer for capabilities that decodes the PESBT field instead of printing it raw.
impl<T: CompressedCapability> Debug for CcxCap<T> {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        f.debug_struct("CcxCap")
            .field("cr_cursor", &self._cr_cursor)
            .field("cr_base", &self.cr_base)
            .field("cr_top", &self._cr_top)
            .field("cr_tag", &self.cr_tag)
            .field("cr_bounds_valid", &self.cr_bounds_valid)
            .field("cr_exp", &self.cr_exp)
            .field("cr_extra", &self.cr_extra)
            .field("permissions", &self.permissions())
            .field("software_permissions", &self.software_permissions())
            .field("otype", &self.otype())
            .field("reserved_bits", &self.reserved_bits())
            .field("flags", &self.flags())
            .finish()
    }
}

/// Structure matching the C type `_cc_N(bounds_bits)`.
/// Represents a floating-point encoded capability bounds.
#[repr(C)]
#[derive(Debug, Clone, Copy)]
pub struct CcxBoundsBits {
    pub b: u16,
    pub t: u16,
    pub e: u8,
    pub ie: bool,
}

// Link the C functions
mod c_funcs;

pub mod caps;

pub mod wrappers;

#[cfg(test)]
mod tests {
    use crate::CompressedCapability;
    // TODO port some tests from the C tests?
    #[test]
    fn test_printing() {
        let cap = crate::caps::cheriv9::cc64::Cc64::decompress_raw(0, 0, false);
        println!("{:?}", cap);

        let cap = crate::caps::cheriv9::cc128::Cc128::decompress_raw(0, 0, false);
        println!("{:?}", cap);
        dbg!(cap.is_exact());
    }

    #[test]
    fn test_cc128_u128_conversion() {
        // Generate a capability between 0, 0x1_0000_0000_0000_0000 with the current cursor/address at 0x100
        // When we get the 128-bit top(), it should be the same as the one we specified.
        // If it isn't, the memory representation of FfiU128 and the C u128 may be different

        let base: u64 = 0x1000_0000_0000;
        let top: u128 = 0x2000_0000_0000;
        let cap = crate::caps::cheriv9::cc128::Cc128::make_max_perms_cap(base, base, top);
        assert_eq!(cap.top(), top);
        assert_eq!(cap._cr_top, top);
        // cr_base is stored directly after _cr_top, so if the sizes for FfiU128 and C u128 are different it will have been overwritten
        assert_eq!(cap.cr_base, base);
    }
}
