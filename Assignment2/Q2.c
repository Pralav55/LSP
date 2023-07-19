//program to accept directory name from user and print all file names from that directory

#include<stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	
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
	
	printf("-------------------------------------------------\n");
	printf("Entries from the directory files are : \n");
	printf("-------------------------------------------------\n");
	printf("Inode Number \t\t File Name\n");
	
	while((entry = readdir(dp) != NULL))
	{
		printf("%s : %d \n",entry->d_name,entry->d_ino);
	}
	printf("-------------------------------------------------\n");
	
	closedir(dp);
	
	return 0;
}

