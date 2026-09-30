macro_rules! ccap_impl_funcs {
    ($ver:ident) => { paste! {
        fn compress_raw(cap: &Cap) -> Addr {
            unsafe { [<$ver _compress_raw>](cap) }
        }
        fn decompress_raw(pesbt: Addr, cursor: Addr, tag: bool) -> Cap {
            let mut cap = Default::default();
            unsafe { [<$ver _decompress_raw>](pesbt, cursor, tag, &mut cap) };
            cap
        }
        fn compress_mem(cap: &Cap) -> Addr {
            unsafe { [<$ver _compress_mem>](cap) }
        }
        fn decompress_mem(pesbt: Addr, cursor: Addr, tag: bool) -> Cap {
            let mut cap = Default::default();
            unsafe { [<$ver _decompress_mem>](pesbt, cursor, tag, &mut cap) };
            cap
        }

        /* Getters */
        fn get_uperms(cap: &Cap) -> u32 {
            unsafe { [<$ver _get_uperms>](cap) }
        }
        fn get_perms(cap: &Cap) -> u32 {
            unsafe { [<$ver _get_perms>](cap) }
        }
        fn get_otype(cap: &Cap) -> u32 {
            unsafe { [<$ver _get_otype>](cap) }
        }
        fn get_reserved(cap: &Cap) -> u8 {
            unsafe { [<$ver _get_reserved>](cap) }
        }
        fn get_flags(cap: &Cap) -> u8 {
            unsafe { [<$ver _get_flags>](cap) }
        }

        /* Updaters */
        fn update_uperms(cap: &mut Cap, value: u32) {
            unsafe { [<$ver _update_uperms>](cap, value as Self::Addr) }
        }
        fn update_perms(cap: &mut Cap, value: u32) {
            unsafe { [<$ver _update_perms>](cap, value as Self::Addr) }
        }
        fn update_otype(cap: &mut Cap, value: u32) {
            unsafe { [<$ver _update_otype>](cap, value as Self::Addr) }
        }
        fn update_reserved(cap: &mut Cap, value: u8) {
            unsafe { [<$ver _update_reserved>](cap, value as Self::Addr) }
        }
        fn update_flags(cap: &mut Cap, value: u8) {
            unsafe { [<$ver _update_flags>](cap, value as Self::Addr) }
        }

        /* Misc */
        fn extract_bounds_bits(pesbt: Self::Addr) -> CcxBoundsBits {
            unsafe { [<$ver _extract_bounds_bits>](pesbt) }
        }
        fn set_bounds(cap: &mut Cap, req_len: Self::Length) -> bool {
            unsafe { [<$ver _setbounds>](cap, req_len) }
        }
        fn is_representable_cap_exact(cap: &Cap) -> bool {
            unsafe { [<$ver _is_representable_cap_exact>](cap) }
        }
        fn is_representable_new_addr(sealed: bool, base: Self::Addr, length: Self::Length, cursor: Self::Addr, new_cursor: Self::Addr) -> bool {
            unsafe { [<$ver _is_representable_new_addr>](sealed, base, length, cursor, new_cursor) }
        }
        fn make_max_perms_cap(base: Self::Addr, cursor: Self::Addr, top: Self::Length) -> Cap {
            unsafe { [<$ver _make_max_perms_cap>](base, cursor, top) }
        }
        fn get_representable_length(length: Self::Length) -> Self::Length {
            unsafe { [<$ver _get_representable_length>](length) }
        }
        fn get_required_alignment(length: Self::Length) -> Self::Length {
            unsafe { [<$ver _get_required_alignment>](length) }
        }
        fn get_alignment_mask(length: Self::Length) -> Self::Length {
            unsafe { [<$ver _get_alignment_mask>](length) }
        }
    } }
}


pub mod morello {
    use crate::c_funcs::*;
    use crate::{CcxBoundsBits, CcxCap, CompressedCapability};
    use paste::paste;

    pub type Length = u128;
    pub type Offset = i128;
    pub type FfiLength = u128;
    pub type FfiOffset = i128;
    pub type Addr = u64;

    pub type Cap = CcxCap<Cc128>;
    pub type Cc128Cap = Cap;

    /// Implements [CompressedCapability] for Morello 128-bit capabilities.
    ///
    /// Empty enum, so it cannot be itself constructed. If you want a CC128 capability, instantiate Cc128Cap.
    ///
    /// Derives Debug, Copy, Clone so that CcxCap<Cc128> can derive them too.
    #[derive(Debug, Copy, Clone)]
    pub enum Cc128 {}
    impl CompressedCapability for Cc128 {
        type Length = Length;
        type Offset = Offset;
        type Addr = Addr;

