#include "Preamble.h"
sclose(SOCKET *sp)
{
 int sd;
 sd=sp->sd;
 free(sp);
 return close(sd);
}
