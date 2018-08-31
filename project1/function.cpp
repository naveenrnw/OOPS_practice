#include "function.h"

/**This file has all the function definations which were decleared in the
 * function.h*/

int Spikes(const vector<double> &v) {
  int count = 0;
  double current = 0;
  double pre = -1000;
  double nxt = 20;

  double sum = std::accumulate(v.begin(), v.end(), 0.0);
  double mean = sum / v.size();

  double sq_sum = std::inner_product(v.begin(), v.end(), v.begin(), 0.0);
  double stdev = std::sqrt(sq_sum / v.size() - mean * mean);

  double thr_hold = 2 * stdev - mean;
  // print(thr_hold)

  for (auto rows : v) {
    if (current >= nxt && current >= pre && current >= int(thr_hold - 1) &&
        current > 12)
      count++;
    pre = current;
    current = nxt;
    nxt = rows;
  }
  return count;
}

void SoundCatagory(vector<double> &SoundData) {
  map<int, string> m;
  m[0] = "Barely audible";
  m[1] = "Quite Home Sound";
  m[2] = "Normal sound like birds air etc.";
  m[3] = "Normal Surrounding sound in office, restaurents etc.";
  m[4] = "Sound in factory and public places.";
  m[5] = "harmful Sound level";

  vector<int> Tracker(6, 0);

  for (auto it : SoundData) {
    if (it < 30) {
      Tracker[0]++;
    } else if (it >= 30 && it < 40) {
      Tracker[1]++;
    } else if (it >= 40 && it < 50) {
      Tracker[2]++;
    } else if (it >= 50 && it < 60) {
      Tracker[3]++;
    } else if (it >= 60 && it < 80) {
      Tracker[4]++;
    } else {
      Tracker[5]++;
    }
  }
  int Index =
      distance(Tracker.begin(), max_element(Tracker.begin(), Tracker.end()));
  cout << m[Index] << endl;
  // cout<<Index<<endl;
}