/*******************************
* Автор:   Сатин Владимир     *
* Задание: Функции            *
* Вариант: 10                 *
*******************************/

#include <iostream>
#include <vector>

using namespace std;

// Returns false and leaves result unchanged if there are no positive elements.
bool positiveMean(const vector<double>& values, double& result) {
  double sum = 0.0;
  int positiveCount = 0;

  for (size_t elementIndex = 0; elementIndex < values.size(); ++elementIndex) {
    if (values[elementIndex] > 0.0) {
      sum += values[elementIndex];
      ++positiveCount;
    }
  }

  if (positiveCount == 0) {
    return false;
  }

  result = sum / positiveCount;
  return true;
}

bool isWithinLimit(const vector<double>& values, double limit) {
  for (size_t elementIndex = 0; elementIndex < values.size(); ++elementIndex) {
    if (values[elementIndex] > limit || values[elementIndex] < -limit) {
      return false;
    }
  }

  return true;
}

int main() {
  int maxSize = 100;
  double maxAbsValue = 1000.0;
  int sizeR;
  int sizeL;
  vector<double> valuesR;
  vector<double> valuesL;
  double meanR = 0.0;
  double meanL = 0.0;
  bool hasMeanR;
  bool hasMeanL;

  cout << "Enter size of R (from 1 to " << maxSize << "): ";
  cin >> sizeR;
  if (sizeR < 1 || sizeR > maxSize) {
    cout << "INVALID\n";
    return 0;
  }

  valuesR.resize(sizeR);
  cout << "Enter " << sizeR << " elements of R: ";
  for (int elementIndex = 0; elementIndex < sizeR; ++elementIndex) {
    cin >> valuesR[elementIndex];
  }

  cout << "Enter size of L (from 1 to " << maxSize << "): ";
  cin >> sizeL;
  if (sizeL < 1 || sizeL > maxSize) {
    cout << "INVALID\n";
    return 0;
  }

  valuesL.resize(sizeL);
  cout << "Enter " << sizeL << " elements of L: ";
  for (int elementIndex = 0; elementIndex < sizeL; ++elementIndex) {
    cin >> valuesL[elementIndex];
  }

  if (!isWithinLimit(valuesR, maxAbsValue) || !isWithinLimit(valuesL, maxAbsValue)) {
    cout << "INVALID\n";
    return 0;
  }

  hasMeanR = positiveMean(valuesR, meanR);
  hasMeanL = positiveMean(valuesL, meanL);

  if (hasMeanR) {
    cout << "Mean of positive elements of R: " << meanR << "\n";
  }
  else {
    cout << "R has no positive elements\n";
  }

  if (hasMeanL) {
    cout << "Mean of positive elements of L: " << meanL << "\n";
  }
  else {
    cout << "L has no positive elements\n";
  }

  return 0;
}