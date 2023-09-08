#include <iostream>
using namespace std;

void ShellSort(int A[], int n) {
  int h = 1;
  do {
    h = 3 * h + 1;
  } while (h < n);

  do {
    h /= 3;

    for (int i=h; i<n; i++) {
      int value = A[i];
      int j = i;

      while (A[j-h] > value) {
        A[j] = A[j-h];
        j -= h;

        if (j < h) {
          break;
        }
      }

      A[j] = value;
    }
  } while (h > 1);
}

int main() {
  int A[] = {30, 50, 15, 60, 35, 10, 40, 45, 5, 25, 55, 20};
  int size = sizeof(A) / sizeof(A[0]);

  ShellSort(A, size);

  for (int i=0; i<size ; i++) {
    cout << A[i] << " ";
  }
}