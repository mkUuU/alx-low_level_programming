#include"main.h"

/**
*create_file-Createsafile.
*@filename:Apointertothenameofthefiletocreate.
*@text_content:Apointertoastringtowritetothefile.
*
*Return:Ifthefunctionfails--1.
*Otherwise-1.
*/
intcreate_file(constchar*filename,char*text_content)
{
intfd,w,len=0;

if(filename==NULL)
return(-1);

if(text_content!=NULL)
{
for(len=0;text_content[len];)
len++;
}

fd=open(filename,O_CREAT|O_RDWR|O_TRUNC,0600);
w=write(fd,text_content,len);

if(fd==-1||w==-1)
return(-1);

close(fd);

return(1);
}

