#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
  long long N, M;
  cin >> N >> M;

  vector<long long> blue(N);

  long long endSum = 0;
  long long start = -1;

	for(int i = 0; i < N; i++) {
		cin >> blue[i];
		endSum += blue[i];
		start = max(start, blue[i]);
	}

	long long end = endSum;

  while (start <= end) {
    long long mid = (start + end)/2;

    long long tempSum = 0;
    long long count = 0;

    for (int i = 0; i<N; i++) {
      if (tempSum + blue[i] > mid) {
        count ++;
        tempSum = 0;
      }
      tempSum += blue[i];
    }

    if (tempSum != 0) {
      count ++;
    }

    if (count > M) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  cout << start << "\n";
}