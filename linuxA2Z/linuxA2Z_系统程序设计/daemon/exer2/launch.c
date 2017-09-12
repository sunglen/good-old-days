#include <stdio.h>
#include <sys/param.h>
#include <signal.h>
#include <fcntl.h>
#define NA_EXIT 0
#define NA_RESTART 1
#include "setup_daemon.c"
#include "fatal.c"
main(int argc,char **argv)
{
  setup_daemon();
  signal(SIGCHLD,SIG_IGN);
  if(argc==1)
    fatal("Usage: run <command> [<parameters>]\n",0);
    execvp(argv[1],&argv[2]);
    fatal("Sorry...couldn't run that!\n",0);

}

