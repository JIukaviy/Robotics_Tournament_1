// OdometerSensor.h

#ifndef _ODOMETERSENSOR_h
#define _ODOMETERSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class OdometerSensor_t {
private:
	double RotationCount;
	double AngleSpeed;
public:
	OdometerSensor_t(int pin);

	double GetAngleSpeed() const;

	double GetRotationCount() const;
};

#endif

