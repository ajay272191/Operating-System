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
        int    qid;
	int length;
        key_t  msgkey;
         
	msgkey = ftok("NULL", 'b'); /* Generate our IPC key value */
	
	qid=msgget(msgkey,IPC_CREAT|0660);/* Open/create the queue */
	
	fprintf( stderr, "message queue id is %d\n",qid);

        if(qid == -1)
	 {
           perror("open_queue");
          exit(1);
         }
     
        mm.mtype   = 1;        /* Load up the message with some data ,Message type must be a positive number! */
	
	
	printf("give a message to send\n");
	scanf(" %[^\n]s",&mm.message);

        /* Bombs away! */
	  
	length=sizeof(struct mymsgbuf)-sizeof(long);
        if( msgsnd(qid,&mm,length,0)==-1)
       	  {
            perror("send_message");
            exit(1);
          }
	else
	{printf("message send..........\n");}
	
printf("after receiving of message press enter to terminal\n");

getchar();	
getchar();
msgctl(qid,IPC_RMID,NULL);
return 0;
}

