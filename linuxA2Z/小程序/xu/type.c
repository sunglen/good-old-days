void type(void)
{
     int x,i;
     FILE *fp;
     xu ok;	
     if((fp=fopen("emp","r"))==NULL){printf("数据库尚未建立!\n");exit(1);}
     printf("当前操作:显示比输入分数大的学生的成绩:");
     for(;;)
     {
     fseek(fp,20,0);i=1;
     printf("\n请输入学生成绩:(输入0退出)");
     scanf("%d",&x);
     if(x==0){break;}
     printf("\n学号	     姓名		分数\n");
      while(fread(&ok.score,4,1,fp)==1)
      { 
       if(ok.score>=x)
       {
         fseek(fp,SIZE*(i-1)+4,0);
         fread(ok.name,10,1,fp);
         printf("%2d%16s%18f\n",i,ok.name,ok.score);
       }
       fseek(fp,SIZE*i+20,0);
       i++;
      }      
     }
    fclose(fp);
}

