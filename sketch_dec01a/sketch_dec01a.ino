
#include "Arduino.h"
#include "L293DMotor.h"
#include "HCSR04.h"
#include "KiwiDrive.h"

double const minDistance = 20.0;
L293DMotor* M1;
L293DMotor* M2;
L293DMotor* M3;
UltraSonicDistanceSensor* distanceSensor;
KiwiDrive *kiwi;


void setup() {
  M1 = new L293DMotor(3, 5);
  M2 = new L293DMotor(6, 9);
  M3 = new L293DMotor(10, 11);
  kiwi = new KiwiDrive(M1,M2,M3);
  distanceSensor = new UltraSonicDistanceSensor(12,13);
}



void loop() {
  kiwi->kiwiLoop(distanceSensor,minDistance);

}
