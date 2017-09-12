#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

main()
{
 if((int)getpid()==(int)getpgrp())
    printf("该进程是领头进程\n");
 else
    printf("该进程不是领头进程\n");
}



