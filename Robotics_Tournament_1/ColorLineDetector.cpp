#include "ColorLineDetector.h"

ColorLineDetector_t::ColorLineDetector_t(ColorSensor_t* color_sensor, int seened_times_treshold) : color_sensor(color_sensor), seened_times_treshold(seened_times_treshold), last_seened_color(White), current_color(White) {}

ColorEnum ColorLineDetector_t::GetState() {
	auto color = color_sensor->GetState();

	if (color == last_seened_color) {
		++seened_times;
	}

	if (seened_times >= seened_times_treshold) {
		current_color = last_seened_color;
	}

	last_seened_color = color;

	return current_color;
}
