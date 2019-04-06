#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

void main(void)
{
  DDRD = (1 << PD5);      // PD5 = LED1, OUTPUT

  while (1)
  {
    if (PIND & (1 << PD2))              // Solange Taster 2 gedrueckt ist, leuchte
    {
      PORTD = (1 << PD5);
      _delay_ms(200);
    }
    else if (PIND & (1 << PD3))
    {
      PORTD = 0;
      _delay_ms(200);
    }
    
      _delay_ms(200);
  }
}
