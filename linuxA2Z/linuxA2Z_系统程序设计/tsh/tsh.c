#include "def.h"
#include "getline.c"
#include "parse.c"
#include "execute.c"

initcold(void)
{
/*do nothing,但是可用signal调用设置信号处理函数*/
}

initwarm(void)
{
   int i;

   backgnd=FALSE;
   lineptr=line;
   avptr=avline;
   infile[0]='\0';
   outfile[0]='\0';
   append=FALSE;

   for(i=0;i<PIPELINE;++i)
   {
     cmdlin[i].infd=0;
     cmdlin[i].outfd=1;
   }

   for(i=3;i<OPEN_MAX;++i)
      close(i);
   printf("tsh:");
   fflush(stdout);
}

main(void)
{
     int i;

     initcold();

     for(;;)
     {
            initwarm();

            if(getline())
               if(i=parse()); /*解析 */
                 execute(i);
     }
}


