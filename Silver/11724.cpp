#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> graph;
static vector<bool> visited;
void DFS(int node);

int main() {
  int N, M;
  cin >> N >> M;

  graph.resize(N+1);
  visited = vector<bool>(N+1, false);

  for (int i=0; i<M; i++) {
    int start, end;
    cin >> start >> end;

    graph[start].push_back(end);
    graph[end].push_back(start);
  }

  int count = 0;
  for (int i=1;i<=N;i++){
    if (!visited[i]) {
      count ++;
      DFS(i);
    }
  }

  cout << count << "\n";
}

void DFS (int node) {
  if(visited[node]) {
    return;
  }

  visited[node] = true;

  for (int i:graph[node]) {
    if (!visited[i]) {
      DFS(i);
    }
  }
}