#include"main.h"

/**
*append_text_to_file-Appendstextattheendofafile.
*@filename:Apointertothenameofthefile.
*@text_content:Thestringtoaddtotheendofthefile.
*
*Return:IfthefunctionfailsorfilenameisNULL--1.
*Ifthefiledoesnotexisttheuserlackswritepermissions--1.
*Otherwise-1.
*/
intappend_text_to_file(constchar*filename,char*text_content)
{
into,w,len=0;

if(filename==NULL)
return(-1);

if(text_content!=NULL)
{
for(len=0;text_content[len];)
len++;
}

o=open(filename,O_WRONLY|O_APPEND);
w=write(o,text_content,len);

if(o==-1||w==-1)
return(-1);

close(o);

return(1);
}

