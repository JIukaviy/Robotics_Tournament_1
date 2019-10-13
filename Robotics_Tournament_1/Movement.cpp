// 
// 
// 

#include "Movement.h"


Movement_t::Movement_t(Wheel_t** wheels, MineThrower_t* mineThrower, double distanceBetweenWheels) {
	memcpy(Wheels, wheels, sizeof(Wheel_t*) * MOTOR_COUNT);

	DistanceBetweenWheels = distanceBetweenWheels;
	diff_coeff = 1;
	ToLeft = false;
	MineThrower = mineThrower;
	forward_speed = 0;
}

void Movement_t::SetForwardSpeed(double speed) {
	if (ToLeft) {
		Wheels[LEFT_WHEEL]->SetForwardSpeed(speed);
		Wheels[RIGHT_WHEEL]->SetForwardSpeed(speed * diff_coeff);
	} else {
		Wheels[LEFT_WHEEL]->SetForwardSpeed(speed * diff_coeff);
		Wheels[RIGHT_WHEEL]->SetForwardSpeed(speed);
	}
	forward_speed = speed;
}

void Movement_t::StopWheels() const {
	for (int i = 0; i < MOTOR_COUNT; i++) {
		Wheels[i]->Stop();
	}
}

void Movement_t::GoRotate(double rotateRadius, bool toLeft) {
	diff_coeff = (rotateRadius - DistanceBetweenWheels) / rotateRadius;
	ToLeft = toLeft;
}

void Movement_t::SetRotateSpeed(double rotateSpeed) {
	diff_coeff = 1 - min(abs(rotateSpeed), 1) * 2;
	ToLeft = signbit(rotateSpeed);
	//Serial.println(rotateSpeed);
	//delay(50);
	SetForwardSpeed(forward_speed);
}

void Movement_t::GoForward() {
	diff_coeff = 1;
}

Wheel_t* Movement_t::GetWheel(int index) const {
	return Wheels[index];
}

MineThrower_t* Movement_t::GetMineThrower() const {
	return MineThrower;
}

void Movement_t::Update() { }
