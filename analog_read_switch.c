/* A simple ADC example that checks the analog reading on ADC5 and turns
 * an LED on if the reading is higher than a threshold value and turns if
 * off if it is under that value. */
#include <avr/io.h>
#include <util/delay.h>

volatile uint8_t ADC_val;
uint_8t Threshold 2
int main()
{
  Serial.begin(9600);
  
  /* Set the LED pin as an output. */
  DDRB = 0x04;
  
  /* Enabling ADC and Setting Prescaler Division value to 32*/
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (0 << ADPS1) | (1 << ADPS0);
  
  ADMUX |=  (0 << REFS0) | (1 << REFS1);
  while(1)
   {
    /* Setting the ADC5 (i.e) A5 pin in arduino to read the analog value*/
     ADMUX = (1 << MUX2) | (1 << MUX0);     
    
    /* Conversion takes place*/
     ADCSRA |= (1 << ADSC);
     
     while (ADCSRA & (1 << ADSC));
     /* After successfull conversion displayes value in ADC_val*/
       ADC_val = ADCH;
      _delay_ms(1);
   
/* continually check if the ADC value is greater than the
 * defined ADC_THRESHOLD value above.  If it is turn the LED on,
 * if it isn't turn it off. */
     if(ADC_val >= Threshold)
       PORTB = 0x04;
     
     else
       PORTB = 0x00;
    }
}
