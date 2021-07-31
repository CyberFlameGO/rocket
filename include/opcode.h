#ifndef OPCODE_H
#define OPCODE_H

/* Type Aliases */
typedef unsigned char opcode_t;

/* Opcodes (see SPEC.md for specifications) */
enum {
	OP_NOP = 0,
	OP_BR,
	OP_RET,
	OP_JMP,
	OP_JSR,
	OP_LD,
	OP_LDR,
	OP_GLD,
	OP_ST,
	OP_STR,
	OP_GST,
	OP_POP,
	OP_LLA,
	OP_LEA,
	OP_ADD,
	OP_ADDR,
	OP_SUB,
	OP_SUBR,
	OP_MUL,
	OP_MULR,
	OP_DIV,
	OP_DIVR,
	OP_REM,
	OP_REMR,
	OP_OR,
	OP_ORR,
	OP_XOR,
	OP_XORR,
	OP_AND,
	OP_ANDR,
	OP_NOT,
	OP_NOTR,
	OP_LDI8,
	OP_LDU8,
	OP_LDI16,
	OP_LDU16,
	OP_LDI32,
	OP_LDU32,
	OP_LDI64,
	OP_LDU64,
	OP_LDF32,
	OP_LDF64
};

#endif /* OPCODE_H */