#include <stdio.h>

void fatal(char *mess)
{
  fprintf(stderr,"Error: %s :-(\n",mess);
  exit(1);
}
