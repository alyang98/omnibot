/*
  HCSR04 - Library for arduino, for HC-SR04 ultrasonic distance sensor.
  Created by Martin Sosic, June 11, 2016.
*/
#include "HCSR04.h"

UltraSonicDistanceSensor::UltraSonicDistanceSensor(
        int triggerPin, int echoPin) {
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

double UltraSonicDistanceSensor::measureDistanceCm() {
    // Make sure that trigger pin is LOW.
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    // Hold trigger for 10 microseconds, which is signal for sensor to measure distance.
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    // Measure the length of echo signal, which is equal to the time needed for sound to go there and back.
    unsigned long durationMicroSec = pulseIn(echoPin, HIGH);
    double distanceCm = durationMicroSec / 2.0 * 0.0343;
    if (distanceCm == 0 || distanceCm > 400) {
        return -1.0 ;
    } else {
        return distanceCm;
    }
}

double UltraSonicDistanceSensor::measureSamples(int samples) {
	double* sample = (double*)malloc(sizeof(double) * samples);
	for (int i = 0; i < samples; i++) {
		sample[i] = measureDistanceCm();
	}
	int max = 0;
	int min = 0;
	double avg = 0;
	for (int i = 1; i < samples; i++) {
		if (sample[i] > sample[max]) {
			max = i;
		}
		if (sample[i] < sample[min]) {
			min = i;
		}
		avg += sample[i];
	}
	avg -= sample[max];
	avg -= sample[min];
	free(sample);
	return avg / (samples - 2);
}
