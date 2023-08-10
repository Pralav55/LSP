//program which is used to demostrate concept of Input Output redirection

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int fd1=0,fd2=0;
	char buff[10];
	
	if(argc != 3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}

	fd1 = fopen(argv[1],"r");
	if(fd1 == -1)
	{
		printf("Unable to open input file\n");
		return -1;
	}
	
	fd2 = open(argv[2],O_RDWR | O_CREAT);
	if(fd2 == -1)
	{
		printf("Unable to open or create output file\n");
		return -1;
	}
	
	while(fgets(buff,sizeof(buff),fd1) != NULL)
	{
		printf("%s\n",buff);
	}
	
	return 0;
}
