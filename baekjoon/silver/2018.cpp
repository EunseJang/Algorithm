#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  int startIdx = 1;
  int endIdx = 1;
  int sum = 1;
  int count = 1;

  while (endIdx != N) { // 마지막 인덱스가 N이여야 종료
    if (sum > N) {
      sum = sum - startIdx;
      startIdx ++;
    }
    else if (sum < N) {
      endIdx++;
      sum = sum + endIdx;
    }
    else { // sum == N인 경우
      count ++;
      endIdx ++;
      sum = sum + endIdx;
    }
  }

  cout << count << "\n";

  return 0;
}