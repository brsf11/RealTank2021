#include"code_def.h"
#include"Buzzer.h"
#include<stdbool.h>

void LCD_init(void);
void LCD_set_cursor(uint16_t x,uint16_t y);
void LCD_fill(uint16_t x,uint16_t y);
void LCD_WriteRAM_Prepare(void);

int main()
{
	LCD_init();


    while(1);
    return 0;
}

void LCD_init()
{
	LCD_write(0xCF,0);  
	LCD_write(0x00,1); 
	LCD_write(0xC1,1); 
	LCD_write(0X30,1); 
	LCD_write(0xED,0);  
	LCD_write(0x64,1); 
	LCD_write(0x03,1); 
	LCD_write(0X12,1); 
	LCD_write(0X81,1); 
	LCD_write(0xE8,0);  
	LCD_write(0x85,1); 
	LCD_write(0x10,1); 
	LCD_write(0x7A,1); 
	LCD_write(0xCB,0);  
	LCD_write(0x39,1); 
	LCD_write(0x2C,1); 
	LCD_write(0x00,1); 
	LCD_write(0x34,1); 
	LCD_write(0x02,1); 
	LCD_write(0xF7,0);  
	LCD_write(0x20,1); 
	LCD_write(0xEA,0);  
	LCD_write(0x00,1); 
	LCD_write(0x00,1); 
	LCD_write(0xC0,0);    //Power control 
	LCD_write(0x1B,1);   //VRH[5:0] 
	LCD_write(0xC1,0);    //Power control 
	LCD_write(0x01,1);   //SAP[2:0];BT[3:0] 
	LCD_write(0xC5,0);    //VCM control 
	LCD_write(0x30,1); 	 //3F
	LCD_write(0x30,1); 	 //3C
	LCD_write(0xC7,0);    //VCM control2 
	LCD_write(0XB7,1); 
	LCD_write(0x36,0);    // Memory Access Control 
	LCD_write(0x48,1); 
	LCD_write(0x3A,0);   
	LCD_write(0x55,1); 
	LCD_write(0xB1,0);   
	LCD_write(0x00,1);   
	LCD_write(0x1A,1); 
	LCD_write(0xB6,0);    // Display Function Control 
	LCD_write(0x0A,1); 
	LCD_write(0xA2,1); 
	LCD_write(0xF2,0);    // 3Gamma Function Disable 
	LCD_write(0x00,1); 
	LCD_write(0x26,0);    //Gamma curve selected 
	LCD_write(0x01,1); 
	LCD_write(0xE0,0);    //Set Gamma 
	LCD_write(0x0F,1); 
	LCD_write(0x2A,1); 
	LCD_write(0x28,1); 
	LCD_write(0x08,1); 
	LCD_write(0x0E,1); 
	LCD_write(0x08,1); 
	LCD_write(0x54,1); 
	LCD_write(0XA9,1); 
	LCD_write(0x43,1); 
	LCD_write(0x0A,1); 
	LCD_write(0x0F,1); 
	LCD_write(0x00,1); 
	LCD_write(0x00,1); 
	LCD_write(0x00,1); 
	LCD_write(0x00,1); 		 
	LCD_write(0XE1,0);    //Set Gamma 
	LCD_write(0x00,1); 
	LCD_write(0x15,1); 
	LCD_write(0x17,1); 
	LCD_write(0x07,1); 
	LCD_write(0x11,1); 
	LCD_write(0x06,1); 
	LCD_write(0x2B,1); 
	LCD_write(0x56,1); 
	LCD_write(0x3C,1); 
	LCD_write(0x05,1); 
	LCD_write(0x10,1); 
	LCD_write(0x0F,1); 
	LCD_write(0x3F,1); 
	LCD_write(0x3F,1); 
	LCD_write(0x0F,1); 
	LCD_write(0x2B,0); 
	LCD_write(0x00,1);
	LCD_write(0x00,1);
	LCD_write(0x01,1);
	LCD_write(0x3f,1);
	LCD_write(0x2A,0); 
	LCD_write(0x00,1);
	LCD_write(0x00,1);
	LCD_write(0x00,1);
	LCD_write(0xef,1);	 
	LCD_write(0x11,0); //Exit Sleep
	Delay(6000000);
	LCD_write(0x29,0); //display on
}

void LCD_set_cursor(uint16_t x,uint16_t y)
{
	LCD_write(0x2A,0); 
	LCD_write(x >> 8,1);
    LCD_write(x & 0XFF,1); 			 
	LCD_write(0x2B,0); 
	LCD_write(y >> 8,1);
    LCD_write(y & 0XFF,1); 
}

void LCD_fill(uint16_t x,uint16_t y)
{
	uint16_t i,j;
	xlen=20;	 
	for(i=y;i<=y+20;i++)
	{
	 	LCD_set_cursor(x,i);      				
		LCD_WriteRAM_Prepare();     				  
		for(j=0;j<xlen;j++)LCD_WRITE(0X0000,1);		    
	}
}

void LCD_WriteRAM_Prepare(void)
{
	LCD_write(0x2C,0);
}

void KEY()
{

}
