#include <stdio.h>
#include <unistd.h>

int main() {
    execl("/bin/ls", "ls", "-l", NULL); // Executes "ls -l"
    perror("execl"); // Print error if any
    return 1;
}
