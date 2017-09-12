#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "fatal.c"
#include <unistd.h>
main(int argc,char **argv)
{

    if(chdir(argv[1])==-1)fatal("chdir()");
    mkdir("h",777);
}
