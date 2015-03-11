//Clock Frequency
//#define F_CPU 16.00E6
#define F_CPU 16.00E6

//AVR-LIBC Headers 
#include <avr/cpufunc.h>
#include <avr/io.h>
#include <avr/sleep.h>

#include <util/delay.h>

#define	ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7
#define ADC8	8
#define ADC9	9
#define ADC10	10
#define TEMP	11
#define VCC4	14
#define AMP0	15
#define AMP1	16
#define AMP2	17

#define SCALE_2		0
#define SCALE_4		2
#define SCALE_8		3
#define SCALE_16	4
#define SCALE_32	5
#define SCALE_64	6
#define SCALE_128	7

#define ADC_AREF 0
#define ADC_AVCC 1

void analogSetup(uint8_t mode, uint8_t scale) {
	switch(mode) {
		//AREF SETUP
		case ADC_AREF:
			ADCSRA = (1 << ADEN) | scale;
			ADCSRB = (1 << AREFEN);
			break;
		
		//AVCC
		case ADC_AVCC:
			ADMUX  = (1 << AREFEN) | (1 << REFS0);
			ADCSRA = (1 << ADEN) | scale;
			ADCSRB = (1 << AREFEN);
			break;
	}
}

void enableDAC(void) {
	DACON = (1 << DAOE) | (1 << DAEN);
}

void disableDAC(void) {
	DACON = 0;
}

void dacWrite(uint16_t level) {
	DACH = (level >> 8);
	DACL = level;
}

//void pwmWrite(uint8_t pin, uint8_t value) {
//
//}
//
//void pwmWrite(uint8_t pin, uint16_t value) {
//
//}
//void digWrite(uint8_t pin, bool valu) {
//
//}
//bool digRead(uint8_t pin) {
//
//}

uint16_t adcRead(uint8_t pin) {
	//Clear Lower 5 bits (MUX[4:0])
	ADMUX &= 0xE0;
	ADMUX |= pin;
	
	//Start conversion
	ADCSRA |= (1 << ADSC);
	
	//Wait for complete conversion
	while(bit_is_set(ADCSRA, ADSC));
	
	//Combine bits and return value
	uint16_t low, high;
	low  = ADCL;
	high = ADCH;
	return (high << 8) | low;
}

void setup(void) {
	//Set up Digital Output Here...
	//DDRB  |= 0xFF;
	//PORTB |= 0xFF;

	//Initialize ADC at AVCC level, 125kHz
	analogSetup(ADC_AVCC, SCALE_128);
	enableDAC();

	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
	
	TIMER0 No Prescaling
	TCCR0A = (1 <<  CS00);

}

int main(void) {
	//Setup Comment
	setup();
	
	//Infinite Loop
	for(;;) {
		uint16_t analogValue = adcRead(ADC0);
		dacWrite(analogValue);
	}

	DDRB = 0xFF;
	
	//for(;;) {
	//for(;;) {
	//	DACH = 255;
	//	DACL = 255;
	//	_delay_ms(500);
	//	DACH = 0;
	//	DACL = 0;
	//	_delay_ms(500);
	//}
	return 0;
}
