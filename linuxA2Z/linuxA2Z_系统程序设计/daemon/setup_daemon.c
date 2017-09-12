setup_daemon(void)
{
 int i;
 
 for(i=0;i<NOFILE;i++)close(i);

 switch(fork())
 {
 case -1:
   fatal("setup_daemon(),第一次fork()",NA_EXIT);
 default:
   exit(0);
 case 0:
   if(setsid()==-1)
     fatal("setup_daemon(),setsid()",NA_EXIT);
   switch(fork())
   {
   case -1:
     fatal("setup_daemon(),第二次fork()",NA_EXIT);
   default:
     exit(0);
   case 0:
     umask(0);
     return;
   }
 }
}

 
