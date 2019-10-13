// Chassis.h

#ifndef _MINETHROWER_h
#define _MINETHROWER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Servo.h>

class MineThrower_t {
private:
	Servo servo;
	int minAngle;
	int maxAngle;
public:
	MineThrower_t(int pin, int minAngle, int maxAngle);

	void Drop();
	void Lift();
};

#endif

