
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

//////////////////////////////////////////////////////////////
/*
    #include<string.h>
    - Library function - memset()

    memset - fill memory with a constant byte 
           - function is used to set a block of memory to a specific value.
    
    ----------------------------------------------------------

    memset(Buffer,0,sizeof(Buffer));
    
        -Buffer         :  A pointer to memory block
        -0              :  The value i want to set
        -sizeof(Buffer) :  The Number of bytes that i want set to 0 (value i want to set = 0).
*/
//////////////////////////////////////////////////////////////

#define BUFFERSIZE 512
int main(int argc , char *argv[])
{
    int Fd_Source = 0;
    int Fd_Destination = 0;
    int iRet = 0;

    char Buffer[BUFFERSIZE] = {'\0'};

    if(argc != 3)
    {
        printf("INSUFFICIENT ARGUMENTS..\n");
        return -1;
    }

    Fd_Source = open(argv[1],O_RDONLY);
    if(Fd_Source == -1)
    {
        printf("UNABLE TO OPEN SOURCE FILE..\n");
        return -1;
    }

    Fd_Destination = open(argv[2],O_WRONLY);
    if(Fd_Destination == -1)
    {
        printf("UNABLE TO OPEN DESTINATION FILE..\n");
        return -1;
    }

    while((iRet = read(Fd_Source,Buffer,sizeof(Buffer)))!= 0)
    {
        write(Fd_Destination,Buffer,sizeof(Buffer));
        memset(Buffer,0,sizeof(Buffer));
    }

    close(Fd_Destination);
    close(Fd_Source);

    return 0;
}