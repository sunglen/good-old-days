#include <stdio.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0
#define OKAY 1
#define ERROR 0
#define MAXLINE 200
#define MAXARG 20
#define PIPELINE 5
#define MAXNAME 100

char line[MAXLINE+1];
char *lineptr;
char avline[MAXLINE+1];
char *avptr;
char infile[MAXNAME+1];
char outfile[MAXNAME+1];

int backgnd;
int lastpid;
int append;

struct cmd
{
char *av[MAXARG];
int infd;
int outfd;
}cmdlin[PIPELINE];


