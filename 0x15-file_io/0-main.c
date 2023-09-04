#include<stdio.h>
#include<stdlib.h>
#include"main.h"

/**
*main-checkthecode
*
*Return:Always0.
*/
intmain(intac,char**av)
{
ssize_tn;

if(ac!=2)
{
dprintf(2,"Usage:%sfilename\n",av[0]);
exit(1);
}
n=read_textfile(av[1],114);
printf("\n(printedchars:%li)\n",n);
n=read_textfile(av[1],1024);
printf("\n(printedchars:%li)\n",n);
return(0);
}
