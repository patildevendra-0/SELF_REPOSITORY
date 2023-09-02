#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>

////////////////////////////////////////////////////////////
/*    
    stat() TAKE FILE PATH and address(&) stuct obj WHERE RETRIVED DATA WILL BE STORED

    #include<sys/stat.h>

    struct stat sobj;

    int stat(const char *pathname, struct stat *statbuf);   

                        -These System call return information about a file
            -pathname  : The path to the file or file system object for which you want to retrieve information.
            -statbuf   : A pointer to a struct stat object where the retrieved information will be stored.
    RETURN :
            -On success, zero is returned.  
            -On error, -1 is returned
            struct stat {
                            dev_t     st_dev;         // ID of device containing file
                            ino_t     st_ino;         // Inode number
                            mode_t    st_mode;        // File type and mode
                            nlink_t   st_nlink;       // Number of hard links
                            uid_t     st_uid;         // User ID of owner
                            gid_t     st_gid;         // Group ID of owner
                            dev_t     st_rdev;        // Device ID (if special file)
                            off_t     st_size;        // Total size, in bytes
                            blksize_t st_blksize;     // Block size for filesystem I/O
                            blkcnt_t  st_blocks;      // Number of 512B blocks allocated
                            time_t    st_atime;       // Last access time
                            time_t    st_mtime;       // Last modification time
                            time_t    st_ctime;       // Last status change time
                        };

    *POSIX 
    #include<time.h>
                    -ctime()   -------> unix epoch to local time

*/
////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{
    struct stat sobj;
    int iRet = 0;

    if(argc != 2)
    {
        printf("INSUFFICIENT COUNT..\n");
        return -1;
    }

    iRet = stat(argv[1],&sobj);

    if(iRet == -1)
    {
        printf("STAT FUNCTION FAILS...\n");
        return -1;
    }

    printf("FILE NAME        : %s\n",argv[1]);
    printf("FILE SIZE        : %ld\n",sobj.st_size);
    printf("NUMBER OF LINKS  : %ld\n",sobj.st_nlink);
    printf("INODE NUMBER     : %ld\n",sobj.st_ino);
    printf("FILESYSTEM NUMBER: %ld\n",sobj.st_dev);
    printf("NUMBER OF BLOCK  : %ld\n",sobj.st_blocks);
    printf("FILE PERMISSIONS : ");

    printf((S_ISDIR(sobj.st_mode))? "d" : "-");
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