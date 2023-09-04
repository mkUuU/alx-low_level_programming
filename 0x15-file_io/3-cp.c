#include"main.h"
#include<stdio.h>
#include<stdlib.h>

char*create_buffer(char*file);
voidclose_file(intfd);

/**
*create_buffer-Allocates1024bytesforabuffer.
*@file:Thenameofthefilebufferisstoringcharsfor.
*
*Return:Apointertothenewly-allocatedbuffer.
*/
char*create_buffer(char*file)
{
char*buffer;

buffer=malloc(sizeof(char)*1024);

if(buffer==NULL)
{
dprintf(STDERR_FILENO,
"Error:Can'twriteto%s\n",file);
exit(99);
}

return(buffer);
}

/**
*close_file-Closesfiledescriptors.
*@fd:Thefiledescriptortobeclosed.
*/
voidclose_file(intfd)
{
intc;

c=close(fd);

if(c==-1)
{
dprintf(STDERR_FILENO,"Error:Can'tclosefd%d\n",fd);
exit(100);
}
}

/**
*main-Copiesthecontentsofafiletoanotherfile.
*@argc:Thenumberofargumentssuppliedtotheprogram.
*@argv:Anarrayofpointerstothearguments.
*
*Return:0onsuccess.
*
*Description:Iftheargumentcountisincorrect-exitcode97.
*Iffile_fromdoesnotexistorcannotberead-exitcode98.
*Iffile_tocannotbecreatedorwrittento-exitcode99.
*Iffile_toorfile_fromcannotbeclosed-exitcode100.
*/
intmain(intargc,char*argv[])
{
intfrom,to,r,w;
char*buffer;

if(argc!=3)
{
dprintf(STDERR_FILENO,"Usage:cpfile_fromfile_to\n");
exit(97);
}

buffer=create_buffer(argv[2]);
from=open(argv[1],O_RDONLY);
r=read(from,buffer,1024);
to=open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,0664);

do{
if(from==-1||r==-1)
{
dprintf(STDERR_FILENO,
"Error:Can'treadfromfile%s\n",argv[1]);
free(buffer);
exit(98);
}

w=write(to,buffer,r);
if(to==-1||w==-1)
{
dprintf(STDERR_FILENO,
"Error:Can'twriteto%s\n",argv[2]);
free(buffer);
exit(99);
}

r=read(from,buffer,1024);
to=open(argv[2],O_WRONLY|O_APPEND);

}while(r>0);

free(buffer);
close_file(from);
close_file(to);

return(0);
}

