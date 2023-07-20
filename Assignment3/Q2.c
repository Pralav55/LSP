//program which accepts directory name and file name from user and check whether that file is present in that directory or not

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char *argv[])
{
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	int flag = 0;
	
	if(argc != 3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	dp = opendir(argv[1]);
	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		if((strcmp(argv[2],entry->d_name)) == 0)
		{
			flag = 1;
			break;
		}
	}
	
	if(flag == 0)
	{
		printf("%s file is not present in the %s directory\n",argv[2],argv[1]);
	}
	else
	{
		printf("%s file is present in the %s directory\n",argv[2],argv[1]);
	}
	
	return 0;
}
