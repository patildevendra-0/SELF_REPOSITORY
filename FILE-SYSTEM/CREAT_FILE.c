#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/////////////////////////////////////////////////////////////
/*
    creat -- Create new file

    #include<fcntl.h>
    -------------------------------------------------------

    int creat(const char *path,mode_t mode)

            ex :  fd = creat(filename,0777);    

            const char *filename = "newfile.txt";

    ---------------------------------------------------------

    pathname  : The path to the file you want to create.
    mode      : The file mode (permissions) to be set for the newly created file
*/
/////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
    int Fd = 0;

    if(argc != 2)
    {
        printf("INSUFFICIENT ARUMENTS..\n");
        return -1;
    }

    Fd = creat(argv[1],0777);
    if(Fd == -1)
    {
        printf("UNABLE TO CREATE FILE..\n");
        return -1;
    }
    else
    {
        printf("FILE IS SUCCESSFULLY CREATED..\n");
    }

    close(Fd);
    return 0;
}