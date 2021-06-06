#include <REGX52.H>
#include "L293D_Motor.H" 



void main()
{
	Timer0Init();
	while(1)
	{
		PWM_Motor(10);	 //Ô½Ð¡Ô½Âý
	}
}





