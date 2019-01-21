# Week 280 - CS280 (Wednesday)
## Topic: Memory Manager.
---
## Why we might need a memory manager
- Disadvantages of new/delete
  - Hidden Behaviour
  - Slow
    - When we call "new", we are actually calling a system call. When there is there is a system call, there needs to be a context switch from user mode to kernel mode so the system can request for memory. After requesting for memory, it will then go which back to user mode.
  - Memory Swapping
    - Pages that are not in use will be transferred into the hard drive and vice versa. If the memory is not managed based on life-time, there will be increased page swapping.
  - Thread Locking
    - For multi-threading, there might be multiple threads that are allocating memory. When Thread A allocates memory in location A, there is a chance for another Thread B to allocate in the same location A.
  - No statistical info
    - With a custom memory manager, we can do debugging and prevent memory leaks.

## Custom memory manager.
- A Custom memory manager needs to allocate and deallocate.
- Allocate
  - Needs to allocate a chunk of memory block
- Deallocate
  - Releases the allocated chunk of memory.
- Types of allocators
  - Linear Allocator.
    - Allocates items linearly
    - Starts from the head of the memory block
    - Has a tracking pointer that keeps track of the first available memory chunk.
      - Advantages
        - Fast because its allocating linearly
        - Low Overhead
      - Disadvantagesek
        - Free() is restricted
          - The tracking pointer doesn't know how many bytes behind the pointer not how large the chunk it is pointing at.
  - Stack Allocator.
    - We still have a tracking pointer, but in addition; each block will have a header block that contain the size of the block. We can do deallocation in a LIFO manner.
      - Advantages
        - Fast because its allocating linearly.
        - Low Overhead.
      - Disadvantages
        - More Overhead than Linear allocator.
  - Pool Allocator.
    - Block Size is fixed and we have two list that keep tracks of the blocks
      - Free list
        - Free list is a linked list that keep tracks of all of the free blocks.
      - Page list
        - Page list is a linked list that keep tracks of all of the blocks
          - A -> B -> C -> D
