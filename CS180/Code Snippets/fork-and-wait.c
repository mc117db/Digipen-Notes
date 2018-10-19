#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // standard POSIX header file
#include <sys/wait.h> // POSIX header file for 'wait' function

int main()
{
    int pid;
        
    pid=fork();
    if(pid==0)
    {
        //Child Process Code
        printf("Child Process.\n");
        
        /*exit(19);
          _exit(19);*/
        return 19;
    }
    else
    {
        int status;
        wait(&status);
        
        if(WIFEXITED(status))
            printf("status = %d\n", WEXITSTATUS(status));
        
        printf("Parent Process.\n");
    }
    
    return 0;
}
