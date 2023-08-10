//program which creates 2 threads first thread prints 1 to 500 and second one 500 to 1

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * threadproc1(void *ptr)
{
	for(int i=1;i<=500;i++)
	{
		printf("Thread1 - %d\n",i);
	}
	pthread_exit(NULL);
}

void * threadproc2(void *ptr)
{
	for(int i=500;i>=1;i--)
	{
		printf("Thread2 - %d\n",i);
	}
	pthread_exit(NULL);
}


int main()
{
	pthread_t TID1,TID2;
	int ret1=0,ret2=0;
	
	ret1 = pthread_create(&TID1
				,NULL
				,threadproc1
				,NULL);
	
	if (ret1 != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread1 is created with ID : %u\n",TID1);
	pthread_join(TID1,NULL);
	
	ret2 = pthread_create(&TID2
				,NULL
				,threadproc2
				,NULL);
	
	if (ret2 != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	printf("Thread2 is created with ID : %u\n",TID2);
	
	pthread_join(TID2,NULL);
	
	printf("End of main thread\n");
	
	pthread_exit(NULL);
	
	return 0;
}
