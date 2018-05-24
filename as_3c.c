#include<stdio.h>
#include<pthread.h>
void * show(void *a)
{
	printf("hello\n");
}
int main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,&show,NULL);
	pthread_exit(NULL);
	printf("main thread\n");
 
return 0;
}
