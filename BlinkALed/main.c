/*
 * ATmega328P l�uft mit einer Frequenz von 16 Mhz
 *
 * Created: 30.11.2017 13:58:19
 * Author : st101396
 */ 

#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* LED A3 (PORTB01) als Ausgang setzen */
	DDRB = 0x02;
	/* Sensor Bandanfang und Bandende als Eingang definieren */
	DDRD = 0x00;
	PORTD = 0x0C;
	
    while (1) 
    {
		/* Abfrage ob der Sensor an PORTD3 auf HIGH geschaltet wird */
		if((PIND & 0x08) == 0)
		{
			PORTB = 0x02; // LED einschalten Mode 1
			_delay_ms(100); // 100 ms warten
			PORTB = 0x00; // LED ausschalten Mode 1
			_delay_ms(100); // 100 ms warten
		}
		else
		{
			PORTB = 0x02; // LED einschalten Mode 2
			_delay_ms(500); // 500 ms warten
			PORTB = 0x00; // LED ausschalten Mode 2
			_delay_ms(500); // 500 ms warten
		}
    }
}

