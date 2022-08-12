#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "math.h"
#include "QUEUE.h"

int main()
{
	QueueEntry e;	Queue q;
	CreateQueue(&q);
	if(!Append(e,&q)){
		printf("not enqueue.\n");
	}
}
 void CreateQueue(Queue*pq){
	 pq->front =NULL;
	 pq->rear =NULL;
	 pq->size =0;
 }
int Append(QueueEntry e,Queue*pq){
	 QueueNode*pn=(QueueNode*)malloc(sizeof(QueueNode));
	 if(!pn){	 
	    return 0;
	 }
	 else
	 {
		 pn->next=NULL;
		 pn->entry= e;
		 if(!pq->rear)
			 pq->front =pn;
		 else
		     pq->rear->next=pn;//run time error for empty queue
		 pq->rear=pn;
		 pq->size++;	
	   return 1;
	 }
 }
 void Serve(QueueEntry*pe,Queue*pq){
	 QueueNode*pn=pq->front;
	 *pe=pn->entry;
	 pq->front=pn->next;
	 free(pn);
	 if(!pq->front)
		 pq->rear=NULL;
	 pq->size--;
 }
int QueueEmpty (Queue*pq){
	return !pq->front; 	 
 }
int QueueFull (Queue*pq){
	return 0;
}
int QueueSize (Queue*pq){
	return pq->size;
}
void ClearQueue(Queue*pq){
	while(pq->front){
		pq->rear=pq->front->next;
		free(pq->front);
		pq->front=pq->rear;
	}
	pq->size =0;
}
void TraverseQueue (Queue*pq,void (*pf)(QueueEntry)){
	for(QueueNode*pn=pq->front;pn;pn=pn->next)
		(*pf)(pn->entry);
}
void Display(QueueEntry e){ //user level
	 printf("e is :%c\n",e);
 }
 


 