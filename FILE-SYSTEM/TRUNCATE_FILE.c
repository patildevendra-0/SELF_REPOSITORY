#include<stdio.h>
#include<unistd.h>

//////////////////////////////////////////////////////////
/*
    #include<unistd.h>
    
    truncate a file to a specified length

    truncate() -- system call
                - FilePath
                - Start point where from data delete start

                iRet = truncate(argv[1],FILE_Start);
                    
                        argv[1]    = Filename
                        File_Start = 10    (first 10 bytes are not lost other whole data is lost)
    RETURN : 
            Success: 0
            Error  : -1
*/
//////////////////////////////////////////////////////////

#define FILE_Start 10

int main(int argc ,char *argv[])
{
    int iRet = 0;

    iRet = truncate(argv[1],FILE_Start);
    if(iRet != 0)
    {
        printf("TRUNCATE FAILS..\n");
        return -1;
    }

}