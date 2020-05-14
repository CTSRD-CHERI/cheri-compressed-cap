#include "sail.h"
#include "rts.h"
#include "elf.h"

// enum write_kind
enum zwrite_kind { zWrite_plain, zWrite_conditional, zWrite_release, zWrite_exclusive, zWrite_exclusive_release, zWrite_RISCV_release, zWrite_RISCV_strong_release, zWrite_RISCV_conditional, zWrite_RISCV_conditional_release, zWrite_RISCV_conditional_strong_release, zWrite_X86_locked };

static bool eq_zwrite_kind(enum zwrite_kind op1, enum zwrite_kind op2) { return op1 == op2; }

enum zwrite_kind UNDEFINED(zwrite_kind)(unit u) { return zWrite_plain; }

// enum trans_kind
enum ztrans_kind { zTransaction_start, zTransaction_commit, zTransaction_abort };

static bool eq_ztrans_kind(enum ztrans_kind op1, enum ztrans_kind op2) { return op1 == op2; }

enum ztrans_kind UNDEFINED(ztrans_kind)(unit u) { return zTransaction_start; }

// struct tuple_(%string, %i)
struct ztuple_z8z5stringzCz0z5iz9 {
  sail_string ztup0;
  sail_int ztup1;
};

static void COPY(ztuple_z8z5stringzCz0z5iz9)(struct ztuple_z8z5stringzCz0z5iz9 *rop, const struct ztuple_z8z5stringzCz0z5iz9 op) {
  COPY(sail_string)(&rop->ztup0, op.ztup0);
  COPY(sail_int)(&rop->ztup1, op.ztup1);
}

static void CREATE(ztuple_z8z5stringzCz0z5iz9)(struct ztuple_z8z5stringzCz0z5iz9 *op) {
  CREATE(sail_string)(&op->ztup0);
  CREATE(sail_int)(&op->ztup1);
}

static void RECREATE(ztuple_z8z5stringzCz0z5iz9)(struct ztuple_z8z5stringzCz0z5iz9 *op) {
  RECREATE(sail_string)(&op->ztup0);
  RECREATE(sail_int)(&op->ztup1);
}

static void KILL(ztuple_z8z5stringzCz0z5iz9)(struct ztuple_z8z5stringzCz0z5iz9 *op) {
  KILL(sail_string)(&op->ztup0);
  KILL(sail_int)(&op->ztup1);
}

static bool EQUAL(ztuple_z8z5stringzCz0z5iz9)(struct ztuple_z8z5stringzCz0z5iz9 op1, struct ztuple_z8z5stringzCz0z5iz9 op2) {
  return EQUAL(sail_string)(op1.ztup0, op2.ztup0) && EQUAL(sail_int)(op1.ztup1, op2.ztup1);
}


// struct tuple_(%string, %i, %i)
struct ztuple_z8z5stringzCz0z5izCz0z5iz9 {
  sail_string ztup0;
  sail_int ztup1;
  sail_int ztup2;
};

static void COPY(ztuple_z8z5stringzCz0z5izCz0z5iz9)(struct ztuple_z8z5stringzCz0z5izCz0z5iz9 *rop, const struct ztuple_z8z5stringzCz0z5izCz0z5iz9 op) {
  COPY(sail_string)(&rop->ztup0, op.ztup0);
  COPY(sail_int)(&rop->ztup1, op.ztup1);
  COPY(sail_int)(&rop->ztup2, op.ztup2);
}

static void CREATE(ztuple_z8z5stringzCz0z5izCz0z5iz9)(struct ztuple_z8z5stringzCz0z5izCz0z5iz9 *op) {
  CREATE(sail_string)(&op->ztup0);
  CREATE(sail_int)(&op->ztup1);
  CREATE(sail_int)(&op->ztup2);
}

static void RECREATE(ztuple_z8z5stringzCz0z5izCz0z5iz9)(struct ztuple_z8z5stringzCz0z5izCz0z5iz9 *op) {
  RECREATE(sail_string)(&op->ztup0);
  RECREATE(sail_int)(&op->ztup1);
  RECREATE(sail_int)(&op->ztup2);
}

static void KILL(ztuple_z8z5stringzCz0z5izCz0z5iz9)(struct ztuple_z8z5stringzCz0z5izCz0z5iz9 *op) {
  KILL(sail_string)(&op->ztup0);
  KILL(sail_int)(&op->ztup1);
  KILL(sail_int)(&op->ztup2);
}

static bool EQUAL(ztuple_z8z5stringzCz0z5izCz0z5iz9)(struct ztuple_z8z5stringzCz0z5izCz0z5iz9 op1, struct ztuple_z8z5stringzCz0z5izCz0z5iz9 op2) {
  return EQUAL(sail_string)(op1.ztup0, op2.ztup0) && EQUAL(sail_int)(op1.ztup1, op2.ztup1) && EQUAL(sail_int)(op1.ztup2, op2.ztup2);
}


// struct tuple_(%string, %string)
struct ztuple_z8z5stringzCz0z5stringz9 {
  sail_string ztup0;
  sail_string ztup1;
};

static void COPY(ztuple_z8z5stringzCz0z5stringz9)(struct ztuple_z8z5stringzCz0z5stringz9 *rop, const struct ztuple_z8z5stringzCz0z5stringz9 op) {
  COPY(sail_string)(&rop->ztup0, op.ztup0);
  COPY(sail_string)(&rop->ztup1, op.ztup1);
}

static void CREATE(ztuple_z8z5stringzCz0z5stringz9)(struct ztuple_z8z5stringzCz0z5stringz9 *op) {
  CREATE(sail_string)(&op->ztup0);
  CREATE(sail_string)(&op->ztup1);
}

static void RECREATE(ztuple_z8z5stringzCz0z5stringz9)(struct ztuple_z8z5stringzCz0z5stringz9 *op) {
  RECREATE(sail_string)(&op->ztup0);
  RECREATE(sail_string)(&op->ztup1);
}

static void KILL(ztuple_z8z5stringzCz0z5stringz9)(struct ztuple_z8z5stringzCz0z5stringz9 *op) {
  KILL(sail_string)(&op->ztup0);
  KILL(sail_string)(&op->ztup1);
}

static bool EQUAL(ztuple_z8z5stringzCz0z5stringz9)(struct ztuple_z8z5stringzCz0z5stringz9 op1, struct ztuple_z8z5stringzCz0z5stringz9 op2) {
  return EQUAL(sail_string)(op1.ztup0, op2.ztup0) && EQUAL(sail_string)(op1.ztup1, op2.ztup1);
}

// union regfp
enum kind_zregfp { Kind_zRField, Kind_zRFull, Kind_zRSlice, Kind_zRSliceBit };

struct zregfp {
  enum kind_zregfp kind;
  union {
    struct { struct ztuple_z8z5stringzCz0z5stringz9 zRField; };
    struct { sail_string zRFull; };
    struct { struct ztuple_z8z5stringzCz0z5izCz0z5iz9 zRSlice; };
    struct { struct ztuple_z8z5stringzCz0z5iz9 zRSliceBit; };
  };
};

static void CREATE(zregfp)(struct zregfp *op)
{
  op->kind = Kind_zRField;
  CREATE(ztuple_z8z5stringzCz0z5stringz9)(&op->zRField);
}

static void RECREATE(zregfp)(struct zregfp *op) {}

static void KILL(zregfp)(struct zregfp *op)
{
  if (op->kind == Kind_zRField) {
    KILL(ztuple_z8z5stringzCz0z5stringz9)(&op->zRField);
  } else if (op->kind == Kind_zRFull) {
    KILL(sail_string)(&op->zRFull);
  } else if (op->kind == Kind_zRSlice) {
    KILL(ztuple_z8z5stringzCz0z5izCz0z5iz9)(&op->zRSlice);
  } else if (op->kind == Kind_zRSliceBit){
    KILL(ztuple_z8z5stringzCz0z5iz9)(&op->zRSliceBit);
  };
}

static void COPY(zregfp)(struct zregfp *rop, struct zregfp op)
{
  if (rop->kind == Kind_zRField) {
    KILL(ztuple_z8z5stringzCz0z5stringz9)(&rop->zRField);
  } else if (rop->kind == Kind_zRFull) {
    KILL(sail_string)(&rop->zRFull);
  } else if (rop->kind == Kind_zRSlice) {
    KILL(ztuple_z8z5stringzCz0z5izCz0z5iz9)(&rop->zRSlice);
  } else if (rop->kind == Kind_zRSliceBit){
    KILL(ztuple_z8z5stringzCz0z5iz9)(&rop->zRSliceBit);
  };
  rop->kind = op.kind;
  if (op.kind == Kind_zRField) {
  
  CREATE(ztuple_z8z5stringzCz0z5stringz9)(&rop->zRField); COPY(ztuple_z8z5stringzCz0z5stringz9)(&rop->zRField, op.zRField);
  } else if (op.kind == Kind_zRFull) {
    CREATE(sail_string)(&rop->zRFull); COPY(sail_string)(&rop->zRFull, op.zRFull);
  } else if (op.kind == Kind_zRSlice) {
  
  CREATE(ztuple_z8z5stringzCz0z5izCz0z5iz9)(&rop->zRSlice); COPY(ztuple_z8z5stringzCz0z5izCz0z5iz9)(&rop->zRSlice, op.zRSlice);
  } else if (op.kind == Kind_zRSliceBit){
  
  CREATE(ztuple_z8z5stringzCz0z5iz9)(&rop->zRSliceBit); COPY(ztuple_z8z5stringzCz0z5iz9)(&rop->zRSliceBit, op.zRSliceBit);
  }
}

static bool EQUAL(zregfp)(struct zregfp op1, struct zregfp op2) {
  if (op1.kind == Kind_zRField && op2.kind == Kind_zRField) {
    return EQUAL(ztuple_z8z5stringzCz0z5stringz9)(op1.zRField, op2.zRField);
  } else if (op1.kind == Kind_zRFull && op2.kind == Kind_zRFull) {
    return EQUAL(sail_string)(op1.zRFull, op2.zRFull);
  } else if (op1.kind == Kind_zRSlice && op2.kind == Kind_zRSlice) {
    return EQUAL(ztuple_z8z5stringzCz0z5izCz0z5iz9)(op1.zRSlice, op2.zRSlice);
  } else if (op1.kind == Kind_zRSliceBit && op2.kind == Kind_zRSliceBit) {
    return EQUAL(ztuple_z8z5stringzCz0z5iz9)(op1.zRSliceBit, op2.zRSliceBit);
  } else return false;
}

static void sailgen_RField(struct zregfp *rop, struct ztuple_z8z5stringzCz0z5stringz9 op)
{
  if (rop->kind == Kind_zRField) {
    KILL(ztuple_z8z5stringzCz0z5stringz9)(&rop->zRField);
  } else if (rop->kind == Kind_zRFull) {
    KILL(sail_string)(&rop->zRFull);
  } else if (rop->kind == Kind_zRSlice) {
    KILL(ztuple_z8z5stringzCz0z5izCz0z5iz9)(&rop->zRSlice);
  } else if (rop->kind == Kind_zRSliceBit){
    KILL(ztuple_z8z5stringzCz0z5iz9)(&rop->zRSliceBit);
  }
  rop->kind = Kind_zRField;
  CREATE(ztuple_z8z5stringzCz0z5stringz9)(&rop->zRField);
  COPY(ztuple_z8z5stringzCz0z5stringz9)(&rop->zRField, op);
  
}

static void sailgen_RFull(struct zregfp *rop, sail_string op)
{
  if (rop->kind == Kind_zRField) {
    KILL(ztuple_z8z5stringzCz0z5stringz9)(&rop->zRField);
  } else if (rop->kind == Kind_zRFull) {
    KILL(sail_string)(&rop->zRFull);
  } else if (rop->kind == Kind_zRSlice) {
    KILL(ztuple_z8z5stringzCz0z5izCz0z5iz9)(&rop->zRSlice);
  } else if (rop->kind == Kind_zRSliceBit){
    KILL(ztuple_z8z5stringzCz0z5iz9)(&rop->zRSliceBit);
  }
  rop->kind = Kind_zRFull;
  CREATE(sail_string)(&rop->zRFull);
  COPY(sail_string)(&rop->zRFull, op);
  
}

static void sailgen_RSlice(struct zregfp *rop, struct ztuple_z8z5stringzCz0z5izCz0z5iz9 op)
{
  if (rop->kind == Kind_zRField) {
    KILL(ztuple_z8z5stringzCz0z5stringz9)(&rop->zRField);
  } else if (rop->kind == Kind_zRFull) {
    KILL(sail_string)(&rop->zRFull);
  } else if (rop->kind == Kind_zRSlice) {
    KILL(ztuple_z8z5stringzCz0z5izCz0z5iz9)(&rop->zRSlice);
  } else if (rop->kind == Kind_zRSliceBit){
    KILL(ztuple_z8z5stringzCz0z5iz9)(&rop->zRSliceBit);
  }
  rop->kind = Kind_zRSlice;
  CREATE(ztuple_z8z5stringzCz0z5izCz0z5iz9)(&rop->zRSlice);
  COPY(ztuple_z8z5stringzCz0z5izCz0z5iz9)(&rop->zRSlice, op);
  
}

static void sailgen_RSliceBit(struct zregfp *rop, struct ztuple_z8z5stringzCz0z5iz9 op)
{
  if (rop->kind == Kind_zRField) {
    KILL(ztuple_z8z5stringzCz0z5stringz9)(&rop->zRField);
  } else if (rop->kind == Kind_zRFull) {
    KILL(sail_string)(&rop->zRFull);
  } else if (rop->kind == Kind_zRSlice) {
    KILL(ztuple_z8z5stringzCz0z5izCz0z5iz9)(&rop->zRSlice);
  } else if (rop->kind == Kind_zRSliceBit){
    KILL(ztuple_z8z5stringzCz0z5iz9)(&rop->zRSliceBit);
  }
  rop->kind = Kind_zRSliceBit;
  CREATE(ztuple_z8z5stringzCz0z5iz9)(&rop->zRSliceBit);
  COPY(ztuple_z8z5stringzCz0z5iz9)(&rop->zRSliceBit, op);
  
}

// enum read_kind
enum zread_kind { zRead_plain, zRead_reserve, zRead_acquire, zRead_exclusive, zRead_exclusive_acquire, zRead_stream, zRead_RISCV_acquire, zRead_RISCV_strong_acquire, zRead_RISCV_reserved, zRead_RISCV_reserved_acquire, zRead_RISCV_reserved_strong_acquire, zRead_X86_locked };

static bool eq_zread_kind(enum zread_kind op1, enum zread_kind op2) { return op1 == op2; }

enum zread_kind UNDEFINED(zread_kind)(unit u) { return zRead_plain; }

// union option
enum kind_zoption { Kind_zNone };

struct zoption {
  enum kind_zoption kind;
  union {struct { unit zNone; };};
};

static void CREATE(zoption)(struct zoption *op)
{
  op->kind = Kind_zNone;
  
}

static void RECREATE(zoption)(struct zoption *op) {}

static void KILL(zoption)(struct zoption *op)
{
  if (op->kind == Kind_zNone){
    /* do nothing */
  };
}

static void COPY(zoption)(struct zoption *rop, struct zoption op)
{
  if (rop->kind == Kind_zNone){
    /* do nothing */
  };
  rop->kind = op.kind;
  if (op.kind == Kind_zNone){
    rop->zNone = op.zNone;
  }
}

static bool EQUAL(zoption)(struct zoption op1, struct zoption op2) {
  if (op1.kind == Kind_zNone && op2.kind == Kind_zNone) {
    return EQUAL(unit)(op1.zNone, op2.zNone);
  } else return false;
}

static void sailgen_None(struct zoption *rop, unit op)
{
  if (rop->kind == Kind_zNone){
    /* do nothing */
  }
  rop->kind = Kind_zNone;
  rop->zNone = op;
}

// union niafp
enum kind_zniafp { Kind_zNIAFP_concrete_address, Kind_zNIAFP_indirect_address, Kind_zNIAFP_successor };

struct zniafp {
  enum kind_zniafp kind;
  union {
    struct { uint64_t zNIAFP_concrete_address; };
    struct { unit zNIAFP_indirect_address; };
    struct { unit zNIAFP_successor; };
  };
};

static void CREATE(zniafp)(struct zniafp *op)
{
  op->kind = Kind_zNIAFP_concrete_address;
  
}

static void RECREATE(zniafp)(struct zniafp *op) {}

static void KILL(zniafp)(struct zniafp *op)
{
  if (op->kind == Kind_zNIAFP_concrete_address) {
    /* do nothing */
  } else if (op->kind == Kind_zNIAFP_indirect_address) {
    /* do nothing */
  } else if (op->kind == Kind_zNIAFP_successor){
    /* do nothing */
  };
}

static void COPY(zniafp)(struct zniafp *rop, struct zniafp op)
{
  if (rop->kind == Kind_zNIAFP_concrete_address) {
    /* do nothing */
  } else if (rop->kind == Kind_zNIAFP_indirect_address) {
    /* do nothing */
  } else if (rop->kind == Kind_zNIAFP_successor){
    /* do nothing */
  };
  rop->kind = op.kind;
  if (op.kind == Kind_zNIAFP_concrete_address) {
    rop->zNIAFP_concrete_address = op.zNIAFP_concrete_address;
  } else if (op.kind == Kind_zNIAFP_indirect_address) {
    rop->zNIAFP_indirect_address = op.zNIAFP_indirect_address;
  } else if (op.kind == Kind_zNIAFP_successor){
    rop->zNIAFP_successor = op.zNIAFP_successor;
  }
}

static bool EQUAL(zniafp)(struct zniafp op1, struct zniafp op2) {
  if (op1.kind == Kind_zNIAFP_concrete_address && op2.kind == Kind_zNIAFP_concrete_address) {
    return EQUAL(fbits)(op1.zNIAFP_concrete_address, op2.zNIAFP_concrete_address);
  } else if (op1.kind == Kind_zNIAFP_indirect_address && op2.kind == Kind_zNIAFP_indirect_address) {
    return EQUAL(unit)(op1.zNIAFP_indirect_address, op2.zNIAFP_indirect_address);
  } else if (op1.kind == Kind_zNIAFP_successor && op2.kind == Kind_zNIAFP_successor) {
    return EQUAL(unit)(op1.zNIAFP_successor, op2.zNIAFP_successor);
  } else return false;
}

static void sailgen_NIAFP_concrete_address(struct zniafp *rop, uint64_t op)
{
  if (rop->kind == Kind_zNIAFP_concrete_address) {
    /* do nothing */
  } else if (rop->kind == Kind_zNIAFP_indirect_address) {
    /* do nothing */
  } else if (rop->kind == Kind_zNIAFP_successor){
    /* do nothing */
  }
  rop->kind = Kind_zNIAFP_concrete_address;
  rop->zNIAFP_concrete_address = op;
}

static void sailgen_NIAFP_indirect_address(struct zniafp *rop, unit op)
{
  if (rop->kind == Kind_zNIAFP_concrete_address) {
    /* do nothing */
  } else if (rop->kind == Kind_zNIAFP_indirect_address) {
    /* do nothing */
  } else if (rop->kind == Kind_zNIAFP_successor){
    /* do nothing */
  }
  rop->kind = Kind_zNIAFP_indirect_address;
  rop->zNIAFP_indirect_address = op;
}

static void sailgen_NIAFP_successor(struct zniafp *rop, unit op)
{
  if (rop->kind == Kind_zNIAFP_concrete_address) {
    /* do nothing */
  } else if (rop->kind == Kind_zNIAFP_indirect_address) {
    /* do nothing */
  } else if (rop->kind == Kind_zNIAFP_successor){
    /* do nothing */
  }
  rop->kind = Kind_zNIAFP_successor;
  rop->zNIAFP_successor = op;
}



// union diafp
enum kind_zdiafp { Kind_zDIAFP_concrete, Kind_zDIAFP_none, Kind_zDIAFP_reg };

struct zdiafp {
  enum kind_zdiafp kind;
  union {
    struct { uint64_t zDIAFP_concrete; };
    struct { unit zDIAFP_none; };
    struct { struct zregfp zDIAFP_reg; };
  };
};

static void CREATE(zdiafp)(struct zdiafp *op)
{
  op->kind = Kind_zDIAFP_concrete;
  
}

static void RECREATE(zdiafp)(struct zdiafp *op) {}

static void KILL(zdiafp)(struct zdiafp *op)
{
  if (op->kind == Kind_zDIAFP_concrete) {
    /* do nothing */
  } else if (op->kind == Kind_zDIAFP_none) {
    /* do nothing */
  } else if (op->kind == Kind_zDIAFP_reg){
    KILL(zregfp)(&op->zDIAFP_reg);
  };
}

static void COPY(zdiafp)(struct zdiafp *rop, struct zdiafp op)
{
  if (rop->kind == Kind_zDIAFP_concrete) {
    /* do nothing */
  } else if (rop->kind == Kind_zDIAFP_none) {
    /* do nothing */
  } else if (rop->kind == Kind_zDIAFP_reg){
    KILL(zregfp)(&rop->zDIAFP_reg);
  };
  rop->kind = op.kind;
  if (op.kind == Kind_zDIAFP_concrete) {
    rop->zDIAFP_concrete = op.zDIAFP_concrete;
  } else if (op.kind == Kind_zDIAFP_none) {
    rop->zDIAFP_none = op.zDIAFP_none;
  } else if (op.kind == Kind_zDIAFP_reg){
    CREATE(zregfp)(&rop->zDIAFP_reg); COPY(zregfp)(&rop->zDIAFP_reg, op.zDIAFP_reg);
  }
}

static bool EQUAL(zdiafp)(struct zdiafp op1, struct zdiafp op2) {
  if (op1.kind == Kind_zDIAFP_concrete && op2.kind == Kind_zDIAFP_concrete) {
    return EQUAL(fbits)(op1.zDIAFP_concrete, op2.zDIAFP_concrete);
  } else if (op1.kind == Kind_zDIAFP_none && op2.kind == Kind_zDIAFP_none) {
    return EQUAL(unit)(op1.zDIAFP_none, op2.zDIAFP_none);
  } else if (op1.kind == Kind_zDIAFP_reg && op2.kind == Kind_zDIAFP_reg) {
    return EQUAL(zregfp)(op1.zDIAFP_reg, op2.zDIAFP_reg);
  } else return false;
}

static void sailgen_DIAFP_concrete(struct zdiafp *rop, uint64_t op)
{
  if (rop->kind == Kind_zDIAFP_concrete) {
    /* do nothing */
  } else if (rop->kind == Kind_zDIAFP_none) {
    /* do nothing */
  } else if (rop->kind == Kind_zDIAFP_reg){
    KILL(zregfp)(&rop->zDIAFP_reg);
  }
  rop->kind = Kind_zDIAFP_concrete;
  rop->zDIAFP_concrete = op;
}

static void sailgen_DIAFP_none(struct zdiafp *rop, unit op)
{
  if (rop->kind == Kind_zDIAFP_concrete) {
    /* do nothing */
  } else if (rop->kind == Kind_zDIAFP_none) {
    /* do nothing */
  } else if (rop->kind == Kind_zDIAFP_reg){
    KILL(zregfp)(&rop->zDIAFP_reg);
  }
  rop->kind = Kind_zDIAFP_none;
  rop->zDIAFP_none = op;
}

static void sailgen_DIAFP_reg(struct zdiafp *rop, struct zregfp op)
{
  if (rop->kind == Kind_zDIAFP_concrete) {
    /* do nothing */
  } else if (rop->kind == Kind_zDIAFP_none) {
    /* do nothing */
  } else if (rop->kind == Kind_zDIAFP_reg){
    KILL(zregfp)(&rop->zDIAFP_reg);
  }
  rop->kind = Kind_zDIAFP_reg;
  CREATE(zregfp)(&rop->zDIAFP_reg);
  COPY(zregfp)(&rop->zDIAFP_reg, op);
  
}

// enum cache_op_kind
enum zcache_op_kind { zCache_op_D_IVAC, zCache_op_D_ISW, zCache_op_D_CSW, zCache_op_D_CISW, zCache_op_D_ZVA, zCache_op_D_CVAC, zCache_op_D_CVAU, zCache_op_D_CIVAC, zCache_op_I_IALLUIS, zCache_op_I_IALLU, zCache_op_I_IVAU };

static bool eq_zcache_op_kind(enum zcache_op_kind op1, enum zcache_op_kind op2) { return op1 == op2; }

enum zcache_op_kind UNDEFINED(zcache_op_kind)(unit u) { return zCache_op_D_IVAC; }

// enum a64_barrier_type
enum za64_barrier_type { zA64_barrier_all, zA64_barrier_LD, zA64_barrier_ST };

static bool eq_za64_barrier_type(enum za64_barrier_type op1, enum za64_barrier_type op2) { return op1 == op2; }

enum za64_barrier_type UNDEFINED(za64_barrier_type)(unit u) { return zA64_barrier_all; }

// enum a64_barrier_domain
enum za64_barrier_domain { zA64_FullShare, zA64_InnerShare, zA64_OuterShare, zA64_NonShare };

static bool eq_za64_barrier_domain(enum za64_barrier_domain op1, enum za64_barrier_domain op2) { return op1 == op2; }

enum za64_barrier_domain UNDEFINED(za64_barrier_domain)(unit u) { return zA64_FullShare; }

// struct tuple_(%enum za64_barrier_domain, %enum za64_barrier_type)
struct ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9 {
  enum za64_barrier_domain ztup0;
  enum za64_barrier_type ztup1;
};

static void COPY(ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9)(struct ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9 *rop, const struct ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
}

static bool EQUAL(ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9)(struct ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9 op1, struct ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9 op2) {
  return EQUAL(za64_barrier_domain)(op1.ztup0, op2.ztup0) && EQUAL(za64_barrier_type)(op1.ztup1, op2.ztup1);
}

// union barrier_kind
enum kind_zbarrier_kind { Kind_zBarrier_DMB, Kind_zBarrier_DSB, Kind_zBarrier_Eieio, Kind_zBarrier_ISB, Kind_zBarrier_Isync, Kind_zBarrier_LwSync, Kind_zBarrier_MIPS_SYNC, Kind_zBarrier_RISCV_i, Kind_zBarrier_RISCV_r_r, Kind_zBarrier_RISCV_r_rw, Kind_zBarrier_RISCV_r_w, Kind_zBarrier_RISCV_rw_r, Kind_zBarrier_RISCV_rw_rw, Kind_zBarrier_RISCV_rw_w, Kind_zBarrier_RISCV_tso, Kind_zBarrier_RISCV_w_r, Kind_zBarrier_RISCV_w_rw, Kind_zBarrier_RISCV_w_w, Kind_zBarrier_Sync, Kind_zBarrier_x86_MFENCE };

struct zbarrier_kind {
  enum kind_zbarrier_kind kind;
  union {
    struct { struct ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9 zBarrier_DMB; };
    struct { struct ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9 zBarrier_DSB; };
    struct { unit zBarrier_Eieio; };
    struct { unit zBarrier_ISB; };
    struct { unit zBarrier_Isync; };
    struct { unit zBarrier_LwSync; };
    struct { unit zBarrier_MIPS_SYNC; };
    struct { unit zBarrier_RISCV_i; };
    struct { unit zBarrier_RISCV_r_r; };
    struct { unit zBarrier_RISCV_r_rw; };
    struct { unit zBarrier_RISCV_r_w; };
    struct { unit zBarrier_RISCV_rw_r; };
    struct { unit zBarrier_RISCV_rw_rw; };
    struct { unit zBarrier_RISCV_rw_w; };
    struct { unit zBarrier_RISCV_tso; };
    struct { unit zBarrier_RISCV_w_r; };
    struct { unit zBarrier_RISCV_w_rw; };
    struct { unit zBarrier_RISCV_w_w; };
    struct { unit zBarrier_Sync; };
    struct { unit zBarrier_x86_MFENCE; };
  };
};

static void CREATE(zbarrier_kind)(struct zbarrier_kind *op)
{
  op->kind = Kind_zBarrier_DMB;
  
}

static void RECREATE(zbarrier_kind)(struct zbarrier_kind *op) {}

static void KILL(zbarrier_kind)(struct zbarrier_kind *op)
{
  if (op->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (op->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  };
}

static void COPY(zbarrier_kind)(struct zbarrier_kind *rop, struct zbarrier_kind op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  };
  rop->kind = op.kind;
  if (op.kind == Kind_zBarrier_DMB) {
    rop->zBarrier_DMB = op.zBarrier_DMB;
  } else if (op.kind == Kind_zBarrier_DSB) {
    rop->zBarrier_DSB = op.zBarrier_DSB;
  } else if (op.kind == Kind_zBarrier_Eieio) {
    rop->zBarrier_Eieio = op.zBarrier_Eieio;
  } else if (op.kind == Kind_zBarrier_ISB) {
    rop->zBarrier_ISB = op.zBarrier_ISB;
  } else if (op.kind == Kind_zBarrier_Isync) {
    rop->zBarrier_Isync = op.zBarrier_Isync;
  } else if (op.kind == Kind_zBarrier_LwSync) {
    rop->zBarrier_LwSync = op.zBarrier_LwSync;
  } else if (op.kind == Kind_zBarrier_MIPS_SYNC) {
    rop->zBarrier_MIPS_SYNC = op.zBarrier_MIPS_SYNC;
  } else if (op.kind == Kind_zBarrier_RISCV_i) {
    rop->zBarrier_RISCV_i = op.zBarrier_RISCV_i;
  } else if (op.kind == Kind_zBarrier_RISCV_r_r) {
    rop->zBarrier_RISCV_r_r = op.zBarrier_RISCV_r_r;
  } else if (op.kind == Kind_zBarrier_RISCV_r_rw) {
    rop->zBarrier_RISCV_r_rw = op.zBarrier_RISCV_r_rw;
  } else if (op.kind == Kind_zBarrier_RISCV_r_w) {
    rop->zBarrier_RISCV_r_w = op.zBarrier_RISCV_r_w;
  } else if (op.kind == Kind_zBarrier_RISCV_rw_r) {
    rop->zBarrier_RISCV_rw_r = op.zBarrier_RISCV_rw_r;
  } else if (op.kind == Kind_zBarrier_RISCV_rw_rw) {
    rop->zBarrier_RISCV_rw_rw = op.zBarrier_RISCV_rw_rw;
  } else if (op.kind == Kind_zBarrier_RISCV_rw_w) {
    rop->zBarrier_RISCV_rw_w = op.zBarrier_RISCV_rw_w;
  } else if (op.kind == Kind_zBarrier_RISCV_tso) {
    rop->zBarrier_RISCV_tso = op.zBarrier_RISCV_tso;
  } else if (op.kind == Kind_zBarrier_RISCV_w_r) {
    rop->zBarrier_RISCV_w_r = op.zBarrier_RISCV_w_r;
  } else if (op.kind == Kind_zBarrier_RISCV_w_rw) {
    rop->zBarrier_RISCV_w_rw = op.zBarrier_RISCV_w_rw;
  } else if (op.kind == Kind_zBarrier_RISCV_w_w) {
    rop->zBarrier_RISCV_w_w = op.zBarrier_RISCV_w_w;
  } else if (op.kind == Kind_zBarrier_Sync) {
    rop->zBarrier_Sync = op.zBarrier_Sync;
  } else if (op.kind == Kind_zBarrier_x86_MFENCE){
    rop->zBarrier_x86_MFENCE = op.zBarrier_x86_MFENCE;
  }
}

static bool EQUAL(zbarrier_kind)(struct zbarrier_kind op1, struct zbarrier_kind op2) {
  if (op1.kind == Kind_zBarrier_DMB && op2.kind == Kind_zBarrier_DMB) {
  
  return EQUAL(ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9)(op1.zBarrier_DMB, op2.zBarrier_DMB);
  } else if (op1.kind == Kind_zBarrier_DSB && op2.kind == Kind_zBarrier_DSB) {
  
  return EQUAL(ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9)(op1.zBarrier_DSB, op2.zBarrier_DSB);
  } else if (op1.kind == Kind_zBarrier_Eieio && op2.kind == Kind_zBarrier_Eieio) {
    return EQUAL(unit)(op1.zBarrier_Eieio, op2.zBarrier_Eieio);
  } else if (op1.kind == Kind_zBarrier_ISB && op2.kind == Kind_zBarrier_ISB) {
    return EQUAL(unit)(op1.zBarrier_ISB, op2.zBarrier_ISB);
  } else if (op1.kind == Kind_zBarrier_Isync && op2.kind == Kind_zBarrier_Isync) {
    return EQUAL(unit)(op1.zBarrier_Isync, op2.zBarrier_Isync);
  } else if (op1.kind == Kind_zBarrier_LwSync && op2.kind == Kind_zBarrier_LwSync) {
    return EQUAL(unit)(op1.zBarrier_LwSync, op2.zBarrier_LwSync);
  } else if (op1.kind == Kind_zBarrier_MIPS_SYNC && op2.kind == Kind_zBarrier_MIPS_SYNC) {
    return EQUAL(unit)(op1.zBarrier_MIPS_SYNC, op2.zBarrier_MIPS_SYNC);
  } else if (op1.kind == Kind_zBarrier_RISCV_i && op2.kind == Kind_zBarrier_RISCV_i) {
    return EQUAL(unit)(op1.zBarrier_RISCV_i, op2.zBarrier_RISCV_i);
  } else if (op1.kind == Kind_zBarrier_RISCV_r_r && op2.kind == Kind_zBarrier_RISCV_r_r) {
    return EQUAL(unit)(op1.zBarrier_RISCV_r_r, op2.zBarrier_RISCV_r_r);
  } else if (op1.kind == Kind_zBarrier_RISCV_r_rw && op2.kind == Kind_zBarrier_RISCV_r_rw) {
    return EQUAL(unit)(op1.zBarrier_RISCV_r_rw, op2.zBarrier_RISCV_r_rw);
  } else if (op1.kind == Kind_zBarrier_RISCV_r_w && op2.kind == Kind_zBarrier_RISCV_r_w) {
    return EQUAL(unit)(op1.zBarrier_RISCV_r_w, op2.zBarrier_RISCV_r_w);
  } else if (op1.kind == Kind_zBarrier_RISCV_rw_r && op2.kind == Kind_zBarrier_RISCV_rw_r) {
    return EQUAL(unit)(op1.zBarrier_RISCV_rw_r, op2.zBarrier_RISCV_rw_r);
  } else if (op1.kind == Kind_zBarrier_RISCV_rw_rw && op2.kind == Kind_zBarrier_RISCV_rw_rw) {
    return EQUAL(unit)(op1.zBarrier_RISCV_rw_rw, op2.zBarrier_RISCV_rw_rw);
  } else if (op1.kind == Kind_zBarrier_RISCV_rw_w && op2.kind == Kind_zBarrier_RISCV_rw_w) {
    return EQUAL(unit)(op1.zBarrier_RISCV_rw_w, op2.zBarrier_RISCV_rw_w);
  } else if (op1.kind == Kind_zBarrier_RISCV_tso && op2.kind == Kind_zBarrier_RISCV_tso) {
    return EQUAL(unit)(op1.zBarrier_RISCV_tso, op2.zBarrier_RISCV_tso);
  } else if (op1.kind == Kind_zBarrier_RISCV_w_r && op2.kind == Kind_zBarrier_RISCV_w_r) {
    return EQUAL(unit)(op1.zBarrier_RISCV_w_r, op2.zBarrier_RISCV_w_r);
  } else if (op1.kind == Kind_zBarrier_RISCV_w_rw && op2.kind == Kind_zBarrier_RISCV_w_rw) {
    return EQUAL(unit)(op1.zBarrier_RISCV_w_rw, op2.zBarrier_RISCV_w_rw);
  } else if (op1.kind == Kind_zBarrier_RISCV_w_w && op2.kind == Kind_zBarrier_RISCV_w_w) {
    return EQUAL(unit)(op1.zBarrier_RISCV_w_w, op2.zBarrier_RISCV_w_w);
  } else if (op1.kind == Kind_zBarrier_Sync && op2.kind == Kind_zBarrier_Sync) {
    return EQUAL(unit)(op1.zBarrier_Sync, op2.zBarrier_Sync);
  } else if (op1.kind == Kind_zBarrier_x86_MFENCE && op2.kind == Kind_zBarrier_x86_MFENCE) {
    return EQUAL(unit)(op1.zBarrier_x86_MFENCE, op2.zBarrier_x86_MFENCE);
  } else return false;
}

