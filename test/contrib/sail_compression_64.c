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
  __label__ end_function_7, end_block_exception_8, end_function_202;

  lbits zgaz32;
  CREATE(lbits)(&zgaz32);
  zeros(&zgaz32, zn);
  not_bits((*(&zcbz32)), zgaz32);
  KILL(lbits)(&zgaz32);
end_function_7: ;
  goto end_function_202;
end_block_exception_8: ;
  goto end_function_202;
end_function_202: ;
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
  __label__ end_function_13, end_block_exception_14, end_function_201;

  sign_extend((*(&zcbz34)), zv, zm);
end_function_13: ;
  goto end_function_201;
end_block_exception_14: ;
  goto end_function_201;
end_function_201: ;
}

static void sailgen_EXTZ(lbits *zcbz35, sail_int zm, lbits zv)
{
  __label__ end_function_16, end_block_exception_17, end_function_200;

  zero_extend((*(&zcbz35)), zv, zm);
end_function_16: ;
  goto end_function_200;
end_block_exception_17: ;
  goto end_function_200;
end_function_200: ;
}

static void sailgen_zzeros_implicit(lbits *rop, sail_int);

static void sailgen_zzeros_implicit(lbits *zcbz36, sail_int zn)
{
  __label__ end_function_19, end_block_exception_20, end_function_199;

  zeros((*(&zcbz36)), zn);
end_function_19: ;
  goto end_function_199;
end_block_exception_20: ;
  goto end_function_199;
end_function_199: ;
}

static void sailgen_ones(lbits *rop, sail_int);

static void sailgen_ones(lbits *zcbz37, sail_int zn)
{
  __label__ end_function_22, end_block_exception_23, end_function_198;

  sailgen_sail_ones((*(&zcbz37)), zn);
end_function_22: ;
  goto end_function_198;
end_block_exception_23: ;
  goto end_function_198;
end_function_198: ;
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
  __label__ end_function_34, end_block_exception_35, end_function_197;

  {
    sail_int zgsz3106;
    CREATE(sail_int)(&zgsz3106);
    CONVERT_OF(sail_int, mach_int)(&zgsz3106, INT64_C(0));
    get_slice_int((*(&zcbz310)), zl, zn, zgsz3106);
    KILL(sail_int)(&zgsz3106);
  }
end_function_34: ;
  goto end_function_197;
end_block_exception_35: ;
  goto end_function_197;
end_function_197: ;
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
  __label__ end_function_43, end_block_exception_44, end_function_196;

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
  goto end_function_196;
end_block_exception_44: ;
  goto end_function_196;
end_function_196: ;
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
  zgsz38 = INT64_C(8);
  zcap_sizze = zgsz38;

let_end_50: ;
}
static void kill_letbind_5(void) {
}

static int64_t zlog2_cap_sizze;
static void create_letbind_6(void) {


  int64_t zgsz39;
  zgsz39 = INT64_C(3);
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
  zgsz311 = INT64_C(0);
  zcap_uperms_width = zgsz311;

let_end_53: ;
}
static void kill_letbind_8(void) {
}

static int64_t zcap_otype_width;
static void create_letbind_9(void) {


  int64_t zgsz312;
  zgsz312 = INT64_C(4);
  zcap_otype_width = zgsz312;

let_end_54: ;
}
static void kill_letbind_9(void) {
}

static int64_t zcap_reserved_width;
static void create_letbind_10(void) {


  int64_t zgsz313;
  zgsz313 = INT64_C(0);
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
  zgsz315 = INT64_C(8);
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
  zgsz317 = INT64_C(32);
  zcap_addr_width = zgsz317;

let_end_59: ;
}
static void kill_letbind_14(void) {
}

static int64_t zcap_len_width;
static void create_letbind_15(void) {


  int64_t zgsz318;
  zgsz318 = INT64_C(33);
  zcap_len_width = zgsz318;

let_end_60: ;
}
static void kill_letbind_15(void) {
}

