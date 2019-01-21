# Week 2 - CS280 (Monday)
## Topic: Memory
---
## What does it mean by 32 bit architecture?
- It means that the computer can process 32 bits in one cache fetch.
- 32 bits of data is moved from the cache to the processor's registers (4 bytes)
- If a block of memory is greater than 32 bits, multiple fetches are required to process that data.
- However, a data structure like a linked list might store 32 bits worth of data all together but the location of the elements are not contiguous in memory thus multiple fetches are required for something that only require 1 fetch.
- An array would be better in this case as it has better **spatial locality**.
## Spatial Locality
- A Cache Line is 64 bytes
- Multiple Cache Lines (4) form a Cache Set.
- Theoretically, the Cache can be accessed in the form of A[ i ][ j ]
  - Where i is the cache set number and j can be up to the number of lines in a cache set. 
- How to create an physical address
  - In order to address a byte out of the 64 bytes in a cache line, we will need 6 bits as part of the address since 2^6 = 64.
  - These 6 bits will be the last 6 bits of the address (LSB), this is called the byte offset.
  - Next we need to address which cache line in the cache set. This is called the cache offset. Since there are 4 Cache Lines in a Cache Set, we will need 2 bits (2^2 = 4) to compute the cache offset.
  - The rest of the bits towards the front will make up the cache set number (also known as the tag).
## Alignment and the need for Padding
- Previously, we talked about the cache set and how it is consisted of cache lines, however if there was no alignment of the data, a block of data can potentially span over multiple cache line whereby with proper alignment, it can fit into one. 
- Hence it will require multiple cache fetches in order to retrieve the data.
  - This problem can be solved if the data is aligned to the cache line through the use of padding.
  - 


