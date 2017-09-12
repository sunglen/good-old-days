/*crc: generate 16 bit CRC code. emulate the hardware.*/
#include <stdio.h>
int shift(void);
enum{
	MASK=0x01
};
char shift_register[16]={0x00};
int main(void)
{
	char input[8];
	char shift_out[3];
	char shift_in[3];
	int i,j;
	int buf;
	char last_out;
	char output[2];

	while((buf=getc(stdin)) != EOF){
		for(i=0;i<=7;i++){
			input[i]=buf & MASK;
			buf>>=1;
		}
		for(i=0;i<=7;i++){
			/*shiftout*/
			shift_out[0]=shift_register[3];
			shift_out[1]=shift_register[10];
			shift_out[2]=shift_register[15];
			shift();
			last_out=shift_out[2]^input[i];
			/*feedback*/
			shift_in[0]=last_out;
			shift_in[1]=last_out^shift_out[0];
			shift_in[2]=last_out^shift_out[1];
			/*shiftin*/
			shift_register[0]=shift_in[0];
			shift_register[4]=shift_in[1];
			shift_register[11]=shift_in[2];
		}

	}
	/*output CRC code*/
	for(i=7,j=0;i>=0;i--,j++){
		output[0]|=(shift_register[j]<<i);
		putc((shift_register[j]?'1':'0'),stderr);
	}
	for(i=7,j=0;i>=0;i--,j++){
		output[1]|=(shift_register[j+8]<<i);
		putc((shift_register[j+8]?'1':'0'),stderr);
	}
	for(i=0;i<=1;i++)
		putc(output[i],stdout);
	exit(0);
}

int shift(void)
{
	int i;
	for(i=15;i>=1;i--){
		shift_register[i]=shift_register[i-1];
	}
	return 0;
}
