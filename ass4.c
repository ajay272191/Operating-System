#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main(){
char c;
int fd;
struct flock lock;
fd=open("test.txt",O_WRONLY);
memset(&lock,0,sizeof(lock));
//lock.1_type=F_WRLCK;
lock.l_type = F_WRLCK;
printf("Locking file.......\n");
//fcntl(fd,F_SETLKW,&lock);
fcntl (fd, F_SETLKW, &lock);
printf("Hit any key for unlock........\n");
scanf("%c",&c);
//lock.1_type=F_UNLCK;
lock.l_type = F_UNLCK;
printf("unlocking.........\n");
fcntl(fd,F_SETLKW,&lock);
close(fd);
return 0;
}
