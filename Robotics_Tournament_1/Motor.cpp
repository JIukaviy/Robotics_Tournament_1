// 
// 
// 

#include "Motor.h"


Motor_t::Motor_t(int enablePin, int input1Pin, int input2Pin) {
	EnablePin = enablePin;
	Input1Pin = input1Pin;
	Input2Pin = input2Pin;

	pinMode(EnablePin, OUTPUT);
	pinMode(Input1Pin, OUTPUT);
	pinMode(Input2Pin, OUTPUT);
}

void Motor_t::SetSpeed(double speed) {
	Speed = speed;
	int value = MinAnalogValue + abs(speed) * (MaxAnalogValue - MinAnalogValue);
	analogWrite(EnablePin, value);
	SetDirection(signbit(speed));
}

double Motor_t::GetSpeed() const {
	return Speed;
}

void Motor_t::SetDirection(int direction) const {
	digitalWrite(Input1Pin, direction ? HIGH : LOW);
	digitalWrite(Input2Pin, direction ? LOW : HIGH);
}

void Motor_t::DisableMotor() const {
	digitalWrite(Input1Pin, LOW);
	digitalWrite(Input2Pin, LOW);
}
