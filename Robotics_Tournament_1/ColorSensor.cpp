#include "ColorSensor.h"

float dist(const float a[3], const float b[3]) {
	float res = 0;
	for (int i = 0; i < 3; i++)
		res += fabs(a[i] - b[i]);
	return res;
}

ColorSensor_t::ColorSensor_t() {
	apds.init();
	apds.enableLightSensor(false);
	delay(200);
}

ColorEnum ColorSensor_t::GetState() {
	uint16_t redRaw, greenRaw, blueRaw, sum;
	if (!apds.readRedLight(redRaw) ||
		!apds.readGreenLight(greenRaw) ||
		!apds.readBlueLight(blueRaw)
	) {
		return White;
	}
	sum = redRaw + greenRaw + blueRaw;

	float minDist = 100, norm[3] = { redRaw / (float)sum, greenRaw / (float)sum, blueRaw / (float)sum };
	/*
	Serial.print("Red: ");
	Serial.print(norm[0]);
	Serial.print(" Green: ");
	Serial.print(norm[1]);
	Serial.print(" Blue: ");
	Serial.println(norm[2]);
	*/
	ColorEnum res = Black;

	float red[] = { 0.45, 0.27, 0.3 };
	if (dist(norm, red) < minDist) {
		minDist = dist(norm, red);
		res = Red;
	}

	float green[] = { 0.25, 0.46, 0.29 };
	if (dist(norm, green) < minDist) {
		minDist = dist(norm, green);
		res = Green;
	}

	float purple[] = { 0.25, 0.31, 0.45 };
	if (dist(norm, purple) < minDist) {
		minDist = dist(norm, purple);
		res = Purple;
	}

	float yellow[] = { 0.32, 0.43, 0.25 }; // #ffff00
	if (dist(norm, yellow) < minDist) {
		minDist = dist(norm, yellow);
		res = Yellow;
	}

	float white[] = { 0.33, 0.33, 0.33 };
	if (dist(norm, white) < minDist) {
		minDist = dist(norm, white);
		res = White;
	}

	return res;
}
/*
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
*/