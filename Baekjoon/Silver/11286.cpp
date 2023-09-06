#include <iostream>
#include <queue>
using namespace std;

struct Compare { // 우선순위 큐 조건
  bool operator() (int a, int b){
    int a_abs = abs(a);
    int b_abs = abs(b);

    if (a_abs == b_abs) { // 절댓값이 같을 경우
      return a>b; // 더 작은 값(음수) 츨략
    } else {
      return a_abs > b_abs; // 절댓값이 더 작은 값 출력
    }
  }
};

int main() {
  int N;
  cin >> N;

  // 우선순위 큐
  priority_queue<int, vector<int>, Compare> myQueue;

  for (int i=0;i<N;i++) {
    int input;
    cin >> input;

    if (input == 0) {
      if (myQueue.empty()) {
        cout << 0 << "\n";
      }
      else {
        cout << myQueue.top() << "\n";
        myQueue.pop();
      }
    }
    else {
      myQueue.push(input);
    }
  }
}