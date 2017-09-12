#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "filelength.c"

main(int argc,char **argv)
{
    int fd1,fd2;
    long pic_offset,file_len,bmp_len,len=0;
    int i,tag;
    char byte_buf,byte_bufs[8];
    char mask[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
    /*用于将被隐藏的文件拆分为位形式的掩码*/
    if((argc!=4)||(strcmp(argv[1],"-h")==0))
    {
    /*加入帮助*/exit(1);
    }
    
    if((argc==4)&&(strcmp(argv[3],"-p")==0))
    {
       fd1=open(argv[1],O_RDONLY);
       fd2=open(argv[2],O_RDWR);
       file_len=filelength(fd1);
       lseek(fd2,10,SEEK_SET);
       read(fd2,&bmp_len,4);
       bmp_len=filelength(fd2)-bmp_len-1;
       lseek(fd2,28,SEEK_SET);
       read(fd2,&tag,2);printf("This is %d bits\n",tag);
      /* if(tag!=24)
         printf("ERROR! NOT A 24bit BMP FILE!\n");
       else*/ if(file_len>=bmp_len/8)
         printf("ERROR! FILE TOO BIG!\n");
       else
       {
          lseek(fd2,2,SEEK_SET);
	  write(fd2,&file_len,4);
	  lseek(fd2,10,SEEK_SET);
	  read(fd2,&pic_offset,4);
	  lseek(fd2,pic_offset,SEEK_SET);
	  while(len<file_len)
	  {
	       read(fd1,&byte_buf,1);
	       len++;
	       read(fd2,&byte_bufs,8);
	       
	       for(i=0;i<8;i++)
	       {
	          if((byte_buf&mask[i])>>i) byte_bufs[i]|=1; 
	          else byte_bufs[i]&=0xfe;
               }
	       lseek(fd2,-8,SEEK_CUR);
	       write(fd2,byte_bufs,8);
          }
       }
    close(fd1);
    close(fd2);
    printf("成功加密!\n");
    exit(0);
    }
    if((argc==4)||(strcmp(argv[3],"-g")==0))
    {
      fd1=open(argv[2],O_RDONLY);
      fd2=open(argv[1],O_CREAT|O_WRONLY);
      lseek(fd1,28,SEEK_SET);
      read(fd1,&tag,2);
    /*  if(tag!=24)
        printf("ERROR! NOT 24bit\n");
      else */
      {
          lseek(fd1,2,SEEK_SET);
	  read(fd1,&file_len,4);
	  lseek(fd1,10,SEEK_SET);
	  read(fd1,&pic_offset,4);
	  lseek(fd1,pic_offset,SEEK_SET);
	  while(len<file_len)
	  {
	      read(fd1,byte_bufs,8);
	      byte_buf=0;
	      for(i=0;i<8;i++)
	         if(byte_bufs[i]&1==1) byte_buf|=mask[i];
	  write(fd2,&byte_buf,1);
          len++;	
          }
	  close(fd1);
	  close(fd2);
	  printf("提取成功!\n");
	  exit(0);
    }
  }
  
}

