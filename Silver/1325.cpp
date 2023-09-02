#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
static int count;
static int N, M;

void DFS(int node);

int main() {
  cin >> N >> M;

  graph.resize(N+1);
  visited = vector<bool> (N+1, false);

  for(int i=0; i<M; i++) {
    int A, B;
    cin >> A >> B;

    graph[B].push_back(A);
  }

  vector<int> result (N, 0);

  for (int i = 1; i <= N; i++) {
    // visited 초기화
    fill(visited.begin(), visited.end(), false);
    
    count = 0;
    DFS(i);
    result[i - 1] = count;
  }

  int maxNum = 0;
  for (int i=0; i<N; i++) {
    maxNum = max(maxNum, result[i]);
  }

  for (int i=0; i<N; i++) {
    if (result[i] == maxNum) {
      cout << i+1 << " ";
    }
  }
}

void DFS(int node) {
  visited[node] = true;

  for(int n : graph[node]) {
    if (!visited[n]) {
      count++;
      DFS(n);
    }
  }
}