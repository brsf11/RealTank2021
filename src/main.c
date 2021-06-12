#include"code_def.h"
#include"Buzzer.h"
#include"LCD.h"

#include"Game.h"


int main()
{
	Delay(6000000);
	LCD_init();
	Delay(1000000);
    GameInit();

    Draw_pic(box,100,100,20);
    Draw_pic(box,200,100,20);
    Draw_pic(wall,100,200,20);

	while(1);
		
    return 0;
}



void KEY()
{

}
