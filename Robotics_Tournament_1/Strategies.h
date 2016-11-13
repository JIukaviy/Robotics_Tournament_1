// Strategies.h

#ifndef _STRATEGIES_h
#define _STRATEGIES_h

#include "Movement.h"
#include "SensorManager.h"
#include "TaskPool.h"

class BaseStrategy_t {
protected:
	SensorManager_t* SensorManager;
	Movement_t* Movement;
	TaskPool_t TaskPool;
public:
	virtual ~BaseStrategy_t();

	BaseStrategy_t(SensorManager_t* sensorManager, Movement_t* movement);

	virtual void Loop() = 0;
	virtual void Init() {}
};

class SimpleLineStrategy_t : public BaseStrategy_t {
public:
	using BaseStrategy_t::BaseStrategy_t;
	void Loop() override;
};

class DebugColorSensor_t : public BaseStrategy_t {
public:
	using BaseStrategy_t::BaseStrategy_t;
	void Loop() override;
};

class DebugWheels_t : public BaseStrategy_t {
public:
	using BaseStrategy_t::BaseStrategy_t;
	void Loop() override;
};

class DebugSonar_t : public BaseStrategy_t {
	using BaseStrategy_t::BaseStrategy_t;
	void Loop() override;
};

class DebugChassis_t : public BaseStrategy_t {
	using BaseStrategy_t::BaseStrategy_t;
	void Loop() override;
};

class BlinkStrategy_t : public BaseStrategy_t {
public:
	using BaseStrategy_t::BaseStrategy_t;
	void Init() override;
	void Loop() override;
};

class MountainStrategy_t : public BaseStrategy_t {
public:
	using BaseStrategy_t::BaseStrategy_t;
	void Loop() override;
	void Init() override;
};

class DuneStrategy_t : public BaseStrategy_t {
public:
	using BaseStrategy_t::BaseStrategy_t;
	void Loop() override;
	void Init() override;
};

#endif

