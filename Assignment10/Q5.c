//program which is  used to get thread id inside its thread function

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void * procthread(void * ptr)
{
	printf("ID of sub thread process : %u\n",pthread_self());
	pthread_exit(NULL);
}

int main()
{
	pthread_t PID;
	int ret = 0;
	
	ret = pthread_create(&PID,
				NULL,
				procthread,
				NULL);
			
	if(ret != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}	
	
	printf("ID of main thread : %u\n",pthread_self());
	pthread_join(PID,NULL);
	
	printf("End of main thread\n");
	
	pthread_exit(NULL);
	
	return 0;
}
