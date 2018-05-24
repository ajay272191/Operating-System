#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h> 
#include<unistd.h>
#include <sys/wait.h> 
int main(int argc, char **argv)
{
  char *name = argv[1];
  int status;
int child_pid;
printf("pid %d\n\n",getpid());  
child_pid = fork();
	printf("argc->%d",argc);
  if (child_pid < 0)
	{
	 printf("Fork error\n");
 	 exit(1);
	}
      else  if (child_pid == 0)
	 { /* Child’s region */
	      printf("child region\n\nppid %d \n  PID is %d\n",getppid(), getpid());
	      return 0; /* exit(0) can also be used, that uses _exit() */
  	}
     else
	 { /* Parent’s region */
	wait(&status);	
	printf("status-> %d\n",status);
     	 printf("parent region \n\nppid %d \npid %d\n",getppid(), child_pid);  
      	 /* exit(0) can also be used that uses _exit()*/
  	}
 
return 0; 
}
