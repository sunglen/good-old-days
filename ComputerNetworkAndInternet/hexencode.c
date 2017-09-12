/* hexencode.c: hex dump */
#include <stdio.h>

main(int argc, char **argv)
{
	int n;

	if(argc != 2){
		fprintf(stderr, "%s: usage: %s name_of_your_data\n", argv[0], argv[0]);
		exit(1);
	}
	
	printf("begin %s\n", argv[1]);

	while((n=fgetc(stdin))!=EOF)
		printf("%02x", n);

/*	printf("\nend %s\n", argv[1]); */
return 0;
}

