#include <netinet/in.h>

#define S_DELAY 0
#define S_NDELAY 1

#ifdef S_LIBRARY
#   define S_RESET 0
#   define S_SET 1
#   define S_NAMLEN 64
#endif

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


