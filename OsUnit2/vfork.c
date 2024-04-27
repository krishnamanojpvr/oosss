#include<stdio.h>
#include<sys/types.h> //type "pid_t" is defined
#include<unistd.h> //"vfork()" is defined
#include<stdlib.h> //"exit()" is defined
int main(){
	/*fork a process*/
	pid_t p;
	p=vfork();
	/*the child and parent will execute every line of code
	  after the fork(each seperately)*/
	if(p==0){
		printf("Hello CHILD PID = %d\n",getpid());
        printf("Child Process exiting with exit(). . .\n");
        exit(0);  
        // _exit(0); //also works (doesn't require standard library (stdlib.h)) but I dont know the difference
		// even if we don't use exit() or _exit() the child process will exit after the parent process exits (doubt!!!)
	}
	else if(p>0){
		printf("Hello PARENT PID = %d\n",getpid());
	}
	else{
		printf("Error : vfork() failed. . .\n");
	}
	return 0;
}
