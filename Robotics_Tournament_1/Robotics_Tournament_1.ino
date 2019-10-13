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
StrategyManager_t* StrategyManager;

void setup() {
	Serial.begin(9600);
	
	Wheel_t* wheels[] = {
		new Wheel_t(new Motor_t(LEFT_MOTOR_ENABLE_PIN, LEFT_MOTOR_INPUT1_PIN, LEFT_MOTOR_INPUT2_PIN), nullptr, 3),
		new Wheel_t(new Motor_t(RIGHT_MOTOR_ENABLE_PIN, RIGHT_MOTOR_INPUT1_PIN, RIGHT_MOTOR_INPUT2_PIN), nullptr, 3)
	};

	MineThrower_t* MineThrower = new MineThrower_t(SERVO_PIN, 5, 100);
	MineThrower->Lift();

	Serial.println("STARTED");
	delay(100);

	MainMovement = new Movement_t(wheels, MineThrower, 10.f);

	IRSensor_t* LeftIRSensor = new IRSensor_t(LEFT_IR_PIN);
	IRSensor_t* RightIRSensor = new IRSensor_t(RIGHT_IR_PIN);
	ColorSensor_t* ColorSensor = new ColorSensor_t();
	ColorLineDetector_t* ColorLineDetector = new ColorLineDetector_t(ColorSensor, 2);
	
	LeftIRSensor->SetMin(30);
	LeftIRSensor->SetMax(800);

	RightIRSensor->SetMin(30);
	RightIRSensor->SetMax(800);
	
	MainSensorManager = new SensorManager_t(
		LeftIRSensor,
		RightIRSensor,
		new ColorSensor_t(),
		new DistanceSensor_t(SONAR_TRIGGER_PIN, SONAR_ECHO_PIN, 300),
		new RadioSensor_t(RADIO_BUTTON_PIN, 5, 0xFE),
		new ButtonSensor_t(ENABLE_BUTTON_PIN),
		ColorLineDetector
	);

	StrategyManager = new StrategyManager_t(MainSensorManager, MainMovement);
	//MainStrategy = new PidLineStrategy_t(MainSensorManager, MainMovement, 0.17, 0, 0);
	//MainStrategy = new SimpleLineStrategy_t(MainSensorManager, MainMovement);
	//MainStrategy = new CalibrateIRSensorsStrategy(MainSensorManager, MainMovement);
	//MainStrategy = new DebugWheels_t(MainSensorManager, MainMovement);
	//MainStrategy = new DebugColorSensor_t(MainSensorManager, MainMovement);
	//MainStrategy = new DebugLightSensor_t(MainSensorManager, MainMovement);
	//MainStrategy = new DebugMineThrower(MainSensorManager, MainMovement);
	//MainStrategy->Init();
}

void loop() {
	StrategyManager->Loop();
	//MainStrategy->Loop();
}