static void sailgen_Barrier_DMB(struct zbarrier_kind *rop, struct ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9 op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_DMB;
  rop->zBarrier_DMB = op;
}

static void sailgen_Barrier_DSB(struct zbarrier_kind *rop, struct ztuple_z8z5enumz0zza64_barrier_domainzCz0z5enumz0zza64_barrier_typez9 op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_DSB;
  rop->zBarrier_DSB = op;
}

static void sailgen_Barrier_Eieio(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_Eieio;
  rop->zBarrier_Eieio = op;
}

static void sailgen_Barrier_ISB(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_ISB;
  rop->zBarrier_ISB = op;
}

static void sailgen_Barrier_Isync(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_Isync;
  rop->zBarrier_Isync = op;
}

static void sailgen_Barrier_LwSync(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_LwSync;
  rop->zBarrier_LwSync = op;
}

static void sailgen_Barrier_MIPS_SYNC(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_MIPS_SYNC;
  rop->zBarrier_MIPS_SYNC = op;
}

static void sailgen_Barrier_RISCV_i(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_RISCV_i;
  rop->zBarrier_RISCV_i = op;
}

static void sailgen_Barrier_RISCV_r_r(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_RISCV_r_r;
  rop->zBarrier_RISCV_r_r = op;
}

static void sailgen_Barrier_RISCV_r_rw(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_RISCV_r_rw;
  rop->zBarrier_RISCV_r_rw = op;
}

static void sailgen_Barrier_RISCV_r_w(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_RISCV_r_w;
  rop->zBarrier_RISCV_r_w = op;
}

static void sailgen_Barrier_RISCV_rw_r(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_RISCV_rw_r;
  rop->zBarrier_RISCV_rw_r = op;
}

static void sailgen_Barrier_RISCV_rw_rw(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_RISCV_rw_rw;
  rop->zBarrier_RISCV_rw_rw = op;
}

static void sailgen_Barrier_RISCV_rw_w(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_RISCV_rw_w;
  rop->zBarrier_RISCV_rw_w = op;
}

static void sailgen_Barrier_RISCV_tso(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_RISCV_tso;
  rop->zBarrier_RISCV_tso = op;
}

static void sailgen_Barrier_RISCV_w_r(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_RISCV_w_r;
  rop->zBarrier_RISCV_w_r = op;
}

static void sailgen_Barrier_RISCV_w_rw(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_RISCV_w_rw;
  rop->zBarrier_RISCV_w_rw = op;
}

static void sailgen_Barrier_RISCV_w_w(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_RISCV_w_w;
  rop->zBarrier_RISCV_w_w = op;
}

static void sailgen_Barrier_Sync(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_Sync;
  rop->zBarrier_Sync = op;
}

static void sailgen_Barrier_x86_MFENCE(struct zbarrier_kind *rop, unit op)
{
  if (rop->kind == Kind_zBarrier_DMB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_DSB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Eieio) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_ISB) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Isync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_LwSync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_MIPS_SYNC) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_i) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_r_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_rw_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_tso) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_r) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_rw) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_RISCV_w_w) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_Sync) {
    /* do nothing */
  } else if (rop->kind == Kind_zBarrier_x86_MFENCE){
    /* do nothing */
  }
  rop->kind = Kind_zBarrier_x86_MFENCE;
  rop->zBarrier_x86_MFENCE = op;
}

// struct tuple_(%enum zread_kind, %enum zwrite_kind)
struct ztuple_z8z5enumz0zzread_kindzCz0z5enumz0zzwrite_kindz9 {
  enum zread_kind ztup0;
  enum zwrite_kind ztup1;
};

static void COPY(ztuple_z8z5enumz0zzread_kindzCz0z5enumz0zzwrite_kindz9)(struct ztuple_z8z5enumz0zzread_kindzCz0z5enumz0zzwrite_kindz9 *rop, const struct ztuple_z8z5enumz0zzread_kindzCz0z5enumz0zzwrite_kindz9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
}

static bool EQUAL(ztuple_z8z5enumz0zzread_kindzCz0z5enumz0zzwrite_kindz9)(struct ztuple_z8z5enumz0zzread_kindzCz0z5enumz0zzwrite_kindz9 op1, struct ztuple_z8z5enumz0zzread_kindzCz0z5enumz0zzwrite_kindz9 op2) {
  return EQUAL(zread_kind)(op1.ztup0, op2.ztup0) && EQUAL(zwrite_kind)(op1.ztup1, op2.ztup1);
}



// union instruction_kind
enum kind_zinstruction_kind { Kind_zIK_barrier, Kind_zIK_branch, Kind_zIK_cache_op, Kind_zIK_mem_read, Kind_zIK_mem_rmw, Kind_zIK_mem_write, Kind_zIK_simple, Kind_zIK_trans };

struct zinstruction_kind {
  enum kind_zinstruction_kind kind;
  union {
    struct { struct zbarrier_kind zIK_barrier; };
    struct { unit zIK_branch; };
    struct { enum zcache_op_kind zIK_cache_op; };
    struct { enum zread_kind zIK_mem_read; };
    struct { struct ztuple_z8z5enumz0zzread_kindzCz0z5enumz0zzwrite_kindz9 zIK_mem_rmw; };
    struct { enum zwrite_kind zIK_mem_write; };
    struct { unit zIK_simple; };
    struct { enum ztrans_kind zIK_trans; };
  };
};

static void CREATE(zinstruction_kind)(struct zinstruction_kind *op)
{
  op->kind = Kind_zIK_barrier;
  CREATE(zbarrier_kind)(&op->zIK_barrier);
}

static void RECREATE(zinstruction_kind)(struct zinstruction_kind *op) {}

static void KILL(zinstruction_kind)(struct zinstruction_kind *op)
{
  if (op->kind == Kind_zIK_barrier) {
    KILL(zbarrier_kind)(&op->zIK_barrier);
  } else if (op->kind == Kind_zIK_branch) {
    /* do nothing */
  } else if (op->kind == Kind_zIK_cache_op) {
    /* do nothing */
  } else if (op->kind == Kind_zIK_mem_read) {
    /* do nothing */
  } else if (op->kind == Kind_zIK_mem_rmw) {
    /* do nothing */
  } else if (op->kind == Kind_zIK_mem_write) {
    /* do nothing */
  } else if (op->kind == Kind_zIK_simple) {
    /* do nothing */
  } else if (op->kind == Kind_zIK_trans){
    /* do nothing */
  };
}

static void COPY(zinstruction_kind)(struct zinstruction_kind *rop, struct zinstruction_kind op)
{
  if (rop->kind == Kind_zIK_barrier) {
    KILL(zbarrier_kind)(&rop->zIK_barrier);
  } else if (rop->kind == Kind_zIK_branch) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_cache_op) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_read) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_rmw) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_write) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_simple) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_trans){
    /* do nothing */
  };
  rop->kind = op.kind;
  if (op.kind == Kind_zIK_barrier) {
    CREATE(zbarrier_kind)(&rop->zIK_barrier); COPY(zbarrier_kind)(&rop->zIK_barrier, op.zIK_barrier);
  } else if (op.kind == Kind_zIK_branch) {
    rop->zIK_branch = op.zIK_branch;
  } else if (op.kind == Kind_zIK_cache_op) {
    rop->zIK_cache_op = op.zIK_cache_op;
  } else if (op.kind == Kind_zIK_mem_read) {
    rop->zIK_mem_read = op.zIK_mem_read;
  } else if (op.kind == Kind_zIK_mem_rmw) {
    rop->zIK_mem_rmw = op.zIK_mem_rmw;
  } else if (op.kind == Kind_zIK_mem_write) {
    rop->zIK_mem_write = op.zIK_mem_write;
  } else if (op.kind == Kind_zIK_simple) {
    rop->zIK_simple = op.zIK_simple;
  } else if (op.kind == Kind_zIK_trans){
    rop->zIK_trans = op.zIK_trans;
  }
}

static bool EQUAL(zinstruction_kind)(struct zinstruction_kind op1, struct zinstruction_kind op2) {
  if (op1.kind == Kind_zIK_barrier && op2.kind == Kind_zIK_barrier) {
    return EQUAL(zbarrier_kind)(op1.zIK_barrier, op2.zIK_barrier);
  } else if (op1.kind == Kind_zIK_branch && op2.kind == Kind_zIK_branch) {
    return EQUAL(unit)(op1.zIK_branch, op2.zIK_branch);
  } else if (op1.kind == Kind_zIK_cache_op && op2.kind == Kind_zIK_cache_op) {
    return EQUAL(zcache_op_kind)(op1.zIK_cache_op, op2.zIK_cache_op);
  } else if (op1.kind == Kind_zIK_mem_read && op2.kind == Kind_zIK_mem_read) {
    return EQUAL(zread_kind)(op1.zIK_mem_read, op2.zIK_mem_read);
  } else if (op1.kind == Kind_zIK_mem_rmw && op2.kind == Kind_zIK_mem_rmw) {
    return EQUAL(ztuple_z8z5enumz0zzread_kindzCz0z5enumz0zzwrite_kindz9)(op1.zIK_mem_rmw, op2.zIK_mem_rmw);
  } else if (op1.kind == Kind_zIK_mem_write && op2.kind == Kind_zIK_mem_write) {
    return EQUAL(zwrite_kind)(op1.zIK_mem_write, op2.zIK_mem_write);
  } else if (op1.kind == Kind_zIK_simple && op2.kind == Kind_zIK_simple) {
    return EQUAL(unit)(op1.zIK_simple, op2.zIK_simple);
  } else if (op1.kind == Kind_zIK_trans && op2.kind == Kind_zIK_trans) {
    return EQUAL(ztrans_kind)(op1.zIK_trans, op2.zIK_trans);
  } else return false;
}

static void sailgen_IK_barrier(struct zinstruction_kind *rop, struct zbarrier_kind op)
{
  if (rop->kind == Kind_zIK_barrier) {
    KILL(zbarrier_kind)(&rop->zIK_barrier);
  } else if (rop->kind == Kind_zIK_branch) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_cache_op) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_read) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_rmw) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_write) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_simple) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_trans){
    /* do nothing */
  }
  rop->kind = Kind_zIK_barrier;
  CREATE(zbarrier_kind)(&rop->zIK_barrier);
  COPY(zbarrier_kind)(&rop->zIK_barrier, op);
  
}

static void sailgen_IK_branch(struct zinstruction_kind *rop, unit op)
{
  if (rop->kind == Kind_zIK_barrier) {
    KILL(zbarrier_kind)(&rop->zIK_barrier);
  } else if (rop->kind == Kind_zIK_branch) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_cache_op) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_read) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_rmw) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_write) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_simple) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_trans){
    /* do nothing */
  }
  rop->kind = Kind_zIK_branch;
  rop->zIK_branch = op;
}

static void sailgen_IK_cache_op(struct zinstruction_kind *rop, enum zcache_op_kind op)
{
  if (rop->kind == Kind_zIK_barrier) {
    KILL(zbarrier_kind)(&rop->zIK_barrier);
  } else if (rop->kind == Kind_zIK_branch) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_cache_op) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_read) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_rmw) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_write) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_simple) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_trans){
    /* do nothing */
  }
  rop->kind = Kind_zIK_cache_op;
  rop->zIK_cache_op = op;
}

static void sailgen_IK_mem_read(struct zinstruction_kind *rop, enum zread_kind op)
{
  if (rop->kind == Kind_zIK_barrier) {
    KILL(zbarrier_kind)(&rop->zIK_barrier);
  } else if (rop->kind == Kind_zIK_branch) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_cache_op) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_read) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_rmw) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_write) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_simple) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_trans){
    /* do nothing */
  }
  rop->kind = Kind_zIK_mem_read;
  rop->zIK_mem_read = op;
}

static void sailgen_IK_mem_rmw(struct zinstruction_kind *rop, struct ztuple_z8z5enumz0zzread_kindzCz0z5enumz0zzwrite_kindz9 op)
{
  if (rop->kind == Kind_zIK_barrier) {
    KILL(zbarrier_kind)(&rop->zIK_barrier);
  } else if (rop->kind == Kind_zIK_branch) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_cache_op) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_read) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_rmw) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_write) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_simple) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_trans){
    /* do nothing */
  }
  rop->kind = Kind_zIK_mem_rmw;
  rop->zIK_mem_rmw = op;
}

static void sailgen_IK_mem_write(struct zinstruction_kind *rop, enum zwrite_kind op)
{
  if (rop->kind == Kind_zIK_barrier) {
    KILL(zbarrier_kind)(&rop->zIK_barrier);
  } else if (rop->kind == Kind_zIK_branch) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_cache_op) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_read) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_rmw) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_write) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_simple) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_trans){
    /* do nothing */
  }
  rop->kind = Kind_zIK_mem_write;
  rop->zIK_mem_write = op;
}

static void sailgen_IK_simple(struct zinstruction_kind *rop, unit op)
{
  if (rop->kind == Kind_zIK_barrier) {
    KILL(zbarrier_kind)(&rop->zIK_barrier);
  } else if (rop->kind == Kind_zIK_branch) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_cache_op) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_read) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_rmw) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_write) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_simple) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_trans){
    /* do nothing */
  }
  rop->kind = Kind_zIK_simple;
  rop->zIK_simple = op;
}

static void sailgen_IK_trans(struct zinstruction_kind *rop, enum ztrans_kind op)
{
  if (rop->kind == Kind_zIK_barrier) {
    KILL(zbarrier_kind)(&rop->zIK_barrier);
  } else if (rop->kind == Kind_zIK_branch) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_cache_op) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_read) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_rmw) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_mem_write) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_simple) {
    /* do nothing */
  } else if (rop->kind == Kind_zIK_trans){
    /* do nothing */
  }
  rop->kind = Kind_zIK_trans;
  rop->zIK_trans = op;
}

// enum ClearRegSet
enum zClearRegSet { zGPRegs, zFPRegs };

static bool eq_zClearRegSet(enum zClearRegSet op1, enum zClearRegSet op2) { return op1 == op2; }

enum zClearRegSet UNDEFINED(zClearRegSet)(unit u) { return zGPRegs; }

// struct Capability
struct zCapability {
  uint64_t zB;
  uint64_t zE;
  uint64_t zT;
  bool zaccess_system_regs;
  uint64_t zaddress;
  bool zflag_cap_mode;
  bool zglobal;
  bool zinternal_e;
  uint64_t zotype;
  bool zpermit_ccall;
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
  bool zsealed;
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
  rop->zinternal_e = op.zinternal_e;
  rop->zotype = op.zotype;
  rop->zpermit_ccall = op.zpermit_ccall;
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
  rop->zsealed = op.zsealed;
  rop->ztag = op.ztag;
  rop->zuperms = op.zuperms;
}

static bool EQUAL(zCapability)(struct zCapability op1, struct zCapability op2) {
  return EQUAL(fbits)(op1.zB, op2.zB) && EQUAL(fbits)(op1.zE, op2.zE) && EQUAL(fbits)(op1.zT, op2.zT) && EQUAL(bool)(op1.zaccess_system_regs, op2.zaccess_system_regs) && EQUAL(fbits)(op1.zaddress, op2.zaddress) && EQUAL(bool)(op1.zflag_cap_mode, op2.zflag_cap_mode) && EQUAL(bool)(op1.zglobal, op2.zglobal) && EQUAL(bool)(op1.zinternal_e, op2.zinternal_e) && EQUAL(fbits)(op1.zotype, op2.zotype) && EQUAL(bool)(op1.zpermit_ccall, op2.zpermit_ccall) && EQUAL(bool)(op1.zpermit_execute, op2.zpermit_execute) && EQUAL(bool)(op1.zpermit_load, op2.zpermit_load) && EQUAL(bool)(op1.zpermit_load_cap, op2.zpermit_load_cap) && EQUAL(bool)(op1.zpermit_seal, op2.zpermit_seal) && EQUAL(bool)(op1.zpermit_set_CID, op2.zpermit_set_CID) && EQUAL(bool)(op1.zpermit_store, op2.zpermit_store) && EQUAL(bool)(op1.zpermit_store_cap, op2.zpermit_store_cap) && EQUAL(bool)(op1.zpermit_store_local_cap, op2.zpermit_store_local_cap) && EQUAL(bool)(op1.zpermit_unseal, op2.zpermit_unseal) && EQUAL(fbits)(op1.zreserved, op2.zreserved) && EQUAL(bool)(op1.zsealed, op2.zsealed) && EQUAL(bool)(op1.ztag, op2.ztag) && EQUAL(fbits)(op1.zuperms, op2.zuperms);
}

// enum CapEx
enum zCapEx { zCapEx_None, zCapEx_LengthViolation, zCapEx_TagViolation, zCapEx_SealViolation, zCapEx_TypeViolation, zCapEx_CallTrap, zCapEx_ReturnTrap, zCapEx_TSSUnderFlow, zCapEx_UserDefViolation, zCapEx_TLBNoStoreCap, zCapEx_InexactBounds, zCapEx_UnalignedBase, zCapEx_GlobalViolation, zCapEx_PermitExecuteViolation, zCapEx_PermitLoadViolation, zCapEx_PermitStoreViolation, zCapEx_PermitLoadCapViolation, zCapEx_PermitStoreCapViolation, zCapEx_PermitStoreLocalCapViolation, zCapEx_PermitSealViolation, zCapEx_AccessSystemRegsViolation, zCapEx_PermitCCallViolation, zCapEx_AccessCCallIDCViolation, zCapEx_PermitUnsealViolation, zCapEx_PermitSetCIDViolation };

static bool eq_zCapEx(enum zCapEx op1, enum zCapEx op2) { return op1 == op2; }

enum zCapEx UNDEFINED(zCapEx)(unit u) { return zCapEx_None; }

// struct cheri_cause
struct zcheri_cause {
  enum zCapEx zcapEx;
  uint64_t zcap_idx;
};

static void COPY(zcheri_cause)(struct zcheri_cause *rop, const struct zcheri_cause op) {
  rop->zcapEx = op.zcapEx;
  rop->zcap_idx = op.zcap_idx;
}

static bool EQUAL(zcheri_cause)(struct zcheri_cause op1, struct zcheri_cause op2) {
  return EQUAL(zCapEx)(op1.zcapEx, op2.zcapEx) && EQUAL(fbits)(op1.zcap_idx, op2.zcap_idx);
}

// enum CPtrCmpOp
enum zCPtrCmpOp { zCEQ, zCNE, zCLT, zCLE, zCLTU, zCLEU, zCEXEQ, zCNEXEQ };

static bool eq_zCPtrCmpOp(enum zCPtrCmpOp op1, enum zCPtrCmpOp op2) { return op1 == op2; }

enum zCPtrCmpOp UNDEFINED(zCPtrCmpOp)(unit u) { return zCEQ; }

















static bool sailgen_zzz3zzzz7mzzJzzK0z3neq_int(sail_int, int64_t);

