void creat_emp(char *info)
{
     int k,i;
     xu s[M];
     FILE *fp;
     printf("\n当前操作:%s! 请输入要%s的个数(不大于%d个):",info,info,M);
     scanf("%d",&k);
     fp=fopen("emp","a");fclose(fp);
     if((fp=fopen("emp","r+"))==NULL)
     {
       printf("\n文件打开失败!:-&");
       exit(1);
     }
     for(i=0;i<k;i++)
     {
        if(info=="插入"||info=="修改")
        {
          printf("\n请输入学号:");
          scanf("%d",&s[i].num);
          printf("\n请输入他(她)的:姓名 性别 年龄 成绩 \n");
          scanf("%s %s %d %f",s[i].name,s[i].xb,&s[i].age,&s[i].score);
        }
        else if(info=="删除")
        {
          printf("\n请输入学号:");
          scanf("%d",&s[i].num);
          s[i].score=0;
        }
        else
        {
          printf("\n请输入字段名(学号 姓名 性别 年龄 成绩):\n");
          scanf("%d %s %s %d %f",&s[i].num,s[i].name,s[i].xb,&s[i].age,&s[i].score);
        }
        fseek(fp,(long)(SIZE*(s[i].num-1)),0);
	fwrite(&s[i],SIZE,1,fp);
     }
     fclose(fp); 
}


