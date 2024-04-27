#include<stdio.h>
#include<sys/types.h> //type "pid_t" is defined
#include<unistd.h> //"fork()" is defined
int main(){
	/*fork a process*/
	pid_t p;
	p=fork();
	/*the child and parent will execute every line of code
	  after the fork(each seperately)*/
	if(p==0){
		printf("Hello CHILD PID = %d\n",getpid());
	}
	else if(p>0){
		printf("Hello PARENT PID = %d\n",getpid());
	}
	else{
		printf("Error : fork() failed. . .\n");
	}
	return 0;
}
