#include <REGX52.H>			  

#include "timer0.h"

sbit SG_PWM=P2^0;							//信号控制引脚						 红——VCC 棕——GND 黄——信号线
unsigned char count=0;					     //计次  赋初值为0
unsigned char PWM_count=0;                  //0--0度，2--45度，4--90度，6--135度，8--180度

void main()
{
  Timer0_Init();
  while(1)
  {
//	  	if(P1_0==0)PWM_count=0;	  //舵机转动0度
//	  	if(P1_1==0)PWM_count=1;else PWM_count=0;	  //舵机转动22.5度		只执行其中一句可避免干扰，也可执行多句 
//    	if(P1_2==0)PWM_count=2;	  //舵机转动45度
//	 	if(P1_3==0)PWM_count=3;	  //舵机转动67.5度			
//	 	if(P1_4==0)PWM_count=4;	  //舵机转动90度
//	  	if(P1_5==0)PWM_count=5;	  //舵机转动112.5度
//	 	if(P1_6==0)PWM_count=6;	  //舵机转动135度
//    	if(P1_7==0)PWM_count=7;	  //舵机转动157.5度
//   	if(P2_1==0)PWM_count=8;	  //舵机转动180度
		PWM_count=2;
   }
}

void Timer0() interrupt 1      //特别注意此处，0--外部中断0，1--定时器中断0，2--外部中断1，3--定时器中断1，4--串行口中断1
{
//	TR0=0;
	TL0 = 0x0C;		//设置定时初始值
	TH0 = 0xFE;		//设置定时初始值
  

	  if(count<=PWM_count)
	  {									
	   		SG_PWM=1;
	  }
	  else
	  {
	    	SG_PWM=0;
	  }
	  count++;						  //计次，每0.5毫秒加1
	  if(count>=40)
	  {
	    	count=0;
	  }
//	  TR0=1;
}
