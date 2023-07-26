#ifndef Motor_h
#define Motor_h

class Motor {
  
  public:
  
  void WakeMotor();
  void StartPosition(bool* positionList);
  void DownPlatform(bool done);
  void UpPlatform(bool done);
  void RightSlider(bool done);
  void LeftSlider(bool done);
  void RightRobot(bool done);
  void LeftRobot(bool done);
  void RightBucket();
  void LeftBucket();
  void EndBucket();

  private:

  void Run(String name);
  void Stop(String name);
  void Left(String name);
  void Right(String name);
};

#endif