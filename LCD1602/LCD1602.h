
#ifndef __LCD1602_H__
#define __LCD1602_H__
void delay(int ms);
void LCD_Init();
void WriteCommand(unsigned char Command);
void WriteData(unsigned char Data);
void Display();

#endif