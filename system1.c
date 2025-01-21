#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>

void main() {
     pid_t childpid = fork();
     if(childpid == 0) {
          printf("\nI am in the child process");
          printf("PARENT ID = %d\n",getppid());
          printf("CHILD ID = %d\n",getpid());
     }
     if(childpid > 0) {
          printf("\nI am in the parent process");
          printf("PARENT ID = %d\n",getpid());
          printf("CHILD ID = %d\n",childpid);
          wait(NULL);
          printf("Child is terminated.Parent moved from waiting state to running state");
     }
     if(childpid < 0) {
          printf("\nFork failed! Unable to create a child process.\n");    
     }
     exit(0);
}     
