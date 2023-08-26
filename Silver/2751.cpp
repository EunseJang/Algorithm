#include <iostream>
#include <vector>
using namespace std;

// 미리 정적 전역 변수로 할당해 두는게 더 빠름
// 재귀 호출마다 벡터를 새로 할당하고 해제하는 비용 X
static vector<int> arr;
static vector<int> temp;

void merge(int left, int mid, int right) {
  int i = left; int j = mid +1; int k = left;
  temp.resize(right+1);

  // 더 작은 값 채택
  while (i <= mid && j <=right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  // 왼쪽편 남은거 그대로 가져옴
  while (i <= mid) {
    temp[k++] = arr[i++];
  }

  // 오른쪽편 남은거 그대로 가져옴
  while (j <= right) {
    temp[k++] = arr[j++];
  }

  // 원본 배열(arr)에 임시 배열(temp) 재복사
  for (int i=left;i<=right;i++) {
    arr[i] = temp[i];
  }
}

// 병합정렬
void merge_sort(int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid+1, right);
    merge (left, mid, right);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  arr.resize(N);

  for (int i=0;i<N;i++) {
    cin >> arr[i];
  }

  merge_sort(0, N-1);

  for (int i=0;i<N;i++) {
    cout << arr[i] << "\n";
  }
}