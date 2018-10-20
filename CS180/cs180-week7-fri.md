# Week 7 - CS180 (Friday)
## Topic: Pipes / Shared Memory
---
## Regarding Pipes
- The basic idea is that a pipe is a FIFO stream of bytes between two processes.
- Named pipes and Anonymous Pipes
  - Named pipes
    - Sharable between any procecess
    - Full Duplex in Windows
      - Same pipe, you can communication both ways
    - Half Duplex in Linux
      - Only uni-directional
    - Obtain the pipe by the name of the pipe
  - Anonymous Pipes
    - Sharable between processes of the same ancestory
    - Unidirectional
    - Obtain the pipe from the parent.
- Every process have 3 processes.
  - stdin
  - stdout
  - stderr
- If the process creates a pipe, it will have 2 more pipes open which is your **PIPE-IN** and **PIPE-OUT**.
![Pipe diagram](https://i.imgur.com/vFMgool.jpg)
- If you spawn another child process, it would have the same pipes opened.
- ![Child pipe](https://i.imgur.com/MoZViiM.jpg)
  
## Unix file descriptors
- Unix/Linux files are numbered
  - 0, 1, 2 … etc
  - 0 is stdin, 1 is stdout, 2 is stderr
  - By default,
  - scanf and std::cin gets input from stdin.
  - printf and std::cout will print to stdout.
  - The default “file” opened for stdin, stdout and
stderr will be the console. (where you can
observe the printing)
- However, using redirection, we can actually get
0, 1 or 2 to be “files” other than the console.

## Using Dup( )
- close() system call closes a pipe which renders the file descriptor invalid.
- The dup() system call duplicates the given file descriptor using the lowest available file descriptor number.
![Dup](https://i.imgur.com/JRiZt28.jpg)

## Shared Memory
- The basic idea is two processes shared a common memory region. This memory region does not belong to either process (not in the program) but somewhere that is allocated by the kernel.
- Process A and Process B has to have a common key.
- When this key is passed to a system call shmget()
  - shmget(key, size of memory, permission flags)
  - shmget will return the shared memory id (smid)
    - If the shared memory already exist, it will return the id.
    - If not, it will create a new shared memory block and return the id.
- You need to attach Process A to the shared memory
  - [shmat](https://linux.die.net/man/2/shmat) (shared memory attach)
  - void* **shmat** (smid[thats your id], ... some other variables not important now); 
  - shmat will return the address of the shared memory.
  - shmctl(...) Shared Memory Control
    - Will delete the shared memory.
    - Can be called by either of the process.
## Queue
- The basic idea is that there is a FIFO data structure that contains "messages" that will allow processes to send messages to another.
- The queue itself have an id which determines where the messages are routed to which process.
___
## Tibits
- Permission flags
  - is an octal number with 3 groups of 3 digits.
  - Each group corresponds to the following. Owner, Group, User
  - Each number of the 3 digit group corresponds to the following.
    - Read, Write, X-ecute
  - So the OCT number 666  (110 110 110 in binary) corresponds to.
    - Owner can read,write but cannot execute.
    - Group can read,write but cannot execute.
    - User can read,write but cannot execute.
