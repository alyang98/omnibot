#include "KiwiDrive.h"

KiwiDrive::KiwiDrive(L293DMotor* m1, L293DMotor* m2, L293DMotor* m3) {
	this->M1 = m1;
	this->M2 = m2;
	this->M3 = m3;
}

void KiwiDrive::forward() {
	this->M1->power(1);
	this->M2->power(0);
	this->M3->power(-1);
}
void KiwiDrive::stop() {
	this->M1->power(0);
	this->M2->power(0);
	this->M3->power(0);
}
void KiwiDrive::left() {
	this->M1->power(turnPower);
	this->M2->power(turnPower);
	this->M3->power(turnPower);
}
void KiwiDrive::right() {
	this->M1->power(-turnPower);
	this->M2->power(-turnPower);
	this->M3->power(-turnPower);
}

void KiwiDrive::kiwiLoop(UltraSonicDistanceSensor* s, double minDist) {
	bool turning = false;

	while (s->measureSamples(10) <= minDist) {
		if (!turning) {
			if (rand() % 2 == 0) {
				this->right();
			}
			else {
				this->left();
			}
			turning = true;
			delay(800);
		}

		delay(100);
	}
	this->forward();
}