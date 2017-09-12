/*文件tdd.h*/
/*本文件包含设备驱动程序和使用这一驱动程序的用户代码所需要的定义和结构说明*/
#ifdef KERNEL

#define TRACE_TXT(text)\
   {\
      if(tdd_trace)\
      {\
         console_print(text);\
         console_print("\n");\
      }\
   }

#define TRACE_CHR(chr)\
   {\
      if(tdd_trace)\
         console_print(chr);\
   }

#define TDD_WRITE 0
#define TDD_READ 1

#endif

#define FALSE 0
#define TRUE 1
#define MAX_BUF 120
#define TDD_TRON (('M'<<8)|0x01)
#define TDD_TROFF (('M'<<8)|0x02)

struct tdd_buf
{
   int buf_size;
   char buffer[MAX_BUF];
   struct tdd_buf *link;
};


