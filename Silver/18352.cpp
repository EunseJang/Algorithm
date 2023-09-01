#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static vector<vector<int>> graph;
static vector<int> visited;
static int N, M, K, X;

void BFS(int node);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K >> X;
  
  graph.resize(N+1);
  visited = vector<int> (N+1, -1);

  for (int i=1;i<=M;i++) {
    int A, B;
    cin >> A >> B;

    graph[A].push_back(B);
  }

  BFS(X);

  bool check = false;

  for(int i=1;i<=N;i++) {
    if (visited[i] == K) {
      check = true;
      cout << i << "\n";
    }
  }
  
  if (!check) {
    cout << -1 << "\n";
  }
}

void BFS(int node) {
  visited[node] = 0;
  
  queue<int> bfsQ;
  bfsQ.push(node);

  while (!bfsQ.empty()) {
    int now = bfsQ.front();
    bfsQ.pop();
    
    for(int i=0; i<graph[now].size(); i++) {
      int next = graph[now][i];

      if (visited[next] == -1) {
        visited[next] = visited[now] +1;
        bfsQ.push(next);
      }
    }
  }
}