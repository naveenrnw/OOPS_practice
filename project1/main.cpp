
#include "function.h"

using json = nlohmann::json;
/**Main function for the Perfoming sutaible calculations and algorithms to
 * obtain the results*/
int main() {
  /**using ifstream to read data from the file and the parsing the data in json
   * format*/
  ifstream fin("data.json");

  json data = json::parse(fin);

  std::vector<Sensor *> Acc_data;
  std::vector<double> Acc_magnitude;
  std::vector<Sensor *> SoundIntensity;
  std::vector<double> AccelerometerData;
  std::vector<double> SoundData;

  for (auto entry : data) {
    Acc_data.push_back(new Accelerometer(
        "Accelerometer", entry.value("ACCELEROMETER X (m/s²)", 0.4f),
        entry.value("ACCELEROMETER Y (m/s²)", 0.4f),
        entry.value("ACCELEROMETER Z (m/s²)", 0.4f),
        entry.value("YYYY-MO-DD HH-MI-SS_SSS", "")));
    SoundIntensity.push_back(
        new Sound("Sound", entry.value("YYYY-MO-DD HH-MI-SS_SSS", ""),
                  entry.value("SOUND LEVEL (dB)", 0.4f)));
  }

  for (auto it : Acc_data) {
    Acc_magnitude.push_back(it->Abs_acc());
    AccelerometerData.push_back(it->GetValue());
  }
  /*
  for (auto itr:Acc_magnitude)
      cout<<itr<<endl;*/
  double MaxValueOfSound;
  auto TempItr = SoundIntensity[0];
  for (auto itr : SoundIntensity) {
    SoundData.push_back(itr->GetValue());
    itr->SetMaxInt(TempItr);
    MaxValueOfSound = itr->MaxIntensity();
    TempItr = itr;
  }
  /**Bellow Function SpikesCount is used for calculating the Number of Shakes of
   * Phone*/
  int SpikesCount = Spikes(AccelerometerData);
  cout << "--------------------" << endl;
  cout << "Number of times of Phone Shaked: " << SpikesCount << endl;
  cout << "--------------------" << endl;
  cout << "Maximum sound Intensity during whole time: "
       << double(MaxValueOfSound) << endl;
  cout << "--------------------" << endl;
  SoundCatagory(SoundData);
  cout << "--------------------" << endl << endl;
  /**Now after all  the calculations are done with , now free the memory and
   * return to main() and exit*/
  for (auto it = Acc_data.begin(); it != Acc_data.end(); it++) delete *it;

  for (auto it = SoundIntensity.begin(); it != SoundIntensity.end(); it++)
    delete *it;
}
