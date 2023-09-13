#include <iostream>
#include <queue>
using namespace std;

// 우선순위를 내림차순으로 설정
struct Compare {
  bool operator()(int a, int b) {
    return a > b;
  }
};

int main() {
  int N;
  cin >> N;

  priority_queue<int, vector<int>, Compare> pq;
  for (int i=0; i<N; i++) {
    int num;
    cin >> num;

    pq.push(num);
  }

  int tmp = 0;
  int sum = 0;

  // 1. 가장 작은 두 수 더하고,
  // 2. 더한 값 다시 큐에 넣고,
  // 3. 또 가장 작은 수 두개 더한다.
  // 계속해서 1 ~ 3 과정 반복
  while (pq.size() > 1) {
    int a = pq.top();
    pq.pop();

    int b = pq.top();
    pq.pop();

    tmp = (a+b);
    sum += tmp;

    pq.push(tmp);
  }
  cout << sum << endl;
}