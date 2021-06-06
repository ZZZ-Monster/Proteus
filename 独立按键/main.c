#include <REGX52.H>
#include "delay.H" 

unsigned char shumaguan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


void main()
{
	unsigned char i=1;
	P2=0x3F;
	while(1)
	{
		if(P0_0==0)
		{
			delay(20);
			while(P0_0==0);
			delay(20);
			P2=shumaguan[i];
			i++;
			if(i>=10) i=0;
		}
	}
}