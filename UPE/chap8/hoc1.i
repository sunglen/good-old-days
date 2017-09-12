# 1 "y.tab.c"

static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";








# 1 "hoc.y"


# 13 "y.tab.c"



short yylhs[] = {                                        -1,
    0,    0,    0,    1,    1,    1,    1,    1,    1,
};
short yylen[] = {                                         2,
    0,    2,    3,    1,    3,    3,    3,    3,    3,
};
short yydefred[] = {                                      1,
    0,    4,    2,    0,    0,    0,    0,    0,    0,    0,
    3,    9,    0,    0,    7,    8,
};
short yydgoto[] = {                                       1,
    5,
};
short yysindex[] = {                                      0,
  -10,    0,    0,  -39,   -8,  -35,  -39,  -39,  -39,  -39,
    0,    0,  -38,  -38,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -5,    1,    0,    0,
};
short yygindex[] = {                                      0,
    9,
};

short yytable[] = {                                       3,
    4,   11,    0,    9,    5,   12,    9,    7,   10,    8,
    6,   10,    6,    0,    0,   13,   14,   15,   16,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    4,
    0,    0,    0,    9,    7,    5,    8,    5,   10,    5,
    0,    6,    0,    6,    0,    6,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    2,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    2,
};
short yycheck[] = {                                      10,
   40,   10,   -1,   42,   10,   41,   42,   43,   47,   45,
   10,   47,    4,   -1,   -1,    7,    8,    9,   10,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   40,
   -1,   -1,   -1,   42,   43,   41,   45,   43,   47,   45,
   -1,   41,   -1,   43,   -1,   45,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,
};





# 123 "y.tab.c"















int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
double  *yyvsp;
double  yyval;
double  yylval;
short yyss[500 ];
double  yyvs[500 ];

# 19 "hoc.y"

	 
# 1 "/usr/include/stdio.h" 1 3
 

















 







# 1 "/usr/include/features.h" 1 3
 




















 


























































 



















 





 



 







 
# 137 "/usr/include/features.h" 3


 









 





 



























# 195 "/usr/include/features.h" 3


































 



 








 




 

# 1 "/usr/include/sys/cdefs.h" 1 3
 




















 




 





 








 




# 71 "/usr/include/sys/cdefs.h" 3


 







 



# 103 "/usr/include/sys/cdefs.h" 3



 








 















 








 








 









 







# 249 "/usr/include/features.h" 2 3


 








 





 

 








# 1 "/usr/include/gnu/stubs.h" 1 3
 






































# 277 "/usr/include/features.h" 2 3




# 27 "/usr/include/stdio.h" 2 3


 



# 1 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 1 3






 


# 19 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3



 


 





 


# 61 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3


 





 


















 





 

 

# 131 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3


 

 


































typedef unsigned int size_t;






















 




 

# 271 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3


# 283 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3


 

 

# 317 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3




 





















# 33 "/usr/include/stdio.h" 2 3





# 1 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stdarg.h" 1 3
 





























































 






typedef void *__gnuc_va_list;



 

# 116 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stdarg.h" 3



















# 202 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stdarg.h" 3




# 38 "/usr/include/stdio.h" 2 3


# 1 "/usr/include/bits/types.h" 1 3
 

















 









# 1 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 1 3






 


# 19 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3



 


 





 


# 61 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3


 





 


















 





 

 

# 131 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3


 

 


# 188 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3





 




 

# 271 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3


# 283 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3


 

 

# 317 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3




 





















# 29 "/usr/include/bits/types.h" 2 3


 
typedef unsigned char __u_char;
typedef unsigned short __u_short;
typedef unsigned int __u_int;
typedef unsigned long __u_long;

__extension__ typedef unsigned long long int __u_quad_t;
__extension__ typedef long long int __quad_t;
# 48 "/usr/include/bits/types.h" 3

typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;

typedef __quad_t *__qaddr_t;

typedef __u_quad_t __dev_t;		 
typedef __u_int __uid_t;		 
typedef __u_int __gid_t;		 
typedef __u_long __ino_t;		 
typedef __u_int __mode_t;		 
typedef __u_int __nlink_t; 		 
typedef long int __off_t;		 
typedef __quad_t __loff_t;		 
typedef int __pid_t;			 
typedef int __ssize_t;			 
typedef long int __rlim_t;		 
typedef __quad_t __rlim64_t;		 
typedef __u_int __id_t;			 

