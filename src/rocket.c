/* System Includes */
#include <stdlib.h>

/* Rocket Includes */
#include "rocket.h"

/* Macros */
#define ROCKET_PUSH(vm, v) vm->stack[++vm->registers[VM_SP]] = v
#define ROCKET_POP(vm) vm->stack[vm->registers[VM_SP]--]
#define ROCKET_NEXT(vm, type) *((type *)rocket_fetch(vm, sizeof(type)))

/* Functions */
rocket_vm_t *
rocket_create_vm(size_t stack_size, size_t memory_size)
{
	rocket_vm_t *vm = (rocket_vm_t *)malloc(sizeof(rocket_vm_t));

	if (!vm)
	{
		return NULL;
	}

	vm->stack = (u64 *)malloc(stack_size);
	vm->cstack = (u64 *)malloc(stack_size);
	vm->locals = (u64 *)malloc(sizeof(u64) * memory_size);

	if (!vm->code || !vm->stack || !vm->locals)
	{
		return NULL;
	}

	int i;
	for (i = 0; i < 16; i++)
	{
		vm->registers[i] = 0;
	}

	return vm;
}

void rocket_destroy_vm(rocket_vm_t *vm)
{
	free(vm->stack);
	free(vm->cstack);
	free(vm->locals);

	free(vm);
}

int rocket_load(rocket_vm_t *vm, rocket_app_t *app)
{
	/* TODO: Implement this */
	return false;
}

void *
rocket_fetch(rocket_vm_t *vm, size_t size)
{
	void *ptr = (void *)&(vm->code[vm->registers[13]]);

	vm->registers[VM_PC] += size;

	return ptr;
}

opcode_t
rocket_step(rocket_vm_t *vm)
{
	opcode_t opcode = ROCKET_NEXT(vm, opcode_t);

	switch (opcode)
	{
	case OP_NOP:
		break;
	case OP_BR:
	{
		u64 addr = ROCKET_NEXT(vm, u64);

		vm->callstack[vm->registers[VM_CS]++] = vm->registers[VM_PC];
		vm->registers[VM_PC] = addr;

		break;
	}
	case OP_RET:
		vm->registers[VM_PC] = vm->callstack[--vm->registers[VM_CS]];
		break;
	case OP_JMP:
	{
		u64 addr = ROCKET_NEXT(vm, u64);

		break;
	}
	case OP_JSR:
		break;
	case OP_LDL:
		break;
	case OP_LDR:
		break;
	case OP_LDG:
		break;
	case OP_STL:
		break;
	case OP_STR:
		break;
	case OP_STG:
		break;
	case OP_MLR:
		break;
	case OP_MLG:
		break;
	case OP_MRL:
		break;
	case OP_MRG:
		break;
	case OP_MGL:
		break;
	case OP_MGR:
		break;
	case OP_POP:
		break;
	case OP_LLA:
		break;
	case OP_LEA:
		break;
	case OP_ADD:
		break;
	case OP_ADDR:
		break;
	case OP_SUB:
		break;
	case OP_SUBR:
		break;
	case OP_MUL:
		break;
	case OP_MULR:
		break;
	case OP_DIV:
		break;
	case OP_DIVR:
		break;
	case OP_REM:
		break;
	case OP_REMR:
		break;
	case OP_OR:
		break;
	case OP_ORR:
		break;
	case OP_XOR:
		break;
	case OP_XORR:
		break;
	case AND:
		break;
	case ANDR:
		break;
	case NOT:
		break;
	case NOTR:
		break;
	case OP_LDI8:
		break;
	case OP_LDU8:
		break;
	case OP_LDI16:
		break;
	case OP_LDU16:
		break;
	case OP_LDI32:
		break;
	case OP_LDU32:
		break;
	case OP_LDI64:
		break;
	case OP_LDU64:
		break;
	case OP_LDF32:
		break;
	case OP_LDF64:
		break;
	default:
		opcode = OP_UNKNOWN;
		break;
	}

	return opcode;
}