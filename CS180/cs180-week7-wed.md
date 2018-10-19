# Week 7 - CS180 (Wednesday)
## Topic: Context Switching
---
## What is saved for Context Switching
- User registers (including FPs, PC, SP)
- Status flags and toehr special registers.
- Wht registers only?
  - How about ALU, Control Unit and all the other stuff in Memory?
    - Ans: Treat ALU and Control Unit like a black box
    - Registers are the input into ALU and Control Unit
    - Save the register values and restore them later.
    - Same register values ensure the same behaviour from ALU and Control Unit.
    - Memory taken care of by OS memory management

## Software Context Saving
- Usually the 1st thing done in ISR
- Sometimes HW context saving doesn't save all the registers.
- SW context saving can be selective in what registers to save.
  - HW context saving cannot be selective. must save regardless if its required or not.

## Why hardware is needed for context switching.
- Need atleast hardware mechanism to save the program counter value before switching
  - Need to save PC through hardware context-saving
  - All other registers can be saved through software context saving.

___
## Inter-process Communication.
- There is need for mechanisms for processes to communicate with each other.
- Those mechanisms are called Inter-process Communication (IPC).
  - Advantages of IPC:
    - Speedup
    - Information Sharing
    - Modularity
    - Convenience for developer.
- 3 techniques of IPC:
  - Using "Pipes"
    - Build a pipe between process A and process B.
      - Output
        - Connect the output control to either one of the process via stdout then
        write into the pipe output.
          - By default, process will write onto stdout.
            - You need to close the process stdout, and make the porcess stdout
            write onto the pipe output; which is pointing to stdout.
      - Input
        - Connect the input control to the other process via stdin.
          - By default, process will read from stdin.
            - You need to close the process stdin, and make the process stdin read
            from the pipe input; which is pointing to stdin.
      - Process have a PIPE IN descriptor and a PIPE OUT descriptor.
        - Pipes will change where the process read and write from.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define READ_END  0
#define WRITE_END 1

int main()
{
  int pid;
  int descriptor[2];

  pipe(descriptor); // pipe will assign the pipe numbers for the
                    // reading end and the writing end of the pipes.
                    // They are some numbers assigned by the kernel.

  pid = fork();     // Take note that the descriptor values will be copied over.

  if (pid == 0)
  {
    // Child code
      printf("1st child PID is &d\n",getpid());

    // Close the reading end of the pipe for safety's sake
      close(descriptor[READ_END]);

    // close(1), which is the file description pointing to stdout
      close(1);

    // duplicate the writing end. Since 1 is the smallest file descriptor
    // available, 1 will point to the writing end after this.

      dup(descriptor[WRITE_END]);

      fflush(stdout);
  }

  else (pid > 0)
  {
    wait(NULL);

    printf("Parent PID is %d\n",getpid());
    close(descriptor[WRITE_END]); // I'm not using this end, close it

    close(0); // close 0, the file descriptor originally pointing to stdin

    // duplicate the reading end, since 0 is smallest file descriptor
    // available, 0 will point to the reading end after this.
    fprintf(stderr,"Before: %d \n",descriptor[READ_END]);
    dup(descriptor[READ_END]);
    fprintf(stderr,"After: %d \n",descriptor[READ_END]);

    //exec call to run wv
    char s[100];
    scanf("%s",s);
    printf("Parent: %s \n",s);

    scanf("%s",s);
    printf("Parent: %s \n",s);

    printf("Parent closing pipes",s);
    close(descriptor[WRITE_END]);
        close(descriptor[READ_END]);
  }
}
```
  - Shared Memory (In other lecture)
  - Message Passing (In other lecture)

___
## Tidbits
- wc command
  - returns number of lines, words, and file bytes of a file.
- Pipe token '|' shifts a process output to another process.