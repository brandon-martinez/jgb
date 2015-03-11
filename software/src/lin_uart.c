ISR(LIN TC) {
	bool
	if(
}
void initUART(uint16_t baud){
	//Unused registers
	//LINSIR
	//LINERR
	//LINBTR
	//LINDLR
	//LINIDR
	//LINSEL

	//Enable UART in rx/tx mode
	LINCR = _BV(LENA) | _BV(LCMD2) | _BV(LCMD1) | _BV(LCMD0);
	
	//Calculate, and set UART baud rate
	uint16_t clkdiv = F_CPU / baud;
	LINBRRL = clkdiv;
	LINBRRH = (clkdiv >> 8)

	//Enable tx_ok and rx_ok interrupts
	//LINENIR = _BV(LENTXOK) | _BV(LENRXOK);
}
