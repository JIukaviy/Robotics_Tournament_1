// Task.h

#ifndef _TASK_h
#define _TASK_h

#include <time.h>
#include "SensorManager.h"
#include "Movement.h"

class Task_t {
protected:
	SensorManager_t* SensorManager;
	Movement_t* Movement;
public:
	Task_t(SensorManager_t* sensorManager, Movement_t* movement) : SensorManager(sensorManager), Movement(movement) {}
	virtual ~Task_t() {}
	virtual void Init() {}
	virtual bool DoWork() { // return true when task is done
		return true;
	}
};

class AddTaskTask_t : public Task_t {
public:
	using Task_t::Task_t;
};

class MoveForwardTask_t : public Task_t {
private:
	clock_t StartTime;
	float Time;
	float Speed;
public:
	MoveForwardTask_t(SensorManager_t* sensorManager, Movement_t* movement, float time, float speed) : Task_t(sensorManager, movement) {
		Speed = speed;
		Time = time;
	}

	void Init() override;
	bool DoWork() override;
};

class RotateTask_t : public Task_t {
private:
	clock_t StartTime;
	float Time;
	float Speed;
	float RotateRadius;
	bool ToLeft;
public:
	RotateTask_t(SensorManager_t* sensorManager, Movement_t* movement, float time, float speed, float rotateRadius, bool toLeft) : Task_t(sensorManager, movement) {
		Time = time;
		RotateRadius = rotateRadius;
		ToLeft = toLeft;
		Speed = speed;
	}

	void Init() override;
	bool DoWork() override;
};

#endif

