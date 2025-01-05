# Set Up Virtual Machine in VirtualBox:

Open VirtualBox and click "New" to create a new virtual machine.
Select Linux as the operating system and Ubuntu 18.04 as the version.
Allocate memory and use an existing virtual hard disk. Browse to the unzipped VDI file and select it.
## Launch the Virtual Machine:
Once the virtual machine is created, select it and click "Start" to boot up the VDI file with the operating system and software.




# Writing, Compiling, and Running a Parameterized C Program Locally

Description:
In this task, a C program (sum1ton.c) is written to compute the sum of numbers from 1 to a user-specified value n. The program uses a loop for the computation and dynamically accepts the input from the user during execution. It is compiled using the standard GCC compiler available on the local Ubuntu system. After successful compilation, the program is executed to display the sum based on the input value of n. This task highlights the development and execution process for parameterized C programs on a host system.

Steps:

Use a text editor (e.g., leafpad) to write a C program that calculates the sum from 1 to n with user input.

Compile the program using the GCC compiler.

Execute the compiled binary (./a.out) and enter a value for n to compute and display the sum.


![Screenshot from 2025-01-05 15-08-35](https://github.com/user-attachments/assets/029b12f2-d530-4343-bd28-42a93ce4170b)

This program involves creating a simple C program (sum1ton.c) that computes the sum of numbers from 1 to 100.



# Compiling and Optimizing a Parameterized C Program for RISC-V Architecture

Description:
In this task, a C program (sum1ton.c) is written to calculate the sum of numbers from 1 to a user-defined value n. The program uses a loop to compute the sum and prompts the user to input the value of n. It is then compiled using a RISC-V cross-compiler (riscv64-unknown-elf-gcc) with optimization flags (-O1 and -Ofast) and specific parameters to define the ABI (-mabi=lp64) and the architecture (-march=rv64i). This ensures that the compiled code is optimized for execution in a 64-bit RISC-V environment.
The output is an object file (sum1ton.o), which can be executed in a RISC-V-based simulation or hardware platform. This task demonstrates how to target specific hardware architectures with cross-compilation.

Steps:

Write the sum1ton.c program that calculates the sum from 1 to n.

Compile the program using the RISC-V GCC compiler with the appropriate flags for optimization and architecture.

Verify the creation of the object file (sum1ton.o) by listing its details.

![Screenshot from 2025-01-05 15-22-30](https://github.com/user-attachments/assets/ebe12e37-010e-49e5-8cd3-22bafbb5ab78)
