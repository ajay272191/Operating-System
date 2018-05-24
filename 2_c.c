#include<stdio.h>
#include<pthread.h>
void * show(void *a)
{
	printf("HELLO WORLD\n");
}
int main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,&show,NULL);
pthread_join(tid,NULL);	
printf("main thread\n");
	
	pthread_exit(NULL);
return 0;
}
