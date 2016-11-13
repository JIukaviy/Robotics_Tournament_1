// 
// 
// 

#include "DistanceSensor.h"


DistanceSensor_t::DistanceSensor_t(int trigPin, int echoPin, int maxDistance) {
	sonar = new NewPing(trigPin, echoPin, maxDistance);
}

int DistanceSensor_t::GetDistance() const {
	return sonar->convert_cm(sonar->ping_median(5));
}
