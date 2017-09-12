forkexec(struct cmd *ptr)
{
    int i,pid;

    if(pid=fork())
    {
      if(backgnd==TRUE)
      printf("%d\n",pid);
      lastpid=pid;
    }
    else
    {
      if(ptr->infd==0&&backgnd==TRUE)
        ptr->infd=open("/dev/null",O_RDONLY);

      if(ptr->infd!=0)
      {
        close(0);
        dup(ptr->infd);
      }

      if(ptr->outfd!=1)
      {
        close(1);
        dup(ptr->outfd);
      }

      if(backgnd==FALSE)
      {
        signal(SIGINT,SIG_DFL);
        signal(SIGQUIT,SIG_DFL);
      }
      for(i=3;i<OPEN_MAX;++i)
        close(i);

      execvp(ptr->av[0],ptr->av);
      exit(1);
    }
}


