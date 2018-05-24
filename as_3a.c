#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<malloc.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
int handler(int);
 
int main()
{
	 
	signal(SIGINT,handler);	
	printf("press ctrl+c (SIGINT SIGNAL) to generate fibonacci series\n\n");
	while(1)
	{sleep(1);}
}
int handler(int sign)
{
	 
	int n,i=0,*arr,status;
	int fd[2],pid;
	int  buf,buff[150]; 
	int a=0,b=1,c;
 
	printf("gine the no. of terms in fibonacci series\n");
	scanf(" %d",&n);
	arr=(int *)calloc(n,sizeof(int));
	status=pipe(fd);
	if(status==-1)
	{
	  perror("pipe _error");
	  exit(1);
	}
	pid=fork();
	if(pid<0)
	{
	  printf("system error::child not created\n");
	  exit(0);
	}
	else if(pid==0)
	{
	  
	  pid=getpid();
	  write(fd[1],&pid,sizeof(int));
	  arr[0]=a;
	  write(fd[1],&arr[0],sizeof(int));
	  arr[1]=b;
	  write(fd[1],&arr[1],sizeof(int));
	  
	  for(i=2;i<n;i++)
	  {
	   c=a+b;
	   arr[i]=c;
	   a=b;
	   b=c;
	   write(fd[1],&arr[i],sizeof(int));
	  }
	 write(fd[1],&sign,sizeof(int));
	exit (0);
	}
	else 
	{
	wait(&status);
	printf("parent proces me hu\n\n");
	read(fd[0],&buf,sizeof(int));
	printf("pid of child is :: %d\n",buf);
	printf("fibonacci series is \n");
	for(i=0;i<n;i++)
	{
	 read(fd[0],&buff[i],sizeof(int));
	 printf("%d\t",buff[i]);
	 
	}
	read(fd[0],&buf,sizeof(int));
	printf(" \nthe signal id :: %d\n",buf);
	exit(3);
	}

return 0;	
}
















