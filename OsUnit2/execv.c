#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    execv("/bin/ls", args); // Executes "ls -l"
    perror("execv"); // Print error if any
    return 1;
}
