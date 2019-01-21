# Week 13 - Wed (Wednesday)
## Topic: Memory Management
---
## Managing the Main Memory
- Main Memory refers to the RAM
  - Memory is either byte addressable or word addressable.
  - A Word consist of 2/3/4 bytes, depending on the architecture.
    - This is because there are a finite addresses available.
  - Address Buses sizes also determine how many addresses can be generated.
    - 1 bit = 2 bytes
    - 2 bit = 4 bytes
    - 32 bits = 2^32 bytes = 4GB. 
## Logical/Physical Address
  - There are different kinds of addresses.
    - Physical Address
      - Refers to the actual addresses of the RAM
    - Logical Address
      - Known only to the CPU and the processes.
      - Maintained by the OS.
      - That address refers to where in the range of the processes's memory.
      - Different processes have different memory range.
        - However, processes do not know about physical address spaces, they
        only use logical addresses.
        - There has to be a conversion from logical to physical address space
        - This is done by the the MMU (Memory Management Unit).
    - When are the logical addresses of a process decided?
      - **During compile/link time binding**
        - Done during the older days
        - Logical addresses = physical addresses
        - Pros
          - No need for conversion from logical to physical address
        - Cons
          - When your process is located in some other place, you need to
          recompile again.
      - **During Load-time binding.**
        - Addresses are relative to some base address in physical memory
          - Each process have their own base address when it loads.
          - (Physical address) = Base Starting Address + Logical Address.
          - Checks are employed to see if the program tries to access before the
          starting base address and beyond the program limit, if so the MMU will
          throw a fatal error.
          - Pros
            - Processes can be located anywhere
          - Cons
            - Processes need to have contiguous block of memory.
            - Not able to run big processes in your RAM until a contiguous block
            of memory is available.
      - **Execution Time Binding**
        - The physical address is computed in hardware at runtime by the MMU
        - Program may be relocated during executing (even after its loaded)
        - Program does not require contiguous physical memory
          - Used by most modern OS

