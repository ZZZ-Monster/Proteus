#include <REGX52.H>
#include "delay.H" 

unsigned char code Clockwise[8]={0x04,0x0c,0x08,0x09,0x01,0x03,0x02,0x06}; //逆时针转动顺序
unsigned char code Anticlockwise[8]={0x06,0x02,0x03,0x01,0x09,0x08,0x0c,0x04};  //  顺时针A-AB-B-BC-C-CD-D-DA

void Step_Motor()
{

	int i=0;
	for(i=0;i<8;i++)
	{
		P2=Anticlockwise[i];
		delay(500);
	}	
}

void main()
{

	while(1)
	{
		 Step_Motor();
	}
}






