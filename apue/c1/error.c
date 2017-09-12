#include <errno.h>
#include "ourhdr.h"

int 
main(int argc, char **argv)
{
	fprintf(stderr, "EFBIG: %s\n", strerror(EALREADY));
	errno=EFBIG;
	errno=EALREADY;
	perror(argv[0]);
	exit(0);
}

