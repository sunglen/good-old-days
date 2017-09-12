#include <sys/mount.h>
#include <unistd.h>
#include "fatal.c"

main()
{
   setuid(0);
   seteuid(0);
   if(mount("/dev/fd0","/floppy","ext2",0,0)==-1)fatal("mount()");
}
