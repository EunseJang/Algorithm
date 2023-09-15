#include <iostream>
using namespace std;

// 연결리스트로 스택 구현
template<typename itemType>
class LinkedListStack 
{
public:
  LinkedListStack();
  ~LinkedListStack();
  void push(itemType v);
  itemType pop();
  int empty();

private:
  struct node {
    itemType key;
    struct node* next;
  };

  struct node* head, * z;
};

template<typename itemType>
LinkedListStack<itemType>::LinkedListStack() 
{
  head = new struct node;
  z = new struct node;
  head->next = z;
  z->next = z;
}

template<typename itemType>
LinkedListStack<itemType>::~LinkedListStack() 
{
  while (!empty()) {
    pop();
  }
  delete z;
  delete head;
}

template<typename itemType>
void LinkedListStack<itemType>::push(itemType v) 
{
  struct node* z = new node;
  z->key = v;
  z->next = head->next;
  head->next = z;
}

template<typename itemType>
itemType LinkedListStack<itemType>::pop() 
{
  if (!empty()) {
    struct node* z = head -> next;
    head -> next = z -> next;
    itemType tmp = z -> key;
    delete z;
    return tmp;
  }
  else {
    return 0;
  }
}

template<typename itemType>
int LinkedListStack<itemType>::empty() {
  if (head -> next == z) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  char op;
  LinkedListStack<double> stack;

  while ((op = cin.get()) != '\n') {
    double result = 0;
    double n1 = 0;
    double n2 = 0;
    
    while (op == ' ') {
      cin.get(op);
    }
    
    if (op == '+') {
      n1 = stack.pop();
      n2 = stack.pop();
      result = n1 + n2;
    }
    if (op == '-') {
      n1 = stack.pop();
      n2 = stack.pop();
      result = n2 - n1;
    }
    if (op == '*') {
      n1 = stack.pop();
      n2 = stack.pop();
      result = n1 * n2;
    }
    if (op  == '/') {
      n1 = stack.pop();
      n2 = stack.pop();
      if (n1 == 0) {
        cerr << "Error: Division by zero" << endl;
        return 0; // 0으로 나누는 예외 처리
      }
      result = n2 / n1;
    }

    while (op >= '0' && op <= '9') {
      result = 10 * result + (op - '0');
      cin.get(op);
    }
    stack.push(result);
  }

  cout << fixed; // 부동 소수점 숫자를 고정된 소수점 형식으로 출력
  cout.precision(2); // 소수점 이하 자릿수는 2로 설정
  cout << stack.pop() << '\n';

  return 0;
}