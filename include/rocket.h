#ifndef ROCKET_H
#define ROCKET_H

/* Required for size_t */
#include <stddef.h>

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

/* Types */
typedef struct rocket_vm {
	u8 *code;
	u64 *stack;
	u64 *locals;
	u64 registers[16];
} rocket_vm_t;

/* Functions */
rocket_vm_t *rocket_create_vm(u8 *code, size_t stack_size, size_t max_memory);
void rocket_destroy_vm(rocket_vm_t *vm);
rocket_result_t rocket_execute(rocket_vm_t *vm);

#endif /* ROCKET_H */