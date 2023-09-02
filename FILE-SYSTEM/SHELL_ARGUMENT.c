#include<stdio.h>


//////////////////////////////////////////////////////////////////////////////
/*
    argc        -> ARGUMENT COUNT
    argv[]      -> ARGUMENT VECTOR

    argv[0]     -> Actual File Name 

                    .ex - 1 : gcc FileSystem2.c -o myexe 
                    argv[0] = myexe
                    ---------------------------------------------
                    .ex - 1 : gcc FileSystem2.c -o myexe Demo.txt
                    argv[0] = myexe
                    argv[1] = Demo.txt
*/
///////////////////////////////////////////////////////////////////////////////

int main(int argc,char *argv[])
{

    if(argc!=2)
    {
        printf("INSUFFICIENT ARGUMENTS...\n");
        return -1;
    }

    printf("APPLICATION NAME  \t\t : %s\n",argv[0]);
    printf("FILE NAME IS AS ARGUMENT : %s\n",argv[1]);

    return 0;
}