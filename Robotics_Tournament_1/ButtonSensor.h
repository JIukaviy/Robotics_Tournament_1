#pragma once

class ButtonSensor_t {
private:
	int Pin;
	bool Pressed;
public:
	ButtonSensor_t(int pin);
	bool GetState();
};