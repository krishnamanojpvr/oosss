#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int fd, i;
    char buf[2];
    fd = open(argv[1], O_RDONLY, 0777);
    if (fd == -1)
    {
        printf("file open error");
    }
    else
    {
        while ((i = read(fd, buf, 1)) > 0)
        {
            printf("%c", buf[0]);
        }
        close(fd);
    }
    return 0;
}