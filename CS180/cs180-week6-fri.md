# Week 6 - CS180 (Friday)
## Topic: Forking
---
## Forking Process Primer part 2
- Whenever a process is forked, the regions of the stack/heap/data/text sections of the current process will be duplicated with a new Process Control Bus (PCB) created for it.
- What happens when there is a memory allocation that happens in the parent process **before** the fork command? 
  - i.e int* = new int( ); // its not going to be deleted?
  - Pointers are numerical values, will they get updated to reflect the new memory location in the child process?
  - Answer: Yes! The pointers will get updated as the values are not the physical memory address but rather the offset from the start of the program's memory region.

## Exec() Command Family
- Look at one of the exec() command that could be executed.
- **int execl(const char *path, const char *arg, ...)**;
  - Eg. execl("/bin/ls","ls","Program Files");
- inside library <unistd.h>
- However, when execl executes; ***it will override your current process's memory space with the program that you called with execl***, the Program Counter will then be pointing to that new process.
~~~
  #include <stdio.h>
  #include <unistd.h>

  int main()
  {
    printf("The exec system call will be called now");
    execl("ex1",0);
    print("Oops, there is something wrong with the execl call.");
  }
~~~
- When execl is called successfully, it will not call the line after it as the memory region of that process will be overridden with the new process "ex1"
- Therefore, if you want to keep your current process you need to fork your program to create a child process.
  - Your child process then calls execl to be replaced with the new process that is called with execl. 

## Other Exec() Commands
- The exec() family of functions replaces the current process image with a new process image. The functions described in this manual page are front-ends for execve( )
  - They are the following:
    - int execl(const char *path, const char *arg, ...);
    - int execlp(const char *file, const char *arg, ...);
    - int execle(const char *path, const char *arg, ..., char * const envp[]);
    - int execv(const char *path, char *const argv[]);
    - int execvp(const char *file, char *const argv[]);
    - int execve(const char *file, char *const argv[], char *const envp[]);
- The post-fix in the function will determine the behaviour of the exec function.
  - **e** – An array of pointers to environment variables is explicitly passed to the new process image.
  - **l** – Command-line arguments are passed individually (a list) to the function.
  - **p** – Uses the PATH environment variable to find the file named in the file argument to be executed.
  - **v** – Command-line arguments are passed to the function as an array (vector) of pointers.
- There is also a variable extern char **environ in <unistd.h> which tells you what is the [user environment](https://linux.die.net/man/7/environ) of the program.
- Another example
~~~
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) {
  int pid;
    fprintf(stdout,"creating child process\n");
    pid = fork();

    if (pid == 0)
    execl("/usr/games/gnome-sudoku","sudoku",NULL);

    else {
      fprintf(stdout,"waiting for child to
      terminate\n");
      wait(NULL);
      fprintf(stdout,"parent terminating\n");
    }
  return 0;
}
~~~
- Note that the exec( ) family all returns an int value
  - That value is the error code of the exec call.
  - [Error code references](http://man7.org/linux/man-pages/man3/errno.3.html)
  - If there is an error, the execl will fail and will execute the next instruction after the exec( ) command.
  - If you include <errno.h>, you will find the associated list of error codes.

## Grep from Linux
- Grep is an .exe that is present in cygwin/linux environments.
- Grep command is used to search for text. It searches the given file for lines containing a match to the given strings or words.
~~~
#include <stdio.h>
#include <unistd.h>
int main()
{
  printf("The exec is now called ... \n");
  execl("/bin/grep.exe","grep","-n","#inc","ek1.c","execl1.c",NULL);
  printf("OPPS")
}
~~~
- The first argument is the path to the grep.exe
- The second argument is the name of the executable without .exe postfix
- The third argument is the command line argument when executing grep
- The fourth argument is the substring to search
- The fifth/sixth argument is the files to search the substring from
- The last argument is the terminator for the execl command.
  - Another variant can be done as shown below.

~~~
#include <stdio.h>
#include <unistd.h>
int main()
{
  printf("The exec is now called ... \n");
  char* argv[] = {"/bin/grep.exe","grep","-n","#inc","ek1.c","execl1.c",NULL};
  execl("/bin/grep.exe",argv};
  printf("OPPS")
}
~~~

## Environment variable
- Environment variable is maintained by the OS
- If you run an exe files, it will use the environment variable from the OS
- If you want to use a custom environment variable, you need to define it yourself.

~~~
  char* envp[] = {
    "Home=/",
    "TZ=UTC+0",
    NULL
  }

  execle("ex1.exe",envp); // I'm passing in a custom environment to this program
~~~
