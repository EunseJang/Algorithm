#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (int i=0; i<N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  int M;
  cin >> M;

  vector<int> check(M);
  for (int i=0; i<M; i++) {
    cin >> check[i];
  }

  for (int i=0; i<M; i++) {
    int num = check[i];

    int start = 0;
    int end = N - 1;

    bool find = false;
    while (start <= end) {
      int mid = (start + end) / 2;
      
      if (num > A[mid]) {
        start = mid + 1;
      } 
      else if (num < A[mid]) {
        end = mid - 1 ;
      } 
      else {
        cout << 1 << "\n";
        find = true;
        break;
      }
    }

    if (!find) {
      cout << 0 << "\n";
    }
  }
}