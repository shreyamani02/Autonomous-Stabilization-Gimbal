#include<I2Cdev.h>
 #include<Kalman.h> 

Servo servox;  
Servo servoy;        

int xpin = 10 ;
int ypin= 9;
int averagex;
int averagey;
int incrament = 2;
int incrament2 = 0;

MPU6050 sensor ;

int16_t accelx, accely, accelz, storex, storey ;


int16_t gyrox, gyroy, gyroz, holdx, holdy ;
int16_t originx = 300;
int16_t originy = -628;




void setup ( )

 { 
  // join I2C bus (I2Cdev library doesn't do this automatically)
  Wire.begin();


servox.attach ( xpin );
servoy.attach(ypin);


Serial.begin  (9600); 

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
holdx = accelx -originx;
holdy = accely - originy;
Serial.print("x: ");
Serial.println (accelx);
averagex = averagex + accelx;
Serial.print("y: ");
Serial.println(accely);
averagey = averagey + accely;
storex = map (holdx, -8000, 8000, 0, 180) ;
storey = map(holdy, -8000, 8000, 0, 180);

servox.write (-storex); 
servoy.write(-storey);

delay (200);

averagex = averagex/incrament;
averagey = averagey/incrament;

Serial.print("xaverage");
Serial.println(averagex);
Serial.print("yaverage");
Serial.println(averagey);
 

 }



