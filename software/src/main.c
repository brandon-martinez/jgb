#include "config.h"

//AVR-LIBC Headers 
#include <avr/cpufunc.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/sleep.h>

#include <util/delay.h>

#include "can_lib.h"
#include "adc.h"
#include "timer.h"
#include "uart.h"

//Device CAN_ID
#define CAN_ID 0x080

//uint8_t response_data[CAN_BUFFER_SIZE];

void setup(void) {
	uart_init(BAUD);
}

int main(void) {
	//Setup Comment
	setup();
	char str [] = "Hello World?";
	for(;;) {
		//uart_println(&(str[0]));
		uart_tx_byte('H');
		uart_tx_byte('e');
		uart_tx_byte('l');
		uart_tx_byte('l');
		uart_tx_byte('o');
		uart_tx_byte(' ');
		uart_tx_byte('W');
		uart_tx_byte('o');
		uart_tx_byte('r');
		uart_tx_byte('l');
		uart_tx_byte('d');
		uart_tx_byte('!');
		uart_tx_byte('\r');
		uart_tx_byte('\n');
		
		//char input[50];
		//uart_rx(input);
		//uart_tx(input);
		//uart_tx('\r');
		//uart_tx('\n');
		_delay_ms(2000);
	}
	
	return 0;
}
