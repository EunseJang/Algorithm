#include <iostream>
using namespace std;

typedef struct treeNode *itemType;
void traverse(struct treeNode *t); 
void visit(struct treeNode *t);

// 트리 노드
struct treeNode { char info; struct treeNode *l, *r; };
struct treeNode *x, *z;

// Stack 클래스
class Stack
{
  public:
    Stack(int max=100) { stack=new itemType[max]; p=0; }; 
    ~Stack(){ delete stack; };
    inline void push(itemType v) { stack[p++] = v; };
    inline itemType pop(){ return stack[--p]; };
    inline int empty(){ return !p; };
  private:
    itemType *stack;
    int p;
};

// Queue 클래스 (Circular Queue)
class Queue{
  private:
    itemType *queue;
    int head, tail, size;
  public:
    Queue(int max = 100) 
    { 
      size = max;
      queue = new itemType[size];
      head = 0;
      tail = 0;
    }
    ~Queue() { delete queue; }

    inline void put(itemType v);
    inline itemType get();
    inline int empty();
};

void Queue::put(itemType v) 
{ 
  queue[tail++] = v; 
  if (tail > size) tail = 0; 
} 
itemType Queue::get() 
{ 
  itemType t = queue[head++]; 
  if (head > size) head = 0; 
  return t; 
} 
int Queue::empty() { return head == tail; } 

// 레벨 순회 (Level Order Traversal)
void traverse(struct treeNode *t) 
{
  Queue queue;
  queue.put(t);
  while (!queue.empty()) 
  { 
    t = queue.get(); visit(t);

    // 레벨트리는 왼->오 방향으로 순회
    if (t->l != z) queue.put(t->l); 
    if (t->r != z) queue.put(t->r); 
  } 
}

void visit(struct treeNode *t) 
{ 
  cout << t->info << " ";
}

int main() {
  char c;
  Stack stack(50);

  // z 선언하고 초기화
  z=new treeNode; z->l = z; z->r = z;

  cout << "input: ";

  while((c=cin.get()) != '\n') 
  {
    // 공백인 경우, 무시하고 그 다음 글자 읽음
    while (c == ' ') cin.get(c);

    // x 선언 후 초기화
    x = new treeNode;
    x->info = c; x->l = z; x->r = z;

    // 연산자인 경우 꺼내서 계산
    if (c=='+' || c=='*' || c=='-') { x->r = stack.pop(); x->l = stack.pop(); }

    stack.push(x);
  }

  traverse(stack.pop());
  cout << endl;

  return 0;
}