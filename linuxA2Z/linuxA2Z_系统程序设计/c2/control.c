#include <stdio.h>
#include <string.h>
#include "fatal.c"
#include "scan_mode.c"
main(int argc,char **argv)
{
char user_name[10];
char secret_words[20];

printf("请输入用户名:");
/*scanf("%s",secret_words);*/
gets(user_name);
scan_mode();
printf("请输入您的密码:");
gets(secret_words);
restore_mode();
printf("\n您好! %s\n",user_name);
printf("您的密码是: %s\n",secret_words);

}

