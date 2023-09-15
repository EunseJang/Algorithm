#include <iostream>
#include <limits>
using namespace std;

void InsertionSort(int A[], int n) {
  int value, j;

  for (int i=2; i<=n; i++) {
    value = A[i];
    j = i;

    while (A[j-1] > value) {
      A[j] = A[j-1];
      j--;
    }

    A[j]=value;
  }
}

int main() {
  int dummy = numeric_limits<int>::min();
  int A[] = {dummy, 30, 20, 40, 10, 5, 10, 30, 15};
  int size = sizeof(A) / sizeof(A[0]) - 1;

  InsertionSort(A, size);

  for (int i=1; i<=size; i++) {
    cout << A[i] << " ";
  }
}