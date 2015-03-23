void setupCAN(uint16_t baudRate, uint16_t canID) {
	CANGCON = (1 << LISTEN) | (1 << ENASTB);
	CANGSTA = (1 << ENFG);
	//CANGIT
	
	//ENIT to enable all interupts
	CANGIE = (1 << ENTX) | (1 << ENRX) | (1 << ENERR);
	
	//(???) Can Mob Status (READ ONLY)
	CANEN2 
	
	//Don't Understand this register
	CANIE1
	
	//Don't Understand this register
	CANSIT2
	
	//Table 19-2 1000kbps 16Mhz 75% (Page 188)
	CANBT1 = 0x02;
	CANBT2 = 0x04;
	CANBT3 = 0x13;
	
	//CAN Timer Clock Scaler = Tclkio * 8 * (CANTCON + 1)
	CANTCON = 
	
	//CAN Timer Range
	CANTIML = 
	CANTIMH = 
	

	//CAN TTC Timer Range
	CANTTCL = 
	CANTTCH = 

	//TX Error Code
	CANTEC = 

	//RX Error Code
	CANREC = 

	
	CANHPMOB
	CANPAGE
	CANSTMOB
	CANCDMOB
	CANIDT1 = (CAN_ID >> 3) CANIDT2 = (CAN_ID << 5) 

	//RTRTAG RB0TAG
	CANIDT4

	//CAN ID Mask (Filtering) Page 168
	//CANIDM1 = (CAN_MSK >> 3) 
	//CANIDM2 = (CAN_MSK << 5)
	//CAMIDM4 = RTRMSK IDEMSK
	
	//CAN Time Stamp Range
	CANSTML
	CANSTMH

	CANMSG
}

bool canSend(struct canFrame* frame) {
	
}

struct canFrame* canReceive(void) {

}
