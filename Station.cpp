#include "Arduino.h"
#include "Station.h"

#define platformStop A0
#define outerStop A1
#define innerStop A2
#define robotStop A3

bool Station::CheckPlatform(){
  
  if(platformStop) return true;
  else return false;
}

bool Station::CheckInner(){
  
  if(innerStop) return true;
  else return false;
}

bool Station::CheckOuter(){
  
  if(outerStop) return true;
  else return false;
}

bool Station::CheckRobot(){
  
  if(robotStop) return true;
  else return false;
}

bool* Station::StartPosition(){

  bool startPositionList[3];
  
  for(int i = 0; i < sizeof(startPositionList); i++){

    switch (i) {
      
      case 0:
      if(platformStop) startPositionList[i] = true;
      else startPositionList[i] = false;
      break;

      case 1:
      if(outerStop) startPositionList[i] = true;
      else startPositionList[i] = false;
      break;

      case 2:
      if(robotStop) startPositionList[i] = true;
      else startPositionList[i] = false;
      break;
    }
  }
  return startPositionList;
}

void Station::WakeStation(){

  //  Wake the end switches
  
  pinMode(platformStop, INPUT);
  pinMode(outerStop, INPUT);
  pinMode(innerStop, INPUT);
  pinMode(robotStop, INPUT);
}