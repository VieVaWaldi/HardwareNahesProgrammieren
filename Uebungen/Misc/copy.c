#include <avr/io.h>

int main()
{
    DDRB = 0xFF;    // out
    DDRC = 0x00;    // in

    while (1) 
    {
        PORTC = PORTB;
    }
    
    return 0;
}
