#include"Driver/code_def.h"
#include"Driver/Buzzer.h"
#include"Driver/LCD.h"
#include"Driver/Timer.h"
#include"Driver/UART.h"

#include"GameSDK/Game.h"
#include"RealTank.h"

uint32_t uart_flag;
uint16_t y,ny;
uint16_t x,nx;

int main()
{
    NVIC_CTRL_ADDR = 0x0;
	Delay(6000000);
	LCD_init();
	Delay(1000000);
    GameInit();

    UART_Init();

    int i,j;
    
    for(i=0;i<12;i++)
    {
        for(j=0;j<16;j++)
        {
            Draw_pic(black,i*20,j*20,20);
        }
    }

    NVIC_CTRL_ADDR = 0x7;

    uart_flag = 0;
    
    y = 0;
    x = 0;
    nx = 0;
    ny = 0;
    while(1)
    {
        Draw_pic(box,nx,ny,20);
        while(!uart_flag);
        Draw_pic(black,x,y,20);
        x = nx;
        y = ny;
        uart_flag = 0;
    }

    
		
    return 0;
}



void KEY()
{
    uart_flag = 1;
    uint32_t temp = KeyboardReg;
    if(temp&(1))
    {
        nx = x + 20;
    }
    else if(temp&(1<<1))
    {
        ny = y + 20;
    }
    else if(temp&(1<<2))
    {
        nx = x - 20;
    }else if(temp&(1<<5))
    {
        ny = y - 20;
    }
}

void Timer_IRQ()
{

}

void UARTRX_IRQ()
{
    UART->INTSTATUSnCLEAR = 2;
    uart_flag = 1;
    char ch = UART_getc();

    if(ch == 'a')
    {
        nx = x - 20;
    }
    else if(ch == 'w')
    {
        ny = y - 20;
    }
    else if(ch == 's')
    {
        ny = y + 20;
    }else if(ch == 'd')
    {
        nx = x + 20;
    }
}
