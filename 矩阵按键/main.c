#include <REGX52.H>
#include "delay.H" 
unsigned char shumaguan[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};	//低电平亮
unsigned char key();
void Nixie();

unsigned char Temp;

void main()
{
	P3=0x00;
	while(1)
	{
		Temp=key();
		Nixie();

	}
}


//数码管显示
void Nixie()
{
	if(Temp/10==0)
	{
		P3_1=1;
		P2=shumaguan[Temp];
		P2=0xff;
	}
	else
	{
		P3_0= 1;
		P2=shumaguan[Temp/10];
		delay(5);
		P3_0= 0;
		P3_1= 1;
		P2=shumaguan[Temp%10];
		delay(5);
		P3_1= 0;

	}
}




//矩阵按键
unsigned char key()
{
	unsigned char NUM;
	P1=0XFF;
	P1_4=0;
	if(P1_0==0){delay(10);while(P1_0==0);delay(10);NUM=1;}
	if(P1_1==0){delay(10);while(P1_1==0);delay(10);NUM=5;}
	if(P1_2==0){delay(10);while(P1_2==0);delay(10);NUM=9;}
	if(P1_3==0){delay(10);while(P1_3==0);delay(10);NUM=13;}

	P1=0XFF;	
	P1_5=0;
	if(P1_0==0){delay(10);while(P1_0==0);delay(10);NUM=2;}
	if(P1_1==0){delay(10);while(P1_1==0);delay(10);NUM=6;}
	if(P1_2==0){delay(10);while(P1_2==0);delay(10);NUM=10;}
	if(P1_3==0){delay(10);while(P1_3==0);delay(10);NUM=14;}


	P1=0XFF;	
	P1_6=0;
	if(P1_0==0){delay(10);while(P1_0==0);delay(10);NUM=3;}
	if(P1_1==0){delay(10);while(P1_1==0);delay(10);NUM=7;}
	if(P1_2==0){delay(10);while(P1_2==0);delay(10);NUM=11;}
	if(P1_3==0){delay(10);while(P1_3==0);delay(10);NUM=15;}


	P1=0XFF;	
	P1_7=0;
	if(P1_0==0){delay(10);while(P1_0==0);delay(10);NUM=4;}
	if(P1_1==0){delay(10);while(P1_1==0);delay(10);NUM=8;}
	if(P1_2==0){delay(10);while(P1_2==0);delay(10);NUM=12;}
	if(P1_3==0){delay(10);while(P1_3==0);delay(10);NUM=16;}

	return NUM;

}

