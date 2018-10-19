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



