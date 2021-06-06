#include <REGX52.H>
#include "delay.H"

unsigned char shumaguan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

 
void main()
{
	signed char i;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			P2=shumaguan[i];
			if(i==9) 
			{
				i=-1;
			}
			delay(200);
		}

	}
}