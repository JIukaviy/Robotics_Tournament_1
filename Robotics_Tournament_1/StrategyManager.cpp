// 
// 
// 

#include "StrategyManager.h"
#include "Strategies.h"

StrategyManager_t::StrategyManager_t(SensorManager_t* sensorManager, Movement_t* movement) {
	SensonManager = sensorManager;
	Movement = movement;
	CurrentAreaColor = Green;
	CurrentStrategy = new CalibrateIRSensorsStrategy(sensorManager, movement);
	CurrentStrategy->Init();
	CurrentState = WaitForStart;

	start_time = millis();
}

void StrategyManager_t::Loop() {
	if (CurrentStrategy) {
		if (SensonManager->GetRadioSensor()->GetState()) {
			CurrentState = Drop;
		}
		switch (CurrentState) {
		case WaitForStart: {
			if (SensonManager->GetButtonSensor()->GetState()) {
				delete CurrentStrategy;
				CurrentStrategy = new PidLineStrategy_t(SensonManager, Movement, 0.65, 10, 0.5);
				CurrentStrategy->Init();
				CurrentState = LineForward;
			}
		} break;
		case LineForward: {
			if (SensonManager->GetColorLineDetector()->GetState() == Green) {
				delete CurrentStrategy;
				Movement->SetRotateSpeed(0);
				Movement->SetForwardSpeed(1);
				CurrentStrategy = new BaseStrategy_t(SensonManager, Movement);
				CurrentState = EnemyCircleArena;
			}
		} break;
		case Mountain: {
			if (SensonManager->GetColorLineDetector()->GetState() == Yellow) {
				CurrentState = DropEnemy;
			}
		} break;
		case DropEnemy: {
			delay(500);
			Movement->GetMineThrower()->Drop();
		} break;
		case CircleArena: {
			if (SensonManager->GetColorLineDetector()->GetState() == Red) {
				CurrentState = Drop;
			}
		} break;
		case EnemyCircleArena: {
			//Movement->SetForwardSpeed(0.5);
			if (SensonManager->GetColorLineDetector()->GetState() == Red) {
				//delay(900);
				CurrentState = Drop;
			}
		} break;
		case TurnBackInCircle: {
			Movement->SetForwardSpeed(1);
			delay(1500);
			/*
			for (int i = 0; i < 150; i++) {
				delay(10);
				if (SensonManager->GetColorLineDetector()->GetState() == Red) {
					break;
				}
			}*/
			CurrentState = Drop;
		} break;
		case Drop: {
			delay(300);
			Movement->SetForwardSpeed(0);
			Movement->GetMineThrower()->Drop();
			Movement->SetRotateSpeed(0);
			Movement->SetForwardSpeed(0.1);
			delay(100);
			Movement->SetForwardSpeed(0.4);
			delay(100);
			Movement->SetForwardSpeed(0.7);
			delay(100);
			Movement->SetForwardSpeed(1);
			delay(3000);
			Movement->SetForwardSpeed(0);
			delete CurrentStrategy;
			CurrentStrategy = nullptr;
			return;
		}
			default: ;
		} 
		CurrentStrategy->Loop();
		/*
		ColorEnum curr_color = SensonManager->GetColorSensor()->GetState();
		if (curr_color != CurrentAreaColor && curr_color != White && curr_color != Black) {
			delete CurrentStrategy;
			switch (curr_color) {
				case Purple: {
					CurrentStrategy = new MountainStrategy_t(SensonManager, Movement);
					CurrentStrategy->Init();
				}
			}
		}*/
	}
}
