#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    char *env[] = { "PATH=/bin", NULL }; // Setting PATH environment variable
    execle("/bin/ls", "ls", "-l", NULL, env); // Executes "ls -l" with custom environment
    perror("execle"); // Print error if any
    return 1;
}
