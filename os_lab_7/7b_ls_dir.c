#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    DIR *dir = opendir(argc < 2 ? "." : argv[1]);
    if (!dir) {
        perror("Error opening directory");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
            printf("Inode: %lu\t File: %s\n", entry->d_ino, entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}