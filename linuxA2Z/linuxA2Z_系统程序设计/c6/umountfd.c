#include <sys/mount.h>
#include <unistd.h>
#include "fatal.c"
main()
{
    setuid(0);
    seteuid(0);
    if(umount("/dev/fd0")==-1)
      fatal("umount()");
}

