#include <avr/io.h>
#define F_CPU 8000000UL //Tell the processor about the oscillator
#include <avr/delay.h>

#define a 	0b00000001
#define b 	0b00000010
#define c 	0b00000100
#define d	0b00001000
#define e	0b00010000
#define f	0b00100000
#define g	0b01000000

						  //	sw2 sw1
#define two 	0b00000010// 	0	1
#define one		0b00000100//	1	0


int i = 0;
void cw (void);
void ccw(void);

unsigned char arr[8] = {a, b, c, d, d, e, f, a};


int main (void)
{
	DDRA = 0xff; //port a output
	DDRB = 0xff; //port b output
	DDRD = 0x00; // port d input
	PORTD = 0xff; //input pullup on port d
	while(1)
	{
		if ((PIND & one) == 0)
		{
			i = ((i > 7)? (0) : (i+1));
			cw();
		}
		else if ((PIND & two) == 0)
		{
			i = ((i < 0)? (7) : (i-1));
			ccw();
		}
	}
	return 0;
}

void cw(void)
{
	if(i > -1 && i < 4)
	{
		PORTB = 0x00;
		PORTA = arr[i];
		_delay_ms(200);
	}
	else if (i > 3 && i < 8)
	{
		PORTA = 0x00;
		PORTB = arr[i];
		_delay_ms(200);
	}
}

void ccw(void)
{
	if(i > -1 && i < 4)
	{
		PORTB = 0x00;
		PORTA = arr[i];
		_delay_ms(200);
	}
	else if (i > 3 && i < 8)
	{
		PORTA = 0x00;
		PORTB = arr[i];
		_delay_ms(200);
	}
}

/*
 	for (i = 0; i < 4 && (PIND & one) == 0; i++)
	{
		PORTB = 0x00;
		PORTA = arr1[i];
		_delay_ms(200);
	}
	for (j = 0; j < 4 && ((PIND & one) == 0);j++)
	{
		PORTA = 0x00;
		PORTB = arr2[j];
		_delay_ms(200);
	}
 */



