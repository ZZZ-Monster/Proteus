#include <REGX52.H>
#include "LCD1602.H" 


void main()
{
	LCD_Init();
	Timer0Init();
	while(1)
	{
		Display();
	}
}