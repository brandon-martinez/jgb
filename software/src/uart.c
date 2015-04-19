#include "uart.h"

#include <stdbool.h>
#include <string.h>

#include <avr/interrupt.h>
#include <avr/io.h>

#include "ringbuf.h"

#include "config.h"
//NOTE:
//Useful Code Reference http://www.avrfreaks.net/forum/usart-interrupt-atmega32m1

struct ringbuffer tx_buffer = {{0}, 0, 0, true};
struct ringbuffer rx_buffer = {{0}, 0, 0, true};

//Receive interrupt routine
ISR(LIN_TC_vect) {
	if(LINSIR & (1 << LRXOK)) {
		//clear LRXOK
		LINSIR &= ~(1 << LRXOK);
		
		//write buffer
		uint8_t recv = LINDAT;
		buffer_write(&tx_buffer, recv);	
	}
	if(LINSIR & (1 << LTXOK)) {
		//clear LTXOK
		//LINSIR &= ~(1 << LTXOK);
		uint8_t data = buffer_read(&tx_buffer); 
		LINDAT = data;
		
		if(buffer_empty(&tx_buffer)) {
			LINENIR  &= ~(1 << LENTXOK);
		}
	}
}


void uart_init(uint16_t baud){
	//Reset LIN/UART hardware
	LINCR = (1 << LSWRES);
	
	//Calculate, and set UART baud rate
	LINBRRH = (((F_CPU / baud) / 16) - 1) >> 8;
	LINBRRL = (((F_CPU / baud) / 16) - 1);
	
	//Bit sampling rate/resync
	LINBTR = (1 << LDISR) | (16 << LBT0);

	//RX interrupt
	LINENIR = (1 << LENRXOK);

	//Enable UART RX & TX
	LINCR = (1 << LENA) | (1 << LCMD2) | (1 << LCMD1) | (1 << LCMD0);

	sei();
}
			
void uart_tx_byte(uint8_t data) {
	
	//the the buffer was empty, enable tx interrupt
	if(!(LINENIR & (1 << LENTXOK))) {
		LINENIR |= (1 << LENTXOK);
		LINDAT = data;
	}
	else {
		//add data to buffer
		buffer_write(&tx_buffer, data);
	}
	
	//Single Blocking Transmission
	//Wait until UART is ready
	//while (LINSIR & (1 << LBUSY));

	//LINDAT = dataByte;
}

void uart_print(char* str) {
	
}

void uart_println(char* str) {
	int len = strlen(str);	
	for(int i=0;i<len;i++) {
		uart_tx_byte(str[i]);
	}
	uart_tx_byte('\r');
	uart_tx_byte('\n');
}

uint8_t uart_rx_byte(void) {
	return buffer_read(&rx_buffer);
}
