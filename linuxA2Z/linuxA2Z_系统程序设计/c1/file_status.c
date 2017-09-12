#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#define MAJOR(a) (int)((unsigned short)(a)>>8)
#define MINOR(a) (int)((unsigned short)(a)&0xFF)

main(int argc,char **argv)
{
  struct stat sbuf;
  int dev_flag;

  for(;argc>1;--argc)
  {
  printf("\nFile name: %s\n",argv[argc-1]);

  if(stat(argv[argc-1],&sbuf)==-1)
    fatal("obtaining status details");

  dev_flag=file_type(&sbuf);
  printf("Permission bits: %o\n",sbuf.st_mode&07777); printf("Permission bits-not changed:%o\n",sbuf.st_mode);
  printf("File numbers:");
  printf("major %d,",MAJOR(sbuf.st_dev));
  printf("minor %d,",MINOR(sbuf.st_dev));
  printf("inode %d\n",sbuf.st_ino);
  printf("link count: %d\n",sbuf.st_nlink);

  if(dev_flag)
  {
  printf("Device numbers:");
  printf("major %d,",MAJOR(sbuf.st_rdev));
  printf("minor %d\n",MINOR(sbuf.st_rdev));
  }
  else
    printf("File size:%ld\n",sbuf.st_size);

  printf("File owner ID: %d\n",sbuf.st_uid);
  printf("File group ID: %d\n",sbuf.st_gid);
  }
 }

 file_type(struct stat *sbufp)
 {
   printf("File type:");

   switch(sbufp->st_mode&S_IFMT)
   {
   case S_IFREG:
     printf("Ordinary file\n");
     return 0;
   case S_IFDIR:
     printf("Directory\n");
     return 0;
   case S_IFIFO:
     printf("Named pipe(FIFO)\n");
     return 0;
   case S_IFBLK:
     printf("Block device special file\n");
     return 1;
   case S_IFCHR:
     printf("Character device special file\n");
     return 1;
   default:
     printf("unknown...\n");
     exit(1);
   }
 }

 fatal(char *mess)
{
 fprintf(stderr,"Error: %s\n",mess);
 exit(1);
}
