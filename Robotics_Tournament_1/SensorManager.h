// SensorManager.h

#ifndef _SENSORMANAGER_h
#define _SENSORMANAGER_h
#include "IRSensor.h"
#include "ColorSensor.h"
#include "DistanceSensor.h"
#include "RadioSensor.h"
#include "ButtonSensor.h"
#include "ColorLineDetector.h"

class SensorManager_t {
private:
	IRSensor_t* LeftIRSensor;
	IRSensor_t* RightIRSensor;
	ColorSensor_t* ColorSensor;
	DistanceSensor_t* DistanceSensor;
	RadioSensor_t* RadioSensor;
	ButtonSensor_t* ButtonSensor;
	ColorLineDetector_t* ColorLineDetector;
public:
	SensorManager_t(IRSensor_t* leftIRSensor, IRSensor_t* rightIRSensor, ColorSensor_t* colorSensor, DistanceSensor_t* distanceSensor, RadioSensor_t* radioSensor, ButtonSensor_t* buttonSensor, ColorLineDetector_t* colorLineDetector);

	IRSensor_t* GetLeftIRSensor() const;
	IRSensor_t* GetRightIRSensor() const;
	ColorSensor_t* GetColorSensor() const;
	DistanceSensor_t* GetDistanceSensor() const;
	RadioSensor_t* GetRadioSensor() const;
	ButtonSensor_t* GetButtonSensor() const;
	ColorLineDetector_t* GetColorLineDetector() const;
};

#endif
