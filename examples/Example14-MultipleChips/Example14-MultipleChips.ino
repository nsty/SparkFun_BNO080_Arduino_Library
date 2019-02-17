/*
  Minimum NOT working example.

  This example should show how to output accelerometer values with two
  BNO080 on the same bus.
*/

//This should be a library version with disabled internal pull-ups when using 5V hardware
#include <Wire.h>

#include "SparkFun_BNO080_Arduino_Library.h"
BNO080 myIMU0, myIMU1;

void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("BNO080 Read Example");

  Wire.begin();

  myIMU0.begin();
  myIMU1.begin(0x4A);

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU0.enableAccelerometer(50); //Send data update every 50ms
  myIMU1.enableAccelerometer(50); //Send data update every 50ms

  Serial.println(F("Accelerometer enabled"));
  Serial.println(F("Output in form x y z in m/s^2"));
}

void loop()
{
  //Look for reports from the IMUs
  if (myIMU0.dataAvailable() == true)
  {
    float x = myIMU0.getAccelX();
    float y = myIMU0.getAccelY();
    float z = myIMU0.getAccelZ();

    Serial.print(F("IMU0:\t"));
    Serial.print(x, 2);
    Serial.print('\t');
    Serial.print(y, 2);
    Serial.print('\t');
    Serial.print(z, 2);
    Serial.print('\n');
  }
  if (myIMU1.dataAvailable() == true)
  {
    float x = myIMU1.getAccelX();
    float y = myIMU1.getAccelY();
    float z = myIMU1.getAccelZ();

    Serial.print(F("IMU1:\t"));
    Serial.print(x, 2);
    Serial.print('\t');
    Serial.print(y, 2);
    Serial.print('\t');
    Serial.print(z, 2);
    Serial.print('\n');
  }
}
