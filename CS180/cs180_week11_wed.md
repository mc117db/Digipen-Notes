# Week 11 - CS180 (Wednesday)
## Topic: Process Scheduling cont.
---
## Preface
- Previously we have seen FCFS scheduling and Shortest-Job First Served scheduling, those kind of scheduling are non-preemptive, which means that they cannot force the current process to stop running.
- However, the later kind of scheduling, the SJFS scheduling is prone to a problem called starvation where the longer processes doesn't have a chance to run because there is a constant stream of shortest jobs coming in.

## Round-robin scheduling.
- Round-robin scheduling is a pre-emptive type of scheduling, which means that it can forcefully yield the current process to let other processes run.
- Time-sharing system
  - Each process will get a **time-slice** (somewhere to 10-100ms)
- The ready queue in Round-robin scheduling is a **circular-queue** (FIFO)
  - Circular queue
    - Linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle.
  - The advantage of round-robin scheduling is that many processes can run in concurrency in a single cpu
  - The disdavntage is that there is a bigger overhead of context switching. The efficiency of work is reduced.

## Algorithm of RR scheduling
  1) Get P from Ready Queue (head)
  2) Execute P for 1 time slice
      - Note that P can completed before its time-slice is up.
  3) If P doesn't complete, put P into end of Ready Queue.
  4) Repeat steps 1 to 4


## Multi-level Queue scheduling
  - A Pre-emptive scheduling algorithm.
  - There are different ready queues to represent different priorities of processes.
    - For example. System (0), User Jobs (1), Background (2)
      - Where 0 is the highest priority and the greater the number, the lower the priority.
  - Each queue are processed in Round-Robin algorithm too.

## Multi-level Feedback Queue
  - Another Pre-emptive scheduling algorithm
  - Multiple ready queues going by the FCFS scheduling algorithm.
  - Each ready-queue have a different time-slice.
  - If a process needs more time to execute, it will go down to a queue with a bigger time-slice.
 
