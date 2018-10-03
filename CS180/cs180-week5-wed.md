# Week 5 - CS180 (Wednesday)
## Topic: System Calls
---
## How are system calls executed?
- int80 instruction (Software Interrupt Instruction aka. TRAP)
- Depending on register values on %eax, %ebx, %ecx. Different system calls will be executed.
  - Refer to [systable](https://www.informatik.htw-dresden.de/~beck/ASM/syscall_list.html) for more information
- System calls will always end with IRET instruction, return statement to calling process.

# DOS OS architecture
![DOS Architecture](https://i.imgur.com/T02nKhi.jpg)
- Single tasked
  - Can only load 1 application at the time.
  - Once application finished, need to load shell program.
- Shell invoked when system booted
- Simple method to run program
  - No Process created
- Single memory space
- Loads program into memory overwriting all but the kernel
- Program exit - shell is reloaded.

# Monolithic OS architecture
![Monolithic Architecture](https://i.imgur.com/jyeCLkK.jpg)
- Everything almost runs in kernel model.
- Example: Linux (Older version) - Newer version of Linux goes by a hybrid approach (Monolithic with Microkernel)
  - Can be though of one single file where every subsystems exist within the system.
  - A subsystem is a set of system calls/system procedures.
  - Everything is written in one single package.
- Pros and Cons
  - Pros
    - Calling function of subsystems is alot easier.
      - Design to implement the kernel is easier too.
    - Speed. Its alot faster as it doesn't need to go places to call system calls.
  - Cons
    - Scalablity issue, need to recompile entire kernel whenever you change something.
    - Any bug in a subsystem = entire system crashed.
      - The entire kernel is loaded in one single memory space.
      - Monolithic = one single space.

# Microkernel architecture.
![Microkernel](https://i.imgur.com/Fg2lUDg.jpg)
- Push stuffs out of kernel
- Client-Server model
  - All services will act as a server inside your OS.
  - If a user applicaton want to access the file system of example, the program is the client; the file system is the server.
- Applications communicate with each other using messages via interprocess communication.
- Example: Mac OS (Older version)
- Pros and Cons
  - Pros
    - If one of the services fails, it will not affect the kernel as its not a part of it.
  - Cons
    - Slow, everything communicates with each other with messages. Communicating this way will cause overhead. (Communication Overhead)
      - Small message delivered in big package? not good.
      - Messages need to go via the IPC (Interprocess Comms), cannot bypass it.

# Exo-kernel architecture
![Exokernel](https://i.imgur.com/z9jUvBw.jpg)
- Proposed by MIT
- Application oriented OS
  - Gives applications all of the control

#Questions
- Is OS using the CPU at all times?
  - Ans: No, when you boot up your OS, CPU wil stay idle and waits for user input.
- After booting and initialization, what are the circumstances that would cause OS code to use the CPU?
  - Ans: When there is a process that is created and running.

# Processes
## What is processes?
- Running program or program in execution.
  - Running program = .exe loaded into memory.
  - Whats the difference between a .exe in disk and a .exe that is running
  - Running program is loaded by the Loader
    - Running program is allocated its stack, heap
    - Program Counter will be pointing to some instruction in the running program
    text (where instructions reside) segment.
  - A Running Program has the following things.
    - Stack, Heap, Text, Data.
  - A Running Program is also known as a running process.
    - TL:DR Process = Active, Program = Passive.

- Processes are the basis for all computation
  - A Program is considered more efficient, the less processes it uses.
  - Process is a **unit of work**
  - Let say you have a program, your user program might have 1 or more processes.
    - Those processes are created and resides in the kernel space.
      - Every process have stack/heap/text/data.
