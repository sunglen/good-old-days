/*zap: interactive process killer */

#include <stdio.h>
#include <signal.h>
char *progname; /* progname for error message. */
char *ps="ps -ax"; /* system dependent. */
int strindex(char *,char *); /* search location of string2 in string1 */
char ttyin(void); /* offer choice. */

main(int argc, char **argv)
{
	FILE *fin;
	char buf[BUFSIZ];
	int i=1,pid;

	progname=argv[0];
	if((fin=popen(ps,"r")) == NULL){
		fprintf(stderr,"%s: cannot run %s\n",progname,ps);
		exit(1);
	}
	while(fgets(buf,sizeof(buf),fin) != NULL){
		do{
			if(argc ==1 || strindex(buf,argv[i])>=0){
				buf[strlen(buf)-1]='\0';
				fprintf(stderr,"%s?",buf);
				if(ttyin()=='y'){
					sscanf(buf,"%d",&pid);
					kill(pid,SIGKILL);
				}
				break;
			}
			i++;
		}while(i<argc);
		i=1; /*在外围循环中内层计数器复位。*/
	}
	exit(0);
}

int strindex(char *s,char *t)
{
	int i=0,n=strlen(t);
	
	while(s[i] != '\0'){
		if(strncmp(s+i,t,n) == 0){
			return i;
		}
		i++;
	}
	return -1;
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


