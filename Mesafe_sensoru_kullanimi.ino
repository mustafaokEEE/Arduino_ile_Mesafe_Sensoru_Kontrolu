#include <Servo.h>
int yellowLed=3;
int greenLed=2;
int echo_pin=4;
int trig_pin=5;

bool yellowBlink=false;
bool greenBlink=false;

Servo servoMotor;

void setup () 
{

  Serial.begin(9600);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);

  servoMotor.attach(9);
  pinMode(yellowLed,OUTPUT);
  pinMode(greenLed,OUTPUT);

}
void loop() 
{
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(5);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);

  long duration=pulseIn(echo_pin,HIGH);   // sinyali okuması için gecen surec
  float distance=(duration/2)*0.0343;       // mesafe hesabı

  Serial.print("Distance"); Serial.print(distance); Serial.println("cm");

  if(greenBlink==false)
    {
      for(int val1=0; val1<=180; val1++)
        {
          servoMotor.write(val1);
          digitalWrite(greenLed,HIGH);
          delay(10);
        }
      greenBlink=true;
        if(greenBlink==true)
          {
            digitalWrite(greenLed,LOW);
          }
    }
      if(yellowBlink==false)
        {
          for(int val2=180; val2>=0; val2--)
            {
              servoMotor.write(val2);
              digitalWrite(yellowLed,HIGH);
              delay(10);
            }
        }
        yellowBlink=true;
          if(yellowBlink==true)
            {
              digitalWrite(yellowLed,LOW);
            }

      greenBlink=false;
      yellowBlink=false;



}