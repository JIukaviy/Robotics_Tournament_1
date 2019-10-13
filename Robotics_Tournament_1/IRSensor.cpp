// 
// 
// 

#include "IRSensor.h"


IRSensor_t::IRSensor_t(int pin) {
	SENSOR_PIN = pin;
	pinMode(SENSOR_PIN, INPUT);
}

float IRSensor_t::GetState() const {
	return constrain((analogRead(SENSOR_PIN) - MinVal) / (MaxVal - MinVal), 0, 1023);
}

void IRSensor_t::SetMin(float val) {
	MinVal = val;
}

void IRSensor_t::SetMax(float val) {
	MaxVal = val;
}
