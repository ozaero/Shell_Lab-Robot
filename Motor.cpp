#include "Arduino.h"
#include "Motor.h"

#define platformDirection 0
#define platformOnOff 1
#define bucketDirection 2
#define bucketOnOff 3
#define sliderDirection 4
#define sliderOnOff 5
#define robotDirection 6
#define robotOnOff 7

void Motor::DownPlatform(bool done){

  if(!done){

    Left("PLATFORM");
    Run("PLATFORM");

  } else{

    Stop("PLATFORM");
  }
}

void Motor::UpPlatform(bool done){

  if(!done){

    Right("PLATFORM");
    Run("PLATFORM");

  } else{

    Stop("PLATFORM");
  }
}

void Motor::RightSlider(bool done){

  if(!done){

    Right("SLIDER");
    Run("SLIDER");

  } else{

    Stop("SLIDER");
  }
}

void Motor::LeftSlider(bool done){

  if(!done){

    Left("SLIDER");
    Run("SLIDER");

  } else{

    Stop("SLIDER");
  }
}

void Motor::RightRobot(bool done){

  if(!done){

    Right("ROBOT");
    Run("ROBOT");

  } else{

    Stop("ROBOT");
  }
}

void Motor::LeftRobot(bool done){

  if(!done){

    Left("ROBOT");
    Run("ROBOT");

  } else {

    Stop("ROBOT");
  }
}

void Motor::RightBucket(){
  
  Right("ROBOT");
  Run("ROBOT");
}

void Motor::LeftBucket(){
  
  Left("BUCKET");
  Run("BUCKET");
}

void Motor::EndBucket(){
  
  Left("BUCKET");
  Run("BUCKET");
}

void Motor::StartPosition(bool* positionList){

  //Check and set the position to the robot starts own move loop, Which presses the switch it stops but

  bool positionDone;

  for(int i = 0; i < sizeof(positionList); i++){

    positionDone = positionList[i];

    switch (i) {

      case 0:
      if(!positionDone) {
        
        Right("PLATFORM");
        Run("PLATFORM");

      } else {

        Stop("PLATFORM");
      }
      break;

      case 1:
      if(!positionDone) {
        
        Right("SLIDER");
        Run("SLIDER");

      } else {

        Stop("SLIDER");
      }
      break;

      case 2:
      if(!positionDone) {
        
        Right("ROBOT");
        Run("ROBOT");

      } else {

        Stop("ROBOT");
      }
      break;
    }
  }
}

void Motor::WakeMotor(){

  //  Wake the DC motor drivers
  
  for (int i = 0; i < 8; i++) pinMode(i, OUTPUT);
}

void Motor::Run(String name){

  //The motor drivers on-off relay set on

  if(name == "PLATFORM") digitalWrite(platformOnOff, HIGH);
  else if(name == "BUCKET") digitalWrite(bucketOnOff, HIGH);
  else if(name == "SLIDER") digitalWrite(sliderOnOff, HIGH);
  else if(name == "ROBOT") digitalWrite(robotOnOff, HIGH);
}

void Motor::Stop(String name){

  //The motor drivers on-off relay set on off

  if(name == "PLATFORM") digitalWrite(platformOnOff, LOW);
  else if(name == "BUCKET") digitalWrite(bucketOnOff, LOW);
  else if(name == "SLIDER") digitalWrite(sliderOnOff, LOW);
  else if(name == "ROBOT") digitalWrite(robotOnOff, LOW);
}

void Motor::Left(String name){

  //The motor drivers direction relay set on

  if(name == "PLATFORM") digitalWrite(platformDirection, HIGH);
  else if(name == "BUCKET") digitalWrite(bucketDirection, HIGH);
  else if(name == "SLIDER") digitalWrite(sliderDirection, HIGH);
  else if(name == "ROBOT") digitalWrite(robotDirection, HIGH);
}

void Motor::Right(String name){

  //The motor drivers direction relay set off

  if(name == "PLATFORM") digitalWrite(platformDirection, LOW);
  else if(name == "BUCKET") digitalWrite(bucketDirection, LOW);
  else if(name == "SLIDER") digitalWrite(sliderDirection, LOW);
  else if(name == "ROBOT") digitalWrite(robotDirection, LOW);
}