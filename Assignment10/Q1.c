// program which is used to create simple thread by using pthread library

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * threadproc(void *ptr)
{
	printf("Inside Thread\n");
}

int main()
{
	pthread_t TID;
	int ret=0;
	
	ret = pthread_create(&TID
				,NULL
				,threadproc
				,NULL);
	
	if (ret != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("pthread is created with ID : %u\n",TID);
	printf("End of main thread\n");
	
	return 0;
}
