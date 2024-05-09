#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    pid_t pid;      // process id
    pid = fork(); // create another process
    if (pid < 0)
    {
        printf("\nFork failed\n");
        exit(-1);
    }
    else if (pid == 0)
    {                                            // child
        execlp("/bin/ls", "ls", "-l", NULL); // execute ls
    }
    else
    { 
        // parent
        printf("Parent Waiting for child to complete!!");
        pid_t childpid;
        childpid = wait(NULL); // wait for child
        printf("\nchild complete, PID -> %d\n",childpid);
        printf("Parent complete, PID -> %d",getpid());
        exit(0);
    }
}