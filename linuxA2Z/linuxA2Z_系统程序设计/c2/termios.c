#include <termios.h>
#include <stdio.h>
#include "fatal.c"

main(int argc,char **argv)
{
 struct termios terminal;

 if(tcgetattr(0,&terminal)==-1)
   fatal("getting terminal attributes");

 printf("input mode flags: %d\n",terminal.c_iflag);
 printf("output mode flags: %d\n",terminal.c_oflag);
 printf("control mode flags: %d\n",terminal.c_cflag);
 printf("local mode flags: %d\n",terminal.c_lflag);

}
