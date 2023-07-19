//program which accepts file name from user and read whole file and display onto the output window

#include<stdio.h>	//Header file inclusion
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024	

int main(int argc,char *argv[])		//main function
{
	int fd=0,ret=0;
	char Buffer[BLOCKSIZE];
	
	if(argc != 2)		//command line argument filter
	{
		printf("Insufficient number of arguments\n");
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);	//Opening the file in read mode
	
	if(fd == -1)	//filter if file does not get opened
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	while((ret = read(fd,Buffer,sizeof(Buffer))) != 0)	//Loop which reads buffer size of data and store into ret 
	{
		write(1,Buffer,ret);	//writes those number of data onto output window
	}
	
	close(fd);	//close the file
	
	return 0;
}
