#include "header.h"

/**header.cpp file has the defination of the functions defined in the header.h*/

/*
void Accelerometer :: display(void)
{
        std::cout<<accx<<"\t"<<accy<<"\t"<<accz<<"\t"<<endl;
}

void Sound :: display(void)
{
        std::cout<<Intensity<<endl;
}

double Sound :: GetInt(void)
{
        return Intensity;
}
*/

/**Below we have the definations of all the functions */

double Accelerometer ::Abs_acc(void) {
  double abs_acc = sqrt(accx * accx + accy * accy + accz * accz);
  return abs_acc;
}

double Sound ::MaxIntensity(void) {
  // TODO
  return MaxSoundIntensity;
}

double Sound ::GetValue(void) { return Intensity; }

double Accelerometer ::GetValue(void) { return accx; }

void Sound ::SetMaxInt(Sensor *ref) {
  // Todo
  if (ref->MaxIntensity() >= Intensity)
    MaxSoundIntensity = ref->MaxIntensity();
  else
    MaxSoundIntensity = Intensity;
}

int Sensor::operator-(string &ref) { return 0; }