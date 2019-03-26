#define F_CPU 16000000L   

#include <avr/io.h>         
#include <avr/cpufunc.h>   
#include <util/delay.h>     

void main(void) 
{
    
    int pressed = 0;
    
    DDRD = (1<<PD5);

    while(1) 
    { 
        if(PIND & (1<<PD2))
        {
            if(pressed == 0) 
            {
                pressed = 1;
                PORTD = (1<<PD5);
            }
            else 
            {
                pressed = 0;
                PORTD = (0<<PD5);
                _delay_ms(1000);
            }
        }
        
    }
}
