/*bytestuffing: adaptive bytestuffing*/
/*soh:0x01,eot:0x04,auto choose stuffing*/
#include <stdio.h>

main(int argc,char **argv)
{
	int buf[0xff+1]={0};
	int stuffing;
	int i,c,min;
	FILE *fin,*fout;
	
	
	if(argc!=3){
		fprintf(stderr,"bytestuffing: Usage:bytestuffing fin fout\n");
		exit(1);
	}

	fin=fopen(argv[1],"r");
	while((c=fgetc(fin))!=EOF){
		buf[(int)c]++;
	}
	fseek(fin, 0L, SEEK_SET);
	min=buf[0];
	stuffing=0x00;
	for(i=0x00;i<=0xff;i++){
		if(buf[i]<=min){
			stuffing=i;
			min=buf[i];
		}
	}
	putc(stuffing,stdout);
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

