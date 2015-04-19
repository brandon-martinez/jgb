#ifndef UART_H 
#define UART_H

#include <stdint.h>
#include <stdbool.h>

void uart_init(uint16_t baud);

//Transmit a single byte
void uart_tx_byte(uint8_t);

//Receive a single byte
uint8_t uart_rx_byte(void);

//Send a string
bool uart_tx_str(char*);

//Receive a string
bool uart_rx_str(char*);

#endif /*LIN_UART_H*/
