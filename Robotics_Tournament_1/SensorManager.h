// SensorManager.h

#ifndef _SENSORMANAGER_h
#define _SENSORMANAGER_h
#include "IRSensor.h"
#include "ColorSensor.h"
#include "DistanceSensor.h"

class SensorManager_t {
private:
	IRSensor_t* LeftIRSensor;
	IRSensor_t* RightIRSensor;
	ColorSensor_t* ColorSensor;
	DistanceSensor_t* DistanceSensor;
public:
	SensorManager_t(IRSensor_t* leftIRSensor, IRSensor_t* rightIRSensor, ColorSensor_t* colorSensor, DistanceSensor_t* distanceSensor);

	IRSensor_t* GetLeftIRSensor() const;
	IRSensor_t* GetRightIRSensor() const;
	ColorSensor_t* GetColorSensor() const;
	DistanceSensor_t* GetDistanceSensor() const;
};


#endif

