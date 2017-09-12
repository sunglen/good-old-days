#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

main()
{
  if((int)getuid()==(int)geteuid())
    printf("程序没有设setuid位\n");
  else
    printf("程序设置了setuid位\n");
}
