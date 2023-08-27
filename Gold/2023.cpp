#include <iostream>
#include <vector>
using namespace std;

void DFS(int num, int jarisu);
bool IsPrime (int num);
static int N;

int main() {
  cin >> N;

  // 한 자릿수 소수
  int singlePrime[] = {2,3,5,7};
  for (int prime : singlePrime) {
    DFS(prime,1); // 한 자릿수 소수부터 깊이우선탐색 진행
  }
}

void DFS(int num, int count) {
  if(N == count) {
    if(IsPrime(num)) { // 소수인 경우 출력
      cout << num << "\n";
    }
    return;
  }

  for (int i=1;i<10;i++){
    if (i%2 != 0) { // 2로 나눠지면 무조건 소수가 아니므로
      if (IsPrime(num * 10 + i)) { 
        DFS(num * 10 + i, count+1);
      }
    }
  }
}

// 소수 판별
bool IsPrime(int num) {
  for(int i=2;i*i<=num;i++){
    if(num%i == 0){
      return false;
    }
  }
  return true;
}