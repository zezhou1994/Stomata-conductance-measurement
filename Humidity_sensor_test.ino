#include <DFRobot_I2C_Multiplexer.h>
#include <HDC2080.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_Sensor.h>


/*Create an I2C Multiplexer object,and the address of I2C Multiplexer is 0X70*/
DFRobot_I2C_Multiplexer I2CMultiplexer(&Wire, 0x70);
HDC2080 sensor(0x40);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  I2CMultiplexer.begin();

  I2CMultiplexer.selectPort(0);

    // Initialize I2C communication
  sensor.begin();
    
  // Begin with a device reset
  sensor.reset();
  
  // Set up the comfort zone
  sensor.setHighTemp(28);         // High temperature of 28C
  sensor.setLowTemp(22);          // Low temperature of 22C
  sensor.setHighHumidity(55);     // High humidity of 55%
  sensor.setLowHumidity(40);      // Low humidity of 40%
  
  // Configure Measurements
  sensor.setMeasurementMode(TEMP_AND_HUMID);  // Set measurements to temperature and humidity
  sensor.setRate(ONE_HZ);                     // Set measurement frequency to 1 Hz
  sensor.setTempRes(FOURTEEN_BIT);
  sensor.setHumidRes(FOURTEEN_BIT);
  
  //begin measuring
  sensor.triggerMeasurement();





    I2CMultiplexer.selectPort(1);

    // Initialize I2C communication
  sensor.begin();
    
  // Begin with a device reset
  sensor.reset();
  
  // Set up the comfort zone
  sensor.setHighTemp(28);         // High temperature of 28C
  sensor.setLowTemp(22);          // Low temperature of 22C
  sensor.setHighHumidity(55);     // High humidity of 55%
  sensor.setLowHumidity(40);      // Low humidity of 40%
  
  // Configure Measurements
  sensor.setMeasurementMode(TEMP_AND_HUMID);  // Set measurements to temperature and humidity
  sensor.setRate(ONE_HZ);                     // Set measurement frequency to 1 Hz
  sensor.setTempRes(FOURTEEN_BIT);
  sensor.setHumidRes(FOURTEEN_BIT);
  
  //begin measuring
  sensor.triggerMeasurement();
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
    I2CMultiplexer.selectPort(0); 
      Serial.print("NO 1: ");
   //I2CMulti.selectPort(0);
//    Humidity_1 = sensor.readHumidity();
//   Temperature_1 = sensor.readTemp();
    Serial.print(sensor.readHumidity());
    Serial.print("; ");
    Serial.print(sensor.readTemp());
    Serial.print("; ");

    I2CMultiplexer.selectPort(1); 
      Serial.print("NO 1: ");
   //I2CMulti.selectPort(0);
//    Humidity_1 = sensor.readHumidity();
//   Temperature_1 = sensor.readTemp();
    Serial.print(sensor.readHumidity());
    Serial.print("; ");
    Serial.print(sensor.readTemp());
    Serial.println("; ");
}
