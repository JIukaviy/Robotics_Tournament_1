#include "MineThrower.h"

MineThrower_t::MineThrower_t(int pin, int minAngle, int maxAngle) : minAngle(minAngle), maxAngle(maxAngle) {
	servo.attach(pin);
}

void MineThrower_t::Drop() {
	servo.write(maxAngle);
}

void MineThrower_t::Lift() {
	servo.write(minAngle);
}
