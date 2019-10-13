#include "RadioSensor.h"

RadioSensor_t::RadioSensor_t(int pin, uint8_t pipe, uint8_t stopByte) : RadioReceiver(pin), StopByte(stopByte), StopReceived(false) {
	RadioReceiver.begin(1000);
	RadioReceiver.openReadingPipe(pipe);
	RadioReceiver.startListening();

	Serial.println(pin);
	Serial.println(pipe);
}

int RadioSensor_t::GetState() {
	if (StopReceived) {
		return true;
	}
	uint8_t pipe;
	if (RadioReceiver.available(&pipe)) {
		uint8_t readed_byte;
		RadioReceiver.read(&readed_byte, sizeof(readed_byte));
		if (readed_byte == StopByte) {
			StopReceived = true;
			return true;
		}
	}
	return false;
}
