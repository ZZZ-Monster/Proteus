#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
#define OUT P2

sbit pos = P1^0;						//定义检测正转位P1^0
sbit neg = P1^1;						//反转     
	
//void delay(uint);

uint TIME;

uchar code turn[] = {0x02,0x06,0x04,0x0c,0x08,0x09,0x01,0x03};			//步进电机脉冲组

void main()
{
	uchar a;
  	OUT = 0x03;
	TMOD = 0x01;	      //定时器T0为方式1
	TH0 = 0x3c;		      //设置定时器初值15536（D）
	TL0 = 0xb0;		  
	EA = 1;			        //开总中断															  
	ET0 = 1;		        //开定时器TO中断
	TR0 = 1;		        //启动定时器T0

/*
	定时器时间=（65536-15536）*12/12=5000us=5ms    
	电机转速计算n=60000/(10*8)=750 r/min
*/
	
	while(1)
	{
		if (pos&&neg) TIME=0;			
		if (!pos)               //如果正转按键按下
		{
			if (TIME==2)
			{
							
				a = a<8?a+1:0;
				OUT = turn[a];
				TIME = 0;
			}
		}
				
		if (!neg)								//反转按键按下
		{
			if (TIME==2)
			{
							
				a = a>0?a-1:7;
				OUT = turn[a];
				TIME = 0;
			}
				
		}
			
/*		a = a<8?a+1:0;
		  OUT = turn[a];
	    delay(20);
*/			
   }		   			
}

/*
void delay(uint j)
{
	uchar i;
	for(;j>0;j--)
	{
		i=250;
		while(--i);
		i=249;
		while(--i);
	}  
}
*/

void timer()interrupt 1	 //T0中断程序
{
   TH0=0x3c;				 //重新赋值--循环一次时间为5ms
   TL0=0xb0;
   TIME++;					 //循环次数加一
}

