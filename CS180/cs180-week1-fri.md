# CS180 Week 1 - Friday
## Topic: Computer Architecture Lecture

---
## Computer Architecture
- Shell is the part that interacts with the user
- Kernel is the part that interacts with the hardware.

## Registers
- Program Counter
  - Store the address of the next instruction to be executed.
- General Purpose Register
  - Used for common operations.
- Stack Counter
  - Store the address of the top of the stack. Used to keep track of the stack.
- Instruction Register
  - Store the actual instruction to be decoded and executed.
  
## Loader
- Able to read the executable format
- Copy the text and data segments into the correct memory
  addresses.
- Allocate space for Stack and heap for the new running
  program
- Set the Program Counter value to the address of the
  starting instruction of the loaded program.
- The newly loaded program runs

## The Boot-up Process
- Power On
- BIOS
  - POST - Power On Self Text
  - Program Counter gets mapped to 0xFFFF FFFF
  - Look for bootable devices (HDD, USB Devices, Network)
    - Looks for bootable devices' MBR (Master Boot Record)
    - MBR contains the bootable codes of the OS
  - BIOS load and run the MBR
  - MBR may load Bootloader/Bootmanager. Eg. GRUB in Ubuntu
  - Load and Run OS

## Services that OS Provides
- Interface/Abstraction
  - Removes the need for low-level details.
- Manages System Resources like:
  - Physical (Actual Physical Devices)
    - Shared by all the programs
    - Virtualization will convert physical resources into logical ones.
  - Logical
    - Virtual view of resources
    - Exclusive to each program.
- Security
  - Prevents application from messing with low-level details.
  
- Resources can either be the following:
  - Time-shared
    - CPU-Mouse,Keyboard,Printer etc.
      - Takes turns to use the whole device.
  - Partitioned
    - Memory, Display devices etc.
      - Shares a portion of the resource.