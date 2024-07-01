#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
    DIR *dirop;
    struct dirent *dired;
    if (argc != 2)
    {
        printf("Invalid number of arguments\n");
    }
    else if ((dirop = opendir(argv[1])) == NULL)
        printf("Cannot open Directory\n");
    else
    {
        printf("%10s %s \n", "Inode", "File Name");
        while ((dired = readdir(dirop)) != NULL)
            printf("%10d %s\n ", dired->d_ino, dired->d_name);
        closedir(dirop);
    }
    return 0;
}