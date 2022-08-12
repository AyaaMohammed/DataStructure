#define StackEntry char
// node and pointer to next node
typedef struct stacknode {
	StackEntry entry;
	struct stacknode* next;
}StackNode;
//pointer to struct
typedef struct stack{
	StackNode *top;
	int size;
}Stack;
int push(StackEntry e,Stack*ps);
 void pop(StackEntry *pe,Stack*ps);
 int StackEmpty(Stack*ps);
 int StackFull(Stack*ps);
 void CreateStack(Stack*ps);
 void StackTop(StackEntry *pe,Stack*ps);
 int StackSize(Stack*ps);
 void ClearStack(Stack*ps);
 void TraverseStack(Stack*ps,void(*pf)(StackEntry));