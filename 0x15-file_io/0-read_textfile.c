#include"main.h"
#include<stdlib.h>

/**
*read_textfile-ReadtextfileprinttoSTDOUT.
*@filename:textfilebeingread
*@letters:numberofletterstoberead
*Return:w-actualnumberofbytesreadandprinted
*0whenfunctionfailsorfilenameisNULL.
*/
ssize_tread_textfile(const char*filename,size_tletters)
{
char*buf;
ssize_tfd;
ssize_tw;
ssize_tt;

fd=open(filename,O_RDONLY);
if(fd==-1)
return(0);
buf=malloc(sizeof(char)*letters);
t=read(fd,buf,letters);
w=write(STDOUT_FILENO,buf,t);

free(buf);
close(fd);
return(w);
}
