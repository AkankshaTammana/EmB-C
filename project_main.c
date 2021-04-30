#include <avr/io.h>
#include <util/delay.h>

void IntiADC(){
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

void USARTInit(uint16_t ubrr_value){
    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&0x00ff;
    UCSR0C =(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    UCSR0B =(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}
char USARTReadChar(){
    while(!(UCSR0A & (1<<RXC0))){

    }
    return UDR0;
}

int main(void)
{
    Activity1();
    IntiADC();
    uint16_t temp;

    //Activity 3 data
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);
    DDRB|=(1<<PB1);

    //Activity 4 data
    USARTInit(103);
    char test;

    while(1){

        if(!(PIND & (1<<PD0))){
            if(!(PIND & (1<<PD4))){
                PORTB |= (1<<PB0);
            }else{
                PORTB &= ~(1<<PB0);
            }
        }else{
            PORTB &= ~(1<<PB0);
        }

        //Activity 2
        temp = Activity2(5);

        //Activity 3
        test = Activity3(temp);

        //Activity 4
        Activity4(test);

    }

    return 0;
}
