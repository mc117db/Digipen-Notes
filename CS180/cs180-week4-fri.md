# Week 4 - CS180 (Friday)
## Topic: OS Services
---
## OS Services
- int instruction
  - int 80h : invokes system call in the kernel
  - 80h is hexidecimal for 128
- In order to access any of the operating system services, you have to make a **system call**
- System calls are the only way to access these services.

## System calls
- Example: printf()
  - Calls the C library (clib)
  - Make a software interrupt (TRAP) by using int 80h
    - Interrupt Vector becomes 80h
    - Interrupt Flag becomes 1 (set)
  - Once the CPU notices that the IF became 1, it will go to the ISR located
  in the IDT at 80h. (The IDT is located by the address pointed by the IDTR)
  - The location of the specfied ISR is the address pointed by the IDTR + (4 times 80h)
    (assumming 32bit)
  - However, there is so many kinds of system calls available, how can we differentiate the specific type
  of system call that we want to execute?
    - Answer: By using the registers.
    - [Linux system call table](https://www.informatik.htw-dresden.de/~beck/ASM/syscall_list.html)
      - Depending on the register value in %eax, the particular system call is invoked.
      - Each value is mapped to a system call, for print in this example its (4) on %eax
    - For instructions that require parameters, the value is stored in the other registers
      - %ebx, %ecx, %edx, %esx, %edi
  - After a system call is executed, it needs to go back to the original calling process' next instruction.
  - That is done by calling IRET - Return to Original Calling Process.
    - Where can we find the original process next instruction? Surely we have to store it somewhere?
    - That instruction (value of the Program Counter) is stored in the STACK.
    - That instruction will be at the top of the stack before leaving the function.
    - The program counter will be set to that value, thus switching the context back before the system call.

- Example: Copying contents of file A onto file B
  - What are the system calls involved? Atleast 6 calls are needed.
    - OPEN File A
    - OPEN File B
    - READ FILE A
    - WRITE FILE B
    - CLOSE FILE A
    - CLOSE FILE B

- Difference system call and function call
  - System call: A call into kernel code, typically performed by executing a interrupt.
  - Function call: If calling a system call (via library), switches into kernel mode from user mode.

- Types of system calls
  - Control
    - Process
    - Files
    - Devices
    - Info
    - Communications
    - Protection



