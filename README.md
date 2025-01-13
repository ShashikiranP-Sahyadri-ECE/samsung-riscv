# RISC-V Talent Development Program

RISC-V Talent Development Program, powered by Samsung Semiconductor India Research (SSIR) along with VLSI System Design (VSD).

# Basic Details

Name: Shashikiran P

College: Sahyadri College of Engineering & Management, Mangaluru

Email ID: shashikiran.ec22@sahyadri.edu.in

GitHub Profile: [ShashikiranP-Sahyadri-ECE](https://github.com/ShashikiranP-Sahyadri-ECE)

LinkedIN Profile: [Shashikiran P](https://www.linkedin.com/in/shashikiran-p-aaa603268/?originalSubdomain=in)





# Task 1



## Set Up Virtual Machine in VirtualBox:

Open VirtualBox and click "New" to create a new virtual machine.
Select Linux as the operating system and Ubuntu 18.04 as the version.
Allocate memory and use an existing virtual hard disk. Browse to the unzipped VDI file and select it.
### Launch the Virtual Machine:
Once the virtual machine is created, select it and click "Start" to boot up the VDI file with the operating system and software.

![Screenshot from 2025-01-05 21-20-53](https://github.com/user-attachments/assets/c3b17e81-c054-42ea-9c82-c749f8a1842e)



## Writing, Compiling, and Running a Parameterized C Program Locally

Description:
In this task, a C program (sum1ton.c) is written to compute the sum of numbers from 1 to a user-specified value n. The program uses a loop for the computation and dynamically accepts the input from the user during execution. It is compiled using the standard GCC compiler available on the local Ubuntu system. After successful compilation, the program is executed to display the sum based on the input value of n. This task highlights the development and execution process for parameterized C programs on a host system.

Steps:

Use a text editor (e.g., leafpad) to write a C program that calculates the sum from 1 to n with user input.

Compile the program using the GCC compiler.

Execute the compiled binary (./a.out) and enter a value for n to compute and display the sum.


The sample program is given by [sum1ton.c](https://github.com/ShashikiranP-Sahyadri-ECE/samsung-riscv/blob/main/Task%201/sum1ton.c)


![Screenshot from 2025-01-05 15-08-35](https://github.com/user-attachments/assets/029b12f2-d530-4343-bd28-42a93ce4170b)

This task involves creating a simple C program (sum1ton.c) that computes the sum of numbers from 1 to 100.





## Compiling and Optimizing a Parameterized C Program for RISC-V Architecture

Description:
In this task, a C program (sum1ton.c) is written to calculate the sum of numbers from 1 to a user-defined value n. The program uses a loop to compute the sum and prompts the user to input the value of n. It is then compiled using a RISC-V cross-compiler (riscv64-unknown-elf-gcc) with optimization flags (-O1 and -Ofast) and specific parameters to define the ABI (-mabi=lp64) and the architecture (-march=rv64i). This ensures that the compiled code is optimized for execution in a 64-bit RISC-V environment.
The output is an object file (sum1ton.o), which can be executed in a RISC-V-based simulation or hardware platform. This task demonstrates how to target specific hardware architectures with cross-compilation.

Steps:

Write the sum1ton.c program that calculates the sum from 1 to n.

Compile the program using the RISC-V GCC compiler with the appropriate flags for optimization and architecture.

Verify the creation of the object file (sum1ton.o) by listing its details.


![Screenshot from 2025-01-05 15-22-30](https://github.com/user-attachments/assets/ebe12e37-010e-49e5-8cd3-22bafbb5ab78)

![401392602-f994fca2-f760-4eae-a46b-b09de0c67caf](https://github.com/user-attachments/assets/805f6522-7020-44f1-873e-d9b2f9277384)

<br>
<br>
<br>



# Task 2

## Multiplication Table 

## Overview
This task involves the compilation and execution of a simple C program that generates a multiplication table for a given integer. The process demonstrates how to:
1. Compile the program for a RISC-V target architecture using the `riscv64-unknown-elf-gcc` compiler.
2. Simulate the execution of the compiled program using the Spike RISC-V simulator.
3. Disassemble the generated object file to examine the machine code and assembly instructions.

## Task Steps

### 1. **C Program Description**
The C program (`multiplication_table.c`) takes an integer input from the user and prints its multiplication table up to 10.

#### Program Code:
```c
#include <stdio.h>

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    for (int i = 1; i <= 10; ++i) {
        printf("%d * %d = %d\n", n, i, n * i);
    }

    return 0;
}
```

![Screenshot from 2025-01-13 21-56-52](https://github.com/user-attachments/assets/258e9eae-6b18-44a8-b748-d8d03a3cfdfb)

![Screenshot from 2025-01-13 22-04-39](https://github.com/user-attachments/assets/ed6f066e-8d8e-4718-a995-8292d0df2fc4)
### 2. **Compiling the Program**
The program is compiled using the `riscv64-unknown-elf-gcc` compiler with the following options:
- `-Ofast`: Enables high-level optimizations.
- `-mabi=lp64`: Specifies the 64-bit little-endian ABI.
- `-march=rv64i`: Targets the RISC-V 64-bit instruction set.

#### Command:
```bash
riscv64-unknown-elf-gcc -Ofast -mabi=lp64 -march=rv64i -o multiplication_table.o multiplication_table.c
```

### 3. **Running the Program in Spike Simulator**
The compiled program (`multiplication_table.o`) is executed in the Spike RISC-V simulator. The program uses the Proxy Kernel (PK) to facilitate execution.

#### Commands:
1. **Run the program**:
    ```bash
    spike pk multiplication_table.o
    ```
   **Output Example:**
    ```
    Enter an integer: 4
    4 * 1 = 4
    4 * 2 = 8
    4 * 3 = 12
    ...
    4 * 10 = 40
    ```

2. **Debug with Spike:**
    ```bash
    spike -d pk multiplication_table.o
    ```
    This command enables debugging, allowing inspection of registers and program flow.

#### Debugging Example:
- Break at a specific PC (program counter):
    ```
    until pc 0x100b0
    ```
- Inspect registers or memory:
    ```
    reg a0
    ```

### 4. **Disassembling the Object File**
The object file is disassembled to view the assembly instructions corresponding to the compiled code. This provides insights into how the program executes at the hardware level.

#### Command:
```bash
riscv64-unknown-elf-objdump -d multiplication_table.o
```

![Screenshot from 2025-01-13 22-20-15](https://github.com/user-attachments/assets/8e461305-f30c-4c24-ae28-c52efd1911f2)

#### Example Disassembly Output:
```asm
00000000000100b0 <main>:
100b0:   0002b537                lui     a0,0x2b
100b4:   00f01113                addi    sp,sp,-64
100b8:   ...
```



## Tools Used
1. **Compiler**: `riscv64-unknown-elf-gcc`
2. **Simulator**: Spike (RISC-V ISA Simulator)
3. **Disassembler**: `riscv64-unknown-elf-objdump`

## Purpose
This task demonstrates:
1. Cross-compilation for a RISC-V architecture.
2. Using the Spike simulator for running and debugging RISC-V binaries.
3. Analyzing the low-level assembly output of a compiled program.

## Requirements
- RISC-V GNU Compiler Toolchain.
- Spike RISC-V Simulator.
- A Linux environment (e.g., Ubuntu).


## Execution Environment
The screenshots provided illustrate the task being performed in a Linux virtual machine environment, using a terminal for compiling, running, and debugging the program.

