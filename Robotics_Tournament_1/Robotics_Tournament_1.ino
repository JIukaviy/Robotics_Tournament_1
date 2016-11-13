#include "StrategyManager.h"
#include "Strategies.h"
#include "Movement.h"
#include "Wheel.h"
#include "Motor.h"
#include "DistanceSensor.h"
#include "ColorSensor.h"
#include "IRSensor.h"
#include "SensorManager.h"
#include "Pins.h"

Movement_t* MainMovement;

SensorManager_t* MainSensorManager;

BaseStrategy_t* MainStrategy;

void setup() {
	MainMovement = new Movement_t(
		new Wheel_t(new Motor_t(LEFT_MOTOR_ENABLE_PIN, LEFT_MOTOR_INPUT1_PIN, LEFT_MOTOR_INPUT2_PIN), nullptr, 3),
		new Wheel_t(new Motor_t(RIGHT_MOTOR_ENABLE_PIN, RIGHT_MOTOR_INPUT1_PIN, RIGHT_MOTOR_INPUT2_PIN), nullptr, 3),
		/*new Chassis_t(SERVO_PIN)*/ nullptr,
		10.f
	);

	MainSensorManager = new SensorManager_t(
		new IRSensor_t(LEFT_IR_PIN),
		new IRSensor_t(RIGHT_IR_PIN),
		new ColorSensor_t(COLOR_INPUT_PIN, COLOR_S2_PIN, COLOR_S3_PIN),
		new DistanceSensor_t(SONAR_TRIGGER_PIN, SONAR_ECHO_PIN, 300));

	MainStrategy = new BlinkStrategy_t(MainSensorManager, MainMovement);
	MainStrategy->Init();
}

void loop() {
	MainStrategy->Loop();
}
