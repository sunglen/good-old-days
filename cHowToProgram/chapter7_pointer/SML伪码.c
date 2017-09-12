/*
 * sml语言解释程序伪码 2000年11月11日  孙舸，湖北工学院
 */

 包含头文件；stdio.h stdlib.h
 定义宏；
 定义全局变量并且初始化：（sml的数据结构（存储结构））
               内存： int memory[100];（用做“正文段”、“用户数据段”）
               累加寄存器：int accumulator;
			   操作码：int operationCode;
			   操作数：int operand；
			   指令注册码：int instructionRegister;
               指令计数器：int insturctionCounter;
定义函数原型：
               main(void);
			   computerDump(void);
			   exitSLM(char *,int);
函数main:

               main()
			   {
			         定义局部变量；
					 循环：
					     读入指令存储到数组中，如果数字等于-99999，结束读入。
                         检验数字是否大于+9999或小于-9999
						 读入；
						 ++i;
					 结束循环
                     
					 for(;;)
					 {
					    instructionRegister=memory[instructionCounter];
						operationCode=instructionRegister/100;
						operand=instructionRegister%100;
					    switch (operationCode)
					    {
					    case RDAD :
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
						      exitSLM("***累加器溢出***",1);
						   ++instructionCounter;
						   break;
					    case SUBTRACT :
						   accumulator-=memory[operand];
						   if(accumulator < -9999 || accumulator > 9999)
						      exitSLM("***累加器溢出***",1);
						   ++instructionCounter;
						   break;
						case DEVIDE :
						   if(memory[operand]==0)
						      exitSLM("*** 被0除:( ***",1);
						   accumulator/=memory[operand];
						   ++instructionCounter;
						   break;
						case MULTIPLY :
						   accumulator*=memory[operand];
						   if(accumulator < -9999 || accumulator > 9999)
						      exitSLM("***累加器溢出***",1);
						   ++instructionCounter;
						   break;
						case BRANCH :
						   instructionCounter=operand;
						   break;
						case BRANCHNEG :
						   if(accumulator<0)
						      instructionCounter=operand;
						   break;
						case BRANCHZERO :
						   if(accumulator==0)
						      instructionCounter=operand;
						   break;
						case HALT :
						   exitSLM("***系统已停机***",0);
						   break;
						default:
						   exitSLM("***指令没有定义***",1);
						break;
					    }
					 }   
               }

函数exitSLM:

void exitSLM(char *message,int exitCode)
{
   printf("%s",message);
   if(exitCode==0)
      printf("\n***Simpletron正常停机***\n");
   else
      printf("\n***系统非正常终止，请检查程序***\n);
   computerDump();
   exit(exitCode);
}

函数computerdump:

void computerDump(void)
{
   /*加入转储代码*/
}
