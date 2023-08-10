// program which is used to predict the problem due to lack of synchronization

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int counter = 0;
pthread_mutex_t lock;

void * threadproc(void *ptr)
{
	pthread_mutex_lock(&lock);
	counter++;
	printf("Running thread : %d\n",counter);
	for(int i=0;i<0xffffffff;i++);
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}

int main()
{
	pthread_t TID1,TID2,TID3,TID4;
	pthread_mutex_init(&lock,NULL);
	int ret=0;
	
	ret = pthread_create(&TID1,NULL,threadproc,NULL);
	if (ret != 0)
	{
		printf("Unable to create thread 1\n");
		return -1;
	}
	
	ret = pthread_create(&TID2,NULL,threadproc,NULL);
	if (ret != 0)
	{
		printf("Unable to create thread 2\n");
		return -1;
	}
	
	ret = pthread_create(&TID3,NULL,threadproc,NULL);
	if (ret != 0)
	{
		printf("Unable to create thread 3\n");
		return -1;
	}
	
	ret = pthread_create(&TID4,NULL,threadproc,NULL);
	if (ret != 0)
	{
		printf("Unable to create thread 4\n");
		return -1;
	}
	
	pthread_join(TID1,NULL);
	pthread_join(TID2,NULL);
	pthread_join(TID3,NULL);
	pthread_join(TID4,NULL);
	
	pthread_mutex_destroy(&lock);
	printf("End of main thread\n");
	
	pthread_exit(NULL);
	
	return 0;
}
