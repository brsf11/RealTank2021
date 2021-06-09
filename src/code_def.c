#include"code_def.h"

void Delay(int interval)
{
    int i = 0;
    while(1) 
		{
			i = i + 1;
			if(i == interval) break;
		}
}

void LCD_write(uint16_t data,uint32_t isData)
{
    uint32_t temp = uint32_t(data);
    if(isData)
    {
        PTFIFO = temp | 0x00010000;
    }
    else
    {
        PTFIFO = temp;
    }
}