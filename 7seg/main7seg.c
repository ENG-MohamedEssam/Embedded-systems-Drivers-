#include <avr/io.h>
#define F_CPU 8000000UL //Tell the processor about the oscillator
#include <avr/delay.h>

#define zero 	0b00111111
#define one 	0b00000110
#define two 	0b01011011
#define three	0b01001111
#define four	0b01100110
#define five 	0b01101101
#define six 	0b01111101
#define seven	0b00000111
#define eight	0b01111111
#define nine	0b01101111

int main (void)
{
	DDRD = 0xff;
	unsigned char Numbers[10]={zero, one, two, three, four, five, six, seven, eight, nine};

	while(1)
	{
		for(int i =0; i < 10; i++)
		{
			PORTD = Numbers[i];
			_delay_ms (500);
		}
	}
	return 0;
}
