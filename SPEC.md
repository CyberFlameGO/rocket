# Instruction Set

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
