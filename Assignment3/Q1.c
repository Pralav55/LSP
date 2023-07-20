//program which accepts two file names from user and copy the content of an existing file into new created file
// cp command implementation

#include<stdio.h>
#include<fcntl.h>


#define BLOCKSIZE 1024

int main(int argc,char *argv[])
{
	int fdSource=0,fdDest=0,ret=0;
	char Buffer[BLOCKSIZE]={'\0'};
	
	if(argc != 3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	fdSource = open(argv[1],O_RDONLY);
	if(fdSource == -1)
	{
		printf("Unable to open source file\n");
		return -1;
	}
	
	fdDest = creat(argv[2],0777);
	if(fdDest == -1)
	{
		printf("Unable to create destination file\n");
		close(fdSource);
		return -1;
	}
	
	while((ret = read(fdSource,Buffer,sizeof(Buffer))) != 0)
	{
		write(fdDest,Buffer,ret);
		memset(Buffer,0,sizeof(Buffer));
	}
	
	close(fdSource);
	close(fdDest);
	
	return 0;
}
