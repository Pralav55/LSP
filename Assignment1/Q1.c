//program which accepts filename from user and open that file

#include<stdio.h>	// Header file Inclusion
#include<fcntl.h>

int main(int argc,char *argv[])	//main function
{
	int fd=0;
	
	if(argc != 2)	//filter to check command line arguments
	{
		printf("Invalid number of arguments\n"); 
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);	// open function to open the file
	
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
