#include <REGX52.H>
#include "delay.H"

unsigned char LED[]={0x01,0x02,0x04,0x08,0x10,0x020,0x040,0x80};
 
void main()
 {
 	unsigned char i,j;
 	while(1)
	{
		for(i=0;i<8;i++)
		{
			P2=LED[j];
			j++;
			if(j==8) j=0;
			delay(100);
		}
		 
	}
}