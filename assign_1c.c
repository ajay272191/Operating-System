#define err_sys(msg) write(1,msg,50)
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include<sys/types.h>

void Info_on_termination_of_child(int status)
{
	if (WIFEXITED(status))
		 printf("normal termination, exit status = %d\n",WEXITSTATUS(status));

	else if (WIFSIGNALED(status))
		   printf("abnormal termination, signal number = %d\n",WTERMSIG(status));
}

int main(void)
{
	pid_t pid;
	int status;

	if ((pid = fork()) < 0)			//creating a child
		 err_sys("fork error");
	else if (pid == 0) 			//child process
		 exit(0);			//child process exiting normally ,only parent left
	if (wait(&status) != pid) 		//parent waiting for child 
		 err_sys("wait error");
	Info_on_termination_of_child(status);	/*calling the function to get termination info*/



	if ((pid = fork()) < 0)			//forking to create a child again
		 err_sys("fork error");
	else if (pid == 0)			/*child proces*/
 		abort();			/*Abnormal termintionof child process by ABORT signal only parent left*/
	if (wait(&status) != pid)		/*parent waiting for child to exit*/
		err_sys("wait error");
	Info_on_termination_of_child(status);	/*calling the function to get termination info*/



	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0)
		status =(status/0);
						/* Division by Zero error generates SIGNAL.NO 8 which kills the child,only parent left*/
	if (wait(&status) != pid) 		/*parent waiting for child process to end*/
		 err_sys("wait error");
	Info_on_termination_of_child(status);

exit(0);
}
