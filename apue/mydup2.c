int mydup2(int fd1, int fd2)
{
	int fd, i=0, fd_reg[fd2];

	close(fd2);
	while((fd=dup(fd1)) != fd2){
		if(fd==-1 || fd > fd2)
			return -1;
		fd_reg[i]=fd;	
		i++;
	}

	while(i){
		close(fd_reg[i-1]);
		i--;
	}

	return fd;
}
