# Week 12 - CS180 (Wednesday)
## Topic: Scheduling Problems cont.
---
## Hardware Lock
- Test and Set
  - 
- Compare and Swap
  - a technique used when designing concurrent algorithms. 
  - NOT A FUNCTION, but is a single atomic instruction. Atomic here means non-interruptable.
  - Basically, compare and swap compares an expected value to the concrete value of a variable, and if the concrete value of the variable is equals to the expected value, swaps the value of the variable for a new variable.
- Instruction behaviour
  ```c++
  int compareandswap(int* value, int expected_val, int new_val)
  {
    int temp = * value;
    if (*value == expected_val){
      *value = new_value;
    }
    return temp;
  }
  ```
- Usage
  ```c++
  int lock = 0;

  // Entry Section
  while(compareandswap(&lock,0,1) != 0);
  // Critical Section
  lock = 0;
  // Remainder section
  ```

## HW Solutions
- TestAndSet and CompareAndSwap are HW instructions!
  - They are atomic intstructions
  - Require hardware design
  - Fails bound waiting requirement.

