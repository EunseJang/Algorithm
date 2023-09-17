#include <iostream>
#include <ctime>
using namespace std;
static int M, N;

void merge(int arr[], int size, int left, int mid, int right) {
	int tmp[size];

	int leftPtr = left;
	int rightPtr = mid + 1;
	int bufPtr = left;

	while (leftPtr <= mid && rightPtr <= right) {
		// 오른쪽 배열이 더 작을 경우
		if (arr[leftPtr] > arr[rightPtr]) {
			tmp[bufPtr++] = arr[rightPtr++];
		} 
		else { // 왼쪽 배열이 더 작을 경우
			tmp[bufPtr++] = arr[leftPtr++];
		}
	}

  if (leftPtr > mid) {
    for (int i=rightPtr; i<=right; i++)
      tmp[bufPtr++] = arr[i];
  }
  else {
    for (int i = leftPtr; i <= mid; i++)
      tmp[bufPtr++] = arr[i];
  }

  for (int i=left; i<=right; i++) {
    arr[i] = tmp[i];
  }
}

void merge_sort(int arr[], int size, int left, int right) {
	if (left < right) {
    int mid = (left + right) / 2;

    merge_sort(arr, size, left, mid);
    merge_sort(arr, size, mid + 1, right);
    merge(arr, size, left, mid, right);
	}
}

// 합집합, 교집합 구하기
void make_set(int A[], int B[]) {
	int unionSize = N+M; // 합집합 최대 크기
	int intersectionSize = (M <= N) ? M : N; // 교집합 최대 크기

	int setUnion[unionSize]; // 합집합 선언 후 초기화
	for (int i = 0; i < unionSize; i++) {
    setUnion[i] = -1;
  }
	int setIntersection[intersectionSize]; // 교집합 선언 후 초기화
	for (int i = 0; i < intersectionSize; i++) {
    setIntersection[i] = -1;
  }

	int ptrA = 0;
	int ptrB = 0;
	int unioinBufPtr = 0;
	int IntersectionBufPtr = 0;

	while (ptrA < M && ptrB < N) {
		if (A[ptrA] < B[ptrB]) { // A집합이 더 작은 경우
			setUnion[unioinBufPtr++] = A[ptrA++];
		} 
		else if (A[ptrA] > B[ptrB]) { // B집합이 더 작은 경우
			setUnion[unioinBufPtr++] = B[ptrB++];
		}
		else { // A집합, B집합 값이 동일할 경우
			setUnion[unioinBufPtr++] = A[ptrA];
			setIntersection[IntersectionBufPtr++] = A[ptrA];
			ptrA++;
			ptrB++;
		}
	}

	// 합집합만 해당!
	if (ptrA >= M) { // 집합 B가 남는 경우
		for (int i = ptrB; i<N; i++) {
			setUnion[unioinBufPtr++] = B[i];
		}
	}
	else if (ptrB >= N) { // 집합 A가 남는 경우
		for (int i = ptrA; i<M; i++) {
			setUnion[unioinBufPtr++] = A[i];
		}
	}

  cout << endl << "uni: ";
	for (int i=0; i<unionSize; i++) {
		if (setUnion[i] != -1) {
			cout << setUnion[i] << " ";
		}
  }
	cout << endl << "inter: " ;
	for (int i=0; i<intersectionSize; i++) {
		if (setIntersection[i] != -1) {
    	cout << setIntersection[i] << " ";
  	}
	}
}

int main() {
  cin >> M >> N;

  int A[M];
  int B[N];

  // random 함수 사용
  srand((unsigned int) time(NULL));

	// 집합 A 설정
	for (int i=0; i<M; i++) {
		A[i] = rand() % 100; // random 범위 0 ~ 99

		for (int j=0; j<i; j++) {
			if (A[i] == A[j]) {
				i--; // 집합이니까 중복되면 안됨
				break; // 중복되면 다시 random값 설정
			}
		}
	}

	// 집합 B 설정
	for (int i=0; i<N; i++) {
		B[i] = rand() % 100; // random 범위 0 ~ 99

		for (int j=0; j<i; j++) {
			if (B[i] == B[j]) {
				i--; // 집합이니까 중복되면 안됨
				break; // 중복되면 다시 random값 설정
			}
		}
	}

	// A와 B는 정렬되어있음을 전제로 함
	merge_sort(A, M, 0, M-1);
	merge_sort(B, N, 0, N-1);

	cout << "A: ";
	for(int i =0; i<M; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	cout << "B: ";
	for(int i=0; i<N; i++) {
		cout << B[i] << " ";
	}

	// 합집합, 교집합 만들기
	make_set(A, B);
	cout << endl;

	return 0;
}