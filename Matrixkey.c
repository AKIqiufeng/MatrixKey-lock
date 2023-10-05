#include <STC89C5xRC.H>
#include "Delay.h"

/**
  * @brief  矩阵键盘读取键码
  * @param  无
  * @retval 按下按键的键码，松手时返回，无按键按下返回0
  如果按住按键，程序会停留在此函数
  */
unsigned char Matrixkey()
{
	unsigned char Key_num=0;
	P1=0xFF;
	P13=0;
	if(P17==0) {Delay(20);while(P17==0);Delay(20);Key_num=1;}
	if(P16==0) {Delay(20);while(P16==0);Delay(20);Key_num=5;}
	if(P15==0) {Delay(20);while(P15==0);Delay(20);Key_num=9;}
	if(P14==0) {Delay(20);while(P14==0);Delay(20);Key_num=13;}
	P1=0xFF;
	P12=0;
	if(P17==0) {Delay(20);while(P17==0);Delay(20);Key_num=2;}
	if(P16==0) {Delay(20);while(P16==0);Delay(20);Key_num=6;}
	if(P15==0) {Delay(20);while(P15==0);Delay(20);Key_num=10;}
	if(P14==0) {Delay(20);while(P14==0);Delay(20);Key_num=14;}
	P1=0xFF;
	P11=0;
	if(P17==0) {Delay(20);while(P17==0);Delay(20);Key_num=3;}
	if(P16==0) {Delay(20);while(P16==0);Delay(20);Key_num=7;}
	if(P15==0) {Delay(20);while(P15==0);Delay(20);Key_num=11;}
	if(P14==0) {Delay(20);while(P14==0);Delay(20);Key_num=15;}
	P1=0xFF;
	P10=0;
	if(P17==0) {Delay(20);while(P17==0);Delay(20);Key_num=4;}
	if(P16==0) {Delay(20);while(P16==0);Delay(20);Key_num=8;}
	if(P15==0) {Delay(20);while(P15==0);Delay(20);Key_num=12;}
	if(P14==0) {Delay(20);while(P14==0);Delay(20);Key_num=16;}
	return Key_num;
}