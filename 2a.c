#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
/*  The intrpt function reacts to the signal passed in the parameter
signum.
    This function is called when a signal occurs.
    A message is output, then the signal handling for SIGINT is reset
    (by default generated by pressing CTRL-C) back to the default
behavior.
*/
//SIG_DFL 	default signal handling
//SIG_IGN 	signal is ignored 
void intrpt(int signum)
{
	int child_pid;
    	printf("I got signal %d\n\n", signum);
	child_pid = fork();

	if (child_pid < 0)
	{
	 printf("Fork error\n");
 	 exit(1);
	}
      else  if (child_pid == 0)
	 { /* Child’s region */
	printf("child region \n\n");
	      printf("PROCESS ID :: %d\nPARENT PROCESS ID :: %d\n",getpid(),getppid());
	      exit(0); /* exit(0) can also be used, that uses _exit() */
  	}
     else
	 { /* Parent’s region */
	printf("parent region \n\n");
     	 printf("PROCESS ID :: %d\nPARENT PROCESS ID :: %d\n\n\n",child_pid,getppid()); 
	 exit(0);
      	 /* exit(0) can also be used that uses _exit()*/
  	}
    (void) signal(SIGINT, SIG_DFL);
	
}

/*  main intercepts the SIGINT signal generated when Ctrl-C is input.
    Otherwise, sits in an infinite loop, printing a message once a secon
d.
*/
int main()
{
   signal(SIGINT, intrpt);//interrupt->signal handler

    while(1) {
        printf("Hello World!\n");
        sleep(1);
    }
}