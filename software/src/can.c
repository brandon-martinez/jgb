// **CANGCON**
//  --------------------------------------------------------------- 
// | ABRQ | OVRQ | TTC | SYNTTC | LISTEN | TEST | ENA/~STB | SWRES |
//  --------------------------------------------------------------- 
// ARBQ - Abort Request
// OVRQ - Overload Frame Request
// TTC - Time Trigger Communication
// SYNTTC - Synchronization of TTC
// LISTEN - Listening Mode
// TEST - Test Mode
// ENA/~STB - Enable/Standby

//
1000 0x00 0x0C 0x36
500 0x02 0x04 0x13
250 
125
100
void setupCAN(uint16_t baudRate) {
	CANGCON = (1 << LISTEN) | (1 << ENASTB);
	//CANGSTA 
	//CANGIT
	//CANGIE =
	CANEN2
	CANEN1
	CANIE2
	CANIE1
	CANSIT2
	CANSIT1
	CANBT1
	CANBT2
	CANBT3
	CANTCON
	CANTIML
	CANTIMH
	CANTTCL
	CANTTCH
	CANTEC
	CANREC
	CANHPMOB
	CANPAGE
	CANSTMOB
	CANCDMOB
	CANIDT1
	CANIDT2
	CANIDT3
	CANIDT4
	CANIDM1
	CANIDM2
	CANIDM3
	CAMIDM4
	CANSTML
	CANSTMH
	CANMSG

