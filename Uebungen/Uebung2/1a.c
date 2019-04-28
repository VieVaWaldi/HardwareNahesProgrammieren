#define F_CPU 16000000L
#define USART_BAUDRATE 9600
//#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) -1)

#include <avr/io.h>
#include <util/delay.h>

void USART_transmit(char data) {
    while((UCSRA & (1<<UDRE)));
    UDR = data;
}

void main (void)
{

    while(1) {
        _delay_ms(122);
    }
    
    while(1){
        int i = 0;
    }

    UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0); 
    UCSRB = (1<<RXEN) | (1<<TXEN);

    char data = '1';

    while(1) {
        USART_transmit(data);
        _delay_ms(20);
    }

}
