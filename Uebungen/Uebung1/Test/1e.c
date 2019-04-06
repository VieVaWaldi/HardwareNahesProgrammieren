#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>

void main (void)
{
  DDRD = (1 << PD7) | (1 << PD5);

  while (1)
  {
    while (PIND & (1 << PD2))
    {
      PORTD = (1 << PD7) | (1 << PD5);
      _delay_ms(1000);
      PORTD = (1 << PD5);
      _delay_ms(1000);
    }

    while (PIND & (1 << PD3))
    {
      PORTD = (1 << PD7) | (1 << PD5);
      _delay_ms(500);
      PORTD = (1 << PD5);
      _delay_ms(500);
    }

    while (PIND & (1 << PD4))
    {
      PORTD = (1 << PD7) | (1 << PD5);
      _delay_ms(100);
      PORTD = (1 << PD5);
      _delay_ms(100);
    }

    PORTD = 0;
    _delay_ms(20);
  }
}
