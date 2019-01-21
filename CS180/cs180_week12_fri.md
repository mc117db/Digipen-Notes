# Week 12 - CS180 (Friday)
## Topic: Scheduling Problems (cont.)
---
## Semaphores
- A semaphore is a variable or abstract data type used to control access to a 
common resource by multiple processes in a concurrent system such as a 
multitasking operating system.
- Two kinds of semaphores
  - Counting/General semaphores.
    - Semaphore variable can be set to N
    - N refers to max number of processes which can be in Critical Section (S)
  - Binary semaphore
    - Also known as mutex
    - Semaphore variable can be 0/1
- Wait and Signal Instructions
  - Wait is called upon entry of CS
    ```
    wait()
    {
      while (TESTANDSET(lock));
            s--;
      // s refers to the max number of process that can enter critical section.
      if (s <= 0)
      {
        // block the calling process
        lock = false;
        block();
      }
    }
    ```
  - Signal is called upon exit of CS
    ```
    signal()
    {
      while (TESTANDSET(lock));
      s++
      // Wake up any one of the sleeping (blocked) process, if queue is not
      // empty
      lock = false;
    }
    ```
## Sleeping Barber Problem
- The sleeping barber problem goes like this.
  - The barber is sleeping at the start, he is waiting for customers
  - If there are customers, he cuts the hair of one
  - If there are still customers, he cuts the next one's hair
    - Else he goes back to sleep if there is no customers.
```
sempahore barber   = 0;
sempahore customer = 0;
sempahore mutex    = 1;
int free_seats = N;

  void Barber()
  {
    while (true)
    {
      // Keep on checking for new customers.
      wait(customer); // Goes to sleep if there are no customers - LINE
         wait(mutex); // Lock the mutex
        free_seats++; // Takes one customer from the free seat, freeing a seat.
       signal(mutex); // Unlock the mutex
           haircut(); // Does the haircut (Critical Section)
    }
  }
```
```
  void Customer()
  {
    wait(mutex); // Lock the mutex
    if (free_seats > 0){
      // There is a free seat! Occupy it
          free_seats--; // Takes a seat
      signal(customer); // Signal the barber at Line A
         signal(mutex); // Unlock the mutex
          wait(barber); // Wait for the barber to be done with his current haircut
         get_haircut(); // Receive the haircut. (Critical Section)
    }
    else
    {
        signal(mutex) // Unlock the mutex
        // There is no free seat.
        LeaveTheShop();
    }
  }
```
- What is the mutex used for?
  - To lock on the free_seat variable, only 1 thread can modify this variable
  at one time, either the Barber, or a customer.
## Dining Philosopher's Problem
- 
![](https://itsphbytes.files.wordpress.com/2016/09/dining-philosopher.png)

```
  semaphore chopsticks[N];
  while (true)
  {
    wait(chopsticks[i]);
    get_left();
    wait(chopsticks[i&N]);
    get_right();
    eat();
    signal(chopsticks[i]);
    signal(chopsticks[i&N]);
    think();
  }
```
- However, there is a problem with this code. If all philospher pick up the same side fork at the same time, for the adjacent philosphers they will see that the other fork will not be free. Thus, there will be a circular waiting lock.
```
  semaphore chopsticks[N];
  while (true)
  {
    
  }
```