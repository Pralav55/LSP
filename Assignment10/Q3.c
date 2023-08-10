//program which creates single thread and we have to pass parameters to that thread from main thread 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * threadproc(void *ptr)
{
	printf("Accepted parameter from main function value is %d\n",(int)ptr);
	pthread_exit(NULL);
}

int main()
{
	pthread_t TID;
	int ret=0;
	int no=10;
	
	ret= pthread_create(&TID
				,NULL
				,threadproc
				,(int *)no);
	
	if (ret != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread is created with ID : %u\n",TID);
	pthread_join(TID,NULL);
	
	printf("End of main thread\n");
	
	pthread_exit(NULL);
	
	return 0;
}
