
jmp_buf env;
fatal(char *text,int next_action)
{
     FILE *fp;
     if((fp=fopen("ERROR.LOG","a"))==0)exit(1);
     fprintf(fp,"Error in %s\n",text);
     fclose(fp);
     
     if(next_action==NA_RESTART)
        longjmp(env,1);
     else
        exit(1);
}

