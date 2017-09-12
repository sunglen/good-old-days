#include <unistd.h>
#include "fatal.c"
main(int argc,char **argv)
{
 if(argc!=3)fatal("检查参数个数");
 if(link(argv[1],argv[2])==-1)fatal("检查参数本身");
 unlink(argv[1]);
}
