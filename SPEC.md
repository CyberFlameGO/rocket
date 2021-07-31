# REX File Format

.rex (Rocket Executable) is a file format that defines a Rocket executable program.

The files contains two major sections, the header and the body. The header contains information such as exported symbols, entry point offset, and how much memory the application may need to execute properly. The body contains the actual bytecode instructions.

**Magic Bytes:**

In order to define a proper REXecutable file, the first three bytes in the file must match the following magic bytes (to mark the file as a valid REX file):

*Magic Bytes:* 52 45 58

**Header Sections:**

Here is a list (in order) of the sections in the header that you must fill in.

* (u64) Entry Point Offset
* (u64) Sizeof Symbols Section
* ^ that many bytes after this will be the entire symbols section

**Header Symbols:**

To create a symbol, you must follow this format in the **symbols section** of the REX header.

* (u8) Symbol Type
* (u64) Hashed symbol name
* (u64) Symbol Location Offset

*Symbol Types:*

| u8 id | Description      |
| ----- | ---------------- |
| 0     | i8               |
| 1     | u8               |
| 2     | i16              |
| 3     | u16              |
| 4     | i32              |
| 5     | u32              |
| 6     | i64              |
| 7     | u64              |
| 8     | f32              |
| 9     | f64              |
| 10    | ascii string     |
| 11    | unicode string   |
| 12    | label (function) |

# Opcode Format

Each opcode should be written as a **single unsigned byte**, and operands should match the size listed in the opcode table below.

**Example RASM (Rocket Assembly):**

MLR    0,    0

**Example Hex:**

0x0B    0x0    0x0000

**Example Binary:**

00001011 00000000 00000000 00000000 00000000 00000000

# Instruction Set

Opcode values (as bytes) starts at 0 with **NOP** and increases by **one** for every instruction on this list.

| Opcode | Parameters                                | Description                                                           |
| ------ | ----------------------------------------- | --------------------------------------------------------------------- |
| NOP    |                                           | No operation                                                          |
| BR     | (u64) Address                             | Branch to address                                                     |
| RET    |                                           | Return from branch                                                    |
| JMP    | (u64) Address                             | Jump to address                                                       |
| JSR    | (u8) Register Index                       | Jump to address in register                                           |
| LDL    | (u32) Local Index                         | Load local value onto stack                                           |
| LDR    | (u8) Register Index                       | Load register value onto stack                                        |
| LDG    | (u64) Global Address                      | Load global value onto stack                                          |
| STL    | (u32) Local Index                         | Store top stack value into local                                      |
| STR    | (u8) Register Index                       | Store top stack value into register                                   |
| STG    | (u64) Global Address                      | Store top stack value into global                                     |
| MLR    | (u8) Register Index, (u32) Local Index    | Copy local value into register                                        |
| MLG    | (u32) Local Index, (u64) Global Address   | Copy local value into global                                          |
| MRL    | (u8) Register Index, (u32) Local Index    | Copy register value into local                                        |
| MRG    | (u8) Register Index, (u64) Global Address | Copy register value into global                                       |
| MGL    | (u32) Local Index, (u64) Global Address   | Copy global value into local                                          |
| MGR    | (u8) Register Index, (u64) Global Address | Copy global value into register                                       |
| POP    |                                           | Remove top stack value                                                |
| LLA    | (u32) Local Index                         | Load effective address of local                                       |
| LEA    | (u64) Program Offset                      | Load effective address of location in program                         |
| ADD    |                                           | Add top two stack values and push result                              |
| ADDR   | (u8) Register Index, (u8) Register Index  | Add values in both registers and store value in first register        |
| SUB    |                                           | Subtract top two stack values and push result                         |
| SUBR   | (u8) Register Index, (u8) Register Index  | Subtract values in both registers and store value in first register   |
| MUL    |                                           | Multiply top two stack values and push result                         |
| MULR   | (u8) Register Index, (u8) Register Index  | Multiply values in both registers and store value in first register   |
| DIV    |                                           | Divide top two stack values and push result                           |
| DIVR   | (u8) Register Index, (u8) Register Index  | Divide values in both registers and store value in first register     |
| REM    |                                           | Divide top two stack values and push remainder as result              |
| REMR   | (u8) Register Index, (u8) Register Index  | Divide values in both registers and store remainder in first register |
| OR     |                                           | OR top two stack values and push result                               |
| ORR    | (u8) Register Index, (u8) Register Index  | OR values in both registers and store value in first register         |
| XOR    |                                           | XOR top two stack values and push result                              |
| XORR   | (u8) Register Index, (u8) Register Index  | XOR values in both registers and store value in first register        |
| AND    |                                           | AND top two stack values and push result                              |
| ANDR   | (u8) Register Index, (u8) Register Index  | AND values in both registers and store value in first register        |
| NOT    |                                           | NOT top two stack values and push result                              |
| NOTR   | (u8) Register Index, (u8) Register Index  | NOT values in both registers and store value in first register        |
| LDI8   | (i8) Value                                | Load value onto stack                                                 |
| LDU8   | (u8) Value                                | Load value onto stack                                                 |
| LDI16  | (i16) Value                               | Load value onto stack                                                 |
| LDU16  | (u16) Value                               | Load value onto stack                                                 |
| LDI32  | (i32) Value                               | Load value onto stack                                                 |
| LDU32  | (u32) Value                               | Load value onto stack                                                 |
| LDI64  | (i64) Value                               | Load value onto stack                                                 |
| LDU64  | (u64) Value                               | Load value onto stack                                                 |
| LDF32  | (f32) Value                               | Load value onto stack                                                 |
| LDF64  | (f64) Value                               | Load value onto stack                                                 |
