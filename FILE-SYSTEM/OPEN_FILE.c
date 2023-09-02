#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

////////////////////////////////////////////////////////
/*
    TTY - > TELE TYPE TERMINAL

    # FOR FD :
                if Fd = 0 -> stdin       (KEYBOARD)
                if Fd = 1 -> stdout      (CONSOL/SCREEN)
                if Fd = 2 -> stderr      (CONSOL/SCREEN)

    ----------------------------------------------------------
    #include <fcntl.h>

    Open -> System Call

    int open(const char *pathname, int flags, mode_t mode);
                ex: Fd = open(Filename,O_RDONLY | S_IRWXU);

    -The return value of open() is a file descriptor
    
    -----------------------------------------------------------

    -pathname    : The path to the file you want to open.
    -flags       : A combination of flags that control how the file is opened and used.
    -mode        : The file mode (permissions) to be set if the file is being created.

    FLAGS: 
                    O_RDONLY    : Open for reading only.
                    O_WRONLY    : Open for writing only.
                    O_RDWR      : Open for reading and writing.
                    O_CREAT     : Create the file if it doesn't exist.
                    O_TRUNC     : Truncate the file if it exists.
                    O_APPEND    : Append data to the end of the file.
                    O_ASYNC     : Enable asynchronous I/O notifications for a file
    MODE:
                    S_IRWXU     :0777   --  User has READ-WRITE-EXECUTE Permission
                    S_IRUSR     :004    --  User has READ Permission
                    S_IWUSR     :002    --  User has WRITE Permission
                    S_IXUSR     :001    --  User has EXECUTE Permission

                    S_IRWXG     :0777   --  Group has READ-WRITE-EXECUTE Permission
                    S_IRGRP     :004    --  Group has READ Permission
                    S_IWGRP     :002    --  Group has WRITE Permission
                    S_IXGRP     :001    --  Group has EXECUTE Permission

                    S_IRWXO     :0777   --  Others has READ-WRITE-EXECUTE Permission
                    S_IROTH     :004    --  Others has RAED Permission
                    S_IWOTH     :002    --  Others has WRITE Permission
                    S_IXOTH     :001    --  Others has EXECUTE Permission
*/
////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
    int Fd = 0;
    char Fname[20];

    printf("ENTER THE NAME OF FILE THAT YOU WANT TO OPEN: ");
    scanf("%s",Fname);

    Fd = open(Fname,O_RDONLY);

    if(Fd == -1)
    {
        printf("UNABLE TO OPEN FILE...\n");
        return -1;
    }
    else
    {
        printf("FILE IS SUCCESSFULLY OPEN WITH FD : %d\n",Fd);
    }

    return 0;
}