#include <iostream>
using namespace std;

int main() {
  int N = 0;
  string numbers;

  cin >> N;
  cin >> numbers;

  int sum = 0;

  for (int i =0; i<numbers.length(); i++) {
    sum += numbers[i] - '0'; // 문자열을 숫자로 바꿈
  }

  cout << sum << "\n";
}