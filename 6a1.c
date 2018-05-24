//This program requests the shared memory segment created by the previous program process_a.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void  main(void)
{
     pid_t   pid;
     key_t MyKey;
     int   ShmID;
     pid_t *ShmPTR;
     char   c;
     int   i; 
     MyKey   = ftok("NULL", 'A');        
     //retrieves the process ID stored in the shared memory segment
     ShmID   = shmget(MyKey, sizeof(pid_t), 0666);
     ShmPTR  = (pid_t *) shmat(ShmID, NULL, 0);
     pid     = *ShmPTR;   
             
     shmdt(ShmPTR);                    
     // an infinite loop asking for a single character input.
    
}

