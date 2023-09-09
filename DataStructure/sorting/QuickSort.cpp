#include <iostream>
#include <limits>
using namespace std;

void Swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int Partition(int A[], int left, int right) {
  int partElem, value;
  partElem = left;
  value = A[partElem];

  do {
    while (A[++left] < value);
    while (A[--right] > value);

    if (left < right) {
      Swap(A[left], A[right]);
    } else {
      break;
    }
  } while (1);

  A[partElem] = A[right];
  A[right] = value;

  return right; // partition값의 index
}

void QuickSort(int A[], int left, int right) {
  int k;

  if (left < right) {
    k = Partition(A, left, right+1); // 전체 배열 범위 (dummy값 포함)
    QuickSort(A, left, k-1);
    QuickSort(A, k+1, right);
  }
}

int main () {
  int dummy = numeric_limits<int>::max();
  int A[] = {30, 20, 40, 35, 5, 10, 45, 50, 25, 15, dummy};
  int size = sizeof(A)/sizeof(A[0]);

  QuickSort(A, 0, size-1); // dummy값 제외

  for (int i=0; i<size-1; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}