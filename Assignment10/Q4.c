//program which creates single thread and it accept one value from user and it return some value to caller thread

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * threadproc(void *ptr)
{
	int no=0;
	printf("Enter a value : ");
	scanf("%d",&no);
	pthread_exit(no);
}

int main()
{
	pthread_t TID;
	int ret=0;
	int value=0;
	
	ret= pthread_create(&TID
				,NULL
				,threadproc
				,NULL);
	
	if (ret != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread is created with ID : %u\n",TID);
	pthread_join(TID,&value);
	printf("return value from thread : %d\n",value);
	
	printf("End of main thread\n");
	
	pthread_exit(NULL);
	
	return 0;
}
