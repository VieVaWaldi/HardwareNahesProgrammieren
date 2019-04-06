#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

void main (void)
{
  int on = 0;
  int pressed = 0;
  int zustand = 0;

  DDRD = (1 << PD5) | (1 << PD6); // LED 1 OUTPUT

  while (1)
  {
    while (PIND & (1 << PD2))
    {
      // Solange etwas gedrueckt wird, warte
       pressed = 1;
       _delay_ms(200);
    }

    if (pressed)
    {
      if (on)
      {
        PORTD = 0;
        on = 0;
        _delay_ms(200);
      }
      else
      {
        switch (zustand)
        {
          case 0:
            PORTD = (1 << PD5);
            zustand++;
            break;
          case 1:
            PORTD = (1 << PD6);
            zustand++;
            break;
          case 2:
            PORTD = (1 << PD5) | (1 << PD6); 
            zustand++;
            break;
          case 3:
            PORTD = 0;
            zustand = 0;
            break;
        }

        on = 1;
        _delay_ms(200);
      }

      pressed = 0;
    }


      _delay_ms(200);
  }
}
