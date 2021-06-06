#include <REGX52.H>

unsigned char shumaguan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

unsigned char i;

void Init_INTO()
{
	EA=1;
	EX0=1;
	IT0=1;
}




void main()
{
	Init_INTO();
	while(1)
	{
		P2=shumaguan[i];
	}
}


void Int0() interrupt 0
{
	i++;
	if(i>=10) i=0;
}

