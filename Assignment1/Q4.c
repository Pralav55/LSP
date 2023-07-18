//program which accepts file name from user and prints all the information of that file

#include<stdio.h>	//header file inclusion
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])	//main function
{
	struct stat sobj;	//object of stat structure
	
	if(argc != 2)	//filter to check command line arguments
	{
		printf("Insufficient number of arguments\n");
		return -1;
	}
	
	stat(argv[1],&sobj);	//Getting details of the particular file
	
	printf("File name : %s\n",argv[1]);		//Displaying all info on terminal
	printf("File size is : %d\n",sobj.st_size);
	printf("Number of Links : %d\n",sobj.st_nlink);
	printf("Inode Number : %d\n",sobj.st_ino);
	printf("File system number : %d\n",sobj.st_dev);
	printf("Number of blocks : %d\n",sobj.st_blocks);
	printf("Mode of file : %d\n",sobj.st_mode);
	printf("Time of Last Access : %d\n",sobj.st_ctime);
	
	return 0;
	
}

