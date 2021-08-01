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
	OP_LDF64,
	OP_UNKNOWN,
	OP_INVALID
};

/* Types */
typedef struct rocket_symbol
{
	u8 type;
	u64 hash;
	u64 offset;
};

typedef struct rocket_app
{
	struct rocket_app_header
	{
		u64 entry_point;
		u64 symbol_count;
		rocket_symbol *symbols;
	} header;

	struct rocket_app_body
	{
		u64 size;
		u8 *code;
	} body;
} rocket_app_t;

typedef struct rocket_vm
{
	u8 *code;
	u64 *stack;
	u64 *locals;
	u64 *callstack;
	u64 registers[16];
} rocket_vm_t;

/* Functions */

/*
 * Create and initialize a VM
 *
 * @returns A pointer to a VM object
 */
rocket_vm_t *rocket_create_vm(u8 *code, size_t stack_size, size_t max_memory);

/*
 * Destroy and cleanup a VM
 */
void rocket_destroy_vm(rocket_vm_t *vm);

/*
 * Load app data into app structure
 *
 * @returns App data structure
 */
rocket_app_t rocket_load_app(u8 *file_data);

/*
 * Load app data into vm
 *
 * @returns Result boolean
 */
int rocket_load_data(rocket_vm_t *vm, rocket_app_t *app);

/*
 * Fetch data from the program
 *
 * @returns A pointer to the data
 */
void *rocket_fetch(rocket_vm_t *vm, size_t size);

/*
 * Execute a step of the program
 *
 * @returns The opcode value that was executed
 */
opcode_t rocket_step(rocket_vm_t *vm);

#endif /* ROCKET_H */