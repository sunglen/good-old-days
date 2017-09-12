#include <stdio.h>
#include <sys/types.h>
#include <time.h>

main()
{
    time_t *loc;
    struct tm *tmptr;
    time(loc);
    tmptr=localtime(loc);
    printf("现在是%d年%d月%d日%d点%d分%d秒.GMT时间%d\n",
    tmptr->tm_year+1900,tmptr->tm_mon+1,tmptr->tm_mday,tmptr->tm_hour,tmptr->tm_min,tmptr->tm_sec,*loc);
    printf("今天是星期%d,是这一年的第%d天.Goodluck!\n",tmptr->tm_wday,tmptr->tm_yday+1);
}

