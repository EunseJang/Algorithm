#include <iostream>
#include <vector>

using namespace std;

// 동전이 가짜인지 확인하는 함수
int findFakeCoin(vector<int> coins, int left, int right) {
  if (left == right) { // 동전이 한 개만 남았으면 그것이 가짜 동전
    return left;
  }
  else {
    if ((right - left + 1) % 2 == 0) { // 나눈 동전이 짝수 개인 경우
      int mid = (left + right) / 2;

      int leftSum = 0;
      int rightSum = 0;

      for (int i = left; i <= mid; i++) {
        leftSum += coins[i];
      }
      for (int i = mid + 1; i <= right; i++) {
        rightSum += coins[i];
      }

      // 왼쪽과 오른쪽 그룹의 총 무게를 비교
      if (leftSum < rightSum) { // 왼쪽이 더 가벼움
        return findFakeCoin(coins, left, mid);
      } 
      else if (leftSum > rightSum) { // 오른쪽이 더 가벼움
        return findFakeCoin(coins, mid + 1, right);
      } 
      else {
        return -1; // 가짜동전 없음
      }
    }
    else { // 나눈 동전이 홀수 개인 경우
      int mid = (left + right) / 2;

      // 왼쪽과 오른쪽 그룹의 총 무게를 비교
      int leftSum = 0;
      int rightSum = 0;

      for (int i = left; i < mid; i++) {
        leftSum += coins[i];
      }
      for (int i = mid + 1; i <= right; i++) {
        rightSum += coins[i];
      }

      if (leftSum < rightSum) { // 왼쪽이 더 가벼움
        return findFakeCoin(coins, left, mid - 1);
      } 
      else if (leftSum > rightSum) { // 오른쪽이 더 가벼움
        return findFakeCoin(coins, mid + 1, right);
      } 
      else {
        return mid; // 왼쪽 오른쪽 같으면 나머지 한개가 가짜동전
      }
    }
  }
}

int main() {
  vector<int> coins (100, -1);

  int fakeCoinIdx;
  cin >> fakeCoinIdx; // 가짜 동전 위치 입력

  for (int i=0; i<100;i++) {
    if (i==fakeCoinIdx) {
      coins[i]=0;
    } else {
      coins[i]=1;
    }
  }

  int fakeCoinIndex = findFakeCoin(coins, 0, coins.size() - 1);

  if (fakeCoinIndex != -1) {
    cout << fakeCoinIndex << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
