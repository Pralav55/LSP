//program which accepts directory name from user and deletes all empty files from that directory

#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	DIR *dp = NULL;
	struct dirent *entry=NULL;
	struct stat sobj;
	char path[40];
	
	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	dp = opendir(argv[1]);
	if(dp == NULL)
	{
		printf("Unable to open the directory\n");
		return -1;
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		sprintf(path,"%s/%s",argv[1],entry->d_name);
		stat(path,&sobj);
		if(sobj.st_size == 0)
		{
			
			remove(path);
		}
	}	
	return 0;
}
