#define F_CPU 16000000L     // CPU Takt wird fuer delay gebraucht

#include <avr/io.h>         // Viele defines fuer Ports etc.

void main(void) 
{
    PORTD = (1<<5);
    DDRD = (1<<5); 
    
    //_NOP();

    while(1) 
    {
    
    }
}
