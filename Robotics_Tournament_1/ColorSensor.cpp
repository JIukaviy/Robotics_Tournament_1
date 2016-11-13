// 
// 
// 

#include "ColorSensor.h"


int ColorSensor_t::GetState(int s2PinState, int s3PinState) const {
	digitalWrite(S2_PIN, s2PinState);
	digitalWrite(S3_PIN, s3PinState);
	return pulseIn(SENSOR_IN_PIN, LOW);
}

ColorSensor_t::ColorSensor_t(int sensorPin, int s2Pin, int s3Pin) {
	SENSOR_IN_PIN = sensorPin;
	S2_PIN = s2Pin;
	S3_PIN = s3Pin;
	pinMode(SENSOR_IN_PIN, INPUT);
	pinMode(S2_PIN, OUTPUT);
	pinMode(S3_PIN, OUTPUT);
}

ColorEnum ColorSensor_t::GetState() const {
	int red;
	int blue;
	int green;

	red = GetState(LOW, LOW);
	blue = GetState(LOW, HIGH);
	green = GetState(HIGH, HIGH);

	double t_yellow = abs(red*1.0f / green);

	ColorEnum res;

	if (blue < green && blue < red) {
		res = Purple;
		Serial.println("Color is Blue");
	} else if (t_yellow + 0.1 > 0.8 && t_yellow - 0.1f < 0.8) {
		res = Yellow;
		Serial.println("Color is Yellow");
	} else if (red < green) {
		res = Red;
		Serial.println("Color is Red");
	} else {
		res = Green;
		Serial.println("Color is Green");
	}

	Serial.print("Red: ");
	Serial.print(red);
	Serial.print(" Green: ");
	Serial.print(green);
	Serial.print(" Blue: ");
	Serial.print(blue);
	Serial.print(" Yellow: ");
	Serial.println(t_yellow);

	return res;
}
