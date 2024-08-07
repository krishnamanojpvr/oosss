#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
main(int argc, char *argv[])
{
    int i, fd1, fd2;
    char *file1, *file2, buf[2];
    file1 = argv[1];
    file2 = argv[2];
    printf("file1=%s file2=%s\n", file1, file2);
    fd1 = open(file1, O_RDONLY, 0777);
    fd2 = creat(file2, 0777);
    while (i = read(fd1, buf, 1) > 0)
        write(fd2, buf, 1);
    printf("%s is copied to %s\n", file1, file2);
    remove(file1);
    printf("%s is removed\n", file1);
    close(fd1);
    close(fd2);
}