#ifndef pancake_h
#define pancake_h
#include <string>
using namespace std;

class Pancake {
private:
  bool _topSweet;
  bool _btmSweet;
  string _orientate;

public:
  Pancake();
  void setTopSweet();
  void setBtmSweet();
  bool getBtmSweet();
  bool getTopSweet();
  string getOrientation();
  void toggleOrientation();
  void setOrientationSweet();
  void setReverseOrientationSweet();
};

#endif
