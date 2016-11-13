// Motor.h

#ifndef _MOTOR_h
#define _MOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Motor_t {
private:
	int EnablePin;
	int Input1Pin;
	int Input2Pin;
	double Speed;
public:
	const int MinAnalogValue = 0;
	const int MaxAnalogValue = 255;

	Motor_t(int enablePin, int input1Pin, int input2Pin);

	void SetSpeed(double speed);

	double GetSpeed() const;

	void SetDirection(int direction) const;

	void DisableMotor() const;
};


#endif

