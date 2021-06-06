
#ifndef __L293D_Motor_H__
#define __L293D_Motor_H__

void Positive_Motor(); //电机正转

void Negative_Motor();//电机反转

void Delay_Motor();	//delay的PWM直流电机调速

void Timer0Init(void);

void PWM_Motor(unsigned char i);

#endif