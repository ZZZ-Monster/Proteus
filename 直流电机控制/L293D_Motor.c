#include <REGX52.H>
#include "delay.H" 

sbit IN1=P2^0;
sbit IN2=P2^1;
sbit EN1=P2^2;


unsigned char Compare,Counter;

//电机正转
void Positive_Motor()
{
	IN1=1;
	IN2=0;
	EN1=1;	
}


//电机反转
void Negative_Motor()
{
	IN1=0;
	IN2=1;
	EN1=1;	
}



//delay的PWM直流电机调速
void Delay_Motor()
{
	IN1=0;
	IN2=1;
	delay(25);
	IN2=0;
	delay(75);
	EN1=1;	
}



void Timer0Init(void)	//1毫秒@12.000MHz
{
	TMOD &= 0xF0;	//设置定时器模式
	TMOD |= 0x01;	//设置定时器模式
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	EA=1;
	ET0=1;
	IN1=0;
}



//定时器的PWM直流电机调速
void PWM_Motor(unsigned char i)
{
	 Compare=i;
}


void PWM_Timer0() interrupt 1
{
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	Counter++;
	if(Counter>=100)
		Counter=0;
	if(Counter<Compare)
	{
		IN1=0;
	}
	 else
	{
	 	IN1=1;
	}
}






