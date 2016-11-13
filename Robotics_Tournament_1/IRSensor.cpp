// 
// 
// 

#include "IRSensor.h"


IRSensor_t::IRSensor_t(int pin) {
	SENSOR_PIN = pin;
	pinMode(SENSOR_PIN, INPUT);
}

int IRSensor_t::GetState() const {
	return digitalRead(SENSOR_PIN);
}
