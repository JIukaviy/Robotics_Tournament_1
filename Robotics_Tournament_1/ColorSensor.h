// ColorSensor.h

#ifndef _COLORSENSOR_h
#define _COLORSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum ColorEnum {
	White,
	Black,
	Red,
	Green,
	Purple,
	Yellow,
	Orange
};

class ColorSensor_t {
private:
	int SENSOR_IN_PIN;
	int S2_PIN;
	int S3_PIN;

	int GetState(int s2PinState, int s3PinState) const;

public:
	ColorSensor_t(int sensorPin, int s2Pin, int s3Pin);

	ColorEnum GetState() const;
};


#endif

