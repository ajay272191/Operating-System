#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	  
	int fd;
	struct flock lock;
	char c,buff[1024];
	
	
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	
	if((fd=open("file.txt",O_RDWR))==-1)
	{perror("eror_openig_file");
	exit(1);
	}
	printf("would you like to read given filepress  yes->y  no->n\n\n");
	c=getchar();
	if(c=='y')
	{
	 read(fd,buff,sizeof(buff));
	 write(1,buff,sizeof(buff));
	}
	printf("press enter to set a lock\n");
	getchar();
	printf("setting lock.........\n");
	
	if(fcntl(fd,F_SETLKW,&lock) == -1)
	{perror("file_controller->fcntl");
	exit(1);	
	}
 	
	printf("lock is set\n press enter to release lock\n");
	getchar();
	 
	lock.l_type=F_UNLCK;
	if(fcntl(fd,F_SETLK,&lock) == -1)
	{
	  perror("file_controller->fcntl");
	  exit(1);
	}
	
	printf("lock released\n\n");
	close(fd);
return 0;
}










