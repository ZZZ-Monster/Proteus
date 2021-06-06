#include <REGX52.H>
#include "delay.h"

#define GPIO_MOTOR P2


unsigned char code Clockwise[8]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09}; //顺时针A-AB-B-BC-C-CD-D-DA
unsigned char code Anticlockwise[8]={0x09,0x08,0x0c,0x04,0x06,0x02,0x03,0x01};  //逆时针转动顺序

//逆时针转动8拍
void  Motor()  
{ 
	unsigned char i;
	for(i=0;i<8;i++)
	{ 
		GPIO_MOTOR&=0xf0;  //低四位清零
		GPIO_MOTOR|=Anticlockwise[i];  //置位低四位的相应位
		Delay(2);	//改变参数可以调节转速	
		//如果要使步进电机停止转动，则使用GPIO_MOTOR&=0xf0; 
	}	                  
}



//逆时针转动180°
void  Anticlockwise180() 
{ 
	unsigned char i,j;
	for(j=0;j<79;j++)  //79这个数字与电机参数有关，需要在仿真实验中不断调整从而确定
	{
		for(i=0;i<8;i++)
		{ 
			GPIO_MOTOR&=0xf0;  //低四位清零
			GPIO_MOTOR|=Anticlockwise[i];  //置位低四位的相应位
			Delay(3);	//调节转速	
		}	   		
  }  
	GPIO_MOTOR&=0xf0;  //低四位清零,停止转动
}


//顺时针转动180°
void Clockwise180()  
{
	unsigned char i,j;
	for(j=0;j<79;j++)  //79这个数字与电机参数有关，需要在仿真实验中不断调整从而确定
	{
		for(i=0;i<8;i++)
		{ 
			GPIO_MOTOR&=0xf0;  //低四位清零
			GPIO_MOTOR|=Clockwise[i];  //置位低四位的相应位
			Delay(3);	//调节转速	
		}	   		
  }  
	GPIO_MOTOR&=0xf0;  //低四位清零,停止转动
}



/*有了步距角参数，我们就可以计算出要使步进电机转动180°，所需要的拍数。
每拍转动（5.625/64）°，在八拍工作方式下，一轮循环下来就转动了(5.625°/8)°，
要使电机转动180°就是要进行180/((5.625°/8))=256轮的8拍循环。256恰好是无符号8位数据所能容纳的数据数（0-255共256）。
这也是这个电机设计的巧妙之处。*/
//逆时针转动180°(适用于28BYJ48)
void  Anticlockwise_28BYJ48_180() 
{ 
	unsigned char i,j;
	for(j=0;j<255;j++)  //改成255
	{
		for(i=0;i<8;i++)
		{ 
			GPIO_MOTOR&=0xf0;  //低四位清零
			GPIO_MOTOR|=Anticlockwise[i];  //置位低四位的相应位
			Delay(3);	//调节转速	
		}	   		
    }  
	GPIO_MOTOR&=0xf0;  //低四位清零,停止转动
}


