#include <STC89C5xRC.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Matrixkey.h"

char Password[]="7355608";//设定密码，更改数字即可，7位

//密码验证函数，按下确认后开始验证
void verify(unsigned char input[7])
{
	int v=1,x=0;
	for(x;x<7;x++)
	if(input[x]!= Password[x]) v=0;//逐位比对密码，如果有不同，判断为否，验证不通过
	if (v==0)//当验证不通过，显示错误提示一秒，回到输入状态
	{
		LCD_ShowString(2,1,"ERROR! ");
		Delay(1000);
	}
	else LCD_ShowString(2,10,"Correct");//验证通过，密码后显示正确提示（后续可加入正确后的执行函数）
}

//输入函数，处理单个输入，以及功能键
void key_input(unsigned char key_num,int *i,unsigned char input[7])//c语言数组名作形参实际传入的为数组首地址，会改变原数组
{
	int x=0;
	if (key_num <= 10)//小于10正常输入密码（10为0）
		if (*i<7)
		{
			input[*i]=(unsigned char)(key_num%10+48);
			++*i;
		}
	if (key_num == 11)//11为退格键
	{
		if (*i>0)
		{
			input[*i-1]='_';
			--*i;
		}
	}
	if (key_num == 12)//12为清零键
	{
		LCD_ShowString(2,10,"       ");//消除correct的显示
		for(x;x<7;x++)//重置用于储存输入的字符数组
			input[x]='_';
		*i=0;
	}
	if (key_num == 16)//16为确认键
		verify(input);//验证密码
}

void main()
{
	int count = 0;//定义计数器用于统计已输入密码的位数
	unsigned char key_num;
	unsigned char input[]="_______";
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	LCD_ShowString(2,1,input);//刷新默认显示
	while(1)
	{
		key_num = Matrixkey();//读取按键输入
		if (key_num != 0)//按键松开则为输入
		{
			key_input(key_num,&count,input);//输入密码
			LCD_ShowString(2,1,input);//刷新显示
		}
	}
}