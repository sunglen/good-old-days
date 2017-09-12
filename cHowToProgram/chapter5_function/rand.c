#include <stdio.h>
#include <stdlib.h>

void sort_box(int *);

main()
{   
    int flag,test_num,i=1,j,box[14];

	printf("hi!孙舸。我现在要从28道题目中选出14道来给你做。\n");
        srand(791017);
	box[0]=rand()%28+1;
	while(i<=13)
	{
	   flag=0;
	   test_num=rand()%28+1;

	   for(j=1;j<=i;++j)
	   {
	      
	      if(box[j-1]==test_num)
              {
                  flag=1;
	      }
	   }

	   if(flag!=1)
	   {
	      box[i]=test_num;
	      ++i;
	   }

	}
	
        sort_box(box);

	for(i=1;i<=14;i++)
	{
	   printf("%4d",box[i-1]);
	   if(i%4==0)printf("\n");
        }
        printf("\n");
	return 0;
}

void sort_box(int *num_box)
{
   int i,j,tmp;
   for(i=1;i<=13;++i)
   {
      for(j=1;j<=14-i;++j)
      {
         if(num_box[j-1]>num_box[j])
         {
            tmp=num_box[j-1];
            num_box[j-1]=num_box[j];
            num_box[j]=tmp;
         }
      }
  }
}


