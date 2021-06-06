#include <REGX52.H>

sbit RS=P3^0;
sbit RW=P3^1;
sbit E=P3^2;

unsigned int Sec=0,Min=52,Hour=22;
unsigned int NUM;


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




//写指令函数
void WriteCommand(unsigned char Command)
{
	RS=0;
	RW=0;
	E=0;
	P2=Command;
	delay(5);	  //延时一下，不然显示不出来
	E=1;
	E=0;
}

//写数据函数
void WriteData(unsigned char Data)
{
	RS=1;
	RW=0;
	E=0;
	P2=Data;
	delay(5);   //延时一下，不然显示不出来
	E=1;
	E=0;
}

//初始化
void LCD_Init()
{
	WriteCommand(0x38);
	WriteCommand(0x0c);
	WriteCommand(0x06);
	WriteCommand(0x01);
}

//初始化定时器
void Timer0Init(void)		//1毫秒@12.000MHz
{
	TMOD &= 0xF0;	//设置定时器模式
	TMOD |= 0x01;	//设置定时器模式
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TR0 = 1;		//定时器0开始计时
	EA=1;
	ET0=1;
}




//写数据，显示
void Display()
{
	WriteCommand(0x80);		   //第一行
	WriteData(Hour/10+'0');
	WriteData(Hour%10+'0');		 //数字加上‘0’就能变成十六进制数据
    WriteData(':');
	WriteData(Min/10+'0');
	WriteData(Min%10+'0');
    WriteData(':');
	WriteData(Sec/10+'0');
	WriteData(Sec%10+'0');
}



void Timer0() interrupt 1
{

	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	NUM++;

	if(NUM>=1000)
	{		   
		NUM=0;
		Sec++;
	}

	if(Sec>=60)
	{
		Sec=0;
		Min++;
	}
	if(Min>=60)
	{
		Min=0;
		Hour++;
	}
	if(Hour>=24)
	{
		Hour=0;
	}
				
		
	
}

















