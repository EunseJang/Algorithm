#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> check(n);

  for(int i=0;i<n;i++){
    cin >> check[i];
  }

  stack<int> myStack;
  vector<string> result;

  int count = 1;
  for (int i=0;i<n;i++){
    while (count <= check[i]){
      myStack.push(count ++);
      result.push_back("+");
    }

    if(myStack.top() == check[i]) {
      myStack.pop();
      result.push_back("-");
    } 
    else if (myStack.top() > check[i]) {
      cout << "NO\n";
      return 0;
    }
  }

  for (int i=0;i<result.size(); i++){
    cout << result[i] << "\n";
  }
}