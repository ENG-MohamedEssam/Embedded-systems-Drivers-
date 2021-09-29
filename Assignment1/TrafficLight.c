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

unsigned char Numbers[10]={zero, one, two, three, four, five, six, seven, eight, nine};
void countDown(int time);

int main (void)
{
	DDRC = 0b00000111;
	DDRA = 0xff;
	DDRB = 0xff;
	while (1)
	{
		PORTC = 0b00000001;
		countDown(10);
		PORTC = 0b00000010;
		countDown(3);
		PORTC = 0b00000100;
		countDown(10);
	}
	return 0;
}

void countDown(int time)
{
	switch(time)
	{
		case 10:
			PORTB = one;
			PORTA = zero;
			_delay_ms(1000);
			PORTB= zero;
			for (int i = 0; i < 10; i++)
			{
				PORTA = Numbers[9-i];
				_delay_ms(1000);
			}
			break;
		case 3:
			for (int i = 3; i >= 0; i--)
			{
				PORTA = Numbers[i];
				_delay_ms(1000);
			}
			break;
	}
}

