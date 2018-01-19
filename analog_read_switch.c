#include <avr/io.h>
#include <util/delay.h>

volatile uint8_t ADC_val;

int main()
{
  Serial.begin(9600);
  DDRB = 0x04;
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (0 << ADPS1) | (1 << ADPS0);
  ADMUX |=  (0 << REFS0) | (1 << REFS1);
  while(1)
   {
     ADMUX = (1 << MUX2) | (1 << MUX0);     
     ADCSRA |= (1 << ADSC);
     
     while (ADCSRA & (1 << ADSC));
       ADC_val = ADCH;
       Serial.println(ADC_val); 
      _delay_ms(1);
      
     if(ADC_val >= 2)
       PORTB = 0x04;
     
     else
       PORTB = 0x00;
    }
}
