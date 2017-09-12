filelength(int fd)
{
    struct stat sbuf;
    fstat(fd,&sbuf);
    return sbuf.st_size;
}
 
