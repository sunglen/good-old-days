#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define NEWFILE (O_WRONLY|O_CREAT|O_TRUNC)
#define MODE600 (S_IRUSR|S_IWUSR)
#define SIZE 1


void filecopy(char *infile,char *outfile)
{
     char buf[SIZE];
     int infd,outfd,count,pos;
     if((infd=open(infile,O_RDONLY))==-1)
        fatal("opening infile");
     if((outfd=open(outfile,NEWFILE,MODE600))==-1)
        fatal("opening outfile");
     while((count=read(infd,buf,sizeof(buf)))>0){
        pos=lseek(infd,(off_t)-5,SEEK_END);
        write(outfd,buf,count);
        printf("%d\n",pos);
                                                }


     if(count==-1)
       fatal("reading data");

     close(infd);
     close(outfd);
}





