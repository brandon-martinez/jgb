#include "adc.h"

#include <avr/io.h>

#include <stdint.h>

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


