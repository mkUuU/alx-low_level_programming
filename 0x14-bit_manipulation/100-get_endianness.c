#include"main.h"

/**
*get_endianness-checksifamachineislittleorbigendian
*Return:0forbig,1forlittle
*/
int get_endianness(void)
{
unsigned int i=1;
char *c=(char*) &i;

return(*c);
}
