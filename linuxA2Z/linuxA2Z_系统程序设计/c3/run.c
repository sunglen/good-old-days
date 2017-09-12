#include <stdio.h>

main(int argc,char **argv)
{
    if(argc==1)
    {
        printf("Usage: run <command> [<parameters>]\n");
        exit(1);
    }

    execvp(argv[1],&argv[2]);
    printf("Sorry...couldn't run that!\n");

}

