//Clock Frequency
//#define F_CPU 16.00E6
#define F_CPU 16.00E6

//AVR-LIBC Headers 
#include <avr/cpufunc.h>
#include <avr/io.h>
#include <avr/sleep.h>

#include <util/delay.h>

//#include "canlib/can_lib.h"
#include "adc.h"
#include "timer.h"


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



void setup(void) {
	//Initialize ADC at AVCC level, 125kHz
	analogSetup(ADC_AVCC, ADC_SCALE_128);
	enableDAC();
	
	timer0_init(TIM_SCALE_1);
	timer0_pwm_init(PWM_OCxA, PWM_NRM, WGM_MODE_3);
	
	DDRD = (1 << PD3);
}

int main(void) {
	//Setup Comment
	setup();
	
	for(;;) {
		for(int i=0;i<256;i++) {
			//OCR0A = i;
			timer0_pwm_write(PWM_OCxA, i);
			_delay_ms(10);
		}
		for(int i=255;i>=0;i--) {
			//OCR0A = i;
			timer0_pwm_write(PWM_OCxA, i);
			_delay_ms(10);
		}
	}

	return 0;
}
