/*练习3.6:
表明如果启用添加标志打开一个文件用于读、写，
那么能用lseek在任何一个位置开始读，但是只能
在添加写，而不能更新文件中任何一个部分的
数据。
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	off_t offset;
	char buf[1024];

	if((fd=open("octave-core", O_RDWR|O_APPEND)) == -1)
		exit(1);

	if((offset=lseek(fd, 0, SEEK_CUR)) == -1)
		exit(1);	
	
	printf("开始的偏移量是：%d\n", offset);

	if((offset=lseek(fd, 15, SEEK_SET)) != 15)
		exit(1);	
	
	printf("现在的偏移量是：%d\n从现在的偏移量开始读：\n", offset);
	
	if(read(fd, buf, sizeof(buf)) == -1)
		exit(1);

	buf[sizeof(buf)-1]='\0';

	printf("%s", buf);
	
	if((offset=lseek(fd, 15, SEEK_SET)) != 15)
		exit(1);	
		
	printf("现在的偏移量是：%d\n从现在的偏移量开始写：\n", offset);
	
	if(write(fd, "yes, you can", 12) == -1)
		exit(1);
	
	if((offset=lseek(fd, 0, SEEK_CUR)) == -1)
		exit(1);	
	
	printf("最后的偏移量是：%d\n", offset);
	return 0;
}
