/*exipad: 将点分十进制ip转换为32位2进制或相反。
execise for Computer Network and Internet*/

#include <stdio.h>
#include <math.h>

void dec2bin(int dec_num, int bits, char *result); 
void bin2dec(char *bin_num, int bits, int *result);

void dec2bin(int dec_num, int bits, char *result)
{
  float tmp=0.0;
  int i=0;
  char t;
  
  while(dec_num >0 && dec_num<pow(2,bits)){
//注意浮点数除法！
    tmp=(float)dec_num/2.0; 
    if(dec_num == 1){
      result[i]='1';
      i++;
      break;
    }else if(floor(tmp) == tmp){
      result[i]='0'; 
      i++;
    }else{
      result[i]='1';
      i++;
    }
    dec_num=floor(tmp);
  }
  
//用'0'填满8位
  for(i;i<=7;i++)
    result[i]='0';
//反转   
  for(i=0;i<4;i++){
	t=result[i];
    	result[i]=result[7-i];
    	result[7-i]=t;
    }
}


void bin2dec(char *bin_num, int n,int *result_dec)
{
  int i,t=0;
  for(i=7;i>=0;i--){
    t=t+(bin_num[i]-'0')*pow(2,(7-i));
  }
  *result_dec=t;
}

int main(void)
{
  char buf[256]={'\0'};
  //char result_bin[]={'0','0','0','0','0','0','0','0','\0'};
  char result_bin[9]={'0'};
  int result_dec[1]={0};
  int dec_num[4]={0};
  char newbuf[256]={'\0'};
  int i=0,j=0,t=0;

  if(fgets(buf,sizeof(buf),stdin) == NULL){
    fprintf(stderr,"The End!\n");
    exit(1);
  }
  
  for(i=0;i<strlen(buf);i++){
      if(buf[i] == '1' || buf[i] == '0'){
	newbuf[j]=buf[i];
	j++;
      }
  }
  if(j == 32){
    for(i=0;i<32;i=i+8){
      bin2dec(newbuf+i, 8, result_dec);
      if(t<3)
	printf("%d.",*result_dec);
      else
	printf("%d\n",*result_dec);
      t++;
    }
  }else{
    sscanf(buf,"%d.%d.%d.%d",&dec_num[0],&dec_num[1],&dec_num[2],&dec_num[3]);
    for(i=0;i<4;i++){
      dec2bin(dec_num[i], 8, result_bin);
      	printf("%s ",result_bin);
    }
    printf("\n");
  }
}
