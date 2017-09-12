#include <netinet/in.h>

typedef struct
{
    struct sockaddr_in sin;
    int sinlen;
    int bindflag;
    int sd;
}SOCKET;

SOCKET *sopen(void);
int sclose(SOCKET *);
int sserver(SOCKET *,int,int);
int sclient(SOCKET *,char *,int);


