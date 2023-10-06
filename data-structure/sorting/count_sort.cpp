#include <iostream>
using namespace std;

void CountSort(int A[], int n, int B[], int k) {
  // 누적합 배열 선언
  int *N = new int[k+1];

  // 배열 N 초기화
  for (int i=0; i<=k; i++) {
    N[i] = 0;
  }

  // 배열 A의 원소 개수 세기
  for (int i=0; i<n; i++) {
    N[A[i]]++;
  }

  // 배열 A값 개수의 누적합 계산
  for (int i=1; i<=k; i++) {
    N[i] += N[i-1];
  }

  // 정렬 후 배열 B에 저장
  for (int i=n-1; i>=0; i--) {
    B[N[A[i]]-1] = A[i];
    N[A[i]]--;
  }

  delete[] N; // 동적 배열 메모리 해제
}

int main() {
  int A[] = {5, 3, 4, 1, 5, 4, 1, 4};
  int n = sizeof(A) / sizeof(A[0]);

  // 계수 정렬 조건: 입력 배열 값이 작은 범위 내에서만 변화하는 경우
  // 키 값 범위 = [1, k]
  int k = A[0];
  for (int i=0; i<n; i++) {
    if (A[i] > k) {
      k = A[i]; // A배열 원소 중 최대 값으로 키 값 범위설정 설정
    }
  }

  int B[n]; // 정렬 결과를 저장할 배열 B

  CountSort(A, n, B, k);

  for (int i=0; i<n; i++) {
    cout << B[i] << " ";
  }

  cout << endl;
  return 0;
}