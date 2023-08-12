#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N,M;
  cin >> N >> M;

  vector<vector<int>> arr(N+1, vector<int>(N+1,0));
  vector<vector<int>> sum(N+1, vector<int>(N+1,0));

  for (int i=1;i<=N;i++) {
    for (int j=1;j<=N;j++) {
      cin >> arr[i][j];
      sum[i][j] = sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+arr[i][j];
    }
  }

  for(int i=0;i<M;i++){
    int x1, x2, y1, y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<"\n";
  }
}