//exercise 1-c-1: select sort.

void selsort(int *data, int size)
{
	int lowkey, lowindex;
	int i, j, tmp;
	
	for(i=0;i<size-1;i++){
		lowindex=i;
		lowkey=data[lowindex];
		for(j=i+1;j<size;j++)
			if(data[j]<lowkey){
				lowindex=j;
				lowkey=data[lowindex];
			}
		tmp=data[i];
		data[i]=lowkey;
		data[lowindex]=tmp;
	}
}

