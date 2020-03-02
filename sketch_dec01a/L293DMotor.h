#pragma once
#include "Arduino.h"
class L293DMotor {
public:

	L293DMotor(int f = 0, int b = 0) {
		x = f;
		y = b;
		pinMode(x, OUTPUT);
		pinMode(y, OUTPUT);
	}

	// v is from -1 to 1
	void power(float v) {
		v = min(v, 1);
		v = max(v, -1);

		if (v < 0) {
			analogWrite(x, 0);
			analogWrite(y, -v * 255);
		}

		else if (v > 0) {
			analogWrite(y, 0);
			analogWrite(x, v * 255);
		}
		else {
			analogWrite(x, 0);
			analogWrite(y, 0);
		}
	}

	void powerTime(float v, int ms) {
		power(v);
		delay(ms);
	}
	void testMotor(int delay_ms = 500) {
		powerTime(1, delay_ms);
		powerTime(0, delay_ms);
		powerTime(-1, delay_ms);
		powerTime(0, delay_ms);
	}
private:
	int x;
	int y;
};




