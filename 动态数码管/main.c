#include <REGX52.H>
#include "delay.H"

unsigned char shumaguan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char weishu[]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07};

void main()
{

	signed char i;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			P3=weishu[i];
			P2=shumaguan[i];
			delay(2);
		  }
		}
}