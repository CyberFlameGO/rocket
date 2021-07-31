#ifndef ROCKET_H
#define ROCKET_H

/* Required for size_t */
#include <stddef.h>

/* Constants */
#define VM_PC 12 /* Program Counter Index */
#define VM_SP 13 /* Stack Pointer Index */
#define VM_FP 14 /* Frame Pointer Index */
#define VM_CS 15 /* Call Stack Pointer Index */

/* Type Aliases */
typedef char i8;
typedef short i16;
typedef int i32;
typedef long i64;
typedef float f32;
typedef double f64;
typedef long double f128;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
typedef int rocket_result_t;
typedef unsigned char opcode_t;

/* Opcodes (see SPEC.md for specifications) */
enum
{
	OP_NOP = 0,
	OP_BR,
	OP_RET,
	OP_JMP,
	OP_JSR,
	OP_LDL,
	OP_LDR,
	OP_LDG,
	OP_STL,
	OP_STR,
	OP_STG,
	OP_MLR,
	OP_MLG,
	OP_MRL,
	OP_MRG,
	OP_MGL,
	OP_MGR,
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

/* Types */
typedef struct rocket_vm
{
	u8 *code;
	u64 registers[16];
	u64 *stack, locals, callstack;
} rocket_vm_t;

/* Functions */
rocket_vm_t *rocket_create_vm(u8 *code, size_t stack_size, size_t max_memory);
void rocket_destroy_vm(rocket_vm_t *vm);
rocket_result_t rocket_execute(rocket_vm_t *vm);

#endif /* ROCKET_H */