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
#include "Chassis.h"

class Movement_t : public Updatable_t {
private:
	Wheel_t* LeftWheel;
	Wheel_t* RightWheel;
	Chassis_t* Chassis;
	double DistanceBetweenWheels;

	double diff_coeff;
	bool ToLeft;
public:
	Movement_t(Wheel_t* leftWheel, Wheel_t* rightWheel, Chassis_t* chassis, double distanceBetweenWheels);

	void SetForwardSpeed(double speed) const;
	void StopWheels() const;
	void GoRotate(double rotateRadius, bool toLeft);
	void GoForward();

	Chassis_t* GetChassis() const;
	Wheel_t* GetLeftWheel() const;
	Wheel_t* GetRightWheel() const;

	void Update() override;
};

#endif

