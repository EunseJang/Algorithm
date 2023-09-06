#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> people(N);

  for (int i=0;i<N;i++) {
    cin >> people[i];
  }

  int index = -1;
  int temp = 0;
  
  for (int i=1;i<N;i++) { // 삽입 정렬
    int now = people[i];
    for (int j=0;j<=i; j++){
      if(now < people[j]) {
        index = j;
        temp = people[j]; 

        for (int k = i; k > index; k--) { // 인덱스 값 조정
          people[k] = people[k-1];
        }
        people[index] = now;
        break;
      } 
    }
  }

  vector<int> sum(N);
  sum[0] = people[0];
  int total = 0;
  for (int i=1;i<N;i++) {
    sum[i] = sum[i-1] + people[i];
    total += sum[i];
  }

  cout << total + people[0] << "\n";
}