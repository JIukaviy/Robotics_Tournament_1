// 
// 
// 

#include "SensorManager.h"

SensorManager_t::SensorManager_t(IRSensor_t* leftIRSensor, IRSensor_t* rightIRSensor, ColorSensor_t* colorSensor, DistanceSensor_t* distanceSensor, RadioSensor_t* radioSensor, ButtonSensor_t* buttonSensor, ColorLineDetector_t* colorLineDetector) {
	LeftIRSensor = leftIRSensor;
	RightIRSensor = rightIRSensor;
	ColorSensor = colorSensor;
	DistanceSensor = distanceSensor;
	RadioSensor = radioSensor;
	ButtonSensor = buttonSensor;
	ColorLineDetector = colorLineDetector;
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

RadioSensor_t* SensorManager_t::GetRadioSensor() const {
	return RadioSensor;
}

ButtonSensor_t* SensorManager_t::GetButtonSensor() const {
	return ButtonSensor;
}

ColorLineDetector_t* SensorManager_t::GetColorLineDetector() const {
	return ColorLineDetector;
}