static bool sailgen_zzz3zzzz7mzzJzzK0z3neq_int(sail_int zx, int64_t zy)
{
  __label__ end_function_1, end_block_exception_2;

  bool zcbz30;
  bool zgaz30;
  {
    sail_int zgsz30;
    CREATE(sail_int)(&zgsz30);
    CONVERT_OF(sail_int, mach_int)(&zgsz30, zy);
    zgaz30 = eq_int(zx, zgsz30);
    KILL(sail_int)(&zgsz30);
  }
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

































static uint64_t sailgen_zzzz7nzzJzzK0z3sail_ones(int64_t);

static uint64_t sailgen_zzzz7nzzJzzK31z3sail_ones(int64_t);

static void sailgen_zzz3zzz3sail_ones(lbits *rop, sail_int);

static uint64_t sailgen_zzzz7nzzJzzK0z3sail_ones(int64_t zn)
{
  __label__ end_function_7, end_block_exception_8;

  uint64_t zcbz32;
  uint64_t zgaz32;
  {
    sail_int zgsz31;
    CREATE(sail_int)(&zgsz31);
    CONVERT_OF(sail_int, mach_int)(&zgsz31, zn);
    lbits zgsz32;
    CREATE(lbits)(&zgsz32);
    zeros(&zgsz32, zgsz31);
    zgaz32 = CONVERT_OF(fbits, lbits)(zgsz32, true);
    KILL(lbits)(&zgsz32);
    KILL(sail_int)(&zgsz31);
  }
  {
    lbits zgsz33;
    CREATE(lbits)(&zgsz33);
    CONVERT_OF(lbits, fbits)(&zgsz33, zgaz32, UINT64_C(0) , true);
    lbits zgsz34;
    CREATE(lbits)(&zgsz34);
    not_bits(&zgsz34, zgsz33);
    zcbz32 = CONVERT_OF(fbits, lbits)(zgsz34, true);
    KILL(lbits)(&zgsz34);
    KILL(lbits)(&zgsz33);
  }

end_function_7: ;
  return zcbz32;
end_block_exception_8: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_zzzz7nzzJzzK31z3sail_ones(int64_t zn)
{
  __label__ end_function_10, end_block_exception_11;

  uint64_t zcbz33;
  uint64_t zgaz33;
  {
    sail_int zgsz35;
    CREATE(sail_int)(&zgsz35);
    CONVERT_OF(sail_int, mach_int)(&zgsz35, zn);
    lbits zgsz36;
    CREATE(lbits)(&zgsz36);
    zeros(&zgsz36, zgsz35);
    zgaz33 = CONVERT_OF(fbits, lbits)(zgsz36, true);
    KILL(lbits)(&zgsz36);
    KILL(sail_int)(&zgsz35);
  }
  {
    lbits zgsz37;
    CREATE(lbits)(&zgsz37);
    CONVERT_OF(lbits, fbits)(&zgsz37, zgaz33, UINT64_C(31) , true);
    lbits zgsz38;
    CREATE(lbits)(&zgsz38);
    not_bits(&zgsz38, zgsz37);
    zcbz33 = CONVERT_OF(fbits, lbits)(zgsz38, true);
    KILL(lbits)(&zgsz38);
    KILL(lbits)(&zgsz37);
  }

end_function_10: ;
  return zcbz33;
end_block_exception_11: ;

  return UINT64_C(0xdeadc0de);
}

static void sailgen_zzz3zzz3sail_ones(lbits *zcbz34, sail_int zn)
{
  __label__ end_function_13, end_block_exception_14, end_function_225;

  lbits zgaz34;
  CREATE(lbits)(&zgaz34);
  zeros(&zgaz34, zn);
  not_bits((*(&zcbz34)), zgaz34);
  KILL(lbits)(&zgaz34);
end_function_13: ;
  goto end_function_225;
end_block_exception_14: ;
  goto end_function_225;
end_function_225: ;
}











static fbits sailgen_not_bit(fbits);

static fbits sailgen_not_bit(fbits zb)
{
  __label__ end_function_16, end_block_exception_17;

  fbits zcbz35;
  bool zgaz35;
  zgaz35 = eq_bit(zb, UINT64_C(1));
  if (zgaz35) {  zcbz35 = UINT64_C(0);  } else {  zcbz35 = UINT64_C(1);  }

end_function_16: ;
  return zcbz35;
end_block_exception_17: ;

  return UINT64_C(0);
}













static uint64_t sailgen_zzzz7mzzJzzK32zzCzz0zz7nzzJzzK4z3EXTS(int64_t, uint64_t);

static void sailgen_zzz3zzz3EXTZ(lbits *rop, sail_int, lbits);

static uint64_t sailgen_zzzz7mzzJzzK15zzCzz0zz7nzzJzzK12z3EXTZ(int64_t, uint64_t);

static uint64_t sailgen_zzz3zzzz7mzzJzzK31z3EXTZ(int64_t, sbits);

static uint64_t sailgen_zzzz7mzzJzzK32zzCzz0zz7nzzJzzK4z3EXTZ(int64_t, uint64_t);

static uint64_t sailgen_zzzz7mzzJzzK32zzCzz0zz7nzzJzzK4z3EXTS(int64_t zm, uint64_t zv)
{
  __label__ end_function_19, end_block_exception_20;

  uint64_t zcbz36;
  {
    lbits zgsz39;
    CREATE(lbits)(&zgsz39);
    CONVERT_OF(lbits, fbits)(&zgsz39, zv, UINT64_C(4) , true);
    sail_int zgsz310;
    CREATE(sail_int)(&zgsz310);
    CONVERT_OF(sail_int, mach_int)(&zgsz310, zm);
    lbits zgsz311;
    CREATE(lbits)(&zgsz311);
    sign_extend(&zgsz311, zgsz39, zgsz310);
    zcbz36 = CONVERT_OF(fbits, lbits)(zgsz311, true);
    KILL(lbits)(&zgsz311);
    KILL(sail_int)(&zgsz310);
    KILL(lbits)(&zgsz39);
  }
end_function_19: ;
  return zcbz36;
end_block_exception_20: ;

  return UINT64_C(0xdeadc0de);
}

static void sailgen_zzz3zzz3EXTZ(lbits *zcbz37, sail_int zm, lbits zv)
{
  __label__ end_function_22, end_block_exception_23, end_function_224;

  zero_extend((*(&zcbz37)), zv, zm);
end_function_22: ;
  goto end_function_224;
end_block_exception_23: ;
  goto end_function_224;
end_function_224: ;
}

static uint64_t sailgen_zzzz7mzzJzzK15zzCzz0zz7nzzJzzK12z3EXTZ(int64_t zm, uint64_t zv)
{
  __label__ end_function_25, end_block_exception_26;

  uint64_t zcbz38;
  {
    lbits zgsz312;
    CREATE(lbits)(&zgsz312);
    CONVERT_OF(lbits, fbits)(&zgsz312, zv, UINT64_C(12) , true);
    sail_int zgsz313;
    CREATE(sail_int)(&zgsz313);
    CONVERT_OF(sail_int, mach_int)(&zgsz313, zm);
    lbits zgsz314;
    CREATE(lbits)(&zgsz314);
    zero_extend(&zgsz314, zgsz312, zgsz313);
    zcbz38 = CONVERT_OF(fbits, lbits)(zgsz314, true);
    KILL(lbits)(&zgsz314);
    KILL(sail_int)(&zgsz313);
    KILL(lbits)(&zgsz312);
  }
end_function_25: ;
  return zcbz38;
end_block_exception_26: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_zzz3zzzz7mzzJzzK31z3EXTZ(int64_t zm, sbits zv)
{
  __label__ end_function_28, end_block_exception_29;

  uint64_t zcbz39;
  {
    lbits zgsz315;
    CREATE(lbits)(&zgsz315);
    CONVERT_OF(lbits, sbits)(&zgsz315, zv, true);
    sail_int zgsz316;
    CREATE(sail_int)(&zgsz316);
    CONVERT_OF(sail_int, mach_int)(&zgsz316, zm);
    lbits zgsz317;
    CREATE(lbits)(&zgsz317);
    zero_extend(&zgsz317, zgsz315, zgsz316);
    zcbz39 = CONVERT_OF(fbits, lbits)(zgsz317, true);
    KILL(lbits)(&zgsz317);
    KILL(sail_int)(&zgsz316);
    KILL(lbits)(&zgsz315);
  }
end_function_28: ;
  return zcbz39;
end_block_exception_29: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_zzzz7mzzJzzK32zzCzz0zz7nzzJzzK4z3EXTZ(int64_t zm, uint64_t zv)
{
  __label__ end_function_31, end_block_exception_32;

  uint64_t zcbz310;
  {
    lbits zgsz318;
    CREATE(lbits)(&zgsz318);
    CONVERT_OF(lbits, fbits)(&zgsz318, zv, UINT64_C(4) , true);
    sail_int zgsz319;
    CREATE(sail_int)(&zgsz319);
    CONVERT_OF(sail_int, mach_int)(&zgsz319, zm);
    lbits zgsz320;
    CREATE(lbits)(&zgsz320);
    zero_extend(&zgsz320, zgsz318, zgsz319);
    zcbz310 = CONVERT_OF(fbits, lbits)(zgsz320, true);
    KILL(lbits)(&zgsz320);
    KILL(sail_int)(&zgsz319);
    KILL(lbits)(&zgsz318);
  }
end_function_31: ;
  return zcbz310;
end_block_exception_32: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_zzzz7nzzJzzK32z3zzeros_implicit(int64_t);

static uint64_t sailgen_zzzz7nzzJzzK8z3zzeros_implicit(int64_t);

static uint64_t sailgen_zzzz7nzzJzzK0z3zzeros_implicit(int64_t);

static uint64_t sailgen_zzzz7nzzJzzK6z3zzeros_implicit(int64_t);

static uint64_t sailgen_zzzz7nzzJzzK2z3zzeros_implicit(int64_t);

static void sailgen_zzz3zzz3zzeros_implicit(lbits *rop, sail_int);

static uint64_t sailgen_zzzz7nzzJzzK5z3zzeros_implicit(int64_t);

static uint64_t sailgen_zzzz7nzzJzzK32z3zzeros_implicit(int64_t zn)
{
  __label__ end_function_34, end_block_exception_35;

  uint64_t zcbz311;
  {
    sail_int zgsz321;
    CREATE(sail_int)(&zgsz321);
    CONVERT_OF(sail_int, mach_int)(&zgsz321, zn);
    lbits zgsz322;
    CREATE(lbits)(&zgsz322);
    zeros(&zgsz322, zgsz321);
    zcbz311 = CONVERT_OF(fbits, lbits)(zgsz322, true);
    KILL(lbits)(&zgsz322);
    KILL(sail_int)(&zgsz321);
  }
end_function_34: ;
  return zcbz311;
end_block_exception_35: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_zzzz7nzzJzzK8z3zzeros_implicit(int64_t zn)
{
  __label__ end_function_37, end_block_exception_38;

  uint64_t zcbz312;
  {
    sail_int zgsz323;
    CREATE(sail_int)(&zgsz323);
    CONVERT_OF(sail_int, mach_int)(&zgsz323, zn);
    lbits zgsz324;
    CREATE(lbits)(&zgsz324);
    zeros(&zgsz324, zgsz323);
    zcbz312 = CONVERT_OF(fbits, lbits)(zgsz324, true);
    KILL(lbits)(&zgsz324);
    KILL(sail_int)(&zgsz323);
  }
end_function_37: ;
  return zcbz312;
end_block_exception_38: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_zzzz7nzzJzzK0z3zzeros_implicit(int64_t zn)
{
  __label__ end_function_40, end_block_exception_41;

  uint64_t zcbz313;
  {
    sail_int zgsz325;
    CREATE(sail_int)(&zgsz325);
    CONVERT_OF(sail_int, mach_int)(&zgsz325, zn);
    lbits zgsz326;
    CREATE(lbits)(&zgsz326);
    zeros(&zgsz326, zgsz325);
    zcbz313 = CONVERT_OF(fbits, lbits)(zgsz326, true);
    KILL(lbits)(&zgsz326);
    KILL(sail_int)(&zgsz325);
  }
end_function_40: ;
  return zcbz313;
end_block_exception_41: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_zzzz7nzzJzzK6z3zzeros_implicit(int64_t zn)
{
  __label__ end_function_43, end_block_exception_44;

  uint64_t zcbz314;
  {
    sail_int zgsz327;
    CREATE(sail_int)(&zgsz327);
    CONVERT_OF(sail_int, mach_int)(&zgsz327, zn);
    lbits zgsz328;
    CREATE(lbits)(&zgsz328);
    zeros(&zgsz328, zgsz327);
    zcbz314 = CONVERT_OF(fbits, lbits)(zgsz328, true);
    KILL(lbits)(&zgsz328);
    KILL(sail_int)(&zgsz327);
  }
end_function_43: ;
  return zcbz314;
end_block_exception_44: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_zzzz7nzzJzzK2z3zzeros_implicit(int64_t zn)
{
  __label__ end_function_46, end_block_exception_47;

  uint64_t zcbz315;
  {
    sail_int zgsz329;
    CREATE(sail_int)(&zgsz329);
    CONVERT_OF(sail_int, mach_int)(&zgsz329, zn);
    lbits zgsz330;
    CREATE(lbits)(&zgsz330);
    zeros(&zgsz330, zgsz329);
    zcbz315 = CONVERT_OF(fbits, lbits)(zgsz330, true);
    KILL(lbits)(&zgsz330);
    KILL(sail_int)(&zgsz329);
  }
end_function_46: ;
  return zcbz315;
end_block_exception_47: ;

  return UINT64_C(0xdeadc0de);
}

static void sailgen_zzz3zzz3zzeros_implicit(lbits *zcbz316, sail_int zn)
{
  __label__ end_function_49, end_block_exception_50, end_function_223;

  zeros((*(&zcbz316)), zn);
end_function_49: ;
  goto end_function_223;
end_block_exception_50: ;
  goto end_function_223;
end_function_223: ;
}

static uint64_t sailgen_zzzz7nzzJzzK5z3zzeros_implicit(int64_t zn)
{
  __label__ end_function_52, end_block_exception_53;

  uint64_t zcbz317;
  {
    sail_int zgsz331;
    CREATE(sail_int)(&zgsz331);
    CONVERT_OF(sail_int, mach_int)(&zgsz331, zn);
    lbits zgsz332;
    CREATE(lbits)(&zgsz332);
    zeros(&zgsz332, zgsz331);
    zcbz317 = CONVERT_OF(fbits, lbits)(zgsz332, true);
    KILL(lbits)(&zgsz332);
    KILL(sail_int)(&zgsz331);
  }
end_function_52: ;
  return zcbz317;
end_block_exception_53: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_zzzz7nzzJzzK0z3ones(int64_t);

static void sailgen_zzz3zzz3ones(lbits *rop, sail_int);

static uint64_t sailgen_zzzz7nzzJzzK31z3ones(int64_t);

static uint64_t sailgen_zzzz7nzzJzzK0z3ones(int64_t zn)
{
  __label__ end_function_55, end_block_exception_56;

  uint64_t zcbz318;
  zcbz318 = sailgen_zzzz7nzzJzzK0z3sail_ones(zn);
end_function_55: ;
  return zcbz318;
end_block_exception_56: ;

  return UINT64_C(0xdeadc0de);
}

static void sailgen_zzz3zzz3ones(lbits *zcbz319, sail_int zn)
{
  __label__ end_function_58, end_block_exception_59, end_function_222;

  sailgen_zzz3zzz3sail_ones((*(&zcbz319)), zn);
end_function_58: ;
  goto end_function_222;
end_block_exception_59: ;
  goto end_function_222;
end_function_222: ;
}

static uint64_t sailgen_zzzz7nzzJzzK31z3ones(int64_t zn)
{
  __label__ end_function_61, end_block_exception_62;

  uint64_t zcbz320;
  zcbz320 = sailgen_zzzz7nzzJzzK31z3sail_ones(zn);
end_function_61: ;
  return zcbz320;
end_block_exception_62: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_bool_to_bits(bool);

static uint64_t sailgen_bool_to_bits(bool zx)
{
  __label__ end_function_64, end_block_exception_65;

  uint64_t zcbz321;
  if (zx) {  zcbz321 = UINT64_C(0b1);  } else {  zcbz321 = UINT64_C(0b0);  }
end_function_64: ;
  return zcbz321;
end_block_exception_65: ;

  return UINT64_C(0xdeadc0de);
}

static bool sailgen_bit_to_bool(fbits);

static bool sailgen_bit_to_bool(fbits zb)
{
  __label__ case_68, case_69, finish_match_67, end_function_70, end_block_exception_71;

  bool zcbz322;
  bool zgsz333;
  {
    fbits zp0z3;
    zp0z3 = zb;
    bool zgsz334;
    zgsz334 = eq_bit(zp0z3, UINT64_C(1));
    if (!(zgsz334)) {
  
    goto case_68;
    }
    zgsz333 = true;
  
    goto finish_match_67;
  }
case_68: ;
  {
    fbits zp0z3;
    zp0z3 = zb;
    bool zgsz335;
    zgsz335 = eq_bit(zp0z3, UINT64_C(0));
    if (!(zgsz335)) {
  
    goto case_69;
    }
    zgsz333 = false;
  
    goto finish_match_67;
  }
case_69: ;
  sail_match_failure("bit_to_bool");
finish_match_67: ;
  zcbz322 = zgsz333;

end_function_70: ;
  return zcbz322;
end_block_exception_71: ;

  return false;
}

static void sailgen_to_bits(lbits *rop, sail_int, sail_int);

static uint64_t sailgen_zzzz7lzzJzzK6z3to_bits(int64_t, sail_int);

static uint64_t sailgen_zzzz7lzzJzzK36z3to_bits(int64_t, sail_int);

static void sailgen_to_bits(lbits *zcbz323, sail_int zl, sail_int zn)
{
  __label__ end_function_73, end_block_exception_74, end_function_221;

  {
    sail_int zgsz336;
    CREATE(sail_int)(&zgsz336);
    CONVERT_OF(sail_int, mach_int)(&zgsz336, 0l);
    get_slice_int((*(&zcbz323)), zl, zn, zgsz336);
    KILL(sail_int)(&zgsz336);
  }
end_function_73: ;
  goto end_function_221;
end_block_exception_74: ;
  goto end_function_221;
end_function_221: ;
}

static uint64_t sailgen_zzzz7lzzJzzK6z3to_bits(int64_t zl, sail_int zn)
{
  __label__ end_function_76, end_block_exception_77;

  uint64_t zcbz324;
  {
    sail_int zgsz337;
    CREATE(sail_int)(&zgsz337);
    CONVERT_OF(sail_int, mach_int)(&zgsz337, zl);
    sail_int zgsz338;
    CREATE(sail_int)(&zgsz338);
    CONVERT_OF(sail_int, mach_int)(&zgsz338, 0l);
    lbits zgsz339;
    CREATE(lbits)(&zgsz339);
    get_slice_int(&zgsz339, zgsz337, zn, zgsz338);
    zcbz324 = CONVERT_OF(fbits, lbits)(zgsz339, true);
    KILL(lbits)(&zgsz339);
    KILL(sail_int)(&zgsz338);
    KILL(sail_int)(&zgsz337);
  }
end_function_76: ;
  return zcbz324;
end_block_exception_77: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_zzzz7lzzJzzK36z3to_bits(int64_t zl, sail_int zn)
{
  __label__ end_function_79, end_block_exception_80;

  uint64_t zcbz325;
  {
    sail_int zgsz340;
    CREATE(sail_int)(&zgsz340);
    CONVERT_OF(sail_int, mach_int)(&zgsz340, zl);
    sail_int zgsz341;
    CREATE(sail_int)(&zgsz341);
    CONVERT_OF(sail_int, mach_int)(&zgsz341, 0l);
    lbits zgsz342;
    CREATE(lbits)(&zgsz342);
    get_slice_int(&zgsz342, zgsz340, zn, zgsz341);
    zcbz325 = CONVERT_OF(fbits, lbits)(zgsz342, true);
    KILL(lbits)(&zgsz342);
    KILL(sail_int)(&zgsz341);
    KILL(sail_int)(&zgsz340);
  }
end_function_79: ;
  return zcbz325;
end_block_exception_80: ;

  return UINT64_C(0xdeadc0de);
}

static bool sailgen_z8operatorz0zzzz7nzzJzzK6z3zI_uz9(uint64_t, uint64_t);

static bool sailgen_z8operatorz0zzzz7nzzJzzK3z3zI_uz9(uint64_t, uint64_t);

static bool sailgen_z8operatorz0zzzz7nzzJzzK8z3zI_uz9(uint64_t, uint64_t);

static bool sailgen_z8operatorz0zzzz7nzzJzzK8z3zKzJ_uz9(uint64_t, uint64_t);

static bool sailgen_z8operatorz0zzzz7nzzJzzK6z3zI_uz9(uint64_t zx, uint64_t zy)
{
  __label__ end_function_82, end_block_exception_83;

  bool zcbz326;
  int64_t zgaz36;
  zgaz36 = ((mach_int) zx);
  int64_t zgaz37;
  zgaz37 = ((mach_int) zy);
  {
    sail_int zgsz344;
    CREATE(sail_int)(&zgsz344);
    CONVERT_OF(sail_int, mach_int)(&zgsz344, zgaz37);
    sail_int zgsz343;
    CREATE(sail_int)(&zgsz343);
    CONVERT_OF(sail_int, mach_int)(&zgsz343, zgaz36);
    zcbz326 = lt(zgsz343, zgsz344);
    KILL(sail_int)(&zgsz344);
    KILL(sail_int)(&zgsz343);
  }


end_function_82: ;
  return zcbz326;
end_block_exception_83: ;

  return false;
}

static bool sailgen_z8operatorz0zzzz7nzzJzzK3z3zI_uz9(uint64_t zx, uint64_t zy)
{
  __label__ end_function_85, end_block_exception_86;

  bool zcbz327;
  int64_t zgaz38;
  zgaz38 = ((mach_int) zx);
  int64_t zgaz39;
  zgaz39 = ((mach_int) zy);
  {
    sail_int zgsz346;
    CREATE(sail_int)(&zgsz346);
    CONVERT_OF(sail_int, mach_int)(&zgsz346, zgaz39);
    sail_int zgsz345;
    CREATE(sail_int)(&zgsz345);
    CONVERT_OF(sail_int, mach_int)(&zgsz345, zgaz38);
    zcbz327 = lt(zgsz345, zgsz346);
    KILL(sail_int)(&zgsz346);
    KILL(sail_int)(&zgsz345);
  }


end_function_85: ;
  return zcbz327;
end_block_exception_86: ;

  return false;
}

static bool sailgen_z8operatorz0zzzz7nzzJzzK8z3zI_uz9(uint64_t zx, uint64_t zy)
{
  __label__ end_function_88, end_block_exception_89;

  bool zcbz328;
  int64_t zgaz310;
  zgaz310 = ((mach_int) zx);
  int64_t zgaz311;
  zgaz311 = ((mach_int) zy);
  {
    sail_int zgsz348;
    CREATE(sail_int)(&zgsz348);
    CONVERT_OF(sail_int, mach_int)(&zgsz348, zgaz311);
    sail_int zgsz347;
    CREATE(sail_int)(&zgsz347);
    CONVERT_OF(sail_int, mach_int)(&zgsz347, zgaz310);
    zcbz328 = lt(zgsz347, zgsz348);
    KILL(sail_int)(&zgsz348);
    KILL(sail_int)(&zgsz347);
  }


end_function_88: ;
  return zcbz328;
end_block_exception_89: ;

  return false;
}

static bool sailgen_z8operatorz0zzzz7nzzJzzK8z3zKzJ_uz9(uint64_t zx, uint64_t zy)
{
  __label__ end_function_91, end_block_exception_92;

  bool zcbz329;
  int64_t zgaz312;
  zgaz312 = ((mach_int) zx);
  int64_t zgaz313;
  zgaz313 = ((mach_int) zy);
  {
    sail_int zgsz350;
    CREATE(sail_int)(&zgsz350);
    CONVERT_OF(sail_int, mach_int)(&zgsz350, zgaz313);
    sail_int zgsz349;
    CREATE(sail_int)(&zgsz349);
    CONVERT_OF(sail_int, mach_int)(&zgsz349, zgaz312);
    zcbz329 = gteq(zgsz349, zgsz350);
    KILL(sail_int)(&zgsz350);
    KILL(sail_int)(&zgsz349);
  }


end_function_91: ;
  return zcbz329;
end_block_exception_92: ;

  return false;
}



static void sailgen_n_leading_spaces(sail_int *rop, sail_string);

static void sailgen_n_leading_spaces(sail_int *zcbz330, sail_string zs)
{
  __label__ case_95, case_96, finish_match_94, end_function_100, end_block_exception_101, end_function_220;

  sail_int zgsz351;
  CREATE(sail_int)(&zgsz351);
  {
    sail_string zp0z3;
    CREATE(sail_string)(&zp0z3);
    COPY(sail_string)(&zp0z3, zs);
    bool zgsz352;
    zgsz352 = eq_string(zp0z3, "");
    if (!(zgsz352)) {
    KILL(sail_string)(&zp0z3);
    goto case_95;
    }
    CONVERT_OF(sail_int, mach_int)(&zgsz351, 0l);
    KILL(sail_string)(&zp0z3);
    goto finish_match_94;
  }
case_95: ;
  {
    __label__ case_98, case_99, finish_match_97;

    sail_string zgaz314;
    CREATE(sail_string)(&zgaz314);
    {
      sail_int zgsz353;
      CREATE(sail_int)(&zgsz353);
      CONVERT_OF(sail_int, mach_int)(&zgsz353, 1l);
      string_take(&zgaz314, zs, zgsz353);
      KILL(sail_int)(&zgsz353);
    }
    sail_int zgsz354;
    CREATE(sail_int)(&zgsz354);
    {
      sail_string zp0z3;
      CREATE(sail_string)(&zp0z3);
      COPY(sail_string)(&zp0z3, zgaz314);
      bool zgsz356;
      zgsz356 = eq_string(zp0z3, " ");
      if (!(zgsz356)) {
      KILL(sail_string)(&zp0z3);
      goto case_98;
      }
      sail_int zgaz316;
      CREATE(sail_int)(&zgaz316);
      {
        sail_string zgaz315;
        CREATE(sail_string)(&zgaz315);
        {
          sail_int zgsz355;
          CREATE(sail_int)(&zgsz355);
          CONVERT_OF(sail_int, mach_int)(&zgsz355, 1l);
          string_drop(&zgaz315, zs, zgsz355);
          KILL(sail_int)(&zgsz355);
        }
        sailgen_n_leading_spaces(&zgaz316, zgaz315);
        KILL(sail_string)(&zgaz315);
      }
      {
        sail_int zgsz357;
        CREATE(sail_int)(&zgsz357);
        CONVERT_OF(sail_int, mach_int)(&zgsz357, 1l);
        add_int(&zgsz354, zgsz357, zgaz316);
        KILL(sail_int)(&zgsz357);
      }
      KILL(sail_int)(&zgaz316);
      KILL(sail_string)(&zp0z3);
      goto finish_match_97;
    }
  case_98: ;
    {
      CONVERT_OF(sail_int, mach_int)(&zgsz354, 0l);
      goto finish_match_97;
    }
  case_99: ;
    sail_match_failure("n_leading_spaces");
  finish_match_97: ;
    COPY(sail_int)(&zgsz351, zgsz354);
    KILL(sail_int)(&zgsz354);
    KILL(sail_string)(&zgaz314);
    goto finish_match_94;
  }
case_96: ;
  sail_match_failure("n_leading_spaces");
finish_match_94: ;
  COPY(sail_int)((*(&zcbz330)), zgsz351);
  KILL(sail_int)(&zgsz351);
end_function_100: ;
  goto end_function_220;
end_block_exception_101: ;
  goto end_function_220;
end_function_220: ;
}

static int64_t sailgen_zzzz7nzzJzzK32z3MAX(int64_t);

static int64_t sailgen_zzzz7nzzJzzK4z3MAX(int64_t);

static int64_t sailgen_zzzz7nzzJzzK32z3MAX(int64_t zn)
{
  __label__ end_function_103, end_block_exception_104;

  int64_t zcbz331;
  int64_t zgaz317;
  {
    sail_int zgsz360;
    CREATE(sail_int)(&zgsz360);
    CONVERT_OF(sail_int, mach_int)(&zgsz360, zn);
    sail_int zgsz361;
    CREATE(sail_int)(&zgsz361);
    pow2(&zgsz361, zgsz360);
    zgaz317 = CONVERT_OF(mach_int, sail_int)(zgsz361);
    KILL(sail_int)(&zgsz361);
    KILL(sail_int)(&zgsz360);
  }
  {
    sail_int zgsz362;
    CREATE(sail_int)(&zgsz362);
    CONVERT_OF(sail_int, mach_int)(&zgsz362, zgaz317);
    sail_int zgsz363;
    CREATE(sail_int)(&zgsz363);
    CONVERT_OF(sail_int, mach_int)(&zgsz363, 1l);
    sail_int zgsz364;
    CREATE(sail_int)(&zgsz364);
    sub_int(&zgsz364, zgsz362, zgsz363);
    zcbz331 = CONVERT_OF(mach_int, sail_int)(zgsz364);
    KILL(sail_int)(&zgsz364);
    KILL(sail_int)(&zgsz363);
    KILL(sail_int)(&zgsz362);
  }

end_function_103: ;
  return zcbz331;
end_block_exception_104: ;

  return INT64_C(0xdeadc0de);
}

static int64_t sailgen_zzzz7nzzJzzK4z3MAX(int64_t zn)
{
  __label__ end_function_106, end_block_exception_107;

  int64_t zcbz332;
  int64_t zgaz318;
  {
    sail_int zgsz365;
    CREATE(sail_int)(&zgsz365);
    CONVERT_OF(sail_int, mach_int)(&zgsz365, zn);
    sail_int zgsz366;
    CREATE(sail_int)(&zgsz366);
    pow2(&zgsz366, zgsz365);
    zgaz318 = CONVERT_OF(mach_int, sail_int)(zgsz366);
    KILL(sail_int)(&zgsz366);
    KILL(sail_int)(&zgsz365);
  }
  {
    sail_int zgsz367;
    CREATE(sail_int)(&zgsz367);
    CONVERT_OF(sail_int, mach_int)(&zgsz367, zgaz318);
    sail_int zgsz368;
    CREATE(sail_int)(&zgsz368);
    CONVERT_OF(sail_int, mach_int)(&zgsz368, 1l);
    sail_int zgsz369;
    CREATE(sail_int)(&zgsz369);
    sub_int(&zgsz369, zgsz367, zgsz368);
    zcbz332 = CONVERT_OF(mach_int, sail_int)(zgsz369);
    KILL(sail_int)(&zgsz369);
    KILL(sail_int)(&zgsz368);
    KILL(sail_int)(&zgsz367);
  }

end_function_106: ;
  return zcbz332;
end_block_exception_107: ;

  return INT64_C(0xdeadc0de);
}



int64_t znum_flags;
static void create_letbind_0(void) {  


  int64_t zgsz370;
  zgsz370 = 1l;
  znum_flags = zgsz370;

let_end_108: ;
}
static void kill_letbind_0(void) {  
}

int64_t zreserved_otypes;
static void create_letbind_1(void) {  


  int64_t zgsz371;
  zgsz371 = 4l;
  zreserved_otypes = zgsz371;

let_end_109: ;
}
static void kill_letbind_1(void) {  
}

int64_t zotype_unsealed;
static void create_letbind_2(void) {  


  int64_t zgsz372;
  zgsz372 = -1l;
  zotype_unsealed = zgsz372;

let_end_110: ;
}
static void kill_letbind_2(void) {  
}

uint64_t zPCC_IDX;
static void create_letbind_3(void) {  


  uint64_t zgsz373;
  zgsz373 = UINT64_C(0b100000);
  zPCC_IDX = zgsz373;

let_end_111: ;
}
static void kill_letbind_3(void) {  
}

uint64_t zDDC_IDX;
static void create_letbind_4(void) {  


  uint64_t zgsz374;
  zgsz374 = UINT64_C(0b100001);
  zDDC_IDX = zgsz374;

let_end_112: ;
}
static void kill_letbind_4(void) {  
}

int64_t zcap_sizze;
static void create_letbind_5(void) {  


  int64_t zgsz375;
  zgsz375 = 8l;
  zcap_sizze = zgsz375;

let_end_113: ;
}
static void kill_letbind_5(void) {  
}

int64_t zlog2_cap_sizze;
static void create_letbind_6(void) {  


  int64_t zgsz376;
  zgsz376 = 3l;
  zlog2_cap_sizze = zgsz376;

let_end_114: ;
}
static void kill_letbind_6(void) {  
}

int64_t zotype_width;
static void create_letbind_7(void) {  


  int64_t zgsz377;
  zgsz377 = 4l;
  zotype_width = zgsz377;

let_end_115: ;
}
static void kill_letbind_7(void) {  
}

int64_t zuperms_width;
static void create_letbind_8(void) {  


  int64_t zgsz378;
  zgsz378 = 0l;
  zuperms_width = zgsz378;

let_end_116: ;
}
static void kill_letbind_8(void) {  
}

int64_t zcap_addr_width;
static void create_letbind_9(void) {  


  int64_t zgsz379;
  zgsz379 = 32l;
  zcap_addr_width = zgsz379;

let_end_117: ;
}
static void kill_letbind_9(void) {  
}

int64_t zcap_len_width;
static void create_letbind_10(void) {  


  int64_t zgsz380;
  {
    sail_int zgsz381;
    CREATE(sail_int)(&zgsz381);
    CONVERT_OF(sail_int, mach_int)(&zgsz381, 32l);
    sail_int zgsz382;
    CREATE(sail_int)(&zgsz382);
    CONVERT_OF(sail_int, mach_int)(&zgsz382, 1l);
    sail_int zgsz383;
    CREATE(sail_int)(&zgsz383);
    add_int(&zgsz383, zgsz381, zgsz382);
    zgsz380 = CONVERT_OF(mach_int, sail_int)(zgsz383);
    KILL(sail_int)(&zgsz383);
    KILL(sail_int)(&zgsz382);
    KILL(sail_int)(&zgsz381);
  }
  zcap_len_width = zgsz380;

let_end_118: ;
}
static void kill_letbind_10(void) {  
}

int64_t zmantissa_width;
static void create_letbind_11(void) {  


  int64_t zgsz384;
  zgsz384 = 8l;
  zmantissa_width = zgsz384;

let_end_119: ;
}
static void kill_letbind_11(void) {  
}

int64_t zMAX_ADDR;
static void create_letbind_12(void) {  


  int64_t zgsz385;
  zgsz385 = sailgen_zzzz7nzzJzzK32z3MAX(zcap_addr_width);
  zMAX_ADDR = zgsz385;

let_end_120: ;
}
static void kill_letbind_12(void) {  
}

static struct zCapability sailgen_undefined_Capability(unit);

static struct zCapability sailgen_undefined_Capability(unit zgsz386)
{
  __label__ end_function_122, end_block_exception_123;

  struct zCapability zcbz333;
  bool zgaz319;
  zgaz319 = undefined_bool(UNIT);
  uint64_t zgaz320;
  {
    sail_int zgsz387;
    CREATE(sail_int)(&zgsz387);
    CONVERT_OF(sail_int, mach_int)(&zgsz387, 0l);
    lbits zgsz388;
    CREATE(lbits)(&zgsz388);
    UNDEFINED(lbits)(&zgsz388, zgsz387);
    zgaz320 = CONVERT_OF(fbits, lbits)(zgsz388, true);
    KILL(lbits)(&zgsz388);
    KILL(sail_int)(&zgsz387);
  }
  bool zgaz321;
  zgaz321 = undefined_bool(UNIT);
  bool zgaz322;
  zgaz322 = undefined_bool(UNIT);
  bool zgaz323;
  zgaz323 = undefined_bool(UNIT);
  bool zgaz324;
  zgaz324 = undefined_bool(UNIT);
  bool zgaz325;
  zgaz325 = undefined_bool(UNIT);
  bool zgaz326;
  zgaz326 = undefined_bool(UNIT);
  bool zgaz327;
  zgaz327 = undefined_bool(UNIT);
  bool zgaz328;
  zgaz328 = undefined_bool(UNIT);
  bool zgaz329;
  zgaz329 = undefined_bool(UNIT);
  bool zgaz330;
  zgaz330 = undefined_bool(UNIT);
  bool zgaz331;
  zgaz331 = undefined_bool(UNIT);
  bool zgaz332;
  zgaz332 = undefined_bool(UNIT);
  uint64_t zgaz333;
  {
    sail_int zgsz389;
    CREATE(sail_int)(&zgsz389);
    CONVERT_OF(sail_int, mach_int)(&zgsz389, 0l);
    lbits zgsz390;
    CREATE(lbits)(&zgsz390);
    UNDEFINED(lbits)(&zgsz390, zgsz389);
    zgaz333 = CONVERT_OF(fbits, lbits)(zgsz390, true);
    KILL(lbits)(&zgsz390);
    KILL(sail_int)(&zgsz389);
  }
  bool zgaz334;
  zgaz334 = undefined_bool(UNIT);
  bool zgaz335;
  zgaz335 = undefined_bool(UNIT);
  uint64_t zgaz336;
  {
    sail_int zgsz391;
    CREATE(sail_int)(&zgsz391);
    CONVERT_OF(sail_int, mach_int)(&zgsz391, 6l);
    lbits zgsz392;
    CREATE(lbits)(&zgsz392);
    UNDEFINED(lbits)(&zgsz392, zgsz391);
    zgaz336 = CONVERT_OF(fbits, lbits)(zgsz392, true);
    KILL(lbits)(&zgsz392);
    KILL(sail_int)(&zgsz391);
  }
  bool zgaz337;
  zgaz337 = undefined_bool(UNIT);
  uint64_t zgaz338;
  {
    sail_int zgsz393;
    CREATE(sail_int)(&zgsz393);
    CONVERT_OF(sail_int, mach_int)(&zgsz393, 8l);
    lbits zgsz394;
    CREATE(lbits)(&zgsz394);
    UNDEFINED(lbits)(&zgsz394, zgsz393);
    zgaz338 = CONVERT_OF(fbits, lbits)(zgsz394, true);
    KILL(lbits)(&zgsz394);
    KILL(sail_int)(&zgsz393);
  }
  uint64_t zgaz339;
  {
    sail_int zgsz395;
    CREATE(sail_int)(&zgsz395);
    CONVERT_OF(sail_int, mach_int)(&zgsz395, 8l);
    lbits zgsz396;
    CREATE(lbits)(&zgsz396);
    UNDEFINED(lbits)(&zgsz396, zgsz395);
    zgaz339 = CONVERT_OF(fbits, lbits)(zgsz396, true);
    KILL(lbits)(&zgsz396);
    KILL(sail_int)(&zgsz395);
  }
  uint64_t zgaz340;
  {
    sail_int zgsz397;
    CREATE(sail_int)(&zgsz397);
    CONVERT_OF(sail_int, mach_int)(&zgsz397, 4l);
    lbits zgsz398;
    CREATE(lbits)(&zgsz398);
    UNDEFINED(lbits)(&zgsz398, zgsz397);
    zgaz340 = CONVERT_OF(fbits, lbits)(zgsz398, true);
    KILL(lbits)(&zgsz398);
    KILL(sail_int)(&zgsz397);
  }
  uint64_t zgaz341;
  {
    sail_int zgsz399;
    CREATE(sail_int)(&zgsz399);
    CONVERT_OF(sail_int, mach_int)(&zgsz399, 32l);
    lbits zgsz3100;
    CREATE(lbits)(&zgsz3100);
    UNDEFINED(lbits)(&zgsz3100, zgsz399);
    zgaz341 = CONVERT_OF(fbits, lbits)(zgsz3100, true);
    KILL(lbits)(&zgsz3100);
    KILL(sail_int)(&zgsz399);
  }
  struct zCapability zgsz3101;
  zgsz3101.zB = zgaz338;
  zgsz3101.zE = zgaz336;
  zgsz3101.zT = zgaz339;
  zgsz3101.zaccess_system_regs = zgaz322;
  zgsz3101.zaddress = zgaz341;
  zgsz3101.zflag_cap_mode = zgaz334;
  zgsz3101.zglobal = zgaz332;
  zgsz3101.zinternal_e = zgaz335;
  zgsz3101.zotype = zgaz340;
  zgsz3101.zpermit_ccall = zgaz324;
  zgsz3101.zpermit_execute = zgaz331;
  zgsz3101.zpermit_load = zgaz330;
  zgsz3101.zpermit_load_cap = zgaz328;
  zgsz3101.zpermit_seal = zgaz325;
  zgsz3101.zpermit_set_CID = zgaz321;
  zgsz3101.zpermit_store = zgaz329;
  zgsz3101.zpermit_store_cap = zgaz327;
  zgsz3101.zpermit_store_local_cap = zgaz326;
  zgsz3101.zpermit_unseal = zgaz323;
  zgsz3101.zreserved = zgaz333;
  zgsz3101.zsealed = zgaz337;
  zgsz3101.ztag = zgaz319;
  zgsz3101.zuperms = zgaz320;
  zcbz333 = zgsz3101;
























end_function_122: ;
  return zcbz333;
end_block_exception_123: ;
  struct zCapability zcbz353 = { .zuperms = UINT64_C(0xdeadc0de), .ztag = false, .zsealed = false, .zreserved = UINT64_C(0xdeadc0de), .zpermit_unseal = false, .zpermit_store_local_cap = false, .zpermit_store_cap = false, .zpermit_store = false, .zpermit_set_CID = false, .zpermit_seal = false, .zpermit_load_cap = false, .zpermit_load = false, .zpermit_execute = false, .zpermit_ccall = false, .zotype = UINT64_C(0xdeadc0de), .zinternal_e = false, .zglobal = false, .zflag_cap_mode = false, .zaddress = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zT = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zB = UINT64_C(0xdeadc0de) };
  return zcbz353;
}

int64_t zmaxE;
static void create_letbind_13(void) {  


  int64_t zgsz3102;
  zgsz3102 = 26l;
  zmaxE = zgsz3102;

let_end_124: ;
}
static void kill_letbind_13(void) {  
}

int64_t zinternal_exponent_take_bits;
static void create_letbind_14(void) {  


  int64_t zgsz3103;
  zgsz3103 = 3l;
  zinternal_exponent_take_bits = zgsz3103;

let_end_125: ;
}
static void kill_letbind_14(void) {  
}

uint64_t zresetE;
static void create_letbind_15(void) {  


  uint64_t zgsz3104;
  {
    sail_int zgsz3105;
    CREATE(sail_int)(&zgsz3105);
    CONVERT_OF(sail_int, mach_int)(&zgsz3105, 6l);
    sail_int zgsz3106;
    CREATE(sail_int)(&zgsz3106);
    CONVERT_OF(sail_int, mach_int)(&zgsz3106, zmaxE);
    lbits zgsz3107;
    CREATE(lbits)(&zgsz3107);
    sailgen_to_bits(&zgsz3107, zgsz3105, zgsz3106);
    zgsz3104 = CONVERT_OF(fbits, lbits)(zgsz3107, true);
    KILL(lbits)(&zgsz3107);
    KILL(sail_int)(&zgsz3106);
    KILL(sail_int)(&zgsz3105);
  }
  zresetE = zgsz3104;

let_end_126: ;
}
static void kill_letbind_15(void) {  
}

uint64_t zresetT;
static void create_letbind_16(void) {  


  uint64_t zgsz3108;
  zgsz3108 = UINT64_C(0x40);
  zresetT = zgsz3108;

let_end_127: ;
}
static void kill_letbind_16(void) {  
}

struct zCapability znull_cap;
static void create_letbind_17(void) {  


  struct zCapability zgsz3113;
  uint64_t zgaz342;
  zgaz342 = sailgen_zzzz7nzzJzzK0z3zzeros_implicit(0l);
  uint64_t zgaz343;
  zgaz343 = sailgen_zzzz7nzzJzzK0z3zzeros_implicit(0l);
  uint64_t zgaz344;
  zgaz344 = sailgen_zzzz7nzzJzzK8z3zzeros_implicit(8l);
  uint64_t zgaz345;
  {
    sail_int zgsz3109;
    CREATE(sail_int)(&zgsz3109);
    CONVERT_OF(sail_int, mach_int)(&zgsz3109, zotype_width);
    sail_int zgsz3110;
    CREATE(sail_int)(&zgsz3110);
    CONVERT_OF(sail_int, mach_int)(&zgsz3110, zotype_unsealed);
    lbits zgsz3111;
    CREATE(lbits)(&zgsz3111);
    sailgen_to_bits(&zgsz3111, zgsz3109, zgsz3110);
    zgaz345 = CONVERT_OF(fbits, lbits)(zgsz3111, true);
    KILL(lbits)(&zgsz3111);
    KILL(sail_int)(&zgsz3110);
    KILL(sail_int)(&zgsz3109);
  }
  uint64_t zgaz346;
  zgaz346 = sailgen_zzzz7nzzJzzK32z3zzeros_implicit(32l);
  struct zCapability zgsz3112;
  zgsz3112.zB = zgaz344;
  zgsz3112.zE = zresetE;
  zgsz3112.zT = zresetT;
  zgsz3112.zaccess_system_regs = false;
  zgsz3112.zaddress = zgaz346;
  zgsz3112.zflag_cap_mode = false;
  zgsz3112.zglobal = false;
  zgsz3112.zinternal_e = true;
  zgsz3112.zotype = zgaz345;
  zgsz3112.zpermit_ccall = false;
  zgsz3112.zpermit_execute = false;
  zgsz3112.zpermit_load = false;
  zgsz3112.zpermit_load_cap = false;
  zgsz3112.zpermit_seal = false;
  zgsz3112.zpermit_set_CID = false;
  zgsz3112.zpermit_store = false;
  zgsz3112.zpermit_store_cap = false;
  zgsz3112.zpermit_store_local_cap = false;
  zgsz3112.zpermit_unseal = false;
  zgsz3112.zreserved = zgaz343;
  zgsz3112.zsealed = false;
  zgsz3112.ztag = false;
  zgsz3112.zuperms = zgaz342;
  zgsz3113 = zgsz3112;






  znull_cap = zgsz3113;

let_end_128: ;
}
static void kill_letbind_17(void) {  
}

struct zCapability zdefault_cap;
static void create_letbind_18(void) {  


  struct zCapability zgsz3118;
  uint64_t zgaz347;
  zgaz347 = sailgen_zzzz7nzzJzzK0z3ones(0l);
  uint64_t zgaz348;
  zgaz348 = sailgen_zzzz7nzzJzzK0z3zzeros_implicit(0l);
  uint64_t zgaz349;
  zgaz349 = sailgen_zzzz7nzzJzzK8z3zzeros_implicit(8l);
  uint64_t zgaz350;
  {
    sail_int zgsz3114;
    CREATE(sail_int)(&zgsz3114);
    CONVERT_OF(sail_int, mach_int)(&zgsz3114, zotype_width);
    sail_int zgsz3115;
    CREATE(sail_int)(&zgsz3115);
    CONVERT_OF(sail_int, mach_int)(&zgsz3115, zotype_unsealed);
    lbits zgsz3116;
    CREATE(lbits)(&zgsz3116);
    sailgen_to_bits(&zgsz3116, zgsz3114, zgsz3115);
    zgaz350 = CONVERT_OF(fbits, lbits)(zgsz3116, true);
    KILL(lbits)(&zgsz3116);
    KILL(sail_int)(&zgsz3115);
    KILL(sail_int)(&zgsz3114);
  }
  uint64_t zgaz351;
  zgaz351 = sailgen_zzzz7nzzJzzK32z3zzeros_implicit(32l);
  struct zCapability zgsz3117;
  zgsz3117.zB = zgaz349;
  zgsz3117.zE = zresetE;
  zgsz3117.zT = zresetT;
  zgsz3117.zaccess_system_regs = true;
  zgsz3117.zaddress = zgaz351;
  zgsz3117.zflag_cap_mode = false;
  zgsz3117.zglobal = true;
  zgsz3117.zinternal_e = true;
  zgsz3117.zotype = zgaz350;
  zgsz3117.zpermit_ccall = true;
  zgsz3117.zpermit_execute = true;
  zgsz3117.zpermit_load = true;
  zgsz3117.zpermit_load_cap = true;
  zgsz3117.zpermit_seal = true;
  zgsz3117.zpermit_set_CID = true;
  zgsz3117.zpermit_store = true;
  zgsz3117.zpermit_store_cap = true;
  zgsz3117.zpermit_store_local_cap = true;
  zgsz3117.zpermit_unseal = true;
  zgsz3117.zreserved = zgaz348;
  zgsz3117.zsealed = false;
  zgsz3117.ztag = true;
  zgsz3117.zuperms = zgaz347;
  zgsz3118 = zgsz3117;






  zdefault_cap = zgsz3118;

let_end_129: ;
}
static void kill_letbind_18(void) {  
}

static struct zCapability sailgen_capBitsToCapability(bool, uint64_t);

static struct zCapability sailgen_capBitsToCapability(bool zt, uint64_t zc)
{
  __label__ case_132, finish_match_131, end_function_133, end_block_exception_136;

  struct zCapability zcbz334;
  bool zinternal_exponent;
  {
    fbits zgaz391;
    {
      sail_int zgsz3120;
      CREATE(sail_int)(&zgsz3120);
      CONVERT_OF(sail_int, mach_int)(&zgsz3120, 46l);
      lbits zgsz3119;
      CREATE(lbits)(&zgsz3119);
      CONVERT_OF(lbits, fbits)(&zgsz3119, zc, UINT64_C(64) , true);
      zgaz391 = bitvector_access(zgsz3119, zgsz3120);
      KILL(sail_int)(&zgsz3120);
      KILL(lbits)(&zgsz3119);
    }
    zinternal_exponent = sailgen_bit_to_bool(zgaz391);
  
  }
  uint64_t zotype;
  {
    lbits zgsz3121;
    CREATE(lbits)(&zgsz3121);
    CONVERT_OF(lbits, fbits)(&zgsz3121, zc, UINT64_C(64) , true);
    sail_int zgsz3122;
    CREATE(sail_int)(&zgsz3122);
    CONVERT_OF(sail_int, mach_int)(&zgsz3122, 50l);
    sail_int zgsz3123;
    CREATE(sail_int)(&zgsz3123);
    CONVERT_OF(sail_int, mach_int)(&zgsz3123, 47l);
    lbits zgsz3124;
    CREATE(lbits)(&zgsz3124);
    vector_subrange_lbits(&zgsz3124, zgsz3121, zgsz3122, zgsz3123);
    zotype = CONVERT_OF(fbits, lbits)(zgsz3124, true);
    KILL(lbits)(&zgsz3124);
    KILL(sail_int)(&zgsz3123);
    KILL(sail_int)(&zgsz3122);
    KILL(lbits)(&zgsz3121);
  }
  bool zgaz353;
  {
    uint64_t zgaz352;
    {
      sail_int zgsz3125;
      CREATE(sail_int)(&zgsz3125);
      CONVERT_OF(sail_int, mach_int)(&zgsz3125, zotype_width);
      sail_int zgsz3126;
      CREATE(sail_int)(&zgsz3126);
      CONVERT_OF(sail_int, mach_int)(&zgsz3126, zotype_unsealed);
      lbits zgsz3127;
      CREATE(lbits)(&zgsz3127);
      sailgen_to_bits(&zgsz3127, zgsz3125, zgsz3126);
      zgaz352 = CONVERT_OF(fbits, lbits)(zgsz3127, true);
      KILL(lbits)(&zgsz3127);
      KILL(sail_int)(&zgsz3126);
      KILL(sail_int)(&zgsz3125);
    }
    {
      lbits zgsz3129;
      CREATE(lbits)(&zgsz3129);
      CONVERT_OF(lbits, fbits)(&zgsz3129, zgaz352, UINT64_C(4) , true);
      lbits zgsz3128;
      CREATE(lbits)(&zgsz3128);
      CONVERT_OF(lbits, fbits)(&zgsz3128, zotype, UINT64_C(4) , true);
      zgaz353 = neq_bits(zgsz3128, zgsz3129);
      KILL(lbits)(&zgsz3129);
      KILL(lbits)(&zgsz3128);
    }
  
  }
  struct zCapability zgsz3130;
  {
    __label__ cleanup_134, end_cleanup_135;

    bool zsealed;
    zsealed = zgaz353;
    uint64_t zE;
    zE = sailgen_zzzz7nzzJzzK6z3zzeros_implicit(6l);
    uint64_t zBs;
    zBs = sailgen_zzzz7nzzJzzK8z3zzeros_implicit(8l);
    uint64_t zT;
    zT = sailgen_zzzz7nzzJzzK6z3zzeros_implicit(6l);
    uint64_t zlenMSBs;
    zlenMSBs = sailgen_zzzz7nzzJzzK2z3zzeros_implicit(2l);
    {
      unit zgsz3131;
      if (zinternal_exponent) {
      {
        uint64_t zgaz354;
        {
          lbits zgsz3142;
          CREATE(lbits)(&zgsz3142);
          CONVERT_OF(lbits, fbits)(&zgsz3142, zc, UINT64_C(64) , true);
          sail_int zgsz3143;
          CREATE(sail_int)(&zgsz3143);
          CONVERT_OF(sail_int, mach_int)(&zgsz3143, 42l);
          sail_int zgsz3144;
          CREATE(sail_int)(&zgsz3144);
          CONVERT_OF(sail_int, mach_int)(&zgsz3144, 40l);
          lbits zgsz3145;
          CREATE(lbits)(&zgsz3145);
          vector_subrange_lbits(&zgsz3145, zgsz3142, zgsz3143, zgsz3144);
          zgaz354 = CONVERT_OF(fbits, lbits)(zgsz3145, true);
          KILL(lbits)(&zgsz3145);
          KILL(sail_int)(&zgsz3144);
          KILL(sail_int)(&zgsz3143);
          KILL(lbits)(&zgsz3142);
        }
        uint64_t zgaz355;
        {
          lbits zgsz3146;
          CREATE(lbits)(&zgsz3146);
          CONVERT_OF(lbits, fbits)(&zgsz3146, zc, UINT64_C(64) , true);
          sail_int zgsz3147;
          CREATE(sail_int)(&zgsz3147);
          CONVERT_OF(sail_int, mach_int)(&zgsz3147, 34l);
          sail_int zgsz3148;
          CREATE(sail_int)(&zgsz3148);
          CONVERT_OF(sail_int, mach_int)(&zgsz3148, 32l);
          lbits zgsz3149;
          CREATE(lbits)(&zgsz3149);
          vector_subrange_lbits(&zgsz3149, zgsz3146, zgsz3147, zgsz3148);
          zgaz355 = CONVERT_OF(fbits, lbits)(zgsz3149, true);
          KILL(lbits)(&zgsz3149);
          KILL(sail_int)(&zgsz3148);
          KILL(sail_int)(&zgsz3147);
          KILL(lbits)(&zgsz3146);
        }
        {
          lbits zgsz3150;
          CREATE(lbits)(&zgsz3150);
          CONVERT_OF(lbits, fbits)(&zgsz3150, zgaz354, UINT64_C(3) , true);
          lbits zgsz3151;
          CREATE(lbits)(&zgsz3151);
          CONVERT_OF(lbits, fbits)(&zgsz3151, zgaz355, UINT64_C(3) , true);
          lbits zgsz3152;
          CREATE(lbits)(&zgsz3152);
          append(&zgsz3152, zgsz3150, zgsz3151);
          zE = CONVERT_OF(fbits, lbits)(zgsz3152, true);
          KILL(lbits)(&zgsz3152);
          KILL(lbits)(&zgsz3151);
          KILL(lbits)(&zgsz3150);
        }
        unit zgsz3162;
        zgsz3162 = UNIT;
      
      
      }
      {
        zlenMSBs = UINT64_C(0b01);
        unit zgsz3161;
        zgsz3161 = UNIT;
      }
      {
        uint64_t zgaz356;
        {
          lbits zgsz3153;
          CREATE(lbits)(&zgsz3153);
          CONVERT_OF(lbits, fbits)(&zgsz3153, zc, UINT64_C(64) , true);
          sail_int zgsz3154;
          CREATE(sail_int)(&zgsz3154);
          CONVERT_OF(sail_int, mach_int)(&zgsz3154, 45l);
          sail_int zgsz3155;
          CREATE(sail_int)(&zgsz3155);
          CONVERT_OF(sail_int, mach_int)(&zgsz3155, 43l);
          lbits zgsz3156;
          CREATE(lbits)(&zgsz3156);
          vector_subrange_lbits(&zgsz3156, zgsz3153, zgsz3154, zgsz3155);
          zgaz356 = CONVERT_OF(fbits, lbits)(zgsz3156, true);
          KILL(lbits)(&zgsz3156);
          KILL(sail_int)(&zgsz3155);
          KILL(sail_int)(&zgsz3154);
          KILL(lbits)(&zgsz3153);
        }
        {
          lbits zgsz3157;
          CREATE(lbits)(&zgsz3157);
          CONVERT_OF(lbits, fbits)(&zgsz3157, zgaz356, UINT64_C(3) , true);
          lbits zgsz3158;
          CREATE(lbits)(&zgsz3158);
          CONVERT_OF(lbits, fbits)(&zgsz3158, UINT64_C(0b000), UINT64_C(3) , true);
          lbits zgsz3159;
          CREATE(lbits)(&zgsz3159);
          append(&zgsz3159, zgsz3157, zgsz3158);
          zT = CONVERT_OF(fbits, lbits)(zgsz3159, true);
          KILL(lbits)(&zgsz3159);
          KILL(lbits)(&zgsz3158);
          KILL(lbits)(&zgsz3157);
        }
        unit zgsz3160;
        zgsz3160 = UNIT;
      
      }
      uint64_t zgaz357;
      {
        lbits zgsz3163;
        CREATE(lbits)(&zgsz3163);
        CONVERT_OF(lbits, fbits)(&zgsz3163, zc, UINT64_C(64) , true);
        sail_int zgsz3164;
        CREATE(sail_int)(&zgsz3164);
        CONVERT_OF(sail_int, mach_int)(&zgsz3164, 39l);
        sail_int zgsz3165;
        CREATE(sail_int)(&zgsz3165);
        CONVERT_OF(sail_int, mach_int)(&zgsz3165, 35l);
        lbits zgsz3166;
        CREATE(lbits)(&zgsz3166);
        vector_subrange_lbits(&zgsz3166, zgsz3163, zgsz3164, zgsz3165);
        zgaz357 = CONVERT_OF(fbits, lbits)(zgsz3166, true);
        KILL(lbits)(&zgsz3166);
        KILL(sail_int)(&zgsz3165);
        KILL(sail_int)(&zgsz3164);
        KILL(lbits)(&zgsz3163);
      }
      {
        lbits zgsz3167;
        CREATE(lbits)(&zgsz3167);
        CONVERT_OF(lbits, fbits)(&zgsz3167, zgaz357, UINT64_C(5) , true);
        lbits zgsz3168;
        CREATE(lbits)(&zgsz3168);
        CONVERT_OF(lbits, fbits)(&zgsz3168, UINT64_C(0b000), UINT64_C(3) , true);
        lbits zgsz3169;
        CREATE(lbits)(&zgsz3169);
        append(&zgsz3169, zgsz3167, zgsz3168);
        zBs = CONVERT_OF(fbits, lbits)(zgsz3169, true);
        KILL(lbits)(&zgsz3169);
        KILL(lbits)(&zgsz3168);
        KILL(lbits)(&zgsz3167);
      }
      zgsz3131 = UNIT;
    
      } else {
      {
        zlenMSBs = UINT64_C(0b00);
        unit zgsz3137;
        zgsz3137 = UNIT;
      }
      {
        {
          lbits zgsz3132;
          CREATE(lbits)(&zgsz3132);
          CONVERT_OF(lbits, fbits)(&zgsz3132, zc, UINT64_C(64) , true);
          sail_int zgsz3133;
          CREATE(sail_int)(&zgsz3133);
          CONVERT_OF(sail_int, mach_int)(&zgsz3133, 45l);
          sail_int zgsz3134;
          CREATE(sail_int)(&zgsz3134);
          CONVERT_OF(sail_int, mach_int)(&zgsz3134, 40l);
          lbits zgsz3135;
          CREATE(lbits)(&zgsz3135);
          vector_subrange_lbits(&zgsz3135, zgsz3132, zgsz3133, zgsz3134);
          zT = CONVERT_OF(fbits, lbits)(zgsz3135, true);
          KILL(lbits)(&zgsz3135);
          KILL(sail_int)(&zgsz3134);
          KILL(sail_int)(&zgsz3133);
          KILL(lbits)(&zgsz3132);
        }
        unit zgsz3136;
        zgsz3136 = UNIT;
      }
      {
        lbits zgsz3138;
        CREATE(lbits)(&zgsz3138);
        CONVERT_OF(lbits, fbits)(&zgsz3138, zc, UINT64_C(64) , true);
        sail_int zgsz3139;
        CREATE(sail_int)(&zgsz3139);
        CONVERT_OF(sail_int, mach_int)(&zgsz3139, 39l);
        sail_int zgsz3140;
        CREATE(sail_int)(&zgsz3140);
        CONVERT_OF(sail_int, mach_int)(&zgsz3140, 32l);
        lbits zgsz3141;
        CREATE(lbits)(&zgsz3141);
        vector_subrange_lbits(&zgsz3141, zgsz3138, zgsz3139, zgsz3140);
        zBs = CONVERT_OF(fbits, lbits)(zgsz3141, true);
        KILL(lbits)(&zgsz3141);
        KILL(sail_int)(&zgsz3140);
        KILL(sail_int)(&zgsz3139);
        KILL(lbits)(&zgsz3138);
      }
      zgsz3131 = UNIT;
      }
    }
    uint64_t zcarry_out;
    {
      bool zgaz390;
      {
        uint64_t zgaz389;
        {
          lbits zgsz3170;
          CREATE(lbits)(&zgsz3170);
          CONVERT_OF(lbits, fbits)(&zgsz3170, zBs, UINT64_C(8) , true);
          sail_int zgsz3171;
          CREATE(sail_int)(&zgsz3171);
          CONVERT_OF(sail_int, mach_int)(&zgsz3171, 5l);
          sail_int zgsz3172;
          CREATE(sail_int)(&zgsz3172);
          CONVERT_OF(sail_int, mach_int)(&zgsz3172, 0l);
          lbits zgsz3173;
          CREATE(lbits)(&zgsz3173);
          vector_subrange_lbits(&zgsz3173, zgsz3170, zgsz3171, zgsz3172);
          zgaz389 = CONVERT_OF(fbits, lbits)(zgsz3173, true);
          KILL(lbits)(&zgsz3173);
          KILL(sail_int)(&zgsz3172);
          KILL(sail_int)(&zgsz3171);
          KILL(lbits)(&zgsz3170);
        }
        zgaz390 = sailgen_z8operatorz0zzzz7nzzJzzK6z3zI_uz9(zT, zgaz389);
      
      }
      if (zgaz390) {  zcarry_out = UINT64_C(0b01);  } else {  zcarry_out = UINT64_C(0b00);  }
    
    }
    uint64_t zTtop2;
    {
      uint64_t zgaz388;
      {
        uint64_t zgaz387;
        {
          lbits zgsz3174;
          CREATE(lbits)(&zgsz3174);
          CONVERT_OF(lbits, fbits)(&zgsz3174, zBs, UINT64_C(8) , true);
          sail_int zgsz3175;
          CREATE(sail_int)(&zgsz3175);
          CONVERT_OF(sail_int, mach_int)(&zgsz3175, 7l);
          sail_int zgsz3176;
          CREATE(sail_int)(&zgsz3176);
          CONVERT_OF(sail_int, mach_int)(&zgsz3176, 6l);
          lbits zgsz3177;
          CREATE(lbits)(&zgsz3177);
          vector_subrange_lbits(&zgsz3177, zgsz3174, zgsz3175, zgsz3176);
          zgaz387 = CONVERT_OF(fbits, lbits)(zgsz3177, true);
          KILL(lbits)(&zgsz3177);
          KILL(sail_int)(&zgsz3176);
          KILL(sail_int)(&zgsz3175);
          KILL(lbits)(&zgsz3174);
        }
        {
          lbits zgsz3178;
          CREATE(lbits)(&zgsz3178);
          CONVERT_OF(lbits, fbits)(&zgsz3178, zgaz387, UINT64_C(2) , true);
          lbits zgsz3179;
          CREATE(lbits)(&zgsz3179);
          CONVERT_OF(lbits, fbits)(&zgsz3179, zlenMSBs, UINT64_C(2) , true);
          lbits zgsz3180;
          CREATE(lbits)(&zgsz3180);
          add_bits(&zgsz3180, zgsz3178, zgsz3179);
          zgaz388 = CONVERT_OF(fbits, lbits)(zgsz3180, true);
          KILL(lbits)(&zgsz3180);
          KILL(lbits)(&zgsz3179);
          KILL(lbits)(&zgsz3178);
        }
      
      }
      {
        lbits zgsz3181;
        CREATE(lbits)(&zgsz3181);
        CONVERT_OF(lbits, fbits)(&zgsz3181, zgaz388, UINT64_C(2) , true);
        lbits zgsz3182;
        CREATE(lbits)(&zgsz3182);
        CONVERT_OF(lbits, fbits)(&zgsz3182, zcarry_out, UINT64_C(2) , true);
        lbits zgsz3183;
        CREATE(lbits)(&zgsz3183);
        add_bits(&zgsz3183, zgsz3181, zgsz3182);
        zTtop2 = CONVERT_OF(fbits, lbits)(zgsz3183, true);
        KILL(lbits)(&zgsz3183);
        KILL(lbits)(&zgsz3182);
        KILL(lbits)(&zgsz3181);
      }
    
    }
    struct zCapability zgaz386;
    {
      bool zgaz359;
      {
        fbits zgaz358;
        {
          sail_int zgsz3185;
          CREATE(sail_int)(&zgsz3185);
          CONVERT_OF(sail_int, mach_int)(&zgsz3185, 63l);
          lbits zgsz3184;
          CREATE(lbits)(&zgsz3184);
          CONVERT_OF(lbits, fbits)(&zgsz3184, zc, UINT64_C(64) , true);
          zgaz358 = bitvector_access(zgsz3184, zgsz3185);
          KILL(sail_int)(&zgsz3185);
          KILL(lbits)(&zgsz3184);
        }
        zgaz359 = sailgen_bit_to_bool(zgaz358);
      
      }
      bool zgaz361;
      {
        fbits zgaz360;
        {
          sail_int zgsz3187;
          CREATE(sail_int)(&zgsz3187);
          CONVERT_OF(sail_int, mach_int)(&zgsz3187, 62l);
          lbits zgsz3186;
          CREATE(lbits)(&zgsz3186);
          CONVERT_OF(lbits, fbits)(&zgsz3186, zc, UINT64_C(64) , true);
          zgaz360 = bitvector_access(zgsz3186, zgsz3187);
          KILL(sail_int)(&zgsz3187);
          KILL(lbits)(&zgsz3186);
        }
        zgaz361 = sailgen_bit_to_bool(zgaz360);
      
      }
      bool zgaz363;
      {
        fbits zgaz362;
        {
          sail_int zgsz3189;
          CREATE(sail_int)(&zgsz3189);
          CONVERT_OF(sail_int, mach_int)(&zgsz3189, 61l);
          lbits zgsz3188;
          CREATE(lbits)(&zgsz3188);
          CONVERT_OF(lbits, fbits)(&zgsz3188, zc, UINT64_C(64) , true);
          zgaz362 = bitvector_access(zgsz3188, zgsz3189);
          KILL(sail_int)(&zgsz3189);
          KILL(lbits)(&zgsz3188);
        }
        zgaz363 = sailgen_bit_to_bool(zgaz362);
      
      }
      bool zgaz365;
      {
        fbits zgaz364;
        {
          sail_int zgsz3191;
          CREATE(sail_int)(&zgsz3191);
          CONVERT_OF(sail_int, mach_int)(&zgsz3191, 60l);
          lbits zgsz3190;
          CREATE(lbits)(&zgsz3190);
          CONVERT_OF(lbits, fbits)(&zgsz3190, zc, UINT64_C(64) , true);
          zgaz364 = bitvector_access(zgsz3190, zgsz3191);
          KILL(sail_int)(&zgsz3191);
          KILL(lbits)(&zgsz3190);
        }
        zgaz365 = sailgen_bit_to_bool(zgaz364);
      
      }
      bool zgaz367;
      {
        fbits zgaz366;
        {
          sail_int zgsz3193;
          CREATE(sail_int)(&zgsz3193);
          CONVERT_OF(sail_int, mach_int)(&zgsz3193, 59l);
          lbits zgsz3192;
          CREATE(lbits)(&zgsz3192);
          CONVERT_OF(lbits, fbits)(&zgsz3192, zc, UINT64_C(64) , true);
          zgaz366 = bitvector_access(zgsz3192, zgsz3193);
          KILL(sail_int)(&zgsz3193);
          KILL(lbits)(&zgsz3192);
        }
        zgaz367 = sailgen_bit_to_bool(zgaz366);
      
      }
      bool zgaz369;
      {
        fbits zgaz368;
        {
          sail_int zgsz3195;
          CREATE(sail_int)(&zgsz3195);
          CONVERT_OF(sail_int, mach_int)(&zgsz3195, 58l);
          lbits zgsz3194;
          CREATE(lbits)(&zgsz3194);
          CONVERT_OF(lbits, fbits)(&zgsz3194, zc, UINT64_C(64) , true);
          zgaz368 = bitvector_access(zgsz3194, zgsz3195);
          KILL(sail_int)(&zgsz3195);
          KILL(lbits)(&zgsz3194);
        }
        zgaz369 = sailgen_bit_to_bool(zgaz368);
      
      }
      bool zgaz371;
      {
        fbits zgaz370;
        {
          sail_int zgsz3197;
          CREATE(sail_int)(&zgsz3197);
          CONVERT_OF(sail_int, mach_int)(&zgsz3197, 57l);
          lbits zgsz3196;
          CREATE(lbits)(&zgsz3196);
          CONVERT_OF(lbits, fbits)(&zgsz3196, zc, UINT64_C(64) , true);
          zgaz370 = bitvector_access(zgsz3196, zgsz3197);
          KILL(sail_int)(&zgsz3197);
          KILL(lbits)(&zgsz3196);
        }
        zgaz371 = sailgen_bit_to_bool(zgaz370);
      
      }
      bool zgaz373;
      {
        fbits zgaz372;
        {
          sail_int zgsz3199;
          CREATE(sail_int)(&zgsz3199);
          CONVERT_OF(sail_int, mach_int)(&zgsz3199, 56l);
          lbits zgsz3198;
          CREATE(lbits)(&zgsz3198);
          CONVERT_OF(lbits, fbits)(&zgsz3198, zc, UINT64_C(64) , true);
          zgaz372 = bitvector_access(zgsz3198, zgsz3199);
          KILL(sail_int)(&zgsz3199);
          KILL(lbits)(&zgsz3198);
        }
        zgaz373 = sailgen_bit_to_bool(zgaz372);
      
      }
      bool zgaz375;
      {
        fbits zgaz374;
        {
          sail_int zgsz3201;
          CREATE(sail_int)(&zgsz3201);
          CONVERT_OF(sail_int, mach_int)(&zgsz3201, 55l);
          lbits zgsz3200;
          CREATE(lbits)(&zgsz3200);
          CONVERT_OF(lbits, fbits)(&zgsz3200, zc, UINT64_C(64) , true);
          zgaz374 = bitvector_access(zgsz3200, zgsz3201);
          KILL(sail_int)(&zgsz3201);
          KILL(lbits)(&zgsz3200);
        }
        zgaz375 = sailgen_bit_to_bool(zgaz374);
      
      }
      bool zgaz377;
      {
        fbits zgaz376;
        {
          sail_int zgsz3203;
          CREATE(sail_int)(&zgsz3203);
          CONVERT_OF(sail_int, mach_int)(&zgsz3203, 54l);
          lbits zgsz3202;
          CREATE(lbits)(&zgsz3202);
          CONVERT_OF(lbits, fbits)(&zgsz3202, zc, UINT64_C(64) , true);
          zgaz376 = bitvector_access(zgsz3202, zgsz3203);
          KILL(sail_int)(&zgsz3203);
          KILL(lbits)(&zgsz3202);
        }
        zgaz377 = sailgen_bit_to_bool(zgaz376);
      
      }
      bool zgaz379;
      {
        fbits zgaz378;
        {
          sail_int zgsz3205;
          CREATE(sail_int)(&zgsz3205);
          CONVERT_OF(sail_int, mach_int)(&zgsz3205, 53l);
          lbits zgsz3204;
          CREATE(lbits)(&zgsz3204);
          CONVERT_OF(lbits, fbits)(&zgsz3204, zc, UINT64_C(64) , true);
          zgaz378 = bitvector_access(zgsz3204, zgsz3205);
          KILL(sail_int)(&zgsz3205);
          KILL(lbits)(&zgsz3204);
        }
        zgaz379 = sailgen_bit_to_bool(zgaz378);
      
      }
      bool zgaz381;
      {
        fbits zgaz380;
        {
          sail_int zgsz3207;
          CREATE(sail_int)(&zgsz3207);
          CONVERT_OF(sail_int, mach_int)(&zgsz3207, 52l);
          lbits zgsz3206;
          CREATE(lbits)(&zgsz3206);
          CONVERT_OF(lbits, fbits)(&zgsz3206, zc, UINT64_C(64) , true);
          zgaz380 = bitvector_access(zgsz3206, zgsz3207);
          KILL(sail_int)(&zgsz3207);
          KILL(lbits)(&zgsz3206);
        }
        zgaz381 = sailgen_bit_to_bool(zgaz380);
      
      }
      bool zgaz383;
      {
        fbits zgaz382;
        {
          sail_int zgsz3209;
          CREATE(sail_int)(&zgsz3209);
          CONVERT_OF(sail_int, mach_int)(&zgsz3209, 51l);
          lbits zgsz3208;
          CREATE(lbits)(&zgsz3208);
          CONVERT_OF(lbits, fbits)(&zgsz3208, zc, UINT64_C(64) , true);
          zgaz382 = bitvector_access(zgsz3208, zgsz3209);
          KILL(sail_int)(&zgsz3209);
          KILL(lbits)(&zgsz3208);
        }
        zgaz383 = sailgen_bit_to_bool(zgaz382);
      
      }
      uint64_t zgaz384;
      {
        lbits zgsz3210;
        CREATE(lbits)(&zgsz3210);
        CONVERT_OF(lbits, fbits)(&zgsz3210, zTtop2, UINT64_C(2) , true);
        lbits zgsz3211;
        CREATE(lbits)(&zgsz3211);
        CONVERT_OF(lbits, fbits)(&zgsz3211, zT, UINT64_C(6) , true);
        lbits zgsz3212;
        CREATE(lbits)(&zgsz3212);
        append(&zgsz3212, zgsz3210, zgsz3211);
        zgaz384 = CONVERT_OF(fbits, lbits)(zgsz3212, true);
        KILL(lbits)(&zgsz3212);
        KILL(lbits)(&zgsz3211);
        KILL(lbits)(&zgsz3210);
      }
      uint64_t zgaz385;
      {
        lbits zgsz3213;
        CREATE(lbits)(&zgsz3213);
        CONVERT_OF(lbits, fbits)(&zgsz3213, zc, UINT64_C(64) , true);
        sail_int zgsz3214;
        CREATE(sail_int)(&zgsz3214);
        CONVERT_OF(sail_int, mach_int)(&zgsz3214, 31l);
        sail_int zgsz3215;
        CREATE(sail_int)(&zgsz3215);
        CONVERT_OF(sail_int, mach_int)(&zgsz3215, 0l);
        lbits zgsz3216;
        CREATE(lbits)(&zgsz3216);
        vector_subrange_lbits(&zgsz3216, zgsz3213, zgsz3214, zgsz3215);
        zgaz385 = CONVERT_OF(fbits, lbits)(zgsz3216, true);
        KILL(lbits)(&zgsz3216);
        KILL(sail_int)(&zgsz3215);
        KILL(sail_int)(&zgsz3214);
        KILL(lbits)(&zgsz3213);
      }
      struct zCapability zgsz3217;
      zgsz3217.zB = zBs;
      zgsz3217.zE = zE;
      zgsz3217.zT = zgaz384;
      zgsz3217.zaccess_system_regs = zgaz361;
      zgsz3217.zaddress = zgaz385;
      zgsz3217.zflag_cap_mode = zgaz383;
      zgsz3217.zglobal = zgaz381;
      zgsz3217.zinternal_e = zinternal_exponent;
      zgsz3217.zotype = zotype;
      zgsz3217.zpermit_ccall = zgaz365;
      zgsz3217.zpermit_execute = zgaz379;
      zgsz3217.zpermit_load = zgaz377;
      zgsz3217.zpermit_load_cap = zgaz373;
      zgsz3217.zpermit_seal = zgaz367;
      zgsz3217.zpermit_set_CID = zgaz359;
      zgsz3217.zpermit_store = zgaz375;
      zgsz3217.zpermit_store_cap = zgaz371;
      zgsz3217.zpermit_store_local_cap = zgaz369;
      zgsz3217.zpermit_unseal = zgaz363;
      zgsz3217.zreserved = UINT64_C(0);
      zgsz3217.zsealed = zsealed;
      zgsz3217.ztag = zt;
      zgsz3217.zuperms = UINT64_C(0);
      zgaz386 = zgsz3217;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    }
    zcbz334 = zgaz386;
    goto cleanup_134;
    /* unreachable after return */
  
  
  
  
  
  
  
  
    goto finish_match_131;
    goto end_cleanup_135;
  cleanup_134: ;
  
  
  
  
  
  
  
  
  
  
  
  
    goto end_function_133;
  end_cleanup_135: ;
  }
case_132: ;
  sail_match_failure("capBitsToCapability");
finish_match_131: ;
  zcbz334 = zgsz3130;




end_function_133: ;
  return zcbz334;
end_block_exception_136: ;
  struct zCapability zcbz354 = { .zuperms = UINT64_C(0xdeadc0de), .ztag = false, .zsealed = false, .zreserved = UINT64_C(0xdeadc0de), .zpermit_unseal = false, .zpermit_store_local_cap = false, .zpermit_store_cap = false, .zpermit_store = false, .zpermit_set_CID = false, .zpermit_seal = false, .zpermit_load_cap = false, .zpermit_load = false, .zpermit_execute = false, .zpermit_ccall = false, .zotype = UINT64_C(0xdeadc0de), .zinternal_e = false, .zglobal = false, .zflag_cap_mode = false, .zaddress = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zT = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zB = UINT64_C(0xdeadc0de) };
  return zcbz354;
}

int64_t zmax_otype;
static void create_letbind_19(void) {  


  int64_t zgsz3219;
  int64_t zgaz392;
  zgaz392 = sailgen_zzzz7nzzJzzK4z3MAX(zotype_width);
  {
    sail_int zgsz3220;
    CREATE(sail_int)(&zgsz3220);
    CONVERT_OF(sail_int, mach_int)(&zgsz3220, zgaz392);
    sail_int zgsz3221;
    CREATE(sail_int)(&zgsz3221);
    CONVERT_OF(sail_int, mach_int)(&zgsz3221, zreserved_otypes);
    sail_int zgsz3222;
    CREATE(sail_int)(&zgsz3222);
    sub_int(&zgsz3222, zgsz3220, zgsz3221);
    zgsz3219 = CONVERT_OF(mach_int, sail_int)(zgsz3222);
    KILL(sail_int)(&zgsz3222);
    KILL(sail_int)(&zgsz3221);
    KILL(sail_int)(&zgsz3220);
  }

  zmax_otype = zgsz3219;

let_end_137: ;
}
static void kill_letbind_19(void) {  
}

static uint64_t sailgen_getCapHardPerms(struct zCapability);

static uint64_t sailgen_getCapHardPerms(struct zCapability zcap)
{
  __label__ end_function_139, end_block_exception_140;

  uint64_t zcbz335;
  uint64_t zgaz3125;
  {
    bool zgaz393;
    zgaz393 = zcap.zpermit_set_CID;
    zgaz3125 = sailgen_bool_to_bits(zgaz393);
  
  }
  uint64_t zgaz3126;
  {
    uint64_t zgaz3123;
    {
      bool zgaz394;
      zgaz394 = zcap.zaccess_system_regs;
      zgaz3123 = sailgen_bool_to_bits(zgaz394);
    
    }
    uint64_t zgaz3124;
    {
      uint64_t zgaz3121;
      {
        bool zgaz395;
        zgaz395 = zcap.zpermit_unseal;
        zgaz3121 = sailgen_bool_to_bits(zgaz395);
      
      }
      uint64_t zgaz3122;
      {
        uint64_t zgaz3119;
        {
          bool zgaz396;
          zgaz396 = zcap.zpermit_ccall;
          zgaz3119 = sailgen_bool_to_bits(zgaz396);
        
        }
        uint64_t zgaz3120;
        {
          uint64_t zgaz3117;
          {
            bool zgaz397;
            zgaz397 = zcap.zpermit_seal;
            zgaz3117 = sailgen_bool_to_bits(zgaz397);
          
          }
          uint64_t zgaz3118;
          {
            uint64_t zgaz3115;
            {
              bool zgaz398;
              zgaz398 = zcap.zpermit_store_local_cap;
              zgaz3115 = sailgen_bool_to_bits(zgaz398);
            
            }
            uint64_t zgaz3116;
            {
              uint64_t zgaz3113;
              {
                bool zgaz399;
                zgaz399 = zcap.zpermit_store_cap;
                zgaz3113 = sailgen_bool_to_bits(zgaz399);
              
              }
              uint64_t zgaz3114;
              {
                uint64_t zgaz3111;
                {
                  bool zgaz3100;
                  zgaz3100 = zcap.zpermit_load_cap;
                  zgaz3111 = sailgen_bool_to_bits(zgaz3100);
                
                }
                uint64_t zgaz3112;
                {
                  uint64_t zgaz3109;
                  {
                    bool zgaz3101;
                    zgaz3101 = zcap.zpermit_store;
                    zgaz3109 = sailgen_bool_to_bits(zgaz3101);
                  
                  }
                  uint64_t zgaz3110;
                  {
                    uint64_t zgaz3107;
                    {
                      bool zgaz3102;
                      zgaz3102 = zcap.zpermit_load;
                      zgaz3107 = sailgen_bool_to_bits(zgaz3102);
                    
                    }
                    uint64_t zgaz3108;
                    {
                      uint64_t zgaz3105;
                      {
                        bool zgaz3103;
                        zgaz3103 = zcap.zpermit_execute;
                        zgaz3105 = sailgen_bool_to_bits(zgaz3103);
                      
                      }
                      uint64_t zgaz3106;
                      {
                        bool zgaz3104;
                        zgaz3104 = zcap.zglobal;
                        zgaz3106 = sailgen_bool_to_bits(zgaz3104);
                      
                      }
                      {
                        lbits zgsz3223;
                        CREATE(lbits)(&zgsz3223);
                        CONVERT_OF(lbits, fbits)(&zgsz3223, zgaz3105, UINT64_C(1) , true);
                        lbits zgsz3224;
                        CREATE(lbits)(&zgsz3224);
                        CONVERT_OF(lbits, fbits)(&zgsz3224, zgaz3106, UINT64_C(1) , true);
                        lbits zgsz3225;
                        CREATE(lbits)(&zgsz3225);
                        append(&zgsz3225, zgsz3223, zgsz3224);
                        zgaz3108 = CONVERT_OF(fbits, lbits)(zgsz3225, true);
                        KILL(lbits)(&zgsz3225);
                        KILL(lbits)(&zgsz3224);
                        KILL(lbits)(&zgsz3223);
                      }
                    
                    
                    }
                    {
                      lbits zgsz3226;
                      CREATE(lbits)(&zgsz3226);
                      CONVERT_OF(lbits, fbits)(&zgsz3226, zgaz3107, UINT64_C(1) , true);
                      lbits zgsz3227;
                      CREATE(lbits)(&zgsz3227);
                      CONVERT_OF(lbits, fbits)(&zgsz3227, zgaz3108, UINT64_C(2) , true);
                      lbits zgsz3228;
                      CREATE(lbits)(&zgsz3228);
                      append(&zgsz3228, zgsz3226, zgsz3227);
                      zgaz3110 = CONVERT_OF(fbits, lbits)(zgsz3228, true);
                      KILL(lbits)(&zgsz3228);
                      KILL(lbits)(&zgsz3227);
                      KILL(lbits)(&zgsz3226);
                    }
                  
                  
                  }
                  {
                    lbits zgsz3229;
                    CREATE(lbits)(&zgsz3229);
                    CONVERT_OF(lbits, fbits)(&zgsz3229, zgaz3109, UINT64_C(1) , true);
                    lbits zgsz3230;
                    CREATE(lbits)(&zgsz3230);
                    CONVERT_OF(lbits, fbits)(&zgsz3230, zgaz3110, UINT64_C(3) , true);
                    lbits zgsz3231;
                    CREATE(lbits)(&zgsz3231);
                    append(&zgsz3231, zgsz3229, zgsz3230);
                    zgaz3112 = CONVERT_OF(fbits, lbits)(zgsz3231, true);
                    KILL(lbits)(&zgsz3231);
                    KILL(lbits)(&zgsz3230);
                    KILL(lbits)(&zgsz3229);
                  }
                
                
                }
                {
                  lbits zgsz3232;
                  CREATE(lbits)(&zgsz3232);
                  CONVERT_OF(lbits, fbits)(&zgsz3232, zgaz3111, UINT64_C(1) , true);
                  lbits zgsz3233;
                  CREATE(lbits)(&zgsz3233);
                  CONVERT_OF(lbits, fbits)(&zgsz3233, zgaz3112, UINT64_C(4) , true);
                  lbits zgsz3234;
                  CREATE(lbits)(&zgsz3234);
                  append(&zgsz3234, zgsz3232, zgsz3233);
                  zgaz3114 = CONVERT_OF(fbits, lbits)(zgsz3234, true);
                  KILL(lbits)(&zgsz3234);
                  KILL(lbits)(&zgsz3233);
                  KILL(lbits)(&zgsz3232);
                }
              
              
              }
              {
                lbits zgsz3235;
                CREATE(lbits)(&zgsz3235);
                CONVERT_OF(lbits, fbits)(&zgsz3235, zgaz3113, UINT64_C(1) , true);
                lbits zgsz3236;
                CREATE(lbits)(&zgsz3236);
                CONVERT_OF(lbits, fbits)(&zgsz3236, zgaz3114, UINT64_C(5) , true);
                lbits zgsz3237;
                CREATE(lbits)(&zgsz3237);
                append(&zgsz3237, zgsz3235, zgsz3236);
                zgaz3116 = CONVERT_OF(fbits, lbits)(zgsz3237, true);
                KILL(lbits)(&zgsz3237);
                KILL(lbits)(&zgsz3236);
                KILL(lbits)(&zgsz3235);
              }
            
            
            }
            {
              lbits zgsz3238;
              CREATE(lbits)(&zgsz3238);
              CONVERT_OF(lbits, fbits)(&zgsz3238, zgaz3115, UINT64_C(1) , true);
              lbits zgsz3239;
              CREATE(lbits)(&zgsz3239);
              CONVERT_OF(lbits, fbits)(&zgsz3239, zgaz3116, UINT64_C(6) , true);
              lbits zgsz3240;
              CREATE(lbits)(&zgsz3240);
              append(&zgsz3240, zgsz3238, zgsz3239);
              zgaz3118 = CONVERT_OF(fbits, lbits)(zgsz3240, true);
              KILL(lbits)(&zgsz3240);
              KILL(lbits)(&zgsz3239);
              KILL(lbits)(&zgsz3238);
            }
          
          
          }
          {
            lbits zgsz3241;
            CREATE(lbits)(&zgsz3241);
            CONVERT_OF(lbits, fbits)(&zgsz3241, zgaz3117, UINT64_C(1) , true);
            lbits zgsz3242;
            CREATE(lbits)(&zgsz3242);
            CONVERT_OF(lbits, fbits)(&zgsz3242, zgaz3118, UINT64_C(7) , true);
            lbits zgsz3243;
            CREATE(lbits)(&zgsz3243);
            append(&zgsz3243, zgsz3241, zgsz3242);
            zgaz3120 = CONVERT_OF(fbits, lbits)(zgsz3243, true);
            KILL(lbits)(&zgsz3243);
            KILL(lbits)(&zgsz3242);
            KILL(lbits)(&zgsz3241);
          }
        
        
        }
        {
          lbits zgsz3244;
          CREATE(lbits)(&zgsz3244);
          CONVERT_OF(lbits, fbits)(&zgsz3244, zgaz3119, UINT64_C(1) , true);
          lbits zgsz3245;
          CREATE(lbits)(&zgsz3245);
          CONVERT_OF(lbits, fbits)(&zgsz3245, zgaz3120, UINT64_C(8) , true);
          lbits zgsz3246;
          CREATE(lbits)(&zgsz3246);
          append(&zgsz3246, zgsz3244, zgsz3245);
          zgaz3122 = CONVERT_OF(fbits, lbits)(zgsz3246, true);
          KILL(lbits)(&zgsz3246);
          KILL(lbits)(&zgsz3245);
          KILL(lbits)(&zgsz3244);
        }
      
      
      }
      {
        lbits zgsz3247;
        CREATE(lbits)(&zgsz3247);
        CONVERT_OF(lbits, fbits)(&zgsz3247, zgaz3121, UINT64_C(1) , true);
        lbits zgsz3248;
        CREATE(lbits)(&zgsz3248);
        CONVERT_OF(lbits, fbits)(&zgsz3248, zgaz3122, UINT64_C(9) , true);
        lbits zgsz3249;
        CREATE(lbits)(&zgsz3249);
        append(&zgsz3249, zgsz3247, zgsz3248);
        zgaz3124 = CONVERT_OF(fbits, lbits)(zgsz3249, true);
        KILL(lbits)(&zgsz3249);
        KILL(lbits)(&zgsz3248);
        KILL(lbits)(&zgsz3247);
      }
    
    
    }
    {
      lbits zgsz3250;
      CREATE(lbits)(&zgsz3250);
      CONVERT_OF(lbits, fbits)(&zgsz3250, zgaz3123, UINT64_C(1) , true);
      lbits zgsz3251;
      CREATE(lbits)(&zgsz3251);
      CONVERT_OF(lbits, fbits)(&zgsz3251, zgaz3124, UINT64_C(10) , true);
      lbits zgsz3252;
      CREATE(lbits)(&zgsz3252);
      append(&zgsz3252, zgsz3250, zgsz3251);
      zgaz3126 = CONVERT_OF(fbits, lbits)(zgsz3252, true);
      KILL(lbits)(&zgsz3252);
      KILL(lbits)(&zgsz3251);
      KILL(lbits)(&zgsz3250);
    }
  
  
  }
  {
    lbits zgsz3253;
    CREATE(lbits)(&zgsz3253);
    CONVERT_OF(lbits, fbits)(&zgsz3253, zgaz3125, UINT64_C(1) , true);
    lbits zgsz3254;
    CREATE(lbits)(&zgsz3254);
    CONVERT_OF(lbits, fbits)(&zgsz3254, zgaz3126, UINT64_C(11) , true);
    lbits zgsz3255;
    CREATE(lbits)(&zgsz3255);
    append(&zgsz3255, zgsz3253, zgsz3254);
    zcbz335 = CONVERT_OF(fbits, lbits)(zgsz3255, true);
    KILL(lbits)(&zgsz3255);
    KILL(lbits)(&zgsz3254);
    KILL(lbits)(&zgsz3253);
  }


end_function_139: ;
  return zcbz335;
end_block_exception_140: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_capToBits(struct zCapability);

static uint64_t sailgen_capToBits(struct zCapability zcap)
{
  __label__ cleanup_143, end_cleanup_144, end_function_142, end_block_exception_145;

  uint64_t zcbz336;
  uint64_t zt_hi;
  {
    uint64_t zgaz3153;
    zgaz3153 = zcap.zT;
    int64_t zgaz3154;
    {
      sail_int zgsz3256;
      CREATE(sail_int)(&zgsz3256);
      CONVERT_OF(sail_int, mach_int)(&zgsz3256, zmantissa_width);
      sail_int zgsz3257;
      CREATE(sail_int)(&zgsz3257);
      CONVERT_OF(sail_int, mach_int)(&zgsz3257, 3l);
      sail_int zgsz3258;
      CREATE(sail_int)(&zgsz3258);
      sub_int(&zgsz3258, zgsz3256, zgsz3257);
      zgaz3154 = CONVERT_OF(mach_int, sail_int)(zgsz3258);
      KILL(sail_int)(&zgsz3258);
      KILL(sail_int)(&zgsz3257);
      KILL(sail_int)(&zgsz3256);
    }
    {
      lbits zgsz3259;
      CREATE(lbits)(&zgsz3259);
      CONVERT_OF(lbits, fbits)(&zgsz3259, zgaz3153, UINT64_C(8) , true);
      sail_int zgsz3260;
      CREATE(sail_int)(&zgsz3260);
      CONVERT_OF(sail_int, mach_int)(&zgsz3260, zgaz3154);
      sail_int zgsz3261;
      CREATE(sail_int)(&zgsz3261);
      CONVERT_OF(sail_int, mach_int)(&zgsz3261, 3l);
      lbits zgsz3262;
      CREATE(lbits)(&zgsz3262);
      vector_subrange_lbits(&zgsz3262, zgsz3259, zgsz3260, zgsz3261);
      zt_hi = CONVERT_OF(fbits, lbits)(zgsz3262, true);
      KILL(lbits)(&zgsz3262);
      KILL(sail_int)(&zgsz3261);
      KILL(sail_int)(&zgsz3260);
      KILL(lbits)(&zgsz3259);
    }
  
  
  }
  uint64_t zt_lo;
  {
    uint64_t zgaz3152;
    zgaz3152 = zcap.zT;
    {
      lbits zgsz3263;
      CREATE(lbits)(&zgsz3263);
      CONVERT_OF(lbits, fbits)(&zgsz3263, zgaz3152, UINT64_C(8) , true);
      sail_int zgsz3264;
      CREATE(sail_int)(&zgsz3264);
      CONVERT_OF(sail_int, mach_int)(&zgsz3264, 2l);
      sail_int zgsz3265;
      CREATE(sail_int)(&zgsz3265);
      CONVERT_OF(sail_int, mach_int)(&zgsz3265, 0l);
      lbits zgsz3266;
      CREATE(lbits)(&zgsz3266);
      vector_subrange_lbits(&zgsz3266, zgsz3263, zgsz3264, zgsz3265);
      zt_lo = CONVERT_OF(fbits, lbits)(zgsz3266, true);
      KILL(lbits)(&zgsz3266);
      KILL(sail_int)(&zgsz3265);
      KILL(sail_int)(&zgsz3264);
      KILL(lbits)(&zgsz3263);
    }
  
  }
  uint64_t zb_hi;
  {
    uint64_t zgaz3150;
    zgaz3150 = zcap.zB;
    int64_t zgaz3151;
    {
      sail_int zgsz3267;
      CREATE(sail_int)(&zgsz3267);
      CONVERT_OF(sail_int, mach_int)(&zgsz3267, zmantissa_width);
      sail_int zgsz3268;
      CREATE(sail_int)(&zgsz3268);
      CONVERT_OF(sail_int, mach_int)(&zgsz3268, 1l);
      sail_int zgsz3269;
      CREATE(sail_int)(&zgsz3269);
      sub_int(&zgsz3269, zgsz3267, zgsz3268);
      zgaz3151 = CONVERT_OF(mach_int, sail_int)(zgsz3269);
      KILL(sail_int)(&zgsz3269);
      KILL(sail_int)(&zgsz3268);
      KILL(sail_int)(&zgsz3267);
    }
    {
      lbits zgsz3270;
      CREATE(lbits)(&zgsz3270);
      CONVERT_OF(lbits, fbits)(&zgsz3270, zgaz3150, UINT64_C(8) , true);
      sail_int zgsz3271;
      CREATE(sail_int)(&zgsz3271);
      CONVERT_OF(sail_int, mach_int)(&zgsz3271, zgaz3151);
      sail_int zgsz3272;
      CREATE(sail_int)(&zgsz3272);
      CONVERT_OF(sail_int, mach_int)(&zgsz3272, 3l);
      lbits zgsz3273;
      CREATE(lbits)(&zgsz3273);
      vector_subrange_lbits(&zgsz3273, zgsz3270, zgsz3271, zgsz3272);
      zb_hi = CONVERT_OF(fbits, lbits)(zgsz3273, true);
      KILL(lbits)(&zgsz3273);
      KILL(sail_int)(&zgsz3272);
      KILL(sail_int)(&zgsz3271);
      KILL(lbits)(&zgsz3270);
    }
  
  
  }
  uint64_t zb_lo;
  {
    uint64_t zgaz3149;
    zgaz3149 = zcap.zB;
    {
      lbits zgsz3274;
      CREATE(lbits)(&zgsz3274);
      CONVERT_OF(lbits, fbits)(&zgsz3274, zgaz3149, UINT64_C(8) , true);
      sail_int zgsz3275;
      CREATE(sail_int)(&zgsz3275);
      CONVERT_OF(sail_int, mach_int)(&zgsz3275, 2l);
      sail_int zgsz3276;
      CREATE(sail_int)(&zgsz3276);
      CONVERT_OF(sail_int, mach_int)(&zgsz3276, 0l);
      lbits zgsz3277;
      CREATE(lbits)(&zgsz3277);
      vector_subrange_lbits(&zgsz3277, zgsz3274, zgsz3275, zgsz3276);
      zb_lo = CONVERT_OF(fbits, lbits)(zgsz3277, true);
      KILL(lbits)(&zgsz3277);
      KILL(sail_int)(&zgsz3276);
      KILL(sail_int)(&zgsz3275);
      KILL(lbits)(&zgsz3274);
    }
  
  }
  {
    bool zgaz3127;
    zgaz3127 = zcap.zinternal_e;
    unit zgsz3278;
    if (zgaz3127) {
    {
      uint64_t zgaz3128;
      zgaz3128 = zcap.zE;
      {
        lbits zgsz3279;
        CREATE(lbits)(&zgsz3279);
        CONVERT_OF(lbits, fbits)(&zgsz3279, zgaz3128, UINT64_C(6) , true);
        sail_int zgsz3280;
        CREATE(sail_int)(&zgsz3280);
        CONVERT_OF(sail_int, mach_int)(&zgsz3280, 5l);
        sail_int zgsz3281;
        CREATE(sail_int)(&zgsz3281);
        CONVERT_OF(sail_int, mach_int)(&zgsz3281, 3l);
        lbits zgsz3282;
        CREATE(lbits)(&zgsz3282);
        vector_subrange_lbits(&zgsz3282, zgsz3279, zgsz3280, zgsz3281);
        zt_lo = CONVERT_OF(fbits, lbits)(zgsz3282, true);
        KILL(lbits)(&zgsz3282);
        KILL(sail_int)(&zgsz3281);
        KILL(sail_int)(&zgsz3280);
        KILL(lbits)(&zgsz3279);
      }
      unit zgsz3283;
      zgsz3283 = UNIT;
    
    }
    uint64_t zgaz3129;
    zgaz3129 = zcap.zE;
    {
      lbits zgsz3284;
      CREATE(lbits)(&zgsz3284);
      CONVERT_OF(lbits, fbits)(&zgsz3284, zgaz3129, UINT64_C(6) , true);
      sail_int zgsz3285;
      CREATE(sail_int)(&zgsz3285);
      CONVERT_OF(sail_int, mach_int)(&zgsz3285, 2l);
      sail_int zgsz3286;
      CREATE(sail_int)(&zgsz3286);
      CONVERT_OF(sail_int, mach_int)(&zgsz3286, 0l);
      lbits zgsz3287;
      CREATE(lbits)(&zgsz3287);
      vector_subrange_lbits(&zgsz3287, zgsz3284, zgsz3285, zgsz3286);
      zb_lo = CONVERT_OF(fbits, lbits)(zgsz3287, true);
      KILL(lbits)(&zgsz3287);
      KILL(sail_int)(&zgsz3286);
      KILL(sail_int)(&zgsz3285);
      KILL(lbits)(&zgsz3284);
    }
    zgsz3278 = UNIT;
  
    } else {  zgsz3278 = UNIT;  }
  
  }
  uint64_t zgaz3148;
  {
    uint64_t zgaz3146;
    zgaz3146 = zcap.zuperms;
    uint64_t zgaz3147;
    {
      uint64_t zgaz3144;
      zgaz3144 = sailgen_getCapHardPerms(zcap);
      uint64_t zgaz3145;
      {
        uint64_t zgaz3142;
        zgaz3142 = zcap.zreserved;
        uint64_t zgaz3143;
        {
          uint64_t zgaz3140;
          {
            bool zgaz3130;
            zgaz3130 = zcap.zflag_cap_mode;
            zgaz3140 = sailgen_bool_to_bits(zgaz3130);
          
          }
          uint64_t zgaz3141;
          {
            uint64_t zgaz3138;
            zgaz3138 = zcap.zotype;
            uint64_t zgaz3139;
            {
              uint64_t zgaz3136;
              {
                bool zgaz3131;
                zgaz3131 = zcap.zinternal_e;
                zgaz3136 = sailgen_bool_to_bits(zgaz3131);
              
              }
              uint64_t zgaz3137;
              {
                uint64_t zgaz3135;
                {
                  uint64_t zgaz3134;
                  {
                    uint64_t zgaz3133;
                    {
                      uint64_t zgaz3132;
                      zgaz3132 = zcap.zaddress;
                      {
                        lbits zgsz3288;
                        CREATE(lbits)(&zgsz3288);
                        CONVERT_OF(lbits, fbits)(&zgsz3288, zb_lo, UINT64_C(3) , true);
                        lbits zgsz3289;
                        CREATE(lbits)(&zgsz3289);
                        CONVERT_OF(lbits, fbits)(&zgsz3289, zgaz3132, UINT64_C(32) , true);
                        lbits zgsz3290;
                        CREATE(lbits)(&zgsz3290);
                        append(&zgsz3290, zgsz3288, zgsz3289);
                        zgaz3133 = CONVERT_OF(fbits, lbits)(zgsz3290, true);
                        KILL(lbits)(&zgsz3290);
                        KILL(lbits)(&zgsz3289);
                        KILL(lbits)(&zgsz3288);
                      }
                    
                    }
                    {
                      lbits zgsz3291;
                      CREATE(lbits)(&zgsz3291);
                      CONVERT_OF(lbits, fbits)(&zgsz3291, zb_hi, UINT64_C(5) , true);
                      lbits zgsz3292;
                      CREATE(lbits)(&zgsz3292);
                      CONVERT_OF(lbits, fbits)(&zgsz3292, zgaz3133, UINT64_C(35) , true);
                      lbits zgsz3293;
                      CREATE(lbits)(&zgsz3293);
                      append(&zgsz3293, zgsz3291, zgsz3292);
                      zgaz3134 = CONVERT_OF(fbits, lbits)(zgsz3293, true);
                      KILL(lbits)(&zgsz3293);
                      KILL(lbits)(&zgsz3292);
                      KILL(lbits)(&zgsz3291);
                    }
                  
                  }
                  {
                    lbits zgsz3294;
                    CREATE(lbits)(&zgsz3294);
                    CONVERT_OF(lbits, fbits)(&zgsz3294, zt_lo, UINT64_C(3) , true);
                    lbits zgsz3295;
                    CREATE(lbits)(&zgsz3295);
                    CONVERT_OF(lbits, fbits)(&zgsz3295, zgaz3134, UINT64_C(40) , true);
                    lbits zgsz3296;
                    CREATE(lbits)(&zgsz3296);
                    append(&zgsz3296, zgsz3294, zgsz3295);
                    zgaz3135 = CONVERT_OF(fbits, lbits)(zgsz3296, true);
                    KILL(lbits)(&zgsz3296);
                    KILL(lbits)(&zgsz3295);
                    KILL(lbits)(&zgsz3294);
                  }
                
                }
                {
                  lbits zgsz3297;
                  CREATE(lbits)(&zgsz3297);
                  CONVERT_OF(lbits, fbits)(&zgsz3297, zt_hi, UINT64_C(3) , true);
                  lbits zgsz3298;
                  CREATE(lbits)(&zgsz3298);
                  CONVERT_OF(lbits, fbits)(&zgsz3298, zgaz3135, UINT64_C(43) , true);
                  lbits zgsz3299;
                  CREATE(lbits)(&zgsz3299);
                  append(&zgsz3299, zgsz3297, zgsz3298);
                  zgaz3137 = CONVERT_OF(fbits, lbits)(zgsz3299, true);
                  KILL(lbits)(&zgsz3299);
                  KILL(lbits)(&zgsz3298);
                  KILL(lbits)(&zgsz3297);
                }
              
              }
              {
                lbits zgsz3300;
                CREATE(lbits)(&zgsz3300);
                CONVERT_OF(lbits, fbits)(&zgsz3300, zgaz3136, UINT64_C(1) , true);
                lbits zgsz3301;
                CREATE(lbits)(&zgsz3301);
                CONVERT_OF(lbits, fbits)(&zgsz3301, zgaz3137, UINT64_C(46) , true);
                lbits zgsz3302;
                CREATE(lbits)(&zgsz3302);
                append(&zgsz3302, zgsz3300, zgsz3301);
                zgaz3139 = CONVERT_OF(fbits, lbits)(zgsz3302, true);
                KILL(lbits)(&zgsz3302);
                KILL(lbits)(&zgsz3301);
                KILL(lbits)(&zgsz3300);
              }
            
            
            }
            {
              lbits zgsz3303;
              CREATE(lbits)(&zgsz3303);
              CONVERT_OF(lbits, fbits)(&zgsz3303, zgaz3138, UINT64_C(4) , true);
              lbits zgsz3304;
              CREATE(lbits)(&zgsz3304);
              CONVERT_OF(lbits, fbits)(&zgsz3304, zgaz3139, UINT64_C(47) , true);
              lbits zgsz3305;
              CREATE(lbits)(&zgsz3305);
              append(&zgsz3305, zgsz3303, zgsz3304);
              zgaz3141 = CONVERT_OF(fbits, lbits)(zgsz3305, true);
              KILL(lbits)(&zgsz3305);
              KILL(lbits)(&zgsz3304);
              KILL(lbits)(&zgsz3303);
            }
          
          
          }
          {
            lbits zgsz3306;
            CREATE(lbits)(&zgsz3306);
            CONVERT_OF(lbits, fbits)(&zgsz3306, zgaz3140, UINT64_C(1) , true);
            lbits zgsz3307;
            CREATE(lbits)(&zgsz3307);
            CONVERT_OF(lbits, fbits)(&zgsz3307, zgaz3141, UINT64_C(51) , true);
            lbits zgsz3308;
            CREATE(lbits)(&zgsz3308);
            append(&zgsz3308, zgsz3306, zgsz3307);
            zgaz3143 = CONVERT_OF(fbits, lbits)(zgsz3308, true);
            KILL(lbits)(&zgsz3308);
            KILL(lbits)(&zgsz3307);
            KILL(lbits)(&zgsz3306);
          }
        
        
        }
        {
          lbits zgsz3309;
          CREATE(lbits)(&zgsz3309);
          CONVERT_OF(lbits, fbits)(&zgsz3309, zgaz3142, UINT64_C(0) , true);
          lbits zgsz3310;
          CREATE(lbits)(&zgsz3310);
          CONVERT_OF(lbits, fbits)(&zgsz3310, zgaz3143, UINT64_C(52) , true);
          lbits zgsz3311;
          CREATE(lbits)(&zgsz3311);
          append(&zgsz3311, zgsz3309, zgsz3310);
          zgaz3145 = CONVERT_OF(fbits, lbits)(zgsz3311, true);
          KILL(lbits)(&zgsz3311);
          KILL(lbits)(&zgsz3310);
          KILL(lbits)(&zgsz3309);
        }
      
      
      }
      {
        lbits zgsz3312;
        CREATE(lbits)(&zgsz3312);
        CONVERT_OF(lbits, fbits)(&zgsz3312, zgaz3144, UINT64_C(12) , true);
        lbits zgsz3313;
        CREATE(lbits)(&zgsz3313);
        CONVERT_OF(lbits, fbits)(&zgsz3313, zgaz3145, UINT64_C(52) , true);
        lbits zgsz3314;
        CREATE(lbits)(&zgsz3314);
        append(&zgsz3314, zgsz3312, zgsz3313);
        zgaz3147 = CONVERT_OF(fbits, lbits)(zgsz3314, true);
        KILL(lbits)(&zgsz3314);
        KILL(lbits)(&zgsz3313);
        KILL(lbits)(&zgsz3312);
      }
    
    
    }
    {
      lbits zgsz3315;
      CREATE(lbits)(&zgsz3315);
      CONVERT_OF(lbits, fbits)(&zgsz3315, zgaz3146, UINT64_C(0) , true);
      lbits zgsz3316;
      CREATE(lbits)(&zgsz3316);
      CONVERT_OF(lbits, fbits)(&zgsz3316, zgaz3147, UINT64_C(64) , true);
      lbits zgsz3317;
      CREATE(lbits)(&zgsz3317);
      append(&zgsz3317, zgsz3315, zgsz3316);
      zgaz3148 = CONVERT_OF(fbits, lbits)(zgsz3317, true);
      KILL(lbits)(&zgsz3317);
      KILL(lbits)(&zgsz3316);
      KILL(lbits)(&zgsz3315);
    }
  
  
  }
  zcbz336 = zgaz3148;
  goto cleanup_143;
  /* unreachable after return */





  goto end_cleanup_144;
cleanup_143: ;





  goto end_function_142;
end_cleanup_144: ;
end_function_142: ;
  return zcbz336;
end_block_exception_145: ;

  return UINT64_C(0xdeadc0de);
}

uint64_t znull_cap_bits;
static void create_letbind_20(void) {  


  uint64_t zgsz3318;
  zgsz3318 = sailgen_capToBits(znull_cap);
  znull_cap_bits = zgsz3318;

let_end_146: ;
}
static void kill_letbind_20(void) {  
}

static uint64_t sailgen_capToMemBits(struct zCapability);

static uint64_t sailgen_capToMemBits(struct zCapability zcap)
{
  __label__ end_function_148, end_block_exception_149;

  uint64_t zcbz337;
  uint64_t zgaz3155;
  zgaz3155 = sailgen_capToBits(zcap);
  {
    lbits zgsz3319;
    CREATE(lbits)(&zgsz3319);
    CONVERT_OF(lbits, fbits)(&zgsz3319, zgaz3155, UINT64_C(64) , true);
    lbits zgsz3320;
    CREATE(lbits)(&zgsz3320);
    CONVERT_OF(lbits, fbits)(&zgsz3320, znull_cap_bits, UINT64_C(64) , true);
    lbits zgsz3321;
    CREATE(lbits)(&zgsz3321);
    xor_bits(&zgsz3321, zgsz3319, zgsz3320);
    zcbz337 = CONVERT_OF(fbits, lbits)(zgsz3321, true);
    KILL(lbits)(&zgsz3321);
    KILL(lbits)(&zgsz3320);
    KILL(lbits)(&zgsz3319);
  }

end_function_148: ;
  return zcbz337;
end_block_exception_149: ;

  return UINT64_C(0xdeadc0de);
}

static struct zCapability sailgen_memBitsToCapability(bool, uint64_t);

static struct zCapability sailgen_memBitsToCapability(bool ztag, uint64_t zb)
{
  __label__ end_function_151, end_block_exception_152;

  struct zCapability zcbz338;
  uint64_t zgaz3156;
  {
    lbits zgsz3322;
    CREATE(lbits)(&zgsz3322);
    CONVERT_OF(lbits, fbits)(&zgsz3322, zb, UINT64_C(64) , true);
    lbits zgsz3323;
    CREATE(lbits)(&zgsz3323);
    CONVERT_OF(lbits, fbits)(&zgsz3323, znull_cap_bits, UINT64_C(64) , true);
    lbits zgsz3324;
    CREATE(lbits)(&zgsz3324);
    xor_bits(&zgsz3324, zgsz3322, zgsz3323);
    zgaz3156 = CONVERT_OF(fbits, lbits)(zgsz3324, true);
    KILL(lbits)(&zgsz3324);
    KILL(lbits)(&zgsz3323);
    KILL(lbits)(&zgsz3322);
  }
  zcbz338 = sailgen_capBitsToCapability(ztag, zgaz3156);

end_function_151: ;
  return zcbz338;
end_block_exception_152: ;
  struct zCapability zcbz355 = { .zuperms = UINT64_C(0xdeadc0de), .ztag = false, .zsealed = false, .zreserved = UINT64_C(0xdeadc0de), .zpermit_unseal = false, .zpermit_store_local_cap = false, .zpermit_store_cap = false, .zpermit_store = false, .zpermit_set_CID = false, .zpermit_seal = false, .zpermit_load_cap = false, .zpermit_load = false, .zpermit_execute = false, .zpermit_ccall = false, .zotype = UINT64_C(0xdeadc0de), .zinternal_e = false, .zglobal = false, .zflag_cap_mode = false, .zaddress = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zT = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zB = UINT64_C(0xdeadc0de) };
  return zcbz355;
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
  __label__ case_155, finish_match_154, end_function_160, end_block_exception_161;

  struct ztuple_z8z5bv32zCz0z5bv33z9 zcbz339;
  int64_t zE;
  {
    int64_t zgaz3193;
    {
      uint64_t zgaz3192;
      zgaz3192 = zc.zE;
      zgaz3193 = ((mach_int) zgaz3192);
    
    }
    {
      sail_int zgsz3325;
      CREATE(sail_int)(&zgsz3325);
      CONVERT_OF(sail_int, mach_int)(&zgsz3325, zmaxE);
      sail_int zgsz3326;
      CREATE(sail_int)(&zgsz3326);
      CONVERT_OF(sail_int, mach_int)(&zgsz3326, zgaz3193);
      sail_int zgsz3327;
      CREATE(sail_int)(&zgsz3327);
      min_int(&zgsz3327, zgsz3325, zgsz3326);
      zE = CONVERT_OF(mach_int, sail_int)(zgsz3327);
      KILL(sail_int)(&zgsz3327);
      KILL(sail_int)(&zgsz3326);
      KILL(sail_int)(&zgsz3325);
    }
  
  }
  uint64_t zgaz3157;
  zgaz3157 = zc.zaddress;
  struct ztuple_z8z5bv32zCz0z5bv33z9 zgsz3328;
  {
    __label__ case_157, finish_match_156;

    uint64_t za;
    za = zgaz3157;
    uint64_t za3;
    {
      uint64_t zgaz3191;
      {
        int64_t zgaz3190;
        {
          int64_t zgaz3189;
          {
            sail_int zgsz3329;
            CREATE(sail_int)(&zgsz3329);
            CONVERT_OF(sail_int, mach_int)(&zgsz3329, zE);
            sail_int zgsz3330;
            CREATE(sail_int)(&zgsz3330);
            CONVERT_OF(sail_int, mach_int)(&zgsz3330, zmantissa_width);
            sail_int zgsz3331;
            CREATE(sail_int)(&zgsz3331);
            add_int(&zgsz3331, zgsz3329, zgsz3330);
            zgaz3189 = CONVERT_OF(mach_int, sail_int)(zgsz3331);
            KILL(sail_int)(&zgsz3331);
            KILL(sail_int)(&zgsz3330);
            KILL(sail_int)(&zgsz3329);
          }
          {
            sail_int zgsz3332;
            CREATE(sail_int)(&zgsz3332);
            CONVERT_OF(sail_int, mach_int)(&zgsz3332, zgaz3189);
            sail_int zgsz3333;
            CREATE(sail_int)(&zgsz3333);
            CONVERT_OF(sail_int, mach_int)(&zgsz3333, 3l);
            sail_int zgsz3334;
            CREATE(sail_int)(&zgsz3334);
            sub_int(&zgsz3334, zgsz3332, zgsz3333);
            zgaz3190 = CONVERT_OF(mach_int, sail_int)(zgsz3334);
            KILL(sail_int)(&zgsz3334);
            KILL(sail_int)(&zgsz3333);
            KILL(sail_int)(&zgsz3332);
          }
        
        }
        {
          lbits zgsz3335;
          CREATE(lbits)(&zgsz3335);
          CONVERT_OF(lbits, fbits)(&zgsz3335, za, UINT64_C(32) , true);
          sail_int zgsz3336;
          CREATE(sail_int)(&zgsz3336);
          CONVERT_OF(sail_int, mach_int)(&zgsz3336, zgaz3190);
          lbits zgsz3337;
          CREATE(lbits)(&zgsz3337);
          shiftr(&zgsz3337, zgsz3335, zgsz3336);
          zgaz3191 = CONVERT_OF(fbits, lbits)(zgsz3337, true);
          KILL(lbits)(&zgsz3337);
          KILL(sail_int)(&zgsz3336);
          KILL(lbits)(&zgsz3335);
        }
      
      }
      {
        lbits zgsz3338;
        CREATE(lbits)(&zgsz3338);
        CONVERT_OF(lbits, fbits)(&zgsz3338, zgaz3191, UINT64_C(32) , true);
        sail_int zgsz3339;
        CREATE(sail_int)(&zgsz3339);
        CONVERT_OF(sail_int, mach_int)(&zgsz3339, 3l);
        lbits zgsz3340;
        CREATE(lbits)(&zgsz3340);
        sail_truncate(&zgsz3340, zgsz3338, zgsz3339);
        za3 = CONVERT_OF(fbits, lbits)(zgsz3340, true);
        KILL(lbits)(&zgsz3340);
        KILL(sail_int)(&zgsz3339);
        KILL(lbits)(&zgsz3338);
      }
    
    }
    uint64_t zB3;
    {
      uint64_t zgaz3188;
      zgaz3188 = zc.zB;
      {
        lbits zgsz3341;
        CREATE(lbits)(&zgsz3341);
        CONVERT_OF(lbits, fbits)(&zgsz3341, zgaz3188, UINT64_C(8) , true);
        sail_int zgsz3342;
        CREATE(sail_int)(&zgsz3342);
        CONVERT_OF(sail_int, mach_int)(&zgsz3342, 3l);
        lbits zgsz3343;
        CREATE(lbits)(&zgsz3343);
        sail_truncateLSB(&zgsz3343, zgsz3341, zgsz3342);
        zB3 = CONVERT_OF(fbits, lbits)(zgsz3343, true);
        KILL(lbits)(&zgsz3343);
        KILL(sail_int)(&zgsz3342);
        KILL(lbits)(&zgsz3341);
      }
    
    }
    uint64_t zT3;
    {
      uint64_t zgaz3187;
      zgaz3187 = zc.zT;
      {
        lbits zgsz3344;
        CREATE(lbits)(&zgsz3344);
        CONVERT_OF(lbits, fbits)(&zgsz3344, zgaz3187, UINT64_C(8) , true);
        sail_int zgsz3345;
        CREATE(sail_int)(&zgsz3345);
        CONVERT_OF(sail_int, mach_int)(&zgsz3345, 3l);
        lbits zgsz3346;
        CREATE(lbits)(&zgsz3346);
        sail_truncateLSB(&zgsz3346, zgsz3344, zgsz3345);
        zT3 = CONVERT_OF(fbits, lbits)(zgsz3346, true);
        KILL(lbits)(&zgsz3346);
        KILL(sail_int)(&zgsz3345);
        KILL(lbits)(&zgsz3344);
      }
    
    }
    uint64_t zR3;
    {
      lbits zgsz3347;
      CREATE(lbits)(&zgsz3347);
      CONVERT_OF(lbits, fbits)(&zgsz3347, zB3, UINT64_C(3) , true);
      lbits zgsz3348;
      CREATE(lbits)(&zgsz3348);
      CONVERT_OF(lbits, fbits)(&zgsz3348, UINT64_C(0b001), UINT64_C(3) , true);
      lbits zgsz3349;
      CREATE(lbits)(&zgsz3349);
      sub_bits(&zgsz3349, zgsz3347, zgsz3348);
      zR3 = CONVERT_OF(fbits, lbits)(zgsz3349, true);
      KILL(lbits)(&zgsz3349);
      KILL(lbits)(&zgsz3348);
      KILL(lbits)(&zgsz3347);
    }
    int64_t zaHi;
    {
      bool zgaz3186;
      zgaz3186 = sailgen_z8operatorz0zzzz7nzzJzzK3z3zI_uz9(za3, zR3);
      if (zgaz3186) {  zaHi = 1l;  } else {  zaHi = 0l;  }
    
    }
    int64_t zbHi;
    {
      bool zgaz3185;
      zgaz3185 = sailgen_z8operatorz0zzzz7nzzJzzK3z3zI_uz9(zB3, zR3);
      if (zgaz3185) {  zbHi = 1l;  } else {  zbHi = 0l;  }
    
    }
    int64_t ztHi;
    {
      bool zgaz3184;
      zgaz3184 = sailgen_z8operatorz0zzzz7nzzJzzK3z3zI_uz9(zT3, zR3);
      if (zgaz3184) {  ztHi = 1l;  } else {  ztHi = 0l;  }
    
    }
    int64_t zcorrection_base;
    {
      sail_int zgsz3350;
      CREATE(sail_int)(&zgsz3350);
      CONVERT_OF(sail_int, mach_int)(&zgsz3350, zbHi);
      sail_int zgsz3351;
      CREATE(sail_int)(&zgsz3351);
      CONVERT_OF(sail_int, mach_int)(&zgsz3351, zaHi);
      sail_int zgsz3352;
      CREATE(sail_int)(&zgsz3352);
      sub_int(&zgsz3352, zgsz3350, zgsz3351);
      zcorrection_base = CONVERT_OF(mach_int, sail_int)(zgsz3352);
      KILL(sail_int)(&zgsz3352);
      KILL(sail_int)(&zgsz3351);
      KILL(sail_int)(&zgsz3350);
    }
    int64_t zcorrection_top;
    {
      sail_int zgsz3353;
      CREATE(sail_int)(&zgsz3353);
      CONVERT_OF(sail_int, mach_int)(&zgsz3353, ztHi);
      sail_int zgsz3354;
      CREATE(sail_int)(&zgsz3354);
      CONVERT_OF(sail_int, mach_int)(&zgsz3354, zaHi);
      sail_int zgsz3355;
      CREATE(sail_int)(&zgsz3355);
      sub_int(&zgsz3355, zgsz3353, zgsz3354);
      zcorrection_top = CONVERT_OF(mach_int, sail_int)(zgsz3355);
      KILL(sail_int)(&zgsz3355);
      KILL(sail_int)(&zgsz3354);
      KILL(sail_int)(&zgsz3353);
    }
    uint64_t za_top;
    {
      int64_t zgaz3183;
      {
        sail_int zgsz3356;
        CREATE(sail_int)(&zgsz3356);
        CONVERT_OF(sail_int, mach_int)(&zgsz3356, zE);
        sail_int zgsz3357;
        CREATE(sail_int)(&zgsz3357);
        CONVERT_OF(sail_int, mach_int)(&zgsz3357, zmantissa_width);
        sail_int zgsz3358;
        CREATE(sail_int)(&zgsz3358);
        add_int(&zgsz3358, zgsz3356, zgsz3357);
        zgaz3183 = CONVERT_OF(mach_int, sail_int)(zgsz3358);
        KILL(sail_int)(&zgsz3358);
        KILL(sail_int)(&zgsz3357);
        KILL(sail_int)(&zgsz3356);
      }
      {
        lbits zgsz3359;
        CREATE(lbits)(&zgsz3359);
        CONVERT_OF(lbits, fbits)(&zgsz3359, za, UINT64_C(32) , true);
        sail_int zgsz3360;
        CREATE(sail_int)(&zgsz3360);
        CONVERT_OF(sail_int, mach_int)(&zgsz3360, zgaz3183);
        lbits zgsz3361;
        CREATE(lbits)(&zgsz3361);
        shiftr(&zgsz3361, zgsz3359, zgsz3360);
        za_top = CONVERT_OF(fbits, lbits)(zgsz3361, true);
        KILL(lbits)(&zgsz3361);
        KILL(sail_int)(&zgsz3360);
        KILL(lbits)(&zgsz3359);
      }
    
    }
    uint64_t zbase;
    {
      lbits zgaz3182;
      CREATE(lbits)(&zgaz3182);
      {
        uint64_t zgaz3180;
        {
          lbits zgsz3362;
          CREATE(lbits)(&zgsz3362);
          CONVERT_OF(lbits, fbits)(&zgsz3362, za_top, UINT64_C(32) , true);
          sail_int zgsz3363;
          CREATE(sail_int)(&zgsz3363);
          CONVERT_OF(sail_int, mach_int)(&zgsz3363, zcorrection_base);
          lbits zgsz3364;
          CREATE(lbits)(&zgsz3364);
          add_bits_int(&zgsz3364, zgsz3362, zgsz3363);
          zgaz3180 = CONVERT_OF(fbits, lbits)(zgsz3364, true);
          KILL(lbits)(&zgsz3364);
          KILL(sail_int)(&zgsz3363);
          KILL(lbits)(&zgsz3362);
        }
        sbits zgaz3181;
        {
          uint64_t zgaz3178;
          zgaz3178 = zc.zB;
          sbits zgaz3179;
          {
            sail_int zgsz3365;
            CREATE(sail_int)(&zgsz3365);
            CONVERT_OF(sail_int, mach_int)(&zgsz3365, zE);
            lbits zgsz3366;
            CREATE(lbits)(&zgsz3366);
            sailgen_zzz3zzz3zzeros_implicit(&zgsz3366, zgsz3365);
            zgaz3179 = CONVERT_OF(sbits, lbits)(zgsz3366, true);
            KILL(lbits)(&zgsz3366);
            KILL(sail_int)(&zgsz3365);
          }
          {
            lbits zgsz3367;
            CREATE(lbits)(&zgsz3367);
            CONVERT_OF(lbits, fbits)(&zgsz3367, zgaz3178, UINT64_C(8) , true);
            lbits zgsz3368;
            CREATE(lbits)(&zgsz3368);
            CONVERT_OF(lbits, sbits)(&zgsz3368, zgaz3179, true);
            lbits zgsz3369;
            CREATE(lbits)(&zgsz3369);
            append(&zgsz3369, zgsz3367, zgsz3368);
            zgaz3181 = CONVERT_OF(sbits, lbits)(zgsz3369, true);
            KILL(lbits)(&zgsz3369);
            KILL(lbits)(&zgsz3368);
            KILL(lbits)(&zgsz3367);
          }
        
        
        }
        {
          lbits zgsz3371;
          CREATE(lbits)(&zgsz3371);
          CONVERT_OF(lbits, sbits)(&zgsz3371, zgaz3181, true);
          lbits zgsz3370;
          CREATE(lbits)(&zgsz3370);
          CONVERT_OF(lbits, fbits)(&zgsz3370, zgaz3180, UINT64_C(32) , true);
          append(&zgaz3182, zgsz3370, zgsz3371);
          KILL(lbits)(&zgsz3371);
          KILL(lbits)(&zgsz3370);
        }
      
      
      }
      {
        sail_int zgsz3372;
        CREATE(sail_int)(&zgsz3372);
        CONVERT_OF(sail_int, mach_int)(&zgsz3372, zcap_len_width);
        lbits zgsz3373;
        CREATE(lbits)(&zgsz3373);
        sail_truncate(&zgsz3373, zgaz3182, zgsz3372);
        zbase = CONVERT_OF(fbits, lbits)(zgsz3373, true);
        KILL(lbits)(&zgsz3373);
        KILL(sail_int)(&zgsz3372);
      }
      KILL(lbits)(&zgaz3182);
    }
    uint64_t ztop;
    {
      lbits zgaz3177;
      CREATE(lbits)(&zgaz3177);
      {
        uint64_t zgaz3175;
        {
          lbits zgsz3374;
          CREATE(lbits)(&zgsz3374);
          CONVERT_OF(lbits, fbits)(&zgsz3374, za_top, UINT64_C(32) , true);
          sail_int zgsz3375;
          CREATE(sail_int)(&zgsz3375);
          CONVERT_OF(sail_int, mach_int)(&zgsz3375, zcorrection_top);
          lbits zgsz3376;
          CREATE(lbits)(&zgsz3376);
          add_bits_int(&zgsz3376, zgsz3374, zgsz3375);
          zgaz3175 = CONVERT_OF(fbits, lbits)(zgsz3376, true);
          KILL(lbits)(&zgsz3376);
          KILL(sail_int)(&zgsz3375);
          KILL(lbits)(&zgsz3374);
        }
        sbits zgaz3176;
        {
          uint64_t zgaz3173;
          zgaz3173 = zc.zT;
          sbits zgaz3174;
          {
            sail_int zgsz3377;
            CREATE(sail_int)(&zgsz3377);
            CONVERT_OF(sail_int, mach_int)(&zgsz3377, zE);
            lbits zgsz3378;
            CREATE(lbits)(&zgsz3378);
            sailgen_zzz3zzz3zzeros_implicit(&zgsz3378, zgsz3377);
            zgaz3174 = CONVERT_OF(sbits, lbits)(zgsz3378, true);
            KILL(lbits)(&zgsz3378);
            KILL(sail_int)(&zgsz3377);
          }
          {
            lbits zgsz3379;
            CREATE(lbits)(&zgsz3379);
            CONVERT_OF(lbits, fbits)(&zgsz3379, zgaz3173, UINT64_C(8) , true);
            lbits zgsz3380;
            CREATE(lbits)(&zgsz3380);
            CONVERT_OF(lbits, sbits)(&zgsz3380, zgaz3174, true);
            lbits zgsz3381;
            CREATE(lbits)(&zgsz3381);
            append(&zgsz3381, zgsz3379, zgsz3380);
            zgaz3176 = CONVERT_OF(sbits, lbits)(zgsz3381, true);
            KILL(lbits)(&zgsz3381);
            KILL(lbits)(&zgsz3380);
            KILL(lbits)(&zgsz3379);
          }
        
        
        }
        {
          lbits zgsz3383;
          CREATE(lbits)(&zgsz3383);
          CONVERT_OF(lbits, sbits)(&zgsz3383, zgaz3176, true);
          lbits zgsz3382;
          CREATE(lbits)(&zgsz3382);
          CONVERT_OF(lbits, fbits)(&zgsz3382, zgaz3175, UINT64_C(32) , true);
          append(&zgaz3177, zgsz3382, zgsz3383);
          KILL(lbits)(&zgsz3383);
          KILL(lbits)(&zgsz3382);
        }
      
      
      }
      {
        sail_int zgsz3384;
        CREATE(sail_int)(&zgsz3384);
        CONVERT_OF(sail_int, mach_int)(&zgsz3384, zcap_len_width);
        lbits zgsz3385;
        CREATE(lbits)(&zgsz3385);
        sail_truncate(&zgsz3385, zgaz3177, zgsz3384);
        ztop = CONVERT_OF(fbits, lbits)(zgsz3385, true);
        KILL(lbits)(&zgsz3385);
        KILL(sail_int)(&zgsz3384);
      }
      KILL(lbits)(&zgaz3177);
    }
    uint64_t zgaz3161;
    {
      uint64_t zgaz3160;
      {
        fbits zgaz3159;
        {
          int64_t zgaz3158;
          {
            sail_int zgsz3386;
            CREATE(sail_int)(&zgsz3386);
            CONVERT_OF(sail_int, mach_int)(&zgsz3386, zcap_addr_width);
            sail_int zgsz3387;
            CREATE(sail_int)(&zgsz3387);
            CONVERT_OF(sail_int, mach_int)(&zgsz3387, 1l);
            sail_int zgsz3388;
            CREATE(sail_int)(&zgsz3388);
            sub_int(&zgsz3388, zgsz3386, zgsz3387);
            zgaz3158 = CONVERT_OF(mach_int, sail_int)(zgsz3388);
            KILL(sail_int)(&zgsz3388);
            KILL(sail_int)(&zgsz3387);
            KILL(sail_int)(&zgsz3386);
          }
          {
            sail_int zgsz3390;
            CREATE(sail_int)(&zgsz3390);
            CONVERT_OF(sail_int, mach_int)(&zgsz3390, zgaz3158);
            lbits zgsz3389;
            CREATE(lbits)(&zgsz3389);
            CONVERT_OF(lbits, fbits)(&zgsz3389, zbase, UINT64_C(33) , true);
            zgaz3159 = bitvector_access(zgsz3389, zgsz3390);
            KILL(sail_int)(&zgsz3390);
            KILL(lbits)(&zgsz3389);
          }
        
        }
        uint64_t zgsz3391;
        zgsz3391 = UINT64_C(0b0);
        zgsz3391 = update_fbits(zgsz3391, 0l, zgaz3159);
        zgaz3160 = zgsz3391;
      
      }
      {
        lbits zgsz3392;
        CREATE(lbits)(&zgsz3392);
        CONVERT_OF(lbits, fbits)(&zgsz3392, UINT64_C(0b0), UINT64_C(1) , true);
        lbits zgsz3393;
        CREATE(lbits)(&zgsz3393);
        CONVERT_OF(lbits, fbits)(&zgsz3393, zgaz3160, UINT64_C(1) , true);
        lbits zgsz3394;
        CREATE(lbits)(&zgsz3394);
        append(&zgsz3394, zgsz3392, zgsz3393);
        zgaz3161 = CONVERT_OF(fbits, lbits)(zgsz3394, true);
        KILL(lbits)(&zgsz3394);
        KILL(lbits)(&zgsz3393);
        KILL(lbits)(&zgsz3392);
      }
    
    }
    struct ztuple_z8z5bv32zCz0z5bv33z9 zgsz3395;
    {
      __label__ case_159, finish_match_158;

      uint64_t zbase2;
      zbase2 = zgaz3161;
      uint64_t zgaz3163;
      {
        int64_t zgaz3162;
        {
          sail_int zgsz3396;
          CREATE(sail_int)(&zgsz3396);
          CONVERT_OF(sail_int, mach_int)(&zgsz3396, zcap_addr_width);
          sail_int zgsz3397;
          CREATE(sail_int)(&zgsz3397);
          CONVERT_OF(sail_int, mach_int)(&zgsz3397, 1l);
          sail_int zgsz3398;
          CREATE(sail_int)(&zgsz3398);
          sub_int(&zgsz3398, zgsz3396, zgsz3397);
          zgaz3162 = CONVERT_OF(mach_int, sail_int)(zgsz3398);
          KILL(sail_int)(&zgsz3398);
          KILL(sail_int)(&zgsz3397);
          KILL(sail_int)(&zgsz3396);
        }
        {
          lbits zgsz3399;
          CREATE(lbits)(&zgsz3399);
          CONVERT_OF(lbits, fbits)(&zgsz3399, ztop, UINT64_C(33) , true);
          sail_int zgsz3400;
          CREATE(sail_int)(&zgsz3400);
          CONVERT_OF(sail_int, mach_int)(&zgsz3400, zcap_addr_width);
          sail_int zgsz3401;
          CREATE(sail_int)(&zgsz3401);
          CONVERT_OF(sail_int, mach_int)(&zgsz3401, zgaz3162);
          lbits zgsz3402;
          CREATE(lbits)(&zgsz3402);
          vector_subrange_lbits(&zgsz3402, zgsz3399, zgsz3400, zgsz3401);
          zgaz3163 = CONVERT_OF(fbits, lbits)(zgsz3402, true);
          KILL(lbits)(&zgsz3402);
          KILL(sail_int)(&zgsz3401);
          KILL(sail_int)(&zgsz3400);
          KILL(lbits)(&zgsz3399);
        }
      
      }
      struct ztuple_z8z5bv32zCz0z5bv33z9 zgsz3403;
      {
        uint64_t ztop2;
        ztop2 = zgaz3163;
        {
          bool zgaz3168;
          {
            bool zgaz3167;
            {
              int64_t zgaz3164;
              {
                sail_int zgsz3404;
                CREATE(sail_int)(&zgsz3404);
                CONVERT_OF(sail_int, mach_int)(&zgsz3404, zmaxE);
                sail_int zgsz3405;
                CREATE(sail_int)(&zgsz3405);
                CONVERT_OF(sail_int, mach_int)(&zgsz3405, 1l);
                sail_int zgsz3406;
                CREATE(sail_int)(&zgsz3406);
                sub_int(&zgsz3406, zgsz3404, zgsz3405);
                zgaz3164 = CONVERT_OF(mach_int, sail_int)(zgsz3406);
                KILL(sail_int)(&zgsz3406);
                KILL(sail_int)(&zgsz3405);
                KILL(sail_int)(&zgsz3404);
              }
              {
                sail_int zgsz3408;
                CREATE(sail_int)(&zgsz3408);
                CONVERT_OF(sail_int, mach_int)(&zgsz3408, zgaz3164);
                sail_int zgsz3407;
                CREATE(sail_int)(&zgsz3407);
                CONVERT_OF(sail_int, mach_int)(&zgsz3407, zE);
                zgaz3167 = lt(zgsz3407, zgsz3408);
                KILL(sail_int)(&zgsz3408);
                KILL(sail_int)(&zgsz3407);
              }
            
            }
            bool zgsz3412;
            if (zgaz3167) {
            int64_t zgaz3166;
            {
              uint64_t zgaz3165;
              {
                lbits zgsz3409;
                CREATE(lbits)(&zgsz3409);
                CONVERT_OF(lbits, fbits)(&zgsz3409, ztop2, UINT64_C(2) , true);
                lbits zgsz3410;
                CREATE(lbits)(&zgsz3410);
                CONVERT_OF(lbits, fbits)(&zgsz3410, zbase2, UINT64_C(2) , true);
                lbits zgsz3411;
                CREATE(lbits)(&zgsz3411);
                sub_bits(&zgsz3411, zgsz3409, zgsz3410);
                zgaz3165 = CONVERT_OF(fbits, lbits)(zgsz3411, true);
                KILL(lbits)(&zgsz3411);
                KILL(lbits)(&zgsz3410);
                KILL(lbits)(&zgsz3409);
              }
              zgaz3166 = ((mach_int) zgaz3165);
            
            }
            {
              sail_int zgsz3414;
              CREATE(sail_int)(&zgsz3414);
              CONVERT_OF(sail_int, mach_int)(&zgsz3414, 1l);
              sail_int zgsz3413;
              CREATE(sail_int)(&zgsz3413);
              CONVERT_OF(sail_int, mach_int)(&zgsz3413, zgaz3166);
              zgsz3412 = gt(zgsz3413, zgsz3414);
              KILL(sail_int)(&zgsz3414);
              KILL(sail_int)(&zgsz3413);
            }
          
            } else {  zgsz3412 = false;  }
            zgaz3168 = zgsz3412;
          
          }
          unit zgsz3415;
          if (zgaz3168) {
          fbits zgaz3170;
          {
            fbits zgaz3169;
            {
              sail_int zgsz3417;
              CREATE(sail_int)(&zgsz3417);
              CONVERT_OF(sail_int, mach_int)(&zgsz3417, zcap_addr_width);
              lbits zgsz3416;
              CREATE(lbits)(&zgsz3416);
              CONVERT_OF(lbits, fbits)(&zgsz3416, ztop, UINT64_C(33) , true);
              zgaz3169 = bitvector_access(zgsz3416, zgsz3417);
              KILL(sail_int)(&zgsz3417);
              KILL(lbits)(&zgsz3416);
            }
            zgaz3170 = sailgen_not_bit(zgaz3169);
          
          }
          {
            lbits zgsz3418;
            CREATE(lbits)(&zgsz3418);
            CONVERT_OF(lbits, fbits)(&zgsz3418, ztop, UINT64_C(33) , true);
            sail_int zgsz3419;
            CREATE(sail_int)(&zgsz3419);
            CONVERT_OF(sail_int, mach_int)(&zgsz3419, zcap_addr_width);
            lbits zgsz3420;
            CREATE(lbits)(&zgsz3420);
            update_lbits(&zgsz3420, zgsz3418, zgsz3419, zgaz3170);
            ztop = CONVERT_OF(fbits, lbits)(zgsz3420, true);
            KILL(lbits)(&zgsz3420);
            KILL(sail_int)(&zgsz3419);
            KILL(lbits)(&zgsz3418);
          }
          zgsz3415 = UNIT;
        
          } else {  zgsz3415 = UNIT;  }
        
        }
        uint64_t zgaz3172;
        {
          int64_t zgaz3171;
          {
            sail_int zgsz3421;
            CREATE(sail_int)(&zgsz3421);
            CONVERT_OF(sail_int, mach_int)(&zgsz3421, zcap_addr_width);
            sail_int zgsz3422;
            CREATE(sail_int)(&zgsz3422);
            CONVERT_OF(sail_int, mach_int)(&zgsz3422, 1l);
            sail_int zgsz3423;
            CREATE(sail_int)(&zgsz3423);
            sub_int(&zgsz3423, zgsz3421, zgsz3422);
            zgaz3171 = CONVERT_OF(mach_int, sail_int)(zgsz3423);
            KILL(sail_int)(&zgsz3423);
            KILL(sail_int)(&zgsz3422);
            KILL(sail_int)(&zgsz3421);
          }
          {
            lbits zgsz3424;
            CREATE(lbits)(&zgsz3424);
            CONVERT_OF(lbits, fbits)(&zgsz3424, zbase, UINT64_C(33) , true);
            sail_int zgsz3425;
            CREATE(sail_int)(&zgsz3425);
            CONVERT_OF(sail_int, mach_int)(&zgsz3425, zgaz3171);
            sail_int zgsz3426;
            CREATE(sail_int)(&zgsz3426);
            CONVERT_OF(sail_int, mach_int)(&zgsz3426, 0l);
            lbits zgsz3427;
            CREATE(lbits)(&zgsz3427);
            vector_subrange_lbits(&zgsz3427, zgsz3424, zgsz3425, zgsz3426);
            zgaz3172 = CONVERT_OF(fbits, lbits)(zgsz3427, true);
            KILL(lbits)(&zgsz3427);
            KILL(sail_int)(&zgsz3426);
            KILL(sail_int)(&zgsz3425);
            KILL(lbits)(&zgsz3424);
          }
        
        }
        struct ztuple_z8z5bv32zCz0z5bv33z9 zgsz3428;
        zgsz3428.ztup0 = zgaz3172;
        zgsz3428.ztup1 = ztop;
        zgsz3403 = zgsz3428;
      
      
      
        goto finish_match_158;
      }
    case_159: ;
      sail_match_failure("getCapBoundsBits");
    finish_match_158: ;
      zgsz3395 = zgsz3403;
    
    
    
      goto finish_match_156;
    }
  case_157: ;
    sail_match_failure("getCapBoundsBits");
  finish_match_156: ;
    zgsz3328 = zgsz3395;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
    goto finish_match_154;
  }
case_155: ;
  sail_match_failure("getCapBoundsBits");
finish_match_154: ;
  zcbz339 = zgsz3328;



end_function_160: ;
  return zcbz339;
end_block_exception_161: ;
  struct ztuple_z8z5bv32zCz0z5bv33z9 zcbz356 = { .ztup1 = UINT64_C(0xdeadc0de), .ztup0 = UINT64_C(0xdeadc0de) };
  return zcbz356;
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
  __label__ case_164, finish_match_163, end_function_165, end_block_exception_166;

  struct ztuple_z8z5i64zCz0z5i64z9 zcbz340;
  struct ztuple_z8z5bv32zCz0z5bv33z9 zgaz3194;
  zgaz3194 = sailgen_getCapBoundsBits(zcap);
  struct ztuple_z8z5i64zCz0z5i64z9 zgsz3432;
  {
    uint64_t zbase;
    zbase = zgaz3194.ztup0;
    uint64_t ztop;
    ztop = zgaz3194.ztup1;
    int64_t zgaz3195;
    zgaz3195 = ((mach_int) zbase);
    int64_t zgaz3196;
    zgaz3196 = ((mach_int) ztop);
    struct ztuple_z8z5i64zCz0z5i64z9 zgsz3433;
    zgsz3433.ztup0 = zgaz3195;
    zgsz3433.ztup1 = zgaz3196;
    zgsz3432 = zgsz3433;
  
  
  
  
  
    goto finish_match_163;
  }
case_164: ;
  sail_match_failure("getCapBounds");
finish_match_163: ;
  zcbz340 = zgsz3432;


end_function_165: ;
  return zcbz340;
end_block_exception_166: ;
  struct ztuple_z8z5i64zCz0z5i64z9 zcbz357 = { .ztup1 = INT64_C(0xdeadc0de), .ztup0 = INT64_C(0xdeadc0de) };
  return zcbz357;
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
  __label__ end_function_170, end_block_exception_171;

  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz341;
  uint64_t zext_base;
  {
    lbits zgsz3435;
    CREATE(lbits)(&zgsz3435);
    CONVERT_OF(lbits, fbits)(&zgsz3435, UINT64_C(0b0), UINT64_C(1) , true);
    lbits zgsz3436;
    CREATE(lbits)(&zgsz3436);
    CONVERT_OF(lbits, fbits)(&zgsz3436, zbase, UINT64_C(32) , true);
    lbits zgsz3437;
    CREATE(lbits)(&zgsz3437);
    append(&zgsz3437, zgsz3435, zgsz3436);
    zext_base = CONVERT_OF(fbits, lbits)(zgsz3437, true);
    KILL(lbits)(&zgsz3437);
    KILL(lbits)(&zgsz3436);
    KILL(lbits)(&zgsz3435);
  }
  uint64_t zlength;
  {
    lbits zgsz3438;
    CREATE(lbits)(&zgsz3438);
    CONVERT_OF(lbits, fbits)(&zgsz3438, ztop, UINT64_C(33) , true);
    lbits zgsz3439;
    CREATE(lbits)(&zgsz3439);
    CONVERT_OF(lbits, fbits)(&zgsz3439, zext_base, UINT64_C(33) , true);
    lbits zgsz3440;
    CREATE(lbits)(&zgsz3440);
    sub_bits(&zgsz3440, zgsz3438, zgsz3439);
    zlength = CONVERT_OF(fbits, lbits)(zgsz3440, true);
    KILL(lbits)(&zgsz3440);
    KILL(lbits)(&zgsz3439);
    KILL(lbits)(&zgsz3438);
  }
  int64_t ze;
  {
    int64_t zgaz3231;
    {
      uint64_t zgaz3230;
      {
        int64_t zgaz3229;
        {
          sail_int zgsz3441;
          CREATE(sail_int)(&zgsz3441);
          CONVERT_OF(sail_int, mach_int)(&zgsz3441, zmantissa_width);
          sail_int zgsz3442;
          CREATE(sail_int)(&zgsz3442);
          CONVERT_OF(sail_int, mach_int)(&zgsz3442, 1l);
          sail_int zgsz3443;
          CREATE(sail_int)(&zgsz3443);
          sub_int(&zgsz3443, zgsz3441, zgsz3442);
          zgaz3229 = CONVERT_OF(mach_int, sail_int)(zgsz3443);
          KILL(sail_int)(&zgsz3443);
          KILL(sail_int)(&zgsz3442);
          KILL(sail_int)(&zgsz3441);
        }
        {
          lbits zgsz3444;
          CREATE(lbits)(&zgsz3444);
          CONVERT_OF(lbits, fbits)(&zgsz3444, zlength, UINT64_C(33) , true);
          sail_int zgsz3445;
          CREATE(sail_int)(&zgsz3445);
          CONVERT_OF(sail_int, mach_int)(&zgsz3445, zcap_addr_width);
          sail_int zgsz3446;
          CREATE(sail_int)(&zgsz3446);
          CONVERT_OF(sail_int, mach_int)(&zgsz3446, zgaz3229);
          lbits zgsz3447;
          CREATE(lbits)(&zgsz3447);
          vector_subrange_lbits(&zgsz3447, zgsz3444, zgsz3445, zgsz3446);
          zgaz3230 = CONVERT_OF(fbits, lbits)(zgsz3447, true);
          KILL(lbits)(&zgsz3447);
          KILL(sail_int)(&zgsz3446);
          KILL(sail_int)(&zgsz3445);
          KILL(lbits)(&zgsz3444);
        }
      
      }
      {
        lbits zgsz3448;
        CREATE(lbits)(&zgsz3448);
        CONVERT_OF(lbits, fbits)(&zgsz3448, zgaz3230, UINT64_C(26) , true);
        sail_int zgsz3449;
        CREATE(sail_int)(&zgsz3449);
        count_leading_zeros(&zgsz3449, zgsz3448);
        zgaz3231 = CONVERT_OF(mach_int, sail_int)(zgsz3449);
        KILL(sail_int)(&zgsz3449);
        KILL(lbits)(&zgsz3448);
      }
    
    }
    {
      sail_int zgsz3450;
      CREATE(sail_int)(&zgsz3450);
      CONVERT_OF(sail_int, mach_int)(&zgsz3450, zmaxE);
      sail_int zgsz3451;
      CREATE(sail_int)(&zgsz3451);
      CONVERT_OF(sail_int, mach_int)(&zgsz3451, zgaz3231);
      sail_int zgsz3452;
      CREATE(sail_int)(&zgsz3452);
      sub_int(&zgsz3452, zgsz3450, zgsz3451);
      ze = CONVERT_OF(mach_int, sail_int)(zgsz3452);
      KILL(sail_int)(&zgsz3452);
      KILL(sail_int)(&zgsz3451);
      KILL(sail_int)(&zgsz3450);
    }
  
  }
  bool zie;
  {
    bool zgaz3228;
    {
      sail_int zgsz3453;
      CREATE(sail_int)(&zgsz3453);
      CONVERT_OF(sail_int, mach_int)(&zgsz3453, ze);
      zgaz3228 = sailgen_zzz3zzzz7mzzJzzK0z3neq_int(zgsz3453, 0l);
      KILL(sail_int)(&zgsz3453);
    }
    bool zgsz3459;
    if (zgaz3228) {  zgsz3459 = true;  } else {
    fbits zgaz3227;
    {
      int64_t zgaz3226;
      {
        sail_int zgsz3454;
        CREATE(sail_int)(&zgsz3454);
        CONVERT_OF(sail_int, mach_int)(&zgsz3454, zmantissa_width);
        sail_int zgsz3455;
        CREATE(sail_int)(&zgsz3455);
        CONVERT_OF(sail_int, mach_int)(&zgsz3455, 2l);
        sail_int zgsz3456;
        CREATE(sail_int)(&zgsz3456);
        sub_int(&zgsz3456, zgsz3454, zgsz3455);
        zgaz3226 = CONVERT_OF(mach_int, sail_int)(zgsz3456);
        KILL(sail_int)(&zgsz3456);
        KILL(sail_int)(&zgsz3455);
        KILL(sail_int)(&zgsz3454);
      }
      {
        sail_int zgsz3458;
        CREATE(sail_int)(&zgsz3458);
        CONVERT_OF(sail_int, mach_int)(&zgsz3458, zgaz3226);
        lbits zgsz3457;
        CREATE(lbits)(&zgsz3457);
        CONVERT_OF(lbits, fbits)(&zgsz3457, zlength, UINT64_C(33) , true);
        zgaz3227 = bitvector_access(zgsz3457, zgsz3458);
        KILL(sail_int)(&zgsz3458);
        KILL(lbits)(&zgsz3457);
      }
    
    }
    zgsz3459 = eq_bit(zgaz3227, UINT64_C(1));
  
    }
    zie = zgsz3459;
  
  }
  uint64_t zBbits;
  {
    lbits zgsz3460;
    CREATE(lbits)(&zgsz3460);
    CONVERT_OF(lbits, fbits)(&zgsz3460, zbase, UINT64_C(32) , true);
    sail_int zgsz3461;
    CREATE(sail_int)(&zgsz3461);
    CONVERT_OF(sail_int, mach_int)(&zgsz3461, zmantissa_width);
    lbits zgsz3462;
    CREATE(lbits)(&zgsz3462);
    sail_truncate(&zgsz3462, zgsz3460, zgsz3461);
    zBbits = CONVERT_OF(fbits, lbits)(zgsz3462, true);
    KILL(lbits)(&zgsz3462);
    KILL(sail_int)(&zgsz3461);
    KILL(lbits)(&zgsz3460);
  }
  uint64_t zTbits;
  {
    lbits zgsz3463;
    CREATE(lbits)(&zgsz3463);
    CONVERT_OF(lbits, fbits)(&zgsz3463, ztop, UINT64_C(33) , true);
    sail_int zgsz3464;
    CREATE(sail_int)(&zgsz3464);
    CONVERT_OF(sail_int, mach_int)(&zgsz3464, zmantissa_width);
    lbits zgsz3465;
    CREATE(lbits)(&zgsz3465);
    sail_truncate(&zgsz3465, zgsz3463, zgsz3464);
    zTbits = CONVERT_OF(fbits, lbits)(zgsz3465, true);
    KILL(lbits)(&zgsz3465);
    KILL(sail_int)(&zgsz3464);
    KILL(lbits)(&zgsz3463);
  }
  bool zlostSignificantTop;
  zlostSignificantTop = false;
  bool zlostSignificantBase;
  zlostSignificantBase = false;
  bool zincE;
  zincE = false;
  {
    unit zgsz3466;
    if (zie) {
    uint64_t zB_ie;
    {
      uint64_t zgaz3221;
      {
        int64_t zgaz3220;
        {
          sail_int zgsz3467;
          CREATE(sail_int)(&zgsz3467);
          CONVERT_OF(sail_int, mach_int)(&zgsz3467, ze);
          sail_int zgsz3468;
          CREATE(sail_int)(&zgsz3468);
          CONVERT_OF(sail_int, mach_int)(&zgsz3468, 3l);
          sail_int zgsz3469;
          CREATE(sail_int)(&zgsz3469);
          add_int(&zgsz3469, zgsz3467, zgsz3468);
          zgaz3220 = CONVERT_OF(mach_int, sail_int)(zgsz3469);
          KILL(sail_int)(&zgsz3469);
          KILL(sail_int)(&zgsz3468);
          KILL(sail_int)(&zgsz3467);
        }
        {
          lbits zgsz3470;
          CREATE(lbits)(&zgsz3470);
          CONVERT_OF(lbits, fbits)(&zgsz3470, zbase, UINT64_C(32) , true);
          sail_int zgsz3471;
          CREATE(sail_int)(&zgsz3471);
          CONVERT_OF(sail_int, mach_int)(&zgsz3471, zgaz3220);
          lbits zgsz3472;
          CREATE(lbits)(&zgsz3472);
          shiftr(&zgsz3472, zgsz3470, zgsz3471);
          zgaz3221 = CONVERT_OF(fbits, lbits)(zgsz3472, true);
          KILL(lbits)(&zgsz3472);
          KILL(sail_int)(&zgsz3471);
          KILL(lbits)(&zgsz3470);
        }
      
      }
      int64_t zgaz3222;
      {
        sail_int zgsz3473;
        CREATE(sail_int)(&zgsz3473);
        CONVERT_OF(sail_int, mach_int)(&zgsz3473, zmantissa_width);
        sail_int zgsz3474;
        CREATE(sail_int)(&zgsz3474);
        CONVERT_OF(sail_int, mach_int)(&zgsz3474, 3l);
        sail_int zgsz3475;
        CREATE(sail_int)(&zgsz3475);
        sub_int(&zgsz3475, zgsz3473, zgsz3474);
        zgaz3222 = CONVERT_OF(mach_int, sail_int)(zgsz3475);
        KILL(sail_int)(&zgsz3475);
        KILL(sail_int)(&zgsz3474);
        KILL(sail_int)(&zgsz3473);
      }
      {
        lbits zgsz3476;
        CREATE(lbits)(&zgsz3476);
        CONVERT_OF(lbits, fbits)(&zgsz3476, zgaz3221, UINT64_C(32) , true);
        sail_int zgsz3477;
        CREATE(sail_int)(&zgsz3477);
        CONVERT_OF(sail_int, mach_int)(&zgsz3477, zgaz3222);
        lbits zgsz3478;
        CREATE(lbits)(&zgsz3478);
        sail_truncate(&zgsz3478, zgsz3476, zgsz3477);
        zB_ie = CONVERT_OF(fbits, lbits)(zgsz3478, true);
        KILL(lbits)(&zgsz3478);
        KILL(sail_int)(&zgsz3477);
        KILL(lbits)(&zgsz3476);
      }
    
    
    }
    uint64_t zT_ie;
    {
      uint64_t zgaz3218;
      {
        int64_t zgaz3217;
        {
          sail_int zgsz3479;
          CREATE(sail_int)(&zgsz3479);
          CONVERT_OF(sail_int, mach_int)(&zgsz3479, ze);
          sail_int zgsz3480;
          CREATE(sail_int)(&zgsz3480);
          CONVERT_OF(sail_int, mach_int)(&zgsz3480, 3l);
          sail_int zgsz3481;
          CREATE(sail_int)(&zgsz3481);
          add_int(&zgsz3481, zgsz3479, zgsz3480);
          zgaz3217 = CONVERT_OF(mach_int, sail_int)(zgsz3481);
          KILL(sail_int)(&zgsz3481);
          KILL(sail_int)(&zgsz3480);
          KILL(sail_int)(&zgsz3479);
        }
        {
          lbits zgsz3482;
          CREATE(lbits)(&zgsz3482);
          CONVERT_OF(lbits, fbits)(&zgsz3482, ztop, UINT64_C(33) , true);
          sail_int zgsz3483;
          CREATE(sail_int)(&zgsz3483);
          CONVERT_OF(sail_int, mach_int)(&zgsz3483, zgaz3217);
          lbits zgsz3484;
          CREATE(lbits)(&zgsz3484);
          shiftr(&zgsz3484, zgsz3482, zgsz3483);
          zgaz3218 = CONVERT_OF(fbits, lbits)(zgsz3484, true);
          KILL(lbits)(&zgsz3484);
          KILL(sail_int)(&zgsz3483);
          KILL(lbits)(&zgsz3482);
        }
      
      }
      int64_t zgaz3219;
      {
        sail_int zgsz3485;
        CREATE(sail_int)(&zgsz3485);
        CONVERT_OF(sail_int, mach_int)(&zgsz3485, zmantissa_width);
        sail_int zgsz3486;
        CREATE(sail_int)(&zgsz3486);
        CONVERT_OF(sail_int, mach_int)(&zgsz3486, 3l);
        sail_int zgsz3487;
        CREATE(sail_int)(&zgsz3487);
        sub_int(&zgsz3487, zgsz3485, zgsz3486);
        zgaz3219 = CONVERT_OF(mach_int, sail_int)(zgsz3487);
        KILL(sail_int)(&zgsz3487);
        KILL(sail_int)(&zgsz3486);
        KILL(sail_int)(&zgsz3485);
      }
      {
        lbits zgsz3488;
        CREATE(lbits)(&zgsz3488);
        CONVERT_OF(lbits, fbits)(&zgsz3488, zgaz3218, UINT64_C(33) , true);
        sail_int zgsz3489;
        CREATE(sail_int)(&zgsz3489);
        CONVERT_OF(sail_int, mach_int)(&zgsz3489, zgaz3219);
        lbits zgsz3490;
        CREATE(lbits)(&zgsz3490);
        sail_truncate(&zgsz3490, zgsz3488, zgsz3489);
        zT_ie = CONVERT_OF(fbits, lbits)(zgsz3490, true);
        KILL(lbits)(&zgsz3490);
        KILL(sail_int)(&zgsz3489);
        KILL(lbits)(&zgsz3488);
      }
    
    
    }
    uint64_t zmaskLo;
    {
      int64_t zgaz3215;
      {
        sail_int zgsz3491;
        CREATE(sail_int)(&zgsz3491);
        CONVERT_OF(sail_int, mach_int)(&zgsz3491, 32l);
        sail_int zgsz3492;
        CREATE(sail_int)(&zgsz3492);
        CONVERT_OF(sail_int, mach_int)(&zgsz3492, 1l);
        sail_int zgsz3493;
        CREATE(sail_int)(&zgsz3493);
        add_int(&zgsz3493, zgsz3491, zgsz3492);
        zgaz3215 = CONVERT_OF(mach_int, sail_int)(zgsz3493);
        KILL(sail_int)(&zgsz3493);
        KILL(sail_int)(&zgsz3492);
        KILL(sail_int)(&zgsz3491);
      }
      sbits zgaz3216;
      {
        int64_t zgaz3214;
        {
          sail_int zgsz3494;
          CREATE(sail_int)(&zgsz3494);
          CONVERT_OF(sail_int, mach_int)(&zgsz3494, ze);
          sail_int zgsz3495;
          CREATE(sail_int)(&zgsz3495);
          CONVERT_OF(sail_int, mach_int)(&zgsz3495, 3l);
          sail_int zgsz3496;
          CREATE(sail_int)(&zgsz3496);
          add_int(&zgsz3496, zgsz3494, zgsz3495);
          zgaz3214 = CONVERT_OF(mach_int, sail_int)(zgsz3496);
          KILL(sail_int)(&zgsz3496);
          KILL(sail_int)(&zgsz3495);
          KILL(sail_int)(&zgsz3494);
        }
        {
          sail_int zgsz3497;
          CREATE(sail_int)(&zgsz3497);
          CONVERT_OF(sail_int, mach_int)(&zgsz3497, zgaz3214);
          lbits zgsz3498;
          CREATE(lbits)(&zgsz3498);
          sailgen_zzz3zzz3ones(&zgsz3498, zgsz3497);
          zgaz3216 = CONVERT_OF(sbits, lbits)(zgsz3498, true);
          KILL(lbits)(&zgsz3498);
          KILL(sail_int)(&zgsz3497);
        }
      
      }
      {
        sail_int zgsz3499;
        CREATE(sail_int)(&zgsz3499);
        CONVERT_OF(sail_int, mach_int)(&zgsz3499, zgaz3215);
        lbits zgsz3500;
        CREATE(lbits)(&zgsz3500);
        CONVERT_OF(lbits, sbits)(&zgsz3500, zgaz3216, true);
        lbits zgsz3501;
        CREATE(lbits)(&zgsz3501);
        sailgen_zzz3zzz3EXTZ(&zgsz3501, zgsz3499, zgsz3500);
        zmaskLo = CONVERT_OF(fbits, lbits)(zgsz3501, true);
        KILL(lbits)(&zgsz3501);
        KILL(lbits)(&zgsz3500);
        KILL(sail_int)(&zgsz3499);
      }
    
    
    }
    {
      int64_t zgaz3198;
      {
        uint64_t zgaz3197;
        {
          lbits zgsz3502;
          CREATE(lbits)(&zgsz3502);
          CONVERT_OF(lbits, fbits)(&zgsz3502, zext_base, UINT64_C(33) , true);
          lbits zgsz3503;
          CREATE(lbits)(&zgsz3503);
          CONVERT_OF(lbits, fbits)(&zgsz3503, zmaskLo, UINT64_C(33) , true);
          lbits zgsz3504;
          CREATE(lbits)(&zgsz3504);
          and_bits(&zgsz3504, zgsz3502, zgsz3503);
          zgaz3197 = CONVERT_OF(fbits, lbits)(zgsz3504, true);
          KILL(lbits)(&zgsz3504);
          KILL(lbits)(&zgsz3503);
          KILL(lbits)(&zgsz3502);
        }
        zgaz3198 = ((mach_int) zgaz3197);
      
      }
      {
        sail_int zgsz3505;
        CREATE(sail_int)(&zgsz3505);
        CONVERT_OF(sail_int, mach_int)(&zgsz3505, zgaz3198);
        zlostSignificantBase = sailgen_zzz3zzzz7mzzJzzK0z3neq_int(zgsz3505, 0l);
        KILL(sail_int)(&zgsz3505);
      }
      unit zgsz3515;
      zgsz3515 = UNIT;
    
    }
    {
      int64_t zgaz3200;
      {
        uint64_t zgaz3199;
        {
          lbits zgsz3506;
          CREATE(lbits)(&zgsz3506);
          CONVERT_OF(lbits, fbits)(&zgsz3506, ztop, UINT64_C(33) , true);
          lbits zgsz3507;
          CREATE(lbits)(&zgsz3507);
          CONVERT_OF(lbits, fbits)(&zgsz3507, zmaskLo, UINT64_C(33) , true);
          lbits zgsz3508;
          CREATE(lbits)(&zgsz3508);
          and_bits(&zgsz3508, zgsz3506, zgsz3507);
          zgaz3199 = CONVERT_OF(fbits, lbits)(zgsz3508, true);
          KILL(lbits)(&zgsz3508);
          KILL(lbits)(&zgsz3507);
          KILL(lbits)(&zgsz3506);
        }
        zgaz3200 = ((mach_int) zgaz3199);
      
      }
      {
        sail_int zgsz3509;
        CREATE(sail_int)(&zgsz3509);
        CONVERT_OF(sail_int, mach_int)(&zgsz3509, zgaz3200);
        zlostSignificantTop = sailgen_zzz3zzzz7mzzJzzK0z3neq_int(zgsz3509, 0l);
        KILL(sail_int)(&zgsz3509);
      }
      unit zgsz3514;
      zgsz3514 = UNIT;
    
    }
    {
      unit zgsz3510;
      if (zlostSignificantTop) {
      {
        lbits zgsz3511;
        CREATE(lbits)(&zgsz3511);
        CONVERT_OF(lbits, fbits)(&zgsz3511, zT_ie, UINT64_C(5) , true);
        sail_int zgsz3512;
        CREATE(sail_int)(&zgsz3512);
        CONVERT_OF(sail_int, mach_int)(&zgsz3512, 1l);
        lbits zgsz3513;
        CREATE(lbits)(&zgsz3513);
        add_bits_int(&zgsz3513, zgsz3511, zgsz3512);
        zT_ie = CONVERT_OF(fbits, lbits)(zgsz3513, true);
        KILL(lbits)(&zgsz3513);
        KILL(sail_int)(&zgsz3512);
        KILL(lbits)(&zgsz3511);
      }
      zgsz3510 = UNIT;
      } else {  zgsz3510 = UNIT;  }
    }
    uint64_t zlen_ie;
    {
      lbits zgsz3516;
      CREATE(lbits)(&zgsz3516);
      CONVERT_OF(lbits, fbits)(&zgsz3516, zT_ie, UINT64_C(5) , true);
      lbits zgsz3517;
      CREATE(lbits)(&zgsz3517);
      CONVERT_OF(lbits, fbits)(&zgsz3517, zB_ie, UINT64_C(5) , true);
      lbits zgsz3518;
      CREATE(lbits)(&zgsz3518);
      sub_bits(&zgsz3518, zgsz3516, zgsz3517);
      zlen_ie = CONVERT_OF(fbits, lbits)(zgsz3518, true);
      KILL(lbits)(&zgsz3518);
      KILL(lbits)(&zgsz3517);
      KILL(lbits)(&zgsz3516);
    }
    {
      bool zgaz3203;
      {
        fbits zgaz3202;
        {
          int64_t zgaz3201;
          {
            sail_int zgsz3519;
            CREATE(sail_int)(&zgsz3519);
            CONVERT_OF(sail_int, mach_int)(&zgsz3519, zmantissa_width);
            sail_int zgsz3520;
            CREATE(sail_int)(&zgsz3520);
            CONVERT_OF(sail_int, mach_int)(&zgsz3520, 4l);
            sail_int zgsz3521;
            CREATE(sail_int)(&zgsz3521);
            sub_int(&zgsz3521, zgsz3519, zgsz3520);
            zgaz3201 = CONVERT_OF(mach_int, sail_int)(zgsz3521);
            KILL(sail_int)(&zgsz3521);
            KILL(sail_int)(&zgsz3520);
            KILL(sail_int)(&zgsz3519);
          }
          {
            sail_int zgsz3523;
            CREATE(sail_int)(&zgsz3523);
            CONVERT_OF(sail_int, mach_int)(&zgsz3523, zgaz3201);
            lbits zgsz3522;
            CREATE(lbits)(&zgsz3522);
            CONVERT_OF(lbits, fbits)(&zgsz3522, zlen_ie, UINT64_C(5) , true);
            zgaz3202 = bitvector_access(zgsz3522, zgsz3523);
            KILL(sail_int)(&zgsz3523);
            KILL(lbits)(&zgsz3522);
          }
        
        }
        zgaz3203 = eq_bit(zgaz3202, UINT64_C(1));
      
      }
      unit zgsz3528;
      if (zgaz3203) {
      __label__ case_169, finish_match_168;

      {
        zincE = true;
        unit zgsz3550;
        zgsz3550 = UNIT;
      }
      {
        bool zgsz3531;
        if (zlostSignificantBase) {  zgsz3531 = true;  } else {
        fbits zgaz3204;
        {
          sail_int zgsz3530;
          CREATE(sail_int)(&zgsz3530);
          CONVERT_OF(sail_int, mach_int)(&zgsz3530, 0l);
          lbits zgsz3529;
          CREATE(lbits)(&zgsz3529);
          CONVERT_OF(lbits, fbits)(&zgsz3529, zB_ie, UINT64_C(5) , true);
          zgaz3204 = bitvector_access(zgsz3529, zgsz3530);
          KILL(sail_int)(&zgsz3530);
          KILL(lbits)(&zgsz3529);
        }
        zgsz3531 = eq_bit(zgaz3204, UINT64_C(1));
      
        }
        zlostSignificantBase = zgsz3531;
        unit zgsz3549;
        zgsz3549 = UNIT;
      }
      {
        bool zgsz3534;
        if (zlostSignificantTop) {  zgsz3534 = true;  } else {
        fbits zgaz3205;
        {
          sail_int zgsz3533;
          CREATE(sail_int)(&zgsz3533);
          CONVERT_OF(sail_int, mach_int)(&zgsz3533, 0l);
          lbits zgsz3532;
          CREATE(lbits)(&zgsz3532);
          CONVERT_OF(lbits, fbits)(&zgsz3532, zT_ie, UINT64_C(5) , true);
          zgaz3205 = bitvector_access(zgsz3532, zgsz3533);
          KILL(sail_int)(&zgsz3533);
          KILL(lbits)(&zgsz3532);
        }
        zgsz3534 = eq_bit(zgaz3205, UINT64_C(1));
      
        }
        zlostSignificantTop = zgsz3534;
        unit zgsz3548;
        zgsz3548 = UNIT;
      }
      {
        uint64_t zgaz3207;
        {
          int64_t zgaz3206;
          {
            sail_int zgsz3535;
            CREATE(sail_int)(&zgsz3535);
            CONVERT_OF(sail_int, mach_int)(&zgsz3535, ze);
            sail_int zgsz3536;
            CREATE(sail_int)(&zgsz3536);
            CONVERT_OF(sail_int, mach_int)(&zgsz3536, 4l);
            sail_int zgsz3537;
            CREATE(sail_int)(&zgsz3537);
            add_int(&zgsz3537, zgsz3535, zgsz3536);
            zgaz3206 = CONVERT_OF(mach_int, sail_int)(zgsz3537);
            KILL(sail_int)(&zgsz3537);
            KILL(sail_int)(&zgsz3536);
            KILL(sail_int)(&zgsz3535);
          }
          {
            lbits zgsz3538;
            CREATE(lbits)(&zgsz3538);
            CONVERT_OF(lbits, fbits)(&zgsz3538, zbase, UINT64_C(32) , true);
            sail_int zgsz3539;
            CREATE(sail_int)(&zgsz3539);
            CONVERT_OF(sail_int, mach_int)(&zgsz3539, zgaz3206);
            lbits zgsz3540;
            CREATE(lbits)(&zgsz3540);
            shiftr(&zgsz3540, zgsz3538, zgsz3539);
            zgaz3207 = CONVERT_OF(fbits, lbits)(zgsz3540, true);
            KILL(lbits)(&zgsz3540);
            KILL(sail_int)(&zgsz3539);
            KILL(lbits)(&zgsz3538);
          }
        
        }
        int64_t zgaz3208;
        {
          sail_int zgsz3541;
          CREATE(sail_int)(&zgsz3541);
          CONVERT_OF(sail_int, mach_int)(&zgsz3541, zmantissa_width);
          sail_int zgsz3542;
          CREATE(sail_int)(&zgsz3542);
          CONVERT_OF(sail_int, mach_int)(&zgsz3542, 3l);
          sail_int zgsz3543;
          CREATE(sail_int)(&zgsz3543);
          sub_int(&zgsz3543, zgsz3541, zgsz3542);
          zgaz3208 = CONVERT_OF(mach_int, sail_int)(zgsz3543);
          KILL(sail_int)(&zgsz3543);
          KILL(sail_int)(&zgsz3542);
          KILL(sail_int)(&zgsz3541);
        }
        {
          lbits zgsz3544;
          CREATE(lbits)(&zgsz3544);
          CONVERT_OF(lbits, fbits)(&zgsz3544, zgaz3207, UINT64_C(32) , true);
          sail_int zgsz3545;
          CREATE(sail_int)(&zgsz3545);
          CONVERT_OF(sail_int, mach_int)(&zgsz3545, zgaz3208);
          lbits zgsz3546;
          CREATE(lbits)(&zgsz3546);
          sail_truncate(&zgsz3546, zgsz3544, zgsz3545);
          zB_ie = CONVERT_OF(fbits, lbits)(zgsz3546, true);
          KILL(lbits)(&zgsz3546);
          KILL(sail_int)(&zgsz3545);
          KILL(lbits)(&zgsz3544);
        }
        unit zgsz3547;
        zgsz3547 = UNIT;
      
      
      }
      int64_t zgaz3209;
      if (zlostSignificantTop) {  zgaz3209 = 1l;  } else {  zgaz3209 = 0l;  }
      unit zgsz3551;
      {
        int64_t zincT;
        zincT = zgaz3209;
        uint64_t zgaz3213;
        {
          uint64_t zgaz3211;
          {
            int64_t zgaz3210;
            {
              sail_int zgsz3552;
              CREATE(sail_int)(&zgsz3552);
              CONVERT_OF(sail_int, mach_int)(&zgsz3552, ze);
              sail_int zgsz3553;
              CREATE(sail_int)(&zgsz3553);
              CONVERT_OF(sail_int, mach_int)(&zgsz3553, 4l);
              sail_int zgsz3554;
              CREATE(sail_int)(&zgsz3554);
              add_int(&zgsz3554, zgsz3552, zgsz3553);
              zgaz3210 = CONVERT_OF(mach_int, sail_int)(zgsz3554);
              KILL(sail_int)(&zgsz3554);
              KILL(sail_int)(&zgsz3553);
              KILL(sail_int)(&zgsz3552);
            }
            {
              lbits zgsz3555;
              CREATE(lbits)(&zgsz3555);
              CONVERT_OF(lbits, fbits)(&zgsz3555, ztop, UINT64_C(33) , true);
              sail_int zgsz3556;
              CREATE(sail_int)(&zgsz3556);
              CONVERT_OF(sail_int, mach_int)(&zgsz3556, zgaz3210);
              lbits zgsz3557;
              CREATE(lbits)(&zgsz3557);
              shiftr(&zgsz3557, zgsz3555, zgsz3556);
              zgaz3211 = CONVERT_OF(fbits, lbits)(zgsz3557, true);
              KILL(lbits)(&zgsz3557);
              KILL(sail_int)(&zgsz3556);
              KILL(lbits)(&zgsz3555);
            }
          
          }
          int64_t zgaz3212;
          {
            sail_int zgsz3558;
            CREATE(sail_int)(&zgsz3558);
            CONVERT_OF(sail_int, mach_int)(&zgsz3558, zmantissa_width);
            sail_int zgsz3559;
            CREATE(sail_int)(&zgsz3559);
            CONVERT_OF(sail_int, mach_int)(&zgsz3559, 3l);
            sail_int zgsz3560;
            CREATE(sail_int)(&zgsz3560);
            sub_int(&zgsz3560, zgsz3558, zgsz3559);
            zgaz3212 = CONVERT_OF(mach_int, sail_int)(zgsz3560);
            KILL(sail_int)(&zgsz3560);
            KILL(sail_int)(&zgsz3559);
            KILL(sail_int)(&zgsz3558);
          }
          {
            lbits zgsz3561;
            CREATE(lbits)(&zgsz3561);
            CONVERT_OF(lbits, fbits)(&zgsz3561, zgaz3211, UINT64_C(33) , true);
            sail_int zgsz3562;
            CREATE(sail_int)(&zgsz3562);
            CONVERT_OF(sail_int, mach_int)(&zgsz3562, zgaz3212);
            lbits zgsz3563;
            CREATE(lbits)(&zgsz3563);
            sail_truncate(&zgsz3563, zgsz3561, zgsz3562);
            zgaz3213 = CONVERT_OF(fbits, lbits)(zgsz3563, true);
            KILL(lbits)(&zgsz3563);
            KILL(sail_int)(&zgsz3562);
            KILL(lbits)(&zgsz3561);
          }
        
        
        }
        {
          lbits zgsz3564;
          CREATE(lbits)(&zgsz3564);
          CONVERT_OF(lbits, fbits)(&zgsz3564, zgaz3213, UINT64_C(5) , true);
          sail_int zgsz3565;
          CREATE(sail_int)(&zgsz3565);
          CONVERT_OF(sail_int, mach_int)(&zgsz3565, zincT);
          lbits zgsz3566;
          CREATE(lbits)(&zgsz3566);
          add_bits_int(&zgsz3566, zgsz3564, zgsz3565);
          zT_ie = CONVERT_OF(fbits, lbits)(zgsz3566, true);
          KILL(lbits)(&zgsz3566);
          KILL(sail_int)(&zgsz3565);
          KILL(lbits)(&zgsz3564);
        }
        zgsz3551 = UNIT;
      
      
        goto finish_match_168;
      }
    case_169: ;
      sail_match_failure("setCapBounds");
    finish_match_168: ;
      zgsz3528 = zgsz3551;
    
    
      } else {  zgsz3528 = UNIT;  }
    
    }
    {
      {
        lbits zgsz3524;
        CREATE(lbits)(&zgsz3524);
        CONVERT_OF(lbits, fbits)(&zgsz3524, zB_ie, UINT64_C(5) , true);
        lbits zgsz3525;
        CREATE(lbits)(&zgsz3525);
        CONVERT_OF(lbits, fbits)(&zgsz3525, UINT64_C(0b000), UINT64_C(3) , true);
        lbits zgsz3526;
        CREATE(lbits)(&zgsz3526);
        append(&zgsz3526, zgsz3524, zgsz3525);
        zBbits = CONVERT_OF(fbits, lbits)(zgsz3526, true);
        KILL(lbits)(&zgsz3526);
        KILL(lbits)(&zgsz3525);
        KILL(lbits)(&zgsz3524);
      }
      unit zgsz3527;
      zgsz3527 = UNIT;
    }
    {
      lbits zgsz3568;
      CREATE(lbits)(&zgsz3568);
      CONVERT_OF(lbits, fbits)(&zgsz3568, zT_ie, UINT64_C(5) , true);
      lbits zgsz3569;
      CREATE(lbits)(&zgsz3569);
      CONVERT_OF(lbits, fbits)(&zgsz3569, UINT64_C(0b000), UINT64_C(3) , true);
      lbits zgsz3570;
      CREATE(lbits)(&zgsz3570);
      append(&zgsz3570, zgsz3568, zgsz3569);
      zTbits = CONVERT_OF(fbits, lbits)(zgsz3570, true);
      KILL(lbits)(&zgsz3570);
      KILL(lbits)(&zgsz3569);
      KILL(lbits)(&zgsz3568);
    }
    zgsz3466 = UNIT;
  
  
  
  
    } else {  zgsz3466 = UNIT;  }
  }
  struct zCapability znewCap;
  {
    uint64_t zgaz3225;
    {
      int64_t zgaz3224;
      if (zincE) {
      {
        sail_int zgsz3571;
        CREATE(sail_int)(&zgsz3571);
        CONVERT_OF(sail_int, mach_int)(&zgsz3571, ze);
        sail_int zgsz3572;
        CREATE(sail_int)(&zgsz3572);
        CONVERT_OF(sail_int, mach_int)(&zgsz3572, 1l);
        sail_int zgsz3573;
        CREATE(sail_int)(&zgsz3573);
        add_int(&zgsz3573, zgsz3571, zgsz3572);
        zgaz3224 = CONVERT_OF(mach_int, sail_int)(zgsz3573);
        KILL(sail_int)(&zgsz3573);
        KILL(sail_int)(&zgsz3572);
        KILL(sail_int)(&zgsz3571);
      }
      } else {  zgaz3224 = ze;  }
      {
        sail_int zgsz3574;
        CREATE(sail_int)(&zgsz3574);
        CONVERT_OF(sail_int, mach_int)(&zgsz3574, zgaz3224);
        zgaz3225 = sailgen_zzzz7lzzJzzK6z3to_bits(6l, zgsz3574);
        KILL(sail_int)(&zgsz3574);
      }
    
    }
    struct zCapability zgsz3575;
    zgsz3575 = zcap;
    zgsz3575.zB = zBbits;
    zgsz3575.zE = zgaz3225;
    zgsz3575.zT = zTbits;
    zgsz3575.zaddress = zbase;
    zgsz3575.zinternal_e = zie;
    znewCap = zgsz3575;
  
  
  }
  bool zexact;
  {
    bool zgaz3223;
    {
      bool zgsz3576;
      if (zlostSignificantBase) {  zgsz3576 = true;  } else {  zgsz3576 = zlostSignificantTop;  }
      zgaz3223 = zgsz3576;
    }
    zexact = not(zgaz3223);
  
  }
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgsz3577;
  zgsz3577.ztup0 = zexact;
  zgsz3577.ztup1 = znewCap;
  zcbz341 = zgsz3577;












end_function_170: ;
  return zcbz341;
end_block_exception_171: ;
  struct zCapability zcbz359 = { .zuperms = UINT64_C(0xdeadc0de), .ztag = false, .zsealed = false, .zreserved = UINT64_C(0xdeadc0de), .zpermit_unseal = false, .zpermit_store_local_cap = false, .zpermit_store_cap = false, .zpermit_store = false, .zpermit_set_CID = false, .zpermit_seal = false, .zpermit_load_cap = false, .zpermit_load = false, .zpermit_execute = false, .zpermit_ccall = false, .zotype = UINT64_C(0xdeadc0de), .zinternal_e = false, .zglobal = false, .zflag_cap_mode = false, .zaddress = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zT = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zB = UINT64_C(0xdeadc0de) };
  struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zcbz358 = { .ztup1 = zcbz359, .ztup0 = false };
  return zcbz358;
}

static uint64_t sailgen_getCapPerms(struct zCapability);

static uint64_t sailgen_getCapPerms(struct zCapability zcap)
{
  __label__ case_174, finish_match_173, end_function_175, end_block_exception_176;

  uint64_t zcbz342;
  uint64_t zgaz3233;
  {
    uint64_t zgaz3232;
    zgaz3232 = sailgen_getCapHardPerms(zcap);
    zgaz3233 = sailgen_zzzz7mzzJzzK15zzCzz0zz7nzzJzzK12z3EXTZ(15l, zgaz3232);
  
  }
  uint64_t zgsz3578;
  {
    uint64_t zperms;
    zperms = zgaz3233;
    uint64_t zgaz3235;
    {
      uint64_t zgaz3234;
      zgaz3234 = zcap.zuperms;
      {
        lbits zgsz3579;
        CREATE(lbits)(&zgsz3579);
        CONVERT_OF(lbits, fbits)(&zgsz3579, zgaz3234, UINT64_C(0) , true);
        lbits zgsz3580;
        CREATE(lbits)(&zgsz3580);
        CONVERT_OF(lbits, fbits)(&zgsz3580, zperms, UINT64_C(15) , true);
        lbits zgsz3581;
        CREATE(lbits)(&zgsz3581);
        append(&zgsz3581, zgsz3579, zgsz3580);
        zgaz3235 = CONVERT_OF(fbits, lbits)(zgsz3581, true);
        KILL(lbits)(&zgsz3581);
        KILL(lbits)(&zgsz3580);
        KILL(lbits)(&zgsz3579);
      }
    
    }
    {
      sbits zgsz3583;
      zgsz3583 = CONVERT_OF(sbits, fbits)(zgaz3235, UINT64_C(15) , true);
      zgsz3578 = sailgen_zzz3zzzz7mzzJzzK31z3EXTZ(31l, zgsz3583);
    
    }
  
  
    goto finish_match_173;
  }
case_174: ;
  sail_match_failure("getCapPerms");
finish_match_173: ;
  zcbz342 = zgsz3578;


end_function_175: ;
  return zcbz342;
end_block_exception_176: ;

  return UINT64_C(0xdeadc0de);
}

static struct zCapability sailgen_setCapPerms(struct zCapability, uint64_t);

static struct zCapability sailgen_setCapPerms(struct zCapability zcap, uint64_t zperms)
{
  __label__ end_function_178, end_block_exception_179;

  struct zCapability zcbz343;
  uint64_t zgaz3237;
  {
    uint64_t zgaz3236;
    {
      lbits zgsz3584;
      CREATE(lbits)(&zgsz3584);
      CONVERT_OF(lbits, fbits)(&zgsz3584, zperms, UINT64_C(31) , true);
      sail_int zgsz3585;
      CREATE(sail_int)(&zgsz3585);
      CONVERT_OF(sail_int, mach_int)(&zgsz3585, 30l);
      sail_int zgsz3586;
      CREATE(sail_int)(&zgsz3586);
      CONVERT_OF(sail_int, mach_int)(&zgsz3586, 15l);
      lbits zgsz3587;
      CREATE(lbits)(&zgsz3587);
      vector_subrange_lbits(&zgsz3587, zgsz3584, zgsz3585, zgsz3586);
      zgaz3236 = CONVERT_OF(fbits, lbits)(zgsz3587, true);
      KILL(lbits)(&zgsz3587);
      KILL(sail_int)(&zgsz3586);
      KILL(sail_int)(&zgsz3585);
      KILL(lbits)(&zgsz3584);
    }
    {
      lbits zgsz3588;
      CREATE(lbits)(&zgsz3588);
      CONVERT_OF(lbits, fbits)(&zgsz3588, zgaz3236, UINT64_C(16) , true);
      sail_int zgsz3589;
      CREATE(sail_int)(&zgsz3589);
      CONVERT_OF(sail_int, mach_int)(&zgsz3589, zuperms_width);
      lbits zgsz3590;
      CREATE(lbits)(&zgsz3590);
      sail_truncate(&zgsz3590, zgsz3588, zgsz3589);
      zgaz3237 = CONVERT_OF(fbits, lbits)(zgsz3590, true);
      KILL(lbits)(&zgsz3590);
      KILL(sail_int)(&zgsz3589);
      KILL(lbits)(&zgsz3588);
    }
  
  }
  bool zgaz3239;
  {
    fbits zgaz3238;
    {
      sail_int zgsz3592;
      CREATE(sail_int)(&zgsz3592);
      CONVERT_OF(sail_int, mach_int)(&zgsz3592, 11l);
      lbits zgsz3591;
      CREATE(lbits)(&zgsz3591);
      CONVERT_OF(lbits, fbits)(&zgsz3591, zperms, UINT64_C(31) , true);
      zgaz3238 = bitvector_access(zgsz3591, zgsz3592);
      KILL(sail_int)(&zgsz3592);
      KILL(lbits)(&zgsz3591);
    }
    zgaz3239 = sailgen_bit_to_bool(zgaz3238);
  
  }
  bool zgaz3241;
  {
    fbits zgaz3240;
    {
      sail_int zgsz3594;
      CREATE(sail_int)(&zgsz3594);
      CONVERT_OF(sail_int, mach_int)(&zgsz3594, 10l);
      lbits zgsz3593;
      CREATE(lbits)(&zgsz3593);
      CONVERT_OF(lbits, fbits)(&zgsz3593, zperms, UINT64_C(31) , true);
      zgaz3240 = bitvector_access(zgsz3593, zgsz3594);
      KILL(sail_int)(&zgsz3594);
      KILL(lbits)(&zgsz3593);
    }
    zgaz3241 = sailgen_bit_to_bool(zgaz3240);
  
  }
  bool zgaz3243;
  {
    fbits zgaz3242;
    {
      sail_int zgsz3596;
      CREATE(sail_int)(&zgsz3596);
      CONVERT_OF(sail_int, mach_int)(&zgsz3596, 9l);
      lbits zgsz3595;
      CREATE(lbits)(&zgsz3595);
      CONVERT_OF(lbits, fbits)(&zgsz3595, zperms, UINT64_C(31) , true);
      zgaz3242 = bitvector_access(zgsz3595, zgsz3596);
      KILL(sail_int)(&zgsz3596);
      KILL(lbits)(&zgsz3595);
    }
    zgaz3243 = sailgen_bit_to_bool(zgaz3242);
  
  }
  bool zgaz3245;
  {
    fbits zgaz3244;
    {
      sail_int zgsz3598;
      CREATE(sail_int)(&zgsz3598);
      CONVERT_OF(sail_int, mach_int)(&zgsz3598, 8l);
      lbits zgsz3597;
      CREATE(lbits)(&zgsz3597);
      CONVERT_OF(lbits, fbits)(&zgsz3597, zperms, UINT64_C(31) , true);
      zgaz3244 = bitvector_access(zgsz3597, zgsz3598);
      KILL(sail_int)(&zgsz3598);
      KILL(lbits)(&zgsz3597);
    }
    zgaz3245 = sailgen_bit_to_bool(zgaz3244);
  
  }
  bool zgaz3247;
  {
    fbits zgaz3246;
    {
      sail_int zgsz3600;
      CREATE(sail_int)(&zgsz3600);
      CONVERT_OF(sail_int, mach_int)(&zgsz3600, 7l);
      lbits zgsz3599;
      CREATE(lbits)(&zgsz3599);
      CONVERT_OF(lbits, fbits)(&zgsz3599, zperms, UINT64_C(31) , true);
      zgaz3246 = bitvector_access(zgsz3599, zgsz3600);
      KILL(sail_int)(&zgsz3600);
      KILL(lbits)(&zgsz3599);
    }
    zgaz3247 = sailgen_bit_to_bool(zgaz3246);
  
  }
  bool zgaz3249;
  {
    fbits zgaz3248;
    {
      sail_int zgsz3602;
      CREATE(sail_int)(&zgsz3602);
      CONVERT_OF(sail_int, mach_int)(&zgsz3602, 6l);
      lbits zgsz3601;
      CREATE(lbits)(&zgsz3601);
      CONVERT_OF(lbits, fbits)(&zgsz3601, zperms, UINT64_C(31) , true);
      zgaz3248 = bitvector_access(zgsz3601, zgsz3602);
      KILL(sail_int)(&zgsz3602);
      KILL(lbits)(&zgsz3601);
    }
    zgaz3249 = sailgen_bit_to_bool(zgaz3248);
  
  }
  bool zgaz3251;
  {
    fbits zgaz3250;
    {
      sail_int zgsz3604;
      CREATE(sail_int)(&zgsz3604);
      CONVERT_OF(sail_int, mach_int)(&zgsz3604, 5l);
      lbits zgsz3603;
      CREATE(lbits)(&zgsz3603);
      CONVERT_OF(lbits, fbits)(&zgsz3603, zperms, UINT64_C(31) , true);
      zgaz3250 = bitvector_access(zgsz3603, zgsz3604);
      KILL(sail_int)(&zgsz3604);
      KILL(lbits)(&zgsz3603);
    }
    zgaz3251 = sailgen_bit_to_bool(zgaz3250);
  
  }
  bool zgaz3253;
  {
    fbits zgaz3252;
    {
      sail_int zgsz3606;
      CREATE(sail_int)(&zgsz3606);
      CONVERT_OF(sail_int, mach_int)(&zgsz3606, 4l);
      lbits zgsz3605;
      CREATE(lbits)(&zgsz3605);
      CONVERT_OF(lbits, fbits)(&zgsz3605, zperms, UINT64_C(31) , true);
      zgaz3252 = bitvector_access(zgsz3605, zgsz3606);
      KILL(sail_int)(&zgsz3606);
      KILL(lbits)(&zgsz3605);
    }
    zgaz3253 = sailgen_bit_to_bool(zgaz3252);
  
  }
  bool zgaz3255;
  {
    fbits zgaz3254;
    {
      sail_int zgsz3608;
      CREATE(sail_int)(&zgsz3608);
      CONVERT_OF(sail_int, mach_int)(&zgsz3608, 3l);
      lbits zgsz3607;
      CREATE(lbits)(&zgsz3607);
      CONVERT_OF(lbits, fbits)(&zgsz3607, zperms, UINT64_C(31) , true);
      zgaz3254 = bitvector_access(zgsz3607, zgsz3608);
      KILL(sail_int)(&zgsz3608);
      KILL(lbits)(&zgsz3607);
    }
    zgaz3255 = sailgen_bit_to_bool(zgaz3254);
  
  }
  bool zgaz3257;
  {
    fbits zgaz3256;
    {
      sail_int zgsz3610;
      CREATE(sail_int)(&zgsz3610);
      CONVERT_OF(sail_int, mach_int)(&zgsz3610, 2l);
      lbits zgsz3609;
      CREATE(lbits)(&zgsz3609);
      CONVERT_OF(lbits, fbits)(&zgsz3609, zperms, UINT64_C(31) , true);
      zgaz3256 = bitvector_access(zgsz3609, zgsz3610);
      KILL(sail_int)(&zgsz3610);
      KILL(lbits)(&zgsz3609);
    }
    zgaz3257 = sailgen_bit_to_bool(zgaz3256);
  
  }
  bool zgaz3259;
  {
    fbits zgaz3258;
    {
      sail_int zgsz3612;
      CREATE(sail_int)(&zgsz3612);
      CONVERT_OF(sail_int, mach_int)(&zgsz3612, 1l);
      lbits zgsz3611;
      CREATE(lbits)(&zgsz3611);
      CONVERT_OF(lbits, fbits)(&zgsz3611, zperms, UINT64_C(31) , true);
      zgaz3258 = bitvector_access(zgsz3611, zgsz3612);
      KILL(sail_int)(&zgsz3612);
      KILL(lbits)(&zgsz3611);
    }
    zgaz3259 = sailgen_bit_to_bool(zgaz3258);
  
  }
  bool zgaz3261;
  {
    fbits zgaz3260;
    {
      sail_int zgsz3614;
      CREATE(sail_int)(&zgsz3614);
      CONVERT_OF(sail_int, mach_int)(&zgsz3614, 0l);
      lbits zgsz3613;
      CREATE(lbits)(&zgsz3613);
      CONVERT_OF(lbits, fbits)(&zgsz3613, zperms, UINT64_C(31) , true);
      zgaz3260 = bitvector_access(zgsz3613, zgsz3614);
      KILL(sail_int)(&zgsz3614);
      KILL(lbits)(&zgsz3613);
    }
    zgaz3261 = sailgen_bit_to_bool(zgaz3260);
  
  }
  struct zCapability zgsz3615;
  zgsz3615 = zcap;
  zgsz3615.zaccess_system_regs = zgaz3241;
  zgsz3615.zglobal = zgaz3261;
  zgsz3615.zpermit_ccall = zgaz3245;
  zgsz3615.zpermit_execute = zgaz3259;
  zgsz3615.zpermit_load = zgaz3257;
  zgsz3615.zpermit_load_cap = zgaz3253;
  zgsz3615.zpermit_seal = zgaz3247;
  zgsz3615.zpermit_set_CID = zgaz3239;
  zgsz3615.zpermit_store = zgaz3255;
  zgsz3615.zpermit_store_cap = zgaz3251;
  zgsz3615.zpermit_store_local_cap = zgaz3249;
  zgsz3615.zpermit_unseal = zgaz3243;
  zgsz3615.zuperms = zgaz3237;
  zcbz343 = zgsz3615;














end_function_178: ;
  return zcbz343;
end_block_exception_179: ;
  struct zCapability zcbz360 = { .zuperms = UINT64_C(0xdeadc0de), .ztag = false, .zsealed = false, .zreserved = UINT64_C(0xdeadc0de), .zpermit_unseal = false, .zpermit_store_local_cap = false, .zpermit_store_cap = false, .zpermit_store = false, .zpermit_set_CID = false, .zpermit_seal = false, .zpermit_load_cap = false, .zpermit_load = false, .zpermit_execute = false, .zpermit_ccall = false, .zotype = UINT64_C(0xdeadc0de), .zinternal_e = false, .zglobal = false, .zflag_cap_mode = false, .zaddress = UINT64_C(0xdeadc0de), .zaccess_system_regs = false, .zT = UINT64_C(0xdeadc0de), .zE = UINT64_C(0xdeadc0de), .zB = UINT64_C(0xdeadc0de) };
  return zcbz360;
}

static uint64_t sailgen_getCapFlags(struct zCapability);

static uint64_t sailgen_getCapFlags(struct zCapability zcap)
{
  __label__ end_function_181, end_block_exception_182;

  uint64_t zcbz344;
  bool zgaz3262;
  zgaz3262 = zcap.zflag_cap_mode;
  zcbz344 = sailgen_bool_to_bits(zgaz3262);

end_function_181: ;
  return zcbz344;
end_block_exception_182: ;

  return UINT64_C(0xdeadc0de);
}

static bool sailgen_hasReservedOType(struct zCapability);

static bool sailgen_hasReservedOType(struct zCapability zcap)
{
  __label__ end_function_184, end_block_exception_185;

  bool zcbz345;
  int64_t zgaz3264;
  {
    uint64_t zgaz3263;
    zgaz3263 = zcap.zotype;
    zgaz3264 = ((mach_int) zgaz3263);
  
  }
  {
    sail_int zgsz3617;
    CREATE(sail_int)(&zgsz3617);
    CONVERT_OF(sail_int, mach_int)(&zgsz3617, zmax_otype);
    sail_int zgsz3616;
    CREATE(sail_int)(&zgsz3616);
    CONVERT_OF(sail_int, mach_int)(&zgsz3616, zgaz3264);
    zcbz345 = gt(zgsz3616, zgsz3617);
    KILL(sail_int)(&zgsz3617);
    KILL(sail_int)(&zgsz3616);
  }

end_function_184: ;
  return zcbz345;
end_block_exception_185: ;

  return false;
}

static uint64_t sailgen_getCapBaseBits(struct zCapability);

static uint64_t sailgen_getCapBaseBits(struct zCapability zc)
{
  __label__ case_188, finish_match_187, end_function_189, end_block_exception_190;

  uint64_t zcbz346;
  struct ztuple_z8z5bv32zCz0z5bv33z9 zgaz3265;
  zgaz3265 = sailgen_getCapBoundsBits(zc);
  uint64_t zgsz3618;
  {
    uint64_t zbase;
    zbase = zgaz3265.ztup0;
    zgsz3618 = zbase;
  
    goto finish_match_187;
  }
case_188: ;
  sail_match_failure("getCapBaseBits");
finish_match_187: ;
  zcbz346 = zgsz3618;


end_function_189: ;
  return zcbz346;
end_block_exception_190: ;

  return UINT64_C(0xdeadc0de);
}

static uint64_t sailgen_getCapOffsetBits(struct zCapability);

static uint64_t sailgen_getCapOffsetBits(struct zCapability zc)
{
  __label__ case_193, finish_match_192, end_function_194, end_block_exception_195;

  uint64_t zcbz347;
  uint64_t zgaz3266;
  zgaz3266 = sailgen_getCapBaseBits(zc);
  uint64_t zgsz3620;
  {
    uint64_t zbase;
    zbase = zgaz3266;
    uint64_t zgaz3267;
    zgaz3267 = zc.zaddress;
    {
      lbits zgsz3622;
      CREATE(lbits)(&zgsz3622);
      CONVERT_OF(lbits, fbits)(&zgsz3622, zgaz3267, UINT64_C(32) , true);
      lbits zgsz3623;
      CREATE(lbits)(&zgsz3623);
      CONVERT_OF(lbits, fbits)(&zgsz3623, zbase, UINT64_C(32) , true);
      lbits zgsz3624;
      CREATE(lbits)(&zgsz3624);
      sub_bits(&zgsz3624, zgsz3622, zgsz3623);
      zgsz3620 = CONVERT_OF(fbits, lbits)(zgsz3624, true);
      KILL(lbits)(&zgsz3624);
      KILL(lbits)(&zgsz3623);
      KILL(lbits)(&zgsz3622);
    }
  
  
    goto finish_match_192;
  }
case_193: ;
  sail_match_failure("getCapOffsetBits");
finish_match_192: ;
  zcbz347 = zgsz3620;


end_function_194: ;
  return zcbz347;
end_block_exception_195: ;

  return UINT64_C(0xdeadc0de);
}

static int64_t sailgen_getCapLength(struct zCapability);

static int64_t sailgen_getCapLength(struct zCapability zc)
{
  __label__ case_198, finish_match_197, end_function_199, end_block_exception_200;

  int64_t zcbz348;
  struct ztuple_z8z5i64zCz0z5i64z9 zgaz3268;
  zgaz3268 = sailgen_getCapBounds(zc);
  int64_t zgsz3625;
  {
    int64_t zbase;
    zbase = zgaz3268.ztup0;
    int64_t ztop;
    ztop = zgaz3268.ztup1;
    {
      bool zgaz3271;
      {
        bool zgaz3270;
        {
          bool zgaz3269;
          zgaz3269 = zc.ztag;
          zgaz3270 = not(zgaz3269);
        
        }
        bool zgsz3626;
        if (zgaz3270) {  zgsz3626 = true;  } else {
        {
          sail_int zgsz3628;
          CREATE(sail_int)(&zgsz3628);
          CONVERT_OF(sail_int, mach_int)(&zgsz3628, zbase);
          sail_int zgsz3627;
          CREATE(sail_int)(&zgsz3627);
          CONVERT_OF(sail_int, mach_int)(&zgsz3627, ztop);
          zgsz3626 = gteq(zgsz3627, zgsz3628);
          KILL(sail_int)(&zgsz3628);
          KILL(sail_int)(&zgsz3627);
        }
        }
        zgaz3271 = zgsz3626;
      
      }
      unit zgsz3629;
      zgsz3629 = sail_assert(zgaz3271, "src/cheri_cap_common.sail 271:40 - 271:41");
    
    }
    int64_t zgaz3272;
    {
      sail_int zgsz3630;
      CREATE(sail_int)(&zgsz3630);
      CONVERT_OF(sail_int, mach_int)(&zgsz3630, ztop);
      sail_int zgsz3631;
      CREATE(sail_int)(&zgsz3631);
      CONVERT_OF(sail_int, mach_int)(&zgsz3631, zbase);
      sail_int zgsz3632;
      CREATE(sail_int)(&zgsz3632);
      sub_int(&zgsz3632, zgsz3630, zgsz3631);
      zgaz3272 = CONVERT_OF(mach_int, sail_int)(zgsz3632);
      KILL(sail_int)(&zgsz3632);
      KILL(sail_int)(&zgsz3631);
      KILL(sail_int)(&zgsz3630);
    }
    int64_t zgaz3273;
    {
      sail_int zgsz3633;
      CREATE(sail_int)(&zgsz3633);
      CONVERT_OF(sail_int, mach_int)(&zgsz3633, zcap_len_width);
      sail_int zgsz3634;
      CREATE(sail_int)(&zgsz3634);
      pow2(&zgsz3634, zgsz3633);
      zgaz3273 = CONVERT_OF(mach_int, sail_int)(zgsz3634);
      KILL(sail_int)(&zgsz3634);
      KILL(sail_int)(&zgsz3633);
    }
    {
      sail_int zgsz3636;
      CREATE(sail_int)(&zgsz3636);
      CONVERT_OF(sail_int, mach_int)(&zgsz3636, zgaz3272);
      sail_int zgsz3637;
      CREATE(sail_int)(&zgsz3637);
      CONVERT_OF(sail_int, mach_int)(&zgsz3637, zgaz3273);
      sail_int zgsz3638;
      CREATE(sail_int)(&zgsz3638);
      emod_int(&zgsz3638, zgsz3636, zgsz3637);
      zgsz3625 = CONVERT_OF(mach_int, sail_int)(zgsz3638);
      KILL(sail_int)(&zgsz3638);
      KILL(sail_int)(&zgsz3637);
      KILL(sail_int)(&zgsz3636);
    }
  
  
  
  
    goto finish_match_197;
  }
case_198: ;
  sail_match_failure("getCapLength");
finish_match_197: ;
  zcbz348 = zgsz3625;


end_function_199: ;
  return zcbz348;
end_block_exception_200: ;

  return INT64_C(0xdeadc0de);
}

static bool sailgen_fastRepCheck(struct zCapability, uint64_t);

static bool sailgen_fastRepCheck(struct zCapability zc, uint64_t zi)
{
  __label__ end_function_202, end_block_exception_203;

  bool zcbz349;
  int64_t zE;
  {
    uint64_t zgaz3287;
    zgaz3287 = zc.zE;
    zE = ((mach_int) zgaz3287);
  
  }
  bool zgaz3275;
  {
    int64_t zgaz3274;
    {
      sail_int zgsz3639;
      CREATE(sail_int)(&zgsz3639);
      CONVERT_OF(sail_int, mach_int)(&zgsz3639, zmaxE);
      sail_int zgsz3640;
      CREATE(sail_int)(&zgsz3640);
      CONVERT_OF(sail_int, mach_int)(&zgsz3640, 2l);
      sail_int zgsz3641;
      CREATE(sail_int)(&zgsz3641);
      sub_int(&zgsz3641, zgsz3639, zgsz3640);
      zgaz3274 = CONVERT_OF(mach_int, sail_int)(zgsz3641);
      KILL(sail_int)(&zgsz3641);
      KILL(sail_int)(&zgsz3640);
      KILL(sail_int)(&zgsz3639);
    }
    {
      sail_int zgsz3643;
      CREATE(sail_int)(&zgsz3643);
      CONVERT_OF(sail_int, mach_int)(&zgsz3643, zgaz3274);
      sail_int zgsz3642;
      CREATE(sail_int)(&zgsz3642);
      CONVERT_OF(sail_int, mach_int)(&zgsz3642, zE);
      zgaz3275 = gteq(zgsz3642, zgsz3643);
      KILL(sail_int)(&zgsz3643);
      KILL(sail_int)(&zgsz3642);
    }
  
  }
  if (zgaz3275) {  zcbz349 = true;  } else {
  int64_t zi_top;
  {
    uint64_t zgaz3286;
    {
      int64_t zgaz3285;
      {
        sail_int zgsz3644;
        CREATE(sail_int)(&zgsz3644);
        CONVERT_OF(sail_int, mach_int)(&zgsz3644, zE);
        sail_int zgsz3645;
        CREATE(sail_int)(&zgsz3645);
        CONVERT_OF(sail_int, mach_int)(&zgsz3645, zmantissa_width);
        sail_int zgsz3646;
        CREATE(sail_int)(&zgsz3646);
        add_int(&zgsz3646, zgsz3644, zgsz3645);
        zgaz3285 = CONVERT_OF(mach_int, sail_int)(zgsz3646);
        KILL(sail_int)(&zgsz3646);
        KILL(sail_int)(&zgsz3645);
        KILL(sail_int)(&zgsz3644);
      }
      {
        lbits zgsz3647;
        CREATE(lbits)(&zgsz3647);
        CONVERT_OF(lbits, fbits)(&zgsz3647, zi, UINT64_C(32) , true);
        sail_int zgsz3648;
        CREATE(sail_int)(&zgsz3648);
        CONVERT_OF(sail_int, mach_int)(&zgsz3648, zgaz3285);
        lbits zgsz3649;
        CREATE(lbits)(&zgsz3649);
        arith_shiftr(&zgsz3649, zgsz3647, zgsz3648);
        zgaz3286 = CONVERT_OF(fbits, lbits)(zgsz3649, true);
        KILL(lbits)(&zgsz3649);
        KILL(sail_int)(&zgsz3648);
        KILL(lbits)(&zgsz3647);
      }
    
    }
    zi_top = fast_signed(zgaz3286, 32);
  
  }
  uint64_t zi_mid;
  {
    uint64_t zgaz3284;
    {
      lbits zgsz3650;
      CREATE(lbits)(&zgsz3650);
      CONVERT_OF(lbits, fbits)(&zgsz3650, zi, UINT64_C(32) , true);
      sail_int zgsz3651;
      CREATE(sail_int)(&zgsz3651);
      CONVERT_OF(sail_int, mach_int)(&zgsz3651, zE);
      lbits zgsz3652;
      CREATE(lbits)(&zgsz3652);
      shiftr(&zgsz3652, zgsz3650, zgsz3651);
      zgaz3284 = CONVERT_OF(fbits, lbits)(zgsz3652, true);
      KILL(lbits)(&zgsz3652);
      KILL(sail_int)(&zgsz3651);
      KILL(lbits)(&zgsz3650);
    }
    {
      lbits zgsz3653;
      CREATE(lbits)(&zgsz3653);
      CONVERT_OF(lbits, fbits)(&zgsz3653, zgaz3284, UINT64_C(32) , true);
      sail_int zgsz3654;
      CREATE(sail_int)(&zgsz3654);
      CONVERT_OF(sail_int, mach_int)(&zgsz3654, zmantissa_width);
      lbits zgsz3655;
      CREATE(lbits)(&zgsz3655);
      sail_truncate(&zgsz3655, zgsz3653, zgsz3654);
      zi_mid = CONVERT_OF(fbits, lbits)(zgsz3655, true);
      KILL(lbits)(&zgsz3655);
      KILL(sail_int)(&zgsz3654);
      KILL(lbits)(&zgsz3653);
    }
  
  }
  uint64_t za_mid;
  {
    uint64_t zgaz3283;
    {
      uint64_t zgaz3282;
      zgaz3282 = zc.zaddress;
      {
        lbits zgsz3656;
        CREATE(lbits)(&zgsz3656);
        CONVERT_OF(lbits, fbits)(&zgsz3656, zgaz3282, UINT64_C(32) , true);
        sail_int zgsz3657;
        CREATE(sail_int)(&zgsz3657);
        CONVERT_OF(sail_int, mach_int)(&zgsz3657, zE);
        lbits zgsz3658;
        CREATE(lbits)(&zgsz3658);
        shiftr(&zgsz3658, zgsz3656, zgsz3657);
        zgaz3283 = CONVERT_OF(fbits, lbits)(zgsz3658, true);
        KILL(lbits)(&zgsz3658);
        KILL(sail_int)(&zgsz3657);
        KILL(lbits)(&zgsz3656);
      }
    
    }
    {
      lbits zgsz3659;
      CREATE(lbits)(&zgsz3659);
      CONVERT_OF(lbits, fbits)(&zgsz3659, zgaz3283, UINT64_C(32) , true);
      sail_int zgsz3660;
      CREATE(sail_int)(&zgsz3660);
      CONVERT_OF(sail_int, mach_int)(&zgsz3660, zmantissa_width);
      lbits zgsz3661;
      CREATE(lbits)(&zgsz3661);
      sail_truncate(&zgsz3661, zgsz3659, zgsz3660);
      za_mid = CONVERT_OF(fbits, lbits)(zgsz3661, true);
      KILL(lbits)(&zgsz3661);
      KILL(sail_int)(&zgsz3660);
      KILL(lbits)(&zgsz3659);
    }
  
  }
  uint64_t zB3;
  {
    uint64_t zgaz3281;
    zgaz3281 = zc.zB;
    {
      lbits zgsz3662;
      CREATE(lbits)(&zgsz3662);
      CONVERT_OF(lbits, fbits)(&zgsz3662, zgaz3281, UINT64_C(8) , true);
      sail_int zgsz3663;
      CREATE(sail_int)(&zgsz3663);
      CONVERT_OF(sail_int, mach_int)(&zgsz3663, 3l);
      lbits zgsz3664;
      CREATE(lbits)(&zgsz3664);
      sail_truncateLSB(&zgsz3664, zgsz3662, zgsz3663);
      zB3 = CONVERT_OF(fbits, lbits)(zgsz3664, true);
      KILL(lbits)(&zgsz3664);
      KILL(sail_int)(&zgsz3663);
      KILL(lbits)(&zgsz3662);
    }
  
  }
  uint64_t zR3;
  {
    lbits zgsz3665;
    CREATE(lbits)(&zgsz3665);
    CONVERT_OF(lbits, fbits)(&zgsz3665, zB3, UINT64_C(3) , true);
    lbits zgsz3666;
    CREATE(lbits)(&zgsz3666);
    CONVERT_OF(lbits, fbits)(&zgsz3666, UINT64_C(0b001), UINT64_C(3) , true);
    lbits zgsz3667;
    CREATE(lbits)(&zgsz3667);
    sub_bits(&zgsz3667, zgsz3665, zgsz3666);
    zR3 = CONVERT_OF(fbits, lbits)(zgsz3667, true);
    KILL(lbits)(&zgsz3667);
    KILL(lbits)(&zgsz3666);
    KILL(lbits)(&zgsz3665);
  }
  uint64_t zR;
  {
    uint64_t zgaz3280;
    {
      int64_t zgaz3279;
      {
        sail_int zgsz3668;
        CREATE(sail_int)(&zgsz3668);
        CONVERT_OF(sail_int, mach_int)(&zgsz3668, zmantissa_width);
        sail_int zgsz3669;
        CREATE(sail_int)(&zgsz3669);
        CONVERT_OF(sail_int, mach_int)(&zgsz3669, 3l);
        sail_int zgsz3670;
        CREATE(sail_int)(&zgsz3670);
        sub_int(&zgsz3670, zgsz3668, zgsz3669);
        zgaz3279 = CONVERT_OF(mach_int, sail_int)(zgsz3670);
        KILL(sail_int)(&zgsz3670);
        KILL(sail_int)(&zgsz3669);
        KILL(sail_int)(&zgsz3668);
      }
      zgaz3280 = sailgen_zzzz7nzzJzzK5z3zzeros_implicit(zgaz3279);
    
    }
    {
      lbits zgsz3671;
      CREATE(lbits)(&zgsz3671);
      CONVERT_OF(lbits, fbits)(&zgsz3671, zR3, UINT64_C(3) , true);
      lbits zgsz3672;
      CREATE(lbits)(&zgsz3672);
      CONVERT_OF(lbits, fbits)(&zgsz3672, zgaz3280, UINT64_C(5) , true);
      lbits zgsz3673;
      CREATE(lbits)(&zgsz3673);
      append(&zgsz3673, zgsz3671, zgsz3672);
      zR = CONVERT_OF(fbits, lbits)(zgsz3673, true);
      KILL(lbits)(&zgsz3673);
      KILL(lbits)(&zgsz3672);
      KILL(lbits)(&zgsz3671);
    }
  
  }
  uint64_t zdiff;
  {
    lbits zgsz3674;
    CREATE(lbits)(&zgsz3674);
    CONVERT_OF(lbits, fbits)(&zgsz3674, zR, UINT64_C(8) , true);
    lbits zgsz3675;
    CREATE(lbits)(&zgsz3675);
    CONVERT_OF(lbits, fbits)(&zgsz3675, za_mid, UINT64_C(8) , true);
    lbits zgsz3676;
    CREATE(lbits)(&zgsz3676);
    sub_bits(&zgsz3676, zgsz3674, zgsz3675);
    zdiff = CONVERT_OF(fbits, lbits)(zgsz3676, true);
    KILL(lbits)(&zgsz3676);
    KILL(lbits)(&zgsz3675);
    KILL(lbits)(&zgsz3674);
  }
  uint64_t zdiff1;
  {
    lbits zgsz3677;
    CREATE(lbits)(&zgsz3677);
    CONVERT_OF(lbits, fbits)(&zgsz3677, zdiff, UINT64_C(8) , true);
    sail_int zgsz3678;
    CREATE(sail_int)(&zgsz3678);
    CONVERT_OF(sail_int, mach_int)(&zgsz3678, 1l);
    lbits zgsz3679;
    CREATE(lbits)(&zgsz3679);
    sub_bits_int(&zgsz3679, zgsz3677, zgsz3678);
    zdiff1 = CONVERT_OF(fbits, lbits)(zgsz3679, true);
    KILL(lbits)(&zgsz3679);
    KILL(sail_int)(&zgsz3678);
    KILL(lbits)(&zgsz3677);
  }
  bool zgaz3276;
  {
    sail_int zgsz3681;
    CREATE(sail_int)(&zgsz3681);
    CONVERT_OF(sail_int, mach_int)(&zgsz3681, 0l);
    sail_int zgsz3680;
    CREATE(sail_int)(&zgsz3680);
    CONVERT_OF(sail_int, mach_int)(&zgsz3680, zi_top);
    zgaz3276 = eq_int(zgsz3680, zgsz3681);
    KILL(sail_int)(&zgsz3681);
    KILL(sail_int)(&zgsz3680);
  }
  if (zgaz3276) {  zcbz349 = sailgen_z8operatorz0zzzz7nzzJzzK8z3zI_uz9(zi_mid, zdiff1);  } else {
  bool zgaz3277;
  {
    sail_int zgsz3683;
    CREATE(sail_int)(&zgsz3683);
    CONVERT_OF(sail_int, mach_int)(&zgsz3683, -1l);
    sail_int zgsz3682;
    CREATE(sail_int)(&zgsz3682);
    CONVERT_OF(sail_int, mach_int)(&zgsz3682, zi_top);
    zgaz3277 = eq_int(zgsz3682, zgsz3683);
    KILL(sail_int)(&zgsz3683);
    KILL(sail_int)(&zgsz3682);
  }
  if (zgaz3277) {
  bool zgaz3278;
  zgaz3278 = sailgen_z8operatorz0zzzz7nzzJzzK8z3zKzJ_uz9(zi_mid, zdiff);
  bool zgsz3684;
  if (zgaz3278) {
  {
    lbits zgsz3686;
    CREATE(lbits)(&zgsz3686);
    CONVERT_OF(lbits, fbits)(&zgsz3686, za_mid, UINT64_C(8) , true);
    lbits zgsz3685;
    CREATE(lbits)(&zgsz3685);
    CONVERT_OF(lbits, fbits)(&zgsz3685, zR, UINT64_C(8) , true);
    zgsz3684 = neq_bits(zgsz3685, zgsz3686);
    KILL(lbits)(&zgsz3686);
    KILL(lbits)(&zgsz3685);
  }
  } else {  zgsz3684 = false;  }
  zcbz349 = zgsz3684;

  } else {  zcbz349 = false;  }

  }









  }


end_function_202: ;
  return zcbz349;
end_block_exception_203: ;

  return false;
}

static void sailgen_capToString(sail_string *rop, struct zCapability);

static void sailgen_capToString(sail_string *zcbz350, struct zCapability zcap)
{
  __label__ case_206, finish_match_205, end_function_207, end_block_exception_208, end_function_219;

  int64_t zlen;
  zlen = sailgen_getCapLength(zcap);
  if (have_exception) {

  goto end_block_exception_208;
  }
  sail_string zlen_str;
  CREATE(sail_string)(&zlen_str);
  {
    uint64_t zgaz3317;
    {
      int64_t zgaz3316;
      {
        sail_int zgsz3687;
        CREATE(sail_int)(&zgsz3687);
        CONVERT_OF(sail_int, mach_int)(&zgsz3687, zcap_len_width);
        sail_int zgsz3688;
        CREATE(sail_int)(&zgsz3688);
        CONVERT_OF(sail_int, mach_int)(&zgsz3688, 3l);
        sail_int zgsz3689;
        CREATE(sail_int)(&zgsz3689);
        add_int(&zgsz3689, zgsz3687, zgsz3688);
        zgaz3316 = CONVERT_OF(mach_int, sail_int)(zgsz3689);
        KILL(sail_int)(&zgsz3689);
        KILL(sail_int)(&zgsz3688);
        KILL(sail_int)(&zgsz3687);
      }
      {
        sail_int zgsz3690;
        CREATE(sail_int)(&zgsz3690);
        CONVERT_OF(sail_int, mach_int)(&zgsz3690, zlen);
        zgaz3317 = sailgen_zzzz7lzzJzzK36z3to_bits(zgaz3316, zgsz3690);
        KILL(sail_int)(&zgsz3690);
      }
    
    }
    {
      lbits zgsz3691;
      CREATE(lbits)(&zgsz3691);
      CONVERT_OF(lbits, fbits)(&zgsz3691, zgaz3317, UINT64_C(36) , true);
      string_of_lbits(&zlen_str, zgsz3691);
      KILL(lbits)(&zgsz3691);
    }
  
  }
  uint64_t zgaz3291;
  {
    bool zgaz3288;
    zgaz3288 = sailgen_hasReservedOType(zcap);
    if (zgaz3288) {
    uint64_t zgaz3289;
    zgaz3289 = zcap.zotype;
    zgaz3291 = sailgen_zzzz7mzzJzzK32zzCzz0zz7nzzJzzK4z3EXTS(32l, zgaz3289);
  
    } else {
    uint64_t zgaz3290;
    zgaz3290 = zcap.zotype;
    zgaz3291 = sailgen_zzzz7mzzJzzK32zzCzz0zz7nzzJzzK4z3EXTZ(32l, zgaz3290);
  
    }
  
  }
  sail_string zgsz3692;
  CREATE(sail_string)(&zgsz3692);
  {
    uint64_t zotype64;
    zotype64 = zgaz3291;
    sail_string zgaz3315;
    CREATE(sail_string)(&zgaz3315);
    {
      sail_string zgaz3313;
      CREATE(sail_string)(&zgaz3313);
      {
        bool zgaz3292;
        zgaz3292 = zcap.ztag;
        if (zgaz3292) {  COPY(sail_string)(&zgaz3313, "1");  } else {  COPY(sail_string)(&zgaz3313, "0");  }
      
      }
      sail_string zgaz3314;
      CREATE(sail_string)(&zgaz3314);
      {
        sail_string zgaz3312;
        CREATE(sail_string)(&zgaz3312);
        {
          sail_string zgaz3310;
          CREATE(sail_string)(&zgaz3310);
          {
            bool zgaz3293;
            zgaz3293 = zcap.zsealed;
            if (zgaz3293) {  COPY(sail_string)(&zgaz3310, "1");  } else {  COPY(sail_string)(&zgaz3310, "0");  }
          
          }
          sail_string zgaz3311;
          CREATE(sail_string)(&zgaz3311);
          {
            sail_string zgaz3309;
            CREATE(sail_string)(&zgaz3309);
            {
              sail_string zgaz3307;
              CREATE(sail_string)(&zgaz3307);
              {
                uint64_t zgaz3295;
                {
                  uint64_t zgaz3294;
                  zgaz3294 = sailgen_getCapPerms(zcap);
                  {
                    lbits zgsz3693;
                    CREATE(lbits)(&zgsz3693);
                    CONVERT_OF(lbits, fbits)(&zgsz3693, UINT64_C(0b0), UINT64_C(1) , true);
                    lbits zgsz3694;
                    CREATE(lbits)(&zgsz3694);
                    CONVERT_OF(lbits, fbits)(&zgsz3694, zgaz3294, UINT64_C(31) , true);
                    lbits zgsz3695;
                    CREATE(lbits)(&zgsz3695);
                    append(&zgsz3695, zgsz3693, zgsz3694);
                    zgaz3295 = CONVERT_OF(fbits, lbits)(zgsz3695, true);
                    KILL(lbits)(&zgsz3695);
                    KILL(lbits)(&zgsz3694);
                    KILL(lbits)(&zgsz3693);
                  }
                
                }
                {
                  lbits zgsz3696;
                  CREATE(lbits)(&zgsz3696);
                  CONVERT_OF(lbits, fbits)(&zgsz3696, zgaz3295, UINT64_C(32) , true);
                  string_of_lbits(&zgaz3307, zgsz3696);
                  KILL(lbits)(&zgsz3696);
                }
              
              }
              sail_string zgaz3308;
              CREATE(sail_string)(&zgaz3308);
              {
                sail_string zgaz3306;
                CREATE(sail_string)(&zgaz3306);
                {
                  sail_string zgaz3304;
                  CREATE(sail_string)(&zgaz3304);
                  {
                    lbits zgsz3697;
                    CREATE(lbits)(&zgsz3697);
                    CONVERT_OF(lbits, fbits)(&zgsz3697, zotype64, UINT64_C(32) , true);
                    string_of_lbits(&zgaz3304, zgsz3697);
                    KILL(lbits)(&zgsz3697);
                  }
                  sail_string zgaz3305;
                  CREATE(sail_string)(&zgaz3305);
                  {
                    sail_string zgaz3303;
                    CREATE(sail_string)(&zgaz3303);
                    {
                      sail_string zgaz3301;
                      CREATE(sail_string)(&zgaz3301);
                      {
                        uint64_t zgaz3296;
                        zgaz3296 = sailgen_getCapOffsetBits(zcap);
                        {
                          lbits zgsz3698;
                          CREATE(lbits)(&zgsz3698);
                          CONVERT_OF(lbits, fbits)(&zgsz3698, zgaz3296, UINT64_C(32) , true);
                          string_of_lbits(&zgaz3301, zgsz3698);
                          KILL(lbits)(&zgsz3698);
                        }
                      
                      }
                      sail_string zgaz3302;
                      CREATE(sail_string)(&zgaz3302);
                      {
                        sail_string zgaz3300;
                        CREATE(sail_string)(&zgaz3300);
                        {
                          sail_string zgaz3298;
                          CREATE(sail_string)(&zgaz3298);
                          {
                            uint64_t zgaz3297;
                            zgaz3297 = sailgen_getCapBaseBits(zcap);
                            {
                              lbits zgsz3699;
                              CREATE(lbits)(&zgsz3699);
                              CONVERT_OF(lbits, fbits)(&zgsz3699, zgaz3297, UINT64_C(32) , true);
                              string_of_lbits(&zgaz3298, zgsz3699);
                              KILL(lbits)(&zgsz3699);
                            }
                          
                          }
                          sail_string zgaz3299;
                          CREATE(sail_string)(&zgaz3299);
                          concat_str(&zgaz3299, " length:", zlen_str);
                          concat_str(&zgaz3300, zgaz3298, zgaz3299);
                          KILL(sail_string)(&zgaz3299);
                          KILL(sail_string)(&zgaz3298);
                        }
                        concat_str(&zgaz3302, " base:", zgaz3300);
                        KILL(sail_string)(&zgaz3300);
                      }
                      concat_str(&zgaz3303, zgaz3301, zgaz3302);
                      KILL(sail_string)(&zgaz3302);
                      KILL(sail_string)(&zgaz3301);
                    }
                    concat_str(&zgaz3305, " offset:", zgaz3303);
                    KILL(sail_string)(&zgaz3303);
                  }
                  concat_str(&zgaz3306, zgaz3304, zgaz3305);
                  KILL(sail_string)(&zgaz3305);
                  KILL(sail_string)(&zgaz3304);
                }
                concat_str(&zgaz3308, " type:", zgaz3306);
                KILL(sail_string)(&zgaz3306);
              }
              concat_str(&zgaz3309, zgaz3307, zgaz3308);
              KILL(sail_string)(&zgaz3308);
              KILL(sail_string)(&zgaz3307);
            }
            concat_str(&zgaz3311, " perms:", zgaz3309);
            KILL(sail_string)(&zgaz3309);
          }
          concat_str(&zgaz3312, zgaz3310, zgaz3311);
          KILL(sail_string)(&zgaz3311);
          KILL(sail_string)(&zgaz3310);
        }
        concat_str(&zgaz3314, " s:", zgaz3312);
        KILL(sail_string)(&zgaz3312);
      }
      concat_str(&zgaz3315, zgaz3313, zgaz3314);
      KILL(sail_string)(&zgaz3314);
      KILL(sail_string)(&zgaz3313);
    }
    concat_str(&zgsz3692, " t:", zgaz3315);
    KILL(sail_string)(&zgaz3315);
  
    goto finish_match_205;
  }
case_206: ;
  sail_match_failure("capToString");
finish_match_205: ;
  COPY(sail_string)((*(&zcbz350)), zgsz3692);
  KILL(sail_string)(&zgsz3692);

  KILL(sail_string)(&zlen_str);

end_function_207: ;
  goto end_function_219;
end_block_exception_208: ;
  goto end_function_219;
end_function_219: ;
}

// register TestCap
struct zCapability zTestCap;

// register TestAddr
uint64_t zTestAddr;

// register TestLen
uint64_t zTestLen;

static unit sailgen_main(unit);


static unit sailgen_main(unit zgsz3701)
{
  __label__ end_function_214, end_block_exception_215;

  unit zcbz351;
  {
    zTestCap = znull_cap;
    unit zgsz3702;
    zgsz3702 = UNIT;
  }
  uint64_t zbits1;
  zbits1 = sailgen_capToBits(zTestCap);
  uint64_t zbits2;
  zbits2 = sailgen_capToMemBits(zTestCap);
  struct zCapability zcap1;
  {
    bool zgaz3322;
    zgaz3322 = zTestCap.ztag;
    zcap1 = sailgen_capBitsToCapability(zgaz3322, zbits1);
  
  }
  struct zCapability zcap2;
  {
    bool zgaz3321;
    zgaz3321 = zTestCap.ztag;
    zcap2 = sailgen_memBitsToCapability(zgaz3321, zbits2);
  
  }
  bool zrep;
  zrep = sailgen_fastRepCheck(zTestCap, zTestAddr);
  {
    __label__ case_211, finish_match_210;

    struct ztuple_z8z5boolzCz0z5structz0zzCapabilityz9 zgaz3318;
    zgaz3318 = sailgen_setCapBounds(zTestCap, zTestAddr, zTestLen);
    unit zgsz3703;
    {
      bool ztup__0;
      ztup__0 = zgaz3318.ztup0;
      struct zCapability ztup__1;
      ztup__1 = zgaz3318.ztup1;
      bool zexact;
      zexact = ztup__0;
      struct zCapability zcap;
      zcap = ztup__1;
      zgsz3703 = UNIT;
    
    
    
    
      goto finish_match_210;
    }
  case_211: ;
    sail_match_failure("main");
  finish_match_210: ;
    unit zgsz3708;
    zgsz3708 = zgsz3703;
  
  
  }
  {
    __label__ case_213, finish_match_212;

    struct ztuple_z8z5i64zCz0z5i64z9 zgaz3319;
    zgaz3319 = sailgen_getCapBounds(zTestCap);
    unit zgsz3705;
    {
      int64_t ztup__0;
      ztup__0 = zgaz3319.ztup0;
      int64_t ztup__1;
      ztup__1 = zgaz3319.ztup1;
      int64_t zbase;
      zbase = ztup__0;
      int64_t ztop;
      ztop = ztup__1;
      zgsz3705 = UNIT;
    
    
    
    
      goto finish_match_212;
    }
  case_213: ;
    sail_match_failure("main");
  finish_match_212: ;
    unit zgsz3707;
    zgsz3707 = zgsz3705;
  
  
  }
  uint64_t zflags;
  zflags = sailgen_getCapFlags(zTestCap);
  struct zCapability znew_cap;
  {
    uint64_t zgaz3320;
    zgaz3320 = sailgen_zzzz7nzzJzzK31z3ones(31l);
    znew_cap = sailgen_setCapPerms(zTestCap, zgaz3320);
  
  }
  sail_string zcap_str;
  CREATE(sail_string)(&zcap_str);
  sailgen_capToString(&zcap_str, zTestCap);
  if (have_exception) {







  KILL(sail_string)(&zcap_str);
  goto end_block_exception_215;
  }
  zcbz351 = UNIT;
  KILL(sail_string)(&zcap_str);







end_function_214: ;
  return zcbz351;
end_block_exception_215: ;

  return UNIT;
}

static unit sailgen_initializze_registers(unit);

static unit sailgen_initializze_registers(unit zgsz3709)
{
  __label__ end_function_217, end_block_exception_218;

  unit zcbz352;
  {
    zTestCap = sailgen_undefined_Capability(UNIT);
    unit zgsz3713;
    zgsz3713 = UNIT;
  }
  {
    {
      sail_int zgsz3710;
      CREATE(sail_int)(&zgsz3710);
      CONVERT_OF(sail_int, mach_int)(&zgsz3710, 32l);
      lbits zgsz3711;
      CREATE(lbits)(&zgsz3711);
      UNDEFINED(lbits)(&zgsz3711, zgsz3710);
      zTestAddr = CONVERT_OF(fbits, lbits)(zgsz3711, true);
      KILL(lbits)(&zgsz3711);
      KILL(sail_int)(&zgsz3710);
    }
    unit zgsz3712;
    zgsz3712 = UNIT;
  }
  int64_t zgaz3323;
  {
    sail_int zgsz3714;
    CREATE(sail_int)(&zgsz3714);
    CONVERT_OF(sail_int, mach_int)(&zgsz3714, 32l);
    sail_int zgsz3715;
    CREATE(sail_int)(&zgsz3715);
    CONVERT_OF(sail_int, mach_int)(&zgsz3715, 1l);
    sail_int zgsz3716;
    CREATE(sail_int)(&zgsz3716);
    add_int(&zgsz3716, zgsz3714, zgsz3715);
    zgaz3323 = CONVERT_OF(mach_int, sail_int)(zgsz3716);
    KILL(sail_int)(&zgsz3716);
    KILL(sail_int)(&zgsz3715);
    KILL(sail_int)(&zgsz3714);
  }
  {
    sail_int zgsz3717;
    CREATE(sail_int)(&zgsz3717);
    CONVERT_OF(sail_int, mach_int)(&zgsz3717, zgaz3323);
    lbits zgsz3718;
    CREATE(lbits)(&zgsz3718);
    UNDEFINED(lbits)(&zgsz3718, zgsz3717);
    zTestLen = CONVERT_OF(fbits, lbits)(zgsz3718, true);
    KILL(lbits)(&zgsz3718);
    KILL(sail_int)(&zgsz3717);
  }
  zcbz352 = UNIT;

end_function_217: ;
  return zcbz352;
end_block_exception_218: ;

  return UNIT;
}

void model_init(void)
{
  setup_rts();
  sailgen_initializze_registers(UNIT);
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
}

void model_fini(void)
{
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
}

int model_main(int argc, char *argv[])
{
  model_init();
  if (process_arguments(argc, argv)) exit(EXIT_FAILURE);
  sailgen_main(UNIT);
  model_fini();
  return EXIT_SUCCESS;
}


