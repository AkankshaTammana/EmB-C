#include <avr/io.h>
#include <util/delay.h>

char Activity3(uint16_t temp){
    char temp1;
    if(temp>0 && temp<=209){
        OCR1A = 1024 * 0.2;
        _delay_ms(200);
        temp1 = 20;

    }
    else if(temp>209 && temp <= 509){
        OCR1A = 1024 * 0.4;
        _delay_ms(200);
        temp1 = 25;
    }
    else if(temp>509 && temp <= 709){
        OCR1A = 1024 * 0.7;
        _delay_ms(200);
        temp1 = 29;
    }
    else if(temp>709 && temp <= 1024){
        OCR1A = 1024 * 0.95;
        _delay_ms(200);
        temp1 = 33;
    }
    else{
        OCR1A = 0;
        _delay_ms(2000);
        temp1 = 0;
    }
    return temp1;
}
