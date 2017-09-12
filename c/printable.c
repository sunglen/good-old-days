/* printable.c : print filename if it's printable.*/

#include <stdio.h>
#include <ctype.h>

int isprintable(FILE *);

main(int argc, char **argv)
{
	int i, choice=1;
	FILE *fp;

	if(argv[1][0]=='-'){
		switch(argv[1][1]){
		case 'v':
			choice=0;
			break;
		default:
			fprintf(stderr,"printable: Usage: printable [-v]\n");
			exit(1);
		}
		argc--;
		argv++;
	}
		
	for(i=1; i<argc; i++){
		if((fp=fopen(argv[i],"r"))==NULL){
			fprintf(stderr,"printable: cannot open %s\n",argv[i]);
		}else if(isprintable(fp)==choice){
			printf("%s\n",argv[i]);
			fclose(fp);
		}
	}
	exit(0);
}

int isprintable(FILE *fp)
{
	int c;
	
	while((c=getc(fp)) != EOF){
		if(isascii(c) &&
		  (isprint(c) || c=='\n' || c=='\t' || c==' ')){
		  	continue;
		}else{
			return 0;
		}
	}
	return 1;
}

