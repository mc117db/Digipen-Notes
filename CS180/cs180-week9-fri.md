# Week 9 - CS180 (Friday)
## Topic: Threads cont.
---
## Multi-threaded Model
- The 3 kinds of models
  - **M : 1**
    - M user threads to 1 kernel thread.
      - Pros:
        - lesser kernel threads are created.
          - Creating a kernel thread is slower and more expensive than creating a user thread.
          - Scheduling decisions have to be made by the OS to create a kernel thread.
      - Cons:
        - If a user thread wants to call a system call but its being in used right now, that user thread have to wait for the kernel thread to be free.
          - Not really running in parallel but taking turns to use the kernel thread.
          - Can't exploit parallel processing (also known as concurrency) using multiple cores.
  - **1 : 1**
    - a user thread to a kernel thread.
      - Pros:
        - More concurrency, exploits parallel processing in multiple CPU.
      - Cons:
        - **Huge** overhead in managing the kernel threads.
  - **M : N**
    - M user threads sharing N (smaller than M usually) threads.
      - Pros:
          Has the advantages of both M:1 and 1:1 model.

## User threads vs Kernel threads.
- User Threads
  - Cheaper & Faster
  - Run-time system
  - 100 times faster than K.T, in terms of creating and destroying.
  - Concurrency depends on the amount of kernel threads.
- Kernel Threads
  - Complex & Expensive to maintain. 
    - Expensive as in: need to manage both process/threads.
  - Managed by the OS
    - Scheduler's complexity is increased (need to manage both process/thread)
  - K.T usually slower.
  - More concurrency when there are more kernel threads.

## How to create user threads using PThread
- PThread is used to create user threads
  - Four methods that you need to know.
    - Creation
      - pthread_create(...)
        - Creates a new thread.
    - Termination
      - pthread_exit(...)
        - Exit a thread.
    - Join
      - pthread_join(...)
        - Something to "wait" where a parent waits for a child.
        - Blocks (or wait) a calling thread until specific event has occurred.
          - For example: t1 is waiting on t2... when t2 **exits**, then t1 will continue executing.
    - yield
      - pthread_yield(...)
        - thread will voluntarly give up CPU for other thread.

