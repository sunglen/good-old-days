#include <stdio.h>

int main(void)
{
  int i,ipad[4];
  char buf[256];

  while(fgets(buf,sizeof(buf),stdin) != NULL){
	  sscanf(buf,"%d.%d.%d.%d",&ipad[0],&ipad[1],&ipad[2],&ipad[3]);
	  printf("关于IP地址：%d.%d.%d.%d:\n",
		 ipad[0],ipad[1],ipad[2],ipad[3]);

	  for(i=0;i<4;i++)
	    if((ipad[i] >= 255 || ipad[i] <= 0)){
		fprintf(stderr,"这是一个无效的IP地址.\n");
		break;
	    }
	
	  if((ipad[0] >= 0) && (ipad[0]<=127)){
	    printf("\tA类地址.\n");
	    if(ipad[1] == 0 && ipad[2] == 0 && ipad[3] == 0)
	      printf("\t标识一个网络.\n");
	    if(ipad[1] == 255 && ipad[2] == 255 & ipad[3] == 255)
	      printf("\t直接广播--在特定网络上广播.\n");
	    if(ipad[0] == 127)
	      printf("\t本地回环.\n");
	    if(ipad[0] == 0 && ipad[1] == 0 && ipad[2] == 0 && ipad[3] == 0)
	      printf("\t本机--起动时使用.\n");
	  }
	
	
	  if((ipad[0] >= 128) && (ipad[0] <= 191)){
	      printf("\tB类地址.\n");
	    if(ipad[2] == 0 && ipad[3] == 0)
	      printf("\t标识一个网络.\n");
	    if(ipad[2] == 255 & ipad[3] == 255)
	      printf("\t直接广播--在特定网络上广播.\n");
	  }
	    
	  if((ipad[0] >= 192 && ipad[0] <=223)){
	    printf("\tC类地址.\n");
	    if(ipad[3] == 0)
	      printf("\t标识一个网络.\n");
	    if(ipad[3] == 255)
	      printf("\t直接广播--在特定网络上广播.\n");
	    }
	
	
	  if((ipad[0] >= 224 && ipad[0] <= 239)){
	    printf("\tD类地址.\n");
	  }
	
	  if((ipad[0] >= 240 && ipad[0] <= 255)){
	    printf("\tE类地址.\n");
	    if(ipad[0] == 255 && 
	       ipad[1] == 255 && ipad[2] == 255 && ipad[3] == 255)
	      printf("\t有限广播--在本地网上广播.\n");
	  }
	  
  }
}
	
	
	
	
	
	
	
