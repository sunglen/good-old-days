#include <stdio.h>
#include <sys/times.h>
#include <unistd.h>

main(int argc,char **argv)
{
    int *status;
    struct tms *buf;

    if(argc==1)
    {
        printf("Usage: getime <command> [<parameters>]\n");
        exit(1);
    }
    if(!fork())
    {
      execvp(argv[1],&argv[2]);
      printf("Sorry...couldn't run that!\n");
    }
    waitpid(-1,status,0);
    sleep(5);
    times(buf);

    printf("All user time %d.%d\nAll sys time %d.%d\nAll user include child %d.%d\nAll sys include child %d.%d\n",
    buf->tms_utime/100,buf->tms_utime%100,buf->tms_stime/100,buf->tms_stime%100,
    buf->tms_cutime/100,buf->tms_cutime%100,buf->tms_cstime/100,buf->tms_cstime%100);
}
