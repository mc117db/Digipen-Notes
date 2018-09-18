# CS180 Week 2 - Friday
## Topic: I/O Device Lecture

---
## I/O Devices
- How does the user interact with the computer
  - Through the use of Input/Output devices.
  - There are many kinds of I/O Devices.
  - How can I/O devices become compatitable with the software.
    - For every I/O Devices have a **controller**.
    - Sometimes the controller is present in the motherboard, or the device itself; but there will always be a controller.
    - The Controller is hardware, the software to make the device work is called the driver.
      - Inside the I/O Controller, there are are registers called **Device Control Registers (DRC)**
        - Common Kinds of registers
          - Status Registers
            - Done-bit
            - Error-bit
          - Data-In/Out Registers
            - Small Buffer of First In First Out Chips (Queue)
              - 1 to 4 bytes in size.
              - Data is pushed in and read from the other end.
                - Data In Register read by CPU.
                - Data Out Register written by CPU.
          - Control Registers
            - Hold Commands from the CPU
                - Has special bits reserved to show status
                - Busy bit
                  - Is enabled when the device is busy.
                - Write bit
                  - Is enabled when the CPU wants to write onto the Data-Out registers.
        - There are other kinds of registers depending on the device but the above are mandatory.
        - The CPU will interact with the I/O Controller and into the I/O Device
        - I/O Device will interact with the I/O Controller and the CPU will read from the I/O Device.
      - CPU will interact with the controller by exchanging bit-patterns with the I/O Controller
  
        - Example: CPU wants to write 1 byte onto the I/O controller.
          1) CPU will check for the busy bit of the I/O controller, if so then it will wait.
          2) CPU will set write bit of command register.
          3) CPU will write a byte of data into the Data-Out Register.
          4) CPU will alert I/O by setting command ready bit.
          5) Controller will set the busy-bit.
          6) Controller will read the command registers, sees that the command is a Write Command
          7) Controller will read data from the Data-Out register and pass that data into the I/O Device to process.

    - CPU can communicate with the I/O Devices in one of two ways.
    ![Communication Diagram](https://i.stack.imgur.com/ra1Km.jpg)
    - From CPU to I/O Device

      - In/Out Instructions
        - Specific for transferring data into I/O Devices.
        - "Out" Writes to different memory ranges that is different than the program's memory which is the I/O Device memory.
  
      - Memory-mapped I/O
        - Use only one instruction called MOV
          - Only has one small range in the memory.
          - That memory is mapped into the I/O Device's memory.
        - Memory mapped I/O is a way to exchange data and instructions between a CPU and peripheral devices attached to it. Memory mapped IO is one where the processor and the IO device share the same memory location(memory).
        - The processor and IO devices are mapped using the memory address. Memory-mapped I/O uses the same address bus to address both memory and I/O devices, and the CPU instructions used are same for accessing the memory and also accessing devices.
        - Good for cases where you have large address spaces, you cannot afford to be addressing with the in/out instructions as there are too many of them. Eg. Graphic Cards