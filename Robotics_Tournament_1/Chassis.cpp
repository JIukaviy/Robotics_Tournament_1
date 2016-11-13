// 
// 
// 

#include "Chassis.h"


Chassis_t::Chassis_t(int pin) {
	servo.attach(pin);
}

void Chassis_t::SetAngle(int angle) {
	servo.write(angle);
}

void Chassis_t::Drop() {
	SetAngle(100);
}

void Chassis_t::Lift() {
	SetAngle(10);
}
