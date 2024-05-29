#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t pids[2], wpid;
    // Fork first child process
    pids[0] = fork();
    if (pids[0] == 0)
    {
        // First child process
        printf("First child process: PID = %d\n", getpid());
        printf("First child process exiting\n");
        exit(0); // First child exits
    }
    // Fork second child process
    pids[1] = fork();
    if (pids[1] == 0)
    {
        // Second child process
        printf("Second child process: PID = %d\n", getpid());
        printf("Second child process exiting\n");
        exit(0); // Second child exits
    }
    if (pids[0] > 0 && pids[1] > 0)
    {
        // Parent process: wait specifically for the first child
        wpid = waitpid(pids[1], NULL, 0);
        printf("Parent: Proceeding after the second child with pid =%d has finished.\n", pids[1]);
    }
    return 0;
}