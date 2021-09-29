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


						  //	sw1 sw2
#define s2		0b00000010// 	0	1
#define s1		0b00000100//	1	0
#define s3		0b00000001
int i = 0 , j = 0;


unsigned char Numbers[10]={zero, one, two, three, four, five, six, seven, eight, nine};

int main (void)
{
	DDRA = 0xff; //port a output
	DDRB = 0xff; //port b output
	DDRD = 0x00; // port d input
	PORTD = 0xff; //input pullup on port d
	PORTA = 0x00;
	PORTB = 0x00;
	while(1)
	{
		if ((PIND & s1) == 0 && (PIND & s2) != 0 )
		{
			i = ((i > 8) ? (0): (i+1));
			PORTA = Numbers[i];
			_delay_ms(200);
		}
		else if ((PIND & s2) == 0 && (PIND & s1) != 0)
		{
			j = ((j > 8) ? (0): (j+1));
			PORTB = Numbers[j];
			_delay_ms(200);
		}
		else if ((((PIND & s1) == 0 && (PIND & s2) == 0)) || ((PIND & s3) == 0))
		{
			i = ((i == 0 )? (9): (i-1));
			j =((i == 9)? (j-1): (j));
			PORTB = Numbers[j];
			PORTA = Numbers[i];
			_delay_ms(500);
		}
	}
	return 0;
}

