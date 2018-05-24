#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main()
{
	struct sockaddr_in address ;
	int cfd=socket(AF_INET,SOCK_STREAM,0);
	char str_clnt[20],str_ser[20];

	address.sin_family = AF_INET;  
	address.sin_addr.s_addr = INADDR_ANY;  
	address.sin_port = htons( 8888 );
	strcpy(str_clnt,inet_ntoa(address.sin_addr));
 	printf("ip->%d\n\n\n",address.sin_addr.s_addr);
	if(connect(cfd,(struct sockaddr*)&address,sizeof(address))>=0)
	 {
	  printf("Connected to server %dn",cfd);
	  printf("nEnter Srting to send %s",str_clnt);
	  //scanf("%s",str_clnt);
	  write(cfd,str_clnt,20);
	  read(cfd,str_ser,20);
	  printf("String from Server: %s",str_ser);
	  close(cfd);
	 }
	 else
	 {
	  printf("socket creation failed");
	 }
	 return 0;
}

