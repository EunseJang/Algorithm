#include <iostream>
using namespace std;

int checkPw[4]; // A:0, C:1, G:2, T:3
int myPw[4] = {0}; // 비교할 A C G T 배열
int checkCount = 0 ; // 4되면 해당 비밀번호는 가능

void pwAdd(char c); // 문자 추가
void pwRemove(char c); // 문자 제거

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int S, P;
  cin >> S >> P;

  string str;
  cin >> str;

  for (int i=0;i<4;i++){
    cin >> checkPw[i];

    if(checkPw [i] == 0) { // 0이면 무조건 조건 충족하니까
      checkCount++;
    }
  }

  // 1. 첫번째 문자열은 직접 처리
  for (int i=0;i<P;i++){
    pwAdd(str[i]);
  }

  int answer = 0;
  if (checkCount == 4) { // ACGT 조건이 일치하면 count
    answer++;
  }


  // 2. 슬라이딩하면서 새로 추가되는 부분, 삭제되는 부분 설정
  for (int back=P ; back<S ; back++){
    int front = back-P;

    pwAdd(str[back]); // 슬라이딩 하면서 추가되는 부분 처리
    pwRemove(str[front]); // 슬라이딩 하면서 삭제되는 부분 처리

    if (checkCount == 4){ // 처리 후 조건 만족하면 count
      answer++;
    }
  }
  cout << answer << "\n";
}

void pwAdd(char c){
  switch(c){
    case 'A':
      myPw[0]++;
      if(myPw[0] == checkPw[0]){
        checkCount ++;
      }
      break;
    case 'C':
      myPw[1]++;
      if(myPw[1] == checkPw[1]){
        checkCount ++;
      }
      break;
    case 'G':
      myPw[2]++;
      if(myPw[2] == checkPw[2]){
        checkCount ++;
      }
      break;
    case 'T':
      myPw[3]++;
      if(myPw[3] == checkPw[3]){
        checkCount ++;
      }
      break;     
   }
}

void pwRemove(char c){
  switch(c) {
    case 'A':
      if(myPw[0] == checkPw[0]) {
        checkCount--;
      }
      myPw[0]--;
      break;
    case 'C':
      if(myPw[1] == checkPw[1]){
        checkCount --;
      }
      myPw[1]--;
      break;
    case 'G':
      if(myPw[2] == checkPw[2]){
        checkCount --;
      }
      myPw[2]--;
      break;
    case 'T':
      if(myPw[3] == checkPw[3]){
        checkCount --;
      }
      myPw[3]--;
      break;     
   }
}