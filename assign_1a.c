#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main(int argc, char **argv)
{
  char *name = argv[1];
  int status;
  int child_pid = fork();
	printf("%d",child_pid);
  if (child_pid < 0)
	{
	 printf("Fork error\n");
 	 exit(1);
	}
      else  if (child_pid == 0)
	 { /* Child’s region */
		child_pid=getpid();
	      printf("Child of %s sees PID of %d\n",name, child_pid);
	      return 0; /* exit(0) can also be used, that uses _exit() */
  	}
     else
	 { /* Parent’s region */
	child_pid=getpid();
     	 printf("I am the parent %s. My child is %d\n",name, child_pid);  
      	 /* exit(0) can also be used that uses _exit()*/
  	}
 
return 0; 
}
