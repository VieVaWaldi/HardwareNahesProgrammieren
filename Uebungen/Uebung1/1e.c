#define F_CPU 8000000L

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
      _delay_ms(0.1);
      PORTD = (1 << PD5);
      _delay_ms(0.1);
    }

    while (PIND & (1 << PD3))
    {
      PORTD = (1 << PD7) | (1 << PD5);
      _delay_ms(0.5);
      PORTD = (1 << PD5);
      _delay_ms(0.5);
    }

    while (PIND & (1 << PD4))
    {
      PORTD = (1 << PD7) | (1 << PD5);
      _delay_ms(10);
      PORTD = (1 << PD5);
      _delay_ms(10);
    }

    PORTD = 0;
    _delay_ms(2);
  }
}
