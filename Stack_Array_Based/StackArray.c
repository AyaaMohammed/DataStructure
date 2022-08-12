#include <stdio.h>
#include <stdlib.h>
#include "STACK.h"

 
int main(){
	
	Stack s;
	StackEntry e;
	int x;
	CreateStack(&s);
	if(!StackFull(&s)){
		push(e,&s);
	}
	if(!StackEmpty(&s)){
		pop(&e ,&s);
	}
	if(!StackEmpty(&s)){
		StackTop(&e,&s);
	}
	x=StackSize(&s);
	ClearStack(&s);
	TraverseStack(&s,&Display);
}

 void Display(StackEntry e){ //user level
	 printf("e is :%c\n",e);
 }
 void TraverseStack(Stack*ps,void(*pf)(StackEntry)){
	for(int i=ps->top;i>0;i--){
		(*pf)(ps->entry[i-1]);
	}
}
void ClearStack(Stack*ps){
	ps ->top=0;
}
int StackSize(Stack*ps){
	return ps->top;
}
void StackTop(StackEntry *pe,Stack*ps){
	*pe = ps->entry[ps->top-1];
}
void CreateStack(Stack*ps){
	ps -> top=0;
}
void push(StackEntry e,Stack*ps){
	ps -> entry[ps->top++] = e;
}
int StackFull(Stack*ps){
	if(ps->top == MAXSTACK){
		return 1;
	}
	else{
		return 0;;
	}
}
void pop(StackEntry *pe,Stack*ps){
	ps->top--;
	*pe = ps->entry[ps->top]; 
}
int StackEmpty(Stack*ps){
	if(ps->top == 0){
		return 1;
	}
	else{
		return 0;;
	}
}