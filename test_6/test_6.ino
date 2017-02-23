// Sketch successfully tested on Arduino Uno Rev3.

// LICENCE
// Luca Giacolini
// www.lucagiacolini.com
// University College of London, Interactive Architecture Lab
// Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)

#include <Servo.h>
Servo servo;           // Define bottom servo 0-180
Servo servo1;         // Define top servo 0-180

int sensorPin = A3;   //sensor pin
int med;
int avVal = 0;

int counter1 = 0;
int counter2 = 0;

bool state;         // current state of the button
int lastState = 0;     // previous state of the button

bool pos;

void setup() {
  
  delay(1000);
  servo.attach(2);
  servo1.attach(4); 
  //set initial position   
  servo.write(112);
  servo1.write(25);
  
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  //calibration routine
  sensorSetup();
}
 
void loop() {
  
  sensorRead();
  if(avVal < (med-10))
  {
    state = true;
  }
  else if(avVal > (med+5))
  {
    state = false;
  }  

  if (state != lastState) 
  {
    if (state == true) 
    {
      counter1++;

    } 
    else 
    {
      counter2++;
    }
  }

  lastState = state;

  if(counter1 == 4 && counter2 == 4){
    defense();
    counter1 = 0;
    counter2 = 0;
    }
}
