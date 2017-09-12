#define LINUS
#ifdef LINUS
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <unistd.h>
#else
       #include <io.h>
#endif
#include <stdio.h>

#define SIZE sizeof(xu)
#define M 100
typedef struct{
long num;
char name[10];
char xb[2];
int age;
float score;
}xu;


