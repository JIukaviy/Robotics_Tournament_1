// 
// 
// 

#include "Movement.h"


Movement_t::Movement_t(Wheel_t* leftWheel, Wheel_t* rightWheel, Chassis_t* chassis, double distanceBetweenWheels) {
	LeftWheel = leftWheel;
	RightWheel = rightWheel;
	Chassis = chassis;
	DistanceBetweenWheels = distanceBetweenWheels;
	diff_coeff = 1;
	ToLeft = false;
}

void Movement_t::SetForwardSpeed(double speed) const {
	if (ToLeft) {
		RightWheel->SetForwardSpeed(speed);
		LeftWheel->SetForwardSpeed(speed * diff_coeff);
	} else {
		LeftWheel->SetForwardSpeed(speed);
		RightWheel->SetForwardSpeed(speed * diff_coeff);
	}
}

void Movement_t::StopWheels() const {
	LeftWheel->Stop();
	RightWheel->Stop();
}

void Movement_t::GoRotate(double rotateRadius, bool toLeft) {
	int diff_coeff = (rotateRadius - DistanceBetweenWheels) / rotateRadius;
	ToLeft = toLeft;
}

void Movement_t::GoForward() {
	diff_coeff = 1;
}

Chassis_t* Movement_t::GetChassis() const {
	return Chassis;
}

Wheel_t* Movement_t::GetLeftWheel() const {
	return LeftWheel;
}

Wheel_t* Movement_t::GetRightWheel() const {
	return RightWheel;
}

void Movement_t::Update() { }
