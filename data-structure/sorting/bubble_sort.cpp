#include <iostream>
using namespace std;

void Swap(int &a, int &b);
void BubbleSort(int A[], int n);

int main() {
  int A[] = {0, 30, 20, 40, 10, 5, 10, 30, 15};
  int n = sizeof(A) / sizeof(A[0]) - 1;

  BubbleSort(A, n);

  for (int i=1; i<=n; i++) {
    cout << A[i] << " ";
  }
}

void Swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void BubbleSort (int A[], int n) {
  bool sorted = false;

  while (!sorted) {
    sorted = true;

    for (int i=1; i<=n; i++) {
      if (A[i-1] > A[i]) {
        Swap(A[i-1], A[i]);
        sorted = false;
      }
    }
  }
}