static int64_t zcaps_per_cache_line;
static void create_letbind_16(void) {


  int64_t zgsz319;
  zgsz319 = INT64_C(8);
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

static struct zEncCapability sailgen_capBitsToEncCapability(uint64_t);

static struct zEncCapability sailgen_capBitsToEncCapability(uint64_t zc)
{
  __label__ end_function_64, end_block_exception_65;

  struct zEncCapability zcbz314;
  uint64_t zgaz39;
  {
    lbits zgsz3130;
    CREATE(lbits)(&zgsz3130);
    CONVERT_OF(lbits, fbits)(&zgsz3130, zc, UINT64_C(64) , true);
    sail_int zgsz3131;
    CREATE(sail_int)(&zgsz3131);
    CONVERT_OF(sail_int, mach_int)(&zgsz3131, INT64_C(63));
    sail_int zgsz3132;
    CREATE(sail_int)(&zgsz3132);
    CONVERT_OF(sail_int, mach_int)(&zgsz3132, INT64_C(52));
    lbits zgsz3133;
    CREATE(lbits)(&zgsz3133);
    vector_subrange_lbits(&zgsz3133, zgsz3130, zgsz3131, zgsz3132);
    zgaz39 = CONVERT_OF(fbits, lbits)(zgsz3133, true);
    KILL(lbits)(&zgsz3133);
    KILL(sail_int)(&zgsz3132);
    KILL(sail_int)(&zgsz3131);
    KILL(lbits)(&zgsz3130);
  }
  uint64_t zgaz310;
  {
    lbits zgsz3126;
    CREATE(lbits)(&zgsz3126);
    CONVERT_OF(lbits, fbits)(&zgsz3126, zc, UINT64_C(64) , true);
    sail_int zgsz3127;
    CREATE(sail_int)(&zgsz3127);
    CONVERT_OF(sail_int, mach_int)(&zgsz3127, INT64_C(51));
    sail_int zgsz3128;
    CREATE(sail_int)(&zgsz3128);
    CONVERT_OF(sail_int, mach_int)(&zgsz3128, INT64_C(51));
    lbits zgsz3129;
    CREATE(lbits)(&zgsz3129);
    vector_subrange_lbits(&zgsz3129, zgsz3126, zgsz3127, zgsz3128);
    zgaz310 = CONVERT_OF(fbits, lbits)(zgsz3129, true);
    KILL(lbits)(&zgsz3129);
    KILL(sail_int)(&zgsz3128);
    KILL(sail_int)(&zgsz3127);
    KILL(lbits)(&zgsz3126);
  }
  uint64_t zgaz311;
  {
    lbits zgsz3122;
    CREATE(lbits)(&zgsz3122);
    CONVERT_OF(lbits, fbits)(&zgsz3122, zc, UINT64_C(64) , true);
    sail_int zgsz3123;
    CREATE(sail_int)(&zgsz3123);
    CONVERT_OF(sail_int, mach_int)(&zgsz3123, INT64_C(50));
    sail_int zgsz3124;
    CREATE(sail_int)(&zgsz3124);
    CONVERT_OF(sail_int, mach_int)(&zgsz3124, INT64_C(47));
    lbits zgsz3125;
    CREATE(lbits)(&zgsz3125);
    vector_subrange_lbits(&zgsz3125, zgsz3122, zgsz3123, zgsz3124);
    zgaz311 = CONVERT_OF(fbits, lbits)(zgsz3125, true);
    KILL(lbits)(&zgsz3125);
    KILL(sail_int)(&zgsz3124);
    KILL(sail_int)(&zgsz3123);
    KILL(lbits)(&zgsz3122);
  }
  fbits zgaz312;
  {
    lbits zgsz3120;
    CREATE(lbits)(&zgsz3120);
    CONVERT_OF(lbits, fbits)(&zgsz3120, zc, UINT64_C(64) , true);
    sail_int zgsz3121;
    CREATE(sail_int)(&zgsz3121);
    CONVERT_OF(sail_int, mach_int)(&zgsz3121, INT64_C(46));
    zgaz312 = bitvector_access(zgsz3120, zgsz3121);
    KILL(sail_int)(&zgsz3121);
    KILL(lbits)(&zgsz3120);
  }
  uint64_t zgaz313;
  {
    lbits zgsz3116;
    CREATE(lbits)(&zgsz3116);
    CONVERT_OF(lbits, fbits)(&zgsz3116, zc, UINT64_C(64) , true);
    sail_int zgsz3117;
    CREATE(sail_int)(&zgsz3117);
    CONVERT_OF(sail_int, mach_int)(&zgsz3117, INT64_C(45));
    sail_int zgsz3118;
    CREATE(sail_int)(&zgsz3118);
    CONVERT_OF(sail_int, mach_int)(&zgsz3118, INT64_C(40));
    lbits zgsz3119;
    CREATE(lbits)(&zgsz3119);
    vector_subrange_lbits(&zgsz3119, zgsz3116, zgsz3117, zgsz3118);
    zgaz313 = CONVERT_OF(fbits, lbits)(zgsz3119, true);
    KILL(lbits)(&zgsz3119);
    KILL(sail_int)(&zgsz3118);
    KILL(sail_int)(&zgsz3117);
    KILL(lbits)(&zgsz3116);
  }
  uint64_t zgaz314;
  {
    lbits zgsz3112;
    CREATE(lbits)(&zgsz3112);
    CONVERT_OF(lbits, fbits)(&zgsz3112, zc, UINT64_C(64) , true);
    sail_int zgsz3113;
    CREATE(sail_int)(&zgsz3113);
    CONVERT_OF(sail_int, mach_int)(&zgsz3113, INT64_C(39));
    sail_int zgsz3114;
    CREATE(sail_int)(&zgsz3114);
    CONVERT_OF(sail_int, mach_int)(&zgsz3114, INT64_C(32));
    lbits zgsz3115;
    CREATE(lbits)(&zgsz3115);
    vector_subrange_lbits(&zgsz3115, zgsz3112, zgsz3113, zgsz3114);
    zgaz314 = CONVERT_OF(fbits, lbits)(zgsz3115, true);
    KILL(lbits)(&zgsz3115);
    KILL(sail_int)(&zgsz3114);
    KILL(sail_int)(&zgsz3113);
    KILL(lbits)(&zgsz3112);
  }
  uint64_t zgaz315;
  {
    lbits zgsz3108;
    CREATE(lbits)(&zgsz3108);
    CONVERT_OF(lbits, fbits)(&zgsz3108, zc, UINT64_C(64) , true);
    sail_int zgsz3109;
    CREATE(sail_int)(&zgsz3109);
    CONVERT_OF(sail_int, mach_int)(&zgsz3109, INT64_C(31));
    sail_int zgsz3110;
    CREATE(sail_int)(&zgsz3110);
    CONVERT_OF(sail_int, mach_int)(&zgsz3110, INT64_C(0));
    lbits zgsz3111;
    CREATE(lbits)(&zgsz3111);
    vector_subrange_lbits(&zgsz3111, zgsz3108, zgsz3109, zgsz3110);
    zgaz315 = CONVERT_OF(fbits, lbits)(zgsz3111, true);
    KILL(lbits)(&zgsz3111);
    KILL(sail_int)(&zgsz3110);
    KILL(sail_int)(&zgsz3109);
    KILL(lbits)(&zgsz3108);
  }
  struct zEncCapability zgsz321;
  zgsz321.zB = zgaz314;
  zgsz321.zT = zgaz313;
  zgsz321.zaddress = zgaz315;
  zgsz321.zflags = zgaz310;
  zgsz321.zinternal_E = zgaz312;
  zgsz321.zotype = zgaz311;
  zgsz321.zperms = zgaz39;
  zgsz321.zreserved = UINT64_C(0);
  zcbz314 = zgsz321;








end_function_64: ;
  return zcbz314;
end_block_exception_65: ;
  struct zEncCapability zcbz346 = { .zB = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaddress = UINT64_C(0xdeadc0de), .zflags = UINT64_C(0xdeadc0de), .zinternal_E = UINT64_C(0), .zotype = UINT64_C(0xdeadc0de), .zperms = UINT64_C(0xdeadc0de), .zreserved = UINT64_C(0xdeadc0de) };
  return zcbz346;
}

static uint64_t sailgen_encCapToBits(struct zEncCapability);

static uint64_t sailgen_encCapToBits(struct zEncCapability zcap)
{
  __label__ end_function_67, end_block_exception_68;

  uint64_t zcbz315;
  uint64_t zgaz329;
  zgaz329 = zcap.zperms;
  uint64_t zgaz330;
  {
    uint64_t zgaz327;
    zgaz327 = zcap.zreserved;
    uint64_t zgaz328;
    {
      uint64_t zgaz325;
      zgaz325 = zcap.zflags;
      uint64_t zgaz326;
      {
        uint64_t zgaz323;
        zgaz323 = zcap.zotype;
        uint64_t zgaz324;
        {
          uint64_t zgaz321;
          {
            fbits zgaz316;
            zgaz316 = zcap.zinternal_E;
            uint64_t zgsz322;
            zgsz322 = UINT64_C(0b0);
            zgsz322 = update_fbits(zgsz322, INT64_C(0), zgaz316);
            zgaz321 = zgsz322;
          }
          uint64_t zgaz322;
          {
            uint64_t zgaz319;
            zgaz319 = zcap.zT;
            uint64_t zgaz320;
            {
              uint64_t zgaz317;
              zgaz317 = zcap.zB;
              uint64_t zgaz318;
              zgaz318 = zcap.zaddress;
              {
                lbits zgsz3134;
                CREATE(lbits)(&zgsz3134);
                CONVERT_OF(lbits, fbits)(&zgsz3134, zgaz317, UINT64_C(8) , true);
                lbits zgsz3135;
                CREATE(lbits)(&zgsz3135);
                CONVERT_OF(lbits, fbits)(&zgsz3135, zgaz318, UINT64_C(32) , true);
                lbits zgsz3136;
                CREATE(lbits)(&zgsz3136);
                append(&zgsz3136, zgsz3134, zgsz3135);
                zgaz320 = CONVERT_OF(fbits, lbits)(zgsz3136, true);
                KILL(lbits)(&zgsz3136);
                KILL(lbits)(&zgsz3135);
                KILL(lbits)(&zgsz3134);
              }
            }
            {
              lbits zgsz3137;
              CREATE(lbits)(&zgsz3137);
              CONVERT_OF(lbits, fbits)(&zgsz3137, zgaz319, UINT64_C(6) , true);
              lbits zgsz3138;
              CREATE(lbits)(&zgsz3138);
              CONVERT_OF(lbits, fbits)(&zgsz3138, zgaz320, UINT64_C(40) , true);
              lbits zgsz3139;
              CREATE(lbits)(&zgsz3139);
              append(&zgsz3139, zgsz3137, zgsz3138);
              zgaz322 = CONVERT_OF(fbits, lbits)(zgsz3139, true);
              KILL(lbits)(&zgsz3139);
              KILL(lbits)(&zgsz3138);
              KILL(lbits)(&zgsz3137);
            }
          }
          {
            lbits zgsz3140;
            CREATE(lbits)(&zgsz3140);
            CONVERT_OF(lbits, fbits)(&zgsz3140, zgaz321, UINT64_C(1) , true);
            lbits zgsz3141;
            CREATE(lbits)(&zgsz3141);
            CONVERT_OF(lbits, fbits)(&zgsz3141, zgaz322, UINT64_C(46) , true);
            lbits zgsz3142;
            CREATE(lbits)(&zgsz3142);
            append(&zgsz3142, zgsz3140, zgsz3141);
            zgaz324 = CONVERT_OF(fbits, lbits)(zgsz3142, true);
            KILL(lbits)(&zgsz3142);
            KILL(lbits)(&zgsz3141);
            KILL(lbits)(&zgsz3140);
          }
        }
        {
          lbits zgsz3143;
          CREATE(lbits)(&zgsz3143);
          CONVERT_OF(lbits, fbits)(&zgsz3143, zgaz323, UINT64_C(4) , true);
          lbits zgsz3144;
          CREATE(lbits)(&zgsz3144);
          CONVERT_OF(lbits, fbits)(&zgsz3144, zgaz324, UINT64_C(47) , true);
          lbits zgsz3145;
          CREATE(lbits)(&zgsz3145);
          append(&zgsz3145, zgsz3143, zgsz3144);
          zgaz326 = CONVERT_OF(fbits, lbits)(zgsz3145, true);
          KILL(lbits)(&zgsz3145);
          KILL(lbits)(&zgsz3144);
          KILL(lbits)(&zgsz3143);
        }
      }
      {
        lbits zgsz3146;
        CREATE(lbits)(&zgsz3146);
        CONVERT_OF(lbits, fbits)(&zgsz3146, zgaz325, UINT64_C(1) , true);
        lbits zgsz3147;
        CREATE(lbits)(&zgsz3147);
        CONVERT_OF(lbits, fbits)(&zgsz3147, zgaz326, UINT64_C(51) , true);
        lbits zgsz3148;
        CREATE(lbits)(&zgsz3148);
        append(&zgsz3148, zgsz3146, zgsz3147);
        zgaz328 = CONVERT_OF(fbits, lbits)(zgsz3148, true);
        KILL(lbits)(&zgsz3148);
        KILL(lbits)(&zgsz3147);
        KILL(lbits)(&zgsz3146);
      }
    }
    {
      lbits zgsz3149;
      CREATE(lbits)(&zgsz3149);
      CONVERT_OF(lbits, fbits)(&zgsz3149, zgaz327, UINT64_C(0) , true);
      lbits zgsz3150;
      CREATE(lbits)(&zgsz3150);
      CONVERT_OF(lbits, fbits)(&zgsz3150, zgaz328, UINT64_C(52) , true);
      lbits zgsz3151;
      CREATE(lbits)(&zgsz3151);
      append(&zgsz3151, zgsz3149, zgsz3150);
      zgaz330 = CONVERT_OF(fbits, lbits)(zgsz3151, true);
      KILL(lbits)(&zgsz3151);
      KILL(lbits)(&zgsz3150);
      KILL(lbits)(&zgsz3149);
    }
  }
  {
    lbits zgsz3152;
    CREATE(lbits)(&zgsz3152);
    CONVERT_OF(lbits, fbits)(&zgsz3152, zgaz329, UINT64_C(12) , true);
    lbits zgsz3153;
    CREATE(lbits)(&zgsz3153);
    CONVERT_OF(lbits, fbits)(&zgsz3153, zgaz330, UINT64_C(52) , true);
    lbits zgsz3154;
    CREATE(lbits)(&zgsz3154);
    append(&zgsz3154, zgsz3152, zgsz3153);
    zcbz315 = CONVERT_OF(fbits, lbits)(zgsz3154, true);
    KILL(lbits)(&zgsz3154);
    KILL(lbits)(&zgsz3153);
    KILL(lbits)(&zgsz3152);
  }


end_function_67: ;
  return zcbz315;
end_block_exception_68: ;

  return UINT64_C(0xdeadc0de);
}

static int64_t zcap_max_addr;
static void create_letbind_18(void) {


  int64_t zgsz323;
  {
    sail_int zgsz3155;
    CREATE(sail_int)(&zgsz3155);
    CONVERT_OF(sail_int, mach_int)(&zgsz3155, zcap_addr_width);
    sail_int zgsz3156;
    CREATE(sail_int)(&zgsz3156);
    sailgen_MAX(&zgsz3156, zgsz3155);
    zgsz323 = CONVERT_OF(mach_int, sail_int)(zgsz3156);
    KILL(sail_int)(&zgsz3156);
    KILL(sail_int)(&zgsz3155);
  }
  zcap_max_addr = zgsz323;

let_end_69: ;
}
static void kill_letbind_18(void) {
}

static int64_t zcap_max_otype;
static void create_letbind_19(void) {


  int64_t zgsz324;
  int64_t zgaz331;
  {
    sail_int zgsz3160;
    CREATE(sail_int)(&zgsz3160);
    CONVERT_OF(sail_int, mach_int)(&zgsz3160, zcap_otype_width);
    sail_int zgsz3161;
    CREATE(sail_int)(&zgsz3161);
    sailgen_MAX(&zgsz3161, zgsz3160);
    zgaz331 = CONVERT_OF(mach_int, sail_int)(zgsz3161);
    KILL(sail_int)(&zgsz3161);
    KILL(sail_int)(&zgsz3160);
  }
  {
    sail_int zgsz3157;
    CREATE(sail_int)(&zgsz3157);
    CONVERT_OF(sail_int, mach_int)(&zgsz3157, zgaz331);
    sail_int zgsz3158;
    CREATE(sail_int)(&zgsz3158);
    CONVERT_OF(sail_int, mach_int)(&zgsz3158, zreserved_otypes);
    sail_int zgsz3159;
    CREATE(sail_int)(&zgsz3159);
    sub_int(&zgsz3159, zgsz3157, zgsz3158);
    zgsz324 = CONVERT_OF(mach_int, sail_int)(zgsz3159);
    KILL(sail_int)(&zgsz3159);
    KILL(sail_int)(&zgsz3158);
    KILL(sail_int)(&zgsz3157);
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
  zgsz326 = INT64_C(15);
  zcap_perms_width = zgsz326;

let_end_72: ;
}
static void kill_letbind_21(void) {
}

static int64_t zcap_max_E;
static void create_letbind_22(void) {


  int64_t zgsz327;
  int64_t zgaz332;
  {
    sail_int zgsz3165;
    CREATE(sail_int)(&zgsz3165);
    CONVERT_OF(sail_int, mach_int)(&zgsz3165, zcap_len_width);
    sail_int zgsz3166;
    CREATE(sail_int)(&zgsz3166);
    CONVERT_OF(sail_int, mach_int)(&zgsz3166, zcap_mantissa_width);
    sail_int zgsz3167;
    CREATE(sail_int)(&zgsz3167);
    sub_int(&zgsz3167, zgsz3165, zgsz3166);
    zgaz332 = CONVERT_OF(mach_int, sail_int)(zgsz3167);
    KILL(sail_int)(&zgsz3167);
    KILL(sail_int)(&zgsz3166);
    KILL(sail_int)(&zgsz3165);
  }
  {
    sail_int zgsz3162;
    CREATE(sail_int)(&zgsz3162);
    CONVERT_OF(sail_int, mach_int)(&zgsz3162, zgaz332);
    sail_int zgsz3163;
    CREATE(sail_int)(&zgsz3163);
    CONVERT_OF(sail_int, mach_int)(&zgsz3163, INT64_C(1));
    sail_int zgsz3164;
    CREATE(sail_int)(&zgsz3164);
    add_int(&zgsz3164, zgsz3162, zgsz3163);
    zgsz327 = CONVERT_OF(mach_int, sail_int)(zgsz3164);
    KILL(sail_int)(&zgsz3164);
    KILL(sail_int)(&zgsz3163);
    KILL(sail_int)(&zgsz3162);
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
    sail_int zgsz3168;
    CREATE(sail_int)(&zgsz3168);
    CONVERT_OF(sail_int, mach_int)(&zgsz3168, zcap_E_width);
    sail_int zgsz3169;
    CREATE(sail_int)(&zgsz3169);
    CONVERT_OF(sail_int, mach_int)(&zgsz3169, zcap_max_E);
    lbits zgsz3170;
    CREATE(lbits)(&zgsz3170);
    sailgen_to_bits(&zgsz3170, zgsz3168, zgsz3169);
    zgsz328 = CONVERT_OF(fbits, lbits)(zgsz3170, true);
    KILL(lbits)(&zgsz3170);
    KILL(sail_int)(&zgsz3169);
    KILL(sail_int)(&zgsz3168);
  }
  zcap_reset_E = zgsz328;

let_end_74: ;
}
static void kill_letbind_23(void) {
}

static uint64_t zcap_reset_T;
static void create_letbind_24(void) {


  uint64_t zgsz329;
  uint64_t zgaz334;
  {
    int64_t zgaz333;
    {
      sail_int zgsz3173;
      CREATE(sail_int)(&zgsz3173);
      CONVERT_OF(sail_int, mach_int)(&zgsz3173, zcap_mantissa_width);
      sail_int zgsz3174;
      CREATE(sail_int)(&zgsz3174);
      CONVERT_OF(sail_int, mach_int)(&zgsz3174, INT64_C(2));
      sail_int zgsz3175;
      CREATE(sail_int)(&zgsz3175);
      sub_int(&zgsz3175, zgsz3173, zgsz3174);
      zgaz333 = CONVERT_OF(mach_int, sail_int)(zgsz3175);
      KILL(sail_int)(&zgsz3175);
      KILL(sail_int)(&zgsz3174);
      KILL(sail_int)(&zgsz3173);
    }
    {
      sail_int zgsz3171;
      CREATE(sail_int)(&zgsz3171);
      CONVERT_OF(sail_int, mach_int)(&zgsz3171, zgaz333);
      lbits zgsz3172;
      CREATE(lbits)(&zgsz3172);
      sailgen_zzeros_implicit(&zgsz3172, zgsz3171);
      zgaz334 = CONVERT_OF(fbits, lbits)(zgsz3172, true);
      KILL(lbits)(&zgsz3172);
      KILL(sail_int)(&zgsz3171);
    }
  }
  {
    lbits zgsz3176;
    CREATE(lbits)(&zgsz3176);
    CONVERT_OF(lbits, fbits)(&zgsz3176, UINT64_C(0b01), UINT64_C(2) , true);
    lbits zgsz3177;
    CREATE(lbits)(&zgsz3177);
    CONVERT_OF(lbits, fbits)(&zgsz3177, zgaz334, UINT64_C(6) , true);
    lbits zgsz3178;
    CREATE(lbits)(&zgsz3178);
    append(&zgsz3178, zgsz3176, zgsz3177);
    zgsz329 = CONVERT_OF(fbits, lbits)(zgsz3178, true);
    KILL(lbits)(&zgsz3178);
    KILL(lbits)(&zgsz3177);
    KILL(lbits)(&zgsz3176);
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
  bool zgaz335;
  zgaz335 = undefined_bool(UNIT);
  uint64_t zgaz336;
  {
    sail_int zgsz3191;
    CREATE(sail_int)(&zgsz3191);
    CONVERT_OF(sail_int, mach_int)(&zgsz3191, INT64_C(0));
    lbits zgsz3192;
    CREATE(lbits)(&zgsz3192);
    UNDEFINED(lbits)(&zgsz3192, zgsz3191);
    zgaz336 = CONVERT_OF(fbits, lbits)(zgsz3192, true);
    KILL(lbits)(&zgsz3192);
    KILL(sail_int)(&zgsz3191);
  }
  bool zgaz337;
  zgaz337 = undefined_bool(UNIT);
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
  uint64_t zgaz349;
  {
    sail_int zgsz3189;
    CREATE(sail_int)(&zgsz3189);
    CONVERT_OF(sail_int, mach_int)(&zgsz3189, INT64_C(0));
    lbits zgsz3190;
    CREATE(lbits)(&zgsz3190);
    UNDEFINED(lbits)(&zgsz3190, zgsz3189);
    zgaz349 = CONVERT_OF(fbits, lbits)(zgsz3190, true);
    KILL(lbits)(&zgsz3190);
    KILL(sail_int)(&zgsz3189);
  }
  bool zgaz350;
  zgaz350 = undefined_bool(UNIT);
  bool zgaz351;
  zgaz351 = undefined_bool(UNIT);
  uint64_t zgaz352;
  {
    sail_int zgsz3187;
    CREATE(sail_int)(&zgsz3187);
    CONVERT_OF(sail_int, mach_int)(&zgsz3187, INT64_C(6));
    lbits zgsz3188;
    CREATE(lbits)(&zgsz3188);
    UNDEFINED(lbits)(&zgsz3188, zgsz3187);
    zgaz352 = CONVERT_OF(fbits, lbits)(zgsz3188, true);
    KILL(lbits)(&zgsz3188);
    KILL(sail_int)(&zgsz3187);
  }
  uint64_t zgaz353;
  {
    sail_int zgsz3185;
    CREATE(sail_int)(&zgsz3185);
    CONVERT_OF(sail_int, mach_int)(&zgsz3185, INT64_C(8));
    lbits zgsz3186;
    CREATE(lbits)(&zgsz3186);
    UNDEFINED(lbits)(&zgsz3186, zgsz3185);
    zgaz353 = CONVERT_OF(fbits, lbits)(zgsz3186, true);
    KILL(lbits)(&zgsz3186);
    KILL(sail_int)(&zgsz3185);
  }
  uint64_t zgaz354;
  {
    sail_int zgsz3183;
    CREATE(sail_int)(&zgsz3183);
    CONVERT_OF(sail_int, mach_int)(&zgsz3183, INT64_C(8));
    lbits zgsz3184;
    CREATE(lbits)(&zgsz3184);
    UNDEFINED(lbits)(&zgsz3184, zgsz3183);
    zgaz354 = CONVERT_OF(fbits, lbits)(zgsz3184, true);
    KILL(lbits)(&zgsz3184);
    KILL(sail_int)(&zgsz3183);
  }
  uint64_t zgaz355;
  {
    sail_int zgsz3181;
    CREATE(sail_int)(&zgsz3181);
    CONVERT_OF(sail_int, mach_int)(&zgsz3181, INT64_C(4));
    lbits zgsz3182;
    CREATE(lbits)(&zgsz3182);
    UNDEFINED(lbits)(&zgsz3182, zgsz3181);
    zgaz355 = CONVERT_OF(fbits, lbits)(zgsz3182, true);
    KILL(lbits)(&zgsz3182);
    KILL(sail_int)(&zgsz3181);
  }
  uint64_t zgaz356;
  {
    sail_int zgsz3179;
    CREATE(sail_int)(&zgsz3179);
    CONVERT_OF(sail_int, mach_int)(&zgsz3179, INT64_C(32));
    lbits zgsz3180;
    CREATE(lbits)(&zgsz3180);
    UNDEFINED(lbits)(&zgsz3180, zgsz3179);
    zgaz356 = CONVERT_OF(fbits, lbits)(zgsz3180, true);
    KILL(lbits)(&zgsz3180);
    KILL(sail_int)(&zgsz3179);
  }
  struct zCapability zgsz331;
  zgsz331.zB = zgaz353;
  zgsz331.zE = zgaz352;
  zgsz331.zT = zgaz354;
  zgsz331.zaccess_system_regs = zgaz338;
  zgsz331.zaddress = zgaz356;
  zgsz331.zflag_cap_mode = zgaz350;
  zgsz331.zglobal = zgaz348;
  zgsz331.zinternal_E = zgaz351;
  zgsz331.zotype = zgaz355;
  zgsz331.zpermit_cinvoke = zgaz340;
  zgsz331.zpermit_execute = zgaz347;
  zgsz331.zpermit_load = zgaz346;
  zgsz331.zpermit_load_cap = zgaz344;
  zgsz331.zpermit_seal = zgaz341;
  zgsz331.zpermit_set_CID = zgaz337;
  zgsz331.zpermit_store = zgaz345;
  zgsz331.zpermit_store_cap = zgaz343;
  zgsz331.zpermit_store_local_cap = zgaz342;
  zgsz331.zpermit_unseal = zgaz339;
  zgsz331.zreserved = zgaz349;
  zgsz331.ztag = zgaz335;
  zgsz331.zuperms = zgaz336;
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
  uint64_t zgaz357;
  {
    sail_int zgsz3202;
    CREATE(sail_int)(&zgsz3202);
    CONVERT_OF(sail_int, mach_int)(&zgsz3202, INT64_C(0));
    lbits zgsz3203;
    CREATE(lbits)(&zgsz3203);
    sailgen_zzeros_implicit(&zgsz3203, zgsz3202);
    zgaz357 = CONVERT_OF(fbits, lbits)(zgsz3203, true);
    KILL(lbits)(&zgsz3203);
    KILL(sail_int)(&zgsz3202);
  }
  uint64_t zgaz358;
  {
    sail_int zgsz3200;
    CREATE(sail_int)(&zgsz3200);
    CONVERT_OF(sail_int, mach_int)(&zgsz3200, INT64_C(0));
    lbits zgsz3201;
    CREATE(lbits)(&zgsz3201);
    sailgen_zzeros_implicit(&zgsz3201, zgsz3200);
    zgaz358 = CONVERT_OF(fbits, lbits)(zgsz3201, true);
    KILL(lbits)(&zgsz3201);
    KILL(sail_int)(&zgsz3200);
  }
  uint64_t zgaz359;
  {
    sail_int zgsz3198;
    CREATE(sail_int)(&zgsz3198);
    CONVERT_OF(sail_int, mach_int)(&zgsz3198, INT64_C(8));
    lbits zgsz3199;
    CREATE(lbits)(&zgsz3199);
    sailgen_zzeros_implicit(&zgsz3199, zgsz3198);
    zgaz359 = CONVERT_OF(fbits, lbits)(zgsz3199, true);
    KILL(lbits)(&zgsz3199);
    KILL(sail_int)(&zgsz3198);
  }
  uint64_t zgaz360;
  {
    sail_int zgsz3195;
    CREATE(sail_int)(&zgsz3195);
    CONVERT_OF(sail_int, mach_int)(&zgsz3195, zcap_otype_width);
    sail_int zgsz3196;
    CREATE(sail_int)(&zgsz3196);
    CONVERT_OF(sail_int, mach_int)(&zgsz3196, zotype_unsealed);
    lbits zgsz3197;
    CREATE(lbits)(&zgsz3197);
    sailgen_to_bits(&zgsz3197, zgsz3195, zgsz3196);
    zgaz360 = CONVERT_OF(fbits, lbits)(zgsz3197, true);
    KILL(lbits)(&zgsz3197);
    KILL(sail_int)(&zgsz3196);
    KILL(sail_int)(&zgsz3195);
  }
  uint64_t zgaz361;
  {
    sail_int zgsz3193;
    CREATE(sail_int)(&zgsz3193);
    CONVERT_OF(sail_int, mach_int)(&zgsz3193, INT64_C(32));
    lbits zgsz3194;
    CREATE(lbits)(&zgsz3194);
    sailgen_zzeros_implicit(&zgsz3194, zgsz3193);
    zgaz361 = CONVERT_OF(fbits, lbits)(zgsz3194, true);
    KILL(lbits)(&zgsz3194);
    KILL(sail_int)(&zgsz3193);
  }
  struct zCapability zgsz332;
  zgsz332.zB = zgaz359;
  zgsz332.zE = zcap_reset_E;
  zgsz332.zT = zcap_reset_T;
  zgsz332.zaccess_system_regs = false;
  zgsz332.zaddress = zgaz361;
  zgsz332.zflag_cap_mode = false;
  zgsz332.zglobal = false;
  zgsz332.zinternal_E = true;
  zgsz332.zotype = zgaz360;
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
  zgsz332.zreserved = zgaz358;
  zgsz332.ztag = false;
  zgsz332.zuperms = zgaz357;
  zgsz333 = zgsz332;






  znull_cap = zgsz333;

let_end_79: ;
}
static void kill_letbind_25(void) {
}

static struct zCapability zdefault_cap;
static void create_letbind_26(void) {


  struct zCapability zgsz335;
  uint64_t zgaz362;
  {
    sail_int zgsz3213;
    CREATE(sail_int)(&zgsz3213);
    CONVERT_OF(sail_int, mach_int)(&zgsz3213, INT64_C(0));
    lbits zgsz3214;
    CREATE(lbits)(&zgsz3214);
    sailgen_ones(&zgsz3214, zgsz3213);
    zgaz362 = CONVERT_OF(fbits, lbits)(zgsz3214, true);
    KILL(lbits)(&zgsz3214);
    KILL(sail_int)(&zgsz3213);
  }
  uint64_t zgaz363;
  {
    sail_int zgsz3211;
    CREATE(sail_int)(&zgsz3211);
    CONVERT_OF(sail_int, mach_int)(&zgsz3211, INT64_C(0));
    lbits zgsz3212;
    CREATE(lbits)(&zgsz3212);
    sailgen_zzeros_implicit(&zgsz3212, zgsz3211);
    zgaz363 = CONVERT_OF(fbits, lbits)(zgsz3212, true);
    KILL(lbits)(&zgsz3212);
    KILL(sail_int)(&zgsz3211);
  }
  uint64_t zgaz364;
  {
    sail_int zgsz3209;
    CREATE(sail_int)(&zgsz3209);
    CONVERT_OF(sail_int, mach_int)(&zgsz3209, INT64_C(8));
    lbits zgsz3210;
    CREATE(lbits)(&zgsz3210);
    sailgen_zzeros_implicit(&zgsz3210, zgsz3209);
    zgaz364 = CONVERT_OF(fbits, lbits)(zgsz3210, true);
    KILL(lbits)(&zgsz3210);
    KILL(sail_int)(&zgsz3209);
  }
  uint64_t zgaz365;
  {
    sail_int zgsz3206;
    CREATE(sail_int)(&zgsz3206);
    CONVERT_OF(sail_int, mach_int)(&zgsz3206, zcap_otype_width);
    sail_int zgsz3207;
    CREATE(sail_int)(&zgsz3207);
    CONVERT_OF(sail_int, mach_int)(&zgsz3207, zotype_unsealed);
    lbits zgsz3208;
    CREATE(lbits)(&zgsz3208);
    sailgen_to_bits(&zgsz3208, zgsz3206, zgsz3207);
    zgaz365 = CONVERT_OF(fbits, lbits)(zgsz3208, true);
    KILL(lbits)(&zgsz3208);
    KILL(sail_int)(&zgsz3207);
    KILL(sail_int)(&zgsz3206);
  }
  uint64_t zgaz366;
  {
    sail_int zgsz3204;
    CREATE(sail_int)(&zgsz3204);
    CONVERT_OF(sail_int, mach_int)(&zgsz3204, INT64_C(32));
    lbits zgsz3205;
    CREATE(lbits)(&zgsz3205);
    sailgen_zzeros_implicit(&zgsz3205, zgsz3204);
    zgaz366 = CONVERT_OF(fbits, lbits)(zgsz3205, true);
    KILL(lbits)(&zgsz3205);
    KILL(sail_int)(&zgsz3204);
  }
  struct zCapability zgsz334;
  zgsz334.zB = zgaz364;
  zgsz334.zE = zcap_reset_E;
  zgsz334.zT = zcap_reset_T;
  zgsz334.zaccess_system_regs = true;
  zgsz334.zaddress = zgaz366;
  zgsz334.zflag_cap_mode = false;
  zgsz334.zglobal = true;
  zgsz334.zinternal_E = true;
  zgsz334.zotype = zgaz365;
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
  zgsz334.zreserved = zgaz363;
  zgsz334.ztag = true;
  zgsz334.zuperms = zgaz362;
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
  uint64_t zgaz399;
  {
    bool zgaz367;
    zgaz367 = zcap.zpermit_set_CID;
    zgaz399 = sailgen_bool_to_bits(zgaz367);
  }
  uint64_t zgaz3100;
  {
    uint64_t zgaz397;
    {
      bool zgaz368;
      zgaz368 = zcap.zaccess_system_regs;
      zgaz397 = sailgen_bool_to_bits(zgaz368);
    }
    uint64_t zgaz398;
    {
      uint64_t zgaz395;
      {
        bool zgaz369;
        zgaz369 = zcap.zpermit_unseal;
        zgaz395 = sailgen_bool_to_bits(zgaz369);
      }
      uint64_t zgaz396;
      {
        uint64_t zgaz393;
        {
          bool zgaz370;
          zgaz370 = zcap.zpermit_cinvoke;
          zgaz393 = sailgen_bool_to_bits(zgaz370);
        }
        uint64_t zgaz394;
        {
          uint64_t zgaz391;
          {
            bool zgaz371;
            zgaz371 = zcap.zpermit_seal;
            zgaz391 = sailgen_bool_to_bits(zgaz371);
          }
          uint64_t zgaz392;
          {
            uint64_t zgaz389;
            {
              bool zgaz372;
              zgaz372 = zcap.zpermit_store_local_cap;
              zgaz389 = sailgen_bool_to_bits(zgaz372);
            }
            uint64_t zgaz390;
            {
              uint64_t zgaz387;
              {
                bool zgaz373;
                zgaz373 = zcap.zpermit_store_cap;
                zgaz387 = sailgen_bool_to_bits(zgaz373);
              }
              uint64_t zgaz388;
              {
                uint64_t zgaz385;
                {
                  bool zgaz374;
                  zgaz374 = zcap.zpermit_load_cap;
                  zgaz385 = sailgen_bool_to_bits(zgaz374);
                }
                uint64_t zgaz386;
                {
                  uint64_t zgaz383;
                  {
                    bool zgaz375;
                    zgaz375 = zcap.zpermit_store;
                    zgaz383 = sailgen_bool_to_bits(zgaz375);
                  }
                  uint64_t zgaz384;
                  {
                    uint64_t zgaz381;
                    {
                      bool zgaz376;
                      zgaz376 = zcap.zpermit_load;
                      zgaz381 = sailgen_bool_to_bits(zgaz376);
                    }
                    uint64_t zgaz382;
                    {
                      uint64_t zgaz379;
                      {
                        bool zgaz377;
                        zgaz377 = zcap.zpermit_execute;
                        zgaz379 = sailgen_bool_to_bits(zgaz377);
                      }
                      uint64_t zgaz380;
                      {
                        bool zgaz378;
                        zgaz378 = zcap.zglobal;
                        zgaz380 = sailgen_bool_to_bits(zgaz378);
                      }
                      {
                        lbits zgsz3215;
                        CREATE(lbits)(&zgsz3215);
                        CONVERT_OF(lbits, fbits)(&zgsz3215, zgaz379, UINT64_C(1) , true);
                        lbits zgsz3216;
                        CREATE(lbits)(&zgsz3216);
                        CONVERT_OF(lbits, fbits)(&zgsz3216, zgaz380, UINT64_C(1) , true);
                        lbits zgsz3217;
                        CREATE(lbits)(&zgsz3217);
                        append(&zgsz3217, zgsz3215, zgsz3216);
                        zgaz382 = CONVERT_OF(fbits, lbits)(zgsz3217, true);
                        KILL(lbits)(&zgsz3217);
                        KILL(lbits)(&zgsz3216);
                        KILL(lbits)(&zgsz3215);
                      }
                    }
                    {
                      lbits zgsz3218;
                      CREATE(lbits)(&zgsz3218);
                      CONVERT_OF(lbits, fbits)(&zgsz3218, zgaz381, UINT64_C(1) , true);
                      lbits zgsz3219;
                      CREATE(lbits)(&zgsz3219);
                      CONVERT_OF(lbits, fbits)(&zgsz3219, zgaz382, UINT64_C(2) , true);
                      lbits zgsz3220;
                      CREATE(lbits)(&zgsz3220);
                      append(&zgsz3220, zgsz3218, zgsz3219);
                      zgaz384 = CONVERT_OF(fbits, lbits)(zgsz3220, true);
                      KILL(lbits)(&zgsz3220);
                      KILL(lbits)(&zgsz3219);
                      KILL(lbits)(&zgsz3218);
                    }
                  }
                  {
                    lbits zgsz3221;
                    CREATE(lbits)(&zgsz3221);
                    CONVERT_OF(lbits, fbits)(&zgsz3221, zgaz383, UINT64_C(1) , true);
                    lbits zgsz3222;
                    CREATE(lbits)(&zgsz3222);
                    CONVERT_OF(lbits, fbits)(&zgsz3222, zgaz384, UINT64_C(3) , true);
                    lbits zgsz3223;
                    CREATE(lbits)(&zgsz3223);
                    append(&zgsz3223, zgsz3221, zgsz3222);
                    zgaz386 = CONVERT_OF(fbits, lbits)(zgsz3223, true);
                    KILL(lbits)(&zgsz3223);
                    KILL(lbits)(&zgsz3222);
                    KILL(lbits)(&zgsz3221);
                  }
                }
                {
                  lbits zgsz3224;
                  CREATE(lbits)(&zgsz3224);
                  CONVERT_OF(lbits, fbits)(&zgsz3224, zgaz385, UINT64_C(1) , true);
                  lbits zgsz3225;
                  CREATE(lbits)(&zgsz3225);
                  CONVERT_OF(lbits, fbits)(&zgsz3225, zgaz386, UINT64_C(4) , true);
                  lbits zgsz3226;
                  CREATE(lbits)(&zgsz3226);
                  append(&zgsz3226, zgsz3224, zgsz3225);
                  zgaz388 = CONVERT_OF(fbits, lbits)(zgsz3226, true);
                  KILL(lbits)(&zgsz3226);
                  KILL(lbits)(&zgsz3225);
                  KILL(lbits)(&zgsz3224);
                }
              }
              {
                lbits zgsz3227;
                CREATE(lbits)(&zgsz3227);
                CONVERT_OF(lbits, fbits)(&zgsz3227, zgaz387, UINT64_C(1) , true);
                lbits zgsz3228;
                CREATE(lbits)(&zgsz3228);
                CONVERT_OF(lbits, fbits)(&zgsz3228, zgaz388, UINT64_C(5) , true);
                lbits zgsz3229;
                CREATE(lbits)(&zgsz3229);
                append(&zgsz3229, zgsz3227, zgsz3228);
                zgaz390 = CONVERT_OF(fbits, lbits)(zgsz3229, true);
                KILL(lbits)(&zgsz3229);
                KILL(lbits)(&zgsz3228);
                KILL(lbits)(&zgsz3227);
              }
            }
            {
              lbits zgsz3230;
              CREATE(lbits)(&zgsz3230);
              CONVERT_OF(lbits, fbits)(&zgsz3230, zgaz389, UINT64_C(1) , true);
              lbits zgsz3231;
              CREATE(lbits)(&zgsz3231);
              CONVERT_OF(lbits, fbits)(&zgsz3231, zgaz390, UINT64_C(6) , true);
              lbits zgsz3232;
              CREATE(lbits)(&zgsz3232);
              append(&zgsz3232, zgsz3230, zgsz3231);
              zgaz392 = CONVERT_OF(fbits, lbits)(zgsz3232, true);
              KILL(lbits)(&zgsz3232);
              KILL(lbits)(&zgsz3231);
              KILL(lbits)(&zgsz3230);
            }
          }
          {
            lbits zgsz3233;
            CREATE(lbits)(&zgsz3233);
            CONVERT_OF(lbits, fbits)(&zgsz3233, zgaz391, UINT64_C(1) , true);
            lbits zgsz3234;
            CREATE(lbits)(&zgsz3234);
            CONVERT_OF(lbits, fbits)(&zgsz3234, zgaz392, UINT64_C(7) , true);
            lbits zgsz3235;
            CREATE(lbits)(&zgsz3235);
            append(&zgsz3235, zgsz3233, zgsz3234);
            zgaz394 = CONVERT_OF(fbits, lbits)(zgsz3235, true);
            KILL(lbits)(&zgsz3235);
            KILL(lbits)(&zgsz3234);
            KILL(lbits)(&zgsz3233);
          }
        }
        {
          lbits zgsz3236;
          CREATE(lbits)(&zgsz3236);
          CONVERT_OF(lbits, fbits)(&zgsz3236, zgaz393, UINT64_C(1) , true);
          lbits zgsz3237;
          CREATE(lbits)(&zgsz3237);
          CONVERT_OF(lbits, fbits)(&zgsz3237, zgaz394, UINT64_C(8) , true);
          lbits zgsz3238;
          CREATE(lbits)(&zgsz3238);
          append(&zgsz3238, zgsz3236, zgsz3237);
          zgaz396 = CONVERT_OF(fbits, lbits)(zgsz3238, true);
          KILL(lbits)(&zgsz3238);
          KILL(lbits)(&zgsz3237);
          KILL(lbits)(&zgsz3236);
        }
      }
      {
        lbits zgsz3239;
        CREATE(lbits)(&zgsz3239);
        CONVERT_OF(lbits, fbits)(&zgsz3239, zgaz395, UINT64_C(1) , true);
        lbits zgsz3240;
        CREATE(lbits)(&zgsz3240);
        CONVERT_OF(lbits, fbits)(&zgsz3240, zgaz396, UINT64_C(9) , true);
        lbits zgsz3241;
        CREATE(lbits)(&zgsz3241);
        append(&zgsz3241, zgsz3239, zgsz3240);
        zgaz398 = CONVERT_OF(fbits, lbits)(zgsz3241, true);
        KILL(lbits)(&zgsz3241);
        KILL(lbits)(&zgsz3240);
        KILL(lbits)(&zgsz3239);
      }
    }
    {
      lbits zgsz3242;
      CREATE(lbits)(&zgsz3242);
      CONVERT_OF(lbits, fbits)(&zgsz3242, zgaz397, UINT64_C(1) , true);
      lbits zgsz3243;
      CREATE(lbits)(&zgsz3243);
      CONVERT_OF(lbits, fbits)(&zgsz3243, zgaz398, UINT64_C(10) , true);
      lbits zgsz3244;
      CREATE(lbits)(&zgsz3244);
      append(&zgsz3244, zgsz3242, zgsz3243);
      zgaz3100 = CONVERT_OF(fbits, lbits)(zgsz3244, true);
      KILL(lbits)(&zgsz3244);
      KILL(lbits)(&zgsz3243);
      KILL(lbits)(&zgsz3242);
    }
  }
  {
    lbits zgsz3245;
    CREATE(lbits)(&zgsz3245);
    CONVERT_OF(lbits, fbits)(&zgsz3245, zgaz399, UINT64_C(1) , true);
    lbits zgsz3246;
    CREATE(lbits)(&zgsz3246);
    CONVERT_OF(lbits, fbits)(&zgsz3246, zgaz3100, UINT64_C(11) , true);
    lbits zgsz3247;
    CREATE(lbits)(&zgsz3247);
    append(&zgsz3247, zgsz3245, zgsz3246);
    zcbz317 = CONVERT_OF(fbits, lbits)(zgsz3247, true);
    KILL(lbits)(&zgsz3247);
    KILL(lbits)(&zgsz3246);
    KILL(lbits)(&zgsz3245);
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
    fbits zgaz3171;
    zgaz3171 = zc.zinternal_E;
    zinternal_E = sailgen_bit_to_bool(zgaz3171);
  }
  uint64_t zE;
  {
    sail_int zgsz3351;
    CREATE(sail_int)(&zgsz3351);
    CONVERT_OF(sail_int, mach_int)(&zgsz3351, INT64_C(6));
    lbits zgsz3352;
    CREATE(lbits)(&zgsz3352);
    sailgen_zzeros_implicit(&zgsz3352, zgsz3351);
    zE = CONVERT_OF(fbits, lbits)(zgsz3352, true);
    KILL(lbits)(&zgsz3352);
    KILL(sail_int)(&zgsz3351);
  }
  uint64_t zBs;
  {
    sail_int zgsz3349;
    CREATE(sail_int)(&zgsz3349);
    CONVERT_OF(sail_int, mach_int)(&zgsz3349, INT64_C(8));
    lbits zgsz3350;
    CREATE(lbits)(&zgsz3350);
    sailgen_zzeros_implicit(&zgsz3350, zgsz3349);
    zBs = CONVERT_OF(fbits, lbits)(zgsz3350, true);
    KILL(lbits)(&zgsz3350);
    KILL(sail_int)(&zgsz3349);
  }
  uint64_t zT;
  {
    sail_int zgsz3347;
    CREATE(sail_int)(&zgsz3347);
    CONVERT_OF(sail_int, mach_int)(&zgsz3347, INT64_C(6));
    lbits zgsz3348;
    CREATE(lbits)(&zgsz3348);
    sailgen_zzeros_implicit(&zgsz3348, zgsz3347);
    zT = CONVERT_OF(fbits, lbits)(zgsz3348, true);
    KILL(lbits)(&zgsz3348);
    KILL(sail_int)(&zgsz3347);
  }
  uint64_t zlenMSBs;
  {
    sail_int zgsz3345;
    CREATE(sail_int)(&zgsz3345);
    CONVERT_OF(sail_int, mach_int)(&zgsz3345, INT64_C(2));
    lbits zgsz3346;
    CREATE(lbits)(&zgsz3346);
    sailgen_zzeros_implicit(&zgsz3346, zgsz3345);
    zlenMSBs = CONVERT_OF(fbits, lbits)(zgsz3346, true);
    KILL(lbits)(&zgsz3346);
    KILL(sail_int)(&zgsz3345);
  }
  {
    unit zgsz336;
    if (zinternal_E) {
      {
        uint64_t zgaz3105;
        {
          uint64_t zgaz3101;
          zgaz3101 = zc.zT;
          int64_t zgaz3102;
          {
            sail_int zgsz3252;
            CREATE(sail_int)(&zgsz3252);
            CONVERT_OF(sail_int, mach_int)(&zgsz3252, zinternal_E_take_bits);
            sail_int zgsz3253;
            CREATE(sail_int)(&zgsz3253);
            CONVERT_OF(sail_int, mach_int)(&zgsz3253, INT64_C(1));
            sail_int zgsz3254;
            CREATE(sail_int)(&zgsz3254);
            sub_int(&zgsz3254, zgsz3252, zgsz3253);
            zgaz3102 = CONVERT_OF(mach_int, sail_int)(zgsz3254);
            KILL(sail_int)(&zgsz3254);
            KILL(sail_int)(&zgsz3253);
            KILL(sail_int)(&zgsz3252);
          }
          {
            lbits zgsz3248;
            CREATE(lbits)(&zgsz3248);
            CONVERT_OF(lbits, fbits)(&zgsz3248, zgaz3101, UINT64_C(6) , true);
            sail_int zgsz3249;
            CREATE(sail_int)(&zgsz3249);
            CONVERT_OF(sail_int, mach_int)(&zgsz3249, zgaz3102);
            sail_int zgsz3250;
            CREATE(sail_int)(&zgsz3250);
            CONVERT_OF(sail_int, mach_int)(&zgsz3250, INT64_C(0));
            lbits zgsz3251;
            CREATE(lbits)(&zgsz3251);
            vector_subrange_lbits(&zgsz3251, zgsz3248, zgsz3249, zgsz3250);
            zgaz3105 = CONVERT_OF(fbits, lbits)(zgsz3251, true);
            KILL(lbits)(&zgsz3251);
            KILL(sail_int)(&zgsz3250);
            KILL(sail_int)(&zgsz3249);
            KILL(lbits)(&zgsz3248);
          }
        }
        uint64_t zgaz3106;
        {
          uint64_t zgaz3103;
          zgaz3103 = zc.zB;
          int64_t zgaz3104;
          {
            sail_int zgsz3259;
            CREATE(sail_int)(&zgsz3259);
            CONVERT_OF(sail_int, mach_int)(&zgsz3259, zinternal_E_take_bits);
            sail_int zgsz3260;
            CREATE(sail_int)(&zgsz3260);
            CONVERT_OF(sail_int, mach_int)(&zgsz3260, INT64_C(1));
            sail_int zgsz3261;
            CREATE(sail_int)(&zgsz3261);
            sub_int(&zgsz3261, zgsz3259, zgsz3260);
            zgaz3104 = CONVERT_OF(mach_int, sail_int)(zgsz3261);
            KILL(sail_int)(&zgsz3261);
            KILL(sail_int)(&zgsz3260);
            KILL(sail_int)(&zgsz3259);
          }
          {
            lbits zgsz3255;
            CREATE(lbits)(&zgsz3255);
            CONVERT_OF(lbits, fbits)(&zgsz3255, zgaz3103, UINT64_C(8) , true);
            sail_int zgsz3256;
            CREATE(sail_int)(&zgsz3256);
            CONVERT_OF(sail_int, mach_int)(&zgsz3256, zgaz3104);
            sail_int zgsz3257;
            CREATE(sail_int)(&zgsz3257);
            CONVERT_OF(sail_int, mach_int)(&zgsz3257, INT64_C(0));
            lbits zgsz3258;
            CREATE(lbits)(&zgsz3258);
            vector_subrange_lbits(&zgsz3258, zgsz3255, zgsz3256, zgsz3257);
            zgaz3106 = CONVERT_OF(fbits, lbits)(zgsz3258, true);
            KILL(lbits)(&zgsz3258);
            KILL(sail_int)(&zgsz3257);
            KILL(sail_int)(&zgsz3256);
            KILL(lbits)(&zgsz3255);
          }
        }
        {
          lbits zgsz3262;
          CREATE(lbits)(&zgsz3262);
          CONVERT_OF(lbits, fbits)(&zgsz3262, zgaz3105, UINT64_C(3) , true);
          lbits zgsz3263;
          CREATE(lbits)(&zgsz3263);
          CONVERT_OF(lbits, fbits)(&zgsz3263, zgaz3106, UINT64_C(3) , true);
          lbits zgsz3264;
          CREATE(lbits)(&zgsz3264);
          append(&zgsz3264, zgsz3262, zgsz3263);
          zE = CONVERT_OF(fbits, lbits)(zgsz3264, true);
          KILL(lbits)(&zgsz3264);
          KILL(lbits)(&zgsz3263);
          KILL(lbits)(&zgsz3262);
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
        uint64_t zgaz3109;
        {
          uint64_t zgaz3107;
          zgaz3107 = zc.zT;
          int64_t zgaz3108;
          {
            sail_int zgsz3269;
            CREATE(sail_int)(&zgsz3269);
            CONVERT_OF(sail_int, mach_int)(&zgsz3269, zcap_mantissa_width);
            sail_int zgsz3270;
            CREATE(sail_int)(&zgsz3270);
            CONVERT_OF(sail_int, mach_int)(&zgsz3270, INT64_C(3));
            sail_int zgsz3271;
            CREATE(sail_int)(&zgsz3271);
            sub_int(&zgsz3271, zgsz3269, zgsz3270);
            zgaz3108 = CONVERT_OF(mach_int, sail_int)(zgsz3271);
            KILL(sail_int)(&zgsz3271);
            KILL(sail_int)(&zgsz3270);
            KILL(sail_int)(&zgsz3269);
          }
          {
            lbits zgsz3265;
            CREATE(lbits)(&zgsz3265);
            CONVERT_OF(lbits, fbits)(&zgsz3265, zgaz3107, UINT64_C(6) , true);
            sail_int zgsz3266;
            CREATE(sail_int)(&zgsz3266);
            CONVERT_OF(sail_int, mach_int)(&zgsz3266, zgaz3108);
            sail_int zgsz3267;
            CREATE(sail_int)(&zgsz3267);
            CONVERT_OF(sail_int, mach_int)(&zgsz3267, INT64_C(3));
            lbits zgsz3268;
            CREATE(lbits)(&zgsz3268);
            vector_subrange_lbits(&zgsz3268, zgsz3265, zgsz3266, zgsz3267);
            zgaz3109 = CONVERT_OF(fbits, lbits)(zgsz3268, true);
            KILL(lbits)(&zgsz3268);
            KILL(sail_int)(&zgsz3267);
            KILL(sail_int)(&zgsz3266);
            KILL(lbits)(&zgsz3265);
          }
        }
        uint64_t zgaz3110;
        {
          sail_int zgsz3275;
          CREATE(sail_int)(&zgsz3275);
          CONVERT_OF(sail_int, mach_int)(&zgsz3275, zinternal_E_take_bits);
          lbits zgsz3276;
          CREATE(lbits)(&zgsz3276);
          sailgen_zzeros_implicit(&zgsz3276, zgsz3275);
          zgaz3110 = CONVERT_OF(fbits, lbits)(zgsz3276, true);
          KILL(lbits)(&zgsz3276);
          KILL(sail_int)(&zgsz3275);
        }
        {
          lbits zgsz3272;
          CREATE(lbits)(&zgsz3272);
          CONVERT_OF(lbits, fbits)(&zgsz3272, zgaz3109, UINT64_C(3) , true);
          lbits zgsz3273;
          CREATE(lbits)(&zgsz3273);
          CONVERT_OF(lbits, fbits)(&zgsz3273, zgaz3110, UINT64_C(3) , true);
          lbits zgsz3274;
          CREATE(lbits)(&zgsz3274);
          append(&zgsz3274, zgsz3272, zgsz3273);
          zT = CONVERT_OF(fbits, lbits)(zgsz3274, true);
          KILL(lbits)(&zgsz3274);
          KILL(lbits)(&zgsz3273);
          KILL(lbits)(&zgsz3272);
        }
        unit zgsz339;
        zgsz339 = UNIT;
      }
      uint64_t zgaz3113;
      {
        uint64_t zgaz3111;
        zgaz3111 = zc.zB;
        int64_t zgaz3112;
        {
          sail_int zgsz3281;
          CREATE(sail_int)(&zgsz3281);
          CONVERT_OF(sail_int, mach_int)(&zgsz3281, zcap_mantissa_width);
          sail_int zgsz3282;
          CREATE(sail_int)(&zgsz3282);
          CONVERT_OF(sail_int, mach_int)(&zgsz3282, INT64_C(1));
          sail_int zgsz3283;
          CREATE(sail_int)(&zgsz3283);
          sub_int(&zgsz3283, zgsz3281, zgsz3282);
          zgaz3112 = CONVERT_OF(mach_int, sail_int)(zgsz3283);
          KILL(sail_int)(&zgsz3283);
          KILL(sail_int)(&zgsz3282);
          KILL(sail_int)(&zgsz3281);
        }
        {
          lbits zgsz3277;
          CREATE(lbits)(&zgsz3277);
          CONVERT_OF(lbits, fbits)(&zgsz3277, zgaz3111, UINT64_C(8) , true);
          sail_int zgsz3278;
          CREATE(sail_int)(&zgsz3278);
          CONVERT_OF(sail_int, mach_int)(&zgsz3278, zgaz3112);
          sail_int zgsz3279;
          CREATE(sail_int)(&zgsz3279);
          CONVERT_OF(sail_int, mach_int)(&zgsz3279, INT64_C(3));
          lbits zgsz3280;
          CREATE(lbits)(&zgsz3280);
          vector_subrange_lbits(&zgsz3280, zgsz3277, zgsz3278, zgsz3279);
          zgaz3113 = CONVERT_OF(fbits, lbits)(zgsz3280, true);
          KILL(lbits)(&zgsz3280);
          KILL(sail_int)(&zgsz3279);
          KILL(sail_int)(&zgsz3278);
          KILL(lbits)(&zgsz3277);
        }
      }
      uint64_t zgaz3114;
      {
        sail_int zgsz3287;
        CREATE(sail_int)(&zgsz3287);
        CONVERT_OF(sail_int, mach_int)(&zgsz3287, zinternal_E_take_bits);
        lbits zgsz3288;
        CREATE(lbits)(&zgsz3288);
        sailgen_zzeros_implicit(&zgsz3288, zgsz3287);
        zgaz3114 = CONVERT_OF(fbits, lbits)(zgsz3288, true);
        KILL(lbits)(&zgsz3288);
        KILL(sail_int)(&zgsz3287);
      }
      {
        lbits zgsz3284;
        CREATE(lbits)(&zgsz3284);
        CONVERT_OF(lbits, fbits)(&zgsz3284, zgaz3113, UINT64_C(5) , true);
        lbits zgsz3285;
        CREATE(lbits)(&zgsz3285);
        CONVERT_OF(lbits, fbits)(&zgsz3285, zgaz3114, UINT64_C(3) , true);
        lbits zgsz3286;
        CREATE(lbits)(&zgsz3286);
        append(&zgsz3286, zgsz3284, zgsz3285);
        zBs = CONVERT_OF(fbits, lbits)(zgsz3286, true);
        KILL(lbits)(&zgsz3286);
        KILL(lbits)(&zgsz3285);
        KILL(lbits)(&zgsz3284);
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
    bool zgaz3170;
    {
      uint64_t zgaz3169;
      {
        int64_t zgaz3168;
        {
          sail_int zgsz3293;
          CREATE(sail_int)(&zgsz3293);
          CONVERT_OF(sail_int, mach_int)(&zgsz3293, zcap_mantissa_width);
          sail_int zgsz3294;
          CREATE(sail_int)(&zgsz3294);
          CONVERT_OF(sail_int, mach_int)(&zgsz3294, INT64_C(3));
          sail_int zgsz3295;
          CREATE(sail_int)(&zgsz3295);
          sub_int(&zgsz3295, zgsz3293, zgsz3294);
          zgaz3168 = CONVERT_OF(mach_int, sail_int)(zgsz3295);
          KILL(sail_int)(&zgsz3295);
          KILL(sail_int)(&zgsz3294);
          KILL(sail_int)(&zgsz3293);
        }
        {
          lbits zgsz3289;
          CREATE(lbits)(&zgsz3289);
          CONVERT_OF(lbits, fbits)(&zgsz3289, zBs, UINT64_C(8) , true);
          sail_int zgsz3290;
          CREATE(sail_int)(&zgsz3290);
          CONVERT_OF(sail_int, mach_int)(&zgsz3290, zgaz3168);
          sail_int zgsz3291;
          CREATE(sail_int)(&zgsz3291);
          CONVERT_OF(sail_int, mach_int)(&zgsz3291, INT64_C(0));
          lbits zgsz3292;
          CREATE(lbits)(&zgsz3292);
          vector_subrange_lbits(&zgsz3292, zgsz3289, zgsz3290, zgsz3291);
          zgaz3169 = CONVERT_OF(fbits, lbits)(zgsz3292, true);
          KILL(lbits)(&zgsz3292);
          KILL(sail_int)(&zgsz3291);
          KILL(sail_int)(&zgsz3290);
          KILL(lbits)(&zgsz3289);
        }
      }
      {
        lbits zgsz3296;
        CREATE(lbits)(&zgsz3296);
        CONVERT_OF(lbits, fbits)(&zgsz3296, zT, UINT64_C(6) , true);
        lbits zgsz3297;
        CREATE(lbits)(&zgsz3297);
        CONVERT_OF(lbits, fbits)(&zgsz3297, zgaz3169, UINT64_C(6) , true);
        zgaz3170 = sailgen_z8operatorz0zI_uz9(zgsz3296, zgsz3297);
        KILL(lbits)(&zgsz3297);
        KILL(lbits)(&zgsz3296);
      }
    }
    if (zgaz3170) {  zcarry_out = UINT64_C(0b01);  } else {  zcarry_out = UINT64_C(0b00);  }
  }
  uint64_t zTtop2;
  {
    uint64_t zgaz3167;
    {
      uint64_t zgaz3166;
      {
        int64_t zgaz3164;
        {
          sail_int zgsz3305;
          CREATE(sail_int)(&zgsz3305);
          CONVERT_OF(sail_int, mach_int)(&zgsz3305, zcap_mantissa_width);
          sail_int zgsz3306;
          CREATE(sail_int)(&zgsz3306);
          CONVERT_OF(sail_int, mach_int)(&zgsz3306, INT64_C(1));
          sail_int zgsz3307;
          CREATE(sail_int)(&zgsz3307);
          sub_int(&zgsz3307, zgsz3305, zgsz3306);
          zgaz3164 = CONVERT_OF(mach_int, sail_int)(zgsz3307);
          KILL(sail_int)(&zgsz3307);
          KILL(sail_int)(&zgsz3306);
          KILL(sail_int)(&zgsz3305);
        }
        int64_t zgaz3165;
        {
          sail_int zgsz3302;
          CREATE(sail_int)(&zgsz3302);
          CONVERT_OF(sail_int, mach_int)(&zgsz3302, zcap_mantissa_width);
          sail_int zgsz3303;
          CREATE(sail_int)(&zgsz3303);
          CONVERT_OF(sail_int, mach_int)(&zgsz3303, INT64_C(2));
          sail_int zgsz3304;
          CREATE(sail_int)(&zgsz3304);
          sub_int(&zgsz3304, zgsz3302, zgsz3303);
          zgaz3165 = CONVERT_OF(mach_int, sail_int)(zgsz3304);
          KILL(sail_int)(&zgsz3304);
          KILL(sail_int)(&zgsz3303);
          KILL(sail_int)(&zgsz3302);
        }
        {
          lbits zgsz3298;
          CREATE(lbits)(&zgsz3298);
          CONVERT_OF(lbits, fbits)(&zgsz3298, zBs, UINT64_C(8) , true);
          sail_int zgsz3299;
          CREATE(sail_int)(&zgsz3299);
          CONVERT_OF(sail_int, mach_int)(&zgsz3299, zgaz3164);
          sail_int zgsz3300;
          CREATE(sail_int)(&zgsz3300);
          CONVERT_OF(sail_int, mach_int)(&zgsz3300, zgaz3165);
          lbits zgsz3301;
          CREATE(lbits)(&zgsz3301);
          vector_subrange_lbits(&zgsz3301, zgsz3298, zgsz3299, zgsz3300);
          zgaz3166 = CONVERT_OF(fbits, lbits)(zgsz3301, true);
          KILL(lbits)(&zgsz3301);
          KILL(sail_int)(&zgsz3300);
          KILL(sail_int)(&zgsz3299);
          KILL(lbits)(&zgsz3298);
        }
      }
      {
        lbits zgsz3308;
        CREATE(lbits)(&zgsz3308);
        CONVERT_OF(lbits, fbits)(&zgsz3308, zgaz3166, UINT64_C(2) , true);
        lbits zgsz3309;
        CREATE(lbits)(&zgsz3309);
        CONVERT_OF(lbits, fbits)(&zgsz3309, zlenMSBs, UINT64_C(2) , true);
        lbits zgsz3310;
        CREATE(lbits)(&zgsz3310);
        add_bits(&zgsz3310, zgsz3308, zgsz3309);
        zgaz3167 = CONVERT_OF(fbits, lbits)(zgsz3310, true);
        KILL(lbits)(&zgsz3310);
        KILL(lbits)(&zgsz3309);
        KILL(lbits)(&zgsz3308);
      }
    }
    {
      lbits zgsz3311;
      CREATE(lbits)(&zgsz3311);
      CONVERT_OF(lbits, fbits)(&zgsz3311, zgaz3167, UINT64_C(2) , true);
      lbits zgsz3312;
      CREATE(lbits)(&zgsz3312);
      CONVERT_OF(lbits, fbits)(&zgsz3312, zcarry_out, UINT64_C(2) , true);
      lbits zgsz3313;
      CREATE(lbits)(&zgsz3313);
      add_bits(&zgsz3313, zgsz3311, zgsz3312);
      zTtop2 = CONVERT_OF(fbits, lbits)(zgsz3313, true);
      KILL(lbits)(&zgsz3313);
      KILL(lbits)(&zgsz3312);
      KILL(lbits)(&zgsz3311);
    }
  }
  struct zCapability zgaz3163;
  {
    uint64_t zgaz3119;
    {
      bool zgaz3115;
      {
        sail_int zgsz3314;
        CREATE(sail_int)(&zgsz3314);
        CONVERT_OF(sail_int, mach_int)(&zgsz3314, zcap_uperms_width);
        sail_int zgsz3315;
        CREATE(sail_int)(&zgsz3315);
        CONVERT_OF(sail_int, mach_int)(&zgsz3315, INT64_C(0));
        zgaz3115 = gt(zgsz3314, zgsz3315);
        KILL(sail_int)(&zgsz3315);
        KILL(sail_int)(&zgsz3314);
      }
      zgaz3119 = UINT64_C(0);
    }
    bool zgaz3122;
    {
      fbits zgaz3121;
      {
        uint64_t zgaz3120;
        zgaz3120 = zc.zperms;
        {
          lbits zgsz3316;
          CREATE(lbits)(&zgsz3316);
          CONVERT_OF(lbits, fbits)(&zgsz3316, zgaz3120, UINT64_C(12) , true);
          sail_int zgsz3317;
          CREATE(sail_int)(&zgsz3317);
          CONVERT_OF(sail_int, mach_int)(&zgsz3317, INT64_C(11));
          zgaz3121 = bitvector_access(zgsz3316, zgsz3317);
          KILL(sail_int)(&zgsz3317);
          KILL(lbits)(&zgsz3316);
        }
      }
      zgaz3122 = sailgen_bit_to_bool(zgaz3121);
    }
    bool zgaz3125;
    {
      fbits zgaz3124;
      {
        uint64_t zgaz3123;
        zgaz3123 = zc.zperms;
        {
          lbits zgsz3318;
          CREATE(lbits)(&zgsz3318);
          CONVERT_OF(lbits, fbits)(&zgsz3318, zgaz3123, UINT64_C(12) , true);
          sail_int zgsz3319;
          CREATE(sail_int)(&zgsz3319);
          CONVERT_OF(sail_int, mach_int)(&zgsz3319, INT64_C(10));
          zgaz3124 = bitvector_access(zgsz3318, zgsz3319);
          KILL(sail_int)(&zgsz3319);
          KILL(lbits)(&zgsz3318);
        }
      }
      zgaz3125 = sailgen_bit_to_bool(zgaz3124);
    }
    bool zgaz3128;
    {
      fbits zgaz3127;
      {
        uint64_t zgaz3126;
        zgaz3126 = zc.zperms;
        {
          lbits zgsz3320;
          CREATE(lbits)(&zgsz3320);
          CONVERT_OF(lbits, fbits)(&zgsz3320, zgaz3126, UINT64_C(12) , true);
          sail_int zgsz3321;
          CREATE(sail_int)(&zgsz3321);
          CONVERT_OF(sail_int, mach_int)(&zgsz3321, INT64_C(9));
          zgaz3127 = bitvector_access(zgsz3320, zgsz3321);
          KILL(sail_int)(&zgsz3321);
          KILL(lbits)(&zgsz3320);
        }
      }
      zgaz3128 = sailgen_bit_to_bool(zgaz3127);
    }
    bool zgaz3131;
    {
      fbits zgaz3130;
      {
        uint64_t zgaz3129;
        zgaz3129 = zc.zperms;
        {
          lbits zgsz3322;
          CREATE(lbits)(&zgsz3322);
          CONVERT_OF(lbits, fbits)(&zgsz3322, zgaz3129, UINT64_C(12) , true);
          sail_int zgsz3323;
          CREATE(sail_int)(&zgsz3323);
          CONVERT_OF(sail_int, mach_int)(&zgsz3323, INT64_C(8));
          zgaz3130 = bitvector_access(zgsz3322, zgsz3323);
          KILL(sail_int)(&zgsz3323);
          KILL(lbits)(&zgsz3322);
        }
      }
      zgaz3131 = sailgen_bit_to_bool(zgaz3130);
    }
    bool zgaz3134;
    {
      fbits zgaz3133;
      {
        uint64_t zgaz3132;
        zgaz3132 = zc.zperms;
        {
          lbits zgsz3324;
          CREATE(lbits)(&zgsz3324);
          CONVERT_OF(lbits, fbits)(&zgsz3324, zgaz3132, UINT64_C(12) , true);
          sail_int zgsz3325;
          CREATE(sail_int)(&zgsz3325);
          CONVERT_OF(sail_int, mach_int)(&zgsz3325, INT64_C(7));
          zgaz3133 = bitvector_access(zgsz3324, zgsz3325);
          KILL(sail_int)(&zgsz3325);
          KILL(lbits)(&zgsz3324);
        }
      }
      zgaz3134 = sailgen_bit_to_bool(zgaz3133);
    }
    bool zgaz3137;
    {
      fbits zgaz3136;
      {
        uint64_t zgaz3135;
        zgaz3135 = zc.zperms;
        {
          lbits zgsz3326;
          CREATE(lbits)(&zgsz3326);
          CONVERT_OF(lbits, fbits)(&zgsz3326, zgaz3135, UINT64_C(12) , true);
          sail_int zgsz3327;
          CREATE(sail_int)(&zgsz3327);
          CONVERT_OF(sail_int, mach_int)(&zgsz3327, INT64_C(6));
          zgaz3136 = bitvector_access(zgsz3326, zgsz3327);
          KILL(sail_int)(&zgsz3327);
          KILL(lbits)(&zgsz3326);
        }
      }
      zgaz3137 = sailgen_bit_to_bool(zgaz3136);
    }
    bool zgaz3140;
    {
      fbits zgaz3139;
      {
        uint64_t zgaz3138;
        zgaz3138 = zc.zperms;
        {
          lbits zgsz3328;
          CREATE(lbits)(&zgsz3328);
          CONVERT_OF(lbits, fbits)(&zgsz3328, zgaz3138, UINT64_C(12) , true);
          sail_int zgsz3329;
          CREATE(sail_int)(&zgsz3329);
          CONVERT_OF(sail_int, mach_int)(&zgsz3329, INT64_C(5));
          zgaz3139 = bitvector_access(zgsz3328, zgsz3329);
          KILL(sail_int)(&zgsz3329);
          KILL(lbits)(&zgsz3328);
        }
      }
      zgaz3140 = sailgen_bit_to_bool(zgaz3139);
    }
    bool zgaz3143;
    {
      fbits zgaz3142;
      {
        uint64_t zgaz3141;
        zgaz3141 = zc.zperms;
        {
          lbits zgsz3330;
          CREATE(lbits)(&zgsz3330);
          CONVERT_OF(lbits, fbits)(&zgsz3330, zgaz3141, UINT64_C(12) , true);
          sail_int zgsz3331;
          CREATE(sail_int)(&zgsz3331);
          CONVERT_OF(sail_int, mach_int)(&zgsz3331, INT64_C(4));
          zgaz3142 = bitvector_access(zgsz3330, zgsz3331);
          KILL(sail_int)(&zgsz3331);
          KILL(lbits)(&zgsz3330);
        }
      }
      zgaz3143 = sailgen_bit_to_bool(zgaz3142);
    }
    bool zgaz3146;
    {
      fbits zgaz3145;
      {
        uint64_t zgaz3144;
        zgaz3144 = zc.zperms;
        {
          lbits zgsz3332;
          CREATE(lbits)(&zgsz3332);
          CONVERT_OF(lbits, fbits)(&zgsz3332, zgaz3144, UINT64_C(12) , true);
          sail_int zgsz3333;
          CREATE(sail_int)(&zgsz3333);
          CONVERT_OF(sail_int, mach_int)(&zgsz3333, INT64_C(3));
          zgaz3145 = bitvector_access(zgsz3332, zgsz3333);
          KILL(sail_int)(&zgsz3333);
          KILL(lbits)(&zgsz3332);
        }
      }
      zgaz3146 = sailgen_bit_to_bool(zgaz3145);
    }
    bool zgaz3149;
    {
      fbits zgaz3148;
      {
        uint64_t zgaz3147;
        zgaz3147 = zc.zperms;
        {
          lbits zgsz3334;
          CREATE(lbits)(&zgsz3334);
          CONVERT_OF(lbits, fbits)(&zgsz3334, zgaz3147, UINT64_C(12) , true);
          sail_int zgsz3335;
          CREATE(sail_int)(&zgsz3335);
          CONVERT_OF(sail_int, mach_int)(&zgsz3335, INT64_C(2));
          zgaz3148 = bitvector_access(zgsz3334, zgsz3335);
          KILL(sail_int)(&zgsz3335);
          KILL(lbits)(&zgsz3334);
        }
      }
      zgaz3149 = sailgen_bit_to_bool(zgaz3148);
    }
    bool zgaz3152;
    {
      fbits zgaz3151;
      {
        uint64_t zgaz3150;
        zgaz3150 = zc.zperms;
        {
          lbits zgsz3336;
          CREATE(lbits)(&zgsz3336);
          CONVERT_OF(lbits, fbits)(&zgsz3336, zgaz3150, UINT64_C(12) , true);
          sail_int zgsz3337;
          CREATE(sail_int)(&zgsz3337);
          CONVERT_OF(sail_int, mach_int)(&zgsz3337, INT64_C(1));
          zgaz3151 = bitvector_access(zgsz3336, zgsz3337);
          KILL(sail_int)(&zgsz3337);
          KILL(lbits)(&zgsz3336);
        }
      }
      zgaz3152 = sailgen_bit_to_bool(zgaz3151);
    }
    bool zgaz3155;
    {
      fbits zgaz3154;
      {
        uint64_t zgaz3153;
        zgaz3153 = zc.zperms;
        {
          lbits zgsz3338;
          CREATE(lbits)(&zgsz3338);
          CONVERT_OF(lbits, fbits)(&zgsz3338, zgaz3153, UINT64_C(12) , true);
          sail_int zgsz3339;
          CREATE(sail_int)(&zgsz3339);
          CONVERT_OF(sail_int, mach_int)(&zgsz3339, INT64_C(0));
          zgaz3154 = bitvector_access(zgsz3338, zgsz3339);
          KILL(sail_int)(&zgsz3339);
          KILL(lbits)(&zgsz3338);
        }
      }
      zgaz3155 = sailgen_bit_to_bool(zgaz3154);
    }
    uint64_t zgaz3156;
    zgaz3156 = zc.zreserved;
    bool zgaz3159;
    {
      fbits zgaz3158;
      {
        uint64_t zgaz3157;
        zgaz3157 = zc.zflags;
        {
          lbits zgsz3340;
          CREATE(lbits)(&zgsz3340);
          CONVERT_OF(lbits, fbits)(&zgsz3340, zgaz3157, UINT64_C(1) , true);
          sail_int zgsz3341;
          CREATE(sail_int)(&zgsz3341);
          CONVERT_OF(sail_int, mach_int)(&zgsz3341, INT64_C(0));
          zgaz3158 = bitvector_access(zgsz3340, zgsz3341);
          KILL(sail_int)(&zgsz3341);
          KILL(lbits)(&zgsz3340);
        }
      }
      zgaz3159 = sailgen_bit_to_bool(zgaz3158);
    }
    uint64_t zgaz3160;
    {
      lbits zgsz3342;
      CREATE(lbits)(&zgsz3342);
      CONVERT_OF(lbits, fbits)(&zgsz3342, zTtop2, UINT64_C(2) , true);
      lbits zgsz3343;
      CREATE(lbits)(&zgsz3343);
      CONVERT_OF(lbits, fbits)(&zgsz3343, zT, UINT64_C(6) , true);
      lbits zgsz3344;
      CREATE(lbits)(&zgsz3344);
      append(&zgsz3344, zgsz3342, zgsz3343);
      zgaz3160 = CONVERT_OF(fbits, lbits)(zgsz3344, true);
      KILL(lbits)(&zgsz3344);
      KILL(lbits)(&zgsz3343);
      KILL(lbits)(&zgsz3342);
    }
    uint64_t zgaz3161;
    zgaz3161 = zc.zotype;
    uint64_t zgaz3162;
    zgaz3162 = zc.zaddress;
    struct zCapability zgsz342;
    zgsz342.zB = zBs;
    zgsz342.zE = zE;
    zgsz342.zT = zgaz3160;
    zgsz342.zaccess_system_regs = zgaz3125;
    zgsz342.zaddress = zgaz3162;
    zgsz342.zflag_cap_mode = zgaz3159;
    zgsz342.zglobal = zgaz3155;
    zgsz342.zinternal_E = zinternal_E;
    zgsz342.zotype = zgaz3161;
    zgsz342.zpermit_cinvoke = zgaz3131;
    zgsz342.zpermit_execute = zgaz3152;
    zgsz342.zpermit_load = zgaz3149;
    zgsz342.zpermit_load_cap = zgaz3143;
    zgsz342.zpermit_seal = zgaz3134;
    zgsz342.zpermit_set_CID = zgaz3122;
    zgsz342.zpermit_store = zgaz3146;
    zgsz342.zpermit_store_cap = zgaz3140;
    zgsz342.zpermit_store_local_cap = zgaz3137;
    zgsz342.zpermit_unseal = zgaz3128;
    zgsz342.zreserved = zgaz3156;
    zgsz342.ztag = zt;
    zgsz342.zuperms = zgaz3119;
    zgaz3163 = zgsz342;
  }
  zcbz318 = zgaz3163;
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

static struct zCapability sailgen_capBitsToCapability(bool, uint64_t);

static struct zCapability sailgen_capBitsToCapability(bool zt, uint64_t zc)
{
  __label__ end_function_90, end_block_exception_91;

  struct zCapability zcbz319;
  struct zEncCapability zgaz3172;
  zgaz3172 = sailgen_capBitsToEncCapability(zc);
  zcbz319 = sailgen_encCapabilityToCapability(zt, zgaz3172);

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
    uint64_t zgaz3199;
    zgaz3199 = zcap.zT;
    int64_t zgaz3200;
    {
      sail_int zgsz3357;
      CREATE(sail_int)(&zgsz3357);
      CONVERT_OF(sail_int, mach_int)(&zgsz3357, zcap_mantissa_width);
      sail_int zgsz3358;
      CREATE(sail_int)(&zgsz3358);
      CONVERT_OF(sail_int, mach_int)(&zgsz3358, INT64_C(3));
      sail_int zgsz3359;
      CREATE(sail_int)(&zgsz3359);
      sub_int(&zgsz3359, zgsz3357, zgsz3358);
      zgaz3200 = CONVERT_OF(mach_int, sail_int)(zgsz3359);
      KILL(sail_int)(&zgsz3359);
      KILL(sail_int)(&zgsz3358);
      KILL(sail_int)(&zgsz3357);
    }
    {
      lbits zgsz3353;
      CREATE(lbits)(&zgsz3353);
      CONVERT_OF(lbits, fbits)(&zgsz3353, zgaz3199, UINT64_C(8) , true);
      sail_int zgsz3354;
      CREATE(sail_int)(&zgsz3354);
      CONVERT_OF(sail_int, mach_int)(&zgsz3354, zgaz3200);
      sail_int zgsz3355;
      CREATE(sail_int)(&zgsz3355);
      CONVERT_OF(sail_int, mach_int)(&zgsz3355, zinternal_E_take_bits);
      lbits zgsz3356;
      CREATE(lbits)(&zgsz3356);
      vector_subrange_lbits(&zgsz3356, zgsz3353, zgsz3354, zgsz3355);
      zt_hi = CONVERT_OF(fbits, lbits)(zgsz3356, true);
      KILL(lbits)(&zgsz3356);
      KILL(sail_int)(&zgsz3355);
      KILL(sail_int)(&zgsz3354);
      KILL(lbits)(&zgsz3353);
    }
  }
  uint64_t zt_lo;
  {
    uint64_t zgaz3197;
    zgaz3197 = zcap.zT;
    int64_t zgaz3198;
    {
      sail_int zgsz3364;
      CREATE(sail_int)(&zgsz3364);
      CONVERT_OF(sail_int, mach_int)(&zgsz3364, zinternal_E_take_bits);
      sail_int zgsz3365;
      CREATE(sail_int)(&zgsz3365);
      CONVERT_OF(sail_int, mach_int)(&zgsz3365, INT64_C(1));
      sail_int zgsz3366;
      CREATE(sail_int)(&zgsz3366);
      sub_int(&zgsz3366, zgsz3364, zgsz3365);
      zgaz3198 = CONVERT_OF(mach_int, sail_int)(zgsz3366);
      KILL(sail_int)(&zgsz3366);
      KILL(sail_int)(&zgsz3365);
      KILL(sail_int)(&zgsz3364);
    }
    {
      lbits zgsz3360;
      CREATE(lbits)(&zgsz3360);
      CONVERT_OF(lbits, fbits)(&zgsz3360, zgaz3197, UINT64_C(8) , true);
      sail_int zgsz3361;
      CREATE(sail_int)(&zgsz3361);
      CONVERT_OF(sail_int, mach_int)(&zgsz3361, zgaz3198);
      sail_int zgsz3362;
      CREATE(sail_int)(&zgsz3362);
      CONVERT_OF(sail_int, mach_int)(&zgsz3362, INT64_C(0));
      lbits zgsz3363;
      CREATE(lbits)(&zgsz3363);
      vector_subrange_lbits(&zgsz3363, zgsz3360, zgsz3361, zgsz3362);
      zt_lo = CONVERT_OF(fbits, lbits)(zgsz3363, true);
      KILL(lbits)(&zgsz3363);
      KILL(sail_int)(&zgsz3362);
      KILL(sail_int)(&zgsz3361);
      KILL(lbits)(&zgsz3360);
    }
  }
  uint64_t zb_hi;
  {
    uint64_t zgaz3195;
    zgaz3195 = zcap.zB;
    int64_t zgaz3196;
    {
      sail_int zgsz3371;
      CREATE(sail_int)(&zgsz3371);
      CONVERT_OF(sail_int, mach_int)(&zgsz3371, zcap_mantissa_width);
      sail_int zgsz3372;
      CREATE(sail_int)(&zgsz3372);
      CONVERT_OF(sail_int, mach_int)(&zgsz3372, INT64_C(1));
      sail_int zgsz3373;
      CREATE(sail_int)(&zgsz3373);
      sub_int(&zgsz3373, zgsz3371, zgsz3372);
      zgaz3196 = CONVERT_OF(mach_int, sail_int)(zgsz3373);
      KILL(sail_int)(&zgsz3373);
      KILL(sail_int)(&zgsz3372);
      KILL(sail_int)(&zgsz3371);
    }
    {
      lbits zgsz3367;
      CREATE(lbits)(&zgsz3367);
      CONVERT_OF(lbits, fbits)(&zgsz3367, zgaz3195, UINT64_C(8) , true);
      sail_int zgsz3368;
      CREATE(sail_int)(&zgsz3368);
      CONVERT_OF(sail_int, mach_int)(&zgsz3368, zgaz3196);
      sail_int zgsz3369;
      CREATE(sail_int)(&zgsz3369);
      CONVERT_OF(sail_int, mach_int)(&zgsz3369, zinternal_E_take_bits);
      lbits zgsz3370;
      CREATE(lbits)(&zgsz3370);
      vector_subrange_lbits(&zgsz3370, zgsz3367, zgsz3368, zgsz3369);
      zb_hi = CONVERT_OF(fbits, lbits)(zgsz3370, true);
      KILL(lbits)(&zgsz3370);
      KILL(sail_int)(&zgsz3369);
      KILL(sail_int)(&zgsz3368);
      KILL(lbits)(&zgsz3367);
    }
  }
  uint64_t zb_lo;
  {
    uint64_t zgaz3193;
    zgaz3193 = zcap.zB;
    int64_t zgaz3194;
    {
      sail_int zgsz3378;
      CREATE(sail_int)(&zgsz3378);
      CONVERT_OF(sail_int, mach_int)(&zgsz3378, zinternal_E_take_bits);
      sail_int zgsz3379;
      CREATE(sail_int)(&zgsz3379);
      CONVERT_OF(sail_int, mach_int)(&zgsz3379, INT64_C(1));
      sail_int zgsz3380;
      CREATE(sail_int)(&zgsz3380);
      sub_int(&zgsz3380, zgsz3378, zgsz3379);
      zgaz3194 = CONVERT_OF(mach_int, sail_int)(zgsz3380);
      KILL(sail_int)(&zgsz3380);
      KILL(sail_int)(&zgsz3379);
      KILL(sail_int)(&zgsz3378);
    }
    {
      lbits zgsz3374;
      CREATE(lbits)(&zgsz3374);
      CONVERT_OF(lbits, fbits)(&zgsz3374, zgaz3193, UINT64_C(8) , true);
      sail_int zgsz3375;
      CREATE(sail_int)(&zgsz3375);
      CONVERT_OF(sail_int, mach_int)(&zgsz3375, zgaz3194);
      sail_int zgsz3376;
      CREATE(sail_int)(&zgsz3376);
      CONVERT_OF(sail_int, mach_int)(&zgsz3376, INT64_C(0));
      lbits zgsz3377;
      CREATE(lbits)(&zgsz3377);
      vector_subrange_lbits(&zgsz3377, zgsz3374, zgsz3375, zgsz3376);
      zb_lo = CONVERT_OF(fbits, lbits)(zgsz3377, true);
      KILL(lbits)(&zgsz3377);
      KILL(sail_int)(&zgsz3376);
      KILL(sail_int)(&zgsz3375);
      KILL(lbits)(&zgsz3374);
    }
  }
  {
    bool zgaz3173;
    zgaz3173 = zcap.zinternal_E;
    unit zgsz343;
    if (zgaz3173) {
      {
        uint64_t zgaz3175;
        zgaz3175 = zcap.zE;
        int64_t zgaz3176;
        {
          int64_t zgaz3174;
          {
            sail_int zgsz3384;
            CREATE(sail_int)(&zgsz3384);
            CONVERT_OF(sail_int, mach_int)(&zgsz3384, INT64_C(2));
            sail_int zgsz3385;
            CREATE(sail_int)(&zgsz3385);
            CONVERT_OF(sail_int, mach_int)(&zgsz3385, zinternal_E_take_bits);
            sail_int zgsz3386;
            CREATE(sail_int)(&zgsz3386);
            mult_int(&zgsz3386, zgsz3384, zgsz3385);
            zgaz3174 = CONVERT_OF(mach_int, sail_int)(zgsz3386);
            KILL(sail_int)(&zgsz3386);
            KILL(sail_int)(&zgsz3385);
            KILL(sail_int)(&zgsz3384);
          }
          {
            sail_int zgsz3381;
            CREATE(sail_int)(&zgsz3381);
            CONVERT_OF(sail_int, mach_int)(&zgsz3381, zgaz3174);
            sail_int zgsz3382;
            CREATE(sail_int)(&zgsz3382);
            CONVERT_OF(sail_int, mach_int)(&zgsz3382, INT64_C(1));
            sail_int zgsz3383;
            CREATE(sail_int)(&zgsz3383);
            sub_int(&zgsz3383, zgsz3381, zgsz3382);
            zgaz3176 = CONVERT_OF(mach_int, sail_int)(zgsz3383);
            KILL(sail_int)(&zgsz3383);
            KILL(sail_int)(&zgsz3382);
            KILL(sail_int)(&zgsz3381);
          }
        }
        {
          lbits zgsz3387;
          CREATE(lbits)(&zgsz3387);
          CONVERT_OF(lbits, fbits)(&zgsz3387, zgaz3175, UINT64_C(6) , true);
          sail_int zgsz3388;
          CREATE(sail_int)(&zgsz3388);
          CONVERT_OF(sail_int, mach_int)(&zgsz3388, zgaz3176);
          sail_int zgsz3389;
          CREATE(sail_int)(&zgsz3389);
          CONVERT_OF(sail_int, mach_int)(&zgsz3389, zinternal_E_take_bits);
          lbits zgsz3390;
          CREATE(lbits)(&zgsz3390);
          vector_subrange_lbits(&zgsz3390, zgsz3387, zgsz3388, zgsz3389);
          zt_lo = CONVERT_OF(fbits, lbits)(zgsz3390, true);
          KILL(lbits)(&zgsz3390);
          KILL(sail_int)(&zgsz3389);
          KILL(sail_int)(&zgsz3388);
          KILL(lbits)(&zgsz3387);
        }
        unit zgsz344;
        zgsz344 = UNIT;
      }
      uint64_t zgaz3177;
      zgaz3177 = zcap.zE;
      int64_t zgaz3178;
      {
        sail_int zgsz3395;
        CREATE(sail_int)(&zgsz3395);
        CONVERT_OF(sail_int, mach_int)(&zgsz3395, zinternal_E_take_bits);
        sail_int zgsz3396;
        CREATE(sail_int)(&zgsz3396);
        CONVERT_OF(sail_int, mach_int)(&zgsz3396, INT64_C(1));
        sail_int zgsz3397;
        CREATE(sail_int)(&zgsz3397);
        sub_int(&zgsz3397, zgsz3395, zgsz3396);
        zgaz3178 = CONVERT_OF(mach_int, sail_int)(zgsz3397);
        KILL(sail_int)(&zgsz3397);
        KILL(sail_int)(&zgsz3396);
        KILL(sail_int)(&zgsz3395);
      }
      {
        lbits zgsz3391;
        CREATE(lbits)(&zgsz3391);
        CONVERT_OF(lbits, fbits)(&zgsz3391, zgaz3177, UINT64_C(6) , true);
        sail_int zgsz3392;
        CREATE(sail_int)(&zgsz3392);
        CONVERT_OF(sail_int, mach_int)(&zgsz3392, zgaz3178);
        sail_int zgsz3393;
        CREATE(sail_int)(&zgsz3393);
        CONVERT_OF(sail_int, mach_int)(&zgsz3393, INT64_C(0));
        lbits zgsz3394;
        CREATE(lbits)(&zgsz3394);
        vector_subrange_lbits(&zgsz3394, zgsz3391, zgsz3392, zgsz3393);
        zb_lo = CONVERT_OF(fbits, lbits)(zgsz3394, true);
        KILL(lbits)(&zgsz3394);
        KILL(sail_int)(&zgsz3393);
        KILL(sail_int)(&zgsz3392);
        KILL(lbits)(&zgsz3391);
      }
      zgsz343 = UNIT;
    } else {  zgsz343 = UNIT;  }
  }
  struct zEncCapability zgaz3192;
  {
    uint64_t zgaz3181;
    {
      uint64_t zgaz3179;
      zgaz3179 = zcap.zuperms;
      uint64_t zgaz3180;
      zgaz3180 = sailgen_getCapHardPerms(zcap);
      {
        lbits zgsz3398;
        CREATE(lbits)(&zgsz3398);
        CONVERT_OF(lbits, fbits)(&zgsz3398, zgaz3179, UINT64_C(0) , true);
        lbits zgsz3399;
        CREATE(lbits)(&zgsz3399);
        CONVERT_OF(lbits, fbits)(&zgsz3399, zgaz3180, UINT64_C(12) , true);
        lbits zgsz3400;
        CREATE(lbits)(&zgsz3400);
        append(&zgsz3400, zgsz3398, zgsz3399);
        zgaz3181 = CONVERT_OF(fbits, lbits)(zgsz3400, true);
        KILL(lbits)(&zgsz3400);
        KILL(lbits)(&zgsz3399);
        KILL(lbits)(&zgsz3398);
      }
    }
    uint64_t zgaz3182;
    zgaz3182 = zcap.zreserved;
    uint64_t zgaz3184;
    {
      bool zgaz3183;
      zgaz3183 = zcap.zflag_cap_mode;
      zgaz3184 = sailgen_bool_to_bits(zgaz3183);
    }
    uint64_t zgaz3185;
    zgaz3185 = zcap.zotype;
    fbits zgaz3188;
    {
      uint64_t zgaz3187;
      {
        bool zgaz3186;
        zgaz3186 = zcap.zinternal_E;
        zgaz3187 = sailgen_bool_to_bits(zgaz3186);
      }
      {
        lbits zgsz3401;
        CREATE(lbits)(&zgsz3401);
        CONVERT_OF(lbits, fbits)(&zgsz3401, zgaz3187, UINT64_C(1) , true);
        sail_int zgsz3402;
        CREATE(sail_int)(&zgsz3402);
        CONVERT_OF(sail_int, mach_int)(&zgsz3402, INT64_C(0));
        zgaz3188 = bitvector_access(zgsz3401, zgsz3402);
        KILL(sail_int)(&zgsz3402);
        KILL(lbits)(&zgsz3401);
      }
    }
    uint64_t zgaz3189;
    {
      lbits zgsz3406;
      CREATE(lbits)(&zgsz3406);
      CONVERT_OF(lbits, fbits)(&zgsz3406, zt_hi, UINT64_C(3) , true);
      lbits zgsz3407;
      CREATE(lbits)(&zgsz3407);
      CONVERT_OF(lbits, fbits)(&zgsz3407, zt_lo, UINT64_C(3) , true);
      lbits zgsz3408;
      CREATE(lbits)(&zgsz3408);
      append(&zgsz3408, zgsz3406, zgsz3407);
      zgaz3189 = CONVERT_OF(fbits, lbits)(zgsz3408, true);
      KILL(lbits)(&zgsz3408);
      KILL(lbits)(&zgsz3407);
      KILL(lbits)(&zgsz3406);
    }
    uint64_t zgaz3190;
    {
      lbits zgsz3403;
      CREATE(lbits)(&zgsz3403);
      CONVERT_OF(lbits, fbits)(&zgsz3403, zb_hi, UINT64_C(5) , true);
      lbits zgsz3404;
      CREATE(lbits)(&zgsz3404);
      CONVERT_OF(lbits, fbits)(&zgsz3404, zb_lo, UINT64_C(3) , true);
      lbits zgsz3405;
      CREATE(lbits)(&zgsz3405);
      append(&zgsz3405, zgsz3403, zgsz3404);
      zgaz3190 = CONVERT_OF(fbits, lbits)(zgsz3405, true);
      KILL(lbits)(&zgsz3405);
      KILL(lbits)(&zgsz3404);
      KILL(lbits)(&zgsz3403);
    }
    uint64_t zgaz3191;
    zgaz3191 = zcap.zaddress;
    struct zEncCapability zgsz345;
    zgsz345.zB = zgaz3190;
    zgsz345.zT = zgaz3189;
    zgsz345.zaddress = zgaz3191;
    zgsz345.zflags = zgaz3184;
    zgsz345.zinternal_E = zgaz3188;
    zgsz345.zotype = zgaz3185;
    zgsz345.zperms = zgaz3181;
    zgsz345.zreserved = zgaz3182;
    zgaz3192 = zgsz345;
  }
  zcbz320 = zgaz3192;
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

static uint64_t sailgen_capToBits(struct zCapability);

static uint64_t sailgen_capToBits(struct zCapability zcap)
{
  __label__ end_function_98, end_block_exception_99;

  uint64_t zcbz321;
  struct zEncCapability zgaz3201;
  zgaz3201 = sailgen_capToEncCap(zcap);
  zcbz321 = sailgen_encCapToBits(zgaz3201);

end_function_98: ;
  return zcbz321;
end_block_exception_99: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t znull_cap_bits;
static void create_letbind_27(void) {


  uint64_t zgsz346;
  zgsz346 = sailgen_capToBits(znull_cap);
  znull_cap_bits = zgsz346;

let_end_100: ;
}
static void kill_letbind_27(void) {
}

static uint64_t sailgen_capToMemBits(struct zCapability);

static uint64_t sailgen_capToMemBits(struct zCapability zcap)
{
  __label__ end_function_102, end_block_exception_103;

  uint64_t zcbz322;
  uint64_t zgaz3202;
  zgaz3202 = sailgen_capToBits(zcap);
  {
    lbits zgsz3409;
    CREATE(lbits)(&zgsz3409);
    CONVERT_OF(lbits, fbits)(&zgsz3409, zgaz3202, UINT64_C(64) , true);
    lbits zgsz3410;
    CREATE(lbits)(&zgsz3410);
    CONVERT_OF(lbits, fbits)(&zgsz3410, znull_cap_bits, UINT64_C(64) , true);
    lbits zgsz3411;
    CREATE(lbits)(&zgsz3411);
    xor_bits(&zgsz3411, zgsz3409, zgsz3410);
    zcbz322 = CONVERT_OF(fbits, lbits)(zgsz3411, true);
    KILL(lbits)(&zgsz3411);
    KILL(lbits)(&zgsz3410);
    KILL(lbits)(&zgsz3409);
  }

end_function_102: ;
  return zcbz322;
end_block_exception_103: ;

  return UINT64_C(0xdeadc0de);
}

static struct zCapability sailgen_memBitsToCapability(bool, uint64_t);

static struct zCapability sailgen_memBitsToCapability(bool ztag, uint64_t zb)
{
  __label__ end_function_105, end_block_exception_106;

  struct zCapability zcbz323;
  uint64_t zgaz3203;
  {
    lbits zgsz3412;
    CREATE(lbits)(&zgsz3412);
    CONVERT_OF(lbits, fbits)(&zgsz3412, zb, UINT64_C(64) , true);
    lbits zgsz3413;
    CREATE(lbits)(&zgsz3413);
    CONVERT_OF(lbits, fbits)(&zgsz3413, znull_cap_bits, UINT64_C(64) , true);
    lbits zgsz3414;
    CREATE(lbits)(&zgsz3414);
    xor_bits(&zgsz3414, zgsz3412, zgsz3413);
    zgaz3203 = CONVERT_OF(fbits, lbits)(zgsz3414, true);
    KILL(lbits)(&zgsz3414);
    KILL(lbits)(&zgsz3413);
    KILL(lbits)(&zgsz3412);
  }
  zcbz323 = sailgen_capBitsToCapability(ztag, zgaz3203);

end_function_105: ;
  return zcbz323;
end_block_exception_106: ;
  struct zCapability zcbz351 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  return zcbz351;
}

// struct tuple_(%bv32, %bv33)
struct ztuple_z8z5bv32zCz0z5bv33z9 {
  uint64_t ztup0;
  uint64_t ztup1;
};

static void COPY(ztuple_z8z5bv32zCz0z5bv33z9)(struct ztuple_z8z5bv32zCz0z5bv33z9 *rop, const struct ztuple_z8z5bv32zCz0z5bv33z9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
}

static bool EQUAL(ztuple_z8z5bv32zCz0z5bv33z9)(struct ztuple_z8z5bv32zCz0z5bv33z9 op1, struct ztuple_z8z5bv32zCz0z5bv33z9 op2) {
  return EQUAL(fbits)(op1.ztup0, op2.ztup0) && EQUAL(fbits)(op1.ztup1, op2.ztup1);
}

static struct ztuple_z8z5bv32zCz0z5bv33z9 sailgen_getCapBoundsBits(struct zCapability);

static struct ztuple_z8z5bv32zCz0z5bv33z9 sailgen_getCapBoundsBits(struct zCapability zc)
{
  __label__ end_function_108, end_block_exception_109;

  struct ztuple_z8z5bv32zCz0z5bv33z9 zcbz324;
  int64_t zE;
  {
    int64_t zgaz3237;
    {
      uint64_t zgaz3236;
      zgaz3236 = zc.zE;
      {
        lbits zgsz3415;
        CREATE(lbits)(&zgsz3415);
        CONVERT_OF(lbits, fbits)(&zgsz3415, zgaz3236, UINT64_C(6) , true);
        sail_int zgsz3416;
        CREATE(sail_int)(&zgsz3416);
        sail_unsigned(&zgsz3416, zgsz3415);
        zgaz3237 = CONVERT_OF(mach_int, sail_int)(zgsz3416);
        KILL(sail_int)(&zgsz3416);
        KILL(lbits)(&zgsz3415);
      }
    }
    {
      sail_int zgsz3417;
      CREATE(sail_int)(&zgsz3417);
      CONVERT_OF(sail_int, mach_int)(&zgsz3417, zcap_max_E);
      sail_int zgsz3418;
      CREATE(sail_int)(&zgsz3418);
      CONVERT_OF(sail_int, mach_int)(&zgsz3418, zgaz3237);
      sail_int zgsz3419;
      CREATE(sail_int)(&zgsz3419);
      min_int(&zgsz3419, zgsz3417, zgsz3418);
      zE = CONVERT_OF(mach_int, sail_int)(zgsz3419);
      KILL(sail_int)(&zgsz3419);
      KILL(sail_int)(&zgsz3418);
      KILL(sail_int)(&zgsz3417);
    }
  }
  uint64_t za;
  za = zc.zaddress;
  uint64_t za3;
  {
    uint64_t zgaz3235;
    {
      int64_t zgaz3234;
      {
        int64_t zgaz3233;
        {
          sail_int zgsz3423;
          CREATE(sail_int)(&zgsz3423);
          CONVERT_OF(sail_int, mach_int)(&zgsz3423, zE);
          sail_int zgsz3424;
          CREATE(sail_int)(&zgsz3424);
          CONVERT_OF(sail_int, mach_int)(&zgsz3424, zcap_mantissa_width);
          sail_int zgsz3425;
          CREATE(sail_int)(&zgsz3425);
          add_int(&zgsz3425, zgsz3423, zgsz3424);
          zgaz3233 = CONVERT_OF(mach_int, sail_int)(zgsz3425);
          KILL(sail_int)(&zgsz3425);
          KILL(sail_int)(&zgsz3424);
          KILL(sail_int)(&zgsz3423);
        }
        {
          sail_int zgsz3420;
          CREATE(sail_int)(&zgsz3420);
          CONVERT_OF(sail_int, mach_int)(&zgsz3420, zgaz3233);
          sail_int zgsz3421;
          CREATE(sail_int)(&zgsz3421);
          CONVERT_OF(sail_int, mach_int)(&zgsz3421, INT64_C(3));
          sail_int zgsz3422;
          CREATE(sail_int)(&zgsz3422);
          sub_int(&zgsz3422, zgsz3420, zgsz3421);
          zgaz3234 = CONVERT_OF(mach_int, sail_int)(zgsz3422);
          KILL(sail_int)(&zgsz3422);
          KILL(sail_int)(&zgsz3421);
          KILL(sail_int)(&zgsz3420);
        }
      }
      {
        lbits zgsz3426;
        CREATE(lbits)(&zgsz3426);
        CONVERT_OF(lbits, fbits)(&zgsz3426, za, UINT64_C(32) , true);
        sail_int zgsz3427;
        CREATE(sail_int)(&zgsz3427);
        CONVERT_OF(sail_int, mach_int)(&zgsz3427, zgaz3234);
        lbits zgsz3428;
        CREATE(lbits)(&zgsz3428);
        shiftr(&zgsz3428, zgsz3426, zgsz3427);
        zgaz3235 = CONVERT_OF(fbits, lbits)(zgsz3428, true);
        KILL(lbits)(&zgsz3428);
        KILL(sail_int)(&zgsz3427);
        KILL(lbits)(&zgsz3426);
      }
    }
    {
      lbits zgsz3429;
      CREATE(lbits)(&zgsz3429);
      CONVERT_OF(lbits, fbits)(&zgsz3429, zgaz3235, UINT64_C(32) , true);
      sail_int zgsz3430;
      CREATE(sail_int)(&zgsz3430);
      CONVERT_OF(sail_int, mach_int)(&zgsz3430, INT64_C(3));
      lbits zgsz3431;
      CREATE(lbits)(&zgsz3431);
      sail_truncate(&zgsz3431, zgsz3429, zgsz3430);
      za3 = CONVERT_OF(fbits, lbits)(zgsz3431, true);
      KILL(lbits)(&zgsz3431);
      KILL(sail_int)(&zgsz3430);
      KILL(lbits)(&zgsz3429);
    }
  }
  uint64_t zB3;
  {
    uint64_t zgaz3232;
    zgaz3232 = zc.zB;
    {
      lbits zgsz3432;
      CREATE(lbits)(&zgsz3432);
      CONVERT_OF(lbits, fbits)(&zgsz3432, zgaz3232, UINT64_C(8) , true);
      sail_int zgsz3433;
      CREATE(sail_int)(&zgsz3433);
      CONVERT_OF(sail_int, mach_int)(&zgsz3433, INT64_C(3));
      lbits zgsz3434;
      CREATE(lbits)(&zgsz3434);
      sail_truncateLSB(&zgsz3434, zgsz3432, zgsz3433);
      zB3 = CONVERT_OF(fbits, lbits)(zgsz3434, true);
      KILL(lbits)(&zgsz3434);
      KILL(sail_int)(&zgsz3433);
      KILL(lbits)(&zgsz3432);
    }
  }
  uint64_t zT3;
  {
    uint64_t zgaz3231;
    zgaz3231 = zc.zT;
    {
      lbits zgsz3435;
      CREATE(lbits)(&zgsz3435);
      CONVERT_OF(lbits, fbits)(&zgsz3435, zgaz3231, UINT64_C(8) , true);
      sail_int zgsz3436;
      CREATE(sail_int)(&zgsz3436);
      CONVERT_OF(sail_int, mach_int)(&zgsz3436, INT64_C(3));
      lbits zgsz3437;
      CREATE(lbits)(&zgsz3437);
      sail_truncateLSB(&zgsz3437, zgsz3435, zgsz3436);
      zT3 = CONVERT_OF(fbits, lbits)(zgsz3437, true);
      KILL(lbits)(&zgsz3437);
      KILL(sail_int)(&zgsz3436);
      KILL(lbits)(&zgsz3435);
    }
  }
  uint64_t zR3;
  {
    lbits zgsz3519;
    CREATE(lbits)(&zgsz3519);
    CONVERT_OF(lbits, fbits)(&zgsz3519, zB3, UINT64_C(3) , true);
    lbits zgsz3520;
    CREATE(lbits)(&zgsz3520);
    CONVERT_OF(lbits, fbits)(&zgsz3520, UINT64_C(0b001), UINT64_C(3) , true);
    lbits zgsz3521;
    CREATE(lbits)(&zgsz3521);
    sub_bits(&zgsz3521, zgsz3519, zgsz3520);
    zR3 = CONVERT_OF(fbits, lbits)(zgsz3521, true);
    KILL(lbits)(&zgsz3521);
    KILL(lbits)(&zgsz3520);
    KILL(lbits)(&zgsz3519);
  }
  int64_t zaHi;
  {
    bool zgaz3230;
    {
      lbits zgsz3438;
      CREATE(lbits)(&zgsz3438);
      CONVERT_OF(lbits, fbits)(&zgsz3438, za3, UINT64_C(3) , true);
      lbits zgsz3439;
      CREATE(lbits)(&zgsz3439);
      CONVERT_OF(lbits, fbits)(&zgsz3439, zR3, UINT64_C(3) , true);
      zgaz3230 = sailgen_z8operatorz0zI_uz9(zgsz3438, zgsz3439);
      KILL(lbits)(&zgsz3439);
      KILL(lbits)(&zgsz3438);
    }
    if (zgaz3230) {  zaHi = INT64_C(1);  } else {  zaHi = INT64_C(0);  }
  }
  int64_t zbHi;
  {
    bool zgaz3229;
    {
      lbits zgsz3440;
      CREATE(lbits)(&zgsz3440);
      CONVERT_OF(lbits, fbits)(&zgsz3440, zB3, UINT64_C(3) , true);
      lbits zgsz3441;
      CREATE(lbits)(&zgsz3441);
      CONVERT_OF(lbits, fbits)(&zgsz3441, zR3, UINT64_C(3) , true);
      zgaz3229 = sailgen_z8operatorz0zI_uz9(zgsz3440, zgsz3441);
      KILL(lbits)(&zgsz3441);
      KILL(lbits)(&zgsz3440);
    }
    if (zgaz3229) {  zbHi = INT64_C(1);  } else {  zbHi = INT64_C(0);  }
  }
  int64_t ztHi;
  {
    bool zgaz3228;
    {
      lbits zgsz3442;
      CREATE(lbits)(&zgsz3442);
      CONVERT_OF(lbits, fbits)(&zgsz3442, zT3, UINT64_C(3) , true);
      lbits zgsz3443;
      CREATE(lbits)(&zgsz3443);
      CONVERT_OF(lbits, fbits)(&zgsz3443, zR3, UINT64_C(3) , true);
      zgaz3228 = sailgen_z8operatorz0zI_uz9(zgsz3442, zgsz3443);
      KILL(lbits)(&zgsz3443);
      KILL(lbits)(&zgsz3442);
    }
    if (zgaz3228) {  ztHi = INT64_C(1);  } else {  ztHi = INT64_C(0);  }
  }
  int64_t zcorrection_base;
  {
    sail_int zgsz3516;
    CREATE(sail_int)(&zgsz3516);
    CONVERT_OF(sail_int, mach_int)(&zgsz3516, zbHi);
    sail_int zgsz3517;
    CREATE(sail_int)(&zgsz3517);
    CONVERT_OF(sail_int, mach_int)(&zgsz3517, zaHi);
    sail_int zgsz3518;
    CREATE(sail_int)(&zgsz3518);
    sub_int(&zgsz3518, zgsz3516, zgsz3517);
    zcorrection_base = CONVERT_OF(mach_int, sail_int)(zgsz3518);
    KILL(sail_int)(&zgsz3518);
    KILL(sail_int)(&zgsz3517);
    KILL(sail_int)(&zgsz3516);
  }
  int64_t zcorrection_top;
  {
    sail_int zgsz3513;
    CREATE(sail_int)(&zgsz3513);
    CONVERT_OF(sail_int, mach_int)(&zgsz3513, ztHi);
    sail_int zgsz3514;
    CREATE(sail_int)(&zgsz3514);
    CONVERT_OF(sail_int, mach_int)(&zgsz3514, zaHi);
    sail_int zgsz3515;
    CREATE(sail_int)(&zgsz3515);
    sub_int(&zgsz3515, zgsz3513, zgsz3514);
    zcorrection_top = CONVERT_OF(mach_int, sail_int)(zgsz3515);
    KILL(sail_int)(&zgsz3515);
    KILL(sail_int)(&zgsz3514);
    KILL(sail_int)(&zgsz3513);
  }
  uint64_t za_top;
  {
    int64_t zgaz3227;
    {
      sail_int zgsz3447;
      CREATE(sail_int)(&zgsz3447);
      CONVERT_OF(sail_int, mach_int)(&zgsz3447, zE);
      sail_int zgsz3448;
      CREATE(sail_int)(&zgsz3448);
      CONVERT_OF(sail_int, mach_int)(&zgsz3448, zcap_mantissa_width);
      sail_int zgsz3449;
      CREATE(sail_int)(&zgsz3449);
      add_int(&zgsz3449, zgsz3447, zgsz3448);
      zgaz3227 = CONVERT_OF(mach_int, sail_int)(zgsz3449);
      KILL(sail_int)(&zgsz3449);
      KILL(sail_int)(&zgsz3448);
      KILL(sail_int)(&zgsz3447);
    }
    {
      lbits zgsz3444;
      CREATE(lbits)(&zgsz3444);
      CONVERT_OF(lbits, fbits)(&zgsz3444, za, UINT64_C(32) , true);
      sail_int zgsz3445;
      CREATE(sail_int)(&zgsz3445);
      CONVERT_OF(sail_int, mach_int)(&zgsz3445, zgaz3227);
      lbits zgsz3446;
      CREATE(lbits)(&zgsz3446);
      shiftr(&zgsz3446, zgsz3444, zgsz3445);
      za_top = CONVERT_OF(fbits, lbits)(zgsz3446, true);
      KILL(lbits)(&zgsz3446);
      KILL(sail_int)(&zgsz3445);
      KILL(lbits)(&zgsz3444);
    }
  }
  uint64_t zbase;
  {
    lbits zgaz3226;
    CREATE(lbits)(&zgaz3226);
    {
      uint64_t zgaz3224;
      {
        lbits zgsz3457;
        CREATE(lbits)(&zgsz3457);
        CONVERT_OF(lbits, fbits)(&zgsz3457, za_top, UINT64_C(32) , true);
        sail_int zgsz3458;
        CREATE(sail_int)(&zgsz3458);
        CONVERT_OF(sail_int, mach_int)(&zgsz3458, zcorrection_base);
        lbits zgsz3459;
        CREATE(lbits)(&zgsz3459);
        add_bits_int(&zgsz3459, zgsz3457, zgsz3458);
        zgaz3224 = CONVERT_OF(fbits, lbits)(zgsz3459, true);
        KILL(lbits)(&zgsz3459);
        KILL(sail_int)(&zgsz3458);
        KILL(lbits)(&zgsz3457);
      }
      sbits zgaz3225;
      {
        uint64_t zgaz3222;
        zgaz3222 = zc.zB;
        sbits zgaz3223;
        {
          sail_int zgsz3453;
          CREATE(sail_int)(&zgsz3453);
          CONVERT_OF(sail_int, mach_int)(&zgsz3453, zE);
          lbits zgsz3454;
          CREATE(lbits)(&zgsz3454);
          sailgen_zzeros_implicit(&zgsz3454, zgsz3453);
          zgaz3223 = CONVERT_OF(sbits, lbits)(zgsz3454, true);
          KILL(lbits)(&zgsz3454);
          KILL(sail_int)(&zgsz3453);
        }
        {
          lbits zgsz3450;
          CREATE(lbits)(&zgsz3450);
          CONVERT_OF(lbits, fbits)(&zgsz3450, zgaz3222, UINT64_C(8) , true);
          lbits zgsz3451;
          CREATE(lbits)(&zgsz3451);
          CONVERT_OF(lbits, sbits)(&zgsz3451, zgaz3223, true);
          lbits zgsz3452;
          CREATE(lbits)(&zgsz3452);
          append(&zgsz3452, zgsz3450, zgsz3451);
          zgaz3225 = CONVERT_OF(sbits, lbits)(zgsz3452, true);
          KILL(lbits)(&zgsz3452);
          KILL(lbits)(&zgsz3451);
          KILL(lbits)(&zgsz3450);
        }
      }
      {
        lbits zgsz3455;
        CREATE(lbits)(&zgsz3455);
        CONVERT_OF(lbits, fbits)(&zgsz3455, zgaz3224, UINT64_C(32) , true);
        lbits zgsz3456;
        CREATE(lbits)(&zgsz3456);
        CONVERT_OF(lbits, sbits)(&zgsz3456, zgaz3225, true);
        append(&zgaz3226, zgsz3455, zgsz3456);
        KILL(lbits)(&zgsz3456);
        KILL(lbits)(&zgsz3455);
      }
    }
    {
      sail_int zgsz3460;
      CREATE(sail_int)(&zgsz3460);
      CONVERT_OF(sail_int, mach_int)(&zgsz3460, zcap_len_width);
      lbits zgsz3461;
      CREATE(lbits)(&zgsz3461);
      sail_truncate(&zgsz3461, zgaz3226, zgsz3460);
      zbase = CONVERT_OF(fbits, lbits)(zgsz3461, true);
      KILL(lbits)(&zgsz3461);
      KILL(sail_int)(&zgsz3460);
    }
    KILL(lbits)(&zgaz3226);
  }
  uint64_t ztop;
  {
    lbits zgaz3221;
    CREATE(lbits)(&zgaz3221);
    {
      uint64_t zgaz3219;
      {
        lbits zgsz3469;
        CREATE(lbits)(&zgsz3469);
        CONVERT_OF(lbits, fbits)(&zgsz3469, za_top, UINT64_C(32) , true);
        sail_int zgsz3470;
        CREATE(sail_int)(&zgsz3470);
        CONVERT_OF(sail_int, mach_int)(&zgsz3470, zcorrection_top);
        lbits zgsz3471;
        CREATE(lbits)(&zgsz3471);
        add_bits_int(&zgsz3471, zgsz3469, zgsz3470);
        zgaz3219 = CONVERT_OF(fbits, lbits)(zgsz3471, true);
        KILL(lbits)(&zgsz3471);
        KILL(sail_int)(&zgsz3470);
        KILL(lbits)(&zgsz3469);
      }
      sbits zgaz3220;
      {
        uint64_t zgaz3217;
        zgaz3217 = zc.zT;
        sbits zgaz3218;
        {
          sail_int zgsz3465;
          CREATE(sail_int)(&zgsz3465);
          CONVERT_OF(sail_int, mach_int)(&zgsz3465, zE);
          lbits zgsz3466;
          CREATE(lbits)(&zgsz3466);
          sailgen_zzeros_implicit(&zgsz3466, zgsz3465);
          zgaz3218 = CONVERT_OF(sbits, lbits)(zgsz3466, true);
          KILL(lbits)(&zgsz3466);
          KILL(sail_int)(&zgsz3465);
        }
        {
          lbits zgsz3462;
          CREATE(lbits)(&zgsz3462);
          CONVERT_OF(lbits, fbits)(&zgsz3462, zgaz3217, UINT64_C(8) , true);
          lbits zgsz3463;
          CREATE(lbits)(&zgsz3463);
          CONVERT_OF(lbits, sbits)(&zgsz3463, zgaz3218, true);
          lbits zgsz3464;
          CREATE(lbits)(&zgsz3464);
          append(&zgsz3464, zgsz3462, zgsz3463);
          zgaz3220 = CONVERT_OF(sbits, lbits)(zgsz3464, true);
          KILL(lbits)(&zgsz3464);
          KILL(lbits)(&zgsz3463);
          KILL(lbits)(&zgsz3462);
        }
      }
      {
        lbits zgsz3467;
        CREATE(lbits)(&zgsz3467);
        CONVERT_OF(lbits, fbits)(&zgsz3467, zgaz3219, UINT64_C(32) , true);
        lbits zgsz3468;
        CREATE(lbits)(&zgsz3468);
        CONVERT_OF(lbits, sbits)(&zgsz3468, zgaz3220, true);
        append(&zgaz3221, zgsz3467, zgsz3468);
        KILL(lbits)(&zgsz3468);
        KILL(lbits)(&zgsz3467);
      }
    }
    {
      sail_int zgsz3472;
      CREATE(sail_int)(&zgsz3472);
      CONVERT_OF(sail_int, mach_int)(&zgsz3472, zcap_len_width);
      lbits zgsz3473;
      CREATE(lbits)(&zgsz3473);
      sail_truncate(&zgsz3473, zgaz3221, zgsz3472);
      ztop = CONVERT_OF(fbits, lbits)(zgsz3473, true);
      KILL(lbits)(&zgsz3473);
      KILL(sail_int)(&zgsz3472);
    }
    KILL(lbits)(&zgaz3221);
  }
  uint64_t zbase2;
  {
    uint64_t zgaz3216;
    {
      fbits zgaz3215;
      {
        int64_t zgaz3214;
        {
          sail_int zgsz3476;
          CREATE(sail_int)(&zgsz3476);
          CONVERT_OF(sail_int, mach_int)(&zgsz3476, zcap_addr_width);
          sail_int zgsz3477;
          CREATE(sail_int)(&zgsz3477);
          CONVERT_OF(sail_int, mach_int)(&zgsz3477, INT64_C(1));
          sail_int zgsz3478;
          CREATE(sail_int)(&zgsz3478);
          sub_int(&zgsz3478, zgsz3476, zgsz3477);
          zgaz3214 = CONVERT_OF(mach_int, sail_int)(zgsz3478);
          KILL(sail_int)(&zgsz3478);
          KILL(sail_int)(&zgsz3477);
          KILL(sail_int)(&zgsz3476);
        }
        {
          lbits zgsz3474;
          CREATE(lbits)(&zgsz3474);
          CONVERT_OF(lbits, fbits)(&zgsz3474, zbase, UINT64_C(33) , true);
          sail_int zgsz3475;
          CREATE(sail_int)(&zgsz3475);
          CONVERT_OF(sail_int, mach_int)(&zgsz3475, zgaz3214);
          zgaz3215 = bitvector_access(zgsz3474, zgsz3475);
          KILL(sail_int)(&zgsz3475);
          KILL(lbits)(&zgsz3474);
        }
      }
      uint64_t zgsz347;
      zgsz347 = UINT64_C(0b0);
      zgsz347 = update_fbits(zgsz347, INT64_C(0), zgaz3215);
      zgaz3216 = zgsz347;
    }
    {
      lbits zgsz3479;
      CREATE(lbits)(&zgsz3479);
      CONVERT_OF(lbits, fbits)(&zgsz3479, UINT64_C(0b0), UINT64_C(1) , true);
      lbits zgsz3480;
      CREATE(lbits)(&zgsz3480);
      CONVERT_OF(lbits, fbits)(&zgsz3480, zgaz3216, UINT64_C(1) , true);
      lbits zgsz3481;
      CREATE(lbits)(&zgsz3481);
      append(&zgsz3481, zgsz3479, zgsz3480);
      zbase2 = CONVERT_OF(fbits, lbits)(zgsz3481, true);
      KILL(lbits)(&zgsz3481);
      KILL(lbits)(&zgsz3480);
      KILL(lbits)(&zgsz3479);
    }
  }
  uint64_t ztop2;
  {
    int64_t zgaz3213;
    {
      sail_int zgsz3486;
      CREATE(sail_int)(&zgsz3486);
      CONVERT_OF(sail_int, mach_int)(&zgsz3486, zcap_addr_width);
      sail_int zgsz3487;
      CREATE(sail_int)(&zgsz3487);
      CONVERT_OF(sail_int, mach_int)(&zgsz3487, INT64_C(1));
      sail_int zgsz3488;
      CREATE(sail_int)(&zgsz3488);
      sub_int(&zgsz3488, zgsz3486, zgsz3487);
      zgaz3213 = CONVERT_OF(mach_int, sail_int)(zgsz3488);
      KILL(sail_int)(&zgsz3488);
      KILL(sail_int)(&zgsz3487);
      KILL(sail_int)(&zgsz3486);
    }
    {
      lbits zgsz3482;
      CREATE(lbits)(&zgsz3482);
      CONVERT_OF(lbits, fbits)(&zgsz3482, ztop, UINT64_C(33) , true);
      sail_int zgsz3483;
      CREATE(sail_int)(&zgsz3483);
      CONVERT_OF(sail_int, mach_int)(&zgsz3483, zcap_addr_width);
      sail_int zgsz3484;
      CREATE(sail_int)(&zgsz3484);
      CONVERT_OF(sail_int, mach_int)(&zgsz3484, zgaz3213);
      lbits zgsz3485;
      CREATE(lbits)(&zgsz3485);
      vector_subrange_lbits(&zgsz3485, zgsz3482, zgsz3483, zgsz3484);
      ztop2 = CONVERT_OF(fbits, lbits)(zgsz3485, true);
      KILL(lbits)(&zgsz3485);
      KILL(sail_int)(&zgsz3484);
      KILL(sail_int)(&zgsz3483);
      KILL(lbits)(&zgsz3482);
    }
  }
  {
    bool zgaz3208;
    {
      bool zgaz3207;
      {
        int64_t zgaz3204;
        {
          sail_int zgsz3491;
          CREATE(sail_int)(&zgsz3491);
          CONVERT_OF(sail_int, mach_int)(&zgsz3491, zcap_max_E);
          sail_int zgsz3492;
          CREATE(sail_int)(&zgsz3492);
          CONVERT_OF(sail_int, mach_int)(&zgsz3492, INT64_C(1));
          sail_int zgsz3493;
          CREATE(sail_int)(&zgsz3493);
          sub_int(&zgsz3493, zgsz3491, zgsz3492);
          zgaz3204 = CONVERT_OF(mach_int, sail_int)(zgsz3493);
          KILL(sail_int)(&zgsz3493);
          KILL(sail_int)(&zgsz3492);
          KILL(sail_int)(&zgsz3491);
        }
        {
          sail_int zgsz3489;
          CREATE(sail_int)(&zgsz3489);
          CONVERT_OF(sail_int, mach_int)(&zgsz3489, zE);
          sail_int zgsz3490;
          CREATE(sail_int)(&zgsz3490);
          CONVERT_OF(sail_int, mach_int)(&zgsz3490, zgaz3204);
          zgaz3207 = lt(zgsz3489, zgsz3490);
          KILL(sail_int)(&zgsz3490);
          KILL(sail_int)(&zgsz3489);
        }
      }
      bool zgsz348;
      if (zgaz3207) {
        int64_t zgaz3206;
        {
          uint64_t zgaz3205;
          {
            lbits zgsz3496;
            CREATE(lbits)(&zgsz3496);
            CONVERT_OF(lbits, fbits)(&zgsz3496, ztop2, UINT64_C(2) , true);
            lbits zgsz3497;
            CREATE(lbits)(&zgsz3497);
            CONVERT_OF(lbits, fbits)(&zgsz3497, zbase2, UINT64_C(2) , true);
            lbits zgsz3498;
            CREATE(lbits)(&zgsz3498);
            sub_bits(&zgsz3498, zgsz3496, zgsz3497);
            zgaz3205 = CONVERT_OF(fbits, lbits)(zgsz3498, true);
            KILL(lbits)(&zgsz3498);
            KILL(lbits)(&zgsz3497);
            KILL(lbits)(&zgsz3496);
          }
          {
            lbits zgsz3494;
            CREATE(lbits)(&zgsz3494);
            CONVERT_OF(lbits, fbits)(&zgsz3494, zgaz3205, UINT64_C(2) , true);
            sail_int zgsz3495;
            CREATE(sail_int)(&zgsz3495);
            sail_unsigned(&zgsz3495, zgsz3494);
            zgaz3206 = CONVERT_OF(mach_int, sail_int)(zgsz3495);
            KILL(sail_int)(&zgsz3495);
            KILL(lbits)(&zgsz3494);
          }
        }
        {
          sail_int zgsz3499;
          CREATE(sail_int)(&zgsz3499);
          CONVERT_OF(sail_int, mach_int)(&zgsz3499, zgaz3206);
          sail_int zgsz3500;
          CREATE(sail_int)(&zgsz3500);
          CONVERT_OF(sail_int, mach_int)(&zgsz3500, INT64_C(1));
          zgsz348 = gt(zgsz3499, zgsz3500);
          KILL(sail_int)(&zgsz3500);
          KILL(sail_int)(&zgsz3499);
        }
      } else {  zgsz348 = false;  }
      zgaz3208 = zgsz348;
    }
    unit zgsz349;
    if (zgaz3208) {
      fbits zgaz3210;
      {
        fbits zgaz3209;
        {
          lbits zgsz3501;
          CREATE(lbits)(&zgsz3501);
          CONVERT_OF(lbits, fbits)(&zgsz3501, ztop, UINT64_C(33) , true);
          sail_int zgsz3502;
          CREATE(sail_int)(&zgsz3502);
          CONVERT_OF(sail_int, mach_int)(&zgsz3502, zcap_addr_width);
          zgaz3209 = bitvector_access(zgsz3501, zgsz3502);
          KILL(sail_int)(&zgsz3502);
          KILL(lbits)(&zgsz3501);
        }
        zgaz3210 = sailgen_not_bit(zgaz3209);
      }
      {
        lbits zgsz3503;
        CREATE(lbits)(&zgsz3503);
        CONVERT_OF(lbits, fbits)(&zgsz3503, ztop, UINT64_C(33) , true);
        sail_int zgsz3504;
        CREATE(sail_int)(&zgsz3504);
        CONVERT_OF(sail_int, mach_int)(&zgsz3504, zcap_addr_width);
        lbits zgsz3505;
        CREATE(lbits)(&zgsz3505);
        update_lbits(&zgsz3505, zgsz3503, zgsz3504, zgaz3210);
        ztop = CONVERT_OF(fbits, lbits)(zgsz3505, true);
        KILL(lbits)(&zgsz3505);
        KILL(sail_int)(&zgsz3504);
        KILL(lbits)(&zgsz3503);
      }
      zgsz349 = UNIT;
    } else {  zgsz349 = UNIT;  }
  }
  uint64_t zgaz3212;
  {
    int64_t zgaz3211;
    {
      sail_int zgsz3510;
      CREATE(sail_int)(&zgsz3510);
      CONVERT_OF(sail_int, mach_int)(&zgsz3510, zcap_addr_width);
      sail_int zgsz3511;
      CREATE(sail_int)(&zgsz3511);
      CONVERT_OF(sail_int, mach_int)(&zgsz3511, INT64_C(1));
      sail_int zgsz3512;
      CREATE(sail_int)(&zgsz3512);
      sub_int(&zgsz3512, zgsz3510, zgsz3511);
      zgaz3211 = CONVERT_OF(mach_int, sail_int)(zgsz3512);
      KILL(sail_int)(&zgsz3512);
      KILL(sail_int)(&zgsz3511);
      KILL(sail_int)(&zgsz3510);
    }
    {
      lbits zgsz3506;
      CREATE(lbits)(&zgsz3506);
      CONVERT_OF(lbits, fbits)(&zgsz3506, zbase, UINT64_C(33) , true);
      sail_int zgsz3507;
      CREATE(sail_int)(&zgsz3507);
      CONVERT_OF(sail_int, mach_int)(&zgsz3507, zgaz3211);
      sail_int zgsz3508;
      CREATE(sail_int)(&zgsz3508);
      CONVERT_OF(sail_int, mach_int)(&zgsz3508, INT64_C(0));
      lbits zgsz3509;
      CREATE(lbits)(&zgsz3509);
      vector_subrange_lbits(&zgsz3509, zgsz3506, zgsz3507, zgsz3508);
      zgaz3212 = CONVERT_OF(fbits, lbits)(zgsz3509, true);
      KILL(lbits)(&zgsz3509);
      KILL(sail_int)(&zgsz3508);
      KILL(sail_int)(&zgsz3507);
      KILL(lbits)(&zgsz3506);
    }
  }
  struct ztuple_z8z5bv32zCz0z5bv33z9 zgsz350;
  zgsz350.ztup0 = zgaz3212;
  zgsz350.ztup1 = ztop;
  zcbz324 = zgsz350;


















end_function_108: ;
  return zcbz324;
end_block_exception_109: ;
  struct ztuple_z8z5bv32zCz0z5bv33z9 zcbz352 = { .ztup0 = UINT64_C(0xdeadc0de), .ztup1 = UINT64_C(0xdeadc0de) };
  return zcbz352;
}

// struct tuple_(%i64, %i64)
struct ztuple_z8z5i64zCz0z5i64z9 {
  int64_t ztup0;
  int64_t ztup1;
};

static void COPY(ztuple_z8z5i64zCz0z5i64z9)(struct ztuple_z8z5i64zCz0z5i64z9 *rop, const struct ztuple_z8z5i64zCz0z5i64z9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
}

static bool EQUAL(ztuple_z8z5i64zCz0z5i64z9)(struct ztuple_z8z5i64zCz0z5i64z9 op1, struct ztuple_z8z5i64zCz0z5i64z9 op2) {
  return EQUAL(mach_int)(op1.ztup0, op2.ztup0) && EQUAL(mach_int)(op1.ztup1, op2.ztup1);
}

static struct ztuple_z8z5i64zCz0z5i64z9 sailgen_getCapBounds(struct zCapability);


static struct ztuple_z8z5i64zCz0z5i64z9 sailgen_getCapBounds(struct zCapability zcap)
{
  __label__ case_112, finish_match_111, end_function_113, end_block_exception_114;

  struct ztuple_z8z5i64zCz0z5i64z9 zcbz325;
  struct ztuple_z8z5bv32zCz0z5bv33z9 zgaz3238;
  zgaz3238 = sailgen_getCapBoundsBits(zcap);
  struct ztuple_z8z5i64zCz0z5i64z9 zgsz351;
  {
    uint64_t zbase;
    zbase = zgaz3238.ztup0;
    uint64_t ztop;
    ztop = zgaz3238.ztup1;
    int64_t zgaz3239;
    {
      lbits zgsz3524;
      CREATE(lbits)(&zgsz3524);
      CONVERT_OF(lbits, fbits)(&zgsz3524, zbase, UINT64_C(32) , true);
      sail_int zgsz3525;
      CREATE(sail_int)(&zgsz3525);
      sail_unsigned(&zgsz3525, zgsz3524);
      zgaz3239 = CONVERT_OF(mach_int, sail_int)(zgsz3525);
      KILL(sail_int)(&zgsz3525);
      KILL(lbits)(&zgsz3524);
    }
    int64_t zgaz3240;
    {
      lbits zgsz3522;
      CREATE(lbits)(&zgsz3522);
      CONVERT_OF(lbits, fbits)(&zgsz3522, ztop, UINT64_C(33) , true);
      sail_int zgsz3523;
      CREATE(sail_int)(&zgsz3523);
      sail_unsigned(&zgsz3523, zgsz3522);
      zgaz3240 = CONVERT_OF(mach_int, sail_int)(zgsz3523);
      KILL(sail_int)(&zgsz3523);
      KILL(lbits)(&zgsz3522);
    }
    struct ztuple_z8z5i64zCz0z5i64z9 zgsz352;
    zgsz352.ztup0 = zgaz3239;
    zgsz352.ztup1 = zgaz3240;
    zgsz351 = zgsz352;
    goto finish_match_111;
  }
case_112: ;
  sail_match_failure("getCapBounds");
finish_match_111: ;
  zcbz325 = zgsz351;


end_function_113: ;
  return zcbz325;
end_block_exception_114: ;
  struct ztuple_z8z5i64zCz0z5i64z9 zcbz353 = { .ztup0 = INT64_C(0xdeadc0de), .ztup1 = INT64_C(0xdeadc0de) };
  return zcbz353;
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

static struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 sailgen_setCapBounds(struct zCapability, uint64_t, uint64_t);

static struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 sailgen_setCapBounds(struct zCapability zcap, uint64_t zbase, uint64_t ztop)
{
  __label__ end_function_116, end_block_exception_117;

  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz326;
  uint64_t zext_base;
  {
    lbits zgsz3654;
    CREATE(lbits)(&zgsz3654);
    CONVERT_OF(lbits, fbits)(&zgsz3654, UINT64_C(0b0), UINT64_C(1) , true);
    lbits zgsz3655;
    CREATE(lbits)(&zgsz3655);
    CONVERT_OF(lbits, fbits)(&zgsz3655, zbase, UINT64_C(32) , true);
    lbits zgsz3656;
    CREATE(lbits)(&zgsz3656);
    append(&zgsz3656, zgsz3654, zgsz3655);
    zext_base = CONVERT_OF(fbits, lbits)(zgsz3656, true);
    KILL(lbits)(&zgsz3656);
    KILL(lbits)(&zgsz3655);
    KILL(lbits)(&zgsz3654);
  }
  uint64_t zlength;
  {
    lbits zgsz3651;
    CREATE(lbits)(&zgsz3651);
    CONVERT_OF(lbits, fbits)(&zgsz3651, ztop, UINT64_C(33) , true);
    lbits zgsz3652;
    CREATE(lbits)(&zgsz3652);
    CONVERT_OF(lbits, fbits)(&zgsz3652, zext_base, UINT64_C(33) , true);
    lbits zgsz3653;
    CREATE(lbits)(&zgsz3653);
    sub_bits(&zgsz3653, zgsz3651, zgsz3652);
    zlength = CONVERT_OF(fbits, lbits)(zgsz3653, true);
    KILL(lbits)(&zgsz3653);
    KILL(lbits)(&zgsz3652);
    KILL(lbits)(&zgsz3651);
  }
  int64_t ze;
  {
    int64_t zgaz3273;
    {
      uint64_t zgaz3272;
      {
        int64_t zgaz3271;
        {
          sail_int zgsz3530;
          CREATE(sail_int)(&zgsz3530);
          CONVERT_OF(sail_int, mach_int)(&zgsz3530, zcap_mantissa_width);
          sail_int zgsz3531;
          CREATE(sail_int)(&zgsz3531);
          CONVERT_OF(sail_int, mach_int)(&zgsz3531, INT64_C(1));
          sail_int zgsz3532;
          CREATE(sail_int)(&zgsz3532);
          sub_int(&zgsz3532, zgsz3530, zgsz3531);
          zgaz3271 = CONVERT_OF(mach_int, sail_int)(zgsz3532);
          KILL(sail_int)(&zgsz3532);
          KILL(sail_int)(&zgsz3531);
          KILL(sail_int)(&zgsz3530);
        }
        {
          lbits zgsz3526;
          CREATE(lbits)(&zgsz3526);
          CONVERT_OF(lbits, fbits)(&zgsz3526, zlength, UINT64_C(33) , true);
          sail_int zgsz3527;
          CREATE(sail_int)(&zgsz3527);
          CONVERT_OF(sail_int, mach_int)(&zgsz3527, zcap_addr_width);
          sail_int zgsz3528;
          CREATE(sail_int)(&zgsz3528);
          CONVERT_OF(sail_int, mach_int)(&zgsz3528, zgaz3271);
          lbits zgsz3529;
          CREATE(lbits)(&zgsz3529);
          vector_subrange_lbits(&zgsz3529, zgsz3526, zgsz3527, zgsz3528);
          zgaz3272 = CONVERT_OF(fbits, lbits)(zgsz3529, true);
          KILL(lbits)(&zgsz3529);
          KILL(sail_int)(&zgsz3528);
          KILL(sail_int)(&zgsz3527);
          KILL(lbits)(&zgsz3526);
        }
      }
      {
        lbits zgsz3533;
        CREATE(lbits)(&zgsz3533);
        CONVERT_OF(lbits, fbits)(&zgsz3533, zgaz3272, UINT64_C(26) , true);
        sail_int zgsz3534;
        CREATE(sail_int)(&zgsz3534);
        count_leading_zeros(&zgsz3534, zgsz3533);
        zgaz3273 = CONVERT_OF(mach_int, sail_int)(zgsz3534);
        KILL(sail_int)(&zgsz3534);
        KILL(lbits)(&zgsz3533);
      }
    }
    {
      sail_int zgsz3535;
      CREATE(sail_int)(&zgsz3535);
      CONVERT_OF(sail_int, mach_int)(&zgsz3535, zcap_max_E);
      sail_int zgsz3536;
      CREATE(sail_int)(&zgsz3536);
      CONVERT_OF(sail_int, mach_int)(&zgsz3536, zgaz3273);
      sail_int zgsz3537;
      CREATE(sail_int)(&zgsz3537);
      sub_int(&zgsz3537, zgsz3535, zgsz3536);
      ze = CONVERT_OF(mach_int, sail_int)(zgsz3537);
      KILL(sail_int)(&zgsz3537);
      KILL(sail_int)(&zgsz3536);
      KILL(sail_int)(&zgsz3535);
    }
  }
  bool zie;
  {
    bool zgaz3270;
    {
      sail_int zgsz3543;
      CREATE(sail_int)(&zgsz3543);
      CONVERT_OF(sail_int, mach_int)(&zgsz3543, ze);
      sail_int zgsz3544;
      CREATE(sail_int)(&zgsz3544);
      CONVERT_OF(sail_int, mach_int)(&zgsz3544, INT64_C(0));
      zgaz3270 = sailgen_neq_int(zgsz3543, zgsz3544);
      KILL(sail_int)(&zgsz3544);
      KILL(sail_int)(&zgsz3543);
    }
    bool zgsz354;
    if (zgaz3270) {  zgsz354 = true;  } else {
      fbits zgaz3269;
      {
        int64_t zgaz3268;
        {
          sail_int zgsz3540;
          CREATE(sail_int)(&zgsz3540);
          CONVERT_OF(sail_int, mach_int)(&zgsz3540, zcap_mantissa_width);
          sail_int zgsz3541;
          CREATE(sail_int)(&zgsz3541);
          CONVERT_OF(sail_int, mach_int)(&zgsz3541, INT64_C(2));
          sail_int zgsz3542;
          CREATE(sail_int)(&zgsz3542);
          sub_int(&zgsz3542, zgsz3540, zgsz3541);
          zgaz3268 = CONVERT_OF(mach_int, sail_int)(zgsz3542);
          KILL(sail_int)(&zgsz3542);
          KILL(sail_int)(&zgsz3541);
          KILL(sail_int)(&zgsz3540);
        }
        {
          lbits zgsz3538;
          CREATE(lbits)(&zgsz3538);
          CONVERT_OF(lbits, fbits)(&zgsz3538, zlength, UINT64_C(33) , true);
          sail_int zgsz3539;
          CREATE(sail_int)(&zgsz3539);
          CONVERT_OF(sail_int, mach_int)(&zgsz3539, zgaz3268);
          zgaz3269 = bitvector_access(zgsz3538, zgsz3539);
          KILL(sail_int)(&zgsz3539);
          KILL(lbits)(&zgsz3538);
        }
      }
      zgsz354 = eq_bit(zgaz3269, UINT64_C(1));
    }
    zie = zgsz354;
  }
  uint64_t zBbits;
  {
    lbits zgsz3648;
    CREATE(lbits)(&zgsz3648);
    CONVERT_OF(lbits, fbits)(&zgsz3648, zbase, UINT64_C(32) , true);
    sail_int zgsz3649;
    CREATE(sail_int)(&zgsz3649);
    CONVERT_OF(sail_int, mach_int)(&zgsz3649, zcap_mantissa_width);
    lbits zgsz3650;
    CREATE(lbits)(&zgsz3650);
    sail_truncate(&zgsz3650, zgsz3648, zgsz3649);
    zBbits = CONVERT_OF(fbits, lbits)(zgsz3650, true);
    KILL(lbits)(&zgsz3650);
    KILL(sail_int)(&zgsz3649);
    KILL(lbits)(&zgsz3648);
  }
  uint64_t zTbits;
  {
    lbits zgsz3645;
    CREATE(lbits)(&zgsz3645);
    CONVERT_OF(lbits, fbits)(&zgsz3645, ztop, UINT64_C(33) , true);
    sail_int zgsz3646;
    CREATE(sail_int)(&zgsz3646);
    CONVERT_OF(sail_int, mach_int)(&zgsz3646, zcap_mantissa_width);
    lbits zgsz3647;
    CREATE(lbits)(&zgsz3647);
    sail_truncate(&zgsz3647, zgsz3645, zgsz3646);
    zTbits = CONVERT_OF(fbits, lbits)(zgsz3647, true);
    KILL(lbits)(&zgsz3647);
    KILL(sail_int)(&zgsz3646);
    KILL(lbits)(&zgsz3645);
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
        uint64_t zgaz3263;
        {
          int64_t zgaz3262;
          {
            sail_int zgsz3548;
            CREATE(sail_int)(&zgsz3548);
            CONVERT_OF(sail_int, mach_int)(&zgsz3548, ze);
            sail_int zgsz3549;
            CREATE(sail_int)(&zgsz3549);
            CONVERT_OF(sail_int, mach_int)(&zgsz3549, INT64_C(3));
            sail_int zgsz3550;
            CREATE(sail_int)(&zgsz3550);
            add_int(&zgsz3550, zgsz3548, zgsz3549);
            zgaz3262 = CONVERT_OF(mach_int, sail_int)(zgsz3550);
            KILL(sail_int)(&zgsz3550);
            KILL(sail_int)(&zgsz3549);
            KILL(sail_int)(&zgsz3548);
          }
          {
            lbits zgsz3545;
            CREATE(lbits)(&zgsz3545);
            CONVERT_OF(lbits, fbits)(&zgsz3545, zbase, UINT64_C(32) , true);
            sail_int zgsz3546;
            CREATE(sail_int)(&zgsz3546);
            CONVERT_OF(sail_int, mach_int)(&zgsz3546, zgaz3262);
            lbits zgsz3547;
            CREATE(lbits)(&zgsz3547);
            shiftr(&zgsz3547, zgsz3545, zgsz3546);
            zgaz3263 = CONVERT_OF(fbits, lbits)(zgsz3547, true);
            KILL(lbits)(&zgsz3547);
            KILL(sail_int)(&zgsz3546);
            KILL(lbits)(&zgsz3545);
          }
        }
        int64_t zgaz3264;
        {
          sail_int zgsz3554;
          CREATE(sail_int)(&zgsz3554);
          CONVERT_OF(sail_int, mach_int)(&zgsz3554, zcap_mantissa_width);
          sail_int zgsz3555;
          CREATE(sail_int)(&zgsz3555);
          CONVERT_OF(sail_int, mach_int)(&zgsz3555, INT64_C(3));
          sail_int zgsz3556;
          CREATE(sail_int)(&zgsz3556);
          sub_int(&zgsz3556, zgsz3554, zgsz3555);
          zgaz3264 = CONVERT_OF(mach_int, sail_int)(zgsz3556);
          KILL(sail_int)(&zgsz3556);
          KILL(sail_int)(&zgsz3555);
          KILL(sail_int)(&zgsz3554);
        }
        {
          lbits zgsz3551;
          CREATE(lbits)(&zgsz3551);
          CONVERT_OF(lbits, fbits)(&zgsz3551, zgaz3263, UINT64_C(32) , true);
          sail_int zgsz3552;
          CREATE(sail_int)(&zgsz3552);
          CONVERT_OF(sail_int, mach_int)(&zgsz3552, zgaz3264);
          lbits zgsz3553;
          CREATE(lbits)(&zgsz3553);
          sail_truncate(&zgsz3553, zgsz3551, zgsz3552);
          zB_ie = CONVERT_OF(fbits, lbits)(zgsz3553, true);
          KILL(lbits)(&zgsz3553);
          KILL(sail_int)(&zgsz3552);
          KILL(lbits)(&zgsz3551);
        }
      }
      uint64_t zT_ie;
      {
        uint64_t zgaz3260;
        {
          int64_t zgaz3259;
          {
            sail_int zgsz3560;
            CREATE(sail_int)(&zgsz3560);
            CONVERT_OF(sail_int, mach_int)(&zgsz3560, ze);
            sail_int zgsz3561;
            CREATE(sail_int)(&zgsz3561);
            CONVERT_OF(sail_int, mach_int)(&zgsz3561, INT64_C(3));
            sail_int zgsz3562;
            CREATE(sail_int)(&zgsz3562);
            add_int(&zgsz3562, zgsz3560, zgsz3561);
            zgaz3259 = CONVERT_OF(mach_int, sail_int)(zgsz3562);
            KILL(sail_int)(&zgsz3562);
            KILL(sail_int)(&zgsz3561);
            KILL(sail_int)(&zgsz3560);
          }
          {
            lbits zgsz3557;
            CREATE(lbits)(&zgsz3557);
            CONVERT_OF(lbits, fbits)(&zgsz3557, ztop, UINT64_C(33) , true);
            sail_int zgsz3558;
            CREATE(sail_int)(&zgsz3558);
            CONVERT_OF(sail_int, mach_int)(&zgsz3558, zgaz3259);
            lbits zgsz3559;
            CREATE(lbits)(&zgsz3559);
            shiftr(&zgsz3559, zgsz3557, zgsz3558);
            zgaz3260 = CONVERT_OF(fbits, lbits)(zgsz3559, true);
            KILL(lbits)(&zgsz3559);
            KILL(sail_int)(&zgsz3558);
            KILL(lbits)(&zgsz3557);
          }
        }
        int64_t zgaz3261;
        {
          sail_int zgsz3566;
          CREATE(sail_int)(&zgsz3566);
          CONVERT_OF(sail_int, mach_int)(&zgsz3566, zcap_mantissa_width);
          sail_int zgsz3567;
          CREATE(sail_int)(&zgsz3567);
          CONVERT_OF(sail_int, mach_int)(&zgsz3567, INT64_C(3));
          sail_int zgsz3568;
          CREATE(sail_int)(&zgsz3568);
          sub_int(&zgsz3568, zgsz3566, zgsz3567);
          zgaz3261 = CONVERT_OF(mach_int, sail_int)(zgsz3568);
          KILL(sail_int)(&zgsz3568);
          KILL(sail_int)(&zgsz3567);
          KILL(sail_int)(&zgsz3566);
        }
        {
          lbits zgsz3563;
          CREATE(lbits)(&zgsz3563);
          CONVERT_OF(lbits, fbits)(&zgsz3563, zgaz3260, UINT64_C(33) , true);
          sail_int zgsz3564;
          CREATE(sail_int)(&zgsz3564);
          CONVERT_OF(sail_int, mach_int)(&zgsz3564, zgaz3261);
          lbits zgsz3565;
          CREATE(lbits)(&zgsz3565);
          sail_truncate(&zgsz3565, zgsz3563, zgsz3564);
          zT_ie = CONVERT_OF(fbits, lbits)(zgsz3565, true);
          KILL(lbits)(&zgsz3565);
          KILL(sail_int)(&zgsz3564);
          KILL(lbits)(&zgsz3563);
        }
      }
      uint64_t zmaskLo;
      {
        sbits zgaz3258;
        {
          int64_t zgaz3257;
          {
            sail_int zgsz3571;
            CREATE(sail_int)(&zgsz3571);
            CONVERT_OF(sail_int, mach_int)(&zgsz3571, ze);
            sail_int zgsz3572;
            CREATE(sail_int)(&zgsz3572);
            CONVERT_OF(sail_int, mach_int)(&zgsz3572, INT64_C(3));
            sail_int zgsz3573;
            CREATE(sail_int)(&zgsz3573);
            add_int(&zgsz3573, zgsz3571, zgsz3572);
            zgaz3257 = CONVERT_OF(mach_int, sail_int)(zgsz3573);
            KILL(sail_int)(&zgsz3573);
            KILL(sail_int)(&zgsz3572);
            KILL(sail_int)(&zgsz3571);
          }
          {
            sail_int zgsz3569;
            CREATE(sail_int)(&zgsz3569);
            CONVERT_OF(sail_int, mach_int)(&zgsz3569, zgaz3257);
            lbits zgsz3570;
            CREATE(lbits)(&zgsz3570);
            sailgen_ones(&zgsz3570, zgsz3569);
            zgaz3258 = CONVERT_OF(sbits, lbits)(zgsz3570, true);
            KILL(lbits)(&zgsz3570);
            KILL(sail_int)(&zgsz3569);
          }
        }
        {
          sail_int zgsz3574;
          CREATE(sail_int)(&zgsz3574);
          CONVERT_OF(sail_int, mach_int)(&zgsz3574, INT64_C(33));
          lbits zgsz3575;
          CREATE(lbits)(&zgsz3575);
          CONVERT_OF(lbits, sbits)(&zgsz3575, zgaz3258, true);
          lbits zgsz3576;
          CREATE(lbits)(&zgsz3576);
          sailgen_EXTZ(&zgsz3576, zgsz3574, zgsz3575);
          zmaskLo = CONVERT_OF(fbits, lbits)(zgsz3576, true);
          KILL(lbits)(&zgsz3576);
          KILL(lbits)(&zgsz3575);
          KILL(sail_int)(&zgsz3574);
        }
      }
      {
        int64_t zgaz3242;
        {
          uint64_t zgaz3241;
          {
            lbits zgsz3579;
            CREATE(lbits)(&zgsz3579);
            CONVERT_OF(lbits, fbits)(&zgsz3579, zext_base, UINT64_C(33) , true);
            lbits zgsz3580;
            CREATE(lbits)(&zgsz3580);
            CONVERT_OF(lbits, fbits)(&zgsz3580, zmaskLo, UINT64_C(33) , true);
            lbits zgsz3581;
            CREATE(lbits)(&zgsz3581);
            and_bits(&zgsz3581, zgsz3579, zgsz3580);
            zgaz3241 = CONVERT_OF(fbits, lbits)(zgsz3581, true);
            KILL(lbits)(&zgsz3581);
            KILL(lbits)(&zgsz3580);
            KILL(lbits)(&zgsz3579);
          }
          {
            lbits zgsz3577;
            CREATE(lbits)(&zgsz3577);
            CONVERT_OF(lbits, fbits)(&zgsz3577, zgaz3241, UINT64_C(33) , true);
            sail_int zgsz3578;
            CREATE(sail_int)(&zgsz3578);
            sail_unsigned(&zgsz3578, zgsz3577);
            zgaz3242 = CONVERT_OF(mach_int, sail_int)(zgsz3578);
            KILL(sail_int)(&zgsz3578);
            KILL(lbits)(&zgsz3577);
          }
        }
        {
          sail_int zgsz3582;
          CREATE(sail_int)(&zgsz3582);
          CONVERT_OF(sail_int, mach_int)(&zgsz3582, zgaz3242);
          sail_int zgsz3583;
          CREATE(sail_int)(&zgsz3583);
          CONVERT_OF(sail_int, mach_int)(&zgsz3583, INT64_C(0));
          zlostSignificantBase = sailgen_neq_int(zgsz3582, zgsz3583);
          KILL(sail_int)(&zgsz3583);
          KILL(sail_int)(&zgsz3582);
        }
        unit zgsz358;
        zgsz358 = UNIT;
      }
      {
        int64_t zgaz3244;
        {
          uint64_t zgaz3243;
          {
            lbits zgsz3586;
            CREATE(lbits)(&zgsz3586);
            CONVERT_OF(lbits, fbits)(&zgsz3586, ztop, UINT64_C(33) , true);
            lbits zgsz3587;
            CREATE(lbits)(&zgsz3587);
            CONVERT_OF(lbits, fbits)(&zgsz3587, zmaskLo, UINT64_C(33) , true);
            lbits zgsz3588;
            CREATE(lbits)(&zgsz3588);
            and_bits(&zgsz3588, zgsz3586, zgsz3587);
            zgaz3243 = CONVERT_OF(fbits, lbits)(zgsz3588, true);
            KILL(lbits)(&zgsz3588);
            KILL(lbits)(&zgsz3587);
            KILL(lbits)(&zgsz3586);
          }
          {
            lbits zgsz3584;
            CREATE(lbits)(&zgsz3584);
            CONVERT_OF(lbits, fbits)(&zgsz3584, zgaz3243, UINT64_C(33) , true);
            sail_int zgsz3585;
            CREATE(sail_int)(&zgsz3585);
            sail_unsigned(&zgsz3585, zgsz3584);
            zgaz3244 = CONVERT_OF(mach_int, sail_int)(zgsz3585);
            KILL(sail_int)(&zgsz3585);
            KILL(lbits)(&zgsz3584);
          }
        }
        {
          sail_int zgsz3589;
          CREATE(sail_int)(&zgsz3589);
          CONVERT_OF(sail_int, mach_int)(&zgsz3589, zgaz3244);
          sail_int zgsz3590;
          CREATE(sail_int)(&zgsz3590);
          CONVERT_OF(sail_int, mach_int)(&zgsz3590, INT64_C(0));
          zlostSignificantTop = sailgen_neq_int(zgsz3589, zgsz3590);
          KILL(sail_int)(&zgsz3590);
          KILL(sail_int)(&zgsz3589);
        }
        unit zgsz357;
        zgsz357 = UNIT;
      }
      {
        unit zgsz356;
        if (zlostSignificantTop) {
          {
            lbits zgsz3591;
            CREATE(lbits)(&zgsz3591);
            CONVERT_OF(lbits, fbits)(&zgsz3591, zT_ie, UINT64_C(5) , true);
            sail_int zgsz3592;
            CREATE(sail_int)(&zgsz3592);
            CONVERT_OF(sail_int, mach_int)(&zgsz3592, INT64_C(1));
            lbits zgsz3593;
            CREATE(lbits)(&zgsz3593);
            add_bits_int(&zgsz3593, zgsz3591, zgsz3592);
            zT_ie = CONVERT_OF(fbits, lbits)(zgsz3593, true);
            KILL(lbits)(&zgsz3593);
            KILL(sail_int)(&zgsz3592);
            KILL(lbits)(&zgsz3591);
          }
          zgsz356 = UNIT;
        } else {  zgsz356 = UNIT;  }
      }
      uint64_t zlen_ie;
      {
        lbits zgsz3636;
        CREATE(lbits)(&zgsz3636);
        CONVERT_OF(lbits, fbits)(&zgsz3636, zT_ie, UINT64_C(5) , true);
        lbits zgsz3637;
        CREATE(lbits)(&zgsz3637);
        CONVERT_OF(lbits, fbits)(&zgsz3637, zB_ie, UINT64_C(5) , true);
        lbits zgsz3638;
        CREATE(lbits)(&zgsz3638);
        sub_bits(&zgsz3638, zgsz3636, zgsz3637);
        zlen_ie = CONVERT_OF(fbits, lbits)(zgsz3638, true);
        KILL(lbits)(&zgsz3638);
        KILL(lbits)(&zgsz3637);
        KILL(lbits)(&zgsz3636);
      }
      {
        bool zgaz3247;
        {
          fbits zgaz3246;
          {
            int64_t zgaz3245;
            {
              sail_int zgsz3596;
              CREATE(sail_int)(&zgsz3596);
              CONVERT_OF(sail_int, mach_int)(&zgsz3596, zcap_mantissa_width);
              sail_int zgsz3597;
              CREATE(sail_int)(&zgsz3597);
              CONVERT_OF(sail_int, mach_int)(&zgsz3597, INT64_C(4));
              sail_int zgsz3598;
              CREATE(sail_int)(&zgsz3598);
              sub_int(&zgsz3598, zgsz3596, zgsz3597);
              zgaz3245 = CONVERT_OF(mach_int, sail_int)(zgsz3598);
              KILL(sail_int)(&zgsz3598);
              KILL(sail_int)(&zgsz3597);
              KILL(sail_int)(&zgsz3596);
            }
            {
              lbits zgsz3594;
              CREATE(lbits)(&zgsz3594);
              CONVERT_OF(lbits, fbits)(&zgsz3594, zlen_ie, UINT64_C(5) , true);
              sail_int zgsz3595;
              CREATE(sail_int)(&zgsz3595);
              CONVERT_OF(sail_int, mach_int)(&zgsz3595, zgaz3245);
              zgaz3246 = bitvector_access(zgsz3594, zgsz3595);
              KILL(sail_int)(&zgsz3595);
              KILL(lbits)(&zgsz3594);
            }
          }
          zgaz3247 = eq_bit(zgaz3246, UINT64_C(1));
        }
        unit zgsz360;
        if (zgaz3247) {
          {
            zincE = true;
            unit zgsz366;
            zgsz366 = UNIT;
          }
          {
            bool zgsz361;
            if (zlostSignificantBase) {  zgsz361 = true;  } else {
              fbits zgaz3248;
              {
                lbits zgsz3599;
                CREATE(lbits)(&zgsz3599);
                CONVERT_OF(lbits, fbits)(&zgsz3599, zB_ie, UINT64_C(5) , true);
                sail_int zgsz3600;
                CREATE(sail_int)(&zgsz3600);
                CONVERT_OF(sail_int, mach_int)(&zgsz3600, INT64_C(0));
                zgaz3248 = bitvector_access(zgsz3599, zgsz3600);
                KILL(sail_int)(&zgsz3600);
                KILL(lbits)(&zgsz3599);
              }
              zgsz361 = eq_bit(zgaz3248, UINT64_C(1));
            }
            zlostSignificantBase = zgsz361;
            unit zgsz365;
            zgsz365 = UNIT;
          }
          {
            bool zgsz362;
            if (zlostSignificantTop) {  zgsz362 = true;  } else {
              fbits zgaz3249;
              {
                lbits zgsz3601;
                CREATE(lbits)(&zgsz3601);
                CONVERT_OF(lbits, fbits)(&zgsz3601, zT_ie, UINT64_C(5) , true);
                sail_int zgsz3602;
                CREATE(sail_int)(&zgsz3602);
                CONVERT_OF(sail_int, mach_int)(&zgsz3602, INT64_C(0));
                zgaz3249 = bitvector_access(zgsz3601, zgsz3602);
                KILL(sail_int)(&zgsz3602);
                KILL(lbits)(&zgsz3601);
              }
              zgsz362 = eq_bit(zgaz3249, UINT64_C(1));
            }
            zlostSignificantTop = zgsz362;
            unit zgsz364;
            zgsz364 = UNIT;
          }
          {
            uint64_t zgaz3251;
            {
              int64_t zgaz3250;
              {
                sail_int zgsz3606;
                CREATE(sail_int)(&zgsz3606);
                CONVERT_OF(sail_int, mach_int)(&zgsz3606, ze);
                sail_int zgsz3607;
                CREATE(sail_int)(&zgsz3607);
                CONVERT_OF(sail_int, mach_int)(&zgsz3607, INT64_C(4));
                sail_int zgsz3608;
                CREATE(sail_int)(&zgsz3608);
                add_int(&zgsz3608, zgsz3606, zgsz3607);
                zgaz3250 = CONVERT_OF(mach_int, sail_int)(zgsz3608);
                KILL(sail_int)(&zgsz3608);
                KILL(sail_int)(&zgsz3607);
                KILL(sail_int)(&zgsz3606);
              }
              {
                lbits zgsz3603;
                CREATE(lbits)(&zgsz3603);
                CONVERT_OF(lbits, fbits)(&zgsz3603, zbase, UINT64_C(32) , true);
                sail_int zgsz3604;
                CREATE(sail_int)(&zgsz3604);
                CONVERT_OF(sail_int, mach_int)(&zgsz3604, zgaz3250);
                lbits zgsz3605;
                CREATE(lbits)(&zgsz3605);
                shiftr(&zgsz3605, zgsz3603, zgsz3604);
                zgaz3251 = CONVERT_OF(fbits, lbits)(zgsz3605, true);
                KILL(lbits)(&zgsz3605);
                KILL(sail_int)(&zgsz3604);
                KILL(lbits)(&zgsz3603);
              }
            }
            int64_t zgaz3252;
            {
              sail_int zgsz3612;
              CREATE(sail_int)(&zgsz3612);
              CONVERT_OF(sail_int, mach_int)(&zgsz3612, zcap_mantissa_width);
              sail_int zgsz3613;
              CREATE(sail_int)(&zgsz3613);
              CONVERT_OF(sail_int, mach_int)(&zgsz3613, INT64_C(3));
              sail_int zgsz3614;
              CREATE(sail_int)(&zgsz3614);
              sub_int(&zgsz3614, zgsz3612, zgsz3613);
              zgaz3252 = CONVERT_OF(mach_int, sail_int)(zgsz3614);
              KILL(sail_int)(&zgsz3614);
              KILL(sail_int)(&zgsz3613);
              KILL(sail_int)(&zgsz3612);
            }
            {
              lbits zgsz3609;
              CREATE(lbits)(&zgsz3609);
              CONVERT_OF(lbits, fbits)(&zgsz3609, zgaz3251, UINT64_C(32) , true);
              sail_int zgsz3610;
              CREATE(sail_int)(&zgsz3610);
              CONVERT_OF(sail_int, mach_int)(&zgsz3610, zgaz3252);
              lbits zgsz3611;
              CREATE(lbits)(&zgsz3611);
              sail_truncate(&zgsz3611, zgsz3609, zgsz3610);
              zB_ie = CONVERT_OF(fbits, lbits)(zgsz3611, true);
              KILL(lbits)(&zgsz3611);
              KILL(sail_int)(&zgsz3610);
              KILL(lbits)(&zgsz3609);
            }
            unit zgsz363;
            zgsz363 = UNIT;
          }
          int64_t zincT;
          if (zlostSignificantTop) {  zincT = INT64_C(1);  } else {  zincT = INT64_C(0);  }
          uint64_t zgaz3256;
          {
            uint64_t zgaz3254;
            {
              int64_t zgaz3253;
              {
                sail_int zgsz3618;
                CREATE(sail_int)(&zgsz3618);
                CONVERT_OF(sail_int, mach_int)(&zgsz3618, ze);
                sail_int zgsz3619;
                CREATE(sail_int)(&zgsz3619);
                CONVERT_OF(sail_int, mach_int)(&zgsz3619, INT64_C(4));
                sail_int zgsz3620;
                CREATE(sail_int)(&zgsz3620);
                add_int(&zgsz3620, zgsz3618, zgsz3619);
                zgaz3253 = CONVERT_OF(mach_int, sail_int)(zgsz3620);
                KILL(sail_int)(&zgsz3620);
                KILL(sail_int)(&zgsz3619);
                KILL(sail_int)(&zgsz3618);
              }
              {
                lbits zgsz3615;
                CREATE(lbits)(&zgsz3615);
                CONVERT_OF(lbits, fbits)(&zgsz3615, ztop, UINT64_C(33) , true);
                sail_int zgsz3616;
                CREATE(sail_int)(&zgsz3616);
                CONVERT_OF(sail_int, mach_int)(&zgsz3616, zgaz3253);
                lbits zgsz3617;
                CREATE(lbits)(&zgsz3617);
                shiftr(&zgsz3617, zgsz3615, zgsz3616);
                zgaz3254 = CONVERT_OF(fbits, lbits)(zgsz3617, true);
                KILL(lbits)(&zgsz3617);
                KILL(sail_int)(&zgsz3616);
                KILL(lbits)(&zgsz3615);
              }
            }
            int64_t zgaz3255;
            {
              sail_int zgsz3624;
              CREATE(sail_int)(&zgsz3624);
              CONVERT_OF(sail_int, mach_int)(&zgsz3624, zcap_mantissa_width);
              sail_int zgsz3625;
              CREATE(sail_int)(&zgsz3625);
              CONVERT_OF(sail_int, mach_int)(&zgsz3625, INT64_C(3));
              sail_int zgsz3626;
              CREATE(sail_int)(&zgsz3626);
              sub_int(&zgsz3626, zgsz3624, zgsz3625);
              zgaz3255 = CONVERT_OF(mach_int, sail_int)(zgsz3626);
              KILL(sail_int)(&zgsz3626);
              KILL(sail_int)(&zgsz3625);
              KILL(sail_int)(&zgsz3624);
            }
            {
              lbits zgsz3621;
              CREATE(lbits)(&zgsz3621);
              CONVERT_OF(lbits, fbits)(&zgsz3621, zgaz3254, UINT64_C(33) , true);
              sail_int zgsz3622;
              CREATE(sail_int)(&zgsz3622);
              CONVERT_OF(sail_int, mach_int)(&zgsz3622, zgaz3255);
              lbits zgsz3623;
              CREATE(lbits)(&zgsz3623);
              sail_truncate(&zgsz3623, zgsz3621, zgsz3622);
              zgaz3256 = CONVERT_OF(fbits, lbits)(zgsz3623, true);
              KILL(lbits)(&zgsz3623);
              KILL(sail_int)(&zgsz3622);
              KILL(lbits)(&zgsz3621);
            }
          }
          {
            lbits zgsz3627;
            CREATE(lbits)(&zgsz3627);
            CONVERT_OF(lbits, fbits)(&zgsz3627, zgaz3256, UINT64_C(5) , true);
            sail_int zgsz3628;
            CREATE(sail_int)(&zgsz3628);
            CONVERT_OF(sail_int, mach_int)(&zgsz3628, zincT);
            lbits zgsz3629;
            CREATE(lbits)(&zgsz3629);
            add_bits_int(&zgsz3629, zgsz3627, zgsz3628);
            zT_ie = CONVERT_OF(fbits, lbits)(zgsz3629, true);
            KILL(lbits)(&zgsz3629);
            KILL(sail_int)(&zgsz3628);
            KILL(lbits)(&zgsz3627);
          }
          zgsz360 = UNIT;
        } else {  zgsz360 = UNIT;  }
      }
      {
        {
          lbits zgsz3630;
          CREATE(lbits)(&zgsz3630);
          CONVERT_OF(lbits, fbits)(&zgsz3630, zB_ie, UINT64_C(5) , true);
          lbits zgsz3631;
          CREATE(lbits)(&zgsz3631);
          CONVERT_OF(lbits, fbits)(&zgsz3631, UINT64_C(0b000), UINT64_C(3) , true);
          lbits zgsz3632;
          CREATE(lbits)(&zgsz3632);
          append(&zgsz3632, zgsz3630, zgsz3631);
          zBbits = CONVERT_OF(fbits, lbits)(zgsz3632, true);
          KILL(lbits)(&zgsz3632);
          KILL(lbits)(&zgsz3631);
          KILL(lbits)(&zgsz3630);
        }
        unit zgsz359;
        zgsz359 = UNIT;
      }
      {
        lbits zgsz3633;
        CREATE(lbits)(&zgsz3633);
        CONVERT_OF(lbits, fbits)(&zgsz3633, zT_ie, UINT64_C(5) , true);
        lbits zgsz3634;
        CREATE(lbits)(&zgsz3634);
        CONVERT_OF(lbits, fbits)(&zgsz3634, UINT64_C(0b000), UINT64_C(3) , true);
        lbits zgsz3635;
        CREATE(lbits)(&zgsz3635);
        append(&zgsz3635, zgsz3633, zgsz3634);
        zTbits = CONVERT_OF(fbits, lbits)(zgsz3635, true);
        KILL(lbits)(&zgsz3635);
        KILL(lbits)(&zgsz3634);
        KILL(lbits)(&zgsz3633);
      }
      zgsz355 = UNIT;
    } else {  zgsz355 = UNIT;  }
  }
  struct zCapability znewCap;
  {
    uint64_t zgaz3267;
    {
      int64_t zgaz3266;
      if (zincE) {
        {
          sail_int zgsz3639;
          CREATE(sail_int)(&zgsz3639);
          CONVERT_OF(sail_int, mach_int)(&zgsz3639, ze);
          sail_int zgsz3640;
          CREATE(sail_int)(&zgsz3640);
          CONVERT_OF(sail_int, mach_int)(&zgsz3640, INT64_C(1));
          sail_int zgsz3641;
          CREATE(sail_int)(&zgsz3641);
          add_int(&zgsz3641, zgsz3639, zgsz3640);
          zgaz3266 = CONVERT_OF(mach_int, sail_int)(zgsz3641);
          KILL(sail_int)(&zgsz3641);
          KILL(sail_int)(&zgsz3640);
          KILL(sail_int)(&zgsz3639);
        }
      } else {  zgaz3266 = ze;  }
      {
        sail_int zgsz3642;
        CREATE(sail_int)(&zgsz3642);
        CONVERT_OF(sail_int, mach_int)(&zgsz3642, INT64_C(6));
        sail_int zgsz3643;
        CREATE(sail_int)(&zgsz3643);
        CONVERT_OF(sail_int, mach_int)(&zgsz3643, zgaz3266);
        lbits zgsz3644;
        CREATE(lbits)(&zgsz3644);
        sailgen_to_bits(&zgsz3644, zgsz3642, zgsz3643);
        zgaz3267 = CONVERT_OF(fbits, lbits)(zgsz3644, true);
        KILL(lbits)(&zgsz3644);
        KILL(sail_int)(&zgsz3643);
        KILL(sail_int)(&zgsz3642);
      }
    }
    struct zCapability zgsz367;
    zgsz367 = zcap;
    zgsz367.zB = zBbits;
    zgsz367.zE = zgaz3267;
    zgsz367.zT = zTbits;
    zgsz367.zaddress = zbase;
    zgsz367.zinternal_E = zie;
    znewCap = zgsz367;
  }
  bool zexact;
  {
    bool zgaz3265;
    {
      bool zgsz368;
      if (zlostSignificantBase) {  zgsz368 = true;  } else {  zgsz368 = zlostSignificantTop;  }
      zgaz3265 = zgsz368;
    }
    zexact = not(zgaz3265);
  }
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgsz369;
  zgsz369.ztup0 = zexact;
  zgsz369.ztup1 = znewCap;
  zcbz326 = zgsz369;












end_function_116: ;
  return zcbz326;
end_block_exception_117: ;
  struct zCapability zcbz355 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz354 = { .ztup0 = false, .ztup1 = zcbz355 };
  return zcbz354;
}

static uint64_t sailgen_getCapPerms(struct zCapability);

static uint64_t sailgen_getCapPerms(struct zCapability zcap)
{
  __label__ end_function_119, end_block_exception_120;

  uint64_t zcbz327;
  uint64_t zperms;
  {
    uint64_t zgaz3275;
    zgaz3275 = sailgen_getCapHardPerms(zcap);
    {
      sail_int zgsz3657;
      CREATE(sail_int)(&zgsz3657);
      CONVERT_OF(sail_int, mach_int)(&zgsz3657, INT64_C(15));
      lbits zgsz3658;
      CREATE(lbits)(&zgsz3658);
      CONVERT_OF(lbits, fbits)(&zgsz3658, zgaz3275, UINT64_C(12) , true);
      lbits zgsz3659;
      CREATE(lbits)(&zgsz3659);
      sailgen_EXTZ(&zgsz3659, zgsz3657, zgsz3658);
      zperms = CONVERT_OF(fbits, lbits)(zgsz3659, true);
      KILL(lbits)(&zgsz3659);
      KILL(lbits)(&zgsz3658);
      KILL(sail_int)(&zgsz3657);
    }
  }
  uint64_t zgaz3274;
  zgaz3274 = zcap.zuperms;
  {
    lbits zgsz3660;
    CREATE(lbits)(&zgsz3660);
    CONVERT_OF(lbits, fbits)(&zgsz3660, zgaz3274, UINT64_C(0) , true);
    lbits zgsz3661;
    CREATE(lbits)(&zgsz3661);
    CONVERT_OF(lbits, fbits)(&zgsz3661, zperms, UINT64_C(15) , true);
    lbits zgsz3662;
    CREATE(lbits)(&zgsz3662);
    append(&zgsz3662, zgsz3660, zgsz3661);
    zcbz327 = CONVERT_OF(fbits, lbits)(zgsz3662, true);
    KILL(lbits)(&zgsz3662);
    KILL(lbits)(&zgsz3661);
    KILL(lbits)(&zgsz3660);
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
  uint64_t zgaz3277;
  {
    uint64_t zgaz3276;
    {
      lbits zgsz3666;
      CREATE(lbits)(&zgsz3666);
      CONVERT_OF(lbits, fbits)(&zgsz3666, zperms, UINT64_C(15) , true);
      sail_int zgsz3667;
      CREATE(sail_int)(&zgsz3667);
      CONVERT_OF(sail_int, mach_int)(&zgsz3667, zcap_uperms_shift);
      lbits zgsz3668;
      CREATE(lbits)(&zgsz3668);
      shiftr(&zgsz3668, zgsz3666, zgsz3667);
      zgaz3276 = CONVERT_OF(fbits, lbits)(zgsz3668, true);
      KILL(lbits)(&zgsz3668);
      KILL(sail_int)(&zgsz3667);
      KILL(lbits)(&zgsz3666);
    }
    {
      lbits zgsz3663;
      CREATE(lbits)(&zgsz3663);
      CONVERT_OF(lbits, fbits)(&zgsz3663, zgaz3276, UINT64_C(15) , true);
      sail_int zgsz3664;
      CREATE(sail_int)(&zgsz3664);
      CONVERT_OF(sail_int, mach_int)(&zgsz3664, zcap_uperms_width);
      lbits zgsz3665;
      CREATE(lbits)(&zgsz3665);
      sail_truncate(&zgsz3665, zgsz3663, zgsz3664);
      zgaz3277 = CONVERT_OF(fbits, lbits)(zgsz3665, true);
      KILL(lbits)(&zgsz3665);
      KILL(sail_int)(&zgsz3664);
      KILL(lbits)(&zgsz3663);
    }
  }
  bool zgaz3279;
  {
    fbits zgaz3278;
    {
      lbits zgsz3669;
      CREATE(lbits)(&zgsz3669);
      CONVERT_OF(lbits, fbits)(&zgsz3669, zperms, UINT64_C(15) , true);
      sail_int zgsz3670;
      CREATE(sail_int)(&zgsz3670);
      CONVERT_OF(sail_int, mach_int)(&zgsz3670, INT64_C(11));
      zgaz3278 = bitvector_access(zgsz3669, zgsz3670);
      KILL(sail_int)(&zgsz3670);
      KILL(lbits)(&zgsz3669);
    }
    zgaz3279 = sailgen_bit_to_bool(zgaz3278);
  }
  bool zgaz3281;
  {
    fbits zgaz3280;
    {
      lbits zgsz3671;
      CREATE(lbits)(&zgsz3671);
      CONVERT_OF(lbits, fbits)(&zgsz3671, zperms, UINT64_C(15) , true);
      sail_int zgsz3672;
      CREATE(sail_int)(&zgsz3672);
      CONVERT_OF(sail_int, mach_int)(&zgsz3672, INT64_C(10));
      zgaz3280 = bitvector_access(zgsz3671, zgsz3672);
      KILL(sail_int)(&zgsz3672);
      KILL(lbits)(&zgsz3671);
    }
    zgaz3281 = sailgen_bit_to_bool(zgaz3280);
  }
  bool zgaz3283;
  {
    fbits zgaz3282;
    {
      lbits zgsz3673;
      CREATE(lbits)(&zgsz3673);
      CONVERT_OF(lbits, fbits)(&zgsz3673, zperms, UINT64_C(15) , true);
      sail_int zgsz3674;
      CREATE(sail_int)(&zgsz3674);
      CONVERT_OF(sail_int, mach_int)(&zgsz3674, INT64_C(9));
      zgaz3282 = bitvector_access(zgsz3673, zgsz3674);
      KILL(sail_int)(&zgsz3674);
      KILL(lbits)(&zgsz3673);
    }
    zgaz3283 = sailgen_bit_to_bool(zgaz3282);
  }
  bool zgaz3285;
  {
    fbits zgaz3284;
    {
      lbits zgsz3675;
      CREATE(lbits)(&zgsz3675);
      CONVERT_OF(lbits, fbits)(&zgsz3675, zperms, UINT64_C(15) , true);
      sail_int zgsz3676;
      CREATE(sail_int)(&zgsz3676);
      CONVERT_OF(sail_int, mach_int)(&zgsz3676, INT64_C(8));
      zgaz3284 = bitvector_access(zgsz3675, zgsz3676);
      KILL(sail_int)(&zgsz3676);
      KILL(lbits)(&zgsz3675);
    }
    zgaz3285 = sailgen_bit_to_bool(zgaz3284);
  }
  bool zgaz3287;
  {
    fbits zgaz3286;
    {
      lbits zgsz3677;
      CREATE(lbits)(&zgsz3677);
      CONVERT_OF(lbits, fbits)(&zgsz3677, zperms, UINT64_C(15) , true);
      sail_int zgsz3678;
      CREATE(sail_int)(&zgsz3678);
      CONVERT_OF(sail_int, mach_int)(&zgsz3678, INT64_C(7));
      zgaz3286 = bitvector_access(zgsz3677, zgsz3678);
      KILL(sail_int)(&zgsz3678);
      KILL(lbits)(&zgsz3677);
    }
    zgaz3287 = sailgen_bit_to_bool(zgaz3286);
  }
  bool zgaz3289;
  {
    fbits zgaz3288;
    {
      lbits zgsz3679;
      CREATE(lbits)(&zgsz3679);
      CONVERT_OF(lbits, fbits)(&zgsz3679, zperms, UINT64_C(15) , true);
      sail_int zgsz3680;
      CREATE(sail_int)(&zgsz3680);
      CONVERT_OF(sail_int, mach_int)(&zgsz3680, INT64_C(6));
      zgaz3288 = bitvector_access(zgsz3679, zgsz3680);
      KILL(sail_int)(&zgsz3680);
      KILL(lbits)(&zgsz3679);
    }
    zgaz3289 = sailgen_bit_to_bool(zgaz3288);
  }
  bool zgaz3291;
  {
    fbits zgaz3290;
    {
      lbits zgsz3681;
      CREATE(lbits)(&zgsz3681);
      CONVERT_OF(lbits, fbits)(&zgsz3681, zperms, UINT64_C(15) , true);
      sail_int zgsz3682;
      CREATE(sail_int)(&zgsz3682);
      CONVERT_OF(sail_int, mach_int)(&zgsz3682, INT64_C(5));
      zgaz3290 = bitvector_access(zgsz3681, zgsz3682);
      KILL(sail_int)(&zgsz3682);
      KILL(lbits)(&zgsz3681);
    }
    zgaz3291 = sailgen_bit_to_bool(zgaz3290);
  }
  bool zgaz3293;
  {
    fbits zgaz3292;
    {
      lbits zgsz3683;
      CREATE(lbits)(&zgsz3683);
      CONVERT_OF(lbits, fbits)(&zgsz3683, zperms, UINT64_C(15) , true);
      sail_int zgsz3684;
      CREATE(sail_int)(&zgsz3684);
      CONVERT_OF(sail_int, mach_int)(&zgsz3684, INT64_C(4));
      zgaz3292 = bitvector_access(zgsz3683, zgsz3684);
      KILL(sail_int)(&zgsz3684);
      KILL(lbits)(&zgsz3683);
    }
    zgaz3293 = sailgen_bit_to_bool(zgaz3292);
  }
  bool zgaz3295;
  {
    fbits zgaz3294;
    {
      lbits zgsz3685;
      CREATE(lbits)(&zgsz3685);
      CONVERT_OF(lbits, fbits)(&zgsz3685, zperms, UINT64_C(15) , true);
      sail_int zgsz3686;
      CREATE(sail_int)(&zgsz3686);
      CONVERT_OF(sail_int, mach_int)(&zgsz3686, INT64_C(3));
      zgaz3294 = bitvector_access(zgsz3685, zgsz3686);
      KILL(sail_int)(&zgsz3686);
      KILL(lbits)(&zgsz3685);
    }
    zgaz3295 = sailgen_bit_to_bool(zgaz3294);
  }
  bool zgaz3297;
  {
    fbits zgaz3296;
    {
      lbits zgsz3687;
      CREATE(lbits)(&zgsz3687);
      CONVERT_OF(lbits, fbits)(&zgsz3687, zperms, UINT64_C(15) , true);
      sail_int zgsz3688;
      CREATE(sail_int)(&zgsz3688);
      CONVERT_OF(sail_int, mach_int)(&zgsz3688, INT64_C(2));
      zgaz3296 = bitvector_access(zgsz3687, zgsz3688);
      KILL(sail_int)(&zgsz3688);
      KILL(lbits)(&zgsz3687);
    }
    zgaz3297 = sailgen_bit_to_bool(zgaz3296);
  }
  bool zgaz3299;
  {
    fbits zgaz3298;
    {
      lbits zgsz3689;
      CREATE(lbits)(&zgsz3689);
      CONVERT_OF(lbits, fbits)(&zgsz3689, zperms, UINT64_C(15) , true);
      sail_int zgsz3690;
      CREATE(sail_int)(&zgsz3690);
      CONVERT_OF(sail_int, mach_int)(&zgsz3690, INT64_C(1));
      zgaz3298 = bitvector_access(zgsz3689, zgsz3690);
      KILL(sail_int)(&zgsz3690);
      KILL(lbits)(&zgsz3689);
    }
    zgaz3299 = sailgen_bit_to_bool(zgaz3298);
  }
  bool zgaz3301;
  {
    fbits zgaz3300;
    {
      lbits zgsz3691;
      CREATE(lbits)(&zgsz3691);
      CONVERT_OF(lbits, fbits)(&zgsz3691, zperms, UINT64_C(15) , true);
      sail_int zgsz3692;
      CREATE(sail_int)(&zgsz3692);
      CONVERT_OF(sail_int, mach_int)(&zgsz3692, INT64_C(0));
      zgaz3300 = bitvector_access(zgsz3691, zgsz3692);
      KILL(sail_int)(&zgsz3692);
      KILL(lbits)(&zgsz3691);
    }
    zgaz3301 = sailgen_bit_to_bool(zgaz3300);
  }
  struct zCapability zgsz370;
  zgsz370 = zcap;
  zgsz370.zaccess_system_regs = zgaz3281;
  zgsz370.zglobal = zgaz3301;
  zgsz370.zpermit_cinvoke = zgaz3285;
  zgsz370.zpermit_execute = zgaz3299;
  zgsz370.zpermit_load = zgaz3297;
  zgsz370.zpermit_load_cap = zgaz3293;
  zgsz370.zpermit_seal = zgaz3287;
  zgsz370.zpermit_set_CID = zgaz3279;
  zgsz370.zpermit_store = zgaz3295;
  zgsz370.zpermit_store_cap = zgaz3291;
  zgsz370.zpermit_store_local_cap = zgaz3289;
  zgsz370.zpermit_unseal = zgaz3283;
  zgsz370.zuperms = zgaz3277;
  zcbz328 = zgsz370;














end_function_122: ;
  return zcbz328;
end_block_exception_123: ;
  struct zCapability zcbz356 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  return zcbz356;
}

static uint64_t sailgen_getCapFlags(struct zCapability);

static uint64_t sailgen_getCapFlags(struct zCapability zcap)
{
  __label__ end_function_125, end_block_exception_126;

  uint64_t zcbz329;
  bool zgaz3302;
  zgaz3302 = zcap.zflag_cap_mode;
  zcbz329 = sailgen_bool_to_bits(zgaz3302);

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
  int64_t zgaz3304;
  {
    uint64_t zgaz3303;
    zgaz3303 = zcap.zotype;
    {
      lbits zgsz3693;
      CREATE(lbits)(&zgsz3693);
      CONVERT_OF(lbits, fbits)(&zgsz3693, zgaz3303, UINT64_C(4) , true);
      sail_int zgsz3694;
      CREATE(sail_int)(&zgsz3694);
      sail_signed(&zgsz3694, zgsz3693);
      zgaz3304 = CONVERT_OF(mach_int, sail_int)(zgsz3694);
      KILL(sail_int)(&zgsz3694);
      KILL(lbits)(&zgsz3693);
    }
  }
  {
    sail_int zgsz3695;
    CREATE(sail_int)(&zgsz3695);
    CONVERT_OF(sail_int, mach_int)(&zgsz3695, zgaz3304);
    sail_int zgsz3696;
    CREATE(sail_int)(&zgsz3696);
    CONVERT_OF(sail_int, mach_int)(&zgsz3696, zotype_unsealed);
    zcbz330 = sailgen_neq_int(zgsz3695, zgsz3696);
    KILL(sail_int)(&zgsz3696);
    KILL(sail_int)(&zgsz3695);
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
  int64_t zgaz3306;
  {
    uint64_t zgaz3305;
    zgaz3305 = zcap.zotype;
    {
      lbits zgsz3697;
      CREATE(lbits)(&zgsz3697);
      CONVERT_OF(lbits, fbits)(&zgsz3697, zgaz3305, UINT64_C(4) , true);
      sail_int zgsz3698;
      CREATE(sail_int)(&zgsz3698);
      sail_unsigned(&zgsz3698, zgsz3697);
      zgaz3306 = CONVERT_OF(mach_int, sail_int)(zgsz3698);
      KILL(sail_int)(&zgsz3698);
      KILL(lbits)(&zgsz3697);
    }
  }
  {
    sail_int zgsz3699;
    CREATE(sail_int)(&zgsz3699);
    CONVERT_OF(sail_int, mach_int)(&zgsz3699, zgaz3306);
    sail_int zgsz3700;
    CREATE(sail_int)(&zgsz3700);
    CONVERT_OF(sail_int, mach_int)(&zgsz3700, zcap_max_otype);
    zcbz331 = gt(zgsz3699, zgsz3700);
    KILL(sail_int)(&zgsz3700);
    KILL(sail_int)(&zgsz3699);
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
  struct ztuple_z8z5bv32zCz0z5bv33z9 zgaz3307;
  zgaz3307 = sailgen_getCapBoundsBits(zc);
  uint64_t zgsz371;
  {
    uint64_t zbase;
    zbase = zgaz3307.ztup0;
    zgsz371 = zbase;
    goto finish_match_134;
  }
case_135: ;
  sail_match_failure("getCapBaseBits");
finish_match_134: ;
  zcbz332 = zgsz371;


end_function_136: ;
  return zcbz332;
end_block_exception_137: ;

  return UINT64_C(0xdeadc0de);
}

static int64_t sailgen_getCapLength(struct zCapability);

static int64_t sailgen_getCapLength(struct zCapability zc)
{
  __label__ case_140, finish_match_139, end_function_141, end_block_exception_142;

  int64_t zcbz333;
  struct ztuple_z8z5i64zCz0z5i64z9 zgaz3308;
  zgaz3308 = sailgen_getCapBounds(zc);
  int64_t zgsz373;
  {
    int64_t zbase;
    zbase = zgaz3308.ztup0;
    int64_t ztop;
    ztop = zgaz3308.ztup1;
    {
      bool zgaz3311;
      {
        bool zgaz3310;
        {
          bool zgaz3309;
          zgaz3309 = zc.ztag;
          zgaz3310 = not(zgaz3309);
        }
        bool zgsz374;
        if (zgaz3310) {  zgsz374 = true;  } else {
          {
            sail_int zgsz3701;
            CREATE(sail_int)(&zgsz3701);
            CONVERT_OF(sail_int, mach_int)(&zgsz3701, ztop);
            sail_int zgsz3702;
            CREATE(sail_int)(&zgsz3702);
            CONVERT_OF(sail_int, mach_int)(&zgsz3702, zbase);
            zgsz374 = gteq(zgsz3701, zgsz3702);
            KILL(sail_int)(&zgsz3702);
            KILL(sail_int)(&zgsz3701);
          }
        }
        zgaz3311 = zgsz374;
      }
      unit zgsz375;
      zgsz375 = sail_assert(zgaz3311, "src/cheri_cap_common.sail:453.40-453.41");
    }
    int64_t zgaz3312;
    {
      sail_int zgsz3708;
      CREATE(sail_int)(&zgsz3708);
      CONVERT_OF(sail_int, mach_int)(&zgsz3708, ztop);
      sail_int zgsz3709;
      CREATE(sail_int)(&zgsz3709);
      CONVERT_OF(sail_int, mach_int)(&zgsz3709, zbase);
      sail_int zgsz3710;
      CREATE(sail_int)(&zgsz3710);
      sub_int(&zgsz3710, zgsz3708, zgsz3709);
      zgaz3312 = CONVERT_OF(mach_int, sail_int)(zgsz3710);
      KILL(sail_int)(&zgsz3710);
      KILL(sail_int)(&zgsz3709);
      KILL(sail_int)(&zgsz3708);
    }
    int64_t zgaz3313;
    {
      sail_int zgsz3706;
      CREATE(sail_int)(&zgsz3706);
      CONVERT_OF(sail_int, mach_int)(&zgsz3706, zcap_len_width);
      sail_int zgsz3707;
      CREATE(sail_int)(&zgsz3707);
      pow2(&zgsz3707, zgsz3706);
      zgaz3313 = CONVERT_OF(mach_int, sail_int)(zgsz3707);
      KILL(sail_int)(&zgsz3707);
      KILL(sail_int)(&zgsz3706);
    }
    {
      sail_int zgsz3703;
      CREATE(sail_int)(&zgsz3703);
      CONVERT_OF(sail_int, mach_int)(&zgsz3703, zgaz3312);
      sail_int zgsz3704;
      CREATE(sail_int)(&zgsz3704);
      CONVERT_OF(sail_int, mach_int)(&zgsz3704, zgaz3313);
      sail_int zgsz3705;
      CREATE(sail_int)(&zgsz3705);
      emod_int(&zgsz3705, zgsz3703, zgsz3704);
      zgsz373 = CONVERT_OF(mach_int, sail_int)(zgsz3705);
      KILL(sail_int)(&zgsz3705);
      KILL(sail_int)(&zgsz3704);
      KILL(sail_int)(&zgsz3703);
    }
    goto finish_match_139;
  }
case_140: ;
  sail_match_failure("getCapLength");
finish_match_139: ;
  zcbz333 = zgsz373;


end_function_141: ;
  return zcbz333;
end_block_exception_142: ;

  return INT64_C(0xdeadc0de);
}

static bool sailgen_inCapBounds(struct zCapability, uint64_t, int64_t);

static bool sailgen_inCapBounds(struct zCapability zcap, uint64_t zaddr, int64_t zsizze)
{
  __label__ case_145, finish_match_144, end_function_146, end_block_exception_147;

  bool zcbz334;
  struct ztuple_z8z5i64zCz0z5i64z9 zgaz3314;
  zgaz3314 = sailgen_getCapBounds(zcap);
  bool zgsz377;
  {
    int64_t zbase;
    zbase = zgaz3314.ztup0;
    int64_t ztop;
    ztop = zgaz3314.ztup1;
    int64_t za;
    {
      lbits zgsz3718;
      CREATE(lbits)(&zgsz3718);
      CONVERT_OF(lbits, fbits)(&zgsz3718, zaddr, UINT64_C(32) , true);
      sail_int zgsz3719;
      CREATE(sail_int)(&zgsz3719);
      sail_unsigned(&zgsz3719, zgsz3718);
      za = CONVERT_OF(mach_int, sail_int)(zgsz3719);
      KILL(sail_int)(&zgsz3719);
      KILL(lbits)(&zgsz3718);
    }
    bool zgaz3316;
    {
      sail_int zgsz3716;
      CREATE(sail_int)(&zgsz3716);
      CONVERT_OF(sail_int, mach_int)(&zgsz3716, za);
      sail_int zgsz3717;
      CREATE(sail_int)(&zgsz3717);
      CONVERT_OF(sail_int, mach_int)(&zgsz3717, zbase);
      zgaz3316 = gteq(zgsz3716, zgsz3717);
      KILL(sail_int)(&zgsz3717);
      KILL(sail_int)(&zgsz3716);
    }
    bool zgsz378;
    if (zgaz3316) {
      int64_t zgaz3315;
      {
        sail_int zgsz3713;
        CREATE(sail_int)(&zgsz3713);
        CONVERT_OF(sail_int, mach_int)(&zgsz3713, za);
        sail_int zgsz3714;
        CREATE(sail_int)(&zgsz3714);
        CONVERT_OF(sail_int, mach_int)(&zgsz3714, zsizze);
        sail_int zgsz3715;
        CREATE(sail_int)(&zgsz3715);
        add_int(&zgsz3715, zgsz3713, zgsz3714);
        zgaz3315 = CONVERT_OF(mach_int, sail_int)(zgsz3715);
        KILL(sail_int)(&zgsz3715);
        KILL(sail_int)(&zgsz3714);
        KILL(sail_int)(&zgsz3713);
      }
      {
        sail_int zgsz3711;
        CREATE(sail_int)(&zgsz3711);
        CONVERT_OF(sail_int, mach_int)(&zgsz3711, zgaz3315);
        sail_int zgsz3712;
        CREATE(sail_int)(&zgsz3712);
        CONVERT_OF(sail_int, mach_int)(&zgsz3712, ztop);
        zgsz378 = lteq(zgsz3711, zgsz3712);
        KILL(sail_int)(&zgsz3712);
        KILL(sail_int)(&zgsz3711);
      }
    } else {  zgsz378 = false;  }
    zgsz377 = zgsz378;
    goto finish_match_144;
  }
case_145: ;
  sail_match_failure("inCapBounds");
finish_match_144: ;
  zcbz334 = zgsz377;


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
  bool zgaz3318;
  {
    bool zgaz3317;
    zgaz3317 = zcap.ztag;
    bool zgsz380;
    if (zgaz3317) {  zgsz380 = not(zcond);  } else {  zgsz380 = false;  }
    zgaz3318 = zgsz380;
  }
  struct zCapability zgsz381;
  zgsz381 = zcap;
  zgsz381.ztag = zgaz3318;
  zcbz335 = zgsz381;


end_function_149: ;
  return zcbz335;
end_block_exception_150: ;
  struct zCapability zcbz357 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  return zcbz357;
}

static struct zCapability sailgen_clearTagIfSealed(struct zCapability);

static struct zCapability sailgen_clearTagIfSealed(struct zCapability zcap)
{
  __label__ end_function_152, end_block_exception_153;

  struct zCapability zcbz336;
  bool zgaz3319;
  zgaz3319 = sailgen_isCapSealed(zcap);
  zcbz336 = sailgen_clearTagIf(zcap, zgaz3319);

end_function_152: ;
  return zcbz336;
end_block_exception_153: ;
  struct zCapability zcbz358 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  return zcbz358;
}

static bool sailgen_capBoundsEqual(struct zCapability, struct zCapability);

static bool sailgen_capBoundsEqual(struct zCapability zc1, struct zCapability zc2)
{
  __label__ case_156, finish_match_155, end_function_159, end_block_exception_160;

  bool zcbz337;
  struct ztuple_z8z5i64zCz0z5i64z9 zgaz3320;
  zgaz3320 = sailgen_getCapBounds(zc1);
  bool zgsz382;
  {
    __label__ case_158, finish_match_157;

    int64_t zbase1;
    zbase1 = zgaz3320.ztup0;
    int64_t ztop1;
    ztop1 = zgaz3320.ztup1;
    struct ztuple_z8z5i64zCz0z5i64z9 zgaz3321;
    zgaz3321 = sailgen_getCapBounds(zc2);
    bool zgsz383;
    {
      int64_t zbase2;
      zbase2 = zgaz3321.ztup0;
      int64_t ztop2;
      ztop2 = zgaz3321.ztup1;
      bool zgaz3322;
      {
        sail_int zgsz3722;
        CREATE(sail_int)(&zgsz3722);
        CONVERT_OF(sail_int, mach_int)(&zgsz3722, zbase1);
        sail_int zgsz3723;
        CREATE(sail_int)(&zgsz3723);
        CONVERT_OF(sail_int, mach_int)(&zgsz3723, zbase2);
        zgaz3322 = eq_int(zgsz3722, zgsz3723);
        KILL(sail_int)(&zgsz3723);
        KILL(sail_int)(&zgsz3722);
      }
      bool zgsz384;
      if (zgaz3322) {
        {
          sail_int zgsz3720;
          CREATE(sail_int)(&zgsz3720);
          CONVERT_OF(sail_int, mach_int)(&zgsz3720, ztop1);
          sail_int zgsz3721;
          CREATE(sail_int)(&zgsz3721);
          CONVERT_OF(sail_int, mach_int)(&zgsz3721, ztop2);
          zgsz384 = eq_int(zgsz3720, zgsz3721);
          KILL(sail_int)(&zgsz3721);
          KILL(sail_int)(&zgsz3720);
        }
      } else {  zgsz384 = false;  }
      zgsz383 = zgsz384;
      goto finish_match_157;
    }
  case_158: ;
    sail_match_failure("capBoundsEqual");
  finish_match_157: ;
    zgsz382 = zgsz383;
    goto finish_match_155;
  }
case_156: ;
  sail_match_failure("capBoundsEqual");
finish_match_155: ;
  zcbz337 = zgsz382;


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
  struct zCapability zcbz360 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz359 = { .ztup0 = false, .ztup1 = zcbz360 };
  return zcbz359;
}

static bool sailgen_fastRepCheck(struct zCapability, uint64_t);

static bool sailgen_fastRepCheck(struct zCapability zc, uint64_t zi)
{
  __label__ end_function_165, end_block_exception_166;

  bool zcbz339;
  int64_t zE;
  {
    uint64_t zgaz3336;
    zgaz3336 = zc.zE;
    {
      lbits zgsz3724;
      CREATE(lbits)(&zgsz3724);
      CONVERT_OF(lbits, fbits)(&zgsz3724, zgaz3336, UINT64_C(6) , true);
      sail_int zgsz3725;
      CREATE(sail_int)(&zgsz3725);
      sail_unsigned(&zgsz3725, zgsz3724);
      zE = CONVERT_OF(mach_int, sail_int)(zgsz3725);
      KILL(sail_int)(&zgsz3725);
      KILL(lbits)(&zgsz3724);
    }
  }
  bool zgaz3324;
  {
    int64_t zgaz3323;
    {
      sail_int zgsz3728;
      CREATE(sail_int)(&zgsz3728);
      CONVERT_OF(sail_int, mach_int)(&zgsz3728, zcap_max_E);
      sail_int zgsz3729;
      CREATE(sail_int)(&zgsz3729);
      CONVERT_OF(sail_int, mach_int)(&zgsz3729, INT64_C(2));
      sail_int zgsz3730;
      CREATE(sail_int)(&zgsz3730);
      sub_int(&zgsz3730, zgsz3728, zgsz3729);
      zgaz3323 = CONVERT_OF(mach_int, sail_int)(zgsz3730);
      KILL(sail_int)(&zgsz3730);
      KILL(sail_int)(&zgsz3729);
      KILL(sail_int)(&zgsz3728);
    }
    {
      sail_int zgsz3726;
      CREATE(sail_int)(&zgsz3726);
      CONVERT_OF(sail_int, mach_int)(&zgsz3726, zE);
      sail_int zgsz3727;
      CREATE(sail_int)(&zgsz3727);
      CONVERT_OF(sail_int, mach_int)(&zgsz3727, zgaz3323);
      zgaz3324 = gteq(zgsz3726, zgsz3727);
      KILL(sail_int)(&zgsz3727);
      KILL(sail_int)(&zgsz3726);
    }
  }
  if (zgaz3324) {  zcbz339 = true;  } else {
    int64_t zi_top;
    {
      uint64_t zgaz3335;
      {
        int64_t zgaz3334;
        {
          sail_int zgsz3734;
          CREATE(sail_int)(&zgsz3734);
          CONVERT_OF(sail_int, mach_int)(&zgsz3734, zE);
          sail_int zgsz3735;
          CREATE(sail_int)(&zgsz3735);
          CONVERT_OF(sail_int, mach_int)(&zgsz3735, zcap_mantissa_width);
          sail_int zgsz3736;
          CREATE(sail_int)(&zgsz3736);
          add_int(&zgsz3736, zgsz3734, zgsz3735);
          zgaz3334 = CONVERT_OF(mach_int, sail_int)(zgsz3736);
          KILL(sail_int)(&zgsz3736);
          KILL(sail_int)(&zgsz3735);
          KILL(sail_int)(&zgsz3734);
        }
        {
          lbits zgsz3731;
          CREATE(lbits)(&zgsz3731);
          CONVERT_OF(lbits, fbits)(&zgsz3731, zi, UINT64_C(32) , true);
          sail_int zgsz3732;
          CREATE(sail_int)(&zgsz3732);
          CONVERT_OF(sail_int, mach_int)(&zgsz3732, zgaz3334);
          lbits zgsz3733;
          CREATE(lbits)(&zgsz3733);
          arith_shiftr(&zgsz3733, zgsz3731, zgsz3732);
          zgaz3335 = CONVERT_OF(fbits, lbits)(zgsz3733, true);
          KILL(lbits)(&zgsz3733);
          KILL(sail_int)(&zgsz3732);
          KILL(lbits)(&zgsz3731);
        }
      }
      {
        lbits zgsz3737;
        CREATE(lbits)(&zgsz3737);
        CONVERT_OF(lbits, fbits)(&zgsz3737, zgaz3335, UINT64_C(32) , true);
        sail_int zgsz3738;
        CREATE(sail_int)(&zgsz3738);
        sail_signed(&zgsz3738, zgsz3737);
        zi_top = CONVERT_OF(mach_int, sail_int)(zgsz3738);
        KILL(sail_int)(&zgsz3738);
        KILL(lbits)(&zgsz3737);
      }
    }
    uint64_t zi_mid;
    {
      uint64_t zgaz3333;
      {
        lbits zgsz3742;
        CREATE(lbits)(&zgsz3742);
        CONVERT_OF(lbits, fbits)(&zgsz3742, zi, UINT64_C(32) , true);
        sail_int zgsz3743;
        CREATE(sail_int)(&zgsz3743);
        CONVERT_OF(sail_int, mach_int)(&zgsz3743, zE);
        lbits zgsz3744;
        CREATE(lbits)(&zgsz3744);
        shiftr(&zgsz3744, zgsz3742, zgsz3743);
        zgaz3333 = CONVERT_OF(fbits, lbits)(zgsz3744, true);
        KILL(lbits)(&zgsz3744);
        KILL(sail_int)(&zgsz3743);
        KILL(lbits)(&zgsz3742);
      }
      {
        lbits zgsz3739;
        CREATE(lbits)(&zgsz3739);
        CONVERT_OF(lbits, fbits)(&zgsz3739, zgaz3333, UINT64_C(32) , true);
        sail_int zgsz3740;
        CREATE(sail_int)(&zgsz3740);
        CONVERT_OF(sail_int, mach_int)(&zgsz3740, zcap_mantissa_width);
        lbits zgsz3741;
        CREATE(lbits)(&zgsz3741);
        sail_truncate(&zgsz3741, zgsz3739, zgsz3740);
        zi_mid = CONVERT_OF(fbits, lbits)(zgsz3741, true);
        KILL(lbits)(&zgsz3741);
        KILL(sail_int)(&zgsz3740);
        KILL(lbits)(&zgsz3739);
      }
    }
    uint64_t za_mid;
    {
      uint64_t zgaz3332;
      {
        uint64_t zgaz3331;
        zgaz3331 = zc.zaddress;
        {
          lbits zgsz3745;
          CREATE(lbits)(&zgsz3745);
          CONVERT_OF(lbits, fbits)(&zgsz3745, zgaz3331, UINT64_C(32) , true);
          sail_int zgsz3746;
          CREATE(sail_int)(&zgsz3746);
          CONVERT_OF(sail_int, mach_int)(&zgsz3746, zE);
          lbits zgsz3747;
          CREATE(lbits)(&zgsz3747);
          shiftr(&zgsz3747, zgsz3745, zgsz3746);
          zgaz3332 = CONVERT_OF(fbits, lbits)(zgsz3747, true);
          KILL(lbits)(&zgsz3747);
          KILL(sail_int)(&zgsz3746);
          KILL(lbits)(&zgsz3745);
        }
      }
      {
        lbits zgsz3748;
        CREATE(lbits)(&zgsz3748);
        CONVERT_OF(lbits, fbits)(&zgsz3748, zgaz3332, UINT64_C(32) , true);
        sail_int zgsz3749;
        CREATE(sail_int)(&zgsz3749);
        CONVERT_OF(sail_int, mach_int)(&zgsz3749, zcap_mantissa_width);
        lbits zgsz3750;
        CREATE(lbits)(&zgsz3750);
        sail_truncate(&zgsz3750, zgsz3748, zgsz3749);
        za_mid = CONVERT_OF(fbits, lbits)(zgsz3750, true);
        KILL(lbits)(&zgsz3750);
        KILL(sail_int)(&zgsz3749);
        KILL(lbits)(&zgsz3748);
      }
    }
    uint64_t zB3;
    {
      uint64_t zgaz3330;
      zgaz3330 = zc.zB;
      {
        lbits zgsz3751;
        CREATE(lbits)(&zgsz3751);
        CONVERT_OF(lbits, fbits)(&zgsz3751, zgaz3330, UINT64_C(8) , true);
        sail_int zgsz3752;
        CREATE(sail_int)(&zgsz3752);
        CONVERT_OF(sail_int, mach_int)(&zgsz3752, INT64_C(3));
        lbits zgsz3753;
        CREATE(lbits)(&zgsz3753);
        sail_truncateLSB(&zgsz3753, zgsz3751, zgsz3752);
        zB3 = CONVERT_OF(fbits, lbits)(zgsz3753, true);
        KILL(lbits)(&zgsz3753);
        KILL(sail_int)(&zgsz3752);
        KILL(lbits)(&zgsz3751);
      }
    }
    uint64_t zR3;
    {
      lbits zgsz3778;
      CREATE(lbits)(&zgsz3778);
      CONVERT_OF(lbits, fbits)(&zgsz3778, zB3, UINT64_C(3) , true);
      lbits zgsz3779;
      CREATE(lbits)(&zgsz3779);
      CONVERT_OF(lbits, fbits)(&zgsz3779, UINT64_C(0b001), UINT64_C(3) , true);
      lbits zgsz3780;
      CREATE(lbits)(&zgsz3780);
      sub_bits(&zgsz3780, zgsz3778, zgsz3779);
      zR3 = CONVERT_OF(fbits, lbits)(zgsz3780, true);
      KILL(lbits)(&zgsz3780);
      KILL(lbits)(&zgsz3779);
      KILL(lbits)(&zgsz3778);
    }
    uint64_t zR;
    {
      uint64_t zgaz3329;
      {
        int64_t zgaz3328;
        {
          sail_int zgsz3756;
          CREATE(sail_int)(&zgsz3756);
          CONVERT_OF(sail_int, mach_int)(&zgsz3756, zcap_mantissa_width);
          sail_int zgsz3757;
          CREATE(sail_int)(&zgsz3757);
          CONVERT_OF(sail_int, mach_int)(&zgsz3757, INT64_C(3));
          sail_int zgsz3758;
          CREATE(sail_int)(&zgsz3758);
          sub_int(&zgsz3758, zgsz3756, zgsz3757);
          zgaz3328 = CONVERT_OF(mach_int, sail_int)(zgsz3758);
          KILL(sail_int)(&zgsz3758);
          KILL(sail_int)(&zgsz3757);
          KILL(sail_int)(&zgsz3756);
        }
        {
          sail_int zgsz3754;
          CREATE(sail_int)(&zgsz3754);
          CONVERT_OF(sail_int, mach_int)(&zgsz3754, zgaz3328);
          lbits zgsz3755;
          CREATE(lbits)(&zgsz3755);
          sailgen_zzeros_implicit(&zgsz3755, zgsz3754);
          zgaz3329 = CONVERT_OF(fbits, lbits)(zgsz3755, true);
          KILL(lbits)(&zgsz3755);
          KILL(sail_int)(&zgsz3754);
        }
      }
      {
        lbits zgsz3759;
        CREATE(lbits)(&zgsz3759);
        CONVERT_OF(lbits, fbits)(&zgsz3759, zR3, UINT64_C(3) , true);
        lbits zgsz3760;
        CREATE(lbits)(&zgsz3760);
        CONVERT_OF(lbits, fbits)(&zgsz3760, zgaz3329, UINT64_C(5) , true);
        lbits zgsz3761;
        CREATE(lbits)(&zgsz3761);
        append(&zgsz3761, zgsz3759, zgsz3760);
        zR = CONVERT_OF(fbits, lbits)(zgsz3761, true);
        KILL(lbits)(&zgsz3761);
        KILL(lbits)(&zgsz3760);
        KILL(lbits)(&zgsz3759);
      }
    }
    uint64_t zdiff;
    {
      lbits zgsz3775;
      CREATE(lbits)(&zgsz3775);
      CONVERT_OF(lbits, fbits)(&zgsz3775, zR, UINT64_C(8) , true);
      lbits zgsz3776;
      CREATE(lbits)(&zgsz3776);
      CONVERT_OF(lbits, fbits)(&zgsz3776, za_mid, UINT64_C(8) , true);
      lbits zgsz3777;
      CREATE(lbits)(&zgsz3777);
      sub_bits(&zgsz3777, zgsz3775, zgsz3776);
      zdiff = CONVERT_OF(fbits, lbits)(zgsz3777, true);
      KILL(lbits)(&zgsz3777);
      KILL(lbits)(&zgsz3776);
      KILL(lbits)(&zgsz3775);
    }
    uint64_t zdiff1;
    {
      lbits zgsz3772;
      CREATE(lbits)(&zgsz3772);
      CONVERT_OF(lbits, fbits)(&zgsz3772, zdiff, UINT64_C(8) , true);
      sail_int zgsz3773;
      CREATE(sail_int)(&zgsz3773);
      CONVERT_OF(sail_int, mach_int)(&zgsz3773, INT64_C(1));
      lbits zgsz3774;
      CREATE(lbits)(&zgsz3774);
      sub_bits_int(&zgsz3774, zgsz3772, zgsz3773);
      zdiff1 = CONVERT_OF(fbits, lbits)(zgsz3774, true);
      KILL(lbits)(&zgsz3774);
      KILL(sail_int)(&zgsz3773);
      KILL(lbits)(&zgsz3772);
    }
    bool zgaz3325;
    {
      sail_int zgsz3770;
      CREATE(sail_int)(&zgsz3770);
      CONVERT_OF(sail_int, mach_int)(&zgsz3770, zi_top);
      sail_int zgsz3771;
      CREATE(sail_int)(&zgsz3771);
      CONVERT_OF(sail_int, mach_int)(&zgsz3771, INT64_C(0));
      zgaz3325 = eq_int(zgsz3770, zgsz3771);
      KILL(sail_int)(&zgsz3771);
      KILL(sail_int)(&zgsz3770);
    }
    if (zgaz3325) {
      {
        lbits zgsz3768;
        CREATE(lbits)(&zgsz3768);
        CONVERT_OF(lbits, fbits)(&zgsz3768, zi_mid, UINT64_C(8) , true);
        lbits zgsz3769;
        CREATE(lbits)(&zgsz3769);
        CONVERT_OF(lbits, fbits)(&zgsz3769, zdiff1, UINT64_C(8) , true);
        zcbz339 = sailgen_z8operatorz0zI_uz9(zgsz3768, zgsz3769);
        KILL(lbits)(&zgsz3769);
        KILL(lbits)(&zgsz3768);
      }
    } else {
      bool zgaz3326;
      {
        sail_int zgsz3766;
        CREATE(sail_int)(&zgsz3766);
        CONVERT_OF(sail_int, mach_int)(&zgsz3766, zi_top);
        sail_int zgsz3767;
        CREATE(sail_int)(&zgsz3767);
        CONVERT_OF(sail_int, mach_int)(&zgsz3767, INT64_C(-1));
        zgaz3326 = eq_int(zgsz3766, zgsz3767);
        KILL(sail_int)(&zgsz3767);
        KILL(sail_int)(&zgsz3766);
      }
      if (zgaz3326) {
        bool zgaz3327;
        {
          lbits zgsz3764;
          CREATE(lbits)(&zgsz3764);
          CONVERT_OF(lbits, fbits)(&zgsz3764, zi_mid, UINT64_C(8) , true);
          lbits zgsz3765;
          CREATE(lbits)(&zgsz3765);
          CONVERT_OF(lbits, fbits)(&zgsz3765, zdiff, UINT64_C(8) , true);
          zgaz3327 = sailgen_z8operatorz0zKzJ_uz9(zgsz3764, zgsz3765);
          KILL(lbits)(&zgsz3765);
          KILL(lbits)(&zgsz3764);
        }
        bool zgsz389;
        if (zgaz3327) {
          {
            lbits zgsz3762;
            CREATE(lbits)(&zgsz3762);
            CONVERT_OF(lbits, fbits)(&zgsz3762, zR, UINT64_C(8) , true);
            lbits zgsz3763;
            CREATE(lbits)(&zgsz3763);
            CONVERT_OF(lbits, fbits)(&zgsz3763, za_mid, UINT64_C(8) , true);
            zgsz389 = neq_bits(zgsz3762, zgsz3763);
            KILL(lbits)(&zgsz3763);
            KILL(lbits)(&zgsz3762);
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

  int64_t zlen;
  zlen = sailgen_getCapLength(zcap);
  sail_string zlen_str;
  CREATE(sail_string)(&zlen_str);
  {
    uint64_t zgaz3365;
    {
      int64_t zgaz3364;
      {
        sail_int zgsz3784;
        CREATE(sail_int)(&zgsz3784);
        CONVERT_OF(sail_int, mach_int)(&zgsz3784, zcap_len_width);
        sail_int zgsz3785;
        CREATE(sail_int)(&zgsz3785);
        CONVERT_OF(sail_int, mach_int)(&zgsz3785, INT64_C(3));
        sail_int zgsz3786;
        CREATE(sail_int)(&zgsz3786);
        add_int(&zgsz3786, zgsz3784, zgsz3785);
        zgaz3364 = CONVERT_OF(mach_int, sail_int)(zgsz3786);
        KILL(sail_int)(&zgsz3786);
        KILL(sail_int)(&zgsz3785);
        KILL(sail_int)(&zgsz3784);
      }
      {
        sail_int zgsz3781;
        CREATE(sail_int)(&zgsz3781);
        CONVERT_OF(sail_int, mach_int)(&zgsz3781, zgaz3364);
        sail_int zgsz3782;
        CREATE(sail_int)(&zgsz3782);
        CONVERT_OF(sail_int, mach_int)(&zgsz3782, zlen);
        lbits zgsz3783;
        CREATE(lbits)(&zgsz3783);
        sailgen_to_bits(&zgsz3783, zgsz3781, zgsz3782);
        zgaz3365 = CONVERT_OF(fbits, lbits)(zgsz3783, true);
        KILL(lbits)(&zgsz3783);
        KILL(sail_int)(&zgsz3782);
        KILL(sail_int)(&zgsz3781);
      }
    }
    {
      lbits zgsz3787;
      CREATE(lbits)(&zgsz3787);
      CONVERT_OF(lbits, fbits)(&zgsz3787, zgaz3365, UINT64_C(36) , true);
      string_of_lbits(&zlen_str, zgsz3787);
      KILL(lbits)(&zgsz3787);
    }
  }
  uint64_t zotype64;
  {
    bool zgaz3361;
    zgaz3361 = sailgen_hasReservedOType(zcap);
    if (zgaz3361) {
      uint64_t zgaz3362;
      zgaz3362 = zcap.zotype;
      {
        sail_int zgsz3791;
        CREATE(sail_int)(&zgsz3791);
        CONVERT_OF(sail_int, mach_int)(&zgsz3791, INT64_C(32));
        lbits zgsz3792;
        CREATE(lbits)(&zgsz3792);
        CONVERT_OF(lbits, fbits)(&zgsz3792, zgaz3362, UINT64_C(4) , true);
        lbits zgsz3793;
        CREATE(lbits)(&zgsz3793);
        sailgen_EXTS(&zgsz3793, zgsz3791, zgsz3792);
        zotype64 = CONVERT_OF(fbits, lbits)(zgsz3793, true);
        KILL(lbits)(&zgsz3793);
        KILL(lbits)(&zgsz3792);
        KILL(sail_int)(&zgsz3791);
      }
    } else {
      uint64_t zgaz3363;
      zgaz3363 = zcap.zotype;
      {
        sail_int zgsz3788;
        CREATE(sail_int)(&zgsz3788);
        CONVERT_OF(sail_int, mach_int)(&zgsz3788, INT64_C(32));
        lbits zgsz3789;
        CREATE(lbits)(&zgsz3789);
        CONVERT_OF(lbits, fbits)(&zgsz3789, zgaz3363, UINT64_C(4) , true);
        lbits zgsz3790;
        CREATE(lbits)(&zgsz3790);
        sailgen_EXTZ(&zgsz3790, zgsz3788, zgsz3789);
        zotype64 = CONVERT_OF(fbits, lbits)(zgsz3790, true);
        KILL(lbits)(&zgsz3790);
        KILL(lbits)(&zgsz3789);
        KILL(sail_int)(&zgsz3788);
      }
    }
  }
  sail_string zgaz3360;
  CREATE(sail_string)(&zgaz3360);
  {
    sail_string zgaz3358;
    CREATE(sail_string)(&zgaz3358);
    {
      bool zgaz3337;
      zgaz3337 = zcap.ztag;
      if (zgaz3337) {  COPY(sail_string)(&zgaz3358, "1");  } else {  COPY(sail_string)(&zgaz3358, "0");  }
    }
    sail_string zgaz3359;
    CREATE(sail_string)(&zgaz3359);
    {
      sail_string zgaz3357;
      CREATE(sail_string)(&zgaz3357);
      {
        sail_string zgaz3355;
        CREATE(sail_string)(&zgaz3355);
        {
          bool zgaz3338;
          zgaz3338 = sailgen_isCapSealed(zcap);
          if (zgaz3338) {  COPY(sail_string)(&zgaz3355, "1");  } else {  COPY(sail_string)(&zgaz3355, "0");  }
        }
        sail_string zgaz3356;
        CREATE(sail_string)(&zgaz3356);
        {
          sail_string zgaz3354;
          CREATE(sail_string)(&zgaz3354);
          {
            sail_string zgaz3352;
            CREATE(sail_string)(&zgaz3352);
            {
              uint64_t zgaz3340;
              {
                uint64_t zgaz3339;
                zgaz3339 = sailgen_getCapPerms(zcap);
                {
                  lbits zgsz3794;
                  CREATE(lbits)(&zgsz3794);
                  CONVERT_OF(lbits, fbits)(&zgsz3794, UINT64_C(0b0), UINT64_C(1) , true);
                  lbits zgsz3795;
                  CREATE(lbits)(&zgsz3795);
                  CONVERT_OF(lbits, fbits)(&zgsz3795, zgaz3339, UINT64_C(15) , true);
                  lbits zgsz3796;
                  CREATE(lbits)(&zgsz3796);
                  append(&zgsz3796, zgsz3794, zgsz3795);
                  zgaz3340 = CONVERT_OF(fbits, lbits)(zgsz3796, true);
                  KILL(lbits)(&zgsz3796);
                  KILL(lbits)(&zgsz3795);
                  KILL(lbits)(&zgsz3794);
                }
              }
              {
                lbits zgsz3797;
                CREATE(lbits)(&zgsz3797);
                CONVERT_OF(lbits, fbits)(&zgsz3797, zgaz3340, UINT64_C(16) , true);
                string_of_lbits(&zgaz3352, zgsz3797);
                KILL(lbits)(&zgsz3797);
              }
            }
            sail_string zgaz3353;
            CREATE(sail_string)(&zgaz3353);
            {
              sail_string zgaz3351;
              CREATE(sail_string)(&zgaz3351);
              {
                sail_string zgaz3349;
                CREATE(sail_string)(&zgaz3349);
                {
                  lbits zgsz3800;
                  CREATE(lbits)(&zgsz3800);
                  CONVERT_OF(lbits, fbits)(&zgsz3800, zotype64, UINT64_C(32) , true);
                  string_of_lbits(&zgaz3349, zgsz3800);
                  KILL(lbits)(&zgsz3800);
                }
                sail_string zgaz3350;
                CREATE(sail_string)(&zgaz3350);
                {
                  sail_string zgaz3348;
                  CREATE(sail_string)(&zgaz3348);
                  {
                    sail_string zgaz3346;
                    CREATE(sail_string)(&zgaz3346);
                    {
                      uint64_t zgaz3341;
                      zgaz3341 = zcap.zaddress;
                      {
                        lbits zgsz3798;
                        CREATE(lbits)(&zgsz3798);
                        CONVERT_OF(lbits, fbits)(&zgsz3798, zgaz3341, UINT64_C(32) , true);
                        string_of_lbits(&zgaz3346, zgsz3798);
                        KILL(lbits)(&zgsz3798);
                      }
                    }
                    sail_string zgaz3347;
                    CREATE(sail_string)(&zgaz3347);
                    {
                      sail_string zgaz3345;
                      CREATE(sail_string)(&zgaz3345);
                      {
                        sail_string zgaz3343;
                        CREATE(sail_string)(&zgaz3343);
                        {
                          uint64_t zgaz3342;
                          zgaz3342 = sailgen_getCapBaseBits(zcap);
                          {
                            lbits zgsz3799;
                            CREATE(lbits)(&zgsz3799);
                            CONVERT_OF(lbits, fbits)(&zgsz3799, zgaz3342, UINT64_C(32) , true);
                            string_of_lbits(&zgaz3343, zgsz3799);
                            KILL(lbits)(&zgsz3799);
                          }
                        }
                        sail_string zgaz3344;
                        CREATE(sail_string)(&zgaz3344);
                        concat_str(&zgaz3344, " length:", zlen_str);
                        concat_str(&zgaz3345, zgaz3343, zgaz3344);
                        KILL(sail_string)(&zgaz3344);
                        KILL(sail_string)(&zgaz3343);
                      }
                      concat_str(&zgaz3347, " base:", zgaz3345);
                      KILL(sail_string)(&zgaz3345);
                    }
                    concat_str(&zgaz3348, zgaz3346, zgaz3347);
                    KILL(sail_string)(&zgaz3347);
                    KILL(sail_string)(&zgaz3346);
                  }
                  concat_str(&zgaz3350, " address:", zgaz3348);
                  KILL(sail_string)(&zgaz3348);
                }
                concat_str(&zgaz3351, zgaz3349, zgaz3350);
                KILL(sail_string)(&zgaz3350);
                KILL(sail_string)(&zgaz3349);
              }
              concat_str(&zgaz3353, " type:", zgaz3351);
              KILL(sail_string)(&zgaz3351);
            }
            concat_str(&zgaz3354, zgaz3352, zgaz3353);
            KILL(sail_string)(&zgaz3353);
            KILL(sail_string)(&zgaz3352);
          }
          concat_str(&zgaz3356, " perms:", zgaz3354);
          KILL(sail_string)(&zgaz3354);
        }
        concat_str(&zgaz3357, zgaz3355, zgaz3356);
        KILL(sail_string)(&zgaz3356);
        KILL(sail_string)(&zgaz3355);
      }
      concat_str(&zgaz3359, " s:", zgaz3357);
      KILL(sail_string)(&zgaz3357);
    }
    concat_str(&zgaz3360, zgaz3358, zgaz3359);
    KILL(sail_string)(&zgaz3359);
    KILL(sail_string)(&zgaz3358);
  }
  concat_str((*(&zcbz340)), " t:", zgaz3360);
  KILL(sail_string)(&zgaz3360);

  KILL(sail_string)(&zlen_str);

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
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgaz3368;
  {
    uint64_t zgaz3366;
    {
      sail_int zgsz3804;
      CREATE(sail_int)(&zgsz3804);
      CONVERT_OF(sail_int, mach_int)(&zgsz3804, INT64_C(32));
      sail_int zgsz3805;
      CREATE(sail_int)(&zgsz3805);
      CONVERT_OF(sail_int, mach_int)(&zgsz3805, INT64_C(0));
      lbits zgsz3806;
      CREATE(lbits)(&zgsz3806);
      sailgen_to_bits(&zgsz3806, zgsz3804, zgsz3805);
      zgaz3366 = CONVERT_OF(fbits, lbits)(zgsz3806, true);
      KILL(lbits)(&zgsz3806);
      KILL(sail_int)(&zgsz3805);
      KILL(sail_int)(&zgsz3804);
    }
    uint64_t zgaz3367;
    {
      lbits zgsz3801;
      CREATE(lbits)(&zgsz3801);
      CONVERT_OF(lbits, fbits)(&zgsz3801, UINT64_C(0b0), UINT64_C(1) , true);
      lbits zgsz3802;
      CREATE(lbits)(&zgsz3802);
      CONVERT_OF(lbits, fbits)(&zgsz3802, zlen, UINT64_C(32) , true);
      lbits zgsz3803;
      CREATE(lbits)(&zgsz3803);
      append(&zgsz3803, zgsz3801, zgsz3802);
      zgaz3367 = CONVERT_OF(fbits, lbits)(zgsz3803, true);
      KILL(lbits)(&zgsz3803);
      KILL(lbits)(&zgsz3802);
      KILL(lbits)(&zgsz3801);
    }
    zgaz3368 = sailgen_setCapBounds(zdefault_cap, zgaz3366, zgaz3367);
  }
  uint64_t zgsz390;
  {
    bool zexact;
    zexact = zgaz3368.ztup0;
    struct zCapability zc;
    zc = zgaz3368.ztup1;
    int64_t ze;
    {
      int64_t zgaz3374;
      {
        uint64_t zgaz3373;
        zgaz3373 = zc.zE;
        {
          lbits zgsz3807;
          CREATE(lbits)(&zgsz3807);
          CONVERT_OF(lbits, fbits)(&zgsz3807, zgaz3373, UINT64_C(6) , true);
          sail_int zgsz3808;
          CREATE(sail_int)(&zgsz3808);
          sail_unsigned(&zgsz3808, zgsz3807);
          zgaz3374 = CONVERT_OF(mach_int, sail_int)(zgsz3808);
          KILL(sail_int)(&zgsz3808);
          KILL(lbits)(&zgsz3807);
        }
      }
      {
        sail_int zgsz3809;
        CREATE(sail_int)(&zgsz3809);
        CONVERT_OF(sail_int, mach_int)(&zgsz3809, zgaz3374);
        sail_int zgsz3810;
        CREATE(sail_int)(&zgsz3810);
        CONVERT_OF(sail_int, mach_int)(&zgsz3810, zcap_max_E);
        sail_int zgsz3811;
        CREATE(sail_int)(&zgsz3811);
        min_int(&zgsz3811, zgsz3809, zgsz3810);
        ze = CONVERT_OF(mach_int, sail_int)(zgsz3811);
        KILL(sail_int)(&zgsz3811);
        KILL(sail_int)(&zgsz3810);
        KILL(sail_int)(&zgsz3809);
      }
    }
    int64_t zez7;
    {
      bool zgaz3372;
      zgaz3372 = zc.zinternal_E;
      if (zgaz3372) {
        {
          sail_int zgsz3812;
          CREATE(sail_int)(&zgsz3812);
          CONVERT_OF(sail_int, mach_int)(&zgsz3812, ze);
          sail_int zgsz3813;
          CREATE(sail_int)(&zgsz3813);
          CONVERT_OF(sail_int, mach_int)(&zgsz3813, zinternal_E_take_bits);
          sail_int zgsz3814;
          CREATE(sail_int)(&zgsz3814);
          add_int(&zgsz3814, zgsz3812, zgsz3813);
          zez7 = CONVERT_OF(mach_int, sail_int)(zgsz3814);
          KILL(sail_int)(&zgsz3814);
          KILL(sail_int)(&zgsz3813);
          KILL(sail_int)(&zgsz3812);
        }
      } else {  zez7 = INT64_C(0);  }
    }
    sbits zgaz3370;
    {
      int64_t zgaz3369;
      {
        sail_int zgsz3817;
        CREATE(sail_int)(&zgsz3817);
        CONVERT_OF(sail_int, mach_int)(&zgsz3817, INT64_C(32));
        sail_int zgsz3818;
        CREATE(sail_int)(&zgsz3818);
        CONVERT_OF(sail_int, mach_int)(&zgsz3818, zez7);
        sail_int zgsz3819;
        CREATE(sail_int)(&zgsz3819);
        sub_int(&zgsz3819, zgsz3817, zgsz3818);
        zgaz3369 = CONVERT_OF(mach_int, sail_int)(zgsz3819);
        KILL(sail_int)(&zgsz3819);
        KILL(sail_int)(&zgsz3818);
        KILL(sail_int)(&zgsz3817);
      }
      {
        sail_int zgsz3815;
        CREATE(sail_int)(&zgsz3815);
        CONVERT_OF(sail_int, mach_int)(&zgsz3815, zgaz3369);
        lbits zgsz3816;
        CREATE(lbits)(&zgsz3816);
        sailgen_ones(&zgsz3816, zgsz3815);
        zgaz3370 = CONVERT_OF(sbits, lbits)(zgsz3816, true);
        KILL(lbits)(&zgsz3816);
        KILL(sail_int)(&zgsz3815);
      }
    }
    sbits zgaz3371;
    {
      sail_int zgsz3823;
      CREATE(sail_int)(&zgsz3823);
      CONVERT_OF(sail_int, mach_int)(&zgsz3823, zez7);
      lbits zgsz3824;
      CREATE(lbits)(&zgsz3824);
      sailgen_zzeros_implicit(&zgsz3824, zgsz3823);
      zgaz3371 = CONVERT_OF(sbits, lbits)(zgsz3824, true);
      KILL(lbits)(&zgsz3824);
      KILL(sail_int)(&zgsz3823);
    }
    {
      lbits zgsz3820;
      CREATE(lbits)(&zgsz3820);
      CONVERT_OF(lbits, sbits)(&zgsz3820, zgaz3370, true);
      lbits zgsz3821;
      CREATE(lbits)(&zgsz3821);
      CONVERT_OF(lbits, sbits)(&zgsz3821, zgaz3371, true);
      lbits zgsz3822;
      CREATE(lbits)(&zgsz3822);
      append(&zgsz3822, zgsz3820, zgsz3821);
      zgsz390 = CONVERT_OF(fbits, lbits)(zgsz3822, true);
      KILL(lbits)(&zgsz3822);
      KILL(lbits)(&zgsz3821);
      KILL(lbits)(&zgsz3820);
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
  uint64_t zgaz3376;
  {
    uint64_t zgaz3375;
    {
      lbits zgsz3828;
      CREATE(lbits)(&zgsz3828);
      CONVERT_OF(lbits, fbits)(&zgsz3828, zm, UINT64_C(32) , true);
      lbits zgsz3829;
      CREATE(lbits)(&zgsz3829);
      not_bits(&zgsz3829, zgsz3828);
      zgaz3375 = CONVERT_OF(fbits, lbits)(zgsz3829, true);
      KILL(lbits)(&zgsz3829);
      KILL(lbits)(&zgsz3828);
    }
    {
      lbits zgsz3825;
      CREATE(lbits)(&zgsz3825);
      CONVERT_OF(lbits, fbits)(&zgsz3825, zlen, UINT64_C(32) , true);
      lbits zgsz3826;
      CREATE(lbits)(&zgsz3826);
      CONVERT_OF(lbits, fbits)(&zgsz3826, zgaz3375, UINT64_C(32) , true);
      lbits zgsz3827;
      CREATE(lbits)(&zgsz3827);
      add_bits(&zgsz3827, zgsz3825, zgsz3826);
      zgaz3376 = CONVERT_OF(fbits, lbits)(zgsz3827, true);
      KILL(lbits)(&zgsz3827);
      KILL(lbits)(&zgsz3826);
      KILL(lbits)(&zgsz3825);
    }
  }
  {
    lbits zgsz3830;
    CREATE(lbits)(&zgsz3830);
    CONVERT_OF(lbits, fbits)(&zgsz3830, zgaz3376, UINT64_C(32) , true);
    lbits zgsz3831;
    CREATE(lbits)(&zgsz3831);
    CONVERT_OF(lbits, fbits)(&zgsz3831, zm, UINT64_C(32) , true);
    lbits zgsz3832;
    CREATE(lbits)(&zgsz3832);
    and_bits(&zgsz3832, zgsz3830, zgsz3831);
    zcbz342 = CONVERT_OF(fbits, lbits)(zgsz3832, true);
    KILL(lbits)(&zgsz3832);
    KILL(lbits)(&zgsz3831);
    KILL(lbits)(&zgsz3830);
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
static uint64_t zTestLen;

static struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 sailgen_doCSetBounds(struct zCapability, uint64_t);

static struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 sailgen_doCSetBounds(struct zCapability zinput, uint64_t zreq_len)
{
  __label__ case_180, finish_match_179, end_function_181, end_block_exception_182;

  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz343;
  uint64_t znewBase;
  znewBase = zinput.zaddress;
  uint64_t znewTop;
  {
    uint64_t zgaz3381;
    {
      sail_int zgsz3836;
      CREATE(sail_int)(&zgsz3836);
      CONVERT_OF(sail_int, mach_int)(&zgsz3836, INT64_C(33));
      lbits zgsz3837;
      CREATE(lbits)(&zgsz3837);
      CONVERT_OF(lbits, fbits)(&zgsz3837, znewBase, UINT64_C(32) , true);
      lbits zgsz3838;
      CREATE(lbits)(&zgsz3838);
      sailgen_EXTZ(&zgsz3838, zgsz3836, zgsz3837);
      zgaz3381 = CONVERT_OF(fbits, lbits)(zgsz3838, true);
      KILL(lbits)(&zgsz3838);
      KILL(lbits)(&zgsz3837);
      KILL(sail_int)(&zgsz3836);
    }
    {
      lbits zgsz3833;
      CREATE(lbits)(&zgsz3833);
      CONVERT_OF(lbits, fbits)(&zgsz3833, zgaz3381, UINT64_C(33) , true);
      lbits zgsz3834;
      CREATE(lbits)(&zgsz3834);
      CONVERT_OF(lbits, fbits)(&zgsz3834, zreq_len, UINT64_C(33) , true);
      lbits zgsz3835;
      CREATE(lbits)(&zgsz3835);
      add_bits(&zgsz3835, zgsz3833, zgsz3834);
      znewTop = CONVERT_OF(fbits, lbits)(zgsz3835, true);
      KILL(lbits)(&zgsz3835);
      KILL(lbits)(&zgsz3834);
      KILL(lbits)(&zgsz3833);
    }
  }
  bool zinBounds;
  {
    int64_t zgaz3380;
    {
      lbits zgsz3839;
      CREATE(lbits)(&zgsz3839);
      CONVERT_OF(lbits, fbits)(&zgsz3839, zreq_len, UINT64_C(33) , true);
      sail_int zgsz3840;
      CREATE(sail_int)(&zgsz3840);
      sail_unsigned(&zgsz3840, zgsz3839);
      zgaz3380 = CONVERT_OF(mach_int, sail_int)(zgsz3840);
      KILL(sail_int)(&zgsz3840);
      KILL(lbits)(&zgsz3839);
    }
    zinBounds = sailgen_inCapBounds(zinput, znewBase, zgaz3380);
  }
  struct zCapability zinCap;
  zinCap = sailgen_clearTagIfSealed(zinput);
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgaz3377;
  zgaz3377 = sailgen_setCapBounds(zinCap, znewBase, znewTop);
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgsz392;
  {
    bool zexact;
    zexact = zgaz3377.ztup0;
    struct zCapability znewCap;
    znewCap = zgaz3377.ztup1;
    struct zCapability zgaz3379;
    {
      bool zgaz3378;
      zgaz3378 = not(zinBounds);
      zgaz3379 = sailgen_clearTagIf(znewCap, zgaz3378);
    }
    struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgsz393;
    zgsz393.ztup0 = zexact;
    zgsz393.ztup1 = zgaz3379;
    zgsz392 = zgsz393;
    goto finish_match_179;
  }
case_180: ;
  sail_match_failure("doCSetBounds");
finish_match_179: ;
  zcbz343 = zgsz392;






end_function_181: ;
  return zcbz343;
end_block_exception_182: ;
  struct zCapability zcbz362 = { .zB = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zT = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zaddress = UINT64_C(0xdeadc0de), .zflag_cap_mode = false, .zglobal = false, .zinternal_E = false, .zotype = UINT64_C(0xdeadc0de), .zpermit_cinvoke = false, .zpermit_execute = false, .zpermit_load = false, .zpermit_load_cap = false, .zpermit_seal = false, .zpermit_set_CID = false, .zpermit_store = false, .zpermit_store_cap = false, .zpermit_store_local_cap = false, .zpermit_unseal = false, .zreserved = UINT64_C(0xdeadc0de), .ztag = false, .zuperms = UINT64_C(0xdeadc0de) };
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz361 = { .ztup0 = false, .ztup1 = zcbz362 };
  return zcbz361;
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
  uint64_t zbits1;
  zbits1 = sailgen_capToBits(zTestCap);
  uint64_t zbits2;
  zbits2 = sailgen_capToMemBits(zTestCap);
  struct zCapability zcap1;
  {
    bool zgaz3387;
    zgaz3387 = zTestCap.ztag;
    zcap1 = sailgen_capBitsToCapability(zgaz3387, zbits1);
  }
  struct zCapability zcap2;
  {
    bool zgaz3386;
    zgaz3386 = zTestCap.ztag;
    zcap2 = sailgen_memBitsToCapability(zgaz3386, zbits2);
  }
  bool zrep;
  zrep = sailgen_fastRepCheck(zTestCap, zTestAddr);
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgaz3382;
  zgaz3382 = sailgen_doCSetBounds(zTestCap, zTestLen);
  unit zgsz397;
  {
    __label__ case_187, finish_match_186;

    bool zexact;
    zexact = zgaz3382.ztup0;
    struct zCapability zcap;
    zcap = zgaz3382.ztup1;
    struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgaz3383;
    zgaz3383 = sailgen_setCapAddr(zTestCap, zTestAddr);
    unit zgsz398;
    {
      __label__ case_189, finish_match_188;

      bool zrepresentable;
      zrepresentable = zgaz3383.ztup0;
      struct zCapability zcapshadowz30;
      zcapshadowz30 = zgaz3383.ztup1;
      struct ztuple_z8z5i64zCz0z5i64z9 zgaz3384;
      zgaz3384 = sailgen_getCapBounds(zTestCap);
      unit zgsz399;
      {
        int64_t zbase;
        zbase = zgaz3384.ztup0;
        int64_t ztop;
        ztop = zgaz3384.ztup1;
        uint64_t zflags;
        zflags = sailgen_getCapFlags(zTestCap);
        struct zCapability znew_cap;
        {
          uint64_t zgaz3385;
          {
            sail_int zgsz3841;
            CREATE(sail_int)(&zgsz3841);
            CONVERT_OF(sail_int, mach_int)(&zgsz3841, INT64_C(15));
            lbits zgsz3842;
            CREATE(lbits)(&zgsz3842);
            sailgen_ones(&zgsz3842, zgsz3841);
            zgaz3385 = CONVERT_OF(fbits, lbits)(zgsz3842, true);
            KILL(lbits)(&zgsz3842);
            KILL(sail_int)(&zgsz3841);
          }
          znew_cap = sailgen_setCapPerms(zTestCap, zgaz3385);
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
        goto finish_match_188;
      }
    case_189: ;
      sail_match_failure("main");
    finish_match_188: ;
      zgsz398 = zgsz399;
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
      sail_int zgsz3843;
      CREATE(sail_int)(&zgsz3843);
      CONVERT_OF(sail_int, mach_int)(&zgsz3843, INT64_C(32));
      lbits zgsz3844;
      CREATE(lbits)(&zgsz3844);
      UNDEFINED(lbits)(&zgsz3844, zgsz3843);
      zTestAddr = CONVERT_OF(fbits, lbits)(zgsz3844, true);
      KILL(lbits)(&zgsz3844);
      KILL(sail_int)(&zgsz3843);
    }
    unit zgsz3104;
    zgsz3104 = UNIT;
  }
  {
    sail_int zgsz3845;
    CREATE(sail_int)(&zgsz3845);
    CONVERT_OF(sail_int, mach_int)(&zgsz3845, INT64_C(33));
    lbits zgsz3846;
    CREATE(lbits)(&zgsz3846);
    UNDEFINED(lbits)(&zgsz3846, zgsz3845);
    zTestLen = CONVERT_OF(fbits, lbits)(zgsz3846, true);
    KILL(lbits)(&zgsz3846);
    KILL(sail_int)(&zgsz3845);
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