typedef struct
  {
    int __val[2];
  } __fsid_t;				 

 
typedef int __daddr_t;			 
typedef char *__caddr_t;
typedef long int __time_t;
typedef long int __swblk_t;		 

typedef long int __clock_t;

 
typedef unsigned long int __fd_mask;

 


 




 
typedef struct
  {
     





    __fd_mask __fds_bits[1024  / (8 * sizeof (__fd_mask)) ];


  } __fd_set;


typedef int __key_t;

 
typedef unsigned short int __ipc_pid_t;


 

 
typedef long int __blkcnt_t;
typedef __quad_t __blkcnt64_t;

 
typedef __u_long __fsblkcnt_t;
typedef __u_quad_t __fsblkcnt64_t;

 
typedef __u_long __fsfilcnt_t;
typedef __u_quad_t __fsfilcnt64_t;

 
typedef __u_long __ino64_t;

 
typedef __loff_t __off64_t;

 
typedef int __t_scalar_t;
typedef unsigned int __t_uscalar_t;

 
typedef int __intptr_t;


 





# 40 "/usr/include/stdio.h" 2 3







 
typedef struct _IO_FILE FILE;








# 1 "/usr/include/libio.h" 1 3
 




























# 1 "/usr/include/_G_config.h" 1 3
 





 






# 1 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 1 3






 


# 19 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3



 


 





 


# 61 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3


 





 


















 





 

 

# 131 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3


 

 


# 188 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3





 




 





























 


























typedef long int wchar_t;
























typedef unsigned int  wint_t;




 

 

# 317 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stddef.h" 3




 





















# 14 "/usr/include/_G_config.h" 2 3





















typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));




 


















 




 














# 30 "/usr/include/libio.h" 2 3
















 

# 1 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stdarg.h" 1 3
 





























































 










 

# 116 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stdarg.h" 3



















# 202 "/usr/lib/gcc-lib/i386-bluepoint-linux/egcs-2.91.66/include/stdarg.h" 3




# 48 "/usr/include/libio.h" 2 3







# 67 "/usr/include/libio.h" 3


 

















# 98 "/usr/include/libio.h" 3











 
























 



















struct _IO_jump_t;  struct _IO_FILE;

 







typedef void _IO_lock_t;



 

struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
   

   
  int _pos;
# 186 "/usr/include/libio.h" 3

};

struct _IO_FILE {
  int _flags;		 


   
   
  char* _IO_read_ptr;	 
  char* _IO_read_end;	 
  char* _IO_read_base;	 
  char* _IO_write_base;	 
  char* _IO_write_ptr;	 
  char* _IO_write_end;	 
  char* _IO_buf_base;	 
  char* _IO_buf_end;	 
   
  char *_IO_save_base;  
  char *_IO_backup_base;   
  char *_IO_save_end;  

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _blksize;
  __off_t   _old_offset;  


   
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

   

  _IO_lock_t *_lock;








  __off64_t   _offset;
   
