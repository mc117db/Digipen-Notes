# Memory Management Unit

Hardware to control access to memory.

The goal is to ensure that each process only has access to its own memory.

## Naive solution

  Allocate a single contiguous block to memory to each process

  Each process gets two numbers:
  * Base  - Start of address space
  * Limit - Amount of space the process gets

  These two numbers are passed to the MMU to calculate the real physical memory.

  Access to addresses outside of [base, base+limit) is a segmentation fault.

  Issue: Why should each segment of the process (text, data, stack, heap) be contiguous?

## Segmentation

  Allows the OS to split up the different segments of the process memory.

  Original model now fails, because we have multiple bases. Thus, we need to keep track of where each segment is.

  Hence,

### Segment Table

Keeps track of where each segment is. It resides in **physical memory**.

  #|Limit | Base
---|------|------
  0|   600|  1400
  1|   700|  2500
  2|   800|  4200
  3|  3000|  8000

**Segment table register** points to the first address of the segment table.

One segment table per process, its address is loaded into the STR when the process loads.

Virtual address contains segment number and offset

Segment number is bitshifted by three (multiplied by 8 - the size of an entry) then added to STR

This gives the new Base

Use the Base + Offset to get the physical address.

### Segmentation Fault

If you access something that you do not have, there is a segmentation fault.

## Memory Allocation

Best fit - Finds the smallest possible block to fit the requested block
Worst fit - Finds the largest possible block to fit the requested block
First fit - Grabs the first usable block