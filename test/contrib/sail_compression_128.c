#include "sail.h"
#include "rts.h"
#include "elf.h"
void (*sail_rts_set_coverage_file)(const char *) = NULL;
#ifdef __cplusplus
extern "C" {
#endif

// enum write_kind
enum zwrite_kind { zWrite_plain, zWrite_conditional, zWrite_release, zWrite_exclusive, zWrite_exclusive_release, zWrite_RISCV_release, zWrite_RISCV_strong_release, zWrite_RISCV_conditional, zWrite_RISCV_conditional_release, zWrite_RISCV_conditional_strong_release, zWrite_X86_locked };

static bool EQUAL(zwrite_kind)(enum zwrite_kind op1, enum zwrite_kind op2) {
  return op1 == op2;
}

static enum zwrite_kind UNDEFINED(zwrite_kind)(unit u) { return zWrite_plain; }

// enum trans_kind
enum ztrans_kind { zTransaction_start, zTransaction_commit, zTransaction_abort };

static bool EQUAL(ztrans_kind)(enum ztrans_kind op1, enum ztrans_kind op2) {
  return op1 == op2;
}

static enum ztrans_kind UNDEFINED(ztrans_kind)(unit u) { return zTransaction_start; }

// enum read_kind
enum zread_kind { zRead_plain, zRead_reserve, zRead_acquire, zRead_exclusive, zRead_exclusive_acquire, zRead_stream, zRead_ifetch, zRead_RISCV_acquire, zRead_RISCV_strong_acquire, zRead_RISCV_reserved, zRead_RISCV_reserved_acquire, zRead_RISCV_reserved_strong_acquire, zRead_X86_locked };

static bool EQUAL(zread_kind)(enum zread_kind op1, enum zread_kind op2) {
  return op1 == op2;
}

static enum zread_kind UNDEFINED(zread_kind)(unit u) { return zRead_plain; }

// union exception
enum kind_zexception { Kind_z__dummy_exnz3 };

struct zexception {
  enum kind_zexception kind;
  union {struct { unit z__dummy_exnz3; };};
};

static void CREATE(zexception)(struct zexception *op) {
  op->kind = Kind_z__dummy_exnz3;
}

static void RECREATE(zexception)(struct zexception *op) {

}

static void KILL(zexception)(struct zexception *op) {
  {}
}

static void COPY(zexception)(struct zexception *rop, struct zexception op) {
  {};
  rop->kind = op.kind;
  if (op.kind == Kind_z__dummy_exnz3) {
    rop->z__dummy_exnz3 = op.z__dummy_exnz3;
  }
}

static bool EQUAL(zexception)(struct zexception op1, struct zexception op2) {
  if (op1.kind == Kind_z__dummy_exnz3 && op2.kind == Kind_z__dummy_exnz3) {
    return EQUAL(unit)(op1.z__dummy_exnz3, op2.z__dummy_exnz3);
  } else return false;
}

static void sailgen___dummy_exnz3(struct zexception *rop, unit op) {
  {}
  rop->kind = Kind_z__dummy_exnz3;
  rop->z__dummy_exnz3 = op;
}

struct zexception *current_exception = NULL;
bool have_exception = false;
sail_string *throw_location = NULL;

// enum cache_op_kind
enum zcache_op_kind { zCache_op_D_IVAC, zCache_op_D_ISW, zCache_op_D_CSW, zCache_op_D_CISW, zCache_op_D_ZVA, zCache_op_D_CVAC, zCache_op_D_CVAU, zCache_op_D_CIVAC, zCache_op_I_IALLUIS, zCache_op_I_IALLU, zCache_op_I_IVAU };

static bool EQUAL(zcache_op_kind)(enum zcache_op_kind op1, enum zcache_op_kind op2) {
  return op1 == op2;
}

static enum zcache_op_kind UNDEFINED(zcache_op_kind)(unit u) { return zCache_op_D_IVAC; }

// enum a64_barrier_type
enum za64_barrier_type { zA64_barrier_all, zA64_barrier_LD, zA64_barrier_ST };

static bool EQUAL(za64_barrier_type)(enum za64_barrier_type op1, enum za64_barrier_type op2) {
  return op1 == op2;
}

static enum za64_barrier_type UNDEFINED(za64_barrier_type)(unit u) { return zA64_barrier_all; }

// enum a64_barrier_domain
enum za64_barrier_domain { zA64_FullShare, zA64_InnerShare, zA64_OuterShare, zA64_NonShare };

static bool EQUAL(za64_barrier_domain)(enum za64_barrier_domain op1, enum za64_barrier_domain op2) {
  return op1 == op2;
}

static enum za64_barrier_domain UNDEFINED(za64_barrier_domain)(unit u) { return zA64_FullShare; }

// struct EncCapability
struct zEncCapability {
  uint64_t zB;
  uint64_t zT;
  uint64_t zaddress;
  uint64_t zflags;
  fbits zinternal_E;
  uint64_t zotype;
  uint64_t zperms;
  uint64_t zreserved;
};

static void COPY(zEncCapability)(struct zEncCapability *rop, const struct zEncCapability op) {
  rop->zB = op.zB;
  rop->zT = op.zT;
  rop->zaddress = op.zaddress;
  rop->zflags = op.zflags;
  rop->zinternal_E = op.zinternal_E;
  rop->zotype = op.zotype;
  rop->zperms = op.zperms;
  rop->zreserved = op.zreserved;
}

static bool EQUAL(zEncCapability)(struct zEncCapability op1, struct zEncCapability op2) {
  return EQUAL(fbits)(op1.zB, op2.zB) && EQUAL(fbits)(op1.zT, op2.zT) && EQUAL(fbits)(op1.zaddress, op2.zaddress) && EQUAL(fbits)(op1.zflags, op2.zflags) && EQUAL(fbits)(op1.zinternal_E, op2.zinternal_E) && EQUAL(fbits)(op1.zotype, op2.zotype) && EQUAL(fbits)(op1.zperms, op2.zperms) && EQUAL(fbits)(op1.zreserved, op2.zreserved);
}

// enum ClearRegSet
enum zClearRegSet { zGPRegs, zFPRegs };

static bool EQUAL(zClearRegSet)(enum zClearRegSet op1, enum zClearRegSet op2) {
  return op1 == op2;
}

static enum zClearRegSet UNDEFINED(zClearRegSet)(unit u) { return zGPRegs; }

// struct Capability
struct zCapability {
  uint64_t zB;
  uint64_t zE;
  uint64_t zT;
  bool zaccess_system_regs;
  uint64_t zaddress;
  bool zflag_cap_mode;
  bool zglobal;
  bool zinternal_E;
  uint64_t zotype;
  bool zpermit_cinvoke;
  bool zpermit_execute;
  bool zpermit_load;
  bool zpermit_load_cap;
  bool zpermit_seal;
  bool zpermit_set_CID;
  bool zpermit_store;
  bool zpermit_store_cap;
  bool zpermit_store_local_cap;
  bool zpermit_unseal;
  uint64_t zreserved;
  bool ztag;
  uint64_t zuperms;
};

static void COPY(zCapability)(struct zCapability *rop, const struct zCapability op) {
  rop->zB = op.zB;
  rop->zE = op.zE;
  rop->zT = op.zT;
  rop->zaccess_system_regs = op.zaccess_system_regs;
  rop->zaddress = op.zaddress;
  rop->zflag_cap_mode = op.zflag_cap_mode;
  rop->zglobal = op.zglobal;
  rop->zinternal_E = op.zinternal_E;
  rop->zotype = op.zotype;
  rop->zpermit_cinvoke = op.zpermit_cinvoke;
  rop->zpermit_execute = op.zpermit_execute;
  rop->zpermit_load = op.zpermit_load;
  rop->zpermit_load_cap = op.zpermit_load_cap;
  rop->zpermit_seal = op.zpermit_seal;
  rop->zpermit_set_CID = op.zpermit_set_CID;
  rop->zpermit_store = op.zpermit_store;
  rop->zpermit_store_cap = op.zpermit_store_cap;
  rop->zpermit_store_local_cap = op.zpermit_store_local_cap;
  rop->zpermit_unseal = op.zpermit_unseal;
  rop->zreserved = op.zreserved;
  rop->ztag = op.ztag;
  rop->zuperms = op.zuperms;
}

static bool EQUAL(zCapability)(struct zCapability op1, struct zCapability op2) {
  return EQUAL(fbits)(op1.zB, op2.zB) && EQUAL(fbits)(op1.zE, op2.zE) && EQUAL(fbits)(op1.zT, op2.zT) && EQUAL(bool)(op1.zaccess_system_regs, op2.zaccess_system_regs) && EQUAL(fbits)(op1.zaddress, op2.zaddress) && EQUAL(bool)(op1.zflag_cap_mode, op2.zflag_cap_mode) && EQUAL(bool)(op1.zglobal, op2.zglobal) && EQUAL(bool)(op1.zinternal_E, op2.zinternal_E) && EQUAL(fbits)(op1.zotype, op2.zotype) && EQUAL(bool)(op1.zpermit_cinvoke, op2.zpermit_cinvoke) && EQUAL(bool)(op1.zpermit_execute, op2.zpermit_execute) && EQUAL(bool)(op1.zpermit_load, op2.zpermit_load) && EQUAL(bool)(op1.zpermit_load_cap, op2.zpermit_load_cap) && EQUAL(bool)(op1.zpermit_seal, op2.zpermit_seal) && EQUAL(bool)(op1.zpermit_set_CID, op2.zpermit_set_CID) && EQUAL(bool)(op1.zpermit_store, op2.zpermit_store) && EQUAL(bool)(op1.zpermit_store_cap, op2.zpermit_store_cap) && EQUAL(bool)(op1.zpermit_store_local_cap, op2.zpermit_store_local_cap) && EQUAL(bool)(op1.zpermit_unseal, op2.zpermit_unseal) && EQUAL(fbits)(op1.zreserved, op2.zreserved) && EQUAL(bool)(op1.ztag, op2.ztag) && EQUAL(fbits)(op1.zuperms, op2.zuperms);
}

// enum CapEx
enum zCapEx { zCapEx_None, zCapEx_LengthViolation, zCapEx_TagViolation, zCapEx_SealViolation, zCapEx_TypeViolation, zCapEx_UserDefViolation, zCapEx_UnalignedBase, zCapEx_GlobalViolation, zCapEx_PermitExecuteViolation, zCapEx_PermitLoadViolation, zCapEx_PermitStoreViolation, zCapEx_PermitLoadCapViolation, zCapEx_PermitStoreCapViolation, zCapEx_PermitStoreLocalCapViolation, zCapEx_AccessSystemRegsViolation, zCapEx_PermitCInvokeViolation, zCapEx_PermitSetCIDViolation };

static bool EQUAL(zCapEx)(enum zCapEx op1, enum zCapEx op2) {
  return op1 == op2;
}

static enum zCapEx UNDEFINED(zCapEx)(unit u) { return zCapEx_None; }

// enum CPtrCmpOp
enum zCPtrCmpOp { zCEQ, zCNE, zCLT, zCLE, zCLTU, zCLEU, zCEXEQ, zCNEXEQ };

static bool EQUAL(zCPtrCmpOp)(enum zCPtrCmpOp op1, enum zCPtrCmpOp op2) {
  return op1 == op2;
}

static enum zCPtrCmpOp UNDEFINED(zCPtrCmpOp)(unit u) { return zCEQ; }

















static bool sailgen_neq_int(sail_int, sail_int);

static bool sailgen_neq_int(sail_int zx, sail_int zy)
{
  __label__ end_function_1, end_block_exception_2;

  bool zcbz30;
  bool zgaz30;
  zgaz30 = eq_int(zx, zy);
  zcbz30 = not(zgaz30);

end_function_1: ;
  return zcbz30;
end_block_exception_2: ;

  return false;
}

























static bool sailgen_neq_bits(lbits zx, lbits zy)
{
  __label__ end_function_4, end_block_exception_5;

  bool zcbz31;
  bool zgaz31;
  zgaz31 = eq_bits(zx, zy);
  zcbz31 = not(zgaz31);

end_function_4: ;
  return zcbz31;
end_block_exception_5: ;

  return false;
}



































static void sailgen_sail_ones(lbits *rop, sail_int);

static void sailgen_sail_ones(lbits *zcbz32, sail_int zn)
{
  __label__ end_function_7, end_block_exception_8, end_function_208;

  lbits zgaz32;
  CREATE(lbits)(&zgaz32);
  zeros(&zgaz32, zn);
  not_bits((*(&zcbz32)), zgaz32);
  KILL(lbits)(&zgaz32);
end_function_7: ;
  goto end_function_208;
end_block_exception_8: ;
  goto end_function_208;
end_function_208: ;
}







static fbits sailgen_not_bit(fbits);

static fbits sailgen_not_bit(fbits zb)
{
  __label__ end_function_10, end_block_exception_11;

  fbits zcbz33;
  bool zgaz33;
  zgaz33 = eq_bit(zb, UINT64_C(1));
  if (zgaz33) {  zcbz33 = UINT64_C(0);  } else {  zcbz33 = UINT64_C(1);  }

end_function_10: ;
  return zcbz33;
end_block_exception_11: ;

  return UINT64_C(0);
}















static void sailgen_EXTS(lbits *rop, sail_int, lbits);

static void sailgen_EXTZ(lbits *rop, sail_int, lbits);

static void sailgen_EXTS(lbits *zcbz34, sail_int zm, lbits zv)
{
  __label__ end_function_13, end_block_exception_14, end_function_207;

  sign_extend((*(&zcbz34)), zv, zm);
end_function_13: ;
  goto end_function_207;
end_block_exception_14: ;
  goto end_function_207;
end_function_207: ;
}

static void sailgen_EXTZ(lbits *zcbz35, sail_int zm, lbits zv)
{
  __label__ end_function_16, end_block_exception_17, end_function_206;

  zero_extend((*(&zcbz35)), zv, zm);
end_function_16: ;
  goto end_function_206;
end_block_exception_17: ;
  goto end_function_206;
end_function_206: ;
}

static void sailgen_zzeros_implicit(lbits *rop, sail_int);

static void sailgen_zzeros_implicit(lbits *zcbz36, sail_int zn)
{
  __label__ end_function_19, end_block_exception_20, end_function_205;

  zeros((*(&zcbz36)), zn);
end_function_19: ;
  goto end_function_205;
end_block_exception_20: ;
  goto end_function_205;
end_function_205: ;
}

static void sailgen_ones(lbits *rop, sail_int);

static void sailgen_ones(lbits *zcbz37, sail_int zn)
{
  __label__ end_function_22, end_block_exception_23, end_function_204;

  sailgen_sail_ones((*(&zcbz37)), zn);
end_function_22: ;
  goto end_function_204;
end_block_exception_23: ;
  goto end_function_204;
end_function_204: ;
}

static uint64_t sailgen_bool_to_bits(bool);

static uint64_t sailgen_bool_to_bits(bool zx)
{
  __label__ end_function_25, end_block_exception_26;

  uint64_t zcbz38;
  if (zx) {  zcbz38 = UINT64_C(0b1);  } else {  zcbz38 = UINT64_C(0b0);  }
end_function_25: ;
  return zcbz38;
end_block_exception_26: ;

  return UINT64_C(0xdeadc0de);
}

static bool sailgen_bit_to_bool(fbits);

static bool sailgen_bit_to_bool(fbits zb)
{
  __label__ case_30, case_29, finish_match_28, end_function_31, end_block_exception_32;

  bool zcbz39;
  bool zgsz30;
  {
    fbits zp0z3;
    zp0z3 = zb;
    bool zgsz32;
    zgsz32 = eq_bit(zp0z3, UINT64_C(1));
    if (!(zgsz32)) {

      goto case_30;
    }
    zgsz30 = true;
    goto finish_match_28;
  }
case_30: ;
  {
    fbits zuz30;
    zuz30 = zb;
    bool zgsz31;
    zgsz31 = eq_bit(zuz30, UINT64_C(0));
    if (!(zgsz31)) {

      goto case_29;
    }
    zgsz30 = false;
    goto finish_match_28;
  }
case_29: ;
  sail_match_failure("bit_to_bool");
finish_match_28: ;
  zcbz39 = zgsz30;

end_function_31: ;
  return zcbz39;
end_block_exception_32: ;

  return false;
}

static void sailgen_to_bits(lbits *rop, sail_int, sail_int);

static void sailgen_to_bits(lbits *zcbz310, sail_int zl, sail_int zn)
{
  __label__ end_function_34, end_block_exception_35, end_function_203;

  {
    sail_int zgsz3106;
    CREATE(sail_int)(&zgsz3106);
    CONVERT_OF(sail_int, mach_int)(&zgsz3106, INT64_C(0));
    get_slice_int((*(&zcbz310)), zl, zn, zgsz3106);
    KILL(sail_int)(&zgsz3106);
  }
end_function_34: ;
  goto end_function_203;
end_block_exception_35: ;
  goto end_function_203;
end_function_203: ;
}

static bool sailgen_z8operatorz0zI_uz9(lbits, lbits);

static bool sailgen_z8operatorz0zKzJ_uz9(lbits, lbits);

static bool sailgen_z8operatorz0zI_uz9(lbits zx, lbits zy)
{
  __label__ end_function_37, end_block_exception_38;

  bool zcbz311;
  sail_int zgaz34;
  CREATE(sail_int)(&zgaz34);
  sail_unsigned(&zgaz34, zx);
  sail_int zgaz35;
  CREATE(sail_int)(&zgaz35);
  sail_unsigned(&zgaz35, zy);
  zcbz311 = lt(zgaz34, zgaz35);
  KILL(sail_int)(&zgaz35);
  KILL(sail_int)(&zgaz34);
end_function_37: ;
  return zcbz311;
end_block_exception_38: ;

  return false;
}

static bool sailgen_z8operatorz0zKzJ_uz9(lbits zx, lbits zy)
{
  __label__ end_function_40, end_block_exception_41;

  bool zcbz312;
  sail_int zgaz36;
  CREATE(sail_int)(&zgaz36);
  sail_unsigned(&zgaz36, zx);
  sail_int zgaz37;
  CREATE(sail_int)(&zgaz37);
  sail_unsigned(&zgaz37, zy);
  zcbz312 = gteq(zgaz36, zgaz37);
  KILL(sail_int)(&zgaz37);
  KILL(sail_int)(&zgaz36);
end_function_40: ;
  return zcbz312;
end_block_exception_41: ;

  return false;
}



static void sailgen_MAX(sail_int *rop, sail_int);

static void sailgen_MAX(sail_int *zcbz313, sail_int zn)
{
  __label__ end_function_43, end_block_exception_44, end_function_202;

  sail_int zgaz38;
  CREATE(sail_int)(&zgaz38);
  pow2(&zgaz38, zn);
  {
    sail_int zgsz3107;
    CREATE(sail_int)(&zgsz3107);
    CONVERT_OF(sail_int, mach_int)(&zgsz3107, INT64_C(1));
    sub_int((*(&zcbz313)), zgaz38, zgsz3107);
    KILL(sail_int)(&zgsz3107);
  }
  KILL(sail_int)(&zgaz38);
end_function_43: ;
  goto end_function_202;
end_block_exception_44: ;
  goto end_function_202;
end_function_202: ;
}



static int64_t zreserved_otypes;
static void create_letbind_0(void) {


  int64_t zgsz33;
  zgsz33 = INT64_C(4);
  zreserved_otypes = zgsz33;

let_end_45: ;
}
static void kill_letbind_0(void) {
}

static int64_t zotype_unsealed;
static void create_letbind_1(void) {


  int64_t zgsz34;
  zgsz34 = INT64_C(-1);
  zotype_unsealed = zgsz34;

let_end_46: ;
}
static void kill_letbind_1(void) {
}

static int64_t zotype_sentry;
static void create_letbind_2(void) {


  int64_t zgsz35;
  zgsz35 = INT64_C(-2);
  zotype_sentry = zgsz35;

let_end_47: ;
}
static void kill_letbind_2(void) {
}

static uint64_t zPCC_IDX;
static void create_letbind_3(void) {


  uint64_t zgsz36;
  zgsz36 = UINT64_C(0b100000);
  zPCC_IDX = zgsz36;

let_end_48: ;
}
static void kill_letbind_3(void) {
}

static uint64_t zDDC_IDX;
static void create_letbind_4(void) {


  uint64_t zgsz37;
  zgsz37 = UINT64_C(0b100001);
  zDDC_IDX = zgsz37;

let_end_49: ;
}
static void kill_letbind_4(void) {
}

static int64_t zcap_sizze;
static void create_letbind_5(void) {


  int64_t zgsz38;
  zgsz38 = INT64_C(16);
  zcap_sizze = zgsz38;

let_end_50: ;
}
static void kill_letbind_5(void) {
}

static int64_t zlog2_cap_sizze;
static void create_letbind_6(void) {


  int64_t zgsz39;
  zgsz39 = INT64_C(4);
  zlog2_cap_sizze = zgsz39;

let_end_51: ;
}
static void kill_letbind_6(void) {
}

static int64_t zcap_hperms_width;
static void create_letbind_7(void) {


  int64_t zgsz310;
  zgsz310 = INT64_C(12);
  zcap_hperms_width = zgsz310;

let_end_52: ;
}
static void kill_letbind_7(void) {
}

static int64_t zcap_uperms_width;
static void create_letbind_8(void) {


  int64_t zgsz311;
  zgsz311 = INT64_C(4);
  zcap_uperms_width = zgsz311;

let_end_53: ;
}
static void kill_letbind_8(void) {
}

static int64_t zcap_otype_width;
static void create_letbind_9(void) {


  int64_t zgsz312;
  zgsz312 = INT64_C(18);
  zcap_otype_width = zgsz312;

let_end_54: ;
}
static void kill_letbind_9(void) {
}

static int64_t zcap_reserved_width;
static void create_letbind_10(void) {


  int64_t zgsz313;
  zgsz313 = INT64_C(2);
  zcap_reserved_width = zgsz313;

let_end_55: ;
}
static void kill_letbind_10(void) {
}

static int64_t zcap_flags_width;
static void create_letbind_11(void) {


  int64_t zgsz314;
  zgsz314 = INT64_C(1);
  zcap_flags_width = zgsz314;

let_end_56: ;
}
static void kill_letbind_11(void) {
}

static int64_t zcap_mantissa_width;
static void create_letbind_12(void) {


  int64_t zgsz315;
  zgsz315 = INT64_C(14);
  zcap_mantissa_width = zgsz315;

let_end_57: ;
}
static void kill_letbind_12(void) {
}

static int64_t zcap_E_width;
static void create_letbind_13(void) {


  int64_t zgsz316;
  zgsz316 = INT64_C(6);
  zcap_E_width = zgsz316;

let_end_58: ;
}
static void kill_letbind_13(void) {
}

static int64_t zcap_addr_width;
static void create_letbind_14(void) {


  int64_t zgsz317;
  zgsz317 = INT64_C(64);
  zcap_addr_width = zgsz317;

let_end_59: ;
}
static void kill_letbind_14(void) {
}

static int64_t zcap_len_width;
static void create_letbind_15(void) {


  int64_t zgsz318;
  zgsz318 = INT64_C(65);
  zcap_len_width = zgsz318;

let_end_60: ;
}
static void kill_letbind_15(void) {
}

static int64_t zcaps_per_cache_line;
static void create_letbind_16(void) {


  int64_t zgsz319;
  zgsz319 = INT64_C(4);
  zcaps_per_cache_line = zgsz319;

let_end_61: ;
}
static void kill_letbind_16(void) {
}

static int64_t zinternal_E_take_bits;
static void create_letbind_17(void) {


  int64_t zgsz320;
  zgsz320 = INT64_C(3);
  zinternal_E_take_bits = zgsz320;

let_end_62: ;
}
static void kill_letbind_17(void) {
}

static struct zEncCapability sailgen_capBitsToEncCapability(lbits);

static struct zEncCapability sailgen_capBitsToEncCapability(lbits zc)
{
  __label__ end_function_64, end_block_exception_65;

  struct zEncCapability zcbz314;
  uint64_t zgaz39;
  {
    sail_int zgsz3127;
    CREATE(sail_int)(&zgsz3127);
    CONVERT_OF(sail_int, mach_int)(&zgsz3127, INT64_C(127));
    sail_int zgsz3128;
    CREATE(sail_int)(&zgsz3128);
    CONVERT_OF(sail_int, mach_int)(&zgsz3128, INT64_C(112));
    lbits zgsz3129;
    CREATE(lbits)(&zgsz3129);
    vector_subrange_lbits(&zgsz3129, zc, zgsz3127, zgsz3128);
    zgaz39 = CONVERT_OF(fbits, lbits)(zgsz3129, true);
    KILL(lbits)(&zgsz3129);
    KILL(sail_int)(&zgsz3128);
    KILL(sail_int)(&zgsz3127);
  }
  uint64_t zgaz310;
  {
    sail_int zgsz3124;
    CREATE(sail_int)(&zgsz3124);
    CONVERT_OF(sail_int, mach_int)(&zgsz3124, INT64_C(111));
    sail_int zgsz3125;
    CREATE(sail_int)(&zgsz3125);
    CONVERT_OF(sail_int, mach_int)(&zgsz3125, INT64_C(110));
    lbits zgsz3126;
    CREATE(lbits)(&zgsz3126);
    vector_subrange_lbits(&zgsz3126, zc, zgsz3124, zgsz3125);
    zgaz310 = CONVERT_OF(fbits, lbits)(zgsz3126, true);
    KILL(lbits)(&zgsz3126);
    KILL(sail_int)(&zgsz3125);
    KILL(sail_int)(&zgsz3124);
  }
  uint64_t zgaz311;
  {
    sail_int zgsz3121;
    CREATE(sail_int)(&zgsz3121);
    CONVERT_OF(sail_int, mach_int)(&zgsz3121, INT64_C(109));
    sail_int zgsz3122;
    CREATE(sail_int)(&zgsz3122);
    CONVERT_OF(sail_int, mach_int)(&zgsz3122, INT64_C(109));
    lbits zgsz3123;
    CREATE(lbits)(&zgsz3123);
    vector_subrange_lbits(&zgsz3123, zc, zgsz3121, zgsz3122);
    zgaz311 = CONVERT_OF(fbits, lbits)(zgsz3123, true);
    KILL(lbits)(&zgsz3123);
    KILL(sail_int)(&zgsz3122);
    KILL(sail_int)(&zgsz3121);
  }
  uint64_t zgaz312;
  {
    sail_int zgsz3118;
    CREATE(sail_int)(&zgsz3118);
    CONVERT_OF(sail_int, mach_int)(&zgsz3118, INT64_C(108));
    sail_int zgsz3119;
    CREATE(sail_int)(&zgsz3119);
    CONVERT_OF(sail_int, mach_int)(&zgsz3119, INT64_C(91));
    lbits zgsz3120;
    CREATE(lbits)(&zgsz3120);
    vector_subrange_lbits(&zgsz3120, zc, zgsz3118, zgsz3119);
    zgaz312 = CONVERT_OF(fbits, lbits)(zgsz3120, true);
    KILL(lbits)(&zgsz3120);
    KILL(sail_int)(&zgsz3119);
    KILL(sail_int)(&zgsz3118);
  }
  fbits zgaz313;
  {
    sail_int zgsz3117;
    CREATE(sail_int)(&zgsz3117);
    CONVERT_OF(sail_int, mach_int)(&zgsz3117, INT64_C(90));
    zgaz313 = bitvector_access(zc, zgsz3117);
    KILL(sail_int)(&zgsz3117);
  }
  uint64_t zgaz314;
  {
    sail_int zgsz3114;
    CREATE(sail_int)(&zgsz3114);
    CONVERT_OF(sail_int, mach_int)(&zgsz3114, INT64_C(89));
    sail_int zgsz3115;
    CREATE(sail_int)(&zgsz3115);
    CONVERT_OF(sail_int, mach_int)(&zgsz3115, INT64_C(78));
    lbits zgsz3116;
    CREATE(lbits)(&zgsz3116);
    vector_subrange_lbits(&zgsz3116, zc, zgsz3114, zgsz3115);
    zgaz314 = CONVERT_OF(fbits, lbits)(zgsz3116, true);
    KILL(lbits)(&zgsz3116);
    KILL(sail_int)(&zgsz3115);
    KILL(sail_int)(&zgsz3114);
  }
  uint64_t zgaz315;
  {
    sail_int zgsz3111;
    CREATE(sail_int)(&zgsz3111);
    CONVERT_OF(sail_int, mach_int)(&zgsz3111, INT64_C(77));
    sail_int zgsz3112;
    CREATE(sail_int)(&zgsz3112);
    CONVERT_OF(sail_int, mach_int)(&zgsz3112, INT64_C(64));
    lbits zgsz3113;
    CREATE(lbits)(&zgsz3113);
    vector_subrange_lbits(&zgsz3113, zc, zgsz3111, zgsz3112);
    zgaz315 = CONVERT_OF(fbits, lbits)(zgsz3113, true);
    KILL(lbits)(&zgsz3113);
    KILL(sail_int)(&zgsz3112);
    KILL(sail_int)(&zgsz3111);
  }
  uint64_t zgaz316;
  {
    sail_int zgsz3108;
    CREATE(sail_int)(&zgsz3108);
    CONVERT_OF(sail_int, mach_int)(&zgsz3108, INT64_C(63));
    sail_int zgsz3109;
    CREATE(sail_int)(&zgsz3109);
    CONVERT_OF(sail_int, mach_int)(&zgsz3109, INT64_C(0));
    lbits zgsz3110;
    CREATE(lbits)(&zgsz3110);
    vector_subrange_lbits(&zgsz3110, zc, zgsz3108, zgsz3109);
    zgaz316 = CONVERT_OF(fbits, lbits)(zgsz3110, true);
    KILL(lbits)(&zgsz3110);
    KILL(sail_int)(&zgsz3109);
    KILL(sail_int)(&zgsz3108);
  }
  struct zEncCapability zgsz321;
  zgsz321.zB = zgaz315;
  zgsz321.zT = zgaz314;
  zgsz321.zaddress = zgaz316;
  zgsz321.zflags = zgaz311;
  zgsz321.zinternal_E = zgaz313;
  zgsz321.zotype = zgaz312;
  zgsz321.zperms = zgaz39;
  zgsz321.zreserved = zgaz310;
  zcbz314 = zgsz321;









end_function_64: ;
  return zcbz314;
end_block_exception_65: ;
  struct zEncCapability zcbz346 = { .zB = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaddress = UINT64_C(0xdeadc0de), .zflags = UINT64_C(0xdeadc0de), .zinternal_E = UINT64_C(0), .zotype = UINT64_C(0xdeadc0de), .zperms = UINT64_C(0xdeadc0de), .zreserved = UINT64_C(0xdeadc0de) };
  return zcbz346;
}

static void sailgen_encCapToBits(lbits *rop, struct zEncCapability);

static void sailgen_encCapToBits(lbits *zcbz315, struct zEncCapability zcap)
{
  __label__ end_function_67, end_block_exception_68, end_function_201;

  uint64_t zgaz330;
  zgaz330 = zcap.zperms;
  lbits zgaz331;
  CREATE(lbits)(&zgaz331);
  {
    uint64_t zgaz328;
    zgaz328 = zcap.zreserved;
    lbits zgaz329;
    CREATE(lbits)(&zgaz329);
    {
      uint64_t zgaz326;
      zgaz326 = zcap.zflags;
      lbits zgaz327;
      CREATE(lbits)(&zgaz327);
      {
        uint64_t zgaz324;
        zgaz324 = zcap.zotype;
        lbits zgaz325;
        CREATE(lbits)(&zgaz325);
        {
          uint64_t zgaz322;
          {
            fbits zgaz317;
            zgaz317 = zcap.zinternal_E;
            uint64_t zgsz322;
            zgsz322 = UINT64_C(0b0);
            zgsz322 = update_fbits(zgsz322, INT64_C(0), zgaz317);
            zgaz322 = zgsz322;
          }
          lbits zgaz323;
          CREATE(lbits)(&zgaz323);
          {
            uint64_t zgaz320;
            zgaz320 = zcap.zT;
            lbits zgaz321;
            CREATE(lbits)(&zgaz321);
            {
              uint64_t zgaz318;
              zgaz318 = zcap.zB;
              uint64_t zgaz319;
              zgaz319 = zcap.zaddress;
              {
                lbits zgsz3130;
                CREATE(lbits)(&zgsz3130);
                CONVERT_OF(lbits, fbits)(&zgsz3130, zgaz318, UINT64_C(14) , true);
                lbits zgsz3131;
                CREATE(lbits)(&zgsz3131);
                CONVERT_OF(lbits, fbits)(&zgsz3131, zgaz319, UINT64_C(64) , true);
                append(&zgaz321, zgsz3130, zgsz3131);
                KILL(lbits)(&zgsz3131);
                KILL(lbits)(&zgsz3130);
              }
            }
            {
              lbits zgsz3132;
              CREATE(lbits)(&zgsz3132);
              CONVERT_OF(lbits, fbits)(&zgsz3132, zgaz320, UINT64_C(12) , true);
              append(&zgaz323, zgsz3132, zgaz321);
              KILL(lbits)(&zgsz3132);
            }
            KILL(lbits)(&zgaz321);
          }
          {
            lbits zgsz3133;
            CREATE(lbits)(&zgsz3133);
            CONVERT_OF(lbits, fbits)(&zgsz3133, zgaz322, UINT64_C(1) , true);
            append(&zgaz325, zgsz3133, zgaz323);
            KILL(lbits)(&zgsz3133);
          }
          KILL(lbits)(&zgaz323);
        }
        {
          lbits zgsz3134;
          CREATE(lbits)(&zgsz3134);
          CONVERT_OF(lbits, fbits)(&zgsz3134, zgaz324, UINT64_C(18) , true);
          append(&zgaz327, zgsz3134, zgaz325);
          KILL(lbits)(&zgsz3134);
        }
        KILL(lbits)(&zgaz325);
      }
      {
        lbits zgsz3135;
        CREATE(lbits)(&zgsz3135);
        CONVERT_OF(lbits, fbits)(&zgsz3135, zgaz326, UINT64_C(1) , true);
        append(&zgaz329, zgsz3135, zgaz327);
        KILL(lbits)(&zgsz3135);
      }
      KILL(lbits)(&zgaz327);
    }
    {
      lbits zgsz3136;
      CREATE(lbits)(&zgsz3136);
      CONVERT_OF(lbits, fbits)(&zgsz3136, zgaz328, UINT64_C(2) , true);
      append(&zgaz331, zgsz3136, zgaz329);
      KILL(lbits)(&zgsz3136);
    }
    KILL(lbits)(&zgaz329);
  }
  {
    lbits zgsz3137;
    CREATE(lbits)(&zgsz3137);
    CONVERT_OF(lbits, fbits)(&zgsz3137, zgaz330, UINT64_C(16) , true);
    append((*(&zcbz315)), zgsz3137, zgaz331);
    KILL(lbits)(&zgsz3137);
  }
  KILL(lbits)(&zgaz331);

end_function_67: ;
  goto end_function_201;
end_block_exception_68: ;
  goto end_function_201;
end_function_201: ;
}

static sail_int zcap_max_addr;
static void create_letbind_18(void) {    CREATE(sail_int)(&zcap_max_addr);


  sail_int zgsz323;
  CREATE(sail_int)(&zgsz323);
  {
    sail_int zgsz3138;
    CREATE(sail_int)(&zgsz3138);
    CONVERT_OF(sail_int, mach_int)(&zgsz3138, zcap_addr_width);
    sailgen_MAX(&zgsz323, zgsz3138);
    KILL(sail_int)(&zgsz3138);
  }
  COPY(sail_int)(&zcap_max_addr, zgsz323);
  KILL(sail_int)(&zgsz323);
let_end_69: ;
}
static void kill_letbind_18(void) {    KILL(sail_int)(&zcap_max_addr);
}

static int64_t zcap_max_otype;
static void create_letbind_19(void) {


  int64_t zgsz324;
  int64_t zgaz332;
  {
    sail_int zgsz3142;
    CREATE(sail_int)(&zgsz3142);
    CONVERT_OF(sail_int, mach_int)(&zgsz3142, zcap_otype_width);
    sail_int zgsz3143;
    CREATE(sail_int)(&zgsz3143);
    sailgen_MAX(&zgsz3143, zgsz3142);
    zgaz332 = CONVERT_OF(mach_int, sail_int)(zgsz3143);
    KILL(sail_int)(&zgsz3143);
    KILL(sail_int)(&zgsz3142);
  }
  {
    sail_int zgsz3139;
    CREATE(sail_int)(&zgsz3139);
    CONVERT_OF(sail_int, mach_int)(&zgsz3139, zgaz332);
    sail_int zgsz3140;
    CREATE(sail_int)(&zgsz3140);
    CONVERT_OF(sail_int, mach_int)(&zgsz3140, zreserved_otypes);
    sail_int zgsz3141;
    CREATE(sail_int)(&zgsz3141);
    sub_int(&zgsz3141, zgsz3139, zgsz3140);
    zgsz324 = CONVERT_OF(mach_int, sail_int)(zgsz3141);
    KILL(sail_int)(&zgsz3141);
    KILL(sail_int)(&zgsz3140);
    KILL(sail_int)(&zgsz3139);
  }

  zcap_max_otype = zgsz324;

let_end_70: ;
}
static void kill_letbind_19(void) {
}

static int64_t zcap_uperms_shift;
static void create_letbind_20(void) {


  int64_t zgsz325;
  zgsz325 = INT64_C(15);
  zcap_uperms_shift = zgsz325;

let_end_71: ;
}
static void kill_letbind_20(void) {
}

static int64_t zcap_perms_width;
static void create_letbind_21(void) {


  int64_t zgsz326;
  zgsz326 = INT64_C(19);
  zcap_perms_width = zgsz326;

let_end_72: ;
}
static void kill_letbind_21(void) {
}

static int64_t zcap_max_E;
static void create_letbind_22(void) {


  int64_t zgsz327;
  int64_t zgaz333;
  {
    sail_int zgsz3147;
    CREATE(sail_int)(&zgsz3147);
    CONVERT_OF(sail_int, mach_int)(&zgsz3147, zcap_len_width);
    sail_int zgsz3148;
    CREATE(sail_int)(&zgsz3148);
    CONVERT_OF(sail_int, mach_int)(&zgsz3148, zcap_mantissa_width);
    sail_int zgsz3149;
    CREATE(sail_int)(&zgsz3149);
    sub_int(&zgsz3149, zgsz3147, zgsz3148);
    zgaz333 = CONVERT_OF(mach_int, sail_int)(zgsz3149);
    KILL(sail_int)(&zgsz3149);
    KILL(sail_int)(&zgsz3148);
    KILL(sail_int)(&zgsz3147);
  }
  {
    sail_int zgsz3144;
    CREATE(sail_int)(&zgsz3144);
    CONVERT_OF(sail_int, mach_int)(&zgsz3144, zgaz333);
    sail_int zgsz3145;
    CREATE(sail_int)(&zgsz3145);
    CONVERT_OF(sail_int, mach_int)(&zgsz3145, INT64_C(1));
    sail_int zgsz3146;
    CREATE(sail_int)(&zgsz3146);
    add_int(&zgsz3146, zgsz3144, zgsz3145);
    zgsz327 = CONVERT_OF(mach_int, sail_int)(zgsz3146);
    KILL(sail_int)(&zgsz3146);
    KILL(sail_int)(&zgsz3145);
    KILL(sail_int)(&zgsz3144);
  }

  zcap_max_E = zgsz327;

let_end_73: ;
}
static void kill_letbind_22(void) {
}

static uint64_t zcap_reset_E;
static void create_letbind_23(void) {


  uint64_t zgsz328;
  {
    sail_int zgsz3150;
    CREATE(sail_int)(&zgsz3150);
    CONVERT_OF(sail_int, mach_int)(&zgsz3150, zcap_E_width);
    sail_int zgsz3151;
    CREATE(sail_int)(&zgsz3151);
    CONVERT_OF(sail_int, mach_int)(&zgsz3151, zcap_max_E);
    lbits zgsz3152;
    CREATE(lbits)(&zgsz3152);
    sailgen_to_bits(&zgsz3152, zgsz3150, zgsz3151);
    zgsz328 = CONVERT_OF(fbits, lbits)(zgsz3152, true);
    KILL(lbits)(&zgsz3152);
    KILL(sail_int)(&zgsz3151);
    KILL(sail_int)(&zgsz3150);
  }
  zcap_reset_E = zgsz328;

let_end_74: ;
}
static void kill_letbind_23(void) {
}

static uint64_t zcap_reset_T;
static void create_letbind_24(void) {


  uint64_t zgsz329;
  uint64_t zgaz335;
  {
    int64_t zgaz334;
    {
      sail_int zgsz3155;
      CREATE(sail_int)(&zgsz3155);
      CONVERT_OF(sail_int, mach_int)(&zgsz3155, zcap_mantissa_width);
      sail_int zgsz3156;
      CREATE(sail_int)(&zgsz3156);
      CONVERT_OF(sail_int, mach_int)(&zgsz3156, INT64_C(2));
      sail_int zgsz3157;
      CREATE(sail_int)(&zgsz3157);
      sub_int(&zgsz3157, zgsz3155, zgsz3156);
      zgaz334 = CONVERT_OF(mach_int, sail_int)(zgsz3157);
      KILL(sail_int)(&zgsz3157);
      KILL(sail_int)(&zgsz3156);
      KILL(sail_int)(&zgsz3155);
    }
    {
      sail_int zgsz3153;
      CREATE(sail_int)(&zgsz3153);
      CONVERT_OF(sail_int, mach_int)(&zgsz3153, zgaz334);
      lbits zgsz3154;
      CREATE(lbits)(&zgsz3154);
      sailgen_zzeros_implicit(&zgsz3154, zgsz3153);
      zgaz335 = CONVERT_OF(fbits, lbits)(zgsz3154, true);
      KILL(lbits)(&zgsz3154);
      KILL(sail_int)(&zgsz3153);
    }
  }
  {
    lbits zgsz3158;
    CREATE(lbits)(&zgsz3158);
    CONVERT_OF(lbits, fbits)(&zgsz3158, UINT64_C(0b01), UINT64_C(2) , true);
    lbits zgsz3159;
    CREATE(lbits)(&zgsz3159);
    CONVERT_OF(lbits, fbits)(&zgsz3159, zgaz335, UINT64_C(12) , true);
    lbits zgsz3160;
    CREATE(lbits)(&zgsz3160);
    append(&zgsz3160, zgsz3158, zgsz3159);
    zgsz329 = CONVERT_OF(fbits, lbits)(zgsz3160, true);
    KILL(lbits)(&zgsz3160);
    KILL(lbits)(&zgsz3159);
    KILL(lbits)(&zgsz3158);
  }

  zcap_reset_T = zgsz329;

let_end_75: ;
}
static void kill_letbind_24(void) {
}

static struct zCapability sailgen_undefined_Capability(unit);

static struct zCapability sailgen_undefined_Capability(unit zgsz330)
{
  __label__ end_function_77, end_block_exception_78;

  struct zCapability zcbz316;
  bool zgaz336;
  zgaz336 = undefined_bool(UNIT);
  uint64_t zgaz337;
  {
    sail_int zgsz3173;
    CREATE(sail_int)(&zgsz3173);
    CONVERT_OF(sail_int, mach_int)(&zgsz3173, INT64_C(4));
    lbits zgsz3174;
    CREATE(lbits)(&zgsz3174);
    UNDEFINED(lbits)(&zgsz3174, zgsz3173);
    zgaz337 = CONVERT_OF(fbits, lbits)(zgsz3174, true);
    KILL(lbits)(&zgsz3174);
    KILL(sail_int)(&zgsz3173);
  }
  bool zgaz338;
  zgaz338 = undefined_bool(UNIT);
  bool zgaz339;
  zgaz339 = undefined_bool(UNIT);
  bool zgaz340;
  zgaz340 = undefined_bool(UNIT);
  bool zgaz341;
  zgaz341 = undefined_bool(UNIT);
  bool zgaz342;
  zgaz342 = undefined_bool(UNIT);
  bool zgaz343;
  zgaz343 = undefined_bool(UNIT);
  bool zgaz344;
  zgaz344 = undefined_bool(UNIT);
  bool zgaz345;
  zgaz345 = undefined_bool(UNIT);
  bool zgaz346;
  zgaz346 = undefined_bool(UNIT);
  bool zgaz347;
  zgaz347 = undefined_bool(UNIT);
  bool zgaz348;
  zgaz348 = undefined_bool(UNIT);
  bool zgaz349;
  zgaz349 = undefined_bool(UNIT);
  uint64_t zgaz350;
  {
    sail_int zgsz3171;
    CREATE(sail_int)(&zgsz3171);
    CONVERT_OF(sail_int, mach_int)(&zgsz3171, INT64_C(2));
    lbits zgsz3172;
    CREATE(lbits)(&zgsz3172);
    UNDEFINED(lbits)(&zgsz3172, zgsz3171);
    zgaz350 = CONVERT_OF(fbits, lbits)(zgsz3172, true);
    KILL(lbits)(&zgsz3172);
    KILL(sail_int)(&zgsz3171);
  }
  bool zgaz351;
  zgaz351 = undefined_bool(UNIT);
  bool zgaz352;
  zgaz352 = undefined_bool(UNIT);
  uint64_t zgaz353;
  {
    sail_int zgsz3169;
    CREATE(sail_int)(&zgsz3169);
    CONVERT_OF(sail_int, mach_int)(&zgsz3169, INT64_C(6));
    lbits zgsz3170;
    CREATE(lbits)(&zgsz3170);
    UNDEFINED(lbits)(&zgsz3170, zgsz3169);
    zgaz353 = CONVERT_OF(fbits, lbits)(zgsz3170, true);
    KILL(lbits)(&zgsz3170);
    KILL(sail_int)(&zgsz3169);
  }
  uint64_t zgaz354;
  {
    sail_int zgsz3167;
    CREATE(sail_int)(&zgsz3167);
    CONVERT_OF(sail_int, mach_int)(&zgsz3167, INT64_C(14));
    lbits zgsz3168;
    CREATE(lbits)(&zgsz3168);
    UNDEFINED(lbits)(&zgsz3168, zgsz3167);
    zgaz354 = CONVERT_OF(fbits, lbits)(zgsz3168, true);
    KILL(lbits)(&zgsz3168);
    KILL(sail_int)(&zgsz3167);
  }
  uint64_t zgaz355;
  {
    sail_int zgsz3165;
    CREATE(sail_int)(&zgsz3165);
    CONVERT_OF(sail_int, mach_int)(&zgsz3165, INT64_C(14));
    lbits zgsz3166;
    CREATE(lbits)(&zgsz3166);
    UNDEFINED(lbits)(&zgsz3166, zgsz3165);
    zgaz355 = CONVERT_OF(fbits, lbits)(zgsz3166, true);
    KILL(lbits)(&zgsz3166);
    KILL(sail_int)(&zgsz3165);
  }
  uint64_t zgaz356;
  {
    sail_int zgsz3163;
    CREATE(sail_int)(&zgsz3163);
    CONVERT_OF(sail_int, mach_int)(&zgsz3163, INT64_C(18));
    lbits zgsz3164;
    CREATE(lbits)(&zgsz3164);
    UNDEFINED(lbits)(&zgsz3164, zgsz3163);
    zgaz356 = CONVERT_OF(fbits, lbits)(zgsz3164, true);
    KILL(lbits)(&zgsz3164);
    KILL(sail_int)(&zgsz3163);
  }
  uint64_t zgaz357;
  {
    sail_int zgsz3161;
    CREATE(sail_int)(&zgsz3161);
    CONVERT_OF(sail_int, mach_int)(&zgsz3161, INT64_C(64));
    lbits zgsz3162;
    CREATE(lbits)(&zgsz3162);
    UNDEFINED(lbits)(&zgsz3162, zgsz3161);
    zgaz357 = CONVERT_OF(fbits, lbits)(zgsz3162, true);
    KILL(lbits)(&zgsz3162);
    KILL(sail_int)(&zgsz3161);
  }
  struct zCapability zgsz331;
  zgsz331.zB = zgaz354;
  zgsz331.zE = zgaz353;
  zgsz331.zT = zgaz355;
  zgsz331.zaccess_system_regs = zgaz339;
  zgsz331.zaddress = zgaz357;
  zgsz331.zflag_cap_mode = zgaz351;
  zgsz331.zglobal = zgaz349;
  zgsz331.zinternal_E = zgaz352;
  zgsz331.zotype = zgaz356;
  zgsz331.zpermit_cinvoke = zgaz341;
  zgsz331.zpermit_execute = zgaz348;
  zgsz331.zpermit_load = zgaz347;
  zgsz331.zpermit_load_cap = zgaz345;
  zgsz331.zpermit_seal = zgaz342;
  zgsz331.zpermit_set_CID = zgaz338;
  zgsz331.zpermit_store = zgaz346;
  zgsz331.zpermit_store_cap = zgaz344;
  zgsz331.zpermit_store_local_cap = zgaz343;
  zgsz331.zpermit_unseal = zgaz340;
  zgsz331.zreserved = zgaz350;
  zgsz331.ztag = zgaz336;
  zgsz331.zuperms = zgaz337;
  zcbz316 = zgsz331;























end_function_77: ;
  return zcbz316;
end_block_exception_78: ;
  struct zCapability zcbz347 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  return zcbz347;
}

static struct zCapability znull_cap;
static void create_letbind_25(void) {


  struct zCapability zgsz333;
  uint64_t zgaz358;
  {
    sail_int zgsz3184;
    CREATE(sail_int)(&zgsz3184);
    CONVERT_OF(sail_int, mach_int)(&zgsz3184, INT64_C(4));
    lbits zgsz3185;
    CREATE(lbits)(&zgsz3185);
    sailgen_zzeros_implicit(&zgsz3185, zgsz3184);
    zgaz358 = CONVERT_OF(fbits, lbits)(zgsz3185, true);
    KILL(lbits)(&zgsz3185);
    KILL(sail_int)(&zgsz3184);
  }
  uint64_t zgaz359;
  {
    sail_int zgsz3182;
    CREATE(sail_int)(&zgsz3182);
    CONVERT_OF(sail_int, mach_int)(&zgsz3182, INT64_C(2));
    lbits zgsz3183;
    CREATE(lbits)(&zgsz3183);
    sailgen_zzeros_implicit(&zgsz3183, zgsz3182);
    zgaz359 = CONVERT_OF(fbits, lbits)(zgsz3183, true);
    KILL(lbits)(&zgsz3183);
    KILL(sail_int)(&zgsz3182);
  }
  uint64_t zgaz360;
  {
    sail_int zgsz3180;
    CREATE(sail_int)(&zgsz3180);
    CONVERT_OF(sail_int, mach_int)(&zgsz3180, INT64_C(14));
    lbits zgsz3181;
    CREATE(lbits)(&zgsz3181);
    sailgen_zzeros_implicit(&zgsz3181, zgsz3180);
    zgaz360 = CONVERT_OF(fbits, lbits)(zgsz3181, true);
    KILL(lbits)(&zgsz3181);
    KILL(sail_int)(&zgsz3180);
  }
  uint64_t zgaz361;
  {
    sail_int zgsz3177;
    CREATE(sail_int)(&zgsz3177);
    CONVERT_OF(sail_int, mach_int)(&zgsz3177, zcap_otype_width);
    sail_int zgsz3178;
    CREATE(sail_int)(&zgsz3178);
    CONVERT_OF(sail_int, mach_int)(&zgsz3178, zotype_unsealed);
    lbits zgsz3179;
    CREATE(lbits)(&zgsz3179);
    sailgen_to_bits(&zgsz3179, zgsz3177, zgsz3178);
    zgaz361 = CONVERT_OF(fbits, lbits)(zgsz3179, true);
    KILL(lbits)(&zgsz3179);
    KILL(sail_int)(&zgsz3178);
    KILL(sail_int)(&zgsz3177);
  }
  uint64_t zgaz362;
  {
    sail_int zgsz3175;
    CREATE(sail_int)(&zgsz3175);
    CONVERT_OF(sail_int, mach_int)(&zgsz3175, INT64_C(64));
    lbits zgsz3176;
    CREATE(lbits)(&zgsz3176);
    sailgen_zzeros_implicit(&zgsz3176, zgsz3175);
    zgaz362 = CONVERT_OF(fbits, lbits)(zgsz3176, true);
    KILL(lbits)(&zgsz3176);
    KILL(sail_int)(&zgsz3175);
  }
  struct zCapability zgsz332;
  zgsz332.zB = zgaz360;
  zgsz332.zE = zcap_reset_E;
  zgsz332.zT = zcap_reset_T;
  zgsz332.zaccess_system_regs = false;
  zgsz332.zaddress = zgaz362;
  zgsz332.zflag_cap_mode = false;
  zgsz332.zglobal = false;
  zgsz332.zinternal_E = true;
  zgsz332.zotype = zgaz361;
  zgsz332.zpermit_cinvoke = false;
  zgsz332.zpermit_execute = false;
  zgsz332.zpermit_load = false;
  zgsz332.zpermit_load_cap = false;
  zgsz332.zpermit_seal = false;
  zgsz332.zpermit_set_CID = false;
  zgsz332.zpermit_store = false;
  zgsz332.zpermit_store_cap = false;
  zgsz332.zpermit_store_local_cap = false;
  zgsz332.zpermit_unseal = false;
  zgsz332.zreserved = zgaz359;
  zgsz332.ztag = false;
  zgsz332.zuperms = zgaz358;
  zgsz333 = zgsz332;






  znull_cap = zgsz333;

let_end_79: ;
}
static void kill_letbind_25(void) {
}

static struct zCapability zdefault_cap;
static void create_letbind_26(void) {


  struct zCapability zgsz335;
  uint64_t zgaz363;
  {
    sail_int zgsz3195;
    CREATE(sail_int)(&zgsz3195);
    CONVERT_OF(sail_int, mach_int)(&zgsz3195, INT64_C(4));
    lbits zgsz3196;
    CREATE(lbits)(&zgsz3196);
    sailgen_ones(&zgsz3196, zgsz3195);
    zgaz363 = CONVERT_OF(fbits, lbits)(zgsz3196, true);
    KILL(lbits)(&zgsz3196);
    KILL(sail_int)(&zgsz3195);
  }
  uint64_t zgaz364;
  {
    sail_int zgsz3193;
    CREATE(sail_int)(&zgsz3193);
    CONVERT_OF(sail_int, mach_int)(&zgsz3193, INT64_C(2));
    lbits zgsz3194;
    CREATE(lbits)(&zgsz3194);
    sailgen_zzeros_implicit(&zgsz3194, zgsz3193);
    zgaz364 = CONVERT_OF(fbits, lbits)(zgsz3194, true);
    KILL(lbits)(&zgsz3194);
    KILL(sail_int)(&zgsz3193);
  }
  uint64_t zgaz365;
  {
    sail_int zgsz3191;
    CREATE(sail_int)(&zgsz3191);
    CONVERT_OF(sail_int, mach_int)(&zgsz3191, INT64_C(14));
    lbits zgsz3192;
    CREATE(lbits)(&zgsz3192);
    sailgen_zzeros_implicit(&zgsz3192, zgsz3191);
    zgaz365 = CONVERT_OF(fbits, lbits)(zgsz3192, true);
    KILL(lbits)(&zgsz3192);
    KILL(sail_int)(&zgsz3191);
  }
  uint64_t zgaz366;
  {
    sail_int zgsz3188;
    CREATE(sail_int)(&zgsz3188);
    CONVERT_OF(sail_int, mach_int)(&zgsz3188, zcap_otype_width);
    sail_int zgsz3189;
    CREATE(sail_int)(&zgsz3189);
    CONVERT_OF(sail_int, mach_int)(&zgsz3189, zotype_unsealed);
    lbits zgsz3190;
    CREATE(lbits)(&zgsz3190);
    sailgen_to_bits(&zgsz3190, zgsz3188, zgsz3189);
    zgaz366 = CONVERT_OF(fbits, lbits)(zgsz3190, true);
    KILL(lbits)(&zgsz3190);
    KILL(sail_int)(&zgsz3189);
    KILL(sail_int)(&zgsz3188);
  }
  uint64_t zgaz367;
  {
    sail_int zgsz3186;
    CREATE(sail_int)(&zgsz3186);
    CONVERT_OF(sail_int, mach_int)(&zgsz3186, INT64_C(64));
    lbits zgsz3187;
    CREATE(lbits)(&zgsz3187);
    sailgen_zzeros_implicit(&zgsz3187, zgsz3186);
    zgaz367 = CONVERT_OF(fbits, lbits)(zgsz3187, true);
    KILL(lbits)(&zgsz3187);
    KILL(sail_int)(&zgsz3186);
  }
  struct zCapability zgsz334;
  zgsz334.zB = zgaz365;
  zgsz334.zE = zcap_reset_E;
  zgsz334.zT = zcap_reset_T;
  zgsz334.zaccess_system_regs = true;
  zgsz334.zaddress = zgaz367;
  zgsz334.zflag_cap_mode = false;
  zgsz334.zglobal = true;
  zgsz334.zinternal_E = true;
  zgsz334.zotype = zgaz366;
  zgsz334.zpermit_cinvoke = true;
  zgsz334.zpermit_execute = true;
  zgsz334.zpermit_load = true;
  zgsz334.zpermit_load_cap = true;
  zgsz334.zpermit_seal = true;
  zgsz334.zpermit_set_CID = true;
  zgsz334.zpermit_store = true;
  zgsz334.zpermit_store_cap = true;
  zgsz334.zpermit_store_local_cap = true;
  zgsz334.zpermit_unseal = true;
  zgsz334.zreserved = zgaz364;
  zgsz334.ztag = true;
  zgsz334.zuperms = zgaz363;
  zgsz335 = zgsz334;






  zdefault_cap = zgsz335;

let_end_80: ;
}
static void kill_letbind_26(void) {
}

static uint64_t sailgen_getCapHardPerms(struct zCapability);

static uint64_t sailgen_getCapHardPerms(struct zCapability zcap)
{
  __label__ end_function_82, end_block_exception_83;

  uint64_t zcbz317;
  uint64_t zgaz3100;
  {
    bool zgaz368;
    zgaz368 = zcap.zpermit_set_CID;
    zgaz3100 = sailgen_bool_to_bits(zgaz368);
  }
  uint64_t zgaz3101;
  {
    uint64_t zgaz398;
    {
      bool zgaz369;
      zgaz369 = zcap.zaccess_system_regs;
      zgaz398 = sailgen_bool_to_bits(zgaz369);
    }
    uint64_t zgaz399;
    {
      uint64_t zgaz396;
      {
        bool zgaz370;
        zgaz370 = zcap.zpermit_unseal;
        zgaz396 = sailgen_bool_to_bits(zgaz370);
      }
      uint64_t zgaz397;
      {
        uint64_t zgaz394;
        {
          bool zgaz371;
          zgaz371 = zcap.zpermit_cinvoke;
          zgaz394 = sailgen_bool_to_bits(zgaz371);
        }
        uint64_t zgaz395;
        {
          uint64_t zgaz392;
          {
            bool zgaz372;
            zgaz372 = zcap.zpermit_seal;
            zgaz392 = sailgen_bool_to_bits(zgaz372);
          }
          uint64_t zgaz393;
          {
            uint64_t zgaz390;
            {
              bool zgaz373;
              zgaz373 = zcap.zpermit_store_local_cap;
              zgaz390 = sailgen_bool_to_bits(zgaz373);
            }
            uint64_t zgaz391;
            {
              uint64_t zgaz388;
              {
                bool zgaz374;
                zgaz374 = zcap.zpermit_store_cap;
                zgaz388 = sailgen_bool_to_bits(zgaz374);
              }
              uint64_t zgaz389;
              {
                uint64_t zgaz386;
                {
                  bool zgaz375;
                  zgaz375 = zcap.zpermit_load_cap;
                  zgaz386 = sailgen_bool_to_bits(zgaz375);
                }
                uint64_t zgaz387;
                {
                  uint64_t zgaz384;
                  {
                    bool zgaz376;
                    zgaz376 = zcap.zpermit_store;
                    zgaz384 = sailgen_bool_to_bits(zgaz376);
                  }
                  uint64_t zgaz385;
                  {
                    uint64_t zgaz382;
                    {
                      bool zgaz377;
                      zgaz377 = zcap.zpermit_load;
                      zgaz382 = sailgen_bool_to_bits(zgaz377);
                    }
                    uint64_t zgaz383;
                    {
                      uint64_t zgaz380;
                      {
                        bool zgaz378;
                        zgaz378 = zcap.zpermit_execute;
                        zgaz380 = sailgen_bool_to_bits(zgaz378);
                      }
                      uint64_t zgaz381;
                      {
                        bool zgaz379;
                        zgaz379 = zcap.zglobal;
                        zgaz381 = sailgen_bool_to_bits(zgaz379);
                      }
                      {
                        lbits zgsz3197;
                        CREATE(lbits)(&zgsz3197);
                        CONVERT_OF(lbits, fbits)(&zgsz3197, zgaz380, UINT64_C(1) , true);
                        lbits zgsz3198;
                        CREATE(lbits)(&zgsz3198);
                        CONVERT_OF(lbits, fbits)(&zgsz3198, zgaz381, UINT64_C(1) , true);
                        lbits zgsz3199;
                        CREATE(lbits)(&zgsz3199);
                        append(&zgsz3199, zgsz3197, zgsz3198);
                        zgaz383 = CONVERT_OF(fbits, lbits)(zgsz3199, true);
                        KILL(lbits)(&zgsz3199);
                        KILL(lbits)(&zgsz3198);
                        KILL(lbits)(&zgsz3197);
                      }
                    }
                    {
                      lbits zgsz3200;
                      CREATE(lbits)(&zgsz3200);
                      CONVERT_OF(lbits, fbits)(&zgsz3200, zgaz382, UINT64_C(1) , true);
                      lbits zgsz3201;
                      CREATE(lbits)(&zgsz3201);
                      CONVERT_OF(lbits, fbits)(&zgsz3201, zgaz383, UINT64_C(2) , true);
                      lbits zgsz3202;
                      CREATE(lbits)(&zgsz3202);
                      append(&zgsz3202, zgsz3200, zgsz3201);
                      zgaz385 = CONVERT_OF(fbits, lbits)(zgsz3202, true);
                      KILL(lbits)(&zgsz3202);
                      KILL(lbits)(&zgsz3201);
                      KILL(lbits)(&zgsz3200);
                    }
                  }
                  {
                    lbits zgsz3203;
                    CREATE(lbits)(&zgsz3203);
                    CONVERT_OF(lbits, fbits)(&zgsz3203, zgaz384, UINT64_C(1) , true);
                    lbits zgsz3204;
                    CREATE(lbits)(&zgsz3204);
                    CONVERT_OF(lbits, fbits)(&zgsz3204, zgaz385, UINT64_C(3) , true);
                    lbits zgsz3205;
                    CREATE(lbits)(&zgsz3205);
                    append(&zgsz3205, zgsz3203, zgsz3204);
                    zgaz387 = CONVERT_OF(fbits, lbits)(zgsz3205, true);
                    KILL(lbits)(&zgsz3205);
                    KILL(lbits)(&zgsz3204);
                    KILL(lbits)(&zgsz3203);
                  }
                }
                {
                  lbits zgsz3206;
                  CREATE(lbits)(&zgsz3206);
                  CONVERT_OF(lbits, fbits)(&zgsz3206, zgaz386, UINT64_C(1) , true);
                  lbits zgsz3207;
                  CREATE(lbits)(&zgsz3207);
                  CONVERT_OF(lbits, fbits)(&zgsz3207, zgaz387, UINT64_C(4) , true);
                  lbits zgsz3208;
                  CREATE(lbits)(&zgsz3208);
                  append(&zgsz3208, zgsz3206, zgsz3207);
                  zgaz389 = CONVERT_OF(fbits, lbits)(zgsz3208, true);
                  KILL(lbits)(&zgsz3208);
                  KILL(lbits)(&zgsz3207);
                  KILL(lbits)(&zgsz3206);
                }
              }
              {
                lbits zgsz3209;
                CREATE(lbits)(&zgsz3209);
                CONVERT_OF(lbits, fbits)(&zgsz3209, zgaz388, UINT64_C(1) , true);
                lbits zgsz3210;
                CREATE(lbits)(&zgsz3210);
                CONVERT_OF(lbits, fbits)(&zgsz3210, zgaz389, UINT64_C(5) , true);
                lbits zgsz3211;
                CREATE(lbits)(&zgsz3211);
                append(&zgsz3211, zgsz3209, zgsz3210);
                zgaz391 = CONVERT_OF(fbits, lbits)(zgsz3211, true);
                KILL(lbits)(&zgsz3211);
                KILL(lbits)(&zgsz3210);
                KILL(lbits)(&zgsz3209);
              }
            }
            {
              lbits zgsz3212;
              CREATE(lbits)(&zgsz3212);
              CONVERT_OF(lbits, fbits)(&zgsz3212, zgaz390, UINT64_C(1) , true);
              lbits zgsz3213;
              CREATE(lbits)(&zgsz3213);
              CONVERT_OF(lbits, fbits)(&zgsz3213, zgaz391, UINT64_C(6) , true);
              lbits zgsz3214;
              CREATE(lbits)(&zgsz3214);
              append(&zgsz3214, zgsz3212, zgsz3213);
              zgaz393 = CONVERT_OF(fbits, lbits)(zgsz3214, true);
              KILL(lbits)(&zgsz3214);
              KILL(lbits)(&zgsz3213);
              KILL(lbits)(&zgsz3212);
            }
          }
          {
            lbits zgsz3215;
            CREATE(lbits)(&zgsz3215);
            CONVERT_OF(lbits, fbits)(&zgsz3215, zgaz392, UINT64_C(1) , true);
            lbits zgsz3216;
            CREATE(lbits)(&zgsz3216);
            CONVERT_OF(lbits, fbits)(&zgsz3216, zgaz393, UINT64_C(7) , true);
            lbits zgsz3217;
            CREATE(lbits)(&zgsz3217);
            append(&zgsz3217, zgsz3215, zgsz3216);
            zgaz395 = CONVERT_OF(fbits, lbits)(zgsz3217, true);
            KILL(lbits)(&zgsz3217);
            KILL(lbits)(&zgsz3216);
            KILL(lbits)(&zgsz3215);
          }
        }
        {
          lbits zgsz3218;
          CREATE(lbits)(&zgsz3218);
          CONVERT_OF(lbits, fbits)(&zgsz3218, zgaz394, UINT64_C(1) , true);
          lbits zgsz3219;
          CREATE(lbits)(&zgsz3219);
          CONVERT_OF(lbits, fbits)(&zgsz3219, zgaz395, UINT64_C(8) , true);
          lbits zgsz3220;
          CREATE(lbits)(&zgsz3220);
          append(&zgsz3220, zgsz3218, zgsz3219);
          zgaz397 = CONVERT_OF(fbits, lbits)(zgsz3220, true);
          KILL(lbits)(&zgsz3220);
          KILL(lbits)(&zgsz3219);
          KILL(lbits)(&zgsz3218);
        }
      }
      {
        lbits zgsz3221;
        CREATE(lbits)(&zgsz3221);
        CONVERT_OF(lbits, fbits)(&zgsz3221, zgaz396, UINT64_C(1) , true);
        lbits zgsz3222;
        CREATE(lbits)(&zgsz3222);
        CONVERT_OF(lbits, fbits)(&zgsz3222, zgaz397, UINT64_C(9) , true);
        lbits zgsz3223;
        CREATE(lbits)(&zgsz3223);
        append(&zgsz3223, zgsz3221, zgsz3222);
        zgaz399 = CONVERT_OF(fbits, lbits)(zgsz3223, true);
        KILL(lbits)(&zgsz3223);
        KILL(lbits)(&zgsz3222);
        KILL(lbits)(&zgsz3221);
      }
    }
    {
      lbits zgsz3224;
      CREATE(lbits)(&zgsz3224);
      CONVERT_OF(lbits, fbits)(&zgsz3224, zgaz398, UINT64_C(1) , true);
      lbits zgsz3225;
      CREATE(lbits)(&zgsz3225);
      CONVERT_OF(lbits, fbits)(&zgsz3225, zgaz399, UINT64_C(10) , true);
      lbits zgsz3226;
      CREATE(lbits)(&zgsz3226);
      append(&zgsz3226, zgsz3224, zgsz3225);
      zgaz3101 = CONVERT_OF(fbits, lbits)(zgsz3226, true);
      KILL(lbits)(&zgsz3226);
      KILL(lbits)(&zgsz3225);
      KILL(lbits)(&zgsz3224);
    }
  }
  {
    lbits zgsz3227;
    CREATE(lbits)(&zgsz3227);
    CONVERT_OF(lbits, fbits)(&zgsz3227, zgaz3100, UINT64_C(1) , true);
    lbits zgsz3228;
    CREATE(lbits)(&zgsz3228);
    CONVERT_OF(lbits, fbits)(&zgsz3228, zgaz3101, UINT64_C(11) , true);
    lbits zgsz3229;
    CREATE(lbits)(&zgsz3229);
    append(&zgsz3229, zgsz3227, zgsz3228);
    zcbz317 = CONVERT_OF(fbits, lbits)(zgsz3229, true);
    KILL(lbits)(&zgsz3229);
    KILL(lbits)(&zgsz3228);
    KILL(lbits)(&zgsz3227);
  }


end_function_82: ;
  return zcbz317;
end_block_exception_83: ;

  return UINT64_C(0xdeadc0de);
}

static struct zCapability sailgen_encCapabilityToCapability(bool, struct zEncCapability);

static struct zCapability sailgen_encCapabilityToCapability(bool zt, struct zEncCapability zc)
{
  __label__ cleanup_86, end_cleanup_87, end_function_85, end_block_exception_88;

  struct zCapability zcbz318;
  bool zinternal_E;
  {
    fbits zgaz3172;
    zgaz3172 = zc.zinternal_E;
    zinternal_E = sailgen_bit_to_bool(zgaz3172);
  }
  uint64_t zE;
  {
    sail_int zgsz3343;
    CREATE(sail_int)(&zgsz3343);
    CONVERT_OF(sail_int, mach_int)(&zgsz3343, INT64_C(6));
    lbits zgsz3344;
    CREATE(lbits)(&zgsz3344);
    sailgen_zzeros_implicit(&zgsz3344, zgsz3343);
    zE = CONVERT_OF(fbits, lbits)(zgsz3344, true);
    KILL(lbits)(&zgsz3344);
    KILL(sail_int)(&zgsz3343);
  }
  uint64_t zBs;
  {
    sail_int zgsz3341;
    CREATE(sail_int)(&zgsz3341);
    CONVERT_OF(sail_int, mach_int)(&zgsz3341, INT64_C(14));
    lbits zgsz3342;
    CREATE(lbits)(&zgsz3342);
    sailgen_zzeros_implicit(&zgsz3342, zgsz3341);
    zBs = CONVERT_OF(fbits, lbits)(zgsz3342, true);
    KILL(lbits)(&zgsz3342);
    KILL(sail_int)(&zgsz3341);
  }
  uint64_t zT;
  {
    sail_int zgsz3339;
    CREATE(sail_int)(&zgsz3339);
    CONVERT_OF(sail_int, mach_int)(&zgsz3339, INT64_C(12));
    lbits zgsz3340;
    CREATE(lbits)(&zgsz3340);
    sailgen_zzeros_implicit(&zgsz3340, zgsz3339);
    zT = CONVERT_OF(fbits, lbits)(zgsz3340, true);
    KILL(lbits)(&zgsz3340);
    KILL(sail_int)(&zgsz3339);
  }
  uint64_t zlenMSBs;
  {
    sail_int zgsz3337;
    CREATE(sail_int)(&zgsz3337);
    CONVERT_OF(sail_int, mach_int)(&zgsz3337, INT64_C(2));
    lbits zgsz3338;
    CREATE(lbits)(&zgsz3338);
    sailgen_zzeros_implicit(&zgsz3338, zgsz3337);
    zlenMSBs = CONVERT_OF(fbits, lbits)(zgsz3338, true);
    KILL(lbits)(&zgsz3338);
    KILL(sail_int)(&zgsz3337);
  }
  {
    unit zgsz336;
    if (zinternal_E) {
      {
        uint64_t zgaz3106;
        {
          uint64_t zgaz3102;
          zgaz3102 = zc.zT;
          int64_t zgaz3103;
          {
            sail_int zgsz3234;
            CREATE(sail_int)(&zgsz3234);
            CONVERT_OF(sail_int, mach_int)(&zgsz3234, zinternal_E_take_bits);
            sail_int zgsz3235;
            CREATE(sail_int)(&zgsz3235);
            CONVERT_OF(sail_int, mach_int)(&zgsz3235, INT64_C(1));
            sail_int zgsz3236;
            CREATE(sail_int)(&zgsz3236);
            sub_int(&zgsz3236, zgsz3234, zgsz3235);
            zgaz3103 = CONVERT_OF(mach_int, sail_int)(zgsz3236);
            KILL(sail_int)(&zgsz3236);
            KILL(sail_int)(&zgsz3235);
            KILL(sail_int)(&zgsz3234);
          }
          {
            lbits zgsz3230;
            CREATE(lbits)(&zgsz3230);
            CONVERT_OF(lbits, fbits)(&zgsz3230, zgaz3102, UINT64_C(12) , true);
            sail_int zgsz3231;
            CREATE(sail_int)(&zgsz3231);
            CONVERT_OF(sail_int, mach_int)(&zgsz3231, zgaz3103);
            sail_int zgsz3232;
            CREATE(sail_int)(&zgsz3232);
            CONVERT_OF(sail_int, mach_int)(&zgsz3232, INT64_C(0));
            lbits zgsz3233;
            CREATE(lbits)(&zgsz3233);
            vector_subrange_lbits(&zgsz3233, zgsz3230, zgsz3231, zgsz3232);
            zgaz3106 = CONVERT_OF(fbits, lbits)(zgsz3233, true);
            KILL(lbits)(&zgsz3233);
            KILL(sail_int)(&zgsz3232);
            KILL(sail_int)(&zgsz3231);
            KILL(lbits)(&zgsz3230);
          }
        }
        uint64_t zgaz3107;
        {
          uint64_t zgaz3104;
          zgaz3104 = zc.zB;
          int64_t zgaz3105;
          {
            sail_int zgsz3241;
            CREATE(sail_int)(&zgsz3241);
            CONVERT_OF(sail_int, mach_int)(&zgsz3241, zinternal_E_take_bits);
            sail_int zgsz3242;
            CREATE(sail_int)(&zgsz3242);
            CONVERT_OF(sail_int, mach_int)(&zgsz3242, INT64_C(1));
            sail_int zgsz3243;
            CREATE(sail_int)(&zgsz3243);
            sub_int(&zgsz3243, zgsz3241, zgsz3242);
            zgaz3105 = CONVERT_OF(mach_int, sail_int)(zgsz3243);
            KILL(sail_int)(&zgsz3243);
            KILL(sail_int)(&zgsz3242);
            KILL(sail_int)(&zgsz3241);
          }
          {
            lbits zgsz3237;
            CREATE(lbits)(&zgsz3237);
            CONVERT_OF(lbits, fbits)(&zgsz3237, zgaz3104, UINT64_C(14) , true);
            sail_int zgsz3238;
            CREATE(sail_int)(&zgsz3238);
            CONVERT_OF(sail_int, mach_int)(&zgsz3238, zgaz3105);
            sail_int zgsz3239;
            CREATE(sail_int)(&zgsz3239);
            CONVERT_OF(sail_int, mach_int)(&zgsz3239, INT64_C(0));
            lbits zgsz3240;
            CREATE(lbits)(&zgsz3240);
            vector_subrange_lbits(&zgsz3240, zgsz3237, zgsz3238, zgsz3239);
            zgaz3107 = CONVERT_OF(fbits, lbits)(zgsz3240, true);
            KILL(lbits)(&zgsz3240);
            KILL(sail_int)(&zgsz3239);
            KILL(sail_int)(&zgsz3238);
            KILL(lbits)(&zgsz3237);
          }
        }
        {
          lbits zgsz3244;
          CREATE(lbits)(&zgsz3244);
          CONVERT_OF(lbits, fbits)(&zgsz3244, zgaz3106, UINT64_C(3) , true);
          lbits zgsz3245;
          CREATE(lbits)(&zgsz3245);
          CONVERT_OF(lbits, fbits)(&zgsz3245, zgaz3107, UINT64_C(3) , true);
          lbits zgsz3246;
          CREATE(lbits)(&zgsz3246);
          append(&zgsz3246, zgsz3244, zgsz3245);
          zE = CONVERT_OF(fbits, lbits)(zgsz3246, true);
          KILL(lbits)(&zgsz3246);
          KILL(lbits)(&zgsz3245);
          KILL(lbits)(&zgsz3244);
        }
        unit zgsz341;
        zgsz341 = UNIT;
      }
      {
        zlenMSBs = UINT64_C(0b01);
        unit zgsz340;
        zgsz340 = UNIT;
      }
      {
        uint64_t zgaz3110;
        {
          uint64_t zgaz3108;
          zgaz3108 = zc.zT;
          int64_t zgaz3109;
          {
            sail_int zgsz3251;
            CREATE(sail_int)(&zgsz3251);
            CONVERT_OF(sail_int, mach_int)(&zgsz3251, zcap_mantissa_width);
            sail_int zgsz3252;
            CREATE(sail_int)(&zgsz3252);
            CONVERT_OF(sail_int, mach_int)(&zgsz3252, INT64_C(3));
            sail_int zgsz3253;
            CREATE(sail_int)(&zgsz3253);
            sub_int(&zgsz3253, zgsz3251, zgsz3252);
            zgaz3109 = CONVERT_OF(mach_int, sail_int)(zgsz3253);
            KILL(sail_int)(&zgsz3253);
            KILL(sail_int)(&zgsz3252);
            KILL(sail_int)(&zgsz3251);
          }
          {
            lbits zgsz3247;
            CREATE(lbits)(&zgsz3247);
            CONVERT_OF(lbits, fbits)(&zgsz3247, zgaz3108, UINT64_C(12) , true);
            sail_int zgsz3248;
            CREATE(sail_int)(&zgsz3248);
            CONVERT_OF(sail_int, mach_int)(&zgsz3248, zgaz3109);
            sail_int zgsz3249;
            CREATE(sail_int)(&zgsz3249);
            CONVERT_OF(sail_int, mach_int)(&zgsz3249, INT64_C(3));
            lbits zgsz3250;
            CREATE(lbits)(&zgsz3250);
            vector_subrange_lbits(&zgsz3250, zgsz3247, zgsz3248, zgsz3249);
            zgaz3110 = CONVERT_OF(fbits, lbits)(zgsz3250, true);
            KILL(lbits)(&zgsz3250);
            KILL(sail_int)(&zgsz3249);
            KILL(sail_int)(&zgsz3248);
            KILL(lbits)(&zgsz3247);
          }
        }
        uint64_t zgaz3111;
        {
          sail_int zgsz3257;
          CREATE(sail_int)(&zgsz3257);
          CONVERT_OF(sail_int, mach_int)(&zgsz3257, zinternal_E_take_bits);
          lbits zgsz3258;
          CREATE(lbits)(&zgsz3258);
          sailgen_zzeros_implicit(&zgsz3258, zgsz3257);
          zgaz3111 = CONVERT_OF(fbits, lbits)(zgsz3258, true);
          KILL(lbits)(&zgsz3258);
          KILL(sail_int)(&zgsz3257);
        }
        {
          lbits zgsz3254;
          CREATE(lbits)(&zgsz3254);
          CONVERT_OF(lbits, fbits)(&zgsz3254, zgaz3110, UINT64_C(9) , true);
          lbits zgsz3255;
          CREATE(lbits)(&zgsz3255);
          CONVERT_OF(lbits, fbits)(&zgsz3255, zgaz3111, UINT64_C(3) , true);
          lbits zgsz3256;
          CREATE(lbits)(&zgsz3256);
          append(&zgsz3256, zgsz3254, zgsz3255);
          zT = CONVERT_OF(fbits, lbits)(zgsz3256, true);
          KILL(lbits)(&zgsz3256);
          KILL(lbits)(&zgsz3255);
          KILL(lbits)(&zgsz3254);
        }
        unit zgsz339;
        zgsz339 = UNIT;
      }
      uint64_t zgaz3114;
      {
        uint64_t zgaz3112;
        zgaz3112 = zc.zB;
        int64_t zgaz3113;
        {
          sail_int zgsz3263;
          CREATE(sail_int)(&zgsz3263);
          CONVERT_OF(sail_int, mach_int)(&zgsz3263, zcap_mantissa_width);
          sail_int zgsz3264;
          CREATE(sail_int)(&zgsz3264);
          CONVERT_OF(sail_int, mach_int)(&zgsz3264, INT64_C(1));
          sail_int zgsz3265;
          CREATE(sail_int)(&zgsz3265);
          sub_int(&zgsz3265, zgsz3263, zgsz3264);
          zgaz3113 = CONVERT_OF(mach_int, sail_int)(zgsz3265);
          KILL(sail_int)(&zgsz3265);
          KILL(sail_int)(&zgsz3264);
          KILL(sail_int)(&zgsz3263);
        }
        {
          lbits zgsz3259;
          CREATE(lbits)(&zgsz3259);
          CONVERT_OF(lbits, fbits)(&zgsz3259, zgaz3112, UINT64_C(14) , true);
          sail_int zgsz3260;
          CREATE(sail_int)(&zgsz3260);
          CONVERT_OF(sail_int, mach_int)(&zgsz3260, zgaz3113);
          sail_int zgsz3261;
          CREATE(sail_int)(&zgsz3261);
          CONVERT_OF(sail_int, mach_int)(&zgsz3261, INT64_C(3));
          lbits zgsz3262;
          CREATE(lbits)(&zgsz3262);
          vector_subrange_lbits(&zgsz3262, zgsz3259, zgsz3260, zgsz3261);
          zgaz3114 = CONVERT_OF(fbits, lbits)(zgsz3262, true);
          KILL(lbits)(&zgsz3262);
          KILL(sail_int)(&zgsz3261);
          KILL(sail_int)(&zgsz3260);
          KILL(lbits)(&zgsz3259);
        }
      }
      uint64_t zgaz3115;
      {
        sail_int zgsz3269;
        CREATE(sail_int)(&zgsz3269);
        CONVERT_OF(sail_int, mach_int)(&zgsz3269, zinternal_E_take_bits);
        lbits zgsz3270;
        CREATE(lbits)(&zgsz3270);
        sailgen_zzeros_implicit(&zgsz3270, zgsz3269);
        zgaz3115 = CONVERT_OF(fbits, lbits)(zgsz3270, true);
        KILL(lbits)(&zgsz3270);
        KILL(sail_int)(&zgsz3269);
      }
      {
        lbits zgsz3266;
        CREATE(lbits)(&zgsz3266);
        CONVERT_OF(lbits, fbits)(&zgsz3266, zgaz3114, UINT64_C(11) , true);
        lbits zgsz3267;
        CREATE(lbits)(&zgsz3267);
        CONVERT_OF(lbits, fbits)(&zgsz3267, zgaz3115, UINT64_C(3) , true);
        lbits zgsz3268;
        CREATE(lbits)(&zgsz3268);
        append(&zgsz3268, zgsz3266, zgsz3267);
        zBs = CONVERT_OF(fbits, lbits)(zgsz3268, true);
        KILL(lbits)(&zgsz3268);
        KILL(lbits)(&zgsz3267);
        KILL(lbits)(&zgsz3266);
      }
      zgsz336 = UNIT;
    } else {
      {
        zlenMSBs = UINT64_C(0b00);
        unit zgsz338;
        zgsz338 = UNIT;
      }
      {
        zT = zc.zT;
        unit zgsz337;
        zgsz337 = UNIT;
      }
      zBs = zc.zB;
      zgsz336 = UNIT;
    }
  }
  uint64_t zcarry_out;
  {
    bool zgaz3171;
    {
      uint64_t zgaz3170;
      {
        int64_t zgaz3169;
        {
          sail_int zgsz3275;
          CREATE(sail_int)(&zgsz3275);
          CONVERT_OF(sail_int, mach_int)(&zgsz3275, zcap_mantissa_width);
          sail_int zgsz3276;
          CREATE(sail_int)(&zgsz3276);
          CONVERT_OF(sail_int, mach_int)(&zgsz3276, INT64_C(3));
          sail_int zgsz3277;
          CREATE(sail_int)(&zgsz3277);
          sub_int(&zgsz3277, zgsz3275, zgsz3276);
          zgaz3169 = CONVERT_OF(mach_int, sail_int)(zgsz3277);
          KILL(sail_int)(&zgsz3277);
          KILL(sail_int)(&zgsz3276);
          KILL(sail_int)(&zgsz3275);
        }
        {
          lbits zgsz3271;
          CREATE(lbits)(&zgsz3271);
          CONVERT_OF(lbits, fbits)(&zgsz3271, zBs, UINT64_C(14) , true);
          sail_int zgsz3272;
          CREATE(sail_int)(&zgsz3272);
          CONVERT_OF(sail_int, mach_int)(&zgsz3272, zgaz3169);
          sail_int zgsz3273;
          CREATE(sail_int)(&zgsz3273);
          CONVERT_OF(sail_int, mach_int)(&zgsz3273, INT64_C(0));
          lbits zgsz3274;
          CREATE(lbits)(&zgsz3274);
          vector_subrange_lbits(&zgsz3274, zgsz3271, zgsz3272, zgsz3273);
          zgaz3170 = CONVERT_OF(fbits, lbits)(zgsz3274, true);
          KILL(lbits)(&zgsz3274);
          KILL(sail_int)(&zgsz3273);
          KILL(sail_int)(&zgsz3272);
          KILL(lbits)(&zgsz3271);
        }
      }
      {
        lbits zgsz3278;
        CREATE(lbits)(&zgsz3278);
        CONVERT_OF(lbits, fbits)(&zgsz3278, zT, UINT64_C(12) , true);
        lbits zgsz3279;
        CREATE(lbits)(&zgsz3279);
        CONVERT_OF(lbits, fbits)(&zgsz3279, zgaz3170, UINT64_C(12) , true);
        zgaz3171 = sailgen_z8operatorz0zI_uz9(zgsz3278, zgsz3279);
        KILL(lbits)(&zgsz3279);
        KILL(lbits)(&zgsz3278);
      }
    }
    if (zgaz3171) {  zcarry_out = UINT64_C(0b01);  } else {  zcarry_out = UINT64_C(0b00);  }
  }
  uint64_t zTtop2;
  {
    uint64_t zgaz3168;
    {
      uint64_t zgaz3167;
      {
        int64_t zgaz3165;
        {
          sail_int zgsz3287;
          CREATE(sail_int)(&zgsz3287);
          CONVERT_OF(sail_int, mach_int)(&zgsz3287, zcap_mantissa_width);
          sail_int zgsz3288;
          CREATE(sail_int)(&zgsz3288);
          CONVERT_OF(sail_int, mach_int)(&zgsz3288, INT64_C(1));
          sail_int zgsz3289;
          CREATE(sail_int)(&zgsz3289);
          sub_int(&zgsz3289, zgsz3287, zgsz3288);
          zgaz3165 = CONVERT_OF(mach_int, sail_int)(zgsz3289);
          KILL(sail_int)(&zgsz3289);
          KILL(sail_int)(&zgsz3288);
          KILL(sail_int)(&zgsz3287);
        }
        int64_t zgaz3166;
        {
          sail_int zgsz3284;
          CREATE(sail_int)(&zgsz3284);
          CONVERT_OF(sail_int, mach_int)(&zgsz3284, zcap_mantissa_width);
          sail_int zgsz3285;
          CREATE(sail_int)(&zgsz3285);
          CONVERT_OF(sail_int, mach_int)(&zgsz3285, INT64_C(2));
          sail_int zgsz3286;
          CREATE(sail_int)(&zgsz3286);
          sub_int(&zgsz3286, zgsz3284, zgsz3285);
          zgaz3166 = CONVERT_OF(mach_int, sail_int)(zgsz3286);
          KILL(sail_int)(&zgsz3286);
          KILL(sail_int)(&zgsz3285);
          KILL(sail_int)(&zgsz3284);
        }
        {
          lbits zgsz3280;
          CREATE(lbits)(&zgsz3280);
          CONVERT_OF(lbits, fbits)(&zgsz3280, zBs, UINT64_C(14) , true);
          sail_int zgsz3281;
          CREATE(sail_int)(&zgsz3281);
          CONVERT_OF(sail_int, mach_int)(&zgsz3281, zgaz3165);
          sail_int zgsz3282;
          CREATE(sail_int)(&zgsz3282);
          CONVERT_OF(sail_int, mach_int)(&zgsz3282, zgaz3166);
          lbits zgsz3283;
          CREATE(lbits)(&zgsz3283);
          vector_subrange_lbits(&zgsz3283, zgsz3280, zgsz3281, zgsz3282);
          zgaz3167 = CONVERT_OF(fbits, lbits)(zgsz3283, true);
          KILL(lbits)(&zgsz3283);
          KILL(sail_int)(&zgsz3282);
          KILL(sail_int)(&zgsz3281);
          KILL(lbits)(&zgsz3280);
        }
      }
      {
        lbits zgsz3290;
        CREATE(lbits)(&zgsz3290);
        CONVERT_OF(lbits, fbits)(&zgsz3290, zgaz3167, UINT64_C(2) , true);
        lbits zgsz3291;
        CREATE(lbits)(&zgsz3291);
        CONVERT_OF(lbits, fbits)(&zgsz3291, zlenMSBs, UINT64_C(2) , true);
        lbits zgsz3292;
        CREATE(lbits)(&zgsz3292);
        add_bits(&zgsz3292, zgsz3290, zgsz3291);
        zgaz3168 = CONVERT_OF(fbits, lbits)(zgsz3292, true);
        KILL(lbits)(&zgsz3292);
        KILL(lbits)(&zgsz3291);
        KILL(lbits)(&zgsz3290);
      }
    }
    {
      lbits zgsz3293;
      CREATE(lbits)(&zgsz3293);
      CONVERT_OF(lbits, fbits)(&zgsz3293, zgaz3168, UINT64_C(2) , true);
      lbits zgsz3294;
      CREATE(lbits)(&zgsz3294);
      CONVERT_OF(lbits, fbits)(&zgsz3294, zcarry_out, UINT64_C(2) , true);
      lbits zgsz3295;
      CREATE(lbits)(&zgsz3295);
      add_bits(&zgsz3295, zgsz3293, zgsz3294);
      zTtop2 = CONVERT_OF(fbits, lbits)(zgsz3295, true);
      KILL(lbits)(&zgsz3295);
      KILL(lbits)(&zgsz3294);
      KILL(lbits)(&zgsz3293);
    }
  }
  struct zCapability zgaz3164;
  {
    uint64_t zgaz3120;
    {
      bool zgaz3116;
      {
        sail_int zgsz3306;
        CREATE(sail_int)(&zgsz3306);
        CONVERT_OF(sail_int, mach_int)(&zgsz3306, zcap_uperms_width);
        sail_int zgsz3307;
        CREATE(sail_int)(&zgsz3307);
        CONVERT_OF(sail_int, mach_int)(&zgsz3307, INT64_C(0));
        zgaz3116 = gt(zgsz3306, zgsz3307);
        KILL(sail_int)(&zgsz3307);
        KILL(sail_int)(&zgsz3306);
      }
      uint64_t zgaz3118;
      zgaz3118 = zc.zperms;
      int64_t zgaz3119;
      {
        int64_t zgaz3117;
        {
          sail_int zgsz3299;
          CREATE(sail_int)(&zgsz3299);
          CONVERT_OF(sail_int, mach_int)(&zgsz3299, zcap_hperms_width);
          sail_int zgsz3300;
          CREATE(sail_int)(&zgsz3300);
          CONVERT_OF(sail_int, mach_int)(&zgsz3300, zcap_uperms_width);
          sail_int zgsz3301;
          CREATE(sail_int)(&zgsz3301);
          add_int(&zgsz3301, zgsz3299, zgsz3300);
          zgaz3117 = CONVERT_OF(mach_int, sail_int)(zgsz3301);
          KILL(sail_int)(&zgsz3301);
          KILL(sail_int)(&zgsz3300);
          KILL(sail_int)(&zgsz3299);
        }
        {
          sail_int zgsz3296;
          CREATE(sail_int)(&zgsz3296);
          CONVERT_OF(sail_int, mach_int)(&zgsz3296, zgaz3117);
          sail_int zgsz3297;
          CREATE(sail_int)(&zgsz3297);
          CONVERT_OF(sail_int, mach_int)(&zgsz3297, INT64_C(1));
          sail_int zgsz3298;
          CREATE(sail_int)(&zgsz3298);
          sub_int(&zgsz3298, zgsz3296, zgsz3297);
          zgaz3119 = CONVERT_OF(mach_int, sail_int)(zgsz3298);
          KILL(sail_int)(&zgsz3298);
          KILL(sail_int)(&zgsz3297);
          KILL(sail_int)(&zgsz3296);
        }
      }
      {
        lbits zgsz3302;
        CREATE(lbits)(&zgsz3302);
        CONVERT_OF(lbits, fbits)(&zgsz3302, zgaz3118, UINT64_C(16) , true);
        sail_int zgsz3303;
        CREATE(sail_int)(&zgsz3303);
        CONVERT_OF(sail_int, mach_int)(&zgsz3303, zgaz3119);
        sail_int zgsz3304;
        CREATE(sail_int)(&zgsz3304);
        CONVERT_OF(sail_int, mach_int)(&zgsz3304, zcap_hperms_width);
        lbits zgsz3305;
        CREATE(lbits)(&zgsz3305);
        vector_subrange_lbits(&zgsz3305, zgsz3302, zgsz3303, zgsz3304);
        zgaz3120 = CONVERT_OF(fbits, lbits)(zgsz3305, true);
        KILL(lbits)(&zgsz3305);
        KILL(sail_int)(&zgsz3304);
        KILL(sail_int)(&zgsz3303);
        KILL(lbits)(&zgsz3302);
      }
    }
    bool zgaz3123;
    {
      fbits zgaz3122;
      {
        uint64_t zgaz3121;
        zgaz3121 = zc.zperms;
        {
          lbits zgsz3308;
          CREATE(lbits)(&zgsz3308);
          CONVERT_OF(lbits, fbits)(&zgsz3308, zgaz3121, UINT64_C(16) , true);
          sail_int zgsz3309;
          CREATE(sail_int)(&zgsz3309);
          CONVERT_OF(sail_int, mach_int)(&zgsz3309, INT64_C(11));
          zgaz3122 = bitvector_access(zgsz3308, zgsz3309);
          KILL(sail_int)(&zgsz3309);
          KILL(lbits)(&zgsz3308);
        }
      }
      zgaz3123 = sailgen_bit_to_bool(zgaz3122);
    }
    bool zgaz3126;
    {
      fbits zgaz3125;
      {
        uint64_t zgaz3124;
        zgaz3124 = zc.zperms;
        {
          lbits zgsz3310;
          CREATE(lbits)(&zgsz3310);
          CONVERT_OF(lbits, fbits)(&zgsz3310, zgaz3124, UINT64_C(16) , true);
          sail_int zgsz3311;
          CREATE(sail_int)(&zgsz3311);
          CONVERT_OF(sail_int, mach_int)(&zgsz3311, INT64_C(10));
          zgaz3125 = bitvector_access(zgsz3310, zgsz3311);
          KILL(sail_int)(&zgsz3311);
          KILL(lbits)(&zgsz3310);
        }
      }
      zgaz3126 = sailgen_bit_to_bool(zgaz3125);
    }
    bool zgaz3129;
    {
      fbits zgaz3128;
      {
        uint64_t zgaz3127;
        zgaz3127 = zc.zperms;
        {
          lbits zgsz3312;
          CREATE(lbits)(&zgsz3312);
          CONVERT_OF(lbits, fbits)(&zgsz3312, zgaz3127, UINT64_C(16) , true);
          sail_int zgsz3313;
          CREATE(sail_int)(&zgsz3313);
          CONVERT_OF(sail_int, mach_int)(&zgsz3313, INT64_C(9));
          zgaz3128 = bitvector_access(zgsz3312, zgsz3313);
          KILL(sail_int)(&zgsz3313);
          KILL(lbits)(&zgsz3312);
        }
      }
      zgaz3129 = sailgen_bit_to_bool(zgaz3128);
    }
    bool zgaz3132;
    {
      fbits zgaz3131;
      {
        uint64_t zgaz3130;
        zgaz3130 = zc.zperms;
        {
          lbits zgsz3314;
          CREATE(lbits)(&zgsz3314);
          CONVERT_OF(lbits, fbits)(&zgsz3314, zgaz3130, UINT64_C(16) , true);
          sail_int zgsz3315;
          CREATE(sail_int)(&zgsz3315);
          CONVERT_OF(sail_int, mach_int)(&zgsz3315, INT64_C(8));
          zgaz3131 = bitvector_access(zgsz3314, zgsz3315);
          KILL(sail_int)(&zgsz3315);
          KILL(lbits)(&zgsz3314);
        }
      }
      zgaz3132 = sailgen_bit_to_bool(zgaz3131);
    }
    bool zgaz3135;
    {
      fbits zgaz3134;
      {
        uint64_t zgaz3133;
        zgaz3133 = zc.zperms;
        {
          lbits zgsz3316;
          CREATE(lbits)(&zgsz3316);
          CONVERT_OF(lbits, fbits)(&zgsz3316, zgaz3133, UINT64_C(16) , true);
          sail_int zgsz3317;
          CREATE(sail_int)(&zgsz3317);
          CONVERT_OF(sail_int, mach_int)(&zgsz3317, INT64_C(7));
          zgaz3134 = bitvector_access(zgsz3316, zgsz3317);
          KILL(sail_int)(&zgsz3317);
          KILL(lbits)(&zgsz3316);
        }
      }
      zgaz3135 = sailgen_bit_to_bool(zgaz3134);
    }
    bool zgaz3138;
    {
      fbits zgaz3137;
      {
        uint64_t zgaz3136;
        zgaz3136 = zc.zperms;
        {
          lbits zgsz3318;
          CREATE(lbits)(&zgsz3318);
          CONVERT_OF(lbits, fbits)(&zgsz3318, zgaz3136, UINT64_C(16) , true);
          sail_int zgsz3319;
          CREATE(sail_int)(&zgsz3319);
          CONVERT_OF(sail_int, mach_int)(&zgsz3319, INT64_C(6));
          zgaz3137 = bitvector_access(zgsz3318, zgsz3319);
          KILL(sail_int)(&zgsz3319);
          KILL(lbits)(&zgsz3318);
        }
      }
      zgaz3138 = sailgen_bit_to_bool(zgaz3137);
    }
    bool zgaz3141;
    {
      fbits zgaz3140;
      {
        uint64_t zgaz3139;
        zgaz3139 = zc.zperms;
        {
          lbits zgsz3320;
          CREATE(lbits)(&zgsz3320);
          CONVERT_OF(lbits, fbits)(&zgsz3320, zgaz3139, UINT64_C(16) , true);
          sail_int zgsz3321;
          CREATE(sail_int)(&zgsz3321);
          CONVERT_OF(sail_int, mach_int)(&zgsz3321, INT64_C(5));
          zgaz3140 = bitvector_access(zgsz3320, zgsz3321);
          KILL(sail_int)(&zgsz3321);
          KILL(lbits)(&zgsz3320);
        }
      }
      zgaz3141 = sailgen_bit_to_bool(zgaz3140);
    }
    bool zgaz3144;
    {
      fbits zgaz3143;
      {
        uint64_t zgaz3142;
        zgaz3142 = zc.zperms;
        {
          lbits zgsz3322;
          CREATE(lbits)(&zgsz3322);
          CONVERT_OF(lbits, fbits)(&zgsz3322, zgaz3142, UINT64_C(16) , true);
          sail_int zgsz3323;
          CREATE(sail_int)(&zgsz3323);
          CONVERT_OF(sail_int, mach_int)(&zgsz3323, INT64_C(4));
          zgaz3143 = bitvector_access(zgsz3322, zgsz3323);
          KILL(sail_int)(&zgsz3323);
          KILL(lbits)(&zgsz3322);
        }
      }
      zgaz3144 = sailgen_bit_to_bool(zgaz3143);
    }
    bool zgaz3147;
    {
      fbits zgaz3146;
      {
        uint64_t zgaz3145;
        zgaz3145 = zc.zperms;
        {
          lbits zgsz3324;
          CREATE(lbits)(&zgsz3324);
          CONVERT_OF(lbits, fbits)(&zgsz3324, zgaz3145, UINT64_C(16) , true);
          sail_int zgsz3325;
          CREATE(sail_int)(&zgsz3325);
          CONVERT_OF(sail_int, mach_int)(&zgsz3325, INT64_C(3));
          zgaz3146 = bitvector_access(zgsz3324, zgsz3325);
          KILL(sail_int)(&zgsz3325);
          KILL(lbits)(&zgsz3324);
        }
      }
      zgaz3147 = sailgen_bit_to_bool(zgaz3146);
    }
    bool zgaz3150;
    {
      fbits zgaz3149;
      {
        uint64_t zgaz3148;
        zgaz3148 = zc.zperms;
        {
          lbits zgsz3326;
          CREATE(lbits)(&zgsz3326);
          CONVERT_OF(lbits, fbits)(&zgsz3326, zgaz3148, UINT64_C(16) , true);
          sail_int zgsz3327;
          CREATE(sail_int)(&zgsz3327);
          CONVERT_OF(sail_int, mach_int)(&zgsz3327, INT64_C(2));
          zgaz3149 = bitvector_access(zgsz3326, zgsz3327);
          KILL(sail_int)(&zgsz3327);
          KILL(lbits)(&zgsz3326);
        }
      }
      zgaz3150 = sailgen_bit_to_bool(zgaz3149);
    }
    bool zgaz3153;
    {
      fbits zgaz3152;
      {
        uint64_t zgaz3151;
        zgaz3151 = zc.zperms;
        {
          lbits zgsz3328;
          CREATE(lbits)(&zgsz3328);
          CONVERT_OF(lbits, fbits)(&zgsz3328, zgaz3151, UINT64_C(16) , true);
          sail_int zgsz3329;
          CREATE(sail_int)(&zgsz3329);
          CONVERT_OF(sail_int, mach_int)(&zgsz3329, INT64_C(1));
          zgaz3152 = bitvector_access(zgsz3328, zgsz3329);
          KILL(sail_int)(&zgsz3329);
          KILL(lbits)(&zgsz3328);
        }
      }
      zgaz3153 = sailgen_bit_to_bool(zgaz3152);
    }
    bool zgaz3156;
    {
      fbits zgaz3155;
      {
        uint64_t zgaz3154;
        zgaz3154 = zc.zperms;
        {
          lbits zgsz3330;
          CREATE(lbits)(&zgsz3330);
          CONVERT_OF(lbits, fbits)(&zgsz3330, zgaz3154, UINT64_C(16) , true);
          sail_int zgsz3331;
          CREATE(sail_int)(&zgsz3331);
          CONVERT_OF(sail_int, mach_int)(&zgsz3331, INT64_C(0));
          zgaz3155 = bitvector_access(zgsz3330, zgsz3331);
          KILL(sail_int)(&zgsz3331);
          KILL(lbits)(&zgsz3330);
        }
      }
      zgaz3156 = sailgen_bit_to_bool(zgaz3155);
    }
    uint64_t zgaz3157;
    zgaz3157 = zc.zreserved;
    bool zgaz3160;
    {
      fbits zgaz3159;
      {
        uint64_t zgaz3158;
        zgaz3158 = zc.zflags;
        {
          lbits zgsz3332;
          CREATE(lbits)(&zgsz3332);
          CONVERT_OF(lbits, fbits)(&zgsz3332, zgaz3158, UINT64_C(1) , true);
          sail_int zgsz3333;
          CREATE(sail_int)(&zgsz3333);
          CONVERT_OF(sail_int, mach_int)(&zgsz3333, INT64_C(0));
          zgaz3159 = bitvector_access(zgsz3332, zgsz3333);
          KILL(sail_int)(&zgsz3333);
          KILL(lbits)(&zgsz3332);
        }
      }
      zgaz3160 = sailgen_bit_to_bool(zgaz3159);
    }
    uint64_t zgaz3161;
    {
      lbits zgsz3334;
      CREATE(lbits)(&zgsz3334);
      CONVERT_OF(lbits, fbits)(&zgsz3334, zTtop2, UINT64_C(2) , true);
      lbits zgsz3335;
      CREATE(lbits)(&zgsz3335);
      CONVERT_OF(lbits, fbits)(&zgsz3335, zT, UINT64_C(12) , true);
      lbits zgsz3336;
      CREATE(lbits)(&zgsz3336);
      append(&zgsz3336, zgsz3334, zgsz3335);
      zgaz3161 = CONVERT_OF(fbits, lbits)(zgsz3336, true);
      KILL(lbits)(&zgsz3336);
      KILL(lbits)(&zgsz3335);
      KILL(lbits)(&zgsz3334);
    }
    uint64_t zgaz3162;
    zgaz3162 = zc.zotype;
    uint64_t zgaz3163;
    zgaz3163 = zc.zaddress;
    struct zCapability zgsz342;
    zgsz342.zB = zBs;
    zgsz342.zE = zE;
    zgsz342.zT = zgaz3161;
    zgsz342.zaccess_system_regs = zgaz3126;
    zgsz342.zaddress = zgaz3163;
    zgsz342.zflag_cap_mode = zgaz3160;
    zgsz342.zglobal = zgaz3156;
    zgsz342.zinternal_E = zinternal_E;
    zgsz342.zotype = zgaz3162;
    zgsz342.zpermit_cinvoke = zgaz3132;
    zgsz342.zpermit_execute = zgaz3153;
    zgsz342.zpermit_load = zgaz3150;
    zgsz342.zpermit_load_cap = zgaz3144;
    zgsz342.zpermit_seal = zgaz3135;
    zgsz342.zpermit_set_CID = zgaz3123;
    zgsz342.zpermit_store = zgaz3147;
    zgsz342.zpermit_store_cap = zgaz3141;
    zgsz342.zpermit_store_local_cap = zgaz3138;
    zgsz342.zpermit_unseal = zgaz3129;
    zgsz342.zreserved = zgaz3157;
    zgsz342.ztag = zt;
    zgsz342.zuperms = zgaz3120;
    zgaz3164 = zgsz342;
  }
  zcbz318 = zgaz3164;
  goto cleanup_86;
  /* unreachable after return */








  goto end_cleanup_87;
cleanup_86: ;








  goto end_function_85;
end_cleanup_87: ;
end_function_85: ;
  return zcbz318;
end_block_exception_88: ;
  struct zCapability zcbz348 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  return zcbz348;
}

static struct zCapability sailgen_capBitsToCapability(bool, lbits);

static struct zCapability sailgen_capBitsToCapability(bool zt, lbits zc)
{
  __label__ end_function_90, end_block_exception_91;

  struct zCapability zcbz319;
  struct zEncCapability zgaz3173;
  zgaz3173 = sailgen_capBitsToEncCapability(zc);
  zcbz319 = sailgen_encCapabilityToCapability(zt, zgaz3173);

end_function_90: ;
  return zcbz319;
end_block_exception_91: ;
  struct zCapability zcbz349 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  return zcbz349;
}

static struct zEncCapability sailgen_capToEncCap(struct zCapability);

static struct zEncCapability sailgen_capToEncCap(struct zCapability zcap)
{
  __label__ cleanup_94, end_cleanup_95, end_function_93, end_block_exception_96;

  struct zEncCapability zcbz320;
  uint64_t zt_hi;
  {
    uint64_t zgaz3200;
    zgaz3200 = zcap.zT;
    int64_t zgaz3201;
    {
      sail_int zgsz3349;
      CREATE(sail_int)(&zgsz3349);
      CONVERT_OF(sail_int, mach_int)(&zgsz3349, zcap_mantissa_width);
      sail_int zgsz3350;
      CREATE(sail_int)(&zgsz3350);
      CONVERT_OF(sail_int, mach_int)(&zgsz3350, INT64_C(3));
      sail_int zgsz3351;
      CREATE(sail_int)(&zgsz3351);
      sub_int(&zgsz3351, zgsz3349, zgsz3350);
      zgaz3201 = CONVERT_OF(mach_int, sail_int)(zgsz3351);
      KILL(sail_int)(&zgsz3351);
      KILL(sail_int)(&zgsz3350);
      KILL(sail_int)(&zgsz3349);
    }
    {
      lbits zgsz3345;
      CREATE(lbits)(&zgsz3345);
      CONVERT_OF(lbits, fbits)(&zgsz3345, zgaz3200, UINT64_C(14) , true);
      sail_int zgsz3346;
      CREATE(sail_int)(&zgsz3346);
      CONVERT_OF(sail_int, mach_int)(&zgsz3346, zgaz3201);
      sail_int zgsz3347;
      CREATE(sail_int)(&zgsz3347);
      CONVERT_OF(sail_int, mach_int)(&zgsz3347, zinternal_E_take_bits);
      lbits zgsz3348;
      CREATE(lbits)(&zgsz3348);
      vector_subrange_lbits(&zgsz3348, zgsz3345, zgsz3346, zgsz3347);
      zt_hi = CONVERT_OF(fbits, lbits)(zgsz3348, true);
      KILL(lbits)(&zgsz3348);
      KILL(sail_int)(&zgsz3347);
      KILL(sail_int)(&zgsz3346);
      KILL(lbits)(&zgsz3345);
    }
  }
  uint64_t zt_lo;
  {
    uint64_t zgaz3198;
    zgaz3198 = zcap.zT;
    int64_t zgaz3199;
    {
      sail_int zgsz3356;
      CREATE(sail_int)(&zgsz3356);
      CONVERT_OF(sail_int, mach_int)(&zgsz3356, zinternal_E_take_bits);
      sail_int zgsz3357;
      CREATE(sail_int)(&zgsz3357);
      CONVERT_OF(sail_int, mach_int)(&zgsz3357, INT64_C(1));
      sail_int zgsz3358;
      CREATE(sail_int)(&zgsz3358);
      sub_int(&zgsz3358, zgsz3356, zgsz3357);
      zgaz3199 = CONVERT_OF(mach_int, sail_int)(zgsz3358);
      KILL(sail_int)(&zgsz3358);
      KILL(sail_int)(&zgsz3357);
      KILL(sail_int)(&zgsz3356);
    }
    {
      lbits zgsz3352;
      CREATE(lbits)(&zgsz3352);
      CONVERT_OF(lbits, fbits)(&zgsz3352, zgaz3198, UINT64_C(14) , true);
      sail_int zgsz3353;
      CREATE(sail_int)(&zgsz3353);
      CONVERT_OF(sail_int, mach_int)(&zgsz3353, zgaz3199);
      sail_int zgsz3354;
      CREATE(sail_int)(&zgsz3354);
      CONVERT_OF(sail_int, mach_int)(&zgsz3354, INT64_C(0));
      lbits zgsz3355;
      CREATE(lbits)(&zgsz3355);
      vector_subrange_lbits(&zgsz3355, zgsz3352, zgsz3353, zgsz3354);
      zt_lo = CONVERT_OF(fbits, lbits)(zgsz3355, true);
      KILL(lbits)(&zgsz3355);
      KILL(sail_int)(&zgsz3354);
      KILL(sail_int)(&zgsz3353);
      KILL(lbits)(&zgsz3352);
    }
  }
  uint64_t zb_hi;
  {
    uint64_t zgaz3196;
    zgaz3196 = zcap.zB;
    int64_t zgaz3197;
    {
      sail_int zgsz3363;
      CREATE(sail_int)(&zgsz3363);
      CONVERT_OF(sail_int, mach_int)(&zgsz3363, zcap_mantissa_width);
      sail_int zgsz3364;
      CREATE(sail_int)(&zgsz3364);
      CONVERT_OF(sail_int, mach_int)(&zgsz3364, INT64_C(1));
      sail_int zgsz3365;
      CREATE(sail_int)(&zgsz3365);
      sub_int(&zgsz3365, zgsz3363, zgsz3364);
      zgaz3197 = CONVERT_OF(mach_int, sail_int)(zgsz3365);
      KILL(sail_int)(&zgsz3365);
      KILL(sail_int)(&zgsz3364);
      KILL(sail_int)(&zgsz3363);
    }
    {
      lbits zgsz3359;
      CREATE(lbits)(&zgsz3359);
      CONVERT_OF(lbits, fbits)(&zgsz3359, zgaz3196, UINT64_C(14) , true);
      sail_int zgsz3360;
      CREATE(sail_int)(&zgsz3360);
      CONVERT_OF(sail_int, mach_int)(&zgsz3360, zgaz3197);
      sail_int zgsz3361;
      CREATE(sail_int)(&zgsz3361);
      CONVERT_OF(sail_int, mach_int)(&zgsz3361, zinternal_E_take_bits);
      lbits zgsz3362;
      CREATE(lbits)(&zgsz3362);
      vector_subrange_lbits(&zgsz3362, zgsz3359, zgsz3360, zgsz3361);
      zb_hi = CONVERT_OF(fbits, lbits)(zgsz3362, true);
      KILL(lbits)(&zgsz3362);
      KILL(sail_int)(&zgsz3361);
      KILL(sail_int)(&zgsz3360);
      KILL(lbits)(&zgsz3359);
    }
  }
  uint64_t zb_lo;
  {
    uint64_t zgaz3194;
    zgaz3194 = zcap.zB;
    int64_t zgaz3195;
    {
      sail_int zgsz3370;
      CREATE(sail_int)(&zgsz3370);
      CONVERT_OF(sail_int, mach_int)(&zgsz3370, zinternal_E_take_bits);
      sail_int zgsz3371;
      CREATE(sail_int)(&zgsz3371);
      CONVERT_OF(sail_int, mach_int)(&zgsz3371, INT64_C(1));
      sail_int zgsz3372;
      CREATE(sail_int)(&zgsz3372);
      sub_int(&zgsz3372, zgsz3370, zgsz3371);
      zgaz3195 = CONVERT_OF(mach_int, sail_int)(zgsz3372);
      KILL(sail_int)(&zgsz3372);
      KILL(sail_int)(&zgsz3371);
      KILL(sail_int)(&zgsz3370);
    }
    {
      lbits zgsz3366;
      CREATE(lbits)(&zgsz3366);
      CONVERT_OF(lbits, fbits)(&zgsz3366, zgaz3194, UINT64_C(14) , true);
      sail_int zgsz3367;
      CREATE(sail_int)(&zgsz3367);
      CONVERT_OF(sail_int, mach_int)(&zgsz3367, zgaz3195);
      sail_int zgsz3368;
      CREATE(sail_int)(&zgsz3368);
      CONVERT_OF(sail_int, mach_int)(&zgsz3368, INT64_C(0));
      lbits zgsz3369;
      CREATE(lbits)(&zgsz3369);
      vector_subrange_lbits(&zgsz3369, zgsz3366, zgsz3367, zgsz3368);
      zb_lo = CONVERT_OF(fbits, lbits)(zgsz3369, true);
      KILL(lbits)(&zgsz3369);
      KILL(sail_int)(&zgsz3368);
      KILL(sail_int)(&zgsz3367);
      KILL(lbits)(&zgsz3366);
    }
  }
  {
    bool zgaz3174;
    zgaz3174 = zcap.zinternal_E;
    unit zgsz343;
    if (zgaz3174) {
      {
        uint64_t zgaz3176;
        zgaz3176 = zcap.zE;
        int64_t zgaz3177;
        {
          int64_t zgaz3175;
          {
            sail_int zgsz3376;
            CREATE(sail_int)(&zgsz3376);
            CONVERT_OF(sail_int, mach_int)(&zgsz3376, INT64_C(2));
            sail_int zgsz3377;
            CREATE(sail_int)(&zgsz3377);
            CONVERT_OF(sail_int, mach_int)(&zgsz3377, zinternal_E_take_bits);
            sail_int zgsz3378;
            CREATE(sail_int)(&zgsz3378);
            mult_int(&zgsz3378, zgsz3376, zgsz3377);
            zgaz3175 = CONVERT_OF(mach_int, sail_int)(zgsz3378);
            KILL(sail_int)(&zgsz3378);
            KILL(sail_int)(&zgsz3377);
            KILL(sail_int)(&zgsz3376);
          }
          {
            sail_int zgsz3373;
            CREATE(sail_int)(&zgsz3373);
            CONVERT_OF(sail_int, mach_int)(&zgsz3373, zgaz3175);
            sail_int zgsz3374;
            CREATE(sail_int)(&zgsz3374);
            CONVERT_OF(sail_int, mach_int)(&zgsz3374, INT64_C(1));
            sail_int zgsz3375;
            CREATE(sail_int)(&zgsz3375);
            sub_int(&zgsz3375, zgsz3373, zgsz3374);
            zgaz3177 = CONVERT_OF(mach_int, sail_int)(zgsz3375);
            KILL(sail_int)(&zgsz3375);
            KILL(sail_int)(&zgsz3374);
            KILL(sail_int)(&zgsz3373);
          }
        }
        {
          lbits zgsz3379;
          CREATE(lbits)(&zgsz3379);
          CONVERT_OF(lbits, fbits)(&zgsz3379, zgaz3176, UINT64_C(6) , true);
          sail_int zgsz3380;
          CREATE(sail_int)(&zgsz3380);
          CONVERT_OF(sail_int, mach_int)(&zgsz3380, zgaz3177);
          sail_int zgsz3381;
          CREATE(sail_int)(&zgsz3381);
          CONVERT_OF(sail_int, mach_int)(&zgsz3381, zinternal_E_take_bits);
          lbits zgsz3382;
          CREATE(lbits)(&zgsz3382);
          vector_subrange_lbits(&zgsz3382, zgsz3379, zgsz3380, zgsz3381);
          zt_lo = CONVERT_OF(fbits, lbits)(zgsz3382, true);
          KILL(lbits)(&zgsz3382);
          KILL(sail_int)(&zgsz3381);
          KILL(sail_int)(&zgsz3380);
          KILL(lbits)(&zgsz3379);
        }
        unit zgsz344;
        zgsz344 = UNIT;
      }
      uint64_t zgaz3178;
      zgaz3178 = zcap.zE;
      int64_t zgaz3179;
      {
        sail_int zgsz3387;
        CREATE(sail_int)(&zgsz3387);
        CONVERT_OF(sail_int, mach_int)(&zgsz3387, zinternal_E_take_bits);
        sail_int zgsz3388;
        CREATE(sail_int)(&zgsz3388);
        CONVERT_OF(sail_int, mach_int)(&zgsz3388, INT64_C(1));
        sail_int zgsz3389;
        CREATE(sail_int)(&zgsz3389);
        sub_int(&zgsz3389, zgsz3387, zgsz3388);
        zgaz3179 = CONVERT_OF(mach_int, sail_int)(zgsz3389);
        KILL(sail_int)(&zgsz3389);
        KILL(sail_int)(&zgsz3388);
        KILL(sail_int)(&zgsz3387);
      }
      {
        lbits zgsz3383;
        CREATE(lbits)(&zgsz3383);
        CONVERT_OF(lbits, fbits)(&zgsz3383, zgaz3178, UINT64_C(6) , true);
        sail_int zgsz3384;
        CREATE(sail_int)(&zgsz3384);
        CONVERT_OF(sail_int, mach_int)(&zgsz3384, zgaz3179);
        sail_int zgsz3385;
        CREATE(sail_int)(&zgsz3385);
        CONVERT_OF(sail_int, mach_int)(&zgsz3385, INT64_C(0));
        lbits zgsz3386;
        CREATE(lbits)(&zgsz3386);
        vector_subrange_lbits(&zgsz3386, zgsz3383, zgsz3384, zgsz3385);
        zb_lo = CONVERT_OF(fbits, lbits)(zgsz3386, true);
        KILL(lbits)(&zgsz3386);
        KILL(sail_int)(&zgsz3385);
        KILL(sail_int)(&zgsz3384);
        KILL(lbits)(&zgsz3383);
      }
      zgsz343 = UNIT;
    } else {  zgsz343 = UNIT;  }
  }
  struct zEncCapability zgaz3193;
  {
    uint64_t zgaz3182;
    {
      uint64_t zgaz3180;
      zgaz3180 = zcap.zuperms;
      uint64_t zgaz3181;
      zgaz3181 = sailgen_getCapHardPerms(zcap);
      {
        lbits zgsz3390;
        CREATE(lbits)(&zgsz3390);
        CONVERT_OF(lbits, fbits)(&zgsz3390, zgaz3180, UINT64_C(4) , true);
        lbits zgsz3391;
        CREATE(lbits)(&zgsz3391);
        CONVERT_OF(lbits, fbits)(&zgsz3391, zgaz3181, UINT64_C(12) , true);
        lbits zgsz3392;
        CREATE(lbits)(&zgsz3392);
        append(&zgsz3392, zgsz3390, zgsz3391);
        zgaz3182 = CONVERT_OF(fbits, lbits)(zgsz3392, true);
        KILL(lbits)(&zgsz3392);
        KILL(lbits)(&zgsz3391);
        KILL(lbits)(&zgsz3390);
      }
    }
    uint64_t zgaz3183;
    zgaz3183 = zcap.zreserved;
    uint64_t zgaz3185;
    {
      bool zgaz3184;
      zgaz3184 = zcap.zflag_cap_mode;
      zgaz3185 = sailgen_bool_to_bits(zgaz3184);
    }
    uint64_t zgaz3186;
    zgaz3186 = zcap.zotype;
    fbits zgaz3189;
    {
      uint64_t zgaz3188;
      {
        bool zgaz3187;
        zgaz3187 = zcap.zinternal_E;
        zgaz3188 = sailgen_bool_to_bits(zgaz3187);
      }
      {
        lbits zgsz3393;
        CREATE(lbits)(&zgsz3393);
        CONVERT_OF(lbits, fbits)(&zgsz3393, zgaz3188, UINT64_C(1) , true);
        sail_int zgsz3394;
        CREATE(sail_int)(&zgsz3394);
        CONVERT_OF(sail_int, mach_int)(&zgsz3394, INT64_C(0));
        zgaz3189 = bitvector_access(zgsz3393, zgsz3394);
        KILL(sail_int)(&zgsz3394);
        KILL(lbits)(&zgsz3393);
      }
    }
    uint64_t zgaz3190;
    {
      lbits zgsz3398;
      CREATE(lbits)(&zgsz3398);
      CONVERT_OF(lbits, fbits)(&zgsz3398, zt_hi, UINT64_C(9) , true);
      lbits zgsz3399;
      CREATE(lbits)(&zgsz3399);
      CONVERT_OF(lbits, fbits)(&zgsz3399, zt_lo, UINT64_C(3) , true);
      lbits zgsz3400;
      CREATE(lbits)(&zgsz3400);
      append(&zgsz3400, zgsz3398, zgsz3399);
      zgaz3190 = CONVERT_OF(fbits, lbits)(zgsz3400, true);
      KILL(lbits)(&zgsz3400);
      KILL(lbits)(&zgsz3399);
      KILL(lbits)(&zgsz3398);
    }
    uint64_t zgaz3191;
    {
      lbits zgsz3395;
      CREATE(lbits)(&zgsz3395);
      CONVERT_OF(lbits, fbits)(&zgsz3395, zb_hi, UINT64_C(11) , true);
      lbits zgsz3396;
      CREATE(lbits)(&zgsz3396);
      CONVERT_OF(lbits, fbits)(&zgsz3396, zb_lo, UINT64_C(3) , true);
      lbits zgsz3397;
      CREATE(lbits)(&zgsz3397);
      append(&zgsz3397, zgsz3395, zgsz3396);
      zgaz3191 = CONVERT_OF(fbits, lbits)(zgsz3397, true);
      KILL(lbits)(&zgsz3397);
      KILL(lbits)(&zgsz3396);
      KILL(lbits)(&zgsz3395);
    }
    uint64_t zgaz3192;
    zgaz3192 = zcap.zaddress;
    struct zEncCapability zgsz345;
    zgsz345.zB = zgaz3191;
    zgsz345.zT = zgaz3190;
    zgsz345.zaddress = zgaz3192;
    zgsz345.zflags = zgaz3185;
    zgsz345.zinternal_E = zgaz3189;
    zgsz345.zotype = zgaz3186;
    zgsz345.zperms = zgaz3182;
    zgsz345.zreserved = zgaz3183;
    zgaz3193 = zgsz345;
  }
  zcbz320 = zgaz3193;
  goto cleanup_94;
  /* unreachable after return */





  goto end_cleanup_95;
cleanup_94: ;





  goto end_function_93;
end_cleanup_95: ;
end_function_93: ;
  return zcbz320;
end_block_exception_96: ;
  struct zEncCapability zcbz350 = { .zB = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaddress = UINT64_C(0xdeadc0de), .zflags = UINT64_C(0xdeadc0de), .zinternal_E = UINT64_C(0), .zotype = UINT64_C(0xdeadc0de), .zperms = UINT64_C(0xdeadc0de), .zreserved = UINT64_C(0xdeadc0de) };
  return zcbz350;
}

static void sailgen_capToBits(lbits *rop, struct zCapability);

static void sailgen_capToBits(lbits *zcbz321, struct zCapability zcap)
{
  __label__ end_function_98, end_block_exception_99, end_function_200;

  struct zEncCapability zgaz3202;
  zgaz3202 = sailgen_capToEncCap(zcap);
  sailgen_encCapToBits((*(&zcbz321)), zgaz3202);

end_function_98: ;
  goto end_function_200;
end_block_exception_99: ;
  goto end_function_200;
end_function_200: ;
}

static lbits znull_cap_bits;
static void create_letbind_27(void) {    CREATE(lbits)(&znull_cap_bits);


  lbits zgsz346;
  CREATE(lbits)(&zgsz346);
  sailgen_capToBits(&zgsz346, znull_cap);
  COPY(lbits)(&znull_cap_bits, zgsz346);
  KILL(lbits)(&zgsz346);
let_end_100: ;
}
static void kill_letbind_27(void) {    KILL(lbits)(&znull_cap_bits);
}

static void sailgen_capToMemBits(lbits *rop, struct zCapability);

static void sailgen_capToMemBits(lbits *zcbz322, struct zCapability zcap)
{
  __label__ end_function_102, end_block_exception_103, end_function_199;

  lbits zgaz3203;
  CREATE(lbits)(&zgaz3203);
  sailgen_capToBits(&zgaz3203, zcap);
  xor_bits((*(&zcbz322)), zgaz3203, znull_cap_bits);
  KILL(lbits)(&zgaz3203);
end_function_102: ;
  goto end_function_199;
end_block_exception_103: ;
  goto end_function_199;
end_function_199: ;
}

static struct zCapability sailgen_memBitsToCapability(bool, lbits);

static struct zCapability sailgen_memBitsToCapability(bool ztag, lbits zb)
{
  __label__ end_function_105, end_block_exception_106;

  struct zCapability zcbz323;
  lbits zgaz3204;
  CREATE(lbits)(&zgaz3204);
  xor_bits(&zgaz3204, zb, znull_cap_bits);
  zcbz323 = sailgen_capBitsToCapability(ztag, zgaz3204);
  KILL(lbits)(&zgaz3204);
end_function_105: ;
  return zcbz323;
end_block_exception_106: ;
  struct zCapability zcbz351 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  return zcbz351;
}

// struct tuple_(%bv64, %bv)
struct ztuple_z8z5bv64zCz0z5bvz9 {
  uint64_t ztup0;
  lbits ztup1;
};

static void COPY(ztuple_z8z5bv64zCz0z5bvz9)(struct ztuple_z8z5bv64zCz0z5bvz9 *rop, const struct ztuple_z8z5bv64zCz0z5bvz9 op) {
  rop->ztup0 = op.ztup0;
  COPY(lbits)(&rop->ztup1, op.ztup1);
}

static void CREATE(ztuple_z8z5bv64zCz0z5bvz9)(struct ztuple_z8z5bv64zCz0z5bvz9 *op) {
  CREATE(lbits)(&op->ztup1);
}

static void RECREATE(ztuple_z8z5bv64zCz0z5bvz9)(struct ztuple_z8z5bv64zCz0z5bvz9 *op) {
  RECREATE(lbits)(&op->ztup1);
}

static void KILL(ztuple_z8z5bv64zCz0z5bvz9)(struct ztuple_z8z5bv64zCz0z5bvz9 *op) {
  KILL(lbits)(&op->ztup1);
}

static bool EQUAL(ztuple_z8z5bv64zCz0z5bvz9)(struct ztuple_z8z5bv64zCz0z5bvz9 op1, struct ztuple_z8z5bv64zCz0z5bvz9 op2) {
  return EQUAL(fbits)(op1.ztup0, op2.ztup0) && EQUAL(lbits)(op1.ztup1, op2.ztup1);
}

static void sailgen_getCapBoundsBits(struct ztuple_z8z5bv64zCz0z5bvz9 *rop, struct zCapability);

static void sailgen_getCapBoundsBits(struct ztuple_z8z5bv64zCz0z5bvz9 *zcbz324, struct zCapability zc)
{
  __label__ end_function_108, end_block_exception_109, end_function_198;

  int64_t zE;
  {
    int64_t zgaz3238;
    {
      uint64_t zgaz3237;
      zgaz3237 = zc.zE;
      {
        lbits zgsz3401;
        CREATE(lbits)(&zgsz3401);
        CONVERT_OF(lbits, fbits)(&zgsz3401, zgaz3237, UINT64_C(6) , true);
        sail_int zgsz3402;
        CREATE(sail_int)(&zgsz3402);
        sail_unsigned(&zgsz3402, zgsz3401);
        zgaz3238 = CONVERT_OF(mach_int, sail_int)(zgsz3402);
        KILL(sail_int)(&zgsz3402);
        KILL(lbits)(&zgsz3401);
      }
    }
    {
      sail_int zgsz3403;
      CREATE(sail_int)(&zgsz3403);
      CONVERT_OF(sail_int, mach_int)(&zgsz3403, zcap_max_E);
      sail_int zgsz3404;
      CREATE(sail_int)(&zgsz3404);
      CONVERT_OF(sail_int, mach_int)(&zgsz3404, zgaz3238);
      sail_int zgsz3405;
      CREATE(sail_int)(&zgsz3405);
      min_int(&zgsz3405, zgsz3403, zgsz3404);
      zE = CONVERT_OF(mach_int, sail_int)(zgsz3405);
      KILL(sail_int)(&zgsz3405);
      KILL(sail_int)(&zgsz3404);
      KILL(sail_int)(&zgsz3403);
    }
  }
  uint64_t za;
  za = zc.zaddress;
  uint64_t za3;
  {
    uint64_t zgaz3236;
    {
      int64_t zgaz3235;
      {
        int64_t zgaz3234;
        {
          sail_int zgsz3409;
          CREATE(sail_int)(&zgsz3409);
          CONVERT_OF(sail_int, mach_int)(&zgsz3409, zE);
          sail_int zgsz3410;
          CREATE(sail_int)(&zgsz3410);
          CONVERT_OF(sail_int, mach_int)(&zgsz3410, zcap_mantissa_width);
          sail_int zgsz3411;
          CREATE(sail_int)(&zgsz3411);
          add_int(&zgsz3411, zgsz3409, zgsz3410);
          zgaz3234 = CONVERT_OF(mach_int, sail_int)(zgsz3411);
          KILL(sail_int)(&zgsz3411);
          KILL(sail_int)(&zgsz3410);
          KILL(sail_int)(&zgsz3409);
        }
        {
          sail_int zgsz3406;
          CREATE(sail_int)(&zgsz3406);
          CONVERT_OF(sail_int, mach_int)(&zgsz3406, zgaz3234);
          sail_int zgsz3407;
          CREATE(sail_int)(&zgsz3407);
          CONVERT_OF(sail_int, mach_int)(&zgsz3407, INT64_C(3));
          sail_int zgsz3408;
          CREATE(sail_int)(&zgsz3408);
          sub_int(&zgsz3408, zgsz3406, zgsz3407);
          zgaz3235 = CONVERT_OF(mach_int, sail_int)(zgsz3408);
          KILL(sail_int)(&zgsz3408);
          KILL(sail_int)(&zgsz3407);
          KILL(sail_int)(&zgsz3406);
        }
      }
      {
        lbits zgsz3412;
        CREATE(lbits)(&zgsz3412);
        CONVERT_OF(lbits, fbits)(&zgsz3412, za, UINT64_C(64) , true);
        sail_int zgsz3413;
        CREATE(sail_int)(&zgsz3413);
        CONVERT_OF(sail_int, mach_int)(&zgsz3413, zgaz3235);
        lbits zgsz3414;
        CREATE(lbits)(&zgsz3414);
        shiftr(&zgsz3414, zgsz3412, zgsz3413);
        zgaz3236 = CONVERT_OF(fbits, lbits)(zgsz3414, true);
        KILL(lbits)(&zgsz3414);
        KILL(sail_int)(&zgsz3413);
        KILL(lbits)(&zgsz3412);
      }
    }
    {
      lbits zgsz3415;
      CREATE(lbits)(&zgsz3415);
      CONVERT_OF(lbits, fbits)(&zgsz3415, zgaz3236, UINT64_C(64) , true);
      sail_int zgsz3416;
      CREATE(sail_int)(&zgsz3416);
      CONVERT_OF(sail_int, mach_int)(&zgsz3416, INT64_C(3));
      lbits zgsz3417;
      CREATE(lbits)(&zgsz3417);
      sail_truncate(&zgsz3417, zgsz3415, zgsz3416);
      za3 = CONVERT_OF(fbits, lbits)(zgsz3417, true);
      KILL(lbits)(&zgsz3417);
      KILL(sail_int)(&zgsz3416);
      KILL(lbits)(&zgsz3415);
    }
  }
  uint64_t zB3;
  {
    uint64_t zgaz3233;
    zgaz3233 = zc.zB;
    {
      lbits zgsz3418;
      CREATE(lbits)(&zgsz3418);
      CONVERT_OF(lbits, fbits)(&zgsz3418, zgaz3233, UINT64_C(14) , true);
      sail_int zgsz3419;
      CREATE(sail_int)(&zgsz3419);
      CONVERT_OF(sail_int, mach_int)(&zgsz3419, INT64_C(3));
      lbits zgsz3420;
      CREATE(lbits)(&zgsz3420);
      sail_truncateLSB(&zgsz3420, zgsz3418, zgsz3419);
      zB3 = CONVERT_OF(fbits, lbits)(zgsz3420, true);
      KILL(lbits)(&zgsz3420);
      KILL(sail_int)(&zgsz3419);
      KILL(lbits)(&zgsz3418);
    }
  }
  uint64_t zT3;
  {
    uint64_t zgaz3232;
    zgaz3232 = zc.zT;
    {
      lbits zgsz3421;
      CREATE(lbits)(&zgsz3421);
      CONVERT_OF(lbits, fbits)(&zgsz3421, zgaz3232, UINT64_C(14) , true);
      sail_int zgsz3422;
      CREATE(sail_int)(&zgsz3422);
      CONVERT_OF(sail_int, mach_int)(&zgsz3422, INT64_C(3));
      lbits zgsz3423;
      CREATE(lbits)(&zgsz3423);
      sail_truncateLSB(&zgsz3423, zgsz3421, zgsz3422);
      zT3 = CONVERT_OF(fbits, lbits)(zgsz3423, true);
      KILL(lbits)(&zgsz3423);
      KILL(sail_int)(&zgsz3422);
      KILL(lbits)(&zgsz3421);
    }
  }
  uint64_t zR3;
  {
    lbits zgsz3493;
    CREATE(lbits)(&zgsz3493);
    CONVERT_OF(lbits, fbits)(&zgsz3493, zB3, UINT64_C(3) , true);
    lbits zgsz3494;
    CREATE(lbits)(&zgsz3494);
    CONVERT_OF(lbits, fbits)(&zgsz3494, UINT64_C(0b001), UINT64_C(3) , true);
    lbits zgsz3495;
    CREATE(lbits)(&zgsz3495);
    sub_bits(&zgsz3495, zgsz3493, zgsz3494);
    zR3 = CONVERT_OF(fbits, lbits)(zgsz3495, true);
    KILL(lbits)(&zgsz3495);
    KILL(lbits)(&zgsz3494);
    KILL(lbits)(&zgsz3493);
  }
  int64_t zaHi;
  {
    bool zgaz3231;
    {
      lbits zgsz3424;
      CREATE(lbits)(&zgsz3424);
      CONVERT_OF(lbits, fbits)(&zgsz3424, za3, UINT64_C(3) , true);
      lbits zgsz3425;
      CREATE(lbits)(&zgsz3425);
      CONVERT_OF(lbits, fbits)(&zgsz3425, zR3, UINT64_C(3) , true);
      zgaz3231 = sailgen_z8operatorz0zI_uz9(zgsz3424, zgsz3425);
      KILL(lbits)(&zgsz3425);
      KILL(lbits)(&zgsz3424);
    }
    if (zgaz3231) {  zaHi = INT64_C(1);  } else {  zaHi = INT64_C(0);  }
  }
  int64_t zbHi;
  {
    bool zgaz3230;
    {
      lbits zgsz3426;
      CREATE(lbits)(&zgsz3426);
      CONVERT_OF(lbits, fbits)(&zgsz3426, zB3, UINT64_C(3) , true);
      lbits zgsz3427;
      CREATE(lbits)(&zgsz3427);
      CONVERT_OF(lbits, fbits)(&zgsz3427, zR3, UINT64_C(3) , true);
      zgaz3230 = sailgen_z8operatorz0zI_uz9(zgsz3426, zgsz3427);
      KILL(lbits)(&zgsz3427);
      KILL(lbits)(&zgsz3426);
    }
    if (zgaz3230) {  zbHi = INT64_C(1);  } else {  zbHi = INT64_C(0);  }
  }
  int64_t ztHi;
  {
    bool zgaz3229;
    {
      lbits zgsz3428;
      CREATE(lbits)(&zgsz3428);
      CONVERT_OF(lbits, fbits)(&zgsz3428, zT3, UINT64_C(3) , true);
      lbits zgsz3429;
      CREATE(lbits)(&zgsz3429);
      CONVERT_OF(lbits, fbits)(&zgsz3429, zR3, UINT64_C(3) , true);
      zgaz3229 = sailgen_z8operatorz0zI_uz9(zgsz3428, zgsz3429);
      KILL(lbits)(&zgsz3429);
      KILL(lbits)(&zgsz3428);
    }
    if (zgaz3229) {  ztHi = INT64_C(1);  } else {  ztHi = INT64_C(0);  }
  }
  int64_t zcorrection_base;
  {
    sail_int zgsz3490;
    CREATE(sail_int)(&zgsz3490);
    CONVERT_OF(sail_int, mach_int)(&zgsz3490, zbHi);
    sail_int zgsz3491;
    CREATE(sail_int)(&zgsz3491);
    CONVERT_OF(sail_int, mach_int)(&zgsz3491, zaHi);
    sail_int zgsz3492;
    CREATE(sail_int)(&zgsz3492);
    sub_int(&zgsz3492, zgsz3490, zgsz3491);
    zcorrection_base = CONVERT_OF(mach_int, sail_int)(zgsz3492);
    KILL(sail_int)(&zgsz3492);
    KILL(sail_int)(&zgsz3491);
    KILL(sail_int)(&zgsz3490);
  }
  int64_t zcorrection_top;
  {
    sail_int zgsz3487;
    CREATE(sail_int)(&zgsz3487);
    CONVERT_OF(sail_int, mach_int)(&zgsz3487, ztHi);
    sail_int zgsz3488;
    CREATE(sail_int)(&zgsz3488);
    CONVERT_OF(sail_int, mach_int)(&zgsz3488, zaHi);
    sail_int zgsz3489;
    CREATE(sail_int)(&zgsz3489);
    sub_int(&zgsz3489, zgsz3487, zgsz3488);
    zcorrection_top = CONVERT_OF(mach_int, sail_int)(zgsz3489);
    KILL(sail_int)(&zgsz3489);
    KILL(sail_int)(&zgsz3488);
    KILL(sail_int)(&zgsz3487);
  }
  uint64_t za_top;
  {
    int64_t zgaz3228;
    {
      sail_int zgsz3433;
      CREATE(sail_int)(&zgsz3433);
      CONVERT_OF(sail_int, mach_int)(&zgsz3433, zE);
      sail_int zgsz3434;
      CREATE(sail_int)(&zgsz3434);
      CONVERT_OF(sail_int, mach_int)(&zgsz3434, zcap_mantissa_width);
      sail_int zgsz3435;
      CREATE(sail_int)(&zgsz3435);
      add_int(&zgsz3435, zgsz3433, zgsz3434);
      zgaz3228 = CONVERT_OF(mach_int, sail_int)(zgsz3435);
      KILL(sail_int)(&zgsz3435);
      KILL(sail_int)(&zgsz3434);
      KILL(sail_int)(&zgsz3433);
    }
    {
      lbits zgsz3430;
      CREATE(lbits)(&zgsz3430);
      CONVERT_OF(lbits, fbits)(&zgsz3430, za, UINT64_C(64) , true);
      sail_int zgsz3431;
      CREATE(sail_int)(&zgsz3431);
      CONVERT_OF(sail_int, mach_int)(&zgsz3431, zgaz3228);
      lbits zgsz3432;
      CREATE(lbits)(&zgsz3432);
      shiftr(&zgsz3432, zgsz3430, zgsz3431);
      za_top = CONVERT_OF(fbits, lbits)(zgsz3432, true);
      KILL(lbits)(&zgsz3432);
      KILL(sail_int)(&zgsz3431);
      KILL(lbits)(&zgsz3430);
    }
  }
  lbits zbase;
  CREATE(lbits)(&zbase);
  {
    lbits zgaz3227;
    CREATE(lbits)(&zgaz3227);
    {
      uint64_t zgaz3225;
      {
        lbits zgsz3441;
        CREATE(lbits)(&zgsz3441);
        CONVERT_OF(lbits, fbits)(&zgsz3441, za_top, UINT64_C(64) , true);
        sail_int zgsz3442;
        CREATE(sail_int)(&zgsz3442);
        CONVERT_OF(sail_int, mach_int)(&zgsz3442, zcorrection_base);
        lbits zgsz3443;
        CREATE(lbits)(&zgsz3443);
        add_bits_int(&zgsz3443, zgsz3441, zgsz3442);
        zgaz3225 = CONVERT_OF(fbits, lbits)(zgsz3443, true);
        KILL(lbits)(&zgsz3443);
        KILL(sail_int)(&zgsz3442);
        KILL(lbits)(&zgsz3441);
      }
      lbits zgaz3226;
      CREATE(lbits)(&zgaz3226);
      {
        uint64_t zgaz3223;
        zgaz3223 = zc.zB;
        sbits zgaz3224;
        {
          sail_int zgsz3438;
          CREATE(sail_int)(&zgsz3438);
          CONVERT_OF(sail_int, mach_int)(&zgsz3438, zE);
          lbits zgsz3439;
          CREATE(lbits)(&zgsz3439);
          sailgen_zzeros_implicit(&zgsz3439, zgsz3438);
          zgaz3224 = CONVERT_OF(sbits, lbits)(zgsz3439, true);
          KILL(lbits)(&zgsz3439);
          KILL(sail_int)(&zgsz3438);
        }
        {
          lbits zgsz3436;
          CREATE(lbits)(&zgsz3436);
          CONVERT_OF(lbits, fbits)(&zgsz3436, zgaz3223, UINT64_C(14) , true);
          lbits zgsz3437;
          CREATE(lbits)(&zgsz3437);
          CONVERT_OF(lbits, sbits)(&zgsz3437, zgaz3224, true);
          append(&zgaz3226, zgsz3436, zgsz3437);
          KILL(lbits)(&zgsz3437);
          KILL(lbits)(&zgsz3436);
        }
      }
      {
        lbits zgsz3440;
        CREATE(lbits)(&zgsz3440);
        CONVERT_OF(lbits, fbits)(&zgsz3440, zgaz3225, UINT64_C(64) , true);
        append(&zgaz3227, zgsz3440, zgaz3226);
        KILL(lbits)(&zgsz3440);
      }
      KILL(lbits)(&zgaz3226);
    }
    {
      sail_int zgsz3444;
      CREATE(sail_int)(&zgsz3444);
      CONVERT_OF(sail_int, mach_int)(&zgsz3444, zcap_len_width);
      sail_truncate(&zbase, zgaz3227, zgsz3444);
      KILL(sail_int)(&zgsz3444);
    }
    KILL(lbits)(&zgaz3227);
  }
  lbits ztop;
  CREATE(lbits)(&ztop);
  {
    lbits zgaz3222;
    CREATE(lbits)(&zgaz3222);
    {
      uint64_t zgaz3220;
      {
        lbits zgsz3450;
        CREATE(lbits)(&zgsz3450);
        CONVERT_OF(lbits, fbits)(&zgsz3450, za_top, UINT64_C(64) , true);
        sail_int zgsz3451;
        CREATE(sail_int)(&zgsz3451);
        CONVERT_OF(sail_int, mach_int)(&zgsz3451, zcorrection_top);
        lbits zgsz3452;
        CREATE(lbits)(&zgsz3452);
        add_bits_int(&zgsz3452, zgsz3450, zgsz3451);
        zgaz3220 = CONVERT_OF(fbits, lbits)(zgsz3452, true);
        KILL(lbits)(&zgsz3452);
        KILL(sail_int)(&zgsz3451);
        KILL(lbits)(&zgsz3450);
      }
      lbits zgaz3221;
      CREATE(lbits)(&zgaz3221);
      {
        uint64_t zgaz3218;
        zgaz3218 = zc.zT;
        sbits zgaz3219;
        {
          sail_int zgsz3447;
          CREATE(sail_int)(&zgsz3447);
          CONVERT_OF(sail_int, mach_int)(&zgsz3447, zE);
          lbits zgsz3448;
          CREATE(lbits)(&zgsz3448);
          sailgen_zzeros_implicit(&zgsz3448, zgsz3447);
          zgaz3219 = CONVERT_OF(sbits, lbits)(zgsz3448, true);
          KILL(lbits)(&zgsz3448);
          KILL(sail_int)(&zgsz3447);
        }
        {
          lbits zgsz3445;
          CREATE(lbits)(&zgsz3445);
          CONVERT_OF(lbits, fbits)(&zgsz3445, zgaz3218, UINT64_C(14) , true);
          lbits zgsz3446;
          CREATE(lbits)(&zgsz3446);
          CONVERT_OF(lbits, sbits)(&zgsz3446, zgaz3219, true);
          append(&zgaz3221, zgsz3445, zgsz3446);
          KILL(lbits)(&zgsz3446);
          KILL(lbits)(&zgsz3445);
        }
      }
      {
        lbits zgsz3449;
        CREATE(lbits)(&zgsz3449);
        CONVERT_OF(lbits, fbits)(&zgsz3449, zgaz3220, UINT64_C(64) , true);
        append(&zgaz3222, zgsz3449, zgaz3221);
        KILL(lbits)(&zgsz3449);
      }
      KILL(lbits)(&zgaz3221);
    }
    {
      sail_int zgsz3453;
      CREATE(sail_int)(&zgsz3453);
      CONVERT_OF(sail_int, mach_int)(&zgsz3453, zcap_len_width);
      sail_truncate(&ztop, zgaz3222, zgsz3453);
      KILL(sail_int)(&zgsz3453);
    }
    KILL(lbits)(&zgaz3222);
  }
  uint64_t zbase2;
  {
    uint64_t zgaz3217;
    {
      fbits zgaz3216;
      {
        int64_t zgaz3215;
        {
          sail_int zgsz3455;
          CREATE(sail_int)(&zgsz3455);
          CONVERT_OF(sail_int, mach_int)(&zgsz3455, zcap_addr_width);
          sail_int zgsz3456;
          CREATE(sail_int)(&zgsz3456);
          CONVERT_OF(sail_int, mach_int)(&zgsz3456, INT64_C(1));
          sail_int zgsz3457;
          CREATE(sail_int)(&zgsz3457);
          sub_int(&zgsz3457, zgsz3455, zgsz3456);
          zgaz3215 = CONVERT_OF(mach_int, sail_int)(zgsz3457);
          KILL(sail_int)(&zgsz3457);
          KILL(sail_int)(&zgsz3456);
          KILL(sail_int)(&zgsz3455);
        }
        {
          sail_int zgsz3454;
          CREATE(sail_int)(&zgsz3454);
          CONVERT_OF(sail_int, mach_int)(&zgsz3454, zgaz3215);
          zgaz3216 = bitvector_access(zbase, zgsz3454);
          KILL(sail_int)(&zgsz3454);
        }
      }
      uint64_t zgsz347;
      zgsz347 = UINT64_C(0b0);
      zgsz347 = update_fbits(zgsz347, INT64_C(0), zgaz3216);
      zgaz3217 = zgsz347;
    }
    {
      lbits zgsz3458;
      CREATE(lbits)(&zgsz3458);
      CONVERT_OF(lbits, fbits)(&zgsz3458, UINT64_C(0b0), UINT64_C(1) , true);
      lbits zgsz3459;
      CREATE(lbits)(&zgsz3459);
      CONVERT_OF(lbits, fbits)(&zgsz3459, zgaz3217, UINT64_C(1) , true);
      lbits zgsz3460;
      CREATE(lbits)(&zgsz3460);
      append(&zgsz3460, zgsz3458, zgsz3459);
      zbase2 = CONVERT_OF(fbits, lbits)(zgsz3460, true);
      KILL(lbits)(&zgsz3460);
      KILL(lbits)(&zgsz3459);
      KILL(lbits)(&zgsz3458);
    }
  }
  uint64_t ztop2;
  {
    int64_t zgaz3214;
    {
      sail_int zgsz3464;
      CREATE(sail_int)(&zgsz3464);
      CONVERT_OF(sail_int, mach_int)(&zgsz3464, zcap_addr_width);
      sail_int zgsz3465;
      CREATE(sail_int)(&zgsz3465);
      CONVERT_OF(sail_int, mach_int)(&zgsz3465, INT64_C(1));
      sail_int zgsz3466;
      CREATE(sail_int)(&zgsz3466);
      sub_int(&zgsz3466, zgsz3464, zgsz3465);
      zgaz3214 = CONVERT_OF(mach_int, sail_int)(zgsz3466);
      KILL(sail_int)(&zgsz3466);
      KILL(sail_int)(&zgsz3465);
      KILL(sail_int)(&zgsz3464);
    }
    {
      sail_int zgsz3461;
      CREATE(sail_int)(&zgsz3461);
      CONVERT_OF(sail_int, mach_int)(&zgsz3461, zcap_addr_width);
      sail_int zgsz3462;
      CREATE(sail_int)(&zgsz3462);
      CONVERT_OF(sail_int, mach_int)(&zgsz3462, zgaz3214);
      lbits zgsz3463;
      CREATE(lbits)(&zgsz3463);
      vector_subrange_lbits(&zgsz3463, ztop, zgsz3461, zgsz3462);
      ztop2 = CONVERT_OF(fbits, lbits)(zgsz3463, true);
      KILL(lbits)(&zgsz3463);
      KILL(sail_int)(&zgsz3462);
      KILL(sail_int)(&zgsz3461);
    }
  }
  {
    bool zgaz3209;
    {
      bool zgaz3208;
      {
        int64_t zgaz3205;
        {
          sail_int zgsz3469;
          CREATE(sail_int)(&zgsz3469);
          CONVERT_OF(sail_int, mach_int)(&zgsz3469, zcap_max_E);
          sail_int zgsz3470;
          CREATE(sail_int)(&zgsz3470);
          CONVERT_OF(sail_int, mach_int)(&zgsz3470, INT64_C(1));
          sail_int zgsz3471;
          CREATE(sail_int)(&zgsz3471);
          sub_int(&zgsz3471, zgsz3469, zgsz3470);
          zgaz3205 = CONVERT_OF(mach_int, sail_int)(zgsz3471);
          KILL(sail_int)(&zgsz3471);
          KILL(sail_int)(&zgsz3470);
          KILL(sail_int)(&zgsz3469);
        }
        {
          sail_int zgsz3467;
          CREATE(sail_int)(&zgsz3467);
          CONVERT_OF(sail_int, mach_int)(&zgsz3467, zE);
          sail_int zgsz3468;
          CREATE(sail_int)(&zgsz3468);
          CONVERT_OF(sail_int, mach_int)(&zgsz3468, zgaz3205);
          zgaz3208 = lt(zgsz3467, zgsz3468);
          KILL(sail_int)(&zgsz3468);
          KILL(sail_int)(&zgsz3467);
        }
      }
      bool zgsz348;
      if (zgaz3208) {
        int64_t zgaz3207;
        {
          uint64_t zgaz3206;
          {
            lbits zgsz3474;
            CREATE(lbits)(&zgsz3474);
            CONVERT_OF(lbits, fbits)(&zgsz3474, ztop2, UINT64_C(2) , true);
            lbits zgsz3475;
            CREATE(lbits)(&zgsz3475);
            CONVERT_OF(lbits, fbits)(&zgsz3475, zbase2, UINT64_C(2) , true);
            lbits zgsz3476;
            CREATE(lbits)(&zgsz3476);
            sub_bits(&zgsz3476, zgsz3474, zgsz3475);
            zgaz3206 = CONVERT_OF(fbits, lbits)(zgsz3476, true);
            KILL(lbits)(&zgsz3476);
            KILL(lbits)(&zgsz3475);
            KILL(lbits)(&zgsz3474);
          }
          {
            lbits zgsz3472;
            CREATE(lbits)(&zgsz3472);
            CONVERT_OF(lbits, fbits)(&zgsz3472, zgaz3206, UINT64_C(2) , true);
            sail_int zgsz3473;
            CREATE(sail_int)(&zgsz3473);
            sail_unsigned(&zgsz3473, zgsz3472);
            zgaz3207 = CONVERT_OF(mach_int, sail_int)(zgsz3473);
            KILL(sail_int)(&zgsz3473);
            KILL(lbits)(&zgsz3472);
          }
        }
        {
          sail_int zgsz3477;
          CREATE(sail_int)(&zgsz3477);
          CONVERT_OF(sail_int, mach_int)(&zgsz3477, zgaz3207);
          sail_int zgsz3478;
          CREATE(sail_int)(&zgsz3478);
          CONVERT_OF(sail_int, mach_int)(&zgsz3478, INT64_C(1));
          zgsz348 = gt(zgsz3477, zgsz3478);
          KILL(sail_int)(&zgsz3478);
          KILL(sail_int)(&zgsz3477);
        }
      } else {  zgsz348 = false;  }
      zgaz3209 = zgsz348;
    }
    unit zgsz349;
    if (zgaz3209) {
      fbits zgaz3211;
      {
        fbits zgaz3210;
        {
          sail_int zgsz3479;
          CREATE(sail_int)(&zgsz3479);
          CONVERT_OF(sail_int, mach_int)(&zgsz3479, zcap_addr_width);
          zgaz3210 = bitvector_access(ztop, zgsz3479);
          KILL(sail_int)(&zgsz3479);
        }
        zgaz3211 = sailgen_not_bit(zgaz3210);
      }
      {
        sail_int zgsz3480;
        CREATE(sail_int)(&zgsz3480);
        CONVERT_OF(sail_int, mach_int)(&zgsz3480, zcap_addr_width);
        update_lbits(&ztop, ztop, zgsz3480, zgaz3211);
        KILL(sail_int)(&zgsz3480);
      }
      zgsz349 = UNIT;
    } else {  zgsz349 = UNIT;  }
  }
  uint64_t zgaz3213;
  {
    int64_t zgaz3212;
    {
      sail_int zgsz3484;
      CREATE(sail_int)(&zgsz3484);
      CONVERT_OF(sail_int, mach_int)(&zgsz3484, zcap_addr_width);
      sail_int zgsz3485;
      CREATE(sail_int)(&zgsz3485);
      CONVERT_OF(sail_int, mach_int)(&zgsz3485, INT64_C(1));
      sail_int zgsz3486;
      CREATE(sail_int)(&zgsz3486);
      sub_int(&zgsz3486, zgsz3484, zgsz3485);
      zgaz3212 = CONVERT_OF(mach_int, sail_int)(zgsz3486);
      KILL(sail_int)(&zgsz3486);
      KILL(sail_int)(&zgsz3485);
      KILL(sail_int)(&zgsz3484);
    }
    {
      sail_int zgsz3481;
      CREATE(sail_int)(&zgsz3481);
      CONVERT_OF(sail_int, mach_int)(&zgsz3481, zgaz3212);
      sail_int zgsz3482;
      CREATE(sail_int)(&zgsz3482);
      CONVERT_OF(sail_int, mach_int)(&zgsz3482, INT64_C(0));
      lbits zgsz3483;
      CREATE(lbits)(&zgsz3483);
      vector_subrange_lbits(&zgsz3483, zbase, zgsz3481, zgsz3482);
      zgaz3213 = CONVERT_OF(fbits, lbits)(zgsz3483, true);
      KILL(lbits)(&zgsz3483);
      KILL(sail_int)(&zgsz3482);
      KILL(sail_int)(&zgsz3481);
    }
  }
  struct ztuple_z8z5bv64zCz0z5bvz9 zgsz350;
  CREATE(ztuple_z8z5bv64zCz0z5bvz9)(&zgsz350);
  zgsz350.ztup0 = zgaz3213;
  COPY(lbits)(&((&zgsz350)->ztup1), ztop);
  COPY(ztuple_z8z5bv64zCz0z5bvz9)((*(&zcbz324)), zgsz350);
  KILL(ztuple_z8z5bv64zCz0z5bvz9)(&zgsz350);



  KILL(lbits)(&ztop);
  KILL(lbits)(&zbase);












end_function_108: ;
  goto end_function_198;
end_block_exception_109: ;
  goto end_function_198;
end_function_198: ;
}

// struct tuple_(%i, %i)
struct ztuple_z8z5izCz0z5iz9 {
  sail_int ztup0;
  sail_int ztup1;
};

static void COPY(ztuple_z8z5izCz0z5iz9)(struct ztuple_z8z5izCz0z5iz9 *rop, const struct ztuple_z8z5izCz0z5iz9 op) {
  COPY(sail_int)(&rop->ztup0, op.ztup0);
  COPY(sail_int)(&rop->ztup1, op.ztup1);
}

static void CREATE(ztuple_z8z5izCz0z5iz9)(struct ztuple_z8z5izCz0z5iz9 *op) {
  CREATE(sail_int)(&op->ztup0);
  CREATE(sail_int)(&op->ztup1);
}

static void RECREATE(ztuple_z8z5izCz0z5iz9)(struct ztuple_z8z5izCz0z5iz9 *op) {
  RECREATE(sail_int)(&op->ztup0);
  RECREATE(sail_int)(&op->ztup1);
}

static void KILL(ztuple_z8z5izCz0z5iz9)(struct ztuple_z8z5izCz0z5iz9 *op) {
  KILL(sail_int)(&op->ztup0);
  KILL(sail_int)(&op->ztup1);
}

static bool EQUAL(ztuple_z8z5izCz0z5iz9)(struct ztuple_z8z5izCz0z5iz9 op1, struct ztuple_z8z5izCz0z5iz9 op2) {
  return EQUAL(sail_int)(op1.ztup0, op2.ztup0) && EQUAL(sail_int)(op1.ztup1, op2.ztup1);
}

static void sailgen_getCapBounds(struct ztuple_z8z5izCz0z5iz9 *rop, struct zCapability);


static void sailgen_getCapBounds(struct ztuple_z8z5izCz0z5iz9 *zcbz325, struct zCapability zcap)
{
  __label__ case_112, finish_match_111, end_function_113, end_block_exception_114, end_function_197;

  struct ztuple_z8z5bv64zCz0z5bvz9 zgaz3239;
  CREATE(ztuple_z8z5bv64zCz0z5bvz9)(&zgaz3239);
  sailgen_getCapBoundsBits(&zgaz3239, zcap);
  struct ztuple_z8z5izCz0z5iz9 zgsz351;
  CREATE(ztuple_z8z5izCz0z5iz9)(&zgsz351);
  {
    uint64_t zbase;
    zbase = zgaz3239.ztup0;
    lbits ztop;
    CREATE(lbits)(&ztop);
    COPY(lbits)(&ztop, zgaz3239.ztup1);
    sail_int zgaz3240;
    CREATE(sail_int)(&zgaz3240);
    {
      lbits zgsz3496;
      CREATE(lbits)(&zgsz3496);
      CONVERT_OF(lbits, fbits)(&zgsz3496, zbase, UINT64_C(64) , true);
      sail_unsigned(&zgaz3240, zgsz3496);
      KILL(lbits)(&zgsz3496);
    }
    sail_int zgaz3241;
    CREATE(sail_int)(&zgaz3241);
    sail_unsigned(&zgaz3241, ztop);
    struct ztuple_z8z5izCz0z5iz9 zgsz352;
    CREATE(ztuple_z8z5izCz0z5iz9)(&zgsz352);
    COPY(sail_int)(&((&zgsz352)->ztup0), zgaz3240);
    COPY(sail_int)(&((&zgsz352)->ztup1), zgaz3241);
    COPY(ztuple_z8z5izCz0z5iz9)(&zgsz351, zgsz352);
    KILL(ztuple_z8z5izCz0z5iz9)(&zgsz352);
    KILL(sail_int)(&zgaz3241);
    KILL(sail_int)(&zgaz3240);
    KILL(lbits)(&ztop);
    goto finish_match_111;
  }
case_112: ;
  sail_match_failure("getCapBounds");
finish_match_111: ;
  COPY(ztuple_z8z5izCz0z5iz9)((*(&zcbz325)), zgsz351);
  KILL(ztuple_z8z5izCz0z5iz9)(&zgsz351);
  KILL(ztuple_z8z5bv64zCz0z5bvz9)(&zgaz3239);
end_function_113: ;
  goto end_function_197;
end_block_exception_114: ;
  goto end_function_197;
end_function_197: ;
}

// struct tuple_(%bool, %struct zCapability)
struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 {
  bool ztup0;
  struct zCapability ztup1;
};

static void COPY(ztuple_z8z5boolzCz0z5structz0zzCapabilityz9)(struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 *rop, const struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
}

static bool EQUAL(ztuple_z8z5boolzCz0z5structz0zzCapabilityz9)(struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 op1, struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 op2) {
  return EQUAL(bool)(op1.ztup0, op2.ztup0) && EQUAL(zCapability)(op1.ztup1, op2.ztup1);
}

static struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 sailgen_setCapBounds(struct zCapability, uint64_t, lbits);

static struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 sailgen_setCapBounds(struct zCapability zcap, uint64_t zbase, lbits ztop)
{
  __label__ end_function_116, end_block_exception_117;

  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz326;
  lbits zext_base;
  CREATE(lbits)(&zext_base);
  {
    lbits zgsz3600;
    CREATE(lbits)(&zgsz3600);
    CONVERT_OF(lbits, fbits)(&zgsz3600, UINT64_C(0b0), UINT64_C(1) , true);
    lbits zgsz3601;
    CREATE(lbits)(&zgsz3601);
    CONVERT_OF(lbits, fbits)(&zgsz3601, zbase, UINT64_C(64) , true);
    append(&zext_base, zgsz3600, zgsz3601);
    KILL(lbits)(&zgsz3601);
    KILL(lbits)(&zgsz3600);
  }
  lbits zlength;
  CREATE(lbits)(&zlength);
  sub_bits(&zlength, ztop, zext_base);
  int64_t ze;
  {
    int64_t zgaz3274;
    {
      uint64_t zgaz3273;
      {
        int64_t zgaz3272;
        {
          sail_int zgsz3500;
          CREATE(sail_int)(&zgsz3500);
          CONVERT_OF(sail_int, mach_int)(&zgsz3500, zcap_mantissa_width);
          sail_int zgsz3501;
          CREATE(sail_int)(&zgsz3501);
          CONVERT_OF(sail_int, mach_int)(&zgsz3501, INT64_C(1));
          sail_int zgsz3502;
          CREATE(sail_int)(&zgsz3502);
          sub_int(&zgsz3502, zgsz3500, zgsz3501);
          zgaz3272 = CONVERT_OF(mach_int, sail_int)(zgsz3502);
          KILL(sail_int)(&zgsz3502);
          KILL(sail_int)(&zgsz3501);
          KILL(sail_int)(&zgsz3500);
        }
        {
          sail_int zgsz3497;
          CREATE(sail_int)(&zgsz3497);
          CONVERT_OF(sail_int, mach_int)(&zgsz3497, zcap_addr_width);
          sail_int zgsz3498;
          CREATE(sail_int)(&zgsz3498);
          CONVERT_OF(sail_int, mach_int)(&zgsz3498, zgaz3272);
          lbits zgsz3499;
          CREATE(lbits)(&zgsz3499);
          vector_subrange_lbits(&zgsz3499, zlength, zgsz3497, zgsz3498);
          zgaz3273 = CONVERT_OF(fbits, lbits)(zgsz3499, true);
          KILL(lbits)(&zgsz3499);
          KILL(sail_int)(&zgsz3498);
          KILL(sail_int)(&zgsz3497);
        }
      }
      {
        lbits zgsz3503;
        CREATE(lbits)(&zgsz3503);
        CONVERT_OF(lbits, fbits)(&zgsz3503, zgaz3273, UINT64_C(52) , true);
        sail_int zgsz3504;
        CREATE(sail_int)(&zgsz3504);
        count_leading_zeros(&zgsz3504, zgsz3503);
        zgaz3274 = CONVERT_OF(mach_int, sail_int)(zgsz3504);
        KILL(sail_int)(&zgsz3504);
        KILL(lbits)(&zgsz3503);
      }
    }
    {
      sail_int zgsz3505;
      CREATE(sail_int)(&zgsz3505);
      CONVERT_OF(sail_int, mach_int)(&zgsz3505, zcap_max_E);
      sail_int zgsz3506;
      CREATE(sail_int)(&zgsz3506);
      CONVERT_OF(sail_int, mach_int)(&zgsz3506, zgaz3274);
      sail_int zgsz3507;
      CREATE(sail_int)(&zgsz3507);
      sub_int(&zgsz3507, zgsz3505, zgsz3506);
      ze = CONVERT_OF(mach_int, sail_int)(zgsz3507);
      KILL(sail_int)(&zgsz3507);
      KILL(sail_int)(&zgsz3506);
      KILL(sail_int)(&zgsz3505);
    }
  }
  bool zie;
  {
    bool zgaz3271;
    {
      sail_int zgsz3512;
      CREATE(sail_int)(&zgsz3512);
      CONVERT_OF(sail_int, mach_int)(&zgsz3512, ze);
      sail_int zgsz3513;
      CREATE(sail_int)(&zgsz3513);
      CONVERT_OF(sail_int, mach_int)(&zgsz3513, INT64_C(0));
      zgaz3271 = sailgen_neq_int(zgsz3512, zgsz3513);
      KILL(sail_int)(&zgsz3513);
      KILL(sail_int)(&zgsz3512);
    }
    bool zgsz354;
    if (zgaz3271) {  zgsz354 = true;  } else {
      fbits zgaz3270;
      {
        int64_t zgaz3269;
        {
          sail_int zgsz3509;
          CREATE(sail_int)(&zgsz3509);
          CONVERT_OF(sail_int, mach_int)(&zgsz3509, zcap_mantissa_width);
          sail_int zgsz3510;
          CREATE(sail_int)(&zgsz3510);
          CONVERT_OF(sail_int, mach_int)(&zgsz3510, INT64_C(2));
          sail_int zgsz3511;
          CREATE(sail_int)(&zgsz3511);
          sub_int(&zgsz3511, zgsz3509, zgsz3510);
          zgaz3269 = CONVERT_OF(mach_int, sail_int)(zgsz3511);
          KILL(sail_int)(&zgsz3511);
          KILL(sail_int)(&zgsz3510);
          KILL(sail_int)(&zgsz3509);
        }
        {
          sail_int zgsz3508;
          CREATE(sail_int)(&zgsz3508);
          CONVERT_OF(sail_int, mach_int)(&zgsz3508, zgaz3269);
          zgaz3270 = bitvector_access(zlength, zgsz3508);
          KILL(sail_int)(&zgsz3508);
        }
      }
      zgsz354 = eq_bit(zgaz3270, UINT64_C(1));
    }
    zie = zgsz354;
  }
  uint64_t zBbits;
  {
    lbits zgsz3597;
    CREATE(lbits)(&zgsz3597);
    CONVERT_OF(lbits, fbits)(&zgsz3597, zbase, UINT64_C(64) , true);
    sail_int zgsz3598;
    CREATE(sail_int)(&zgsz3598);
    CONVERT_OF(sail_int, mach_int)(&zgsz3598, zcap_mantissa_width);
    lbits zgsz3599;
    CREATE(lbits)(&zgsz3599);
    sail_truncate(&zgsz3599, zgsz3597, zgsz3598);
    zBbits = CONVERT_OF(fbits, lbits)(zgsz3599, true);
    KILL(lbits)(&zgsz3599);
    KILL(sail_int)(&zgsz3598);
    KILL(lbits)(&zgsz3597);
  }
  uint64_t zTbits;
  {
    sail_int zgsz3595;
    CREATE(sail_int)(&zgsz3595);
    CONVERT_OF(sail_int, mach_int)(&zgsz3595, zcap_mantissa_width);
    lbits zgsz3596;
    CREATE(lbits)(&zgsz3596);
    sail_truncate(&zgsz3596, ztop, zgsz3595);
    zTbits = CONVERT_OF(fbits, lbits)(zgsz3596, true);
    KILL(lbits)(&zgsz3596);
    KILL(sail_int)(&zgsz3595);
  }
  bool zlostSignificantTop;
  zlostSignificantTop = false;
  bool zlostSignificantBase;
  zlostSignificantBase = false;
  bool zincE;
  zincE = false;
  {
    unit zgsz355;
    if (zie) {
      uint64_t zB_ie;
      {
        uint64_t zgaz3264;
        {
          int64_t zgaz3263;
          {
            sail_int zgsz3517;
            CREATE(sail_int)(&zgsz3517);
            CONVERT_OF(sail_int, mach_int)(&zgsz3517, ze);
            sail_int zgsz3518;
            CREATE(sail_int)(&zgsz3518);
            CONVERT_OF(sail_int, mach_int)(&zgsz3518, INT64_C(3));
            sail_int zgsz3519;
            CREATE(sail_int)(&zgsz3519);
            add_int(&zgsz3519, zgsz3517, zgsz3518);
            zgaz3263 = CONVERT_OF(mach_int, sail_int)(zgsz3519);
            KILL(sail_int)(&zgsz3519);
            KILL(sail_int)(&zgsz3518);
            KILL(sail_int)(&zgsz3517);
          }
          {
            lbits zgsz3514;
            CREATE(lbits)(&zgsz3514);
            CONVERT_OF(lbits, fbits)(&zgsz3514, zbase, UINT64_C(64) , true);
            sail_int zgsz3515;
            CREATE(sail_int)(&zgsz3515);
            CONVERT_OF(sail_int, mach_int)(&zgsz3515, zgaz3263);
            lbits zgsz3516;
            CREATE(lbits)(&zgsz3516);
            shiftr(&zgsz3516, zgsz3514, zgsz3515);
            zgaz3264 = CONVERT_OF(fbits, lbits)(zgsz3516, true);
            KILL(lbits)(&zgsz3516);
            KILL(sail_int)(&zgsz3515);
            KILL(lbits)(&zgsz3514);
          }
        }
        int64_t zgaz3265;
        {
          sail_int zgsz3523;
          CREATE(sail_int)(&zgsz3523);
          CONVERT_OF(sail_int, mach_int)(&zgsz3523, zcap_mantissa_width);
          sail_int zgsz3524;
          CREATE(sail_int)(&zgsz3524);
          CONVERT_OF(sail_int, mach_int)(&zgsz3524, INT64_C(3));
          sail_int zgsz3525;
          CREATE(sail_int)(&zgsz3525);
          sub_int(&zgsz3525, zgsz3523, zgsz3524);
          zgaz3265 = CONVERT_OF(mach_int, sail_int)(zgsz3525);
          KILL(sail_int)(&zgsz3525);
          KILL(sail_int)(&zgsz3524);
          KILL(sail_int)(&zgsz3523);
        }
        {
          lbits zgsz3520;
          CREATE(lbits)(&zgsz3520);
          CONVERT_OF(lbits, fbits)(&zgsz3520, zgaz3264, UINT64_C(64) , true);
          sail_int zgsz3521;
          CREATE(sail_int)(&zgsz3521);
          CONVERT_OF(sail_int, mach_int)(&zgsz3521, zgaz3265);
          lbits zgsz3522;
          CREATE(lbits)(&zgsz3522);
          sail_truncate(&zgsz3522, zgsz3520, zgsz3521);
          zB_ie = CONVERT_OF(fbits, lbits)(zgsz3522, true);
          KILL(lbits)(&zgsz3522);
          KILL(sail_int)(&zgsz3521);
          KILL(lbits)(&zgsz3520);
        }
      }
      uint64_t zT_ie;
      {
        lbits zgaz3261;
        CREATE(lbits)(&zgaz3261);
        {
          int64_t zgaz3260;
          {
            sail_int zgsz3527;
            CREATE(sail_int)(&zgsz3527);
            CONVERT_OF(sail_int, mach_int)(&zgsz3527, ze);
            sail_int zgsz3528;
            CREATE(sail_int)(&zgsz3528);
            CONVERT_OF(sail_int, mach_int)(&zgsz3528, INT64_C(3));
            sail_int zgsz3529;
            CREATE(sail_int)(&zgsz3529);
            add_int(&zgsz3529, zgsz3527, zgsz3528);
            zgaz3260 = CONVERT_OF(mach_int, sail_int)(zgsz3529);
            KILL(sail_int)(&zgsz3529);
            KILL(sail_int)(&zgsz3528);
            KILL(sail_int)(&zgsz3527);
          }
          {
            sail_int zgsz3526;
            CREATE(sail_int)(&zgsz3526);
            CONVERT_OF(sail_int, mach_int)(&zgsz3526, zgaz3260);
            shiftr(&zgaz3261, ztop, zgsz3526);
            KILL(sail_int)(&zgsz3526);
          }
        }
        int64_t zgaz3262;
        {
          sail_int zgsz3532;
          CREATE(sail_int)(&zgsz3532);
          CONVERT_OF(sail_int, mach_int)(&zgsz3532, zcap_mantissa_width);
          sail_int zgsz3533;
          CREATE(sail_int)(&zgsz3533);
          CONVERT_OF(sail_int, mach_int)(&zgsz3533, INT64_C(3));
          sail_int zgsz3534;
          CREATE(sail_int)(&zgsz3534);
          sub_int(&zgsz3534, zgsz3532, zgsz3533);
          zgaz3262 = CONVERT_OF(mach_int, sail_int)(zgsz3534);
          KILL(sail_int)(&zgsz3534);
          KILL(sail_int)(&zgsz3533);
          KILL(sail_int)(&zgsz3532);
        }
        {
          sail_int zgsz3530;
          CREATE(sail_int)(&zgsz3530);
          CONVERT_OF(sail_int, mach_int)(&zgsz3530, zgaz3262);
          lbits zgsz3531;
          CREATE(lbits)(&zgsz3531);
          sail_truncate(&zgsz3531, zgaz3261, zgsz3530);
          zT_ie = CONVERT_OF(fbits, lbits)(zgsz3531, true);
          KILL(lbits)(&zgsz3531);
          KILL(sail_int)(&zgsz3530);
        }
        KILL(lbits)(&zgaz3261);
      }
      lbits zmaskLo;
      CREATE(lbits)(&zmaskLo);
      {
        sbits zgaz3259;
        {
          int64_t zgaz3258;
          {
            sail_int zgsz3537;
            CREATE(sail_int)(&zgsz3537);
            CONVERT_OF(sail_int, mach_int)(&zgsz3537, ze);
            sail_int zgsz3538;
            CREATE(sail_int)(&zgsz3538);
            CONVERT_OF(sail_int, mach_int)(&zgsz3538, INT64_C(3));
            sail_int zgsz3539;
            CREATE(sail_int)(&zgsz3539);
            add_int(&zgsz3539, zgsz3537, zgsz3538);
            zgaz3258 = CONVERT_OF(mach_int, sail_int)(zgsz3539);
            KILL(sail_int)(&zgsz3539);
            KILL(sail_int)(&zgsz3538);
            KILL(sail_int)(&zgsz3537);
          }
          {
            sail_int zgsz3535;
            CREATE(sail_int)(&zgsz3535);
            CONVERT_OF(sail_int, mach_int)(&zgsz3535, zgaz3258);
            lbits zgsz3536;
            CREATE(lbits)(&zgsz3536);
            sailgen_ones(&zgsz3536, zgsz3535);
            zgaz3259 = CONVERT_OF(sbits, lbits)(zgsz3536, true);
            KILL(lbits)(&zgsz3536);
            KILL(sail_int)(&zgsz3535);
          }
        }
        {
          sail_int zgsz3540;
          CREATE(sail_int)(&zgsz3540);
          CONVERT_OF(sail_int, mach_int)(&zgsz3540, INT64_C(65));
          lbits zgsz3541;
          CREATE(lbits)(&zgsz3541);
          CONVERT_OF(lbits, sbits)(&zgsz3541, zgaz3259, true);
          sailgen_EXTZ(&zmaskLo, zgsz3540, zgsz3541);
          KILL(lbits)(&zgsz3541);
          KILL(sail_int)(&zgsz3540);
        }
      }
      {
        sail_int zgaz3243;
        CREATE(sail_int)(&zgaz3243);
        {
          lbits zgaz3242;
          CREATE(lbits)(&zgaz3242);
          and_bits(&zgaz3242, zext_base, zmaskLo);
          sail_unsigned(&zgaz3243, zgaz3242);
          KILL(lbits)(&zgaz3242);
        }
        {
          sail_int zgsz3542;
          CREATE(sail_int)(&zgsz3542);
          CONVERT_OF(sail_int, mach_int)(&zgsz3542, INT64_C(0));
          zlostSignificantBase = sailgen_neq_int(zgaz3243, zgsz3542);
          KILL(sail_int)(&zgsz3542);
        }
        unit zgsz358;
        zgsz358 = UNIT;
        KILL(sail_int)(&zgaz3243);
      }
      {
        sail_int zgaz3245;
        CREATE(sail_int)(&zgaz3245);
        {
          lbits zgaz3244;
          CREATE(lbits)(&zgaz3244);
          and_bits(&zgaz3244, ztop, zmaskLo);
          sail_unsigned(&zgaz3245, zgaz3244);
          KILL(lbits)(&zgaz3244);
        }
        {
          sail_int zgsz3543;
          CREATE(sail_int)(&zgsz3543);
          CONVERT_OF(sail_int, mach_int)(&zgsz3543, INT64_C(0));
          zlostSignificantTop = sailgen_neq_int(zgaz3245, zgsz3543);
          KILL(sail_int)(&zgsz3543);
        }
        unit zgsz357;
        zgsz357 = UNIT;
        KILL(sail_int)(&zgaz3245);
      }
      {
        unit zgsz356;
        if (zlostSignificantTop) {
          {
            lbits zgsz3544;
            CREATE(lbits)(&zgsz3544);
            CONVERT_OF(lbits, fbits)(&zgsz3544, zT_ie, UINT64_C(11) , true);
            sail_int zgsz3545;
            CREATE(sail_int)(&zgsz3545);
            CONVERT_OF(sail_int, mach_int)(&zgsz3545, INT64_C(1));
            lbits zgsz3546;
            CREATE(lbits)(&zgsz3546);
            add_bits_int(&zgsz3546, zgsz3544, zgsz3545);
            zT_ie = CONVERT_OF(fbits, lbits)(zgsz3546, true);
            KILL(lbits)(&zgsz3546);
            KILL(sail_int)(&zgsz3545);
            KILL(lbits)(&zgsz3544);
          }
          zgsz356 = UNIT;
        } else {  zgsz356 = UNIT;  }
      }
      uint64_t zlen_ie;
      {
        lbits zgsz3586;
        CREATE(lbits)(&zgsz3586);
        CONVERT_OF(lbits, fbits)(&zgsz3586, zT_ie, UINT64_C(11) , true);
        lbits zgsz3587;
        CREATE(lbits)(&zgsz3587);
        CONVERT_OF(lbits, fbits)(&zgsz3587, zB_ie, UINT64_C(11) , true);
        lbits zgsz3588;
        CREATE(lbits)(&zgsz3588);
        sub_bits(&zgsz3588, zgsz3586, zgsz3587);
        zlen_ie = CONVERT_OF(fbits, lbits)(zgsz3588, true);
        KILL(lbits)(&zgsz3588);
        KILL(lbits)(&zgsz3587);
        KILL(lbits)(&zgsz3586);
      }
      {
        bool zgaz3248;
        {
          fbits zgaz3247;
          {
            int64_t zgaz3246;
            {
              sail_int zgsz3549;
              CREATE(sail_int)(&zgsz3549);
              CONVERT_OF(sail_int, mach_int)(&zgsz3549, zcap_mantissa_width);
              sail_int zgsz3550;
              CREATE(sail_int)(&zgsz3550);
              CONVERT_OF(sail_int, mach_int)(&zgsz3550, INT64_C(4));
              sail_int zgsz3551;
              CREATE(sail_int)(&zgsz3551);
              sub_int(&zgsz3551, zgsz3549, zgsz3550);
              zgaz3246 = CONVERT_OF(mach_int, sail_int)(zgsz3551);
              KILL(sail_int)(&zgsz3551);
              KILL(sail_int)(&zgsz3550);
              KILL(sail_int)(&zgsz3549);
            }
            {
              lbits zgsz3547;
              CREATE(lbits)(&zgsz3547);
              CONVERT_OF(lbits, fbits)(&zgsz3547, zlen_ie, UINT64_C(11) , true);
              sail_int zgsz3548;
              CREATE(sail_int)(&zgsz3548);
              CONVERT_OF(sail_int, mach_int)(&zgsz3548, zgaz3246);
              zgaz3247 = bitvector_access(zgsz3547, zgsz3548);
              KILL(sail_int)(&zgsz3548);
              KILL(lbits)(&zgsz3547);
            }
          }
          zgaz3248 = eq_bit(zgaz3247, UINT64_C(1));
        }
        unit zgsz360;
        if (zgaz3248) {
          {
            zincE = true;
            unit zgsz366;
            zgsz366 = UNIT;
          }
          {
            bool zgsz361;
            if (zlostSignificantBase) {  zgsz361 = true;  } else {
              fbits zgaz3249;
              {
                lbits zgsz3552;
                CREATE(lbits)(&zgsz3552);
                CONVERT_OF(lbits, fbits)(&zgsz3552, zB_ie, UINT64_C(11) , true);
                sail_int zgsz3553;
                CREATE(sail_int)(&zgsz3553);
                CONVERT_OF(sail_int, mach_int)(&zgsz3553, INT64_C(0));
                zgaz3249 = bitvector_access(zgsz3552, zgsz3553);
                KILL(sail_int)(&zgsz3553);
                KILL(lbits)(&zgsz3552);
              }
              zgsz361 = eq_bit(zgaz3249, UINT64_C(1));
            }
            zlostSignificantBase = zgsz361;
            unit zgsz365;
            zgsz365 = UNIT;
          }
          {
            bool zgsz362;
            if (zlostSignificantTop) {  zgsz362 = true;  } else {
              fbits zgaz3250;
              {
                lbits zgsz3554;
                CREATE(lbits)(&zgsz3554);
                CONVERT_OF(lbits, fbits)(&zgsz3554, zT_ie, UINT64_C(11) , true);
                sail_int zgsz3555;
                CREATE(sail_int)(&zgsz3555);
                CONVERT_OF(sail_int, mach_int)(&zgsz3555, INT64_C(0));
                zgaz3250 = bitvector_access(zgsz3554, zgsz3555);
                KILL(sail_int)(&zgsz3555);
                KILL(lbits)(&zgsz3554);
              }
              zgsz362 = eq_bit(zgaz3250, UINT64_C(1));
            }
            zlostSignificantTop = zgsz362;
            unit zgsz364;
            zgsz364 = UNIT;
          }
          {
            uint64_t zgaz3252;
            {
              int64_t zgaz3251;
              {
                sail_int zgsz3559;
                CREATE(sail_int)(&zgsz3559);
                CONVERT_OF(sail_int, mach_int)(&zgsz3559, ze);
                sail_int zgsz3560;
                CREATE(sail_int)(&zgsz3560);
                CONVERT_OF(sail_int, mach_int)(&zgsz3560, INT64_C(4));
                sail_int zgsz3561;
                CREATE(sail_int)(&zgsz3561);
                add_int(&zgsz3561, zgsz3559, zgsz3560);
                zgaz3251 = CONVERT_OF(mach_int, sail_int)(zgsz3561);
                KILL(sail_int)(&zgsz3561);
                KILL(sail_int)(&zgsz3560);
                KILL(sail_int)(&zgsz3559);
              }
              {
                lbits zgsz3556;
                CREATE(lbits)(&zgsz3556);
                CONVERT_OF(lbits, fbits)(&zgsz3556, zbase, UINT64_C(64) , true);
                sail_int zgsz3557;
                CREATE(sail_int)(&zgsz3557);
                CONVERT_OF(sail_int, mach_int)(&zgsz3557, zgaz3251);
                lbits zgsz3558;
                CREATE(lbits)(&zgsz3558);
                shiftr(&zgsz3558, zgsz3556, zgsz3557);
                zgaz3252 = CONVERT_OF(fbits, lbits)(zgsz3558, true);
                KILL(lbits)(&zgsz3558);
                KILL(sail_int)(&zgsz3557);
                KILL(lbits)(&zgsz3556);
              }
            }
            int64_t zgaz3253;
            {
              sail_int zgsz3565;
              CREATE(sail_int)(&zgsz3565);
              CONVERT_OF(sail_int, mach_int)(&zgsz3565, zcap_mantissa_width);
              sail_int zgsz3566;
              CREATE(sail_int)(&zgsz3566);
              CONVERT_OF(sail_int, mach_int)(&zgsz3566, INT64_C(3));
              sail_int zgsz3567;
              CREATE(sail_int)(&zgsz3567);
              sub_int(&zgsz3567, zgsz3565, zgsz3566);
              zgaz3253 = CONVERT_OF(mach_int, sail_int)(zgsz3567);
              KILL(sail_int)(&zgsz3567);
              KILL(sail_int)(&zgsz3566);
              KILL(sail_int)(&zgsz3565);
            }
            {
              lbits zgsz3562;
              CREATE(lbits)(&zgsz3562);
              CONVERT_OF(lbits, fbits)(&zgsz3562, zgaz3252, UINT64_C(64) , true);
              sail_int zgsz3563;
              CREATE(sail_int)(&zgsz3563);
              CONVERT_OF(sail_int, mach_int)(&zgsz3563, zgaz3253);
              lbits zgsz3564;
              CREATE(lbits)(&zgsz3564);
              sail_truncate(&zgsz3564, zgsz3562, zgsz3563);
              zB_ie = CONVERT_OF(fbits, lbits)(zgsz3564, true);
              KILL(lbits)(&zgsz3564);
              KILL(sail_int)(&zgsz3563);
              KILL(lbits)(&zgsz3562);
            }
            unit zgsz363;
            zgsz363 = UNIT;
          }
          int64_t zincT;
          if (zlostSignificantTop) {  zincT = INT64_C(1);  } else {  zincT = INT64_C(0);  }
          uint64_t zgaz3257;
          {
            lbits zgaz3255;
            CREATE(lbits)(&zgaz3255);
            {
              int64_t zgaz3254;
              {
                sail_int zgsz3569;
                CREATE(sail_int)(&zgsz3569);
                CONVERT_OF(sail_int, mach_int)(&zgsz3569, ze);
                sail_int zgsz3570;
                CREATE(sail_int)(&zgsz3570);
                CONVERT_OF(sail_int, mach_int)(&zgsz3570, INT64_C(4));
                sail_int zgsz3571;
                CREATE(sail_int)(&zgsz3571);
                add_int(&zgsz3571, zgsz3569, zgsz3570);
                zgaz3254 = CONVERT_OF(mach_int, sail_int)(zgsz3571);
                KILL(sail_int)(&zgsz3571);
                KILL(sail_int)(&zgsz3570);
                KILL(sail_int)(&zgsz3569);
              }
              {
                sail_int zgsz3568;
                CREATE(sail_int)(&zgsz3568);
                CONVERT_OF(sail_int, mach_int)(&zgsz3568, zgaz3254);
                shiftr(&zgaz3255, ztop, zgsz3568);
                KILL(sail_int)(&zgsz3568);
              }
            }
            int64_t zgaz3256;
            {
              sail_int zgsz3574;
              CREATE(sail_int)(&zgsz3574);
              CONVERT_OF(sail_int, mach_int)(&zgsz3574, zcap_mantissa_width);
              sail_int zgsz3575;
              CREATE(sail_int)(&zgsz3575);
              CONVERT_OF(sail_int, mach_int)(&zgsz3575, INT64_C(3));
              sail_int zgsz3576;
              CREATE(sail_int)(&zgsz3576);
              sub_int(&zgsz3576, zgsz3574, zgsz3575);
              zgaz3256 = CONVERT_OF(mach_int, sail_int)(zgsz3576);
              KILL(sail_int)(&zgsz3576);
              KILL(sail_int)(&zgsz3575);
              KILL(sail_int)(&zgsz3574);
            }
            {
              sail_int zgsz3572;
              CREATE(sail_int)(&zgsz3572);
              CONVERT_OF(sail_int, mach_int)(&zgsz3572, zgaz3256);
              lbits zgsz3573;
              CREATE(lbits)(&zgsz3573);
              sail_truncate(&zgsz3573, zgaz3255, zgsz3572);
              zgaz3257 = CONVERT_OF(fbits, lbits)(zgsz3573, true);
              KILL(lbits)(&zgsz3573);
              KILL(sail_int)(&zgsz3572);
            }
            KILL(lbits)(&zgaz3255);
          }
          {
            lbits zgsz3577;
            CREATE(lbits)(&zgsz3577);
            CONVERT_OF(lbits, fbits)(&zgsz3577, zgaz3257, UINT64_C(11) , true);
            sail_int zgsz3578;
            CREATE(sail_int)(&zgsz3578);
            CONVERT_OF(sail_int, mach_int)(&zgsz3578, zincT);
            lbits zgsz3579;
            CREATE(lbits)(&zgsz3579);
            add_bits_int(&zgsz3579, zgsz3577, zgsz3578);
            zT_ie = CONVERT_OF(fbits, lbits)(zgsz3579, true);
            KILL(lbits)(&zgsz3579);
            KILL(sail_int)(&zgsz3578);
            KILL(lbits)(&zgsz3577);
          }
          zgsz360 = UNIT;
        } else {  zgsz360 = UNIT;  }
      }
      {
        {
          lbits zgsz3580;
          CREATE(lbits)(&zgsz3580);
          CONVERT_OF(lbits, fbits)(&zgsz3580, zB_ie, UINT64_C(11) , true);
          lbits zgsz3581;
          CREATE(lbits)(&zgsz3581);
          CONVERT_OF(lbits, fbits)(&zgsz3581, UINT64_C(0b000), UINT64_C(3) , true);
          lbits zgsz3582;
          CREATE(lbits)(&zgsz3582);
          append(&zgsz3582, zgsz3580, zgsz3581);
          zBbits = CONVERT_OF(fbits, lbits)(zgsz3582, true);
          KILL(lbits)(&zgsz3582);
          KILL(lbits)(&zgsz3581);
          KILL(lbits)(&zgsz3580);
        }
        unit zgsz359;
        zgsz359 = UNIT;
      }
      {
        lbits zgsz3583;
        CREATE(lbits)(&zgsz3583);
        CONVERT_OF(lbits, fbits)(&zgsz3583, zT_ie, UINT64_C(11) , true);
        lbits zgsz3584;
        CREATE(lbits)(&zgsz3584);
        CONVERT_OF(lbits, fbits)(&zgsz3584, UINT64_C(0b000), UINT64_C(3) , true);
        lbits zgsz3585;
        CREATE(lbits)(&zgsz3585);
        append(&zgsz3585, zgsz3583, zgsz3584);
        zTbits = CONVERT_OF(fbits, lbits)(zgsz3585, true);
        KILL(lbits)(&zgsz3585);
        KILL(lbits)(&zgsz3584);
        KILL(lbits)(&zgsz3583);
      }
      zgsz355 = UNIT;
      KILL(lbits)(&zmaskLo);
    } else {  zgsz355 = UNIT;  }
  }
  struct zCapability znewCap;
  {
    uint64_t zgaz3268;
    {
      int64_t zgaz3267;
      if (zincE) {
        {
          sail_int zgsz3589;
          CREATE(sail_int)(&zgsz3589);
          CONVERT_OF(sail_int, mach_int)(&zgsz3589, ze);
          sail_int zgsz3590;
          CREATE(sail_int)(&zgsz3590);
          CONVERT_OF(sail_int, mach_int)(&zgsz3590, INT64_C(1));
          sail_int zgsz3591;
          CREATE(sail_int)(&zgsz3591);
          add_int(&zgsz3591, zgsz3589, zgsz3590);
          zgaz3267 = CONVERT_OF(mach_int, sail_int)(zgsz3591);
          KILL(sail_int)(&zgsz3591);
          KILL(sail_int)(&zgsz3590);
          KILL(sail_int)(&zgsz3589);
        }
      } else {  zgaz3267 = ze;  }
      {
        sail_int zgsz3592;
        CREATE(sail_int)(&zgsz3592);
        CONVERT_OF(sail_int, mach_int)(&zgsz3592, INT64_C(6));
        sail_int zgsz3593;
        CREATE(sail_int)(&zgsz3593);
        CONVERT_OF(sail_int, mach_int)(&zgsz3593, zgaz3267);
        lbits zgsz3594;
        CREATE(lbits)(&zgsz3594);
        sailgen_to_bits(&zgsz3594, zgsz3592, zgsz3593);
        zgaz3268 = CONVERT_OF(fbits, lbits)(zgsz3594, true);
        KILL(lbits)(&zgsz3594);
        KILL(sail_int)(&zgsz3593);
        KILL(sail_int)(&zgsz3592);
      }
    }
    struct zCapability zgsz367;
    zgsz367 = zcap;
    zgsz367.zB = zBbits;
    zgsz367.zE = zgaz3268;
    zgsz367.zT = zTbits;
    zgsz367.zaddress = zbase;
    zgsz367.zinternal_E = zie;
    znewCap = zgsz367;
  }
  bool zexact;
  {
    bool zgaz3266;
    {
      bool zgsz368;
      if (zlostSignificantBase) {  zgsz368 = true;  } else {  zgsz368 = zlostSignificantTop;  }
      zgaz3266 = zgsz368;
    }
    zexact = not(zgaz3266);
  }
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgsz369;
  zgsz369.ztup0 = zexact;
  zgsz369.ztup1 = znewCap;
  zcbz326 = zgsz369;










  KILL(lbits)(&zlength);
  KILL(lbits)(&zext_base);
end_function_116: ;
  return zcbz326;
end_block_exception_117: ;
  struct zCapability zcbz353 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz352 = { .ztup0 = false, .ztup1 = zcbz353 };
  return zcbz352;
}

static uint64_t sailgen_getCapPerms(struct zCapability);

static uint64_t sailgen_getCapPerms(struct zCapability zcap)
{
  __label__ end_function_119, end_block_exception_120;

  uint64_t zcbz327;
  uint64_t zperms;
  {
    uint64_t zgaz3276;
    zgaz3276 = sailgen_getCapHardPerms(zcap);
    {
      sail_int zgsz3602;
      CREATE(sail_int)(&zgsz3602);
      CONVERT_OF(sail_int, mach_int)(&zgsz3602, INT64_C(15));
      lbits zgsz3603;
      CREATE(lbits)(&zgsz3603);
      CONVERT_OF(lbits, fbits)(&zgsz3603, zgaz3276, UINT64_C(12) , true);
      lbits zgsz3604;
      CREATE(lbits)(&zgsz3604);
      sailgen_EXTZ(&zgsz3604, zgsz3602, zgsz3603);
      zperms = CONVERT_OF(fbits, lbits)(zgsz3604, true);
      KILL(lbits)(&zgsz3604);
      KILL(lbits)(&zgsz3603);
      KILL(sail_int)(&zgsz3602);
    }
  }
  uint64_t zgaz3275;
  zgaz3275 = zcap.zuperms;
  {
    lbits zgsz3605;
    CREATE(lbits)(&zgsz3605);
    CONVERT_OF(lbits, fbits)(&zgsz3605, zgaz3275, UINT64_C(4) , true);
    lbits zgsz3606;
    CREATE(lbits)(&zgsz3606);
    CONVERT_OF(lbits, fbits)(&zgsz3606, zperms, UINT64_C(15) , true);
    lbits zgsz3607;
    CREATE(lbits)(&zgsz3607);
    append(&zgsz3607, zgsz3605, zgsz3606);
    zcbz327 = CONVERT_OF(fbits, lbits)(zgsz3607, true);
    KILL(lbits)(&zgsz3607);
    KILL(lbits)(&zgsz3606);
    KILL(lbits)(&zgsz3605);
  }


end_function_119: ;
  return zcbz327;
end_block_exception_120: ;

  return UINT64_C(0xdeadc0de);
}

static struct zCapability sailgen_setCapPerms(struct zCapability, uint64_t);

static struct zCapability sailgen_setCapPerms(struct zCapability zcap, uint64_t zperms)
{
  __label__ end_function_122, end_block_exception_123;

  struct zCapability zcbz328;
  uint64_t zgaz3278;
  {
    uint64_t zgaz3277;
    {
      lbits zgsz3611;
      CREATE(lbits)(&zgsz3611);
      CONVERT_OF(lbits, fbits)(&zgsz3611, zperms, UINT64_C(19) , true);
      sail_int zgsz3612;
      CREATE(sail_int)(&zgsz3612);
      CONVERT_OF(sail_int, mach_int)(&zgsz3612, zcap_uperms_shift);
      lbits zgsz3613;
      CREATE(lbits)(&zgsz3613);
      shiftr(&zgsz3613, zgsz3611, zgsz3612);
      zgaz3277 = CONVERT_OF(fbits, lbits)(zgsz3613, true);
      KILL(lbits)(&zgsz3613);
      KILL(sail_int)(&zgsz3612);
      KILL(lbits)(&zgsz3611);
    }
    {
      lbits zgsz3608;
      CREATE(lbits)(&zgsz3608);
      CONVERT_OF(lbits, fbits)(&zgsz3608, zgaz3277, UINT64_C(19) , true);
      sail_int zgsz3609;
      CREATE(sail_int)(&zgsz3609);
      CONVERT_OF(sail_int, mach_int)(&zgsz3609, zcap_uperms_width);
      lbits zgsz3610;
      CREATE(lbits)(&zgsz3610);
      sail_truncate(&zgsz3610, zgsz3608, zgsz3609);
      zgaz3278 = CONVERT_OF(fbits, lbits)(zgsz3610, true);
      KILL(lbits)(&zgsz3610);
      KILL(sail_int)(&zgsz3609);
      KILL(lbits)(&zgsz3608);
    }
  }
  bool zgaz3280;
  {
    fbits zgaz3279;
    {
      lbits zgsz3614;
      CREATE(lbits)(&zgsz3614);
      CONVERT_OF(lbits, fbits)(&zgsz3614, zperms, UINT64_C(19) , true);
      sail_int zgsz3615;
      CREATE(sail_int)(&zgsz3615);
      CONVERT_OF(sail_int, mach_int)(&zgsz3615, INT64_C(11));
      zgaz3279 = bitvector_access(zgsz3614, zgsz3615);
      KILL(sail_int)(&zgsz3615);
      KILL(lbits)(&zgsz3614);
    }
    zgaz3280 = sailgen_bit_to_bool(zgaz3279);
  }
  bool zgaz3282;
  {
    fbits zgaz3281;
    {
      lbits zgsz3616;
      CREATE(lbits)(&zgsz3616);
      CONVERT_OF(lbits, fbits)(&zgsz3616, zperms, UINT64_C(19) , true);
      sail_int zgsz3617;
      CREATE(sail_int)(&zgsz3617);
      CONVERT_OF(sail_int, mach_int)(&zgsz3617, INT64_C(10));
      zgaz3281 = bitvector_access(zgsz3616, zgsz3617);
      KILL(sail_int)(&zgsz3617);
      KILL(lbits)(&zgsz3616);
    }
    zgaz3282 = sailgen_bit_to_bool(zgaz3281);
  }
  bool zgaz3284;
  {
    fbits zgaz3283;
    {
      lbits zgsz3618;
      CREATE(lbits)(&zgsz3618);
      CONVERT_OF(lbits, fbits)(&zgsz3618, zperms, UINT64_C(19) , true);
      sail_int zgsz3619;
      CREATE(sail_int)(&zgsz3619);
      CONVERT_OF(sail_int, mach_int)(&zgsz3619, INT64_C(9));
      zgaz3283 = bitvector_access(zgsz3618, zgsz3619);
      KILL(sail_int)(&zgsz3619);
      KILL(lbits)(&zgsz3618);
    }
    zgaz3284 = sailgen_bit_to_bool(zgaz3283);
  }
  bool zgaz3286;
  {
    fbits zgaz3285;
    {
      lbits zgsz3620;
      CREATE(lbits)(&zgsz3620);
      CONVERT_OF(lbits, fbits)(&zgsz3620, zperms, UINT64_C(19) , true);
      sail_int zgsz3621;
      CREATE(sail_int)(&zgsz3621);
      CONVERT_OF(sail_int, mach_int)(&zgsz3621, INT64_C(8));
      zgaz3285 = bitvector_access(zgsz3620, zgsz3621);
      KILL(sail_int)(&zgsz3621);
      KILL(lbits)(&zgsz3620);
    }
    zgaz3286 = sailgen_bit_to_bool(zgaz3285);
  }
  bool zgaz3288;
  {
    fbits zgaz3287;
    {
      lbits zgsz3622;
      CREATE(lbits)(&zgsz3622);
      CONVERT_OF(lbits, fbits)(&zgsz3622, zperms, UINT64_C(19) , true);
      sail_int zgsz3623;
      CREATE(sail_int)(&zgsz3623);
      CONVERT_OF(sail_int, mach_int)(&zgsz3623, INT64_C(7));
      zgaz3287 = bitvector_access(zgsz3622, zgsz3623);
      KILL(sail_int)(&zgsz3623);
      KILL(lbits)(&zgsz3622);
    }
    zgaz3288 = sailgen_bit_to_bool(zgaz3287);
  }
  bool zgaz3290;
  {
    fbits zgaz3289;
    {
      lbits zgsz3624;
      CREATE(lbits)(&zgsz3624);
      CONVERT_OF(lbits, fbits)(&zgsz3624, zperms, UINT64_C(19) , true);
      sail_int zgsz3625;
      CREATE(sail_int)(&zgsz3625);
      CONVERT_OF(sail_int, mach_int)(&zgsz3625, INT64_C(6));
      zgaz3289 = bitvector_access(zgsz3624, zgsz3625);
      KILL(sail_int)(&zgsz3625);
      KILL(lbits)(&zgsz3624);
    }
    zgaz3290 = sailgen_bit_to_bool(zgaz3289);
  }
  bool zgaz3292;
  {
    fbits zgaz3291;
    {
      lbits zgsz3626;
      CREATE(lbits)(&zgsz3626);
      CONVERT_OF(lbits, fbits)(&zgsz3626, zperms, UINT64_C(19) , true);
      sail_int zgsz3627;
      CREATE(sail_int)(&zgsz3627);
      CONVERT_OF(sail_int, mach_int)(&zgsz3627, INT64_C(5));
      zgaz3291 = bitvector_access(zgsz3626, zgsz3627);
      KILL(sail_int)(&zgsz3627);
      KILL(lbits)(&zgsz3626);
    }
    zgaz3292 = sailgen_bit_to_bool(zgaz3291);
  }
  bool zgaz3294;
  {
    fbits zgaz3293;
    {
      lbits zgsz3628;
      CREATE(lbits)(&zgsz3628);
      CONVERT_OF(lbits, fbits)(&zgsz3628, zperms, UINT64_C(19) , true);
      sail_int zgsz3629;
      CREATE(sail_int)(&zgsz3629);
      CONVERT_OF(sail_int, mach_int)(&zgsz3629, INT64_C(4));
      zgaz3293 = bitvector_access(zgsz3628, zgsz3629);
      KILL(sail_int)(&zgsz3629);
      KILL(lbits)(&zgsz3628);
    }
    zgaz3294 = sailgen_bit_to_bool(zgaz3293);
  }
  bool zgaz3296;
  {
    fbits zgaz3295;
    {
      lbits zgsz3630;
      CREATE(lbits)(&zgsz3630);
      CONVERT_OF(lbits, fbits)(&zgsz3630, zperms, UINT64_C(19) , true);
      sail_int zgsz3631;
      CREATE(sail_int)(&zgsz3631);
      CONVERT_OF(sail_int, mach_int)(&zgsz3631, INT64_C(3));
      zgaz3295 = bitvector_access(zgsz3630, zgsz3631);
      KILL(sail_int)(&zgsz3631);
      KILL(lbits)(&zgsz3630);
    }
    zgaz3296 = sailgen_bit_to_bool(zgaz3295);
  }
  bool zgaz3298;
  {
    fbits zgaz3297;
    {
      lbits zgsz3632;
      CREATE(lbits)(&zgsz3632);
      CONVERT_OF(lbits, fbits)(&zgsz3632, zperms, UINT64_C(19) , true);
      sail_int zgsz3633;
      CREATE(sail_int)(&zgsz3633);
      CONVERT_OF(sail_int, mach_int)(&zgsz3633, INT64_C(2));
      zgaz3297 = bitvector_access(zgsz3632, zgsz3633);
      KILL(sail_int)(&zgsz3633);
      KILL(lbits)(&zgsz3632);
    }
    zgaz3298 = sailgen_bit_to_bool(zgaz3297);
  }
  bool zgaz3300;
  {
    fbits zgaz3299;
    {
      lbits zgsz3634;
      CREATE(lbits)(&zgsz3634);
      CONVERT_OF(lbits, fbits)(&zgsz3634, zperms, UINT64_C(19) , true);
      sail_int zgsz3635;
      CREATE(sail_int)(&zgsz3635);
      CONVERT_OF(sail_int, mach_int)(&zgsz3635, INT64_C(1));
      zgaz3299 = bitvector_access(zgsz3634, zgsz3635);
      KILL(sail_int)(&zgsz3635);
      KILL(lbits)(&zgsz3634);
    }
    zgaz3300 = sailgen_bit_to_bool(zgaz3299);
  }
  bool zgaz3302;
  {
    fbits zgaz3301;
    {
      lbits zgsz3636;
      CREATE(lbits)(&zgsz3636);
      CONVERT_OF(lbits, fbits)(&zgsz3636, zperms, UINT64_C(19) , true);
      sail_int zgsz3637;
      CREATE(sail_int)(&zgsz3637);
      CONVERT_OF(sail_int, mach_int)(&zgsz3637, INT64_C(0));
      zgaz3301 = bitvector_access(zgsz3636, zgsz3637);
      KILL(sail_int)(&zgsz3637);
      KILL(lbits)(&zgsz3636);
    }
    zgaz3302 = sailgen_bit_to_bool(zgaz3301);
  }
  struct zCapability zgsz370;
  zgsz370 = zcap;
  zgsz370.zaccess_system_regs = zgaz3282;
  zgsz370.zglobal = zgaz3302;
  zgsz370.zpermit_cinvoke = zgaz3286;
  zgsz370.zpermit_execute = zgaz3300;
  zgsz370.zpermit_load = zgaz3298;
  zgsz370.zpermit_load_cap = zgaz3294;
  zgsz370.zpermit_seal = zgaz3288;
  zgsz370.zpermit_set_CID = zgaz3280;
  zgsz370.zpermit_store = zgaz3296;
  zgsz370.zpermit_store_cap = zgaz3292;
  zgsz370.zpermit_store_local_cap = zgaz3290;
  zgsz370.zpermit_unseal = zgaz3284;
  zgsz370.zuperms = zgaz3278;
  zcbz328 = zgsz370;














end_function_122: ;
  return zcbz328;
end_block_exception_123: ;
  struct zCapability zcbz354 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  return zcbz354;
}

static uint64_t sailgen_getCapFlags(struct zCapability);

static uint64_t sailgen_getCapFlags(struct zCapability zcap)
{
  __label__ end_function_125, end_block_exception_126;

  uint64_t zcbz329;
  bool zgaz3303;
  zgaz3303 = zcap.zflag_cap_mode;
  zcbz329 = sailgen_bool_to_bits(zgaz3303);

end_function_125: ;
  return zcbz329;
end_block_exception_126: ;

  return UINT64_C(0xdeadc0de);
}

static bool sailgen_isCapSealed(struct zCapability);

static bool sailgen_isCapSealed(struct zCapability zcap)
{
  __label__ end_function_128, end_block_exception_129;

  bool zcbz330;
  int64_t zgaz3305;
  {
    uint64_t zgaz3304;
    zgaz3304 = zcap.zotype;
    {
      lbits zgsz3638;
      CREATE(lbits)(&zgsz3638);
      CONVERT_OF(lbits, fbits)(&zgsz3638, zgaz3304, UINT64_C(18) , true);
      sail_int zgsz3639;
      CREATE(sail_int)(&zgsz3639);
      sail_signed(&zgsz3639, zgsz3638);
      zgaz3305 = CONVERT_OF(mach_int, sail_int)(zgsz3639);
      KILL(sail_int)(&zgsz3639);
      KILL(lbits)(&zgsz3638);
    }
  }
  {
    sail_int zgsz3640;
    CREATE(sail_int)(&zgsz3640);
    CONVERT_OF(sail_int, mach_int)(&zgsz3640, zgaz3305);
    sail_int zgsz3641;
    CREATE(sail_int)(&zgsz3641);
    CONVERT_OF(sail_int, mach_int)(&zgsz3641, zotype_unsealed);
    zcbz330 = sailgen_neq_int(zgsz3640, zgsz3641);
    KILL(sail_int)(&zgsz3641);
    KILL(sail_int)(&zgsz3640);
  }

end_function_128: ;
  return zcbz330;
end_block_exception_129: ;

  return false;
}

static bool sailgen_hasReservedOType(struct zCapability);

static bool sailgen_hasReservedOType(struct zCapability zcap)
{
  __label__ end_function_131, end_block_exception_132;

  bool zcbz331;
  int64_t zgaz3307;
  {
    uint64_t zgaz3306;
    zgaz3306 = zcap.zotype;
    {
      lbits zgsz3642;
      CREATE(lbits)(&zgsz3642);
      CONVERT_OF(lbits, fbits)(&zgsz3642, zgaz3306, UINT64_C(18) , true);
      sail_int zgsz3643;
      CREATE(sail_int)(&zgsz3643);
      sail_unsigned(&zgsz3643, zgsz3642);
      zgaz3307 = CONVERT_OF(mach_int, sail_int)(zgsz3643);
      KILL(sail_int)(&zgsz3643);
      KILL(lbits)(&zgsz3642);
    }
  }
  {
    sail_int zgsz3644;
    CREATE(sail_int)(&zgsz3644);
    CONVERT_OF(sail_int, mach_int)(&zgsz3644, zgaz3307);
    sail_int zgsz3645;
    CREATE(sail_int)(&zgsz3645);
    CONVERT_OF(sail_int, mach_int)(&zgsz3645, zcap_max_otype);
    zcbz331 = gt(zgsz3644, zgsz3645);
    KILL(sail_int)(&zgsz3645);
    KILL(sail_int)(&zgsz3644);
  }

end_function_131: ;
  return zcbz331;
end_block_exception_132: ;

  return false;
}

static uint64_t sailgen_getCapBaseBits(struct zCapability);

static uint64_t sailgen_getCapBaseBits(struct zCapability zc)
{
  __label__ case_135, finish_match_134, end_function_136, end_block_exception_137;

  uint64_t zcbz332;
  struct ztuple_z8z5bv64zCz0z5bvz9 zgaz3308;
  CREATE(ztuple_z8z5bv64zCz0z5bvz9)(&zgaz3308);
  sailgen_getCapBoundsBits(&zgaz3308, zc);
  uint64_t zgsz371;
  {
    uint64_t zbase;
    zbase = zgaz3308.ztup0;
    zgsz371 = zbase;
    goto finish_match_134;
  }
case_135: ;
  sail_match_failure("getCapBaseBits");
finish_match_134: ;
  zcbz332 = zgsz371;

  KILL(ztuple_z8z5bv64zCz0z5bvz9)(&zgaz3308);
end_function_136: ;
  return zcbz332;
end_block_exception_137: ;

  return UINT64_C(0xdeadc0de);
}

static void sailgen_getCapLength(sail_int *rop, struct zCapability);

static void sailgen_getCapLength(sail_int *zcbz333, struct zCapability zc)
{
  __label__ case_140, finish_match_139, end_function_141, end_block_exception_142, end_function_196;

  struct ztuple_z8z5izCz0z5iz9 zgaz3309;
  CREATE(ztuple_z8z5izCz0z5iz9)(&zgaz3309);
  sailgen_getCapBounds(&zgaz3309, zc);
  sail_int zgsz373;
  CREATE(sail_int)(&zgsz373);
  {
    sail_int zbase;
    CREATE(sail_int)(&zbase);
    COPY(sail_int)(&zbase, zgaz3309.ztup0);
    sail_int ztop;
    CREATE(sail_int)(&ztop);
    COPY(sail_int)(&ztop, zgaz3309.ztup1);
    {
      bool zgaz3312;
      {
        bool zgaz3311;
        {
          bool zgaz3310;
          zgaz3310 = zc.ztag;
          zgaz3311 = not(zgaz3310);
        }
        bool zgsz374;
        if (zgaz3311) {  zgsz374 = true;  } else {  zgsz374 = gteq(ztop, zbase);  }
        zgaz3312 = zgsz374;
      }
      unit zgsz375;
      zgsz375 = sail_assert(zgaz3312, "src/cheri_cap_common.sail:453.40-453.41");
    }
    sail_int zgaz3313;
    CREATE(sail_int)(&zgaz3313);
    sub_int(&zgaz3313, ztop, zbase);
    sail_int zgaz3314;
    CREATE(sail_int)(&zgaz3314);
    {
      sail_int zgsz3646;
      CREATE(sail_int)(&zgsz3646);
      CONVERT_OF(sail_int, mach_int)(&zgsz3646, zcap_len_width);
      pow2(&zgaz3314, zgsz3646);
      KILL(sail_int)(&zgsz3646);
    }
    emod_int(&zgsz373, zgaz3313, zgaz3314);
    KILL(sail_int)(&zgaz3314);
    KILL(sail_int)(&zgaz3313);
    KILL(sail_int)(&ztop);
    KILL(sail_int)(&zbase);
    goto finish_match_139;
  }
case_140: ;
  sail_match_failure("getCapLength");
finish_match_139: ;
  COPY(sail_int)((*(&zcbz333)), zgsz373);
  KILL(sail_int)(&zgsz373);
  KILL(ztuple_z8z5izCz0z5iz9)(&zgaz3309);
end_function_141: ;
  goto end_function_196;
end_block_exception_142: ;
  goto end_function_196;
end_function_196: ;
}

static bool sailgen_inCapBounds(struct zCapability, uint64_t, sail_int);

static bool sailgen_inCapBounds(struct zCapability zcap, uint64_t zaddr, sail_int zsizze)
{
  __label__ case_145, finish_match_144, end_function_146, end_block_exception_147;

  bool zcbz334;
  struct ztuple_z8z5izCz0z5iz9 zgaz3315;
  CREATE(ztuple_z8z5izCz0z5iz9)(&zgaz3315);
  sailgen_getCapBounds(&zgaz3315, zcap);
  bool zgsz377;
  {
    sail_int zbase;
    CREATE(sail_int)(&zbase);
    COPY(sail_int)(&zbase, zgaz3315.ztup0);
    sail_int ztop;
    CREATE(sail_int)(&ztop);
    COPY(sail_int)(&ztop, zgaz3315.ztup1);
    sail_int za;
    CREATE(sail_int)(&za);
    {
      lbits zgsz3647;
      CREATE(lbits)(&zgsz3647);
      CONVERT_OF(lbits, fbits)(&zgsz3647, zaddr, UINT64_C(64) , true);
      sail_unsigned(&za, zgsz3647);
      KILL(lbits)(&zgsz3647);
    }
    bool zgaz3317;
    zgaz3317 = gteq(za, zbase);
    bool zgsz378;
    if (zgaz3317) {
      sail_int zgaz3316;
      CREATE(sail_int)(&zgaz3316);
      add_int(&zgaz3316, za, zsizze);
      zgsz378 = lteq(zgaz3316, ztop);
      KILL(sail_int)(&zgaz3316);
    } else {  zgsz378 = false;  }
    zgsz377 = zgsz378;
    KILL(sail_int)(&za);
    KILL(sail_int)(&ztop);
    KILL(sail_int)(&zbase);
    goto finish_match_144;
  }
case_145: ;
  sail_match_failure("inCapBounds");
finish_match_144: ;
  zcbz334 = zgsz377;

  KILL(ztuple_z8z5izCz0z5iz9)(&zgaz3315);
end_function_146: ;
  return zcbz334;
end_block_exception_147: ;

  return false;
}

static struct zCapability sailgen_clearTagIf(struct zCapability, bool);

static struct zCapability sailgen_clearTagIf(struct zCapability zcap, bool zcond)
{
  __label__ end_function_149, end_block_exception_150;

  struct zCapability zcbz335;
  bool zgaz3319;
  {
    bool zgaz3318;
    zgaz3318 = zcap.ztag;
    bool zgsz380;
    if (zgaz3318) {  zgsz380 = not(zcond);  } else {  zgsz380 = false;  }
    zgaz3319 = zgsz380;
  }
  struct zCapability zgsz381;
  zgsz381 = zcap;
  zgsz381.ztag = zgaz3319;
  zcbz335 = zgsz381;


end_function_149: ;
  return zcbz335;
end_block_exception_150: ;
  struct zCapability zcbz355 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  return zcbz355;
}

static struct zCapability sailgen_clearTagIfSealed(struct zCapability);

static struct zCapability sailgen_clearTagIfSealed(struct zCapability zcap)
{
  __label__ end_function_152, end_block_exception_153;

  struct zCapability zcbz336;
  bool zgaz3320;
  zgaz3320 = sailgen_isCapSealed(zcap);
  zcbz336 = sailgen_clearTagIf(zcap, zgaz3320);

end_function_152: ;
  return zcbz336;
end_block_exception_153: ;
  struct zCapability zcbz356 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  return zcbz356;
}

static bool sailgen_capBoundsEqual(struct zCapability, struct zCapability);

static bool sailgen_capBoundsEqual(struct zCapability zc1, struct zCapability zc2)
{
  __label__ case_156, finish_match_155, end_function_159, end_block_exception_160;

  bool zcbz337;
  struct ztuple_z8z5izCz0z5iz9 zgaz3321;
  CREATE(ztuple_z8z5izCz0z5iz9)(&zgaz3321);
  sailgen_getCapBounds(&zgaz3321, zc1);
  bool zgsz382;
  {
    __label__ case_158, finish_match_157;

    sail_int zbase1;
    CREATE(sail_int)(&zbase1);
    COPY(sail_int)(&zbase1, zgaz3321.ztup0);
    sail_int ztop1;
    CREATE(sail_int)(&ztop1);
    COPY(sail_int)(&ztop1, zgaz3321.ztup1);
    struct ztuple_z8z5izCz0z5iz9 zgaz3322;
    CREATE(ztuple_z8z5izCz0z5iz9)(&zgaz3322);
    sailgen_getCapBounds(&zgaz3322, zc2);
    bool zgsz383;
    {
      sail_int zbase2;
      CREATE(sail_int)(&zbase2);
      COPY(sail_int)(&zbase2, zgaz3322.ztup0);
      sail_int ztop2;
      CREATE(sail_int)(&ztop2);
      COPY(sail_int)(&ztop2, zgaz3322.ztup1);
      bool zgaz3323;
      zgaz3323 = eq_int(zbase1, zbase2);
      bool zgsz384;
      if (zgaz3323) {  zgsz384 = eq_int(ztop1, ztop2);  } else {  zgsz384 = false;  }
      zgsz383 = zgsz384;
      KILL(sail_int)(&ztop2);
      KILL(sail_int)(&zbase2);
      goto finish_match_157;
    }
  case_158: ;
    sail_match_failure("capBoundsEqual");
  finish_match_157: ;
    zgsz382 = zgsz383;
    KILL(ztuple_z8z5izCz0z5iz9)(&zgaz3322);
    KILL(sail_int)(&ztop1);
    KILL(sail_int)(&zbase1);
    goto finish_match_155;
  }
case_156: ;
  sail_match_failure("capBoundsEqual");
finish_match_155: ;
  zcbz337 = zgsz382;

  KILL(ztuple_z8z5izCz0z5iz9)(&zgaz3321);
end_function_159: ;
  return zcbz337;
end_block_exception_160: ;

  return false;
}

static struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 sailgen_setCapAddr(struct zCapability, uint64_t);

static struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 sailgen_setCapAddr(struct zCapability zc, uint64_t zaddr)
{
  __label__ end_function_162, end_block_exception_163;

  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz338;
  struct zCapability znewCap;
  {
    struct zCapability zgsz387;
    zgsz387 = zc;
    zgsz387.zaddress = zaddr;
    znewCap = zgsz387;
  }
  bool zrepresentable;
  zrepresentable = sailgen_capBoundsEqual(zc, znewCap);
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgsz388;
  zgsz388.ztup0 = zrepresentable;
  zgsz388.ztup1 = znewCap;
  zcbz338 = zgsz388;



end_function_162: ;
  return zcbz338;
end_block_exception_163: ;
  struct zCapability zcbz358 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz357 = { .ztup0 = false, .ztup1 = zcbz358 };
  return zcbz357;
}

static bool sailgen_fastRepCheck(struct zCapability, uint64_t);

static bool sailgen_fastRepCheck(struct zCapability zc, uint64_t zi)
{
  __label__ end_function_165, end_block_exception_166;

  bool zcbz339;
  int64_t zE;
  {
    uint64_t zgaz3337;
    zgaz3337 = zc.zE;
    {
      lbits zgsz3648;
      CREATE(lbits)(&zgsz3648);
      CONVERT_OF(lbits, fbits)(&zgsz3648, zgaz3337, UINT64_C(6) , true);
      sail_int zgsz3649;
      CREATE(sail_int)(&zgsz3649);
      sail_unsigned(&zgsz3649, zgsz3648);
      zE = CONVERT_OF(mach_int, sail_int)(zgsz3649);
      KILL(sail_int)(&zgsz3649);
      KILL(lbits)(&zgsz3648);
    }
  }
  bool zgaz3325;
  {
    int64_t zgaz3324;
    {
      sail_int zgsz3652;
      CREATE(sail_int)(&zgsz3652);
      CONVERT_OF(sail_int, mach_int)(&zgsz3652, zcap_max_E);
      sail_int zgsz3653;
      CREATE(sail_int)(&zgsz3653);
      CONVERT_OF(sail_int, mach_int)(&zgsz3653, INT64_C(2));
      sail_int zgsz3654;
      CREATE(sail_int)(&zgsz3654);
      sub_int(&zgsz3654, zgsz3652, zgsz3653);
      zgaz3324 = CONVERT_OF(mach_int, sail_int)(zgsz3654);
      KILL(sail_int)(&zgsz3654);
      KILL(sail_int)(&zgsz3653);
      KILL(sail_int)(&zgsz3652);
    }
    {
      sail_int zgsz3650;
      CREATE(sail_int)(&zgsz3650);
      CONVERT_OF(sail_int, mach_int)(&zgsz3650, zE);
      sail_int zgsz3651;
      CREATE(sail_int)(&zgsz3651);
      CONVERT_OF(sail_int, mach_int)(&zgsz3651, zgaz3324);
      zgaz3325 = gteq(zgsz3650, zgsz3651);
      KILL(sail_int)(&zgsz3651);
      KILL(sail_int)(&zgsz3650);
    }
  }
  if (zgaz3325) {  zcbz339 = true;  } else {
    int64_t zi_top;
    {
      uint64_t zgaz3336;
      {
        int64_t zgaz3335;
        {
          sail_int zgsz3658;
          CREATE(sail_int)(&zgsz3658);
          CONVERT_OF(sail_int, mach_int)(&zgsz3658, zE);
          sail_int zgsz3659;
          CREATE(sail_int)(&zgsz3659);
          CONVERT_OF(sail_int, mach_int)(&zgsz3659, zcap_mantissa_width);
          sail_int zgsz3660;
          CREATE(sail_int)(&zgsz3660);
          add_int(&zgsz3660, zgsz3658, zgsz3659);
          zgaz3335 = CONVERT_OF(mach_int, sail_int)(zgsz3660);
          KILL(sail_int)(&zgsz3660);
          KILL(sail_int)(&zgsz3659);
          KILL(sail_int)(&zgsz3658);
        }
        {
          lbits zgsz3655;
          CREATE(lbits)(&zgsz3655);
          CONVERT_OF(lbits, fbits)(&zgsz3655, zi, UINT64_C(64) , true);
          sail_int zgsz3656;
          CREATE(sail_int)(&zgsz3656);
          CONVERT_OF(sail_int, mach_int)(&zgsz3656, zgaz3335);
          lbits zgsz3657;
          CREATE(lbits)(&zgsz3657);
          arith_shiftr(&zgsz3657, zgsz3655, zgsz3656);
          zgaz3336 = CONVERT_OF(fbits, lbits)(zgsz3657, true);
          KILL(lbits)(&zgsz3657);
          KILL(sail_int)(&zgsz3656);
          KILL(lbits)(&zgsz3655);
        }
      }
      {
        lbits zgsz3661;
        CREATE(lbits)(&zgsz3661);
        CONVERT_OF(lbits, fbits)(&zgsz3661, zgaz3336, UINT64_C(64) , true);
        sail_int zgsz3662;
        CREATE(sail_int)(&zgsz3662);
        sail_signed(&zgsz3662, zgsz3661);
        zi_top = CONVERT_OF(mach_int, sail_int)(zgsz3662);
        KILL(sail_int)(&zgsz3662);
        KILL(lbits)(&zgsz3661);
      }
    }
    uint64_t zi_mid;
    {
      uint64_t zgaz3334;
      {
        lbits zgsz3666;
        CREATE(lbits)(&zgsz3666);
        CONVERT_OF(lbits, fbits)(&zgsz3666, zi, UINT64_C(64) , true);
        sail_int zgsz3667;
        CREATE(sail_int)(&zgsz3667);
        CONVERT_OF(sail_int, mach_int)(&zgsz3667, zE);
        lbits zgsz3668;
        CREATE(lbits)(&zgsz3668);
        shiftr(&zgsz3668, zgsz3666, zgsz3667);
        zgaz3334 = CONVERT_OF(fbits, lbits)(zgsz3668, true);
        KILL(lbits)(&zgsz3668);
        KILL(sail_int)(&zgsz3667);
        KILL(lbits)(&zgsz3666);
      }
      {
        lbits zgsz3663;
        CREATE(lbits)(&zgsz3663);
        CONVERT_OF(lbits, fbits)(&zgsz3663, zgaz3334, UINT64_C(64) , true);
        sail_int zgsz3664;
        CREATE(sail_int)(&zgsz3664);
        CONVERT_OF(sail_int, mach_int)(&zgsz3664, zcap_mantissa_width);
        lbits zgsz3665;
        CREATE(lbits)(&zgsz3665);
        sail_truncate(&zgsz3665, zgsz3663, zgsz3664);
        zi_mid = CONVERT_OF(fbits, lbits)(zgsz3665, true);
        KILL(lbits)(&zgsz3665);
        KILL(sail_int)(&zgsz3664);
        KILL(lbits)(&zgsz3663);
      }
    }
    uint64_t za_mid;
    {
      uint64_t zgaz3333;
      {
        uint64_t zgaz3332;
        zgaz3332 = zc.zaddress;
        {
          lbits zgsz3669;
          CREATE(lbits)(&zgsz3669);
          CONVERT_OF(lbits, fbits)(&zgsz3669, zgaz3332, UINT64_C(64) , true);
          sail_int zgsz3670;
          CREATE(sail_int)(&zgsz3670);
          CONVERT_OF(sail_int, mach_int)(&zgsz3670, zE);
          lbits zgsz3671;
          CREATE(lbits)(&zgsz3671);
          shiftr(&zgsz3671, zgsz3669, zgsz3670);
          zgaz3333 = CONVERT_OF(fbits, lbits)(zgsz3671, true);
          KILL(lbits)(&zgsz3671);
          KILL(sail_int)(&zgsz3670);
          KILL(lbits)(&zgsz3669);
        }
      }
      {
        lbits zgsz3672;
        CREATE(lbits)(&zgsz3672);
        CONVERT_OF(lbits, fbits)(&zgsz3672, zgaz3333, UINT64_C(64) , true);
        sail_int zgsz3673;
        CREATE(sail_int)(&zgsz3673);
        CONVERT_OF(sail_int, mach_int)(&zgsz3673, zcap_mantissa_width);
        lbits zgsz3674;
        CREATE(lbits)(&zgsz3674);
        sail_truncate(&zgsz3674, zgsz3672, zgsz3673);
        za_mid = CONVERT_OF(fbits, lbits)(zgsz3674, true);
        KILL(lbits)(&zgsz3674);
        KILL(sail_int)(&zgsz3673);
        KILL(lbits)(&zgsz3672);
      }
    }
    uint64_t zB3;
    {
      uint64_t zgaz3331;
      zgaz3331 = zc.zB;
      {
        lbits zgsz3675;
        CREATE(lbits)(&zgsz3675);
        CONVERT_OF(lbits, fbits)(&zgsz3675, zgaz3331, UINT64_C(14) , true);
        sail_int zgsz3676;
        CREATE(sail_int)(&zgsz3676);
        CONVERT_OF(sail_int, mach_int)(&zgsz3676, INT64_C(3));
        lbits zgsz3677;
        CREATE(lbits)(&zgsz3677);
        sail_truncateLSB(&zgsz3677, zgsz3675, zgsz3676);
        zB3 = CONVERT_OF(fbits, lbits)(zgsz3677, true);
        KILL(lbits)(&zgsz3677);
        KILL(sail_int)(&zgsz3676);
        KILL(lbits)(&zgsz3675);
      }
    }
    uint64_t zR3;
    {
      lbits zgsz3702;
      CREATE(lbits)(&zgsz3702);
      CONVERT_OF(lbits, fbits)(&zgsz3702, zB3, UINT64_C(3) , true);
      lbits zgsz3703;
      CREATE(lbits)(&zgsz3703);
      CONVERT_OF(lbits, fbits)(&zgsz3703, UINT64_C(0b001), UINT64_C(3) , true);
      lbits zgsz3704;
      CREATE(lbits)(&zgsz3704);
      sub_bits(&zgsz3704, zgsz3702, zgsz3703);
      zR3 = CONVERT_OF(fbits, lbits)(zgsz3704, true);
      KILL(lbits)(&zgsz3704);
      KILL(lbits)(&zgsz3703);
      KILL(lbits)(&zgsz3702);
    }
    uint64_t zR;
    {
      uint64_t zgaz3330;
      {
        int64_t zgaz3329;
        {
          sail_int zgsz3680;
          CREATE(sail_int)(&zgsz3680);
          CONVERT_OF(sail_int, mach_int)(&zgsz3680, zcap_mantissa_width);
          sail_int zgsz3681;
          CREATE(sail_int)(&zgsz3681);
          CONVERT_OF(sail_int, mach_int)(&zgsz3681, INT64_C(3));
          sail_int zgsz3682;
          CREATE(sail_int)(&zgsz3682);
          sub_int(&zgsz3682, zgsz3680, zgsz3681);
          zgaz3329 = CONVERT_OF(mach_int, sail_int)(zgsz3682);
          KILL(sail_int)(&zgsz3682);
          KILL(sail_int)(&zgsz3681);
          KILL(sail_int)(&zgsz3680);
        }
        {
          sail_int zgsz3678;
          CREATE(sail_int)(&zgsz3678);
          CONVERT_OF(sail_int, mach_int)(&zgsz3678, zgaz3329);
          lbits zgsz3679;
          CREATE(lbits)(&zgsz3679);
          sailgen_zzeros_implicit(&zgsz3679, zgsz3678);
          zgaz3330 = CONVERT_OF(fbits, lbits)(zgsz3679, true);
          KILL(lbits)(&zgsz3679);
          KILL(sail_int)(&zgsz3678);
        }
      }
      {
        lbits zgsz3683;
        CREATE(lbits)(&zgsz3683);
        CONVERT_OF(lbits, fbits)(&zgsz3683, zR3, UINT64_C(3) , true);
        lbits zgsz3684;
        CREATE(lbits)(&zgsz3684);
        CONVERT_OF(lbits, fbits)(&zgsz3684, zgaz3330, UINT64_C(11) , true);
        lbits zgsz3685;
        CREATE(lbits)(&zgsz3685);
        append(&zgsz3685, zgsz3683, zgsz3684);
        zR = CONVERT_OF(fbits, lbits)(zgsz3685, true);
        KILL(lbits)(&zgsz3685);
        KILL(lbits)(&zgsz3684);
        KILL(lbits)(&zgsz3683);
      }
    }
    uint64_t zdiff;
    {
      lbits zgsz3699;
      CREATE(lbits)(&zgsz3699);
      CONVERT_OF(lbits, fbits)(&zgsz3699, zR, UINT64_C(14) , true);
      lbits zgsz3700;
      CREATE(lbits)(&zgsz3700);
      CONVERT_OF(lbits, fbits)(&zgsz3700, za_mid, UINT64_C(14) , true);
      lbits zgsz3701;
      CREATE(lbits)(&zgsz3701);
      sub_bits(&zgsz3701, zgsz3699, zgsz3700);
      zdiff = CONVERT_OF(fbits, lbits)(zgsz3701, true);
      KILL(lbits)(&zgsz3701);
      KILL(lbits)(&zgsz3700);
      KILL(lbits)(&zgsz3699);
    }
    uint64_t zdiff1;
    {
      lbits zgsz3696;
      CREATE(lbits)(&zgsz3696);
      CONVERT_OF(lbits, fbits)(&zgsz3696, zdiff, UINT64_C(14) , true);
      sail_int zgsz3697;
      CREATE(sail_int)(&zgsz3697);
      CONVERT_OF(sail_int, mach_int)(&zgsz3697, INT64_C(1));
      lbits zgsz3698;
      CREATE(lbits)(&zgsz3698);
      sub_bits_int(&zgsz3698, zgsz3696, zgsz3697);
      zdiff1 = CONVERT_OF(fbits, lbits)(zgsz3698, true);
      KILL(lbits)(&zgsz3698);
      KILL(sail_int)(&zgsz3697);
      KILL(lbits)(&zgsz3696);
    }
    bool zgaz3326;
    {
      sail_int zgsz3694;
      CREATE(sail_int)(&zgsz3694);
      CONVERT_OF(sail_int, mach_int)(&zgsz3694, zi_top);
      sail_int zgsz3695;
      CREATE(sail_int)(&zgsz3695);
      CONVERT_OF(sail_int, mach_int)(&zgsz3695, INT64_C(0));
      zgaz3326 = eq_int(zgsz3694, zgsz3695);
      KILL(sail_int)(&zgsz3695);
      KILL(sail_int)(&zgsz3694);
    }
    if (zgaz3326) {
      {
        lbits zgsz3692;
        CREATE(lbits)(&zgsz3692);
        CONVERT_OF(lbits, fbits)(&zgsz3692, zi_mid, UINT64_C(14) , true);
        lbits zgsz3693;
        CREATE(lbits)(&zgsz3693);
        CONVERT_OF(lbits, fbits)(&zgsz3693, zdiff1, UINT64_C(14) , true);
        zcbz339 = sailgen_z8operatorz0zI_uz9(zgsz3692, zgsz3693);
        KILL(lbits)(&zgsz3693);
        KILL(lbits)(&zgsz3692);
      }
    } else {
      bool zgaz3327;
      {
        sail_int zgsz3690;
        CREATE(sail_int)(&zgsz3690);
        CONVERT_OF(sail_int, mach_int)(&zgsz3690, zi_top);
        sail_int zgsz3691;
        CREATE(sail_int)(&zgsz3691);
        CONVERT_OF(sail_int, mach_int)(&zgsz3691, INT64_C(-1));
        zgaz3327 = eq_int(zgsz3690, zgsz3691);
        KILL(sail_int)(&zgsz3691);
        KILL(sail_int)(&zgsz3690);
      }
      if (zgaz3327) {
        bool zgaz3328;
        {
          lbits zgsz3688;
          CREATE(lbits)(&zgsz3688);
          CONVERT_OF(lbits, fbits)(&zgsz3688, zi_mid, UINT64_C(14) , true);
          lbits zgsz3689;
          CREATE(lbits)(&zgsz3689);
          CONVERT_OF(lbits, fbits)(&zgsz3689, zdiff, UINT64_C(14) , true);
          zgaz3328 = sailgen_z8operatorz0zKzJ_uz9(zgsz3688, zgsz3689);
          KILL(lbits)(&zgsz3689);
          KILL(lbits)(&zgsz3688);
        }
        bool zgsz389;
        if (zgaz3328) {
          {
            lbits zgsz3686;
            CREATE(lbits)(&zgsz3686);
            CONVERT_OF(lbits, fbits)(&zgsz3686, zR, UINT64_C(14) , true);
            lbits zgsz3687;
            CREATE(lbits)(&zgsz3687);
            CONVERT_OF(lbits, fbits)(&zgsz3687, za_mid, UINT64_C(14) , true);
            zgsz389 = neq_bits(zgsz3686, zgsz3687);
            KILL(lbits)(&zgsz3687);
            KILL(lbits)(&zgsz3686);
          }
        } else {  zgsz389 = false;  }
        zcbz339 = zgsz389;
      } else {  zcbz339 = false;  }
    }
  }


end_function_165: ;
  return zcbz339;
end_block_exception_166: ;

  return false;
}

static void sailgen_capToString(sail_string *rop, struct zCapability);

static void sailgen_capToString(sail_string *zcbz340, struct zCapability zcap)
{
  __label__ end_function_168, end_block_exception_169, end_function_195;

  sail_int zlen;
  CREATE(sail_int)(&zlen);
  sailgen_getCapLength(&zlen, zcap);
  sail_string zlen_str;
  CREATE(sail_string)(&zlen_str);
  {
    lbits zgaz3366;
    CREATE(lbits)(&zgaz3366);
    {
      int64_t zgaz3365;
      {
        sail_int zgsz3706;
        CREATE(sail_int)(&zgsz3706);
        CONVERT_OF(sail_int, mach_int)(&zgsz3706, zcap_len_width);
        sail_int zgsz3707;
        CREATE(sail_int)(&zgsz3707);
        CONVERT_OF(sail_int, mach_int)(&zgsz3707, INT64_C(3));
        sail_int zgsz3708;
        CREATE(sail_int)(&zgsz3708);
        add_int(&zgsz3708, zgsz3706, zgsz3707);
        zgaz3365 = CONVERT_OF(mach_int, sail_int)(zgsz3708);
        KILL(sail_int)(&zgsz3708);
        KILL(sail_int)(&zgsz3707);
        KILL(sail_int)(&zgsz3706);
      }
      {
        sail_int zgsz3705;
        CREATE(sail_int)(&zgsz3705);
        CONVERT_OF(sail_int, mach_int)(&zgsz3705, zgaz3365);
        sailgen_to_bits(&zgaz3366, zgsz3705, zlen);
        KILL(sail_int)(&zgsz3705);
      }
    }
    string_of_lbits(&zlen_str, zgaz3366);
    KILL(lbits)(&zgaz3366);
  }
  uint64_t zotype64;
  {
    bool zgaz3362;
    zgaz3362 = sailgen_hasReservedOType(zcap);
    if (zgaz3362) {
      uint64_t zgaz3363;
      zgaz3363 = zcap.zotype;
      {
        sail_int zgsz3712;
        CREATE(sail_int)(&zgsz3712);
        CONVERT_OF(sail_int, mach_int)(&zgsz3712, INT64_C(64));
        lbits zgsz3713;
        CREATE(lbits)(&zgsz3713);
        CONVERT_OF(lbits, fbits)(&zgsz3713, zgaz3363, UINT64_C(18) , true);
        lbits zgsz3714;
        CREATE(lbits)(&zgsz3714);
        sailgen_EXTS(&zgsz3714, zgsz3712, zgsz3713);
        zotype64 = CONVERT_OF(fbits, lbits)(zgsz3714, true);
        KILL(lbits)(&zgsz3714);
        KILL(lbits)(&zgsz3713);
        KILL(sail_int)(&zgsz3712);
      }
    } else {
      uint64_t zgaz3364;
      zgaz3364 = zcap.zotype;
      {
        sail_int zgsz3709;
        CREATE(sail_int)(&zgsz3709);
        CONVERT_OF(sail_int, mach_int)(&zgsz3709, INT64_C(64));
        lbits zgsz3710;
        CREATE(lbits)(&zgsz3710);
        CONVERT_OF(lbits, fbits)(&zgsz3710, zgaz3364, UINT64_C(18) , true);
        lbits zgsz3711;
        CREATE(lbits)(&zgsz3711);
        sailgen_EXTZ(&zgsz3711, zgsz3709, zgsz3710);
        zotype64 = CONVERT_OF(fbits, lbits)(zgsz3711, true);
        KILL(lbits)(&zgsz3711);
        KILL(lbits)(&zgsz3710);
        KILL(sail_int)(&zgsz3709);
      }
    }
  }
  sail_string zgaz3361;
  CREATE(sail_string)(&zgaz3361);
  {
    sail_string zgaz3359;
    CREATE(sail_string)(&zgaz3359);
    {
      bool zgaz3338;
      zgaz3338 = zcap.ztag;
      if (zgaz3338) {  COPY(sail_string)(&zgaz3359, "1");  } else {  COPY(sail_string)(&zgaz3359, "0");  }
    }
    sail_string zgaz3360;
    CREATE(sail_string)(&zgaz3360);
    {
      sail_string zgaz3358;
      CREATE(sail_string)(&zgaz3358);
      {
        sail_string zgaz3356;
        CREATE(sail_string)(&zgaz3356);
        {
          bool zgaz3339;
          zgaz3339 = sailgen_isCapSealed(zcap);
          if (zgaz3339) {  COPY(sail_string)(&zgaz3356, "1");  } else {  COPY(sail_string)(&zgaz3356, "0");  }
        }
        sail_string zgaz3357;
        CREATE(sail_string)(&zgaz3357);
        {
          sail_string zgaz3355;
          CREATE(sail_string)(&zgaz3355);
          {
            sail_string zgaz3353;
            CREATE(sail_string)(&zgaz3353);
            {
              uint64_t zgaz3341;
              {
                uint64_t zgaz3340;
                zgaz3340 = sailgen_getCapPerms(zcap);
                {
                  lbits zgsz3715;
                  CREATE(lbits)(&zgsz3715);
                  CONVERT_OF(lbits, fbits)(&zgsz3715, UINT64_C(0b0), UINT64_C(1) , true);
                  lbits zgsz3716;
                  CREATE(lbits)(&zgsz3716);
                  CONVERT_OF(lbits, fbits)(&zgsz3716, zgaz3340, UINT64_C(19) , true);
                  lbits zgsz3717;
                  CREATE(lbits)(&zgsz3717);
                  append(&zgsz3717, zgsz3715, zgsz3716);
                  zgaz3341 = CONVERT_OF(fbits, lbits)(zgsz3717, true);
                  KILL(lbits)(&zgsz3717);
                  KILL(lbits)(&zgsz3716);
                  KILL(lbits)(&zgsz3715);
                }
              }
              {
                lbits zgsz3718;
                CREATE(lbits)(&zgsz3718);
                CONVERT_OF(lbits, fbits)(&zgsz3718, zgaz3341, UINT64_C(20) , true);
                string_of_lbits(&zgaz3353, zgsz3718);
                KILL(lbits)(&zgsz3718);
              }
            }
            sail_string zgaz3354;
            CREATE(sail_string)(&zgaz3354);
            {
              sail_string zgaz3352;
              CREATE(sail_string)(&zgaz3352);
              {
                sail_string zgaz3350;
                CREATE(sail_string)(&zgaz3350);
                {
                  lbits zgsz3721;
                  CREATE(lbits)(&zgsz3721);
                  CONVERT_OF(lbits, fbits)(&zgsz3721, zotype64, UINT64_C(64) , true);
                  string_of_lbits(&zgaz3350, zgsz3721);
                  KILL(lbits)(&zgsz3721);
                }
                sail_string zgaz3351;
                CREATE(sail_string)(&zgaz3351);
                {
                  sail_string zgaz3349;
                  CREATE(sail_string)(&zgaz3349);
                  {
                    sail_string zgaz3347;
                    CREATE(sail_string)(&zgaz3347);
                    {
                      uint64_t zgaz3342;
                      zgaz3342 = zcap.zaddress;
                      {
                        lbits zgsz3719;
                        CREATE(lbits)(&zgsz3719);
                        CONVERT_OF(lbits, fbits)(&zgsz3719, zgaz3342, UINT64_C(64) , true);
                        string_of_lbits(&zgaz3347, zgsz3719);
                        KILL(lbits)(&zgsz3719);
                      }
                    }
                    sail_string zgaz3348;
                    CREATE(sail_string)(&zgaz3348);
                    {
                      sail_string zgaz3346;
                      CREATE(sail_string)(&zgaz3346);
                      {
                        sail_string zgaz3344;
                        CREATE(sail_string)(&zgaz3344);
                        {
                          uint64_t zgaz3343;
                          zgaz3343 = sailgen_getCapBaseBits(zcap);
                          {
                            lbits zgsz3720;
                            CREATE(lbits)(&zgsz3720);
                            CONVERT_OF(lbits, fbits)(&zgsz3720, zgaz3343, UINT64_C(64) , true);
                            string_of_lbits(&zgaz3344, zgsz3720);
                            KILL(lbits)(&zgsz3720);
                          }
                        }
                        sail_string zgaz3345;
                        CREATE(sail_string)(&zgaz3345);
                        concat_str(&zgaz3345, " length:", zlen_str);
                        concat_str(&zgaz3346, zgaz3344, zgaz3345);
                        KILL(sail_string)(&zgaz3345);
                        KILL(sail_string)(&zgaz3344);
                      }
                      concat_str(&zgaz3348, " base:", zgaz3346);
                      KILL(sail_string)(&zgaz3346);
                    }
                    concat_str(&zgaz3349, zgaz3347, zgaz3348);
                    KILL(sail_string)(&zgaz3348);
                    KILL(sail_string)(&zgaz3347);
                  }
                  concat_str(&zgaz3351, " address:", zgaz3349);
                  KILL(sail_string)(&zgaz3349);
                }
                concat_str(&zgaz3352, zgaz3350, zgaz3351);
                KILL(sail_string)(&zgaz3351);
                KILL(sail_string)(&zgaz3350);
              }
              concat_str(&zgaz3354, " type:", zgaz3352);
              KILL(sail_string)(&zgaz3352);
            }
            concat_str(&zgaz3355, zgaz3353, zgaz3354);
            KILL(sail_string)(&zgaz3354);
            KILL(sail_string)(&zgaz3353);
          }
          concat_str(&zgaz3357, " perms:", zgaz3355);
          KILL(sail_string)(&zgaz3355);
        }
        concat_str(&zgaz3358, zgaz3356, zgaz3357);
        KILL(sail_string)(&zgaz3357);
        KILL(sail_string)(&zgaz3356);
      }
      concat_str(&zgaz3360, " s:", zgaz3358);
      KILL(sail_string)(&zgaz3358);
    }
    concat_str(&zgaz3361, zgaz3359, zgaz3360);
    KILL(sail_string)(&zgaz3360);
    KILL(sail_string)(&zgaz3359);
  }
  concat_str((*(&zcbz340)), " t:", zgaz3361);
  KILL(sail_string)(&zgaz3361);

  KILL(sail_string)(&zlen_str);
  KILL(sail_int)(&zlen);
end_function_168: ;
  goto end_function_195;
end_block_exception_169: ;
  goto end_function_195;
end_function_195: ;
}

static uint64_t sailgen_getRepresentableAlignmentMask(uint64_t);

static uint64_t sailgen_getRepresentableAlignmentMask(uint64_t zlen)
{
  __label__ case_172, finish_match_171, end_function_173, end_block_exception_174;

  uint64_t zcbz341;
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgaz3369;
  {
    uint64_t zgaz3367;
    {
      sail_int zgsz3724;
      CREATE(sail_int)(&zgsz3724);
      CONVERT_OF(sail_int, mach_int)(&zgsz3724, INT64_C(64));
      sail_int zgsz3725;
      CREATE(sail_int)(&zgsz3725);
      CONVERT_OF(sail_int, mach_int)(&zgsz3725, INT64_C(0));
      lbits zgsz3726;
      CREATE(lbits)(&zgsz3726);
      sailgen_to_bits(&zgsz3726, zgsz3724, zgsz3725);
      zgaz3367 = CONVERT_OF(fbits, lbits)(zgsz3726, true);
      KILL(lbits)(&zgsz3726);
      KILL(sail_int)(&zgsz3725);
      KILL(sail_int)(&zgsz3724);
    }
    lbits zgaz3368;
    CREATE(lbits)(&zgaz3368);
    {
      lbits zgsz3722;
      CREATE(lbits)(&zgsz3722);
      CONVERT_OF(lbits, fbits)(&zgsz3722, UINT64_C(0b0), UINT64_C(1) , true);
      lbits zgsz3723;
      CREATE(lbits)(&zgsz3723);
      CONVERT_OF(lbits, fbits)(&zgsz3723, zlen, UINT64_C(64) , true);
      append(&zgaz3368, zgsz3722, zgsz3723);
      KILL(lbits)(&zgsz3723);
      KILL(lbits)(&zgsz3722);
    }
    zgaz3369 = sailgen_setCapBounds(zdefault_cap, zgaz3367, zgaz3368);
    KILL(lbits)(&zgaz3368);
  }
  uint64_t zgsz390;
  {
    bool zexact;
    zexact = zgaz3369.ztup0;
    struct zCapability zc;
    zc = zgaz3369.ztup1;
    int64_t ze;
    {
      int64_t zgaz3375;
      {
        uint64_t zgaz3374;
        zgaz3374 = zc.zE;
        {
          lbits zgsz3727;
          CREATE(lbits)(&zgsz3727);
          CONVERT_OF(lbits, fbits)(&zgsz3727, zgaz3374, UINT64_C(6) , true);
          sail_int zgsz3728;
          CREATE(sail_int)(&zgsz3728);
          sail_unsigned(&zgsz3728, zgsz3727);
          zgaz3375 = CONVERT_OF(mach_int, sail_int)(zgsz3728);
          KILL(sail_int)(&zgsz3728);
          KILL(lbits)(&zgsz3727);
        }
      }
      {
        sail_int zgsz3729;
        CREATE(sail_int)(&zgsz3729);
        CONVERT_OF(sail_int, mach_int)(&zgsz3729, zgaz3375);
        sail_int zgsz3730;
        CREATE(sail_int)(&zgsz3730);
        CONVERT_OF(sail_int, mach_int)(&zgsz3730, zcap_max_E);
        sail_int zgsz3731;
        CREATE(sail_int)(&zgsz3731);
        min_int(&zgsz3731, zgsz3729, zgsz3730);
        ze = CONVERT_OF(mach_int, sail_int)(zgsz3731);
        KILL(sail_int)(&zgsz3731);
        KILL(sail_int)(&zgsz3730);
        KILL(sail_int)(&zgsz3729);
      }
    }
    int64_t zez7;
    {
      bool zgaz3373;
      zgaz3373 = zc.zinternal_E;
      if (zgaz3373) {
        {
          sail_int zgsz3732;
          CREATE(sail_int)(&zgsz3732);
          CONVERT_OF(sail_int, mach_int)(&zgsz3732, ze);
          sail_int zgsz3733;
          CREATE(sail_int)(&zgsz3733);
          CONVERT_OF(sail_int, mach_int)(&zgsz3733, zinternal_E_take_bits);
          sail_int zgsz3734;
          CREATE(sail_int)(&zgsz3734);
          add_int(&zgsz3734, zgsz3732, zgsz3733);
          zez7 = CONVERT_OF(mach_int, sail_int)(zgsz3734);
          KILL(sail_int)(&zgsz3734);
          KILL(sail_int)(&zgsz3733);
          KILL(sail_int)(&zgsz3732);
        }
      } else {  zez7 = INT64_C(0);  }
    }
    sbits zgaz3371;
    {
      int64_t zgaz3370;
      {
        sail_int zgsz3737;
        CREATE(sail_int)(&zgsz3737);
        CONVERT_OF(sail_int, mach_int)(&zgsz3737, INT64_C(64));
        sail_int zgsz3738;
        CREATE(sail_int)(&zgsz3738);
        CONVERT_OF(sail_int, mach_int)(&zgsz3738, zez7);
        sail_int zgsz3739;
        CREATE(sail_int)(&zgsz3739);
        sub_int(&zgsz3739, zgsz3737, zgsz3738);
        zgaz3370 = CONVERT_OF(mach_int, sail_int)(zgsz3739);
        KILL(sail_int)(&zgsz3739);
        KILL(sail_int)(&zgsz3738);
        KILL(sail_int)(&zgsz3737);
      }
      {
        sail_int zgsz3735;
        CREATE(sail_int)(&zgsz3735);
        CONVERT_OF(sail_int, mach_int)(&zgsz3735, zgaz3370);
        lbits zgsz3736;
        CREATE(lbits)(&zgsz3736);
        sailgen_ones(&zgsz3736, zgsz3735);
        zgaz3371 = CONVERT_OF(sbits, lbits)(zgsz3736, true);
        KILL(lbits)(&zgsz3736);
        KILL(sail_int)(&zgsz3735);
      }
    }
    sbits zgaz3372;
    {
      sail_int zgsz3743;
      CREATE(sail_int)(&zgsz3743);
      CONVERT_OF(sail_int, mach_int)(&zgsz3743, zez7);
      lbits zgsz3744;
      CREATE(lbits)(&zgsz3744);
      sailgen_zzeros_implicit(&zgsz3744, zgsz3743);
      zgaz3372 = CONVERT_OF(sbits, lbits)(zgsz3744, true);
      KILL(lbits)(&zgsz3744);
      KILL(sail_int)(&zgsz3743);
    }
    {
      lbits zgsz3740;
      CREATE(lbits)(&zgsz3740);
      CONVERT_OF(lbits, sbits)(&zgsz3740, zgaz3371, true);
      lbits zgsz3741;
      CREATE(lbits)(&zgsz3741);
      CONVERT_OF(lbits, sbits)(&zgsz3741, zgaz3372, true);
      lbits zgsz3742;
      CREATE(lbits)(&zgsz3742);
      append(&zgsz3742, zgsz3740, zgsz3741);
      zgsz390 = CONVERT_OF(fbits, lbits)(zgsz3742, true);
      KILL(lbits)(&zgsz3742);
      KILL(lbits)(&zgsz3741);
      KILL(lbits)(&zgsz3740);
    }
    goto finish_match_171;
  }
case_172: ;
  sail_match_failure("getRepresentableAlignmentMask");
finish_match_171: ;
  zcbz341 = zgsz390;


end_function_173: ;
  return zcbz341;
end_block_exception_174: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_getRepresentableLength(uint64_t);

static uint64_t sailgen_getRepresentableLength(uint64_t zlen)
{
  __label__ end_function_176, end_block_exception_177;

  uint64_t zcbz342;
  uint64_t zm;
  zm = sailgen_getRepresentableAlignmentMask(zlen);
  uint64_t zgaz3377;
  {
    uint64_t zgaz3376;
    {
      lbits zgsz3748;
      CREATE(lbits)(&zgsz3748);
      CONVERT_OF(lbits, fbits)(&zgsz3748, zm, UINT64_C(64) , true);
      lbits zgsz3749;
      CREATE(lbits)(&zgsz3749);
      not_bits(&zgsz3749, zgsz3748);
      zgaz3376 = CONVERT_OF(fbits, lbits)(zgsz3749, true);
      KILL(lbits)(&zgsz3749);
      KILL(lbits)(&zgsz3748);
    }
    {
      lbits zgsz3745;
      CREATE(lbits)(&zgsz3745);
      CONVERT_OF(lbits, fbits)(&zgsz3745, zlen, UINT64_C(64) , true);
      lbits zgsz3746;
      CREATE(lbits)(&zgsz3746);
      CONVERT_OF(lbits, fbits)(&zgsz3746, zgaz3376, UINT64_C(64) , true);
      lbits zgsz3747;
      CREATE(lbits)(&zgsz3747);
      add_bits(&zgsz3747, zgsz3745, zgsz3746);
      zgaz3377 = CONVERT_OF(fbits, lbits)(zgsz3747, true);
      KILL(lbits)(&zgsz3747);
      KILL(lbits)(&zgsz3746);
      KILL(lbits)(&zgsz3745);
    }
  }
  {
    lbits zgsz3750;
    CREATE(lbits)(&zgsz3750);
    CONVERT_OF(lbits, fbits)(&zgsz3750, zgaz3377, UINT64_C(64) , true);
    lbits zgsz3751;
    CREATE(lbits)(&zgsz3751);
    CONVERT_OF(lbits, fbits)(&zgsz3751, zm, UINT64_C(64) , true);
    lbits zgsz3752;
    CREATE(lbits)(&zgsz3752);
    and_bits(&zgsz3752, zgsz3750, zgsz3751);
    zcbz342 = CONVERT_OF(fbits, lbits)(zgsz3752, true);
    KILL(lbits)(&zgsz3752);
    KILL(lbits)(&zgsz3751);
    KILL(lbits)(&zgsz3750);
  }


end_function_176: ;
  return zcbz342;
end_block_exception_177: ;

  return UINT64_C(0xdeadc0de);
}

// register TestCap
static struct zCapability zTestCap;

// register TestAddr
static uint64_t zTestAddr;

// register TestLen
static lbits zTestLen;

static struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 sailgen_doCSetBounds(struct zCapability, lbits);

static struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 sailgen_doCSetBounds(struct zCapability zinput, lbits zreq_len)
{
  __label__ case_180, finish_match_179, end_function_181, end_block_exception_182;

  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz343;
  uint64_t znewBase;
  znewBase = zinput.zaddress;
  lbits znewTop;
  CREATE(lbits)(&znewTop);
  {
    lbits zgaz3382;
    CREATE(lbits)(&zgaz3382);
    {
      sail_int zgsz3753;
      CREATE(sail_int)(&zgsz3753);
      CONVERT_OF(sail_int, mach_int)(&zgsz3753, INT64_C(65));
      lbits zgsz3754;
      CREATE(lbits)(&zgsz3754);
      CONVERT_OF(lbits, fbits)(&zgsz3754, znewBase, UINT64_C(64) , true);
      sailgen_EXTZ(&zgaz3382, zgsz3753, zgsz3754);
      KILL(lbits)(&zgsz3754);
      KILL(sail_int)(&zgsz3753);
    }
    add_bits(&znewTop, zgaz3382, zreq_len);
    KILL(lbits)(&zgaz3382);
  }
  bool zinBounds;
  {
    sail_int zgaz3381;
    CREATE(sail_int)(&zgaz3381);
    sail_unsigned(&zgaz3381, zreq_len);
    zinBounds = sailgen_inCapBounds(zinput, znewBase, zgaz3381);
    KILL(sail_int)(&zgaz3381);
  }
  struct zCapability zinCap;
  zinCap = sailgen_clearTagIfSealed(zinput);
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgaz3378;
  zgaz3378 = sailgen_setCapBounds(zinCap, znewBase, znewTop);
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgsz392;
  {
    bool zexact;
    zexact = zgaz3378.ztup0;
    struct zCapability znewCap;
    znewCap = zgaz3378.ztup1;
    struct zCapability zgaz3380;
    {
      bool zgaz3379;
      zgaz3379 = not(zinBounds);
      zgaz3380 = sailgen_clearTagIf(znewCap, zgaz3379);
    }
    struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgsz393;
    zgsz393.ztup0 = zexact;
    zgsz393.ztup1 = zgaz3380;
    zgsz392 = zgsz393;
    goto finish_match_179;
  }
case_180: ;
  sail_match_failure("doCSetBounds");
finish_match_179: ;
  zcbz343 = zgsz392;




  KILL(lbits)(&znewTop);

end_function_181: ;
  return zcbz343;
end_block_exception_182: ;
  struct zCapability zcbz360 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz359 = { .ztup0 = false, .ztup1 = zcbz360 };
  return zcbz359;
}

static unit sailgen_main(unit);


static unit sailgen_main(unit zgsz395)
{
  __label__ case_185, finish_match_184, end_function_190, end_block_exception_191;

  unit zcbz344;
  {
    zTestCap = znull_cap;
    unit zgsz396;
    zgsz396 = UNIT;
  }
  lbits zbits1;
  CREATE(lbits)(&zbits1);
  sailgen_capToBits(&zbits1, zTestCap);
  lbits zbits2;
  CREATE(lbits)(&zbits2);
  sailgen_capToMemBits(&zbits2, zTestCap);
  struct zCapability zcap1;
  {
    bool zgaz3388;
    zgaz3388 = zTestCap.ztag;
    zcap1 = sailgen_capBitsToCapability(zgaz3388, zbits1);
  }
  struct zCapability zcap2;
  {
    bool zgaz3387;
    zgaz3387 = zTestCap.ztag;
    zcap2 = sailgen_memBitsToCapability(zgaz3387, zbits2);
  }
  bool zrep;
  zrep = sailgen_fastRepCheck(zTestCap, zTestAddr);
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgaz3383;
  zgaz3383 = sailgen_doCSetBounds(zTestCap, zTestLen);
  unit zgsz397;
  {
    __label__ case_187, finish_match_186;

    bool zexact;
    zexact = zgaz3383.ztup0;
    struct zCapability zcap;
    zcap = zgaz3383.ztup1;
    struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgaz3384;
    zgaz3384 = sailgen_setCapAddr(zTestCap, zTestAddr);
    unit zgsz398;
    {
      __label__ case_189, finish_match_188;

      bool zrepresentable;
      zrepresentable = zgaz3384.ztup0;
      struct zCapability zcapshadowz30;
      zcapshadowz30 = zgaz3384.ztup1;
      struct ztuple_z8z5izCz0z5iz9 zgaz3385;
      CREATE(ztuple_z8z5izCz0z5iz9)(&zgaz3385);
      sailgen_getCapBounds(&zgaz3385, zTestCap);
      unit zgsz399;
      {
        sail_int zbase;
        CREATE(sail_int)(&zbase);
        COPY(sail_int)(&zbase, zgaz3385.ztup0);
        sail_int ztop;
        CREATE(sail_int)(&ztop);
        COPY(sail_int)(&ztop, zgaz3385.ztup1);
        uint64_t zflags;
        zflags = sailgen_getCapFlags(zTestCap);
        struct zCapability znew_cap;
        {
          uint64_t zgaz3386;
          {
            sail_int zgsz3755;
            CREATE(sail_int)(&zgsz3755);
            CONVERT_OF(sail_int, mach_int)(&zgsz3755, INT64_C(19));
            lbits zgsz3756;
            CREATE(lbits)(&zgsz3756);
            sailgen_ones(&zgsz3756, zgsz3755);
            zgaz3386 = CONVERT_OF(fbits, lbits)(zgsz3756, true);
            KILL(lbits)(&zgsz3756);
            KILL(sail_int)(&zgsz3755);
          }
          znew_cap = sailgen_setCapPerms(zTestCap, zgaz3386);
        }
        sail_string zcap_str;
        CREATE(sail_string)(&zcap_str);
        sailgen_capToString(&zcap_str, zTestCap);
        uint64_t zlen;
        zlen = sailgen_getRepresentableLength(zTestAddr);
        uint64_t zmask;
        zmask = sailgen_getRepresentableAlignmentMask(zTestAddr);
        zgsz399 = UNIT;
        KILL(sail_string)(&zcap_str);
        KILL(sail_int)(&ztop);
        KILL(sail_int)(&zbase);
        goto finish_match_188;
      }
    case_189: ;
      sail_match_failure("main");
    finish_match_188: ;
      zgsz398 = zgsz399;
      KILL(ztuple_z8z5izCz0z5iz9)(&zgaz3385);
      goto finish_match_186;
    }
  case_187: ;
    sail_match_failure("main");
  finish_match_186: ;
    zgsz397 = zgsz398;
    goto finish_match_184;
  }
case_185: ;
  sail_match_failure("main");
finish_match_184: ;
  zcbz344 = zgsz397;





  KILL(lbits)(&zbits2);
  KILL(lbits)(&zbits1);
end_function_190: ;
  return zcbz344;
end_block_exception_191: ;

  return UNIT;
}

static unit sailgen_initializze_registers(unit);

static unit sailgen_initializze_registers(unit zgsz3103)
{
  __label__ end_function_193, end_block_exception_194;

  unit zcbz345;
  {
    zTestCap = sailgen_undefined_Capability(UNIT);
    unit zgsz3105;
    zgsz3105 = UNIT;
  }
  {
    {
      sail_int zgsz3757;
      CREATE(sail_int)(&zgsz3757);
      CONVERT_OF(sail_int, mach_int)(&zgsz3757, INT64_C(64));
      lbits zgsz3758;
      CREATE(lbits)(&zgsz3758);
      UNDEFINED(lbits)(&zgsz3758, zgsz3757);
      zTestAddr = CONVERT_OF(fbits, lbits)(zgsz3758, true);
      KILL(lbits)(&zgsz3758);
      KILL(sail_int)(&zgsz3757);
    }
    unit zgsz3104;
    zgsz3104 = UNIT;
  }
  {
    sail_int zgsz3759;
    CREATE(sail_int)(&zgsz3759);
    CONVERT_OF(sail_int, mach_int)(&zgsz3759, INT64_C(65));
    UNDEFINED(lbits)(&zTestLen, zgsz3759);
    KILL(sail_int)(&zgsz3759);
  }
  zcbz345 = UNIT;
end_function_193: ;
  return zcbz345;
end_block_exception_194: ;

  return UNIT;
}

static void model_init(void)
{
  setup_rts();
  current_exception = sail_new(struct zexception);
  CREATE(zexception)(current_exception);
  throw_location = sail_new(sail_string);
  CREATE(sail_string)(throw_location);
  create_letbind_0();
  create_letbind_1();
  create_letbind_2();
  create_letbind_3();
  create_letbind_4();
  create_letbind_5();
  create_letbind_6();
  create_letbind_7();
  create_letbind_8();
  create_letbind_9();
  create_letbind_10();
  create_letbind_11();
  create_letbind_12();
  create_letbind_13();
  create_letbind_14();
  create_letbind_15();
  create_letbind_16();
  create_letbind_17();
  create_letbind_18();
  create_letbind_19();
  create_letbind_20();
  create_letbind_21();
  create_letbind_22();
  create_letbind_23();
  create_letbind_24();
  create_letbind_25();
  create_letbind_26();
  create_letbind_27();
  CREATE(lbits)(&zTestLen);
  sailgen_initializze_registers(UNIT);
}

static void model_fini(void)
{
  kill_letbind_27();
  kill_letbind_26();
  kill_letbind_25();
  kill_letbind_24();
  kill_letbind_23();
  kill_letbind_22();
  kill_letbind_21();
  kill_letbind_20();
  kill_letbind_19();
  kill_letbind_18();
  kill_letbind_17();
  kill_letbind_16();
  kill_letbind_15();
  kill_letbind_14();
  kill_letbind_13();
  kill_letbind_12();
  kill_letbind_11();
  kill_letbind_10();
  kill_letbind_9();
  kill_letbind_8();
  kill_letbind_7();
  kill_letbind_6();
  kill_letbind_5();
  kill_letbind_4();
  kill_letbind_3();
  kill_letbind_2();
  kill_letbind_1();
  kill_letbind_0();
  KILL(lbits)(&zTestLen);
  cleanup_rts();
  if (have_exception) {fprintf(stderr, "Exiting due to uncaught exception: %s\n", *throw_location);}
  KILL(zexception)(current_exception);
  sail_free(current_exception);
  KILL(sail_string)(throw_location);
  sail_free(throw_location);
  if (have_exception) {exit(EXIT_FAILURE);}
}

void model_pre_exit()
{
}

static int model_main(int argc, char *argv[])
{
  model_init();
  if (process_arguments(argc, argv)) exit(EXIT_FAILURE);
  sailgen_main(UNIT);
  model_fini();
  model_pre_exit();
  return EXIT_SUCCESS;
}



#ifdef __cplusplus
}
#endif