  int _unused2[16];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;











 

 

typedef __ssize_t __io_read_fn  (void *  __cookie, char *__buf,
				       size_t __nbytes)  ;

 





typedef __ssize_t __io_write_fn  (void *  __cookie, __const char *__buf,
				      size_t __n)  ;

 





typedef int __io_seek_fn  (void *  __cookie, __off_t   __pos, int __w)  ;

 
typedef int __io_close_fn  (void *  __cookie)  ;


# 311 "/usr/include/libio.h" 3







extern int __underflow  (_IO_FILE *)    ;
extern int __uflow  (_IO_FILE *)    ;
extern int __overflow  (_IO_FILE *, int)    ;
















extern int _IO_getc  (_IO_FILE *__fp)    ;
extern int _IO_putc  (int __c, _IO_FILE *__fp)    ;
extern int _IO_feof  (_IO_FILE *__fp)    ;
extern int _IO_ferror  (_IO_FILE *__fp)    ;

extern int _IO_peekc_locked  (_IO_FILE *__fp)    ;

 



extern void _IO_flockfile  (_IO_FILE *)    ;
extern void _IO_funlockfile  (_IO_FILE *)    ;
extern int _IO_ftrylockfile  (_IO_FILE *)    ;












extern int _IO_vfscanf  (_IO_FILE *  , const char *  ,
			     __gnuc_va_list , int *  )    ;
extern int _IO_vfprintf  (_IO_FILE *  , const char *  ,
			      __gnuc_va_list )    ;
extern __ssize_t   _IO_padn  (_IO_FILE *, int, __ssize_t  )    ;
extern size_t   _IO_sgetn  (_IO_FILE *, void *, size_t  )    ;

extern __off64_t   _IO_seekoff  (_IO_FILE *, __off64_t  , int, int)    ;
extern __off64_t   _IO_seekpos  (_IO_FILE *, __off64_t  , int)    ;

extern void _IO_free_backup_area  (_IO_FILE *)    ;






# 57 "/usr/include/stdio.h" 2 3


 

typedef __off_t  fpos_t;







 





 





 






 







 




 








# 1 "/usr/include/bits/stdio_lim.h" 1 3
 




































# 110 "/usr/include/stdio.h" 2 3



 
extern FILE *stdin;		 
extern FILE *stdout;		 
extern FILE *stderr;		 


 
extern int remove  (__const char *__filename)    ;
 
extern int rename  (__const char *__old, __const char *__new)    ;


 

extern FILE *tmpfile  (void)    ;










 
extern char *tmpnam  (char *__s)    ;


 

extern char *tmpnam_r  (char *__s)    ;




 






extern char *tempnam  (__const char *__dir, __const char *__pfx)    ;



 
extern int fclose  (FILE *__stream)    ;
 
extern int fflush  (FILE *__stream)    ;


 
extern int fflush_unlocked  (FILE *__stream)    ;









 
extern FILE *fopen  (__const char *   __filename,
			 __const char *   __modes)    ;
 
extern FILE *freopen  (__const char *   __filename,
			   __const char *   __modes,
			   FILE *   __stream)    ;
# 197 "/usr/include/stdio.h" 3










 
extern FILE *fdopen  (int __fd, __const char *__modes)    ;


# 223 "/usr/include/stdio.h" 3



 

extern void setbuf  (FILE *   __stream, char *   __buf)    ;
 


extern int setvbuf  (FILE *   __stream, char *   __buf,
			 int __modes, size_t __n)    ;


 

extern void setbuffer  (FILE *   __stream, char *   __buf,
			    size_t __size)    ;

 
extern void setlinebuf  (FILE *__stream)    ;



 
extern int fprintf  (FILE *   __stream,
			 __const char *   __format, ...)    ;
 
extern int printf  (__const char *   __format, ...)    ;
 
extern int sprintf  (char *   __s,
			 __const char *   __format, ...)    ;

 
extern int vfprintf  (FILE *   __s,
			  __const char *   __format,
			  __gnuc_va_list  __arg)    ;
 
extern int vprintf  (__const char *   __format,
			 __gnuc_va_list  __arg)    ;
 
extern int vsprintf  (char *   __s,
			  __const char *   __format,
			  __gnuc_va_list  __arg)    ;


 
extern int snprintf  (char *   __s, size_t __maxlen,
			  __const char *   __format, ...)    
     __attribute__ ((__format__ (__printf__, 3, 4)));

extern int __vsnprintf  (char *   __s, size_t __maxlen,
			     __const char *   __format,
			     __gnuc_va_list  __arg)    
     __attribute__ ((__format__ (__printf__, 3, 0)));
extern int vsnprintf  (char *   __s, size_t __maxlen,
			   __const char *   __format,
			   __gnuc_va_list  __arg)    
     __attribute__ ((__format__ (__printf__, 3, 0)));


# 302 "/usr/include/stdio.h" 3



 
extern int fscanf  (FILE *   __stream,
			__const char *   __format, ...)    ;
 
extern int scanf  (__const char *   __format, ...)    ;
 
extern int sscanf  (__const char *   __s,
			__const char *   __format, ...)    ;

# 330 "/usr/include/stdio.h" 3



 
extern int fgetc  (FILE *__stream)    ;
extern int getc  (FILE *__stream)    ;

 
extern int getchar  (void)    ;

 




 
extern int getc_unlocked  (FILE *__stream)    ;
extern int getchar_unlocked  (void)    ;



 
extern int fgetc_unlocked  (FILE *__stream)    ;



 
extern int fputc  (int __c, FILE *__stream)    ;
extern int putc  (int __c, FILE *__stream)    ;

 
extern int putchar  (int __c)    ;

 




 
extern int fputc_unlocked  (int __c, FILE *__stream)    ;



 
extern int putc_unlocked  (int __c, FILE *__stream)    ;
extern int putchar_unlocked  (int __c)    ;




 
extern int getw  (FILE *__stream)    ;

 
extern int putw  (int __w, FILE *__stream)    ;



 
extern char *fgets  (char *   __s, int __n,
			 FILE *   __stream)    ;







 

extern char *gets  (char *__s)    ;


# 420 "/usr/include/stdio.h" 3



 
extern int fputs  (__const char *   __s,
		       FILE *   __stream)    ;







 
extern int puts  (__const char *__s)    ;


 
extern int ungetc  (int __c, FILE *__stream)    ;


 
extern size_t fread  (void *   __ptr, size_t __size,
			  size_t __n, FILE *   __stream)    ;
 
extern size_t fwrite  (__const void *   __ptr, size_t __size,
			   size_t __n, FILE *   __s)    ;


 
extern size_t fread_unlocked  (void *   __ptr, size_t __size,
				   size_t __n, FILE *   __stream)    ;
extern size_t fwrite_unlocked  (__const void *   __ptr,
				    size_t __size, size_t __n,
				    FILE *   __stream)    ;



 
extern int fseek  (FILE *__stream, long int __off, int __whence)    ;
 
extern long int ftell  (FILE *__stream)    ;
 
extern void rewind  (FILE *__stream)    ;

 




 


typedef __off_t off_t;




















 
extern int fgetpos  (FILE *   __stream,
			 fpos_t *   __pos)    ;
 
extern int fsetpos  (FILE *__stream, __const fpos_t *__pos)    ;
# 519 "/usr/include/stdio.h" 3


# 529 "/usr/include/stdio.h" 3


 
extern void clearerr  (FILE *__stream)    ;
 
extern int feof  (FILE *__stream)    ;
 
extern int ferror  (FILE *__stream)    ;


 
extern void clearerr_unlocked  (FILE *__stream)    ;
extern int feof_unlocked  (FILE *__stream)    ;
extern int ferror_unlocked  (FILE *__stream)    ;



 
extern void perror  (__const char *__s)    ;

 


extern int sys_nerr;
extern __const char *__const sys_errlist[];








 
extern int fileno  (FILE *__stream)    ;



 
extern int fileno_unlocked  (FILE *__stream)    ;





 
extern FILE *popen  (__const char *__command, __const char *__modes)    ;

 
extern int pclose  (FILE *__stream)    ;




 
extern char *ctermid  (char *__s)    ;









# 603 "/usr/include/stdio.h" 3




 

 
extern void flockfile  (FILE *__stream)    ;

 

extern int ftrylockfile  (FILE *__stream)    ;

 
extern void funlockfile  (FILE *__stream)    ;










 





 




# 21 "hoc.y" 2

# 1 "/usr/include/ctype.h" 1 3
 

















 









 


 







# 1 "/usr/include/endian.h" 1 3
 






















 









 
# 1 "/usr/include/bits/endian.h" 1 3
 






# 35 "/usr/include/endian.h" 2 3


 













# 40 "/usr/include/ctype.h" 2 3







enum
{
  _ISupper = (( 0 ) < 8 ? ((1 << ( 0 )) << 8) : ((1 << ( 0 )) >> 8)) ,	 
  _ISlower = (( 1 ) < 8 ? ((1 << ( 1 )) << 8) : ((1 << ( 1 )) >> 8)) ,	 
  _ISalpha = (( 2 ) < 8 ? ((1 << ( 2 )) << 8) : ((1 << ( 2 )) >> 8)) ,	 
  _ISdigit = (( 3 ) < 8 ? ((1 << ( 3 )) << 8) : ((1 << ( 3 )) >> 8)) ,	 
  _ISxdigit = (( 4 ) < 8 ? ((1 << ( 4 )) << 8) : ((1 << ( 4 )) >> 8)) ,	 
  _ISspace = (( 5 ) < 8 ? ((1 << ( 5 )) << 8) : ((1 << ( 5 )) >> 8)) ,	 
  _ISprint = (( 6 ) < 8 ? ((1 << ( 6 )) << 8) : ((1 << ( 6 )) >> 8)) ,	 
  _ISgraph = (( 7 ) < 8 ? ((1 << ( 7 )) << 8) : ((1 << ( 7 )) >> 8)) ,	 
  _ISblank = (( 8 ) < 8 ? ((1 << ( 8 )) << 8) : ((1 << ( 8 )) >> 8)) ,	 
  _IScntrl = (( 9 ) < 8 ? ((1 << ( 9 )) << 8) : ((1 << ( 9 )) >> 8)) ,	 
  _ISpunct = (( 10 ) < 8 ? ((1 << ( 10 )) << 8) : ((1 << ( 10 )) >> 8)) ,	 
  _ISalnum = (( 11 ) < 8 ? ((1 << ( 11 )) << 8) : ((1 << ( 11 )) >> 8)) 	 
};


 










extern __const unsigned short int *__ctype_b;	 
extern __const __int32_t *__ctype_tolower;  
extern __const __int32_t *__ctype_toupper;  









 



extern int  isalnum   (int)     ;
extern int  isalpha   (int)     ;
extern int  iscntrl   (int)     ;
extern int  isdigit   (int)     ;
extern int  islower   (int)     ;
extern int  isgraph   (int)     ;
extern int  isprint   (int)     ;
extern int  ispunct   (int)     ;
extern int  isspace   (int)     ;
extern int  isupper   (int)     ;
extern int  isxdigit   (int)     ;






 
extern int tolower  (int __c)    ;

 
extern int toupper  (int __c)    ;




 

extern int isascii  (int __c)    ;

 

extern int toascii  (int __c)    ;




 

extern int  _toupper   (int)     ;
extern int  _tolower   (int)     ;



















# 164 "/usr/include/ctype.h" 3


# 186 "/usr/include/ctype.h" 3













# 273 "/usr/include/ctype.h" 3


 


# 22 "hoc.y" 2

char *progname;			 
int  lineno=1;

main(int argc,char **argv)	 
{
   progname=argv[0];
   yyparse();
}

yylex()
{
   int c;

   while((c=getchar()) == ' ' || c == '\t')
      ;
   if(c == (-1) )
      return 0;
   if(c == '.' || (__ctype_b[(int) ( ( c ) )] & (unsigned short int)   _ISdigit )  )	 
   {
      ungetc(c,stdin);
      scanf("%lf",&yylval);
      return 257 ;
   }
   if(c == '\n')
      ++lineno;
   return c;
}

yyerror(char *s)
{
   warning(s,(char *)0);
}

warning(char *s, char *t)
{
   fprintf(stderr,"%s: %s",progname,s);
   if(t)
      fprintf(stderr," %s",t);
   fprintf(stderr," near line %d\n",lineno);
}

# 194 "y.tab.c"





int
yyparse()
{
    register int yym, yyn, yystate;
# 213 "y.tab.c"


    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
# 237 "y.tab.c"

    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= 247  && yycheck[yyn] == yychar)
    {





        if (yyssp >= yyss + 500   - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= 247  && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;



yynewerror:
    yyerror("syntax error");



yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += 256 ) >= 0 &&
                    yyn <= 247  && yycheck[yyn] == 256 )
            {





                if (yyssp >= yyss + 500   - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {





                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
# 321 "y.tab.c"

        yychar = (-1);
        goto yyloop;
    }
yyreduce:





    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 3:
# 9 "hoc.y"

{ printf("\t%.8g\n",yyvsp[-1]); }
break;
case 4:
# 11 "hoc.y"

{ yyval = yyvsp[0];  	}
break;
case 5:
# 12 "hoc.y"

{ yyval = yyvsp[-2] + yyvsp[0]; }
break;
case 6:
# 13 "hoc.y"

{ yyval = yyvsp[-2] - yyvsp[0]; }
break;
case 7:
# 14 "hoc.y"

{ yyval = yyvsp[-2] * yyvsp[0]; }
break;
case 8:
# 15 "hoc.y"

{ yyval = yyvsp[-2] / yyvsp[0]; }
break;
case 9:
# 16 "hoc.y"

{ yyval = yyvsp[-1];	}
break;
# 363 "y.tab.c"

    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {





        yystate = 1 ;
        *++yyssp = 1 ;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
# 391 "y.tab.c"

        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= 247  && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];





    if (yyssp >= yyss + 500   - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
