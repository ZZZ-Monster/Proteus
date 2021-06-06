#include "regx52.h"
#include "delay.h"
#include "motor.h"

//主函数
void main(void) 
{ 

  	while(1)
 	{
		if(P1_0==0)			  //光线亮度充足就输出 0
		{
			Anticlockwise_28BYJ48_180();    	
		}
				
		else if(P1_0==1)	 //光线亮度达不到就输出	1
		{
			clockwise_28BYJ48_180();
			
		}
	
					
  	}
}
