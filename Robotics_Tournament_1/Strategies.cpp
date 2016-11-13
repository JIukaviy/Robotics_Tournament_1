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
	Movement->GetLeftWheel()->SetForwardSpeed(SensorManager->GetLeftIRSensor()->GetState() ? 1 : -1);
	Movement->GetRightWheel()->SetForwardSpeed(SensorManager->GetRightIRSensor()->GetState() ? 1 : -1);
}

void DebugColorSensor_t::Loop() {
	SensorManager->GetColorSensor()->GetState();
	delay(500);
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

void DebugChassis_t::Loop() {
	Movement->GetChassis()->Drop();
	delay(5000);
	Movement->GetChassis()->Lift();
	delay(5000);
}

void BlinkStrategy_t::Init() {
	pinMode(13, OUTPUT);
}

void BlinkStrategy_t::Loop() {
	digitalWrite(13, HIGH);
	delay(500);
	digitalWrite(13, LOW);
	delay(500);
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