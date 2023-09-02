#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

//////////////////////////////////////////////////////
/*
    #include<unistd.h>

    write - write to a file descriptor (in FILE)

    iRet = write(Fd,Buffer,14);

        -fd       : File Discriptor or resource where we want write the data
        -buffer   : Data stored which we want write in file
        -count    : The Maximum number of bytes write in file
    
    RETURN :
            - On Sucess write system call return the number of bytes written in file
            - OR return error -1

*/
//////////////////////////////////////////////////////

#define BUFFERSIZE 512

int main(int argc,char *argv[])
{
    int Fd = 0;
    char Buffer[BUFFERSIZE] = "SHREE GANESH..";
    int iRet = 0;
    

    if(argc != 2)
    {
        printf("INSUFFICIENT ARGUMENTS..\n");
        return -1;
    }

    Fd = open(argv[1],O_RDWR);
    if(Fd == -1)
    {
        printf("UNABLE TO OPEN FILE..\n");
        return -1;
    }

    iRet = write(Fd,Buffer,14);
    printf("NUMBER OF BYTES WRIITEN IN FILE IS: %d\n",iRet);
    
    close(Fd);
    return 0;
}