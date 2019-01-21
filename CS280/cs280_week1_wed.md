# Week 1 - CS280 (Wednesday)
## Topic: Data Structures
---
## Data Structures
- Data structures are ways to represent chunk(s) of memory
  - That memory may be contiguous or not.
    - Memory can be of different size.
      - Bit
      - Byte (8 bits)
      - Block (Multiple Bytes)
      - Cache Line size 64 bytes (in x86)
    - HDD and Memory (RAM) is block addressable.
- Whenever you choose a data structure for your problem, you have to consider.
  - What you wish to be able to do with it?
    - Do you need it to be?
      - Dynamic Size?
      - Random Access?
      - Other Functions?

## Memory
- HDD to DRAM takes about 500ms, this kind of time is very slow.
- Therefore we have to store stuff in the Cache (SRAM)
  - Accessing the SRAM takes about 1ms!
- Concept of Locality
  - Temporal Locality
    - Refers to the reuse of data, within a relatively small time frame.
  - Spatial Locality
    - Refers to data elements that are within relatively close data locations.
      - Array:
        - Elements are placed in contiguous memory.
        - When an array is moved from the main memory into the cache, blocks of memory is moved at one time.
        - The block of memory that move into the cache doesn't contain the data that the user wants, that is called a **cache miss**.
          - eg: array is 8 bytes, cache only can hold 3, user wants to access element 7.
          - 3 bytes of the array is moved into cache (0-2), first time doesn't contain element user wants, cache miss.
          - another 3 bytes is moved into cache (3-5), still a cache miss.
          - finally the last 2 elements (6-7) is moved to cache, with the element that user wants.
- Improving Cache Accesses
  - Even though cache access is very fast, linear searching of data will take some time.
  - Cache Set Concept
    - Blocks of bytes are arranged into sets of data so that it is easier to load and search for data.