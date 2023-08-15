#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> check(N);
  for (int i = 0; i < N; i++) {
    cin >> check[i];
  }

  stack<int> index;
  vector<int> ans(N, -1);

  index.push(0);

  for (int i = 1; i < N; i++) {
    while (!index.empty() && check[index.top()] < check[i]) {
      ans[index.top()] = check[i];
      index.pop();
    }
    index.push(i);
  }

  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  
  cout << "\n";
  return 0;
}
