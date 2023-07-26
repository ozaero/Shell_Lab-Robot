#ifndef Station_h
#define Station_h

class Station {
  
  public:

  bool CheckPlatform();
  bool CheckInner();
  bool CheckOuter();
  bool CheckRobot();
  void WakeStation();
  bool* StartPosition();
};

#endif