#ifndef CAN_H
#define CAN_H

//REMOVE THIS FOR PRODUCTION!
//CONFIGURE FROM EEPROM
#define CAN_ID 
#define CAN_MSK

struct canFrame {
	uint8_t length;
	uint8_t data[8];
};

void setupCAN(uint16_t, uint16_t);

bool canSend(struct canFrame* frame);
#endif /*CAN_H*/
