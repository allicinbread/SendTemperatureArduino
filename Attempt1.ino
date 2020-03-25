// Written by: Allison Chang 
// Sourced from: SparkFun_TMP117.cpp

#include <Wire.h>

void setup() {
  Wire.begin();                // join i2c bus (address optional for master)
  Serial.begin(9600);          // start serial communication at 9600bps
}

int reading = 0;

void loop() {

  // step 1: instruct sensor to return a reading
  Wire.beginTransmission(72); 
  Wire.write(byte(0x00));      
  Wire.endTransmission();      // stop transmitting

  // step 2: request reading from sensor
  Wire.requestFrom(72, (uint8_t)2);    

  uint8_t data[2] = {0};
  int16_t datac = 0;
  if (Wire.available() <= 2) 
  {
    data[0] = Wire.read();        // Reads the first set of bits (D15-D8)
    data[1] = Wire.read();        // Reads the second set of bits (D7-D0)
    datac = ((data[0] << 8) | data[1]); // Swap the LSB and the MSB
  }
  
  Serial.println(datac*0.0078);

  delay(180000);                  // how often you want the temperature to send in ms, currently sending every 3 minutes 
}
