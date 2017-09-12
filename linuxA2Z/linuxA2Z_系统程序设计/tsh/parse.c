#include "command.c"
#include "check.c"
#include "getname.c"

parse(void)
{
     int i;

     command(0);

     if(check("<"))
        getname(infile);

     for(i=1;i<PIPELINE;++i)
       if(check("|"))
         command(i);
       else
         break;

     if(check(">"))
     {
       if(check(">"))
       append=TRUE;

       getname(outfile);
     }

     if(check("&"))
       backgnd=TRUE;

     if(check("\n"))
       return(i);
     else
     {
     fprintf(stderr,"Command line syntax error\n");
     return(ERROR);
     }
}
