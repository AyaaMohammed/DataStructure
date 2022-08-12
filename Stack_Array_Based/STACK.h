#define MAXSTACK 5
#define StackEntry char
 typedef struct stack{
	 int top;
	 StackEntry entry[MAXSTACK];
 }Stack;
 
 void push(StackEntry e,Stack*ps);
 void pop(StackEntry *pe,Stack*ps);
 int StackEmpty(Stack*ps);
 int StackFull(Stack*ps);
 void CreateStack(Stack*ps);
 void StackTop(StackEntry *pe,Stack*ps);
 int StackSize(Stack*ps);
 void ClearStack(Stack*ps);
 void TraverseStack(Stack*ps,void(*pf)(StackEntry));
void Display(StackEntry);