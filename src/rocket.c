/* System Includes */
#include <stdio.h>
#include <stdlib.h>

/* Rocket Includes */
#include "rocket.h"
#include "opcode.h"

/* Macros */
#define ROCKET_PUSH(vm, v) vm->stack[++vm->registers[14]] = v
#define ROCKET_POP(vm) vm->stack[vm->registers[14]--]
#define ROCKET_NEXT(vm, type) *((type *)rocket_next(vm, sizeof(type)))

/* Functions */
rocket_vm_t *
rocket_create_vm(u8 *code, size_t stack_size, size_t memory_size)
{
	rocket_vm_t *vm = (rocket_vm_t *)malloc(sizeof(rocket_vm_t));

	if (!vm) {
		return NULL;
	}

	vm->code = code;
	vm->stack = (u64 *)malloc(stack_size);
	vm->locals = (u64 *)malloc(sizeof(u64) * memory_size);

	if (!vm->code || !vm->stack || !vm->locals) {
		return NULL;
	}

	return vm;
}

void
rocket_destroy_vm(rocket_vm_t *vm)
{
	free(vm->stack);
	free(vm->locals);

	free(vm);
}

void *
rocket_next(rocket_vm_t *vm, size_t size)
{
	void *ptr = (void *) &(vm->code[vm->registers[13]]);

	vm->registers[13] += size;

	return ptr;
}

rocket_result_t
rocket_execute(rocket_vm_t *vm)
{
	while (vm) {
		opcode_t opcode = ROCKET_NEXT(vm, opcode_t);

		switch (opcode) {
			case OP_NOP:
				break;
			case OP_BR:
				break;
		}
	}
}