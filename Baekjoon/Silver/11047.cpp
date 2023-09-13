#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, K;

  cin >> N >> K;

  vector<int> coins(N);
  for(int i=0; i<N; i++) {
    cin >> coins[i];
  }

  int count = 0;
  for (int i=N-1; i>=0; i--) { // 단위가 큰 돈부터 내림차순
    if (coins[i] <= K) {
      count += (K/coins[i]); // 동전 개수 세기
      K = K%coins[i]; // 남은 돈
    }
  }
  cout << count << endl;
}
