// Movement.h

#ifndef _MOVEMENT_h
#define _MOVEMENT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Updatable.h"
#include "Wheel.h"
#include "MineThrower.h"

#define MOTOR_COUNT 2

#define LEFT_WHEEL 0
#define RIGHT_WHEEL 1

class Movement_t : public Updatable_t {
private:
	Wheel_t* Wheels[MOTOR_COUNT];
	MineThrower_t* MineThrower;
	double DistanceBetweenWheels;

	double diff_coeff;
	double forward_speed;
	bool ToLeft;
public:
	Movement_t(Wheel_t** wheels, MineThrower_t* mineThrower, double distanceBetweenWheels);

	void SetForwardSpeed(double speed);
	void StopWheels() const;
	void GoRotate(double rotateRadius, bool toLeft);
	void SetRotateSpeed(double rotateSpeed);
	void GoForward();

	Wheel_t* GetWheel(int index) const;

	MineThrower_t* GetMineThrower() const;

	void Update() override;
};

#endif

