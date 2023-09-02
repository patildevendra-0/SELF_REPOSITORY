#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>

/////////////////////////////////////////////////////////////
/*  POSIX
    
    IF FILE IS ALREADY OPEN THEN fstat() TAKE OPEN FILE FD and address(&) stuct obj WHERE RETRIVED DATA WILL BE STORED

    fstat() --- get file status(info)
    iRet = fstat(Fd,&sobj);
            Fd   = File Discriptor
            sobj = struct stat object where the retrieved information will be stored.

    RETURN :
            -On success, zero is returned.  
            -On error, -1 is returned
*/
/////////////////////////////////////////////////////////////
int main(int argc ,char *argv[])
{
    int Fd = 0;
    int iRet = 0;

    struct stat sobj;

    Fd = open(argv[1],O_RDONLY);
    if(Fd == -1)
    {
        printf("UNABLE TO OPEN FILE...\n");
        return -1;
    }

    iRet = fstat(Fd,&sobj);
    if(iRet == -1)
    {
        printf("FSTAT FUNCTION FAILS..\n");
        return -1;
    }

    printf("FILE NAME        : %s\n",argv[1]);
    printf("FILE SIZE        : %ld\n",sobj.st_size);
    printf("NUMBER OF LINKS  : %ld\n",sobj.st_nlink);
    printf("INODE NUMBER     : %ld\n",sobj.st_ino);
    printf("FILESYSTEM NUMBER: %ld\n",sobj.st_dev);
    printf("NUMBER OF BLOCK  : %ld\n",sobj.st_blocks);
    printf("FILE PERMISSIONS : ");
    printf((S_ISDIR(sobj.st_mode))?  "d" : "-");
    printf((sobj.st_mode & S_IRUSR)? "r" : "-");
    printf((sobj.st_mode & S_IWUSR)? "w" : "-");
    printf((sobj.st_mode & S_IXUSR)? "x" : "-");
    printf((sobj.st_mode & S_IRGRP)? "r" : "-");
    printf((sobj.st_mode & S_IWGRP)? "w" : "-");
    printf((sobj.st_mode & S_IXGRP)? "x" : "-");
    printf((sobj.st_mode & S_IROTH)? "r" : "-");
    printf((sobj.st_mode & S_IWOTH)? "w" : "-");
    printf((sobj.st_mode & S_IXOTH)? "x" : "-");
    printf("\n");
    printf("LAST MODIFICATION : %s\n",ctime(&(sobj.st_mtime)));

    return 0;
}