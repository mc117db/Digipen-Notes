# CS180 Week 3 - Tues
## Topic: I/O Device Lecture 2
---

## CPU to I/O
- Memory-mapped I/O
  - Uses software to wait for I/O
  - Can check status registers at fixed times
  - Pros
    - Fast response time (for program waiting)
    - Low CPU utilization (CPU keeps on checking on the I/O Devices to see if 
      its free or not, wasting cycles)
      - Main task of CPU is to do computation
      - Waiting is a waste of resources. (Polling)
- Special instructions
  - I/O ports
    - Different address spaces for memory and I/O devices
    - E.g. Intel IN, OUT instructions
    - Register I/O instructions: IN/OUT move data between I/O
    ports and the EAX (32-bit I/O), AX (16-bit I/O) or AL (8-bit
    I/O) general registers.
    -Block I/O instructions: INS/OUTS move blocks of data
    between I/O ports and memory space

## I/O to CPU
- Polling
  - CPU keep on checking on I/O device command register whether there is a
    command for the CPU to read the data.
- Interrupts
  - CPU only stops when the I/O Device raises an interrupt, the CPU will stop
    whatever its doing and address the interrupt from the I/O Device.
  - CPU stops its execution and attends to the I/O Device
    ![Diagram of I/O layout](https://i.imgur.com/U7IDeik.png)
    - Interrupt flag (IF)
      - 1 Bit flag, you can set the flag and clear it
        - 1 = interrupt, 0 = no interrupt.
      - This flag resides in the CPU
      - Has wires that are connected to all of the I/O devices.
    - Interrupt Vector (IV)
      - Stores a number ranging to 0-255
      - Each number represents type of the interrupt, varying of the kind of CPU
      ![Intel Interrupt table](https://i.imgur.com/NzEUTJi.png)
        - From 0-18 are numbers reserved for error events
        - 19-31 are unused (Intel reserved)
        - 32-255 are maskable interrupts for the I/O controllers, one for 
          each I/O controller
- Interrupt handling
    ![Interrupt process](https://i.imgur.com/ywbq8Jn.png)

- Kinds of Interrupts
  - 3 Kinds of Interrupts
    - Exceptions/Faults: errors like divide by zero
    - Hardware interrupt: I/O faulty
    - Software-generated interrupt: System calls.
  - Maskable and non-maskable
    - Maskable refers to "can be turned off"
    - Usually execuptions/faults are not maskable, need to be addressed immediately.
  - Interrupt priority
    - Interrupt handling can be interrupted by higher priority interrupts.
      - Remember the IV? the lower the number, the higher the interrupt.

- ISR (Interrupt Service Routine)
  - Software handling of interrupts.
  - ISR codes are stored in the memory.
    - That place is called the Interrupt Vector Table (IVT)
  - For every number in the IV, there is an ISR location associated to it
    - Every ISR address contain a set of instructions tied to it.
  - When an interrupt of that kind is raise, instructions in that ISR location
    will be executed.
    - The program counter will be set to the first instruction of the ISR
    - The program counter will then be offsetted by N * 8 or N * 4 whether the
      architecture is 64 or 32 bit, where N is the interrupt priority.
    - After CPU finishes executing ISR, PC is set to the previous instruction
      that the CPU was executing.
