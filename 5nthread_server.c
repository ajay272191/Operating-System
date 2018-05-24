#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

void *ServerEcho(void *args)
{
	int cfd=(int)args;
	char str[20];
  	read(cfd,str,20);
 	printf("nreading from client:%s\n",str);
 	write(cfd,str,20);
	printf("nechoing back to client\n");
 	close(cfd);
}

int main()
{
	struct sockaddr_in address;
	int i,n,bi,sfd,cfd; //client/server File Discriptor
 	pthread_t t[20];
 	
	sfd =socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{perror("socket");
	 exit(1);
	}
 
 	address.sin_family = AF_INET;  
 	address.sin_addr.s_addr = INADDR_ANY;  
 	address.sin_port = htons( 8888 );  
 
 	if(bind(sfd,(struct sockaddr*)&address,sizeof(address))<0)
         {perror("bind:");
	  exit(1);	
	 }

	  printf("  socket has been created\n");
	  printf("give the number of thread(number of client) \n");
	  scanf(" %d",&n);
	  listen(sfd,n); 
  	  
	 while(1)
  	  {
  	   for(i=0;i<n;i++)      //can support n clients at a time
  	    {
  	        cfd=accept(sfd,NULL,NULL);
		printf("ip->\n\n\nip->%d\n\n",address.sin_addr,inet_ntoa(address.sin_addr));
  	     printf("nConnected to client %dn",cfd);
  	     pthread_create(&t,NULL,ServerEcho,(void *)cfd);

  	    }
  	  }
  	close(sfd);
 
 return 0;
}
