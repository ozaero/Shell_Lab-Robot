#include "Motor.h"
#include "Station.h"

Motor Motor;
Station Station;

bool sceneDone;
// delayTime is that the system doesn't sens when animation starts until the part of robot cant press the switch, shaketime is the bucket move left and right dring enough time
int delayTime, shakeTime;

int sceneList[12];

void setup() {
  
  Parameter();
  SetForStar();
}

void loop() {

  SceneManager();
}

void SceneManager(){

  //This function chooses which animatation function runs while it reads animation code from the sceneList

  bool sceneDone = false;

  for(int scene; scene < sizeof(sceneList); scene++){

    while (sceneDone) {
      
      switch (scene) {
        
        case 1:
        Scene1();
        break;

        case 2:
        Scene2();
        break;

        case 3:
        Scene3();
        break;

        case 4:
        Scene4();
        break;

        case 5:
        Scene5();
        break;

        case 11:
        SceneR1();
        break;

        case 12:
        SceneR2();
        break;
      }

      delay(delayTime);
    }
  }
}

void SetForStar(){

  //This function sets the robot to start position before the animation loop start
  
  bool* startPositionList;
  bool isStart = false;

  while (isStart) {
    
    startPositionList = Station.StartPosition();
    Motor.StartPosition(startPositionList);
    
    for(int i = 0; sizeof(startPositionList); i++) {

      //This if blocks control the statement that all parts are ready to animation loop
      
      if(!startPositionList[i]) break;
      if(i == 2) isStart = true;
    }
  }
}

void Scene1(){

  //This scene lets move the platform of robot up and when it presses the own switch it stops to move

  sceneDone = false;

  while (sceneDone) {
    
    Motor.UpPlatform(sceneDone);
    sceneDone = Station.CheckPlatform();
  }
}

//This scene call the buckets motors turn functions and freeze for a while. 

void Scene2(){

  int count = 0;
  
  Motor.RightBucket();
  delay(shakeTime);

  while (true) {

    Motor.LeftBucket();
    delay(shakeTime);
    Motor.RightBucket();
    delay(shakeTime);

    count++;

    if(count == 2) break;
  }
}

void Scene3(){

  //This scene lets move the slider of robot right and when it presses the own inner switch it stops to move

  sceneDone = false;

  while (sceneDone) {
    
    Motor.RightSlider(sceneDone);
    sceneDone = Station.CheckInner();
  }
}

void Scene4(){

  //This scene lets move the slider of robot right and when it presses the own outer switch it stops to move

  sceneDone = false;

  while (sceneDone) {
    
    Motor.RightSlider(sceneDone);
    sceneDone = Station.CheckOuter();
  }
}

void Scene5(){

  //This scene lets move the slider and platform start position together 

  bool platformDone = false;
  bool sliderDone = false;
  sceneDone = false;

  while (sceneDone) {

    if(!sliderDone){

      sliderDone = Station.CheckOuter();
      Motor.LeftSlider(sliderDone);
    }
    
    if(!platformDone){

      platformDone = Station.CheckPlatform();
      Motor.DownPlatform(platformDone);
    }

    if(platformDone && sliderDone) sceneDone = true;
  }
}

void SceneR1(){

  //This scene lets move the injector arm of robot right and when it presses the own switch it stops to move

  sceneDone = false;

  while (sceneDone) {
    
    Motor.RightRobot(sceneDone);
    sceneDone = Station.CheckRobot();
  }
}

void SceneR2(){

  //This scene lets move the injector arm of robot left and when it presses the own switch it stops to move

  sceneDone = false;

  while (sceneDone) {
    
    Motor.LeftRobot(sceneDone);
    sceneDone = Station.CheckRobot();
  }
}

void Parameter(){

  int scene;

  delayTime = 750;
  shakeTime = 200;

  //Wake the components

  Motor.WakeMotor();
  Station.WakeStation();

  //The list takes in this loop choose the sequence of animations

  for(int i = 0; i < sizeof(sceneList); i++){

    switch (i) {
      
      case 0:
      scene = 1;
      break;

      case 1:
      scene = 2;
      break;

      case 2:
      case 5:
      scene = 3;
      break;

      case 3:
      case 6:
      case 9:
      scene = 11;
      break;

      case 4:
      case 7:
      case 10:
      scene = 12;
      break;

      case 8:
      scene = 4;
      break;

      case 11:
      scene = 5;
      break;
    }

    sceneList[i] = scene;
  }
}
