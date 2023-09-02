#include<stdio.h>
#include<unistd.h>
#include<dirent.h>

/////////////////////////////////////////////////////////////
/*
        #include<dirent.h>

        DIR *dp = NULL;
        struct dirent *entry = NULL;

        -The opendir() function opens a directory stream corresponding to
            the directory name, and returns a pointer to the directory
            stream.  The stream is positioned at the first entry in the
            directory.

        RETURN :
            Success    - pointer to the directory stream
            Error      - error OR NULL    
*/
/////////////////////////////////////////////////////////////

int main(int argc ,char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("INSUFFICIENT ARGUMENTS...\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("UNABLE TO OPEN DIRECTORY..\n");
        return -1;
    }

    while((entry = readdir(dp))!=NULL)
    {
        printf("%s\n",entry->d_name);
    }
}