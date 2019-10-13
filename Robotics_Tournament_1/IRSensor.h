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
	double MinVal = 0;
	double MaxVal = 1;
public:
	IRSensor_t(int pin);
	float GetState() const;
	void SetMin(float val);
	void SetMax(float val);
};


#endif

