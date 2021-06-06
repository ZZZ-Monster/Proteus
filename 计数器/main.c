//计数器只能链接P3_4和P3_5

#include <REGX52.H>


unsigned char shumaguan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int count;

void Init_counter()		//5000微秒@12.000MHz
{
	TMOD &= 0xF0;	//设置计数器模式
	TMOD |= 0x06;	//设置计数器模式   8位自动重载的计数器
	TL0 = 256-3;	//设置计数器始值   计数几次就减几
	TH0 = 256-3;	//设置计数器始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//计数器0开始计时
	EA =  1;
	ET0 = 1;
}




void main()
{
	Init_counter();
	P2=0x3F;
	while(1)
	{
		P2=shumaguan[count];
		if(count>=10) count=0;
	}
}


void Counter0() interrupt 1
{
	count++;
}






