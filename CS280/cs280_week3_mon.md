# Week 3 - CS280 (Monday)
## Topic: Introduction to Algorithm Analysis
---
## Introduction
- An Algorithm is a well-defined computational procedure.
  - Benefits of Algorithm
    - Check the correctness of our solution.
    - Complexity, the amount of time and space of the algorithm.
      - Time Complexity, Big O (Worst Case Analysis)
- Question: Why do't we implement and check time by executing and recording the time taken?
  - May take a long time.
  - Cannot ensure the same environment for every execution
    - Operating system may do something that may differ per executing.
  - How to analyse time
  - The factors that we are interested are:
    - I/O Size (Size of Input).
    - Time taken to process output.
      - We are interested in the growth of time over the I/O size.
  - Example:
  ```
  int x; // C1
  int y; // C2
  int z; // C3
  for (int x = 0; s < N; x++)
  {
    for (int y = 0; y < N; y++)
    {
      z = z + 1; // C4
    }
  }

  // T(N) = C1 + C2 + C3 + C4 x (N^2)
  // The dominant term is N^2 in this case
  // The worst case is O(N^2)
  ```
- Data structures
  - Way to organise/store data for algorithms.
  - Data structures facilitates the accessing and updating of data.
    - An algorithm needs to be designed before the implementation of the data structure as the user needs determine the characteristics of the data structure.
- Example: Dictionary Application
  - Input: Words
  - Output: Meanings of words.
  - Data structure: Random order in storage, alphabetical order.
  - Algorithms that the app needs
    - Search
    - Sort
    - Mapping

