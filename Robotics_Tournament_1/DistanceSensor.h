// DistanceSensor.h

#ifndef _DISTANCESENSOR_h
#define _DISTANCESENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <NewPing.h>

class DistanceSensor_t {
private:
	NewPing* sonar;
public:
	DistanceSensor_t(int trigPin, int echoPin, int maxDistance);

	int GetDistance() const;
};

#endif

