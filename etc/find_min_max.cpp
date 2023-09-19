#include <iostream>
using namespace std;

void find_min_max(int A[], int size, int minTmp, int maxTmp) {
  int small;
  int large;

  for (int i=1; i < size; i+=2) {
    if (A[i] < A[i+1]) {
      small = A[i];
      large = A[i+1];
    } else {
      small = A[i+1];
      large = A[i];
    }
    if (small < minTmp) minTmp = small;
    if (large > maxTmp) maxTmp = large;
  }

  cout << "min: " << minTmp << endl;
  cout << "max: " << maxTmp << endl;
}

int main() {
  int A[] = { 17, 8, 21, 35, 48, 2, 11 };
  int size = sizeof(A) / sizeof(A[0]);

  int minTmp = A[0];
  int maxTmp = A[0];

  find_min_max(A, size, minTmp, maxTmp);

  return 0;
}