#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<int> arr(N);
  for (int i=0; i<N; i++){
    cin >> arr[i];
  }

  for (int i=1;i<N;i++){
    for (int j=0; j<N-i;j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  for (int i=0; i<N; i++){
    cout << arr[i] << "\n";
  }
}