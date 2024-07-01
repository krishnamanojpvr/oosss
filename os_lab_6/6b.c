#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int pid, pid1, pid2;
    pid = fork();
    if (pid == -1)
    {
        printf("ERROR IN PROCESS CREATION \n");
        exit(0);
    }
    if (pid != 0)
    {
        pid1 = getpid();
        printf("\n the parent process ID is %d", pid1);
    }
    else
    {
        pid2 = getpid();
        printf("\n the child process ID is %d\n", pid2);
    }
    return 0;
}