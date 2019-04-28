#define F_CPU 16000000L
#define PAUSE 1000
#include <avr/io.h>
#include <util/delay.h>

void main (void)
{
  DDRD = (1 << PD5) | (1 << PD6); // Pin5 + Pin6 auf Output
  while (1)
  {
    PORTD = (1 << PD5);           // Schalte auf Pin 5 Strom
    _delay_ms(PAUSE);
    PORTD = (1 << PD6);           // Schalte auf Pin 6 Strom
    _delay_ms(PAUSE);
  }
}
