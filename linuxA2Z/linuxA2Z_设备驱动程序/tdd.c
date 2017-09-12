/*header代码开始*/
/*这一段包括所有有关的头文件。注意KERNEL符号的定义；它用在一些头文件中（包括tdd.h)。
当头文件用在内核代码中时，有条件地包括一些定义和附加项。普通用户代码中不定义这一符号，
因此不包含这些附加项。*/
#define KERNEL

#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/tty.h>
#include <linux/signal.h>
#include <linux/errno.h>
#include <linux/malloc.h>

#include <asm/io.h>
#include <asm/segment.h>
#include <asm/system.h>
#include <asm/irq.h>

#include "tdd.h"

/*这是在驱动程序内部使用的static变量。变量tdd_trace用作打开和关闭查错跟踪输出的标志；
write_busy和read_busy是用来防止多重读和多重写的标志；而qhead和qtail分别是信息连接表的
头尾指针*/
static int tdd_trace;
static int write_busy;
static int read_busy;
static struct tdd_buf *qhead;
static struct tdd_buf *qtail;

/*本段建立指向其他设备驱动程序子程序的file_operation结构。在引导系统时，由初始化子程序
将指向这一结构的指针传送给内核。在其他方面不说明的内核函数也在这里说明。*/
static int tdd_read(struct inode *,struct file *,char *,int);
static int tdd_write(struct inode *,struct file *,char *,int);
static int tdd_ioctl(struct inode *,struct file *,unsigned int,unsigned long);
static int tdd_open(struct inode *,struct file *);
static void tdd_release(struct inode *,struct file *);
extern void console_print(char *);

struct file_operations tdd_fops =
{
   NULL,
   tdd_read,
   tdd_write,
   NULL,
   NULL,
   tdd_ioctl,
   NULL,
   tdd_open,
   tdd_release,
   NULL,
   NULL,
   NULL,
   NULL
};
/*header代码结束*/

/*init函数*/
void tdd_init(void)
{
   tdd_trace=TRUE;

   if(register_chrdev(30,"tdd",&tdd_fops))
      TRACE_TXT("Can not register tdd driver as major device 30")
   else
      TRACE_TXT("Tiny device driver registered succefully!")

  qhead=0;
  write_busy=FALSE;
  read_busy=FALSE;
  tdd_trace=FALSE;
  return;
}

/*open函数*/
static int tdd_open(struct inode *inode,struct file *file)
{
   TRACE_TXT("tdd_open")

/*第一项任务是为准备打开的设备特殊文件提取辅助设备号。这可以用宏命令MINOR（）
在inode参数所指的结构中在i_rdev字段中提取。*/
   switch(MINOR(inode->i_rdev))
   {
      case TDD_WRITE:
         if(write_busy)
            return -EBUSY;
         else
            write_busy=TRUE;
         return 0;

      case TDD_READ:
         if(read_busy)
            return -EBUSY;
         else
            read_busy=TRUE;
         return 0;

      default:
         return -ENXIO;
   }
}

/*release函数*/
/*tdd_release所作的只是将读和写的忙标致复位。*/
static void tdd_release(struct inode *inode,struct file *file)
{
   TRACE_TXT("tdd_release")

   switch(MINOR(inode->i_rdev))
   {
      case TDD_WRITE:
         write_busy=FALSE;
         return;
      case TDD_READ:
         read_busy=FALSE;
         return;
   }
}

/*write函数*/
static int tdd_write(struct inode *inode,struct file *file,char *buffer,int count)
{
   int i,len;
   struct tdd_buf *ptr;
   TRACE_TXT("tdd_write")

   /*检验和保证只有打开/dev/tddw设备特殊文件的进程才能写信息。*/
   if(MINOR(inode->i_rdev)!=TDD_WRITE)
      return -EINVAL;

   /*分配足以容纳单条信息的内核内存块，进行检验确保没有问题。如有问题返回出错信息*/
   if((ptr=kmalloc(sizeof(struct tdd_buf),GFP_KERNEL))==0)
      return -ENOMEM;

   /*检验内核能从指定的内存块中读取。然后将信息从用户空间复制到内核分配的信息空间。
   实际复制的字符数由count或BUF_MAX的大小决定，取其中较小的一个作为作为字符计数。*/
   len=count<MAX_BUF?count:MAX_BUF;

   if(verify_area(VERIFY_READ,buffer,len))
      return -EFAULT;

   for(i=0;i<count&&i<MAX_BUF;++i)
   {
      ptr->buffer[i]=get_user_byte(buffer+1);
      TRACE_CHR("w")
   }

   /*将新的信息结构连接到设备驱动程序的联结表的最后*/
   ptr->link=0;
   if(qhead==0)
      qhead=ptr;
   else
     qtail->link=ptr;
   qtail=ptr;
   TRACE_CHR("\n")

   /*在信息结构中设置实际信息长度，同时将这一值用tdd_write()返回。这一值并由write系统
   调用返回给发出调用的用户进程*/
   ptr->buf_size=i;
   return i;
}

/*read函数*/
/*tdd_read()函数的buffer和count参数分别是指向用户空间的缓冲区的指针和字符计数。
用户缓冲区现在从设备驱动程序的信息结构中接受字符*/
static int tdd_read(struct inode *inode,struct file *file,char *buffer,int count)
{
   int i,len;
   struct tdd_buf *ptr;

   TRACE_TXT("tdd_read")

   /*只允许对/dev/ttyr设备特殊文件执行read()调用。*/
   if(MINOR(inode->i_rdev)!=TDD_READ)
      return -EINVAL;

   /*如果在队列里没有信息，并不阻止read()调用，只将errno变量的值设为ENDATA，并返回-1值。*/
   if(qhead=0)
      return -ENODATA;

   /*将第一条信息从队列中取下，设置变量ptr指向这条信息。*/
   ptr=qhead;
   qhead=qhead->link;

   /*检验内核能否写指定的内存块，然后按要求的字符数(count)或者信息缓冲区的实际字符数（ptr->buf_size)
   将信息复制到用户空间的缓冲区(buffer)。用较小的数字进行复制。用户有责任保证指定的缓冲区
   足以容纳请求的字符数，内核对此不进行检查。*/
   len=count<ptr->buf_size?count:ptr->buf_size;

   if(verify_area(VERIFY_WRITE,buffer,len))
     return -EFAULT;
   for(i=0;i<count&&i<ptr->buf_size;i++)
   {
      put_user_byte(ptr->buffer[i],buffer+i);
      TRACE_CHR("r")
   }
   TRACE_CHR("\n")

   /*最后将旧的信息结构释放归还内核，并返回实际传送的字节数。*/
   kfree_s(ptr,sizeof(struct tdd_buf));
   return i;
}

/*ioctl函数*/
/*这一驱动程序的ioctl()函数非常简单，但足以说明一些概念。*/
/*这一驱动程序提供了两个新的ioctl()调用，用来打开和关闭跟踪功能。分别用TDD_TRON和TDD_TROFF
命令来完成。*/
static int tdd_ioctl(struct inode *inode,struct file *file,unsigned int cmd,unsigned long arg)
{
   TRACE_TXT("tdd_ioctl")

   switch(cmd)
   {
      case TDD_TRON:
         tdd_trace=TRUE;
         return 0;
      case TDD_TROFF:
         tdd_trace=FALSE;
         return 0;
      default:
         return -EINVAL;
   }
}

