#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <string>
#include <vector>
#include "json.hpp"

using namespace std;

/**Defining new base class with name Sensor having constructor and distructor */
class Sensor {
  std::string SensorName;
  std::string TimeStamp;

 public:
  explicit Sensor(const std::string &name, const std::string &t)
      : SensorName(name), TimeStamp(t) {}
  virtual ~Sensor() {}
  // virtual double MaxAcceleration() { }
  virtual double MaxIntensity() {}
  // operator=(double); // TODO equating time or acc
  virtual double Abs_acc(void) {}
  // virtual void display(void) { }
  virtual double GetValue() {}
  virtual void SetMaxInt(Sensor *) {}
  // virtual double GetInt(void) { }
  int operator-(string &ref);
};

/**New Derived class Accelerometer using base class Sensor having 3 attributes
 * and some member functions*/
class Accelerometer : public Sensor {
  double accx;
  double accy;
  double accz;
  // string time_stamp;
 public:
  Accelerometer(const std::string &str, double a, double b, double c,
                const std::string &t)
      : Sensor(str, t), accx(a), accy(b), accz(c) {}
  ~Accelerometer() {}
  double Abs_acc(void);
  void display(void);
  double GetValue(void);
  // double MaxAcceleration();
};
/**New Derived class from base class Sensor with 2 attributes and some functions
 * described*/
class Sound : public Sensor {
  double Intensity;
  double MaxSoundIntensity;

 public:
  Sound(const std::string &str, const std::string &t, double a)
      : Sensor(str, t), Intensity(a), MaxSoundIntensity(-1) {}
  ~Sound() {}
  // void display();
  double MaxIntensity(void);
  void SetMaxInt(Sensor *ref);
  // double GetInt(void);
  double GetValue(void);
};