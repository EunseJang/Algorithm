#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string N;
  cin >> N;

  vector<int> arr(N.size());

  for (int i=0;i<N.size();i++) {
    arr[i] = N[i] - '0';
  }

  for (int i=0;i<N.size()-1;i++){
    int max_index = i;
    for (int j=i+1;j<N.size();j++) {
      if (arr[max_index] < arr[j]) {
        max_index = j; // 쵀댓값 찾고,
      }
    }
    int temp = arr[i]; // swap
    arr[i] = arr[max_index];
    arr[max_index] = temp;
  }

  for (int i=0;i<N.size();i++){
    cout << arr[i];
  }
}