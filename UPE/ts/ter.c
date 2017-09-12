#include <stdio.h>

main(void)
{
   char buf[10];
   while(read(0,buf,10))
      printf("buf:%s\n",buf);
   return 0;
}
