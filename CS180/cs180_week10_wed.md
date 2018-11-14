# Week 10 - CS180 (Wednesday)
## Topic: Process Scheduling
---
## Process Scheduling
- We only have 1 CPU but we have multiple applications to run in "parallel"
  - We need some mechanism to choose a process in the pool of available processes
  to run in CPU. This is referred to as scheduling
  - If the process scheduling is not efficient, the OS performance will go down.
- We saw before that a process have 5 possible states.
  - Ready state
    - Process is ready to run
  - Run state
    - Process is running already
  - New state
    - Process is newly created and waiting to be added in the ready queue
  - Wait state
    - Process is waiting to be added in the ready queue (coming back from IO for example)
  - Terminated state
    - Process is terminated.

- Our process scheduler will be responsible for taking the process from the ready
state to the running state by choosing a process from the ready queue and also decided
when the currently running process is to be switched out.
  - We want to maximise the CPU utilization by always trying to keep it busy running processes.
  - Switching the CPU among processes increases efficiency and productivity.

- In a single process system.
  - For example, we have P1, P2, P3
  - If P1 was running and then goes into waiting then the CPU will be idle.
- In a multi-process system.
  - Sample example, We have P1, P2, P3
    - If P1 was running and goes into waiting then the scheduled processes will take over.

- Kinds of schedules
  - Preemptive
    - In preemptive mode, currently running process may be interrupted and moved to the ready State by the operating system.
    - When a new process arrives or when an interrupt occurs, if that process/interrupt has a higher priority than the current running process, it may get switched out for that.
    - Forcefully remove a process from the CPU
      - Doesn't have to wait for the process to go WAITING to be switched out.
      - When a higher priority process needs to be run, it will switch out the running process.
      - When Preemptive scheduling occures
        - HW interrupt arrives
          - Wait -> Ready
          - Run -> Ready.
  - Non-preemptive
    - In non-preemptive mode, once if a process enters into running state, it continues to execute until it terminates or blocks itself to wait for Input/Output or by requesting some operating system service. ie to say: Wait for the current process to finish before switching out.
  - The following cases can occur in both preemptive/non-premptive.
    - Process terminates.
    - Process goes to wait state.

- Processes/Threads
  - Computation vs IO
    - Computation of MxN matrix multiplication
      - CPU-Bound
    - Searching a file
      - I/O Bound
- For any Processes/Threads, there are bound to be CPU/IO bursts.
  - CPU burst is when the process is being executed in the CPU. I/O burst is when the CPU is waiting for I/O for further execution.
  - The beginning and the end of the process/thread will have to be a CPU burst.
  ```
  Think of a “burst” as a brief stretch of “run as fast as you can go until you can’t.”

  A CPU bursts when it is executing instructions; an I/O system bursts when it services requests to fetch information. The idea is that each component operates until it can’t.

  A CPU can run instructions from cache until it needs to fetch more instructions or data from memory. That ends the CPU burst and starts the I/O burst. The I/O burst read or writes data until the requested data is read/written or the space to store it cache runs out. That ends an I/O burst.

  The magic of an OS is the act of managing and scheduling these activities to maximize the use of the resources and minimize wait and idle time.

  In real life, a lot of this activity can be managed in parallel, but in OS design you should consider the dependencies between I/O and CPU activities and events and make sure that each subsystem can burst as effectively as possible.
  ```
  
- Kinds of queues
  - FIFO Queue
    - First in first out, pretty simple.
  - Priority Queue
    - Each process have a priority, the lower the number the higher the priority.
      - For example -> P1 (4), P2 (3), P3(2).
        - P3 is scheduled to be run next as its the highest priority.
  - Tree
  - Unordered linked list

- 3 Metrics for measuring performance of scheduling criteria/algorithms
  - Turn-around time.
    - Total time taken by a process from when it enters ready queue to until
    process terminates.
    - Entire lifetime of the process.
  - Waiting time.
    - Time taken by the process from the momment it enters ready queue to the time
    it actually starts running.
    - Total duration spent in the ready queue.
  - Response time.
    - Something to do with the I/O
    - The time it takes from when the process places a I/O request to when it is placed into the wait state.

