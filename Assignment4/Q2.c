//program which accepts directory name from user and creates new directory of that name

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	char DirName[20];
	
	printf("Enter directory name which you want to create :- ");
	scanf("%s",DirName);
	
	int fd = mkdir(DirName,S_IRWXU);
	
	if(fd == -1)
	{
		printf("Unable to create directory\n");
		return -1;
	}
	return 0;
}
