#include <avr/io.h>

void Activity1(){
    DDRB |= (1<<PB0);
    DDRD &= ~(1<<PD0);
    PORTD |= (1<<PD0);
    DDRD &= ~(1<<PD4);
    PORTD |= (1<<PD4);
}
