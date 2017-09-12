#include <termios.h>
#include <unistd.h>

struct termios tsave;

void scan_mode(void)
{

struct termios tbuf;

if (!isatty(0))
  fatal ("standard input is not a terminal");

  if (tcgetattr(0,&tbuf)==-1)
    fatal("gettinf terminal attributes");

    tsave=tbuf;
    tbuf.c_lflag &= ~(ECHO|ICANON|ISIG);
 /* tbuf.c_cc[VMIN]=tbuf.c_cc[VTIME]=0;*/

    if (tcsetattr(0,TCSANOW,&tbuf)==-1)
      fatal("settinf terminal attributes");
}

void restore_mode(void)
{
 if (tcsetattr(0,TCSANOW,&tsave)==-1)
   fatal("restoring terminal attributes");
}

