#include<time.h>
#include<sys/time.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
  

 
  struct timeval start, end;

  gettimeofday(&start, NULL);

 getchar();
	getchar();

  gettimeofday(&end, NULL);

  printf("total time taken by process: %ld\n", ((end.tv_sec * 1000000 + end.tv_usec)
		  - (start.tv_sec * 1000000 + start.tv_usec)));

  return 0;
}
