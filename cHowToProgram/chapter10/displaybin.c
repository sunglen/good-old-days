#include <stdio.h>

void displayBits(unsigned);

main(void)
{
   unsigned x;
   printf("Enter a int:");
   scanf("%u",&x);
   displayBits(x);
   return 0;
}

void displayBits(unsigned value)
{
   unsigned c,displayMask=1<<(8*sizeof(unsigned)-1);
   printf("%7u=",value);

   for(c=1;c<=8*sizeof(unsigned);++c)
   {
      putchar(value & displayMask ?'1':'0');
      value<<=1;

      if(c%8==0)
         putchar(' ');
    }
    putchar('\n');
}

