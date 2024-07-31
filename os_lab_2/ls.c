#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    const char *dir_path = (argc > 1) ? argv[1] : ".";
    DIR *dir = opendir(dir_path);
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