        type FfiLength = FfiLength;
        type FfiOffset = FfiOffset;

        const PERM_GLOBAL: u32 = (1 << 0);
        const PERM_EXECUTE: u32 = (1 << 15);
        const PERM_LOAD: u32 = (1 << 17);
        const PERM_STORE: u32 = (1 << 16);
        const PERM_LOAD_CAP: u32 = (1 << 14);
        const PERM_STORE_CAP: u32 = (1 << 13);
        const PERM_STORE_LOCAL: u32 = (1 << 12);
        const PERM_SEAL: u32 = (1 << 11);
        const PERM_CINVOKE: u32 = (1 << 8);
        const PERM_UNSEAL: u32 = (1 << 10);
        const PERM_ACCESS_SYS_REGS: u32 = (1 << 9);
        const PERM_SETCID: u32 = (1 << 7);

        /// _128m.h:171
        /// encoded directly _128m.h:78
        const MAX_REPRESENTABLE_OTYPE: u32 = ((1u32 << 15)) - 1;
        const OTYPE_UNSEALED: u32 = 0;
        const OTYPE_SENTRY: u32 = 1;
        const OTYPE_RESERVED2: u32 = 2;
        const OTYPE_RESERVED3: u32 = 3;
        const MAX_UNRESERVED_OTYPE: u32 = Self::MAX_REPRESENTABLE_OTYPE;

        ccap_impl_funcs!(cc128m);
    }
}

pub mod cheriv9 {
    //! CHERIv9 Implementations

    pub mod cc64 {
        use crate::c_funcs::*;
        use crate::{CcxBoundsBits, CcxCap, CompressedCapability};
        use paste::paste;

        pub type Length = u64;
        pub type Offset = i64;
        pub type FfiLength = u64;
        pub type FfiOffset = i64;
        pub type Addr = u32;

        pub type Cap = CcxCap<Cc64>;
        pub type Cc64Cap = Cap;

        /// Implements [CompressedCapability] for CHERIv9 64-bit capabilities.
        ///
        /// Empty enum, so it cannot be itself constructed. If you want a CC64 capability, instantiate CC64::Cap.
        ///
        /// Derives Debug, Copy, Clone so that CcxCap<Cc64> can derive them too.
        #[derive(Debug, Copy, Clone)]
        pub enum Cc64 {}
        impl CompressedCapability for Cc64 {
            type Length = Length;
            type Offset = Offset;
            type Addr = Addr;

            type FfiLength = FfiLength;
            type FfiOffset = FfiOffset;

            /// _64.h:126
            const MAX_REPRESENTABLE_OTYPE: u32 = 0b1111;
            const OTYPE_UNSEALED: u32 = Self::MAX_REPRESENTABLE_OTYPE - 0;
            const OTYPE_SENTRY: u32 = Self::MAX_REPRESENTABLE_OTYPE - 1;
            const OTYPE_RESERVED2: u32 = Self::MAX_REPRESENTABLE_OTYPE - 2;
            const OTYPE_RESERVED3: u32 = Self::MAX_REPRESENTABLE_OTYPE - 3;
            const MAX_UNRESERVED_OTYPE: u32 = Self::MAX_REPRESENTABLE_OTYPE;

            ccap_impl_funcs! {cc64}
        }
    }

    pub mod cc128 {
        use crate::c_funcs::*;
        use crate::{CcxBoundsBits, CcxCap, CompressedCapability};
        use paste::paste;

        pub type Length = u128;
        pub type Offset = i128;
        pub type FfiLength = u128;
        pub type FfiOffset = i128;
        pub type Addr = u64;

        pub type Cap = CcxCap<Cc128>;
        pub type Cc128Cap = Cap;

        /// Implements [CompressedCapability] for CHERIv9 128-bit capabilities.
        ///
        /// Empty enum, so it cannot be itself constructed. If you want a CC128 capability, instantiate Cc128Cap.
        ///
        /// Derives Debug, Copy, Clone so that CcxCap<Cc128> can derive them too.
        #[derive(Debug, Copy, Clone)]
        pub enum Cc128 {}
        impl CompressedCapability for Cc128 {
            type Length = Length;
            type Offset = Offset;
            type Addr = Addr;

            type FfiLength = FfiLength;
            type FfiOffset = FfiOffset;

            /// The OTYPE field is 18 bits (108:91) in CC128
            /// _128.h:126
            const MAX_REPRESENTABLE_OTYPE: u32 = 0x3_FFFF;
            const OTYPE_UNSEALED: u32 = Self::MAX_REPRESENTABLE_OTYPE - 0;
            const OTYPE_SENTRY: u32 = Self::MAX_REPRESENTABLE_OTYPE - 1;
            const OTYPE_RESERVED2: u32 = Self::MAX_REPRESENTABLE_OTYPE - 2;
            const OTYPE_RESERVED3: u32 = Self::MAX_REPRESENTABLE_OTYPE - 3;
            const MAX_UNRESERVED_OTYPE: u32 = Self::MAX_REPRESENTABLE_OTYPE - 4;

