// 
// 
// 

#include "Strategies.h"

BaseStrategy_t::~BaseStrategy_t() {}

BaseStrategy_t::BaseStrategy_t(SensorManager_t* sensorManager, Movement_t* movement) {		
	Movement = movement;
	SensorManager = sensorManager;
}

void SimpleLineStrategy_t::Loop() {
	const int maxVal = 100;
	bool leftSensor = SensorManager->GetLeftIRSensor()->GetState() > maxVal;
	bool rightSensor = SensorManager->GetRightIRSensor()->GetState() > maxVal;
	Movement->GetWheel(LEFT_WHEEL)->SetForwardSpeed(leftSensor ? -1 : 1);
	Movement->GetWheel(RIGHT_WHEEL)->SetForwardSpeed(rightSensor ? -1 : 1);
}

PidLineStrategy_t::PidLineStrategy_t(SensorManager_t* sensor_manager, Movement_t* movement, double p, double d, double treshold) : BaseStrategy_t(sensor_manager, movement), treshold(treshold) {
	P = p;
	D = d;
	last_val = 0;
	last_time = 0;
	last_left_activated = false;
	last_right_activated = false;
}

void PidLineStrategy_t::Init() {
	Movement->SetForwardSpeed(0.8);
}

void PidLineStrategy_t::Loop() {
	double val = SensorManager->GetLeftIRSensor()->GetState() - SensorManager->GetRightIRSensor()->GetState();
	double time = micros() * 1e-06;
	double dtime = time - last_time;
	double k = max(min(val * P + (val - last_val) * dtime * D, 1), -1);
	//Movement->GetWheel(LEFT_WHEEL)->SetForwardSpeed(0.8 - k);
	//Movement->GetWheel(RIGHT_WHEEL)->SetForwardSpeed(0.8 + k);
	Movement->SetRotateSpeed(k);
	last_time = time;
	last_val = val;
}

void DebugColorSensor_t::Loop() {
	auto color = SensorManager->GetColorSensor()->GetState();

	Serial.print("Color is ");
	switch (color) {
	case Red:
		Serial.println("RED"); break;
	case Green:
		Serial.println("Green"); break;
	case Purple:
		Serial.println("Purple"); break;
	case Yellow:
		Serial.println("Yellow"); break;
	case Orange:
		Serial.println("Orange"); break;
	case White:
		Serial.println("White"); break;
	case Black:
		Serial.println("Black"); break;
	}

	delay(100);
}

void DebugWheels_t::Loop() {
	Movement->SetForwardSpeed(1);
	delay(2000);
	Movement->StopWheels();
	delay(2000);
	Movement->SetForwardSpeed(-1);
	delay(2000);
}

void DebugSonar_t::Loop() {
	Serial.print(SensorManager->GetDistanceSensor()->GetDistance());
	Serial.println("cm");
	delay(300);
}

void BlinkStrategy_t::Init() {
	pinMode(13, OUTPUT);
}

void BlinkStrategy_t::Loop() {
	digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
	delay(1000);
}

void MountainStrategy_t::Init() {
	TaskPool.PushTask(new MoveForwardTask_t(SensorManager, Movement, 1, 1), 0);
	TaskPool.PushTask(new RotateTask_t(SensorManager, Movement, 1, 1, 0, false), 0);
	TaskPool.PushTask(new MoveForwardTask_t(SensorManager, Movement, 5, 1), 0);
	TaskPool.PushTask(new RotateTask_t(SensorManager, Movement, 1, 1, 0, true), 0);
	TaskPool.PushTask(new MoveForwardTask_t(SensorManager, Movement, 1, 1), 0);
}

void MountainStrategy_t::Loop() {
	TaskPool.DoTasks();
}

void DuneStrategy_t::Init() {
	TaskPool.PushTask(new MoveForwardTask_t(SensorManager, Movement, 1, 1), 0);
	TaskPool.PushTask(new RotateTask_t(SensorManager, Movement, 1, 1, 0, true), 0);
	TaskPool.PushTask(new MoveForwardTask_t(SensorManager, Movement, 2, 1), 0);
	TaskPool.PushTask(new RotateTask_t(SensorManager, Movement, 1, 1, 0, false), 0);
	TaskPool.PushTask(new MoveForwardTask_t(SensorManager, Movement, 1, 1), 0);
}

void DuneStrategy_t::Loop() {
	TaskPool.DoTasks();
}

void DebugLightSensor_t::Loop() {
	Serial.print(SensorManager->GetLeftIRSensor()->GetState());
	Serial.print(' ');
	Serial.println(SensorManager->GetRightIRSensor()->GetState());
}

void DebugLightSensor_t::Init() {
	
}

void CalibrateIRSensorsStrategy::Loop() {
	double leftState = SensorManager->GetLeftIRSensor()->GetState();
	double rightState = SensorManager->GetRightIRSensor()->GetState();
	LeftMin = min(leftState, LeftMin);
	LeftMax = max(leftState, LeftMax);
	RightMin = min(rightState, RightMin);
	RightMax = max(rightState, RightMax);

	/*
	SensorManager->GetLeftIRSensor()->SetMin(LeftMin);
	SensorManager->GetLeftIRSensor()->SetMax(LeftMax);

	SensorManager->GetRightIRSensor()->SetMin(RightMin);
	SensorManager->GetRightIRSensor()->SetMax(RightMax);*/

	Serial.print(LeftMin);
	Serial.print(' ');
	Serial.print(LeftMax);
	Serial.print(' ');
	Serial.print(RightMin);
	Serial.print(' ');
	Serial.print(RightMax);
	Serial.println();
	delay(20);
}

DebugIRCalibration::DebugIRCalibration(SensorManager_t* sensor_manager, Movement_t* movement) : BaseStrategy_t(sensor_manager, movement), calibrate_ir_sensors_strategy(sensor_manager, movement), start_time(0) {}

void DebugIRCalibration::Loop() {
	if (millis() * 1e-03 - start_time > 4) {
		calibrate_ir_sensors_strategy.Loop();
	} else {
		Serial.print(SensorManager->GetLeftIRSensor()->GetState());
		Serial.print(' ');
		Serial.println(SensorManager->GetRightIRSensor()->GetState());
		delay(50);
	}
}

void DebugIRCalibration::Init() {
	start_time = millis() * 1e-03;
	calibrate_ir_sensors_strategy.Init();
}

void DebugMineThrower::Loop() {
	if (SensorManager->GetButtonSensor()->GetState()) {
		Movement->GetMineThrower()->Drop();
	}
}
