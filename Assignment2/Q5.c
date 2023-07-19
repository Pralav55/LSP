// program which accepts directory name from user and print name of such a file having largest size

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	char DirName[20],name[50];
	struct stat sobj;
	int iMax=0;
	char *maxname = NULL;
	
	printf("Enter name of directory : ");
	scanf("%s",DirName);
	
	dp = opendir(DirName);
	if(dp == NULL)
	{
		printf("Unable to open the directory\n");
		return -1;
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		sprintf(name,"%s/%s",DirName,entry->d_name);
		stat(name,&sobj);
		if(iMax < sobj.st_size)
		{
			iMax = sobj.st_size;
			maxname = entry->d_name;
		}
	}
	
	printf("Largest file in %s directory is %s with %d size\n",DirName,maxname,iMax);
	
	return 0;
}
