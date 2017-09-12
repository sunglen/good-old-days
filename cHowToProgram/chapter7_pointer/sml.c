/*
 *   sml语言解释程序 2000年11月11日  孙舸，湖北工学院
 */

#include <stdio.h>
#include <stdlib.h>

#define READ 10
#define WRITE 11		/*输入和输出*/
#define LOAD 20         
#define STORE 21        /*加载入寄存器和存储到内存*/
#define ADD 30
#define SUBTRACT 31
#define DEVIDE 32
#define MULTIPLY 33     /*运算*/
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43			/*控制的转移*/


/* 定义全局变量并且初始化：（sml的数据结构（存储结构））*/
int memory[100]={0};        /*       内存： （用做“正文段”、“用户数据段”）  */
int accumulator=0;        /*       累加寄存器：							 */	
int operationCode=0;		/*	     操作码：                                 */
int operand=0;			/*       操作数：                                 */
int instructionRegister=0;/*	     指令注册码：                              */
int instructionCounter=0; /*       指令计数器：                              */ 

int main(int,char **);
void exitSML(char *,int);
void computerDump(void);
			   
/* 函数main:*/

int main(int argc,char **argv)
{
   int i=0,temp=0;
   FILE *codeFilePtr;

//   printf("%02d ?",i);
   if(argc != 2)
      exitSML("用法：sml sml文件",1);

   if((codeFilePtr=fopen(argv[1],"r"))==NULL)
      exitSML("sml文件打开失败！",1);

   fscanf(codeFilePtr,"%d",&temp);
   while(temp != -99999)
   {
      if(temp > -9999 && temp < 9999)
      {
         memory[i]=temp;
		 ++i;
      }
      if(i==100) break;
//      printf("%02d ?",i);
      fscanf(codeFilePtr,"%d",&temp);
   }  

for(;;)
{
   instructionRegister=memory[instructionCounter];
   operationCode=instructionRegister/100;
   operand=instructionRegister%100;
   switch (operationCode)
   {
      case READ :
	     printf("?");
	     scanf("%d",&memory[operand]);
	     while(memory[operand] < -9999 || memory[operand] > +9999)
	     {
	        printf("Wrong,Again.?");
		    scanf("%d",&memory[operand]);
	     }
	     ++instructionCounter;
         break;
						
	  case WRITE :
	     printf("%d\n",memory[operand]);
		 ++instructionCounter;
		 break;
						
	  case LOAD :						      
		 accumulator=memory[operand];
		 ++instructionCounter;
		 break;
						
	  case STORE :
	     memory[operand]=accumulator;
	     ++instructionCounter;
		 break;
						
	  case ADD :
	     accumulator+=memory[operand];
		 if(accumulator < -9999 || accumulator > 9999)
	        exitSML("***累加器溢出***",1);
		 ++instructionCounter;
		 break;
					    
	  case SUBTRACT :
	     accumulator-=memory[operand];
		 if(accumulator < -9999 || accumulator > 9999)
		    exitSML("***累加器溢出***",1);
		 ++instructionCounter;
		 break;
						
	  case DEVIDE :
	     if(memory[operand]==0)
	        exitSML("*** 被0除:( ***",1);
	     accumulator/=memory[operand];
             ++instructionCounter;
	     break;
						
	  case MULTIPLY :
	     accumulator*=memory[operand];
		 if(accumulator < -9999 || accumulator > 9999)
		    exitSML("***累加器溢出***",1);
		 ++instructionCounter;
		 break;
						
	  case BRANCH :
	     instructionCounter=operand;
		 break;
						
	  case BRANCHNEG :
	     if(accumulator<0)
		instructionCounter=operand;
             else
                ++instructionCounter;
	     break;
						
	  case BRANCHZERO :
	     if(accumulator==0)
		    instructionCounter=operand;
	     else
	        ++instructionCounter;
		 break;
						
	  case HALT :
	     exitSML("***系统已停机***",0);
	     break;
	  default:
	     exitSML("***指令没有定义***",1);
		 break;
   }
}   
return 0;
}

/* 函数exitSML:*/

void exitSML(char *message,int exitCode)
{
   printf("%s",message);
   if(exitCode==0)
      printf("\n***Simpletron正常停机***\n");
   else
      printf("\n***系统非正常终止，请检查程序***\n");
   computerDump();
   exit(exitCode);
}

/* 函数computerdump:*/

void computerDump(void)
{
   int i,j;
   printf("\n寄存器：\n%-24s%+05d\n%-24s   %02d\n%-24s%+05d\n%-24s   %02d\n%-24s   %02d\n",
                       "accumulator",accumulator,
                       "instructionCounter",instructionCounter,
                       "instructionRegister",instructionRegister,
                       "operationCode",operationCode,
                       "operand",operand
         );
   printf("内存：\n");
   for(i=0;i<=9;++i)
      printf("%8d",i);
   for(i=0;i<=9;++i)
   {
      printf("\n%2d",i*10);
      for(j=0;j<=9;++j)
      {
         printf("   %+05d",memory[i*10+j]);
      }
   }
   printf("\n");
}
