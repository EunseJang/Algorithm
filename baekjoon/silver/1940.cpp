#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N;
  cin >> M;

  vector<int> arr(N,0);
  for (int i=0; i<N; i++){
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  int startIdx=0;
  int endIdx=N-1;
  int count =0;

  while(startIdx < endIdx) {
    if(arr[startIdx] + arr[endIdx] > M) {
      endIdx--;
    }
    else if (arr[startIdx] + arr[endIdx] < M) {
      startIdx++;
    }
    else {
      startIdx ++;
      endIdx --;
      count ++;
    }
  }

  cout << count << '\n';

  return 0;
}