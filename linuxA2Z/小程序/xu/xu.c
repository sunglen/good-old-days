/*linux gcc 调试通过*/
#include "xu.h"
#include "creat_emp.c"
#include "type.c"

main(void)
{
  int number;
  printf("学生成绩管理系统\n");
  printf("---------------- 湖北工学院 许传琪 2000年6月17日\n");
  printf("---------------- 遵守GPL 版权信息可在http://www.gnu.org找到\n");

  /*版权信息*/
  for(;;)
  { 
   printf("_______________\n");
   printf("1.建立数据库\n");
   printf("2.添加数据\n");
   printf("3.插入数据\n");
   printf("4.修改数据\n");
   printf("5.删除数据\n");
   printf("6.成绩检索\n");
   printf("7.退出系统\n");
   printf("_______________");
   printf("\n\n请输入菜单号(1-7):");
   scanf("%d",&number);
   switch(number)
   {
         case 1: creat_emp("建立"); break;
	 case 2: creat_emp("添加"); break;
	 case 3: creat_emp("插入"); break;
	 case 4: creat_emp("修改"); break;
	 case 5: creat_emp("删除"); break;
	 case 6: type(); break;
	 case 7: exit(0); 
   }
  } 
}

