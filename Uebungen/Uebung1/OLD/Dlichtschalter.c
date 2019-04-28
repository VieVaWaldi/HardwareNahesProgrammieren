#define F_CPU 16000000L   

#include <avr/io.h>         
#include <avr/cpufunc.h>   
#include <util/delay.h>     

void main(void) 
{
    
    int pressedBut = 0;
    int pressedLed = 0;

    DDRD = (1<<PD5);

    while(1) 
    {  
        
        if(PIND & (1<<PD2)) 
        {
            pressedBut = 1;

            if(pressedLed == 0) {
                PORTD = (1<<PD5);
                pressedLed = 1;
            }
            

        }
        else 
        {
            pressedBut = 0;

        }
            

        }            
        
        _delay_ms(2);
    
    }
}

// Heute haben wir gelernt:

// 1. Immer nach Portaenderung ein delay einfuegen.
// 2. In der Regel den Tastenzustand in while definieren
//    Kein If else fuer zustandsabfragen 
