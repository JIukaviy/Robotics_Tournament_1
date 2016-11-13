// Updatable.h

#ifndef _UPDATABLE_h
#define _UPDATABLE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Updatable_t {
public:
	virtual ~Updatable_t() {}
	virtual void Update() = 0;
};

#endif

