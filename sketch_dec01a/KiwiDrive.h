#pragma once

#include "L293DMotor.h"
#include "HCSR04.h"
class KiwiDrive {
public:
	KiwiDrive(L293DMotor* m1, L293DMotor* m2, L293DMotor* m3);
	void forward();
	void stop();
	void left();
	void right();
	void kiwiLoop(UltraSonicDistanceSensor* s, double minDist);

private:
	const float turnPower = .75f;
	L293DMotor* M1, * M2, * M3;
};