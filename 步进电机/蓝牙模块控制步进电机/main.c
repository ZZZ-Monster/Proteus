#include "regx52.h"
#include "delay.h"
#include "motor.h"
#include "UART.h"

unsigned char Flag;

//主函数
void main(void) 
{ 
	UART_Init();
 	while(1)
 	{
  		
  	}
}



void UART_Routine() interrupt 4
{
	 if(RI==1)    //RI为接收中断标志位（当接收完毕会自动置1）
	 {	
	 	Flag=SBUF;
		if(Flag==0x01)
		{
			Anticlockwise_28BYJ48_180();
		}
		if(Flag==0x02)
		{
			Clockwise_28BYJ48_180();
		}						
		RI=0;     //响应中断后必须手动置0
	 }
}

