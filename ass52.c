#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include <linux/ipc.h>
#include <linux/msg.h>
struct mymsgbuf 
{
	long    mtype;          /* Message type */
        char message[100];
}mm;


int main()
{
        int    qid,length;
        key_t  msgkey;
         
        msgkey = ftok("NULL",'b');/* Generate our IPC key value */
	qid=msgget(msgkey,IPC_CREAT|0660);
        if(qid == -1)/* Open/create the queue */
	 {
           perror("open_queue");
          exit(1);
         }
	
 	length=sizeof(struct mymsgbuf) - sizeof(long);
        if(msgrcv(qid,&mm,length,mm.mtype,0)==-1)
	 {
           perror("receive_message");
           exit(1);
         }
        else
        {       
	 printf("received message ::\t%s\n",mm.message);
	 printf("\n\n message received\n");
	}
return 0;
}


