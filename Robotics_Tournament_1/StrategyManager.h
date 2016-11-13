// StrategyManager.h

#ifndef _STRATEGYMANAGER_h
#define _STRATEGYMANAGER_h
#include "Strategies.h"

class StrategyManager_t {
private:
	SensorManager_t* SensonManager;
	Movement_t* Movement;
	BaseStrategy_t* CurrentStrategy;
	ColorEnum CurrentAreaColor;
public:
	StrategyManager_t(SensorManager_t* sensorManager, Movement_t* movement);
	void Loop();
};

#endif

