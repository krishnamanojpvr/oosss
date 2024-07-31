#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dir = opendir(argc < 2 ? "." : argv[1]);
    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}