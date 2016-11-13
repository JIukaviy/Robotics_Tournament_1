// 
// 
// 

#include "Wheel.h"
#include "Constants.h"

Wheel_t::Wheel_t(Motor_t* motor, OdometerSensor_t* odometerSensor, int wheelRadius) {
	Motor = motor;
	OdometerSensor = odometerSensor;
	WheelRadius = wheelRadius;
	SpeedPid = new PID(&PidInput, &PidOutput, &TargetRotationsPerSecond, WHEEL_KD, WHEEL_KI, WHEEL_KP, DIRECT);
	SpeedPid->SetOutputLimits(-1, 1);
}

void Wheel_t::SetAngleSpeed(double rotationsPerSecond) {
	TargetRotationsPerSecond = rotationsPerSecond;
}

void Wheel_t::SetForwardSpeed(double distancePerSecond) {
	TargetRotationsPerSecond = distancePerSecond / (2 * PI * WheelRadius);
}

double Wheel_t::GetAngleSpeed() const {
	if (OdometerSensor) {
		return OdometerSensor->GetAngleSpeed();
	} else {
		return Motor->GetSpeed();
	}
}

double Wheel_t::GetForwardSpeed() const {
	return GetAngleSpeed() * 2 * PI * WheelRadius;
}

void Wheel_t::Stop() {
	TargetRotationsPerSecond = 0;
}

void Wheel_t::Update() {
	if (OdometerSensor) {
		PidInput = OdometerSensor->GetAngleSpeed();
		SpeedPid->Compute();
		Motor->SetSpeed(PidOutput);
	} else {
		Motor->SetSpeed(TargetRotationsPerSecond);
	}
}

Wheel_t::~Wheel_t() {
	delete SpeedPid;
}
