/*esc-stuffing*/
/*soh:0x01,eot:0x04,stuffing:0x1b*/
#include <stdio.h>

main(int argc,char **argv)
{
	int buf[0xff+1];
	char stuffing=0x1b;
	int i,c;/*c should NOT be char !*/
	FILE *fin,*fout;
	
	
	if(argc!=3){
		fprintf(stderr,"esc-stuffing: Usage:esc-stuffing fin\n");
		exit(1);
	}

	fin=fopen(argv[1],"r");
	fout=fopen(argv[2],"w");
	while((c=fgetc(fin))!=EOF){
		switch(c){
			case 0x01 || 0x04 || stuffing :
				fputc(stuffing,fout);
				fputc(c,fout);
				break;
			default:
				fputc(c,fout);
		}
	}
	fclose(fin);
	fclose(fout);
}

