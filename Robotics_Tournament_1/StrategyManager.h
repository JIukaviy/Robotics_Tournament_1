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

	unsigned int start_time;

	enum States {
		WaitForStart,
		LineForward,
		Mountain,
		CircleArena,
		DropEnemy,
		EnemyCircleArena,
		TurnBackInCircle,
		OutCircleArena,
		Drop
	} CurrentState;
public:
	StrategyManager_t(SensorManager_t* sensorManager, Movement_t* movement);
	void Loop();
};

#endif
