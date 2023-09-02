#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

////////////////////////////////////////////////////////////////
/*  
    #include<unistd.h>

    read - read from a file descriptor (from file)
    
    iRet = read(Fd,Buffer,sizeof(Buffer));

        -fd     : File Discriptor or resource where we want read the data
        -buffer : Data Read from file will be stored
        -count  : The Maximum number of bytes read from file

    RETURN :
            - On Sucess write system call return the number of bytes written in file
            - OR return error -1

*/
////////////////////////////////////////////////////////////////

#define BUFFERSIZE 512
int main(int argc ,char *argv[])
{
    int Fd = 0;
    char Buffer[BUFFERSIZE];
    int iRet = 0;


    if(argc != 2)
    {
        printf("INSUFFICIENT ARGUMENTS..\n");
        return -1;
    }

    Fd = open(argv[1],O_RDONLY);
    if(Fd == -1)
    {
        printf("UNABLE TO OPEN FILE..\n");
        return -1;
    }
    
    iRet = read(Fd,Buffer,sizeof(Buffer));

    printf("NUMBER OF BYTES READ FROM FILE: %d\n",iRet);

    write(1,Buffer,sizeof(Buffer));

    printf("\n");

    close(Fd);
    
    return 0;
}