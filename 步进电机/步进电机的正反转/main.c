
#include <regx52.h> 
unsigned char code table1[]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09}; /*Õý×ª±í*/ 

void delay(int ms)		//@12.000MHz
{
	while(ms)
	{
	 	unsigned char i, j;
		i = 2;
		j = 239;
		do
			{
				while (--j);
			} 
			while (--i);
		ms--;
	}	
}


void main() 
{ 	
	unsigned int j;
	P2=0;
	while(1)
	{
		for(j=1;j<8;j++)
		{
			
			P2=table1[j];
			delay(1000);
		}
	} 
}