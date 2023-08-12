#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N = 0;
  int M = 0;

  cin >> N >> M;
  int arr[100000];
  int sum[100000];

  for (int i =0; i<N; i++){
    cin >> arr[i];
  }

  sum[0] = 0;
  for (int i =1; i<=N; i++){
    sum[i] = sum[i-1] + arr[i-1];
  }

  int i = 0;
  int j = 0;

  for (int k=0; k<M; k++){
    cin >> i >> j;
    cout << sum[j] - sum[i-1] << "\n";
  }
}