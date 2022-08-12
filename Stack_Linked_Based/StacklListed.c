#include<stdio.h>
#include<stdlib.h>
#include "STACK.h"
int main(){
	Stack s;
	StackEntry e;
	int x;
	CreateStack(&s);
	
		if(!Push(e,&s)){
		   printf("NOT ADDED");
		};
						
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
void CreateStack(Stack*ps){
	ps->top=NULL;
	ps->size=0;
}
 Push(StackEntry e,Stack*ps)
{
	StackNode*pn=(StackNode*)malloc(sizeof(StackNode));
	if(!pn){
		return 0;
	}
	else{
	pn->entry=e;
	pn->next=ps->top;
	ps->top=pn;
	ps->size++;
	return 1;}
}
void StackTop(StackEntry *pe,Stack*ps){
	*pe = ps->top->entry;
}
void Pop(StackEntry *pe,Stack*ps){
	StackNode*pn;
	*pe = ps->top->entry;
	pn=ps->top;
	ps->top=ps->top->next;
	free(pn);
	ps->size--;
}
int StackEmpty(Stack*ps){
	if(ps->top == NULL){
		return 1;
	}
	else{
		return 0;;
	}
}
int StackFull(Stack*ps){    // NOT FULL
	return 0;
}
void ClearStack(Stack*ps){
	StackNode*pn=ps->top;
	StackNode*qn=ps->top;
	while(pn){
		pn=pn->next;
		free(qn);
		qn=pn;
	}
	ps->top=NULL;
	ps->size=0;

}
void TraverseStack(Stack*ps,void(*pf)(StackEntry)){
	StackNode*pn=ps->top;
	while(pn){
		(*pf)(pn->entry);
		pn=pn->next;	
		}
}
int StackSize(Stack*ps){
	/*int x =0;
	StackNode*pn=ps->top;
	while(pn){		
		pn=pn->next;	
		x++;
		}
		return x;*/
	return ps->size;								
}
void Display(StackEntry e){ //user level
	 printf("e is :%c\n",e);
}
