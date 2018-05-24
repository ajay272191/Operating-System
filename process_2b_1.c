#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int   ShmID;      
pid_t *ShmPTR;    

int  main(void)
{
     int   i;
     pid_t pid = getpid();
     key_t MyKey;
     
     //creates a shared memory
     MyKey   = ftok("NULL", 'A');   
     ShmID   = shmget(MyKey, sizeof(pid_t), IPC_CREAT | 0666);
     //attaches this shared memory to its address space 
     ShmPTR  = (pid_t *) shmat(ShmID, NULL, 0);
     //saves its process ID there for another process to retrieve 
     *ShmPTR = pid;               
     //infinite loop
	printf("prog1\n\n");
	printf("pid:: %d\n",pid);
    while(1)
	{
	  	write(Shmptr,pid,sizeof(pid));
		printf("press enter to after execution of prog 2\n");
		gtchar();
	}
     }
}

