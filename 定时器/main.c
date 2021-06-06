#include <REGX52.H>


unsigned char shumaguan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


void Timer0Init(void)		//5000微秒@12.000MHz
{
	TMOD &= 0xF0;	//设置定时器模式
	TMOD |= 0x01;	//设置定时器模式
	TL0 = 0xA0;		//设置定时初始值
	TH0 = 0x15;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	EA =  1;
	ET0 = 1;
}




void main()
{
	Timer0Init();
	P2=0x3F;
	while(1)
	{
		
	}
}


void Timer0() interrupt 1
{
	static unsigned int i,count;
	TL0 = 0xA0;		//设置定时初始值
	TH0 = 0x15;		//设置定时初始值
	count++;
	if(count>=10)
	{
		count=0;
		i++; 
		P2=shumaguan[i];
		if(i>=9) i=0;
		
	}	
}






