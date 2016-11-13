// 
// 
// 

#include "Task.h"

void MoveForwardTask_t::Init() {
	StartTime = clock();

	Movement->GoForward();
	Movement->SetForwardSpeed(Speed);
}

bool MoveForwardTask_t::DoWork() {
	return (clock() - StartTime) / CLOCKS_PER_SEC >= Time;
}

void RotateTask_t::Init() {
	StartTime = clock();

	Movement->GoRotate(RotateRadius, ToLeft);
	Movement->SetForwardSpeed(Speed);
}

bool RotateTask_t::DoWork() {
	return (clock() - StartTime) / CLOCKS_PER_SEC >= Time;
}
