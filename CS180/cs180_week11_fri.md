# Week 11 - CS180 (Friday)
## Topic: Process Synchronization
---
## What does Synchronization mean?
  - It means coordination between processes.
    - especially multiple processes/threads that share data.
  - For example, P1 and P2 are running in parrallel and they are sharing an out variable.
    - In the ideal situation, P1 will write into the out variable and then P2 will read from that variable.
    - However, without process syncing that P2 might read the variable before P1 writes into it, which will cause problems.
    - Even if we have a dirty flag system that denotes that P1 have written into the variable. P2 would have to WAIT for P1 to write into the variable which will be inefficient.

## How do we do synchronization between multiple process
  - In the previous example, P1 is known as the producer and P2 is known as a Consumer.
    - the example is called the Producer-Consumer problem.
      - There is also that fact that code itself is non-atomic instructions
      - Also there is instruction inter-leaving where the compiler shifts instructions upwards to optimize speed.
      - The section of code that deals with shared memory/variables are known as the critical section.

## What is a Critical Section
 - In concurrent programming, concurrent accesses to shared resources can lead to unexpected or erroneous behavior, so parts of the program where the shared resource is accessed are protected. This protected section is the critical section or critical region. It cannot be executed by more than one process at a time.
 - Typically, the critical section accesses a shared resource, such as a data structure, a peripheral device, or a network connection, that would not operate correctly in the context of multiple concurrent accesses.
## General structure for Critical Section Solutions
```
while (true)
{
  // entry section eg, entryCS()
  critical section
  // exit secction eg, leaveCS()
  remainder section
}
```
- Solution criterias for Critical Section Solutions
  - 1) Mutual Exclusion
    - if Pi is in CS, then NO other Pj's should be in CS
  - 2) Progress
    - If NO Pi's is in CS, let say some Pj need CS
      - Who can decide Pj's entry to CS?
        - Only the processes which are not in the "Remainder" section.
  - 3) Bounded Waiting:
    - Bound/Limit to number of process that are allowed to enter CS after Pi request CS, and before the request is granted.

## Mechanisms for CS solution
- No enhanced supported
  - Peterson's Algorithm
  - Provide solution for P1 and P2
    - Has a global variable turn which takes in value 1 or 2
    - bool a integer array to denote interests
      - int interested[2];
        - interested[0] = true then P1 is ready to enter CS.
        - interested[1] = true then P2 is ready to enter CS.
```
  // ------------ Block Start -------------- //
  entryCS();
  cs;
  leaveCS();
  // ------------ Block End ---------------- //
  
  int turn;
  int interested[2];

  void EntryCS(int proc) // proc can be 0/1
  {
    int other;
    other = proc ^ 0x1; // Toggle
    interested[proc] = ture;
    turn = proc;
    while((turn == proc) && interested[other]);
  }

  void LeaveCS(int proc)
  {
    interested[proc] = false;
  }

``` 
- Hardware mechanism
- Sephamores

