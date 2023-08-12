#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> arr(N, 0);

  for (int i=0;i<N;i++){
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  int count = 0;

  for (int k=0;k<N;k++) {
    int startIdx = 0;
    int endIdx = N-1;
    int find = arr[k];
    while(startIdx < endIdx) {
      if(arr[startIdx] + arr[endIdx] < find) {
        startIdx ++;
      }
      else if (arr[startIdx] + arr[endIdx] > find) {
        endIdx--;
      }
      else {
        if (startIdx != k && endIdx != k){
          count ++;
          break;
        }
        else if (startIdx == k) {
          startIdx ++;
        }
        else if (endIdx == k) {
          endIdx --;
        }
      }
    }
  }

  cout << count << "\n";

  return 0;
}