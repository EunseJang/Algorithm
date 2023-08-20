#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<pair<int,int>> A(N);

  for (int i=0;i<N;i++){
    cin >> A[i].first; // 10 1 5 2 3 (값)
    A[i].second = i;   // 0 1 2 3 4 (인덱스)
  }

  sort(A.begin(), A.end());
  // 1 3 4 2 0 (인덱스)
  // 1 2 3 5 10 (값)

  int max = 0;

  for (int i =0;i<N;i++){
    if (max < A[i].second - i){
      max = A[i].second - i;
    }
  }

  cout << max + 1 << "\n";
}