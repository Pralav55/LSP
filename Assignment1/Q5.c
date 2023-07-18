#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int fd=0,ret=0,size=0;
	char *Buffer = NULL;
	
	if(argc !=3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	
	size = atoi(argv[2]);
	Buffer = (char *)malloc(size);
	
	ret = read(fd,Buffer,size);
	if(ret == 0)
	{
		printf("Unable to read data from file\n");
		return -1;
	}
	
	printf("Data from file :\n");
	write(1,Buffer,ret);
	printf("\n");
	
	return 0;
}
