#include <REGX52.H>
void UART_SendByte(unsigned char Byte);
unsigned char Temp;

void UART_Init()
{
	SCON = 0x50;	//8位数据,可变波特率
	TMOD &= 0x0F;	//设置定时器模式
	TMOD |= 0x20;	//设置定时器模式
	TL1 = 0xC7;		//设置定时初始值
	TH1 = 0xFE;		//设置定时初始值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//定时器1开始计时
	ES=1;
	EA=1;
}

	


void main()
{
	UART_Init();
	while(1)
	{
		
	}
}




void UART_Routine() interrupt 4
{
	 if(RI==1)    //RI为接收中断标志位（当接收完毕会自动置1）
	 {		
		UART_SendByte(SBUF);	//从机收到后再发到SBUF里显示
		P2_0=~P2_0;		
		RI=0;     //响应中断后必须手动置0
	 }
}



void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}



