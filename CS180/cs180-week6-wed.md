# Week 6 - CS180 (Wednesday)
## Topic: Forking Processes Primer
---
## Fork Command
- **int fork( )**
- inside library unistd.h
  - Creates another process of the current program which runs at the instruction after the fork command is executed.
- Fork also returns the program id (pid) of the newly created process.
  - If the pid is 0, its the child process
  - If greater than 0, its the parent process.

## Get Program ID Command
- **int getpid( )**
- inside library unistd.h
- Returns the program id of the current running process.

## Wait Command
- **wait(NULL)**
- inside <sys/wait.h>
- By calling this command, the parent process will wait for the child process to complete first before resuming executing after that wait command.
- Takes in a L-val int, will be set to the exit value of the child process.

## WIFEXITED(status)
- Macro that checks if an int contains an exit code.

~~~
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>

int main ()
{
	std::cout << "Parent Process ID: " 
            << getpid() << std::endl;
	
	int retval;
	retval = fork();
	
	if (retval == 0)
	{
		for(int i = 0; i < 10; i++)
		{
			std::cout << "Child Process, its pid " 
                << getpid() << std::endl;
		}
		return 123;
	}
	else
	{
		int status;
		wait(&status);
		if(WIFEXITED(status))
		{
			std::cout << "Child is finished, running with return val" 
                << WEXITSTATUS(status) << std::endl;
		}
		std::cout << "Parent Process is completed! PID: " << getpid();
	}
}
~~~


