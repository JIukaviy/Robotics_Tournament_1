// Wheel.h

#ifndef _WHEEL_h
#define _WHEEL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Updatable.h"
#include "Motor.h"
#include "OdometerSensor.h"
#include <PID_v1.h>

class Wheel_t : public Updatable_t {
private:
	Motor_t* Motor;
	OdometerSensor_t* OdometerSensor;
	double WheelRadius;
	double TargetRotationsPerSecond;

	PID* SpeedPid;
	double PidInput;
	double PidOutput;
public:
	Wheel_t(Motor_t* motor, OdometerSensor_t* odometerSensor, int wheelRadius);

	void SetAngleSpeed(double rotationsPerSecond);
	void SetForwardSpeed(double distancePerSecond);
	double GetAngleSpeed() const;
	double GetForwardSpeed() const;
	void Stop();
	void Update() override;
	~Wheel_t();
};

#endif

