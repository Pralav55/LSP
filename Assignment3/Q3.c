//program which accepts two directory names from user and move all files from source directory to destination directory

#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	DIR *dp1 = NULL;
	DIR *dp2 = NULL;
	struct dirent *entry = NULL;
	char oldname[50],newname[50];
	
	if(argc != 3)
	{
		printf("Insufficient number of arguments\n");
		return -1;
	}
	
	dp1 = opendir(argv[1]);
	if(dp1 == NULL)
	{
		printf("Unable to open source directory\n");
		return -1;
	} 
	
	dp2 = mkdir(argv[2],S_IRWXU);
	if(dp2 == NULL)
	{
		printf("Unable to create destination directory\n");
		return -1;
	}
	
	while((entry = readdir(dp1)) != NULL)
	{
		sprintf(oldname,"%s/%s",argv[1],entry->d_name);
		sprintf(newname,"%s/%s",argv[2],entry->d_name);
		
		rename(oldname,newname);
	}
	
	closedir(dp1);
	
	return 0;
}
