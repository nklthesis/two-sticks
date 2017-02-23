// Sketch successfully tested on Arduino Uno Rev3.

// LICENCE
// Luca Giacolini
// www.lucagiacolini.com
// University College of London, Interactive Architecture Lab
// Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)

#include <Servo.h>
Servo servo;          // Define bottom servo 0-180
Servo servo1;         // Define top servo 0-180

int sensorPin = A3;   //sensor pin
int med;
int avVal = 0;

int count1 = 0;
int count2 = 0;
int count3 = 0;


void setup() {
  
  delay(1000);
  servo.attach(2);
  servo1.attach(4); 
  //set initial position   
  servo.write(180);
  servo1.write(40);
  
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  //calibration routine
  sensorSetup();
}

void loop() {

sensorRead();

  while((avVal < (med+10))&&(avVal > (med-20)))
  {
    servo.write(100);
    servo1.write(40);
    sensorRead();
    
    if(count1 == 15 || count1 == 30 || count1 == 60 || count1 == 95)
    {
      panning();
    }
    else if((count1 > 100)&&(count1 < 125))
    {
      randomSweep();
    }
    
    else if(count1 == 140 || count1 == 160)
    {
      panning();
    }

    else if(count1 > 200)
    {
      randomSweep();
    }
        
    count1++;
  }
  
  count1=0;
  
  while(avVal > (med+10))
  {
    servo.write(80);
    servo1.write(80);
    sensorRead();
    
    if(count2 == 10)
    {
      servo.write(random(80,90));
      servo1.write(random(80,90));
      delay(100);
    }
    else if(count2 > 30)
    {
      servo.write(random(80,90));
      servo1.write(random(80,90));
      delay(100);
    }
    
    count2++;
  }

  count2 = 0;
  


  while(avVal < (med-20))
  {
    servo.write(120);
    servo1.write(110);
    sensorRead();
    if(count3 == 20)
    {
      servo.write(random(130,120));
      servo1.write(random(120,110));
      delay(100);
    }
    
    count3++;
  }
  
  count3 = 0;

}
