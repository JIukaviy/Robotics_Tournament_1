#include "ButtonSensor.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

ButtonSensor_t::ButtonSensor_t(int pin) {
	Pin = pin;
	Pressed = false;
	pinMode(Pin, INPUT_PULLUP);
}

bool ButtonSensor_t::GetState() {
	if (Pressed) {
		return true;
	}
	if (!digitalRead(Pin)) {
		Pressed = true;
		return true;
	}
	return false;
}
