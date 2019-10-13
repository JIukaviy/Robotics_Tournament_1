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

	virtual void Loop() {};
	virtual void Init() {}
};

class SimpleLineStrategy_t : public BaseStrategy_t {
public:
	using BaseStrategy_t::BaseStrategy_t;
	void Loop() override;
};

class PidLineStrategy_t : public BaseStrategy_t {
private:
	double P;
	double D;
	double last_val;
	double last_time;
	double treshold;
	bool last_left_activated;
	bool last_right_activated;
public:
	PidLineStrategy_t(SensorManager_t* sensor_manager, Movement_t* movement, double p, double d, double treshold);
	void Init() override;
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

class DebugLightSensor_t : public BaseStrategy_t {
public:
	using BaseStrategy_t::BaseStrategy_t;
	void Loop() override;
	void Init() override;
};

class CalibrateIRSensorsStrategy : public BaseStrategy_t {
public:
	using BaseStrategy_t::BaseStrategy_t;
	void Loop() override;
private:
	double LeftMin = 2000;
	double LeftMax = 0;
	double RightMin = 2000;
	double RightMax = 0;
};

class DebugIRCalibration : public BaseStrategy_t {
private:
	CalibrateIRSensorsStrategy calibrate_ir_sensors_strategy;
	double start_time;
public:
	DebugIRCalibration(SensorManager_t* sensor_manager, Movement_t* movement);
	void Loop() override;
	void Init() override;
};

class DebugMineThrower : public BaseStrategy_t {
public:
	using BaseStrategy_t::BaseStrategy_t;
	void Loop() override;
};

#endif

