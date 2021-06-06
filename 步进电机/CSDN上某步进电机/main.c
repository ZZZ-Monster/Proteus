#include <regx52.h>
#define uchar unsigned char
#define uint unsigned int


uchar speed=0;
uchar code fan[] = {0x09,0x08,0x0c,0x04,0x06,0x02,0x03,0x01};
uchar code zheng[] = {0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};



void delay1ms(uint t){
	char i;
	while(t--){
	 	for(i=0;i<113;i++);
	}
}




void main()
{
	uchar i;

	while(1)
	{
		if (P1_0==0)
		{
			for(i=0;i<8;i++)
			{
				P2 = zheng[i];
				delay1ms(speed);	
			}
		}
	}
}
