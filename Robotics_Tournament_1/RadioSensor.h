#pragma once

#include <iarduino_RF433_Transmitter.h>
#include <iarduino_RF433_Receiver.h> 

class RadioSensor_t {
public:
	RadioSensor_t(int pin, uint8_t pipe, uint8_t stopByte);
	int GetState();
private:
	uint8_t StopByte;
	bool StopReceived;
	iarduino_RF433_Receiver RadioReceiver;
};