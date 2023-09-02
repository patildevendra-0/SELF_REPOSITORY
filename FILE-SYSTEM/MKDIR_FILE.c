#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>

/////////////////////////////////////////////////////////////
/*  
    #include<sys/stat.h>

    int mkdir(const char * pathname,mode_t mode);

    RETURN: 
        Success = zero
        Error   = -1
*/
/////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
    int iRet = 0;

    iRet = mkdir(argv[1],S_IRWXU);
    if(iRet == 0)
    {
        printf("Directory Created Successfully..\n");
    }
    else
    {
        printf("ERROR WHILE CREATING DIRECTORY..\n");
    }

    return 0;
}
