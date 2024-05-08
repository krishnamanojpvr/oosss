#include <stdio.h>
#include <unistd.h>

int main() {
    execlp("ls", "ls", "-l", NULL); // Executes "ls -l"
    perror("execlp"); // Print error if any
    return 1;
}
