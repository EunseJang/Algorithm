#include <iostream>
using namespace std;

typedef struct treeNode* itemType;
void traverse(struct treeNode* t);
void visit(struct treeNode* t);

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

int main() 
{
	char c; 
  Stack stack(50);

  // z 선언하고 초기화
	z=new treeNode; z->l = z; z->r = z;

  cout << "input: ";

  while((c= cin.get())!='\n') 
  {	
    // 공백인 경우, 무시하고 그 다음 글자 읽음
    while(c==' ') cin.get(c);

    // x 선언 후 초기화
    x = new treeNode;
    x->info = c; x->l = z; x->r = z;
    
    // 연산자인 경우 꺼내서 계산
    if(c=='+' || c=='*' || c=='-') { x->r = stack.pop(); x->l = stack.pop(); } 
    
    stack.push(x); 
  }

  // 중위 순회
  traverse(stack.pop()); 
  cout << endl; 
  return 0;     
}

void visit(struct treeNode *t) 
{ 
  cout << t->info << " ";
} 

void traverse(struct treeNode *t) 
{ 
  if (t != z) 
  { 
    // 중위 순회 (Inorder Traversal)
    traverse(t->l);
    visit(t);
    traverse(t->r); 

  /*
    전위 순회(PreOrder)인 경우
    visit(t);
    traverse(t->l);
    traverse(t->r);
  */

  /*
    후위 순회(PostOrder)인 경우
    traverse(t->l);
    traverse(t->r);
    visit(t); 
  */
  } 
}
