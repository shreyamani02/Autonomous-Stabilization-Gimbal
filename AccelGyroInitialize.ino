#include <Wire.h>
#include <MPU6050.h>
//#include <MPU9250.h>
 #include <Servo.h>  
 #include<I2Cdev.h>


MPU6050 sensor;

int16_t accelx, accely, accelz;


int16_t gyrox, gyroy, gyroz;
int i = 1;



void setup ( )

 { 
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();

Serial.begin  (115200); 

Serial.println  ( "Initializing the sensor" ); 

sensor.initialize ( ); 

Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 

delay (1000); 

Serial.println ( "Taking Values from the sensor" );

delay (1000);

}




void loop ( ) 

 { 


sensor.getMotion6 (&accelx, &accely, &accelz, &gyrox, &gyroy, &gyroz);

Serial.print("accelX \t");
Serial.print(accelx);
Serial.print("\t accelY \t");
Serial.print(accely);
Serial.print("\taccelZ\t");
Serial.print( accelz);
Serial.print("\tgyroX\t");
Serial.print(gyrox);
Serial.print("\tgyroY\t");
Serial.print(gyroy);
Serial.print("\tgyroZ\t");
Serial.println(gyroz);

delay(300);
 

 }



