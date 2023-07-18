//program which accepts filename and mode from user and checks whether our process can access that file in accepted mode or not

#include<stdio.h>	//header file inclusion
#include<string.h>
#include<fcntl.h>

int main(int argc,char *argv[])	//main function
{
	int Mode=0;
	
	if(argc != 3)	//filter to Handle command line arguments
	{
		printf("Error : Invalid number of arguments \n");
		return -1;
	}
	
	if((strcmp(argv[2],"read")) == 0)	// condition for mode in which user wants to open 
	{
		Mode = R_OK;
	}
	else if((strcmp(argv[2],"write")) == 0)
	{
		Mode = W_OK;
	}
	else if((strcmp(argv[2],"execute")) == 0)
	{
		Mode = X_OK;
	}
	else
	{
		printf("Error : Unable to fetch the mode from command line argument : %s\n",argv[2]);
		printf("Modes : read , write and execute\n");
		return -1;
	}
	
	if(access(argv[1],Mode) < 0)	//checks if the file can be opened in specified mode or not 
	{
		printf("Unable to access %s file in %s mode \n",argv[1],argv[2]);
	}
	else
	{
		printf("you can access %s file in %s mode \n",argv[1],argv[2]);
	}
	
	return 0;
}

