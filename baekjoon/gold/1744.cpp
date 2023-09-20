#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static int N;

// case 나누기
// 1. 0인 경우
// 2. 음수인 경우
// 3. 양수인 경우
// 예외) 음수 홀수개인 경우 0이랑 곱해서 없애기
// 예외) 1이 존재하면 묶지말고 개별로 더하기

int positiveSum (vector<int>& arr, int positiveIdx) {
  int sum = 0;
  if ((N-positiveIdx) % 2 == 0) { // 짝수개인 경우
    for (int i = N-1; i >= positiveIdx; i--) {
      if (arr[i] != 1 && arr[i-1] != 1) {
        int tmp = arr[i] * arr[i-1];
        sum += tmp;
        i--;
      } else {
        int tmp = arr[i] + arr[i-1];
        sum += tmp;
        i--;
      }
    }
  } 
  else { // 홀수인 경우
    for (int i = N-1; i > positiveIdx; i--) {
      if (arr[i] != 1 && arr[i-1] != 1) {
        int tmp = arr[i] * arr[i-1];
        sum += tmp;
        i--;
      } else {
        int tmp = arr[i] + arr[i-1];
        sum += tmp;
        i--;
      }
    }
    sum += arr[positiveIdx];
  }
  return sum;
}

int negativeSum (vector<int>& arr, int negativeIdx, bool isZero) {
  int sum = 0;
  if ((negativeIdx+1) % 2 == 0) { // 짝수개인 경우
    for (int i = 0; i <= negativeIdx; i++) {
      int tmp = arr[i] * arr[i+1];
      sum += tmp;
      i++;
    }
  } 
  else { // 홀수인 경우
    for (int i = 0; i < negativeIdx; i++) {
      int tmp = arr[i] * arr[i+1];
      sum += tmp;
      i++;
    }
    if (!isZero) {
      sum += arr[negativeIdx];
    }
  }
  return sum;
}

int main() {
  cin >> N;

  vector<int> arr(N);
  for (int i=0; i<N; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  // 0이 있는 경우, 없는 경우
  // 음수만 있는 경우, 양수만 있는 경우, 둘다 있는 경우
  int zeroIdx;
  bool isZero = false;
  for (int i=0; i<N; i++) {
    if (arr[i] == 0) {
      isZero = true;
      zeroIdx = i; // 0을 갖는 인덱스 값
      break;
    } 
  }

  int positiveIdx = -1;
  int negativeIdx = -1;
  int sum = 0;

  if (isZero) { // 0이 존재하는 경우
    sum = 0;

    // 음수만 존재
    if (zeroIdx == N-1) {
      negativeIdx = zeroIdx - 1;
      sum = negativeSum(arr, negativeIdx, true);
      cout << sum << endl;
      return 0;
    }
    // 양수만 존재
    else if (zeroIdx == 0) {
      positiveIdx = zeroIdx + 1;
      sum = positiveSum(arr, positiveIdx);
      cout << sum << endl;
      return 0;
    }
    // 음수, 양수 모두 존재
    else {
      positiveIdx = zeroIdx + 1;
      negativeIdx = zeroIdx - 1;
      int positive = positiveSum(arr, positiveIdx);
      cout << positive + negative << endl;
      return 0;
    }
  } 
  else { // 0이 존재하지 않는 경우
    int idx = -1;
    bool isNegative = false;
    for (int i=0; i<N; i++){
      if (arr[i] < 0) {
        idx = i;
        isNegative = true;
      }
    }

    // 음수만 존재
    if (idx == N-1) {
      int sum = negativeSum(arr, idx, false);
      cout << sum << endl;
      return 0;
    }
    // 양수만 존재
    else if (isNegative == false) {
      int sum = positiveSum(arr, 0);
      cout << sum << endl;
      return 0;
    }
    // 둘다 존재
    else {
      int positive = positiveSum(arr, idx + 1);
      int negative = negativeSum(arr, idx, false); 
      cout << positive + negative << endl;
      return 0;
    }
  }
}