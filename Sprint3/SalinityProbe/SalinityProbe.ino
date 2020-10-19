#include <Servo.h>
#include <conductivity.h>
#include <Sleep_n0m1.h>

Servo movePlates;
Sleep sleep;

  float calibrate(int reading){
  return float(reading);
  }

void setup() {
  // put your setup code here, to run once:
  movePlates.attach(9);
  Serial.begin(9600);
  sleep.pwrDownMode();
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading;
  float calibratedReading;
  
  movePlates.write(0); //Lower plates
  sleep.sleepDelay(2000);
  
  movePlates.write(90); //Stop plates
  
  reading = getConductivity(); //Get reading
  
  calibratedReading = calibrate(reading); //Calibrate and print
  Serial.println(calibratedReading);
  
  movePlates.write(180); //Raise Plates
  sleep.sleepDelay(2000);
  
  movePlates.write(90); //Stop for 60 seconds
  sleep.sleepDelay(60000);
}
