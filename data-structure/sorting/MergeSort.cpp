#include <iostream>
using namespace std;

const int NUM_OF_KEYS = 10;

void Merge(int A[], int left, int mid, int right) {
  int B[NUM_OF_KEYS]; // 임시 배열
  int i, leftPtr, rightPtr, bufPtr;

  leftPtr = left;
  rightPtr = mid + 1;
  bufPtr = left; // 임시 배열 B의 pointer

  while (leftPtr <= mid && rightPtr <= right) {
    if (A[leftPtr] <= A[rightPtr]) {
      B[bufPtr++] = A[leftPtr++];
    } else {
      B[bufPtr++] = A[rightPtr++];
    }
  }

  if (leftPtr > mid) {
    for (int i=rightPtr; i<=right; i++)
      B[bufPtr++] = A[i];
  }
  else {
    for (int i = leftPtr; i <= mid; i++)
      B[bufPtr++] = A[i];
  }

  for (int i=left; i<=right; i++) {
    A[i] = B[i];
  }
}

void MergeSort(int A[], int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;

    MergeSort(A, left, mid);
    MergeSort(A, mid + 1, right);
    Merge(A, left, mid, right);
  }
}

int main() {
  int A[] = {30, 20, 40, 35, 5, 50, 45, 10, 25, 15};
  int size = sizeof(A) / sizeof(A[0]);

  MergeSort(A, 0, size - 1);

  for (int i = 0; i < size; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}