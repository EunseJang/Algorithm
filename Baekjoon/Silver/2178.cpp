#include <iostream>
#include <queue>
using namespace std;

// 좌표 순서: 위 -> 왼 -> 아래 -> 오 (시계 반대 방향)
static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};
static int map[101][101];
static bool visited[101][101] = {false};
static int N, M;
void BFS (int x, int y);

int main() {
  cin >> N >> M;

  for (int i=1; i<=N; i++) {
    string str;
    cin >> str;
    for (int j=1; j<=M; j++) {
      map[i][j] = str[j-1] - '0';
    }
  }

  BFS(1, 1); // (1,1) 좌표에서 출발
  cout << map[N][M] << "\n";
}

void BFS (int x, int y) {
  visited[x][y] = true;
  queue<pair<int, int>> bfsQueue;
  bfsQueue.push(make_pair(x,y));

  int tmp[2]; // 현재 위치 좌표 확인용
  while (!bfsQueue.empty()) {
    tmp[0] = bfsQueue.front().first; // x좌표
    tmp[1] = bfsQueue.front().second; // y좌표

    bfsQueue.pop();
    
    for(int i=0; i<4; i++) {
      int m = tmp[0] + dx[i]; // x 좌표
      int n = tmp[1] + dy[i]; // y 좌표

      if (m>=1 && n>=1 && m<=N && n<=M) { // 좌표 유효성 검사
        if(map[m][n] == 1 && !visited[m][n]) {// 방문 하지 않는 좌표 중에서 값이 1인 좌표
          visited[m][n] = true;
          map[m][n] = map[tmp[0]][tmp[1]] + 1; // 좌표 count;
          bfsQueue.push(make_pair(m, n));
        }
      }
    }
  }
}