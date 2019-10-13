#pragma once

#include "ColorSensor.h"

class ColorLineDetector_t {
private:
	ColorSensor_t* color_sensor;
	ColorEnum last_seened_color;
	ColorEnum current_color;
	int seened_times = 0;
	int seened_times_treshold;
public:
	ColorLineDetector_t(ColorSensor_t* color_sensor, int seened_times_treshold);
	ColorEnum GetState();
};
