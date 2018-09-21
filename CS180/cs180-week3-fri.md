# Week 3 - CS180 (Friday)
## Topic: Interrupt Handling
---
## Interrupt Handling
- Interrupt Vector stores a number from 0-255
- Each number represents the priority of interrupt
- Whenever the interrupt is being handled, the Program Counter will fetch the
instruction stored on the IVT (Interrupt Vector Table).
  - IVT Representation
    | IV | ISR                          |
    |----|------------------------------|
    | 0  | Address of Service Routine 0 |
    | 1  | Address of Service Routine 1 |
    | 2  | Address of Service Routine 2 |
  - IVT can be thought of an array of function pointers.
  - The IVT is located in the memory.
  - Each entry in the IVT is contains a pointer to function which is to be called
  when the interrupt is being handled.
    - The PC is pointed to the start of the IVT first, depending on the priority number contained on the IV (Interrupt Vector), the PC will then be offseted by N x (size of pointer, 32bit = 4, 64bit = 8) where N is the number stored on the IV.
    - After that, that value stored in the PC will be indirectly addressed (go to the instruction stored in that location). That value is called a Interrupt Service Routine (ISR)
    - Before the ISR executes, the current instruction is pushed into the stack.
    - After the CPU finishes executing the Interrupt Service Routine, the PC is set to the previous instruction which the CPU was executing, which was stored to the stack.
- Questions: How do we know the address of the IVT?
  - Ans: It depends on the mode.

  | Real Mode  (Unprotected Mode)        | Protected Mode                  |
  |-----------------------------|---------------------------------|
  | Can Access BIOs + OS Subroutines       | Only OS Subroutines             |
  | Located at Physical Memory             | Logical + Physical Memory, 32/64|
  | Address is hardcoded, first entry is at 0x0000 | Address of IVT is stored in Interuppt Descriptor Table Register (IDTR)|
  - When the Computer boots up, the CPU be loaded in real mode.
    - Here any instruction can be executed, mostly BIOs instructions and some OS subroutines.
    - Once the controller (Bootloader) hands over the control to the OS (OS logo is shown), the mode is switched to the protected mode.
- Question: Can we change the IDTR?
  - Ans: The operating system will be the one that change the IDTR.
  - 

## Interrupt mechanism
- Interrupt mechanism also used for exceptions
  - Terminate proces, crash system due to hardware error
- Page fault executes when memory access error
- System call executes via **trap** to trigger kernel to execute request.
- Multi-CPU systems can process interrupts concurrently
  - Only if operating system designed to handle it.
- Used for time-sensitive processing, frequent, must be fast. 

## Direct Memory Address
- Used to transfer data without raising so many interrupts.
  - Alot of interrupts = low CPU utilization.
- Allow devices to read/write memory directly
without CPU intervention.
  - Does not mean accessing the memory in the
  same cycle.
  - Whether multiple devices (e.g. CPU) can access
  the memory at the same time depends on the
  memory design.
  - Allows CPU processing to be in parallel with
device to memory communication.
- Reduce number of interrupts.
- Done by the DMA Controller
  - Supports the CPU for bulk data transfer.
  - Avoids burdening Main CPU by transferring bulk data.
![DMA](https://i.imgur.com/2XYyoWi.jpg)
    - User initial transfer from one memory location to another
    - Disk controller (I/O Controller) will send a DMA request to the DMA controller and a WORD of data.
      - DMA request contains the following:
        - pointer to start location
        - pointer to destination
        - number of bytes to be transferred. (C)
    - DMA will seize the memory bus, it will stop the CPU from accessing the memory bus for the time being.
    - DMA will send acknowledgment back to the I/O Controller and transfers data to the destination pointed by the DMA request.
    - When a byte is transferred, the start pointer is incremented and the number of bytes is decremented.
    - When number of bytes to transfer is 0, DMA interrupts CPU to signal transfer completion.


