// 
// 
// 

#include "StrategyManager.h"


StrategyManager_t::StrategyManager_t(SensorManager_t* sensorManager, Movement_t* movement) {
	SensonManager = sensorManager;
	Movement = movement;
	CurrentAreaColor = Green;
}

void StrategyManager_t::Loop() {
	if (CurrentStrategy) {
		CurrentStrategy->Loop();
		ColorEnum curr_color = SensonManager->GetColorSensor()->GetState();
		if (curr_color != CurrentAreaColor && curr_color != White && curr_color != Black) {
			delete CurrentStrategy;
			switch (curr_color) {
				case Purple: {
					CurrentStrategy = new MountainStrategy_t(SensonManager, Movement);
					CurrentStrategy->Init();
				}
			}
		}
	}
}
