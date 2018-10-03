# Week 4 - CS180 (Wednesday)
## Topic: System Calls and Architecture
---

## OS Roles, Services, System Calls and Architecture.
- Iternary
  - Roles of an OS
  - Services provided by OS
  - System calls
    - Interface between user program and OS
  - OS architecture
    - Organization and Design of OS code

- Roles of an OS
  - Role of OS
    - I/O Management
      - Manage Device drivers
        - User talks to the OS
        - OS talks to the device driver which works on the I/O Controller.
    - Storage Management
      - Files and Disks
        - Does defragmentation
          - Make sure that the portions of data are organised sequentially.
          - When data is arranged sequentially, don't need to jump around the disk to get the things you need.
        - File system.
        Different standard of storing data into the disk.
          - NTFS (New Technology File System)
            - New system use this.
          - FAT (File allocation table)
            - Old systems use this.
    - Memory Management
      - RAM
        - Allocation of memory for the processes
        - Protect memory from being written by another process
        - How to handle when we run out of RAM
    - Process Management
      - Starts and terminates processes
      - Coordinating processes (allowing processes to talk to one another,
      protecting them from one another)
      - When an .exe runs, it becomes a process (when its loaded by the Loader).
        - Instructions are loaded into memory.
        - Program stack/heap are allocated.
        - PC is set to the first instruction of the program.

- OS Services
![OS Services Table](https://i.imgur.com/yS9zUfr.jpg)
  - User interfaces with GUI/Batch files/Command Line
  - GUI makes System calls
  - System calls upon services to get the job done.
    - Only System calls can call upon services
    - What is a system call?
      - Can only be invoked only in the kernel mode.
      - User cannot invoke system calls directly
      - Only System API (which programs interfaces with) can invoke system calls.
    - Invoking a system call
      - "int" instruction
        - Generates a software interrupt.
        - int80h: 80h is the parameter of the interrupt instruction.
          - 80h refers to the interrupt vector number for the Interrupt Vector.
  - Services will work on the hardware.
    - This way, user doesn't need to know about the hardware of the system.

