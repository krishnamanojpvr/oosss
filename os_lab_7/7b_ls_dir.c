#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char path[1024];

    // Open the specified directory or the current directory if none is specified
    if (argc < 2)
    {
        dir = opendir(".");
    }
    else
    {
        dir = opendir(argv[1]);
    }

    if (dir == NULL)
    {
        perror("Error opening directory");
        return EXIT_FAILURE;
    }

    // Read each entry in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        // Construct the full path to the file
        if (argc < 2)
        {
            snprintf(path, sizeof(path), "./%s", entry->d_name);
        }
        else
        {
            snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);
        }

        // Get file statistics
        if (stat(path, &file_stat) == -1)
        {
            perror("Error stat");
            continue;
        }

        // Print the inode number and file name
        printf("Inode: %lu\t File: %s\n", file_stat.st_ino, entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return EXIT_SUCCESS;
}
