#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
int main(){
    int fd[2],n;
    char buffer[100];
    pid_t p = fork();
    pipe(fd);
    if(p>0){// Parent Process
        close(fd[0]);
        printf("Parent passing value to child\n");
        write(fd[1],"hello\n",6); //fd[1] is the write end of pipe
        wait();
    }
    if(p==0){
        close(fd[1]);
        printf("Child printing received value");
        n = read(fd[0],buffer,100); //fd[0] is the read end of pipe
        write(1,buffer,n); 
    }
}