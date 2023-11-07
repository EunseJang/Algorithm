#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000; // 최대 문자열 길이

// 3값 중 최소값을 찾는 함수 별도 구현
int min_three(int a, int b, int c) {
    return min(min(a, b), c);
}

int EditDist(int n, char X[], int m, char Y[], int ins, int del, int chg) {
/*
  [입력]
  1) X[1..n], Y[1..m] : 문자 배열
  2) ins : 삽입 비용
  3) del : 삭제 비용
  4) chg : 변경 비용

  [출력] 편집 거리
*/
  int D[n+1][m+1];
  D[0][0] = 0;

  for (int i = 1; i < n + 1; i++) {
    D[i][0] = D[i - 1][0] + del; // 첫 열(수직 방향) 초기화 (삭제)
  }
  for (int i = 1; i < m + 1; i++) {
    D[0][i] = D[0][i - 1] + ins; // 첫 행(수평 방향) 초기화 (삽입)
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      int c = (X[i - 1] == Y[j - 1]) ? 0 : chg;
      D[i][j] = min_three(D[i - 1][j] + del, D[i][j - 1] + ins, D[i - 1][j - 1] + c);
    }
  }

  // 완성된 D 테이블 출력
  cout << endl << "[D table]" << endl;
  for (int i=0; i<n+1; i++) {
    for (int j=0; j<m+1; j++) {
      cout << D[i][j] << " ";
    }
    cout << endl;
  }

  return D[n][m];
}

int main() {
  // // 삽입, 삭제, 대체 편집 거리는 1로 설정
  int ins = 1; 
  int del = 1;
  int chg = 1;

  char X[MAX], Y[MAX];
  cout << "origin string(S) : ";
  cin >> X;
  cout << "change string(T) : ";
  cin >> Y;

  int n = strlen(X);
  int m = strlen(Y);

  int result = EditDist(n, X, m, Y, ins, del, chg);

  cout << "Edit distanc : " << result << endl;

  return 0;
}
