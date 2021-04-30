#include <avr/io.h>
#include <util/delay.h>

void Activity4(char data){
    while(!(UCSR0A & (1<<UDRE0)))
    {

    }
    UDR0= data;
}
