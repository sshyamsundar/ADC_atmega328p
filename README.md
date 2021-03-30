In Real world applications most of the sensors which fetch data from surroundings is in analog form example( Temperature , Humidity, Moisture etc). To asses the sensor inputs we have to read analog values from the sensors. In this reposiitory we are fetching data using ATMEGA328p AVR controller without using arduino library directly interacting with registers to have clear indepth vision of controller workings. Analog to Digital Conversion(ADC) will be made Micro controller.

In this project i will be switching LED based on the readings of analog values. I will let you know the features of ATMEGA328p

    10-bit successive approximation ADC
    0 - VCC ADC Input Voltage Range
    The minimum value represents GND and the maximum value represents the voltage on the AREF pin minus 1 LSB.

Successive Approximation Method: 
                     1. (Vin > Vd): Set the next bit to 1
                     2. (Vin < Vd): Reset the last set bit to 0 and set the next bit
If the SAC is 12bit then 12 clk cycles will be taken, if 10bit then 10 clk cycles taken.
In other words, resolution is the smallest voltage increment corresponding to a 1 LSB change.
Scaled ADC_value = Raw value * reference voltage/ ADC_resolution(in our code multiplier, divisor and ADC_reference scale used)


The number of analog-to-digital converter bits is the amount of bits that make up an ADC reading. For example, a particular ADC may hold 10 bits. That means that when it converts an analog value to a digital value, it stores it in 10 bits. Each bit can either be a 1 or a 0. Therefore, with 10 bits, there are a possible 210, or 1024 values, ranging from 0 to 1023. If another ADC is a 12-bit ADc, it can hold a possible 212, or 4096 values. Therefore the range of analog to digital values can be 0 to 4095. So the smaller the ADC, the smaller the range. 

