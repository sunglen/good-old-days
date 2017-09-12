#include <netinet/in.h>


typedef struct
{
    struct sockaddr_in sin;
    int sinlen;
    int bindflag;
    int sd;
}SOCKET;




sclose(SOCKET *sp)
{
 int sd;
 sd=sp->sd;
 free(sp);
 return close(sd);
}
