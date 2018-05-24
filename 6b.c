// C program to demonstrate working of
// difftime()
#include<time.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int func()
{
	sleep(4);
}
int main()
{
    int sec;
        time_t time1, time2;
 	int a,b,pid;
        // Current time
	struct timeval start, end;
	//time(&time1);
	a=gettimeofday(&start, NULL);
	printf("\nsubmission time:: %d",a);
	pid=fork();
	if(pid==0)
	{
	printf("\n child process me hu\n\n");
	func();
	}
	else
	{wait();
	  printf("\n\nparent process me hu\n");
	}
	b=gettimeofday(&end, NULL);
	printf("\ntermination time micro seconds  %ldms\n", ((end.tv_sec * 1000000 + end.tv_usec)- (start.tv_sec * 1000000 + start.tv_usec)));
    	//time(&time2);
    	//printf("\ntime in second %.2f seconds", difftime(time2, time1));

    return 0;
}
