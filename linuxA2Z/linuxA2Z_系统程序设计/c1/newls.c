#include <stdio.h>
#include <dirent.h>

main(int argc,char **argv)
{
  DIR *dp;
  struct dirent *link;/*如何利用反回值*/

  dp=opendir(argv[1]); /*调用反回一个目录指针*/

  while((link=readdir(dp))!=0)
       printf("%s\n",link->d_name);

       closedir(dp);
}
