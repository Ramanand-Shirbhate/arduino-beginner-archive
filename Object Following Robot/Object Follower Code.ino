#include <NewPing.h>
#define trig 11
#define echo 12

#define max_fwd_speed 75
#define max_turn_speed 50

#define min_dist 10
#define max_dist 30

#define ir_right 2
#define ir_left 3

int enA=5;
int R1=7;
int R2=8;

int enB=6;
int L1=9;
int L2=10;

NewPing mySensor(trig, echo, 400);

void setup()
{
  
  pinMode(enA, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  
  pinMode(enB, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);

  pinMode(ir_right, INPUT);
  pinMode(ir_left, INPUT);
  rotateMotor(0,0);   
}


void loop()
{
  int distance = mySensor.ping_cm();
  int rightIRSensorValue = digitalRead(ir_right);
  int leftIRSensorValue = digitalRead(ir_left);

  
  if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH )
  {
      rotateMotor(max_fwd_speed - max_turn_speed, max_fwd_speed + max_turn_speed ); 
  }
  
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW )
  {
      rotateMotor(max_fwd_speed + max_turn_speed, max_fwd_speed - max_turn_speed); 
  }
  else if (distance >= min_dist && distance <= max_dist)
  {
    rotateMotor(max_fwd_speed, max_fwd_speed);
  }
  else 
  {
    rotateMotor(0, 0);
  }
}


void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  if (rightMotorSpeed < 0)
  {
    digitalWrite(R1,LOW);
    digitalWrite(R2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(R1,HIGH);
    digitalWrite(R2,LOW);      
  }
  else
  {
    digitalWrite(R1,LOW);
    digitalWrite(R2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(L1,LOW);
    digitalWrite(L2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(L1,HIGH);
    digitalWrite(L2,LOW);      
  }
  else 
  {
    digitalWrite(L1,LOW);
    digitalWrite(L2,LOW);      
  }
  analogWrite(enA, abs(rightMotorSpeed));
  analogWrite(enB, abs(leftMotorSpeed));    
}