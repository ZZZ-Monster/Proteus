#include <REGX52.H>
#include "lcd1602.H"


sbit STRAT=P3^0;
sbit EOC=P3^1;
sbit OE=P3^2;

unsigned char Data;

unsigned char ADC()
{
	STRAT=0;
	STRAT=1;
	delay(5);
	STRAT=0;
	while(EOC==0);//等待转换完成
	OE=1;
	Data=P2;
	OE=0;
	return Data;
}






