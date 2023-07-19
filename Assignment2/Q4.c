//program to accept directory name from user and print all file names and its types

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int  argc,char *argv[])
{
	char DirName[20];
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	char name[50];
	struct stat sobj;
	
	printf("Enter name of the directory : ");
	scanf("%s",DirName);
	
	dp = opendir(DirName);
	if(dp == NULL)
	{
		printf("Unable to open directory \n");
		return -1;
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		sprintf(name,"%s/%s",DirName,entry->d_name);
		stat(name,&sobj);
		if(S_ISREG(sobj.st_mode))
		{
			printf("File name : %10s File Type : Regular File\n",name);
		}
		else if(S_ISDIR(sobj.st_mode))
		{
			printf("File name : %10s File Type : Directory\n",name);
		}
		else if(S_ISLNK(sobj.st_mode))
		{
			printf("File name : %10s File Type : Symbolic Link\n",name);	
		}
		
	}
	
	return 0;
}
