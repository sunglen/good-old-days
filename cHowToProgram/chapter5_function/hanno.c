#include <stdio.h>

void do_move(int,int,int,int);

main()
{
   int n=0,fi=1,la=3,mi=2;

   printf("汉诺塔。请输入圆盘数：（-1结束）\n");
   scanf("%d",&n);

   while(n!=-1)
   {
      do_move(n,fi,la,mi);
      printf("汉诺塔。请输入圆盘数：（-1结束）\n");
      scanf("%d",&n);
   }

   return 0;
}

void do_move(int n,int fi,int la,int mi)
{
     if(n==1)
        printf("%d ------->%d\n",fi,la);
     else
        {
         do_move(n-1,fi,mi,la);
         do_move(1,fi,la,mi);
         do_move(n-1,mi,la,fi);
        }
}

