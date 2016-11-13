// Chassis.h

#ifndef _CHASSIS_h
#define _CHASSIS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <Servo.h>

class Chassis_t {
private:
	Servo servo;
public:
	Chassis_t(int pin);

	void SetAngle(int angle);
	void Drop();
	void Lift();
};

#endif

