#include <avr/io.h>
#define F_CPU 8000000UL //Tell the processor about the oscillator
#include <avr/delay.h>

int main (void)
{
	DDRA = 0x00; //switch pin o/p
	DDRB = 0b10000000; // led pin i/p
	PORTA = 0b00001000; // for pull up res

	while(1)
	{
		if ((PINA & 0b00001000) == 0) //switch is pressed
		{
			PORTB ^= 0b10000000;
			_delay_ms(20);
		}
		else
		{
			PORTB = 0x00;
		}
	}

	return 0;
}
