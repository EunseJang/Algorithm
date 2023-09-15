#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> graph;
static vector<bool> visited;
static bool success = false;
void DFS(int node, int depth);

int main() {
  int N, M;
  cin >> N >> M;

  graph.resize(N);
  visited = vector<bool>(N, false);

  for (int i=0; i<M; i++) {
    int start, end;
    cin >> start >> end;

    graph[start].push_back(end);
    graph[end].push_back(start);
  }

  for (int i=0;i<N;i++){
    if (!success) {
      DFS(i, 0);
    }
  }

  if (success) {
    cout << 1 << "\n";
  } else {
    cout << 0 << "\n";
  }

  return 0;
}

void DFS (int node, int depth) {
  if(depth >= 4) { // 문제에서 말하는 친구 관계를 가지기 위한 조건
    success = true;
    return;
  }

  visited[node] = true;

  for (int i : graph[node]) {
    if (!visited[i]) {
      DFS(i, depth + 1);
    }
  }

  // 만약 depth >= 4인 경로를 찾지 못하면, 현재 경로가 실패한 것으로 판단
  // 따라서 다른 경로를 탐색할 수 있도록 백트래킹하기 위해 다시 false로 설정
  visited[node] = false;
}