            ccap_impl_funcs!(cc128);
        }
    }
}

pub mod rvy {
    //! RISC-V Y extension implementations

    pub mod cc64 {
        use crate::c_funcs::*;
        use crate::{CcxBoundsBits, CcxCap, CompressedCapability};
        use paste::paste;

        pub type Length = u64;
        pub type Offset = i64;
        pub type FfiLength = u64;
        pub type FfiOffset = i64;
        pub type Addr = u32;

        pub type Cap = CcxCap<Cc64>;
        pub type Cc64Cap = Cap;

        /// Implements [CompressedCapability] for RISC-V Y 64-bit capabilities.
        ///
        /// Empty enum, so it cannot be itself constructed. If you want a CC64 capability, instantiate CC64::Cap.
        ///
        /// Derives Debug, Copy, Clone so that CcxCap<Cc64> can derive them too.
        #[derive(Debug, Copy, Clone)]
        pub enum Cc64 {}
        impl CompressedCapability for Cc64 {
            type Length = Length;
            type Offset = Offset;
            type Addr = Addr;

            type FfiLength = FfiLength;
            type FfiOffset = FfiOffset;

            // Lots of permissions are missing
            const PERM_GLOBAL: u32 = 0;
            const PERM_EXECUTE: u32 = (1 << 17);
            const PERM_LOAD: u32 = (1 << 18);
            const PERM_STORE: u32 = (1 << 0);
            const PERM_LOAD_CAP: u32 = 0; // encoded with combo of PERM_CAPABILITY and _LOAD
            const PERM_STORE_CAP: u32 = 0; // encoded with combo of PERM_CAPABILITY and _STORE
            const PERM_STORE_LOCAL: u32 = 0;
            const PERM_SEAL: u32 = 0;
            const PERM_CINVOKE: u32 = 0;
            const PERM_UNSEAL: u32 = 0;
            const PERM_ACCESS_SYS_REGS: u32 = 0;
            const PERM_SETCID: u32 = 0;

            /// This is a single bit in RV32Y but CHERIoT does something different not modelled here
            const MAX_REPRESENTABLE_OTYPE: u32 = 0b1;
            const OTYPE_UNSEALED: u32 = 0;
            const OTYPE_SENTRY: u32 = 1;
            const OTYPE_RESERVED2: u32 = u32::MAX;
            const OTYPE_RESERVED3: u32 = u32::MAX;
            const MAX_UNRESERVED_OTYPE: u32 = u32::MAX;

            ccap_impl_funcs! {cc64r}
        }
    }

    pub mod cc128 {
        use crate::c_funcs::*;
        use crate::{CcxBoundsBits, CcxCap, CompressedCapability};
        use paste::paste;

        pub type Length = u128;
        pub type Offset = i128;
        pub type FfiLength = u128;
        pub type FfiOffset = i128;
        pub type Addr = u64;

        pub type Cap = CcxCap<Cc128>;
        pub type Cc128Cap = Cap;

        /// Implements [CompressedCapability] for RISC-V Y 128-bit capabilities.
        ///
        /// Empty enum, so it cannot be itself constructed. If you want a CC128 capability, instantiate Cc128Cap.
        ///
        /// Derives Debug, Copy, Clone so that CcxCap<Cc128> can derive them too.
        #[derive(Debug, Copy, Clone)]
        pub enum Cc128 {}
        impl CompressedCapability for Cc128 {
            type Length = Length;
            type Offset = Offset;
            type Addr = Addr;

            type FfiLength = FfiLength;
            type FfiOffset = FfiOffset;

            // Lots of permissions are missing
            const PERM_GLOBAL: u32 = 0;
            const PERM_EXECUTE: u32 = (1 << 17);
            const PERM_LOAD: u32 = (1 << 18);
            const PERM_STORE: u32 = (1 << 0);
            const PERM_LOAD_CAP: u32 = 0; // encoded with combo of PERM_CAPABILITY and _LOAD
            const PERM_STORE_CAP: u32 = 0; // encoded with combo of PERM_CAPABILITY and _STORE
            const PERM_STORE_LOCAL: u32 = 0;
            const PERM_SEAL: u32 = 0;
            const PERM_CINVOKE: u32 = 0;
            const PERM_UNSEAL: u32 = 0;
            const PERM_ACCESS_SYS_REGS: u32 = 0;
            const PERM_SETCID: u32 = 0;

