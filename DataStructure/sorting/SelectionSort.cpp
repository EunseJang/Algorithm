#include <iostream>
using namespace std;

void InsertionSort(int A[], int n){
  for (int i=1; i<=n; i++) {
    int value = A[i];
    int j = i;

    while (j > 1 && A[j-1] > value) {
      A[j] = A[j-1];
      j--;
    }

    A[j] = value;
  }
}

int main() {
  int A[] = {0, 30, 20, 40, 10, 5, 10, 30, 15}; // 0은 dummy값
  int n = sizeof(A)/sizeof(A[0])-1; // dummy값 제외 원소 개수

  InsertionSort(A, n);

  for (int i = 1; i <= n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}