#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static vector<vector<pair<int, int>>> tree;
static vector<int> visited;
void BFS(int node);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int V;
  cin >> V;

  tree.resize(V+1);
  visited = vector<int> (V+1, -1);

  for (int i=1;i<=V; i++) {
    int from, to, weight;
    cin >> from;

    while(true) {
      cin >> to;

      if (to == -1) { 
        break;
      }

      cin >> weight;
      tree[from].push_back(make_pair(to, weight));
    }
  }

  BFS(1);

  int maxN = 0;
  for (int i=1; i<=V; i++) {
    if (visited[maxN] < visited[i]) {
      maxN = i;
    }
  }

  fill(visited.begin(), visited.end(), -1);

  BFS(maxN);
  sort(visited.begin(), visited.end());
  cout << visited[V] << "\n";
}

void BFS(int node) {
  queue<int> bfsQ;
  bfsQ.push(node);
  
  visited[node] = 0;
  
  while(!bfsQ.empty()) {
    int now = bfsQ.front();
    bfsQ.pop();

    for (int i=0; i<tree[now].size(); i++) {
      int next = tree[now][i].first;
      int weight = tree[now][i].second;

      if (visited[next] == -1) {
        bfsQ.push(next);
        visited[next] = visited[now] + weight;
      } 
    }
  }
}