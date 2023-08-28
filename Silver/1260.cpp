#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

static vector<vector<int>> graph;
static vector<bool> visited;
static queue<int> bfsQueue;
void DFS(int node);
void BFS(int node);

int main() {
  int N, M, V;
  cin >> N >> M >> V;

  graph.resize(N+1);
  visited = vector<bool> (N+1, false);
  
  for (int i=1;i<=M;i++) {
    int n1, n2;
    cin >> n1 >> n2;

    graph[n1].push_back(n2);
    graph[n2].push_back(n1);
  }

  // 방문할 노드가 여러개면 작은 노드 먼저 방문
  for (int i=1; i<=N; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  DFS(V);
  cout << "\n";
  fill (visited.begin(), visited.end(), false); // bfs 진행을 위해 다시 초기화
  
  BFS(V);
  cout << "\n";
}

// DFS
void DFS(int node) {
  cout << node << " ";
  visited[node] = true;

  for (int n : graph[node]) {
    if (!visited[n]) {
      DFS(n);
    } 
  }
}

// BFS
void BFS(int node) {
  bfsQueue.push(node);
  visited[node] = true;

  while (!bfsQueue.empty()) {
    int result = bfsQueue.front();
    bfsQueue.pop();
    cout << result << " ";

    for (int n : graph[result]) {
      if (!visited[n]) {
        bfsQueue.push(n);
        visited[n] = true;
      }
    }
  }
}