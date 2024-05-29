#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    execvp("ls", args); // Executes "ls -l"
    perror("execvp"); // Print error if any
    return 1;
}
