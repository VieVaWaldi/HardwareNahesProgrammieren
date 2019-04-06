/* 
 * LED Anschalten + Blinken
 * ========================
 * Bringen Sie den Controller dazu, eine beliebige LED des Evaluationboard anzuschalten.
 * Erweitern Sie danach ihr Programm so, dass die LED im Sekundentakt blinkt.
 * Ändern Sie dann die Schaltgeschwindigkeit in z.B. 0,5s 0,1s 0,05s 0,01s 0,005s 0,001s.
 * Was stellen Sie, insbesondere bei sehr kleinen Werten, fest?
 */

#define F_CPU 16000000L
#define pause 1

#include <avr/io.h>
#include <util/delay.h>

void main (void)              // Am Mikroprozessor bekommt man sowieso keine Werte uebergeben
{
  // PD5 = LED1
  DDRD = (1 << PD5);          // Schalte bei LED1 auf Output, DDRD = Datenregister D

  while (1)
  {
    PORTD = (1 << PD5);       // Schalte Strom dorthin, PORTD = Portregister D
    _delay_ms(pause);         // Pause
    PORTD = 0;
    _delay_ms(pause);         // Pause
  }
}
