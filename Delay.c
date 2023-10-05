#include <intrins.h>

/**
  * @brief  延时函数
  * @param  延时时间，单位毫秒
  * @retval 无
  */
void Delay(unsigned int x)		//@11.0592MHz xms
{
	unsigned char i, j;
	while(x--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
  }
}