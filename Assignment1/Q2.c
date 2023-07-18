//program which accepts filename and mode from user and then open that file in specified mode

#include<stdio.h>	// Header file Inclusion
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[])	//main function
{
	int fd= 0 , mode= 0;
	
	if(argc != 3)	//filter to check command line arguments
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	if((strcmp(argv[2],"read"))==0)	//filter to check which mode user wants with help of command line arguments
	{
		mode = O_RDONLY;
	}
	else if((strcmp(argv[2],"write"))==0)
	{
		mode = O_WRONLY;
	}
	else
	{
		mode = O_RDWR;
	}
	
	fd = open(argv[1],mode);	// open function to open the file
	
	if(fd == -1)	// condition to check whether the file is opened or not
	{
		printf("Unable to open the file\n");
		return -1;
	}
	else
	{
		printf("File successfully opened with file descriptor : %d\n",fd);
		return 0;
	}
}
