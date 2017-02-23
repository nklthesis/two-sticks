void randomSweep()
{
  //swtiching in between rest and moving somewhere randomly
  switch (random(0,1)){
    
  case 0:
  servo.write(random(0, 100));
  servo1.write(random(30, 60));
  delay(150);
  servo.write(random(100, 180));
  servo1.write(random(60, 80));
  delay(150);
  break;

  case 1:
  delay(400); 
  break;
  }
}

void panning()
{
  servo.write(0);
  delay(100);
  servo.write(180);
  delay(500);
}

void defense()
{
  servo.write(100);
  servo1.write(90);
  delay(300);
  servo1.write(70);
  delay(100);
  servo1.write(90);
  delay(100);
    servo1.write(70);
  delay(100);
  servo1.write(25);
  servo.write(112);
}
