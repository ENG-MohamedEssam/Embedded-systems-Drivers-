#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "LCD_interface.h"

int main(void)
{
	DIO_u8Init();
	LCD_voidInit();

	LCD_voidWriteChar(' ');

	while(1)
	{
	}
	return 0;
}
