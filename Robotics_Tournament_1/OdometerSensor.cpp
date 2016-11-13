// 
// 
// 

#include "OdometerSensor.h"


OdometerSensor_t::OdometerSensor_t(int pin) {
	pinMode(pin, INPUT);
	RotationCount = 0;
	AngleSpeed = 0;
}

double OdometerSensor_t::GetAngleSpeed() const {
	return AngleSpeed;
}

double OdometerSensor_t::GetRotationCount() const {
	return RotationCount;
}
