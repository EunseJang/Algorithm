#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void InsertionSort(int A[], int n) {
  int i, j, minIdx;

  for (int i=0; i<n-1; i++) {
    minIdx = i;
    for (j=minIdx+1; j<n; j++){
      if (A[minIdx] > A[j]) {
        minIdx = j;
      }
    }

    if (minIdx != i) {
      Swap(A[i], A[minIdx]);
    }
  }
}

int main() {
  int A[] = {30, 20, 40, 10, 5, 10, 30, 15};
  int size = sizeof(A)/sizeof(A[0]);

  InsertionSort(A, size);

  for (int i = 0; i<size; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}