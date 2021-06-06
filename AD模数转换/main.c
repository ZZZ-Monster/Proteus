#include <REGX52.H>
#include "lcd1602.H" 
#include "ADC0808.H" 


void main()
{
	LCD_Init();
 	while(1)
	{
		Display();		
	}
}