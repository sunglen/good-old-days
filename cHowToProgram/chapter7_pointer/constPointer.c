#include <stdio.h>

main()
{ 
   char ok(void);
   int x=5;int y=20;
   const int * const ptr=&x;
   ptr=&y;
   *ptr=100;
   printf("%d\n",*ptr);
   ok();
 
   return 0;
}

char ok(void)
{
   printf("ok!\n");
   return 'w';
}

   