            /// This is a single bit in RV64Y but there are reserved bits off the top
            const MAX_REPRESENTABLE_OTYPE: u32 = 0b1;
            const OTYPE_UNSEALED: u32 = 0;
            const OTYPE_SENTRY: u32 = 1;
            const OTYPE_RESERVED2: u32 = u32::MAX;
            const OTYPE_RESERVED3: u32 = u32::MAX;
            const MAX_UNRESERVED_OTYPE: u32 = u32::MAX;

            ccap_impl_funcs!(cc128r);
        }
    }
}

pub mod cheri256 {
    pub type Length = u128;
    pub type Offset = u64;
    pub type FfiLength = u64;
    pub type FfiOffset = u64;
    pub type Addr = u64;

    #[repr(C)]
    #[derive(Debug, Copy, Clone)]
    pub struct Cap {
        cr_cursor: u64,
        cr_base: u64,
        cr_length: u64,
        cr_otype: u32,
        cr_perms: u16,
        cr_uperms: u16,
        cr_tag: u8,
        cr_flags: u8,
        cr_reserved: u8,
    }
    impl Cap {
        // TODO in-memory and in-register representations with {de,}compress_256cap() C function
        
        pub const MAX_REPRESENTABLE_OTYPE: u32 = (1u32 << 24) - 1;
        pub const OTYPE_UNSEALED: u32 = Self::MAX_REPRESENTABLE_OTYPE - 0;
        pub const OTYPE_SENTRY: u32 = Self::MAX_REPRESENTABLE_OTYPE - 1;

        pub fn tag(&self) -> bool {
            // cr_tag is interpreted as a boolean with C rules
            self.cr_tag != 0
        }
        pub fn set_tag(&mut self, tag: bool) {
            self.cr_tag = if tag { 1 } else { 0 };
        }

        pub fn base(&self) -> Addr {
            self.cr_base
        }
        pub fn top(&self) -> Length {
            self.cr_base as u128 + self.cr_length as u128
        }
        pub fn bounds(&self) -> (Addr, Length) {
            (self.base(), self.top())
        }
        /// Sets the base and top of this capability using C FFI function [CompressedCapability::set_bounds].
        /// Returns true always, because always representable
        pub fn set_bounds_unchecked(&mut self, req_len: u64) -> bool {
            if self.cr_length < req_len {
                self.cr_tag = 0;
            }
            self.cr_base = self.cr_cursor;
            self.cr_length = req_len;
            true
        }

        pub fn address(&self) -> Addr {
            self.cr_cursor
        }
        pub fn set_address_unchecked(&mut self, addr: Addr) {
            self.cr_cursor = addr;
        }

        pub fn offset(&self) -> Offset {
            let cursor: Offset = self.cr_cursor.into();
            let base: Offset = self.cr_base.into();
            (cursor - base).into()
        }
        // TODO top64

        pub fn length(&self) -> Length {
            self.cr_length.into()
        }
        // TODO length64

        pub fn software_permissions(&self) -> u16 {
            self.cr_uperms
        }
        pub fn set_software_permissions(&mut self, uperms: u16) {
            self.cr_uperms = uperms
        }

        pub fn permissions(&self) -> u16 {
            self.cr_perms
        }
        pub fn set_permissions(&mut self, perms: u16) {
            self.cr_perms = perms
        }

        pub fn otype(&self) -> u32 {
            self.cr_otype
        }
        pub fn is_sealed(&self) -> bool {
            self.otype() != Self::OTYPE_UNSEALED
        }
        pub fn set_otype(&mut self, otype: u32) {
            self.cr_otype = otype
        }

        pub fn reserved_bits(&self) -> u8 {
            self.cr_reserved
        }
        pub fn set_reserved_bits(&mut self, bits: u8) {
            self.cr_reserved = bits
        }

        pub fn flags(&self) -> u8 {
            self.cr_flags
        }
        pub fn set_flags(&mut self, flags: u8) {
            self.cr_flags = flags
        }

        pub fn is_exact(&self) -> bool {
            true
        }
        pub fn is_representable_with_new_addr(&self, new_addr: Addr) -> bool {
            true
        }

        pub fn make_max_perms_cap(base: Addr, cursor: Addr, top: Addr) -> Self {
            Self {
                cr_cursor: cursor,
                cr_base: base,
                cr_length: top - base,
                cr_otype: 0,
                cr_perms: 0,
                cr_uperms: 0,
                cr_tag: if (base <= top) && (base <= cursor) && (cursor <= top) { 1 } else { 0 },
                cr_flags: 0,
                cr_reserved: 0,
            }
        }
    }
}