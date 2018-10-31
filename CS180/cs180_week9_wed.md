# Week 9 - CS180 - (Wednesday)
## Topic: Threads
---
## Threads, what are they?
- A Thread is a sequence of instructions that can be ran in parallel.
  - For example. Login application will have atleast two threads.
    - One for the UI and the other to do the actual work.
    - If not, your UI will be hanged when your computer is doing the work.
- Two types of threads
  - User created threads
    - Done by user library.
  - Kernel created threads
    - Done by the OS.
- Stack Frame 
  - A Stack Frame is consisting of...
    - Register save data
    - Local Variables
    - Function Params
    - old PC
    - old SP
  - Whenever there is a function call, you will be putting stack frames into the stack.
  - By looking at the stack frames, you can find the sequence of execution of function calls.
  - %esp stores the stack ptr register's val
  - %eip stores the PC register val.
- Back to threads
  - Threads are tied to a process, you cannot have a thread that isn't tied to a process.
    - If that process dies, the thread dies along with it.
  - Each thread will have its own.
    - Program Counter.
    - Stack Pointer.
    - and Stack regions.
  - Unlike creating new processes, creating new threads is cheap!
    - Resources can be shared instead of duplicated with threads
      - Threads share the same program static data
    - Threads can communicate with each other through the same shared data region. Removing the need for IPC stuff.
  - Threads are use for multi-programming, doing work in parallel.
    - Similiar to processes with use time-slicing to achieve parallelism, threads also behave in the same way.
## Multi-threading Models
- M : 1
  - Many users threads to 1 Kernel thread
    - Boost library
    - PThreads
    - Java Threads
    - Win Threads
- 1 : 1
  - For every user thread there will be a kernel thread too
- M : N
  - For every M user threads, there will be N (which is smaller than M) kernel threads
    - That means that the user threads will be sharing kernel threads.
- Note that only the kernel threads are known to the CPU, the CPU doesn't know anything about the user threads (threads reside in a process).


