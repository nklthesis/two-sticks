int sum = 0;
int value = 0;
int numReadings = 10;

//calibration. Do not touch the sensor stick when Arduino starts up. When the routine is done, the actuation stick sort of shakes his head to confirm;
int sensorSetup()
{

  int testVal;
  int testSum;

  for (int i=0; i < 40; i++){
    
  testVal = analogRead(sensorPin);
  testSum = testSum+testVal;

  delay(50);
  }  
  
  med = (testSum/40);

  servo1.write(60);
  delay(100);
  servo1.write(40);  

  return med;
}  


//input: flex sensor on A3. Reading the average of n' values;
int sensorRead()
{
    sum = 0;
  avVal = 0;
  
  for (int i=0; i < numReadings; i++)
  {  
    value = analogRead(sensorPin);
    sum = sum+value;
    delay(5);
  }  
  avVal = (sum/numReadings);
  
//  Serial.print("rest position value = ");
//  Serial.println(avVal);

  return avVal;
}
