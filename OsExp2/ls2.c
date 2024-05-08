#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    // Check if a directory was provided as an argument
    const char *dir_path = (argc > 1) ? argv[1] : ".";

    // Open the directory
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Read directory entries
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}