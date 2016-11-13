// IRSensor_t.h

#ifndef _IRSENSOR_h
#define _IRSENSOR_h


#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class IRSensor_t {
private:
	int SENSOR_PIN;
public:
	IRSensor_t(int pin);
	int GetState() const;
};


#endif

