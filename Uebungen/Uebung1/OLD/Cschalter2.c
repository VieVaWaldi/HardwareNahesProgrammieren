#define F_CPU 16000000L   

#include <avr/io.h>         
#include <avr/cpufunc.h>   
#include <util/delay.h>     

void main(void) 
{
    
    int pressed = 0;

    DDRD = (1<<PD6) | (1<<PD5);

    while(1) 
    {  
  
        if(PIND & (1<<PD2)) {
            PORTD = (1<<PD5);
        }

        if(PIND & (1<<PD3)) {
            PORTD = 0;
        }

        _delay_ms(20);
    }
}

// Heute haben wir gelernt:

// 1. Immer nach Portaenderung ein delay einfuegen.
// 2. In der Regel den Tastenzustand in while definieren
//    Kein If else fuer zustandsabfragen 
