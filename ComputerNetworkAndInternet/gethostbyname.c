#include <netdb.h>
#include <sys/socket.h>
#include <stdio.h>
extern int h_errno;

struct hostent *host;

main(int argc, char **argv)
{
	if(argc != 2){
		fprintf(stderr, "%s: usage: %s hostname\n", argv[0], argv[0]);
		exit(1);
	}
	
	if((host=gethostbyname(argv[1]))==NULL)
		herror(argv[0]);
	else{
		
		printf("the ipad of %s is %d.%d.%d.%d\n", host->h_name, 
		(int)host->h_addr_list[0][0]>=0 ? (int)host->h_addr_list[0][0] : 256+(int)host->h_addr_list[0][0],
		(int)host->h_addr_list[0][1]>=0 ? (int)host->h_addr_list[0][1] : 256+(int)host->h_addr_list[0][1],
		(int)host->h_addr_list[0][2]>=0 ? (int)host->h_addr_list[0][2] : 256+(int)host->h_addr_list[0][2],
		(int)host->h_addr_list[0][3]>=0 ? (int)host->h_addr_list[0][3] : 256+(int)host->h_addr_list[0][3]);
	}

return 0;
}

