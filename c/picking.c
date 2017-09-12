/* pick: offer choice on each argument or on stdin data. */

#include <stdio.h>
void pick(char *); /*offer choice */
char ttyin(void); /* process ttyin from /dev/tty ver.1 */

char *progname; /* progname for error messages. */

main(int argc, char **argv)
{
	int i;
	char buf[BUFSIZ];
		
	progname=argv[0];
	if(argc==2 && strcmp(argv[1],"-")==0){
		while(fgets(buf,sizeof(buf),stdin) != NULL){
			buf[strlen(buf)-1]='\0';
			pick(buf);
		}
	}else{
		for(i=1;i<argc;i++){
			pick(argv[i]);
		}
	}
	exit(0);
}

void pick(char *s)
{
	fprintf(stderr,"%s?",s);
	if(ttyin()=='y'){
		printf("%s\n",s);
	}
}

	
char ttyin()
{
	FILE *tty;
	char buf[BUFSIZ];

	if((tty=fopen("/dev/tty","r")) == NULL){
		fprintf(stderr,"%s: cannot open /dev/tty.\n",progname);
		exit(1);
	}
	if(fgets(buf,sizeof(buf),tty) == NULL || buf[0] == 'q'){
		exit(0);
	}
	return buf[0];
}


