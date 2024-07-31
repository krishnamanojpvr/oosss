#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Child Process\n");
    } else {
        wait(NULL); // Wait for the child process to complete
        printf("Parent Process\n");
    }
    return 0;
}