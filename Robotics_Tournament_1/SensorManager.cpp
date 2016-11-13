// 
// 
// 

#include "SensorManager.h"


SensorManager_t::SensorManager_t(IRSensor_t* leftIRSensor, IRSensor_t* rightIRSensor, ColorSensor_t* colorSensor, DistanceSensor_t* distanceSensor) {
	LeftIRSensor = leftIRSensor;
	RightIRSensor = rightIRSensor;
	ColorSensor = colorSensor;
	DistanceSensor = distanceSensor;
}

IRSensor_t* SensorManager_t::GetLeftIRSensor() const {
	return LeftIRSensor;
}

IRSensor_t* SensorManager_t::GetRightIRSensor() const {
	return RightIRSensor;
}

ColorSensor_t* SensorManager_t::GetColorSensor() const {
	return ColorSensor;
}

DistanceSensor_t* SensorManager_t::GetDistanceSensor() const {
	return DistanceSensor;
}
