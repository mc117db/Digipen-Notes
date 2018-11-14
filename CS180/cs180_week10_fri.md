# Week 10 - CS180 (Friday)
## Topic: Threading cont.
---
## 
- Lets simulate how a scheduler works
  - Example: The following are the time-slices that the example processes P1,P2,P3 needs.
    - P1 ( 10 ms CPU, 4 ms I/O, 3ms CPU)
    - P2 ( 3ms CPU, 4 ms I/O, 3ms CPU, 4ms I/O, 2ms CPU)
    - P3 ( 5ms CPU, 5ms I/O, 8 ms CPU)
  - Lets take non-preemptive scheduling (no control over scheduling)
  - (Insert picture here.)
- Priority Scheduling
  - Job with the smallest CPU burst will be given highest priority.
  - Scheduling also depends on external/internal factors.
    - Internal
      - Time limit
      - Memory sequence
      - number of open files.
    - External
      - How important the process is to the user
      - type/amount paid to run the process.
  - Cons:
    - Starvation - Low-priority process will not get CPU at all.
      - Using technique called Aging to overcome this problem
        - After every 15min/sec/ms. Increase priority of waiting process.
  - Example: The following are the time-slices that the example processes P1,P2,P3 needs.
    - P1 ( 10 ms CPU, 4 ms I/O, 3ms CPU)
    - P2 ( 3ms CPU, 4 ms I/O, 3ms CPU, 4ms I/O, 2ms CPU)
    - P3 ( 5ms CPU, 5ms I/O, 8 ms CPU)
    - (Insert Picture here)
