// ColorSensor.h

#ifndef _COLORSENSOR_h
#define _COLORSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <SparkFun_APDS9960.h>

enum ColorEnum {
	White,
	Black,
	Red,
	Green,
	Purple,
	Yellow,
	Orange
};

class ColorSensor_t {
private:
	SparkFun_APDS9960 apds;
public:
	ColorSensor_t();
	ColorEnum GetState();
};


#endif

