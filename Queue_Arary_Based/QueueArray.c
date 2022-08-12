#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "QUEUE.h"

int main(){	
	Queue q;
	QueueEntry  e;
	CreateQueue(&q);
}
void CreateQueue(Queue * pq){
	pq->front =0;
	pq->rear=-1;
	pq->size =0;
}
void Append(QueueEntry e,Queue *pq){
	//pq->rear =(pq->rear+1)% MAXQUEUE;
	if(pq->rear == MAXQUEUE-1){
		pq->rear=0;
	}else{
		pq->rear++;
	}	
	pq->entry[pq->rear] = e;
	pq->size++;	
}
void Serve(QueueEntry*pe ,Queue*pq){
	*pe = pq->entry[pq->front];
	if(pq->front == MAXQUEUE-1){
		pq->front=0;
	}else{
		pq->front++;
	}
	pq->size--;
}
int QueueEmpty(Queue*pq){
	return !pq->size;
}
int QueueFull(Queue*pq){
	return (pq->size == MAXQUEUE);
}
int QueueSize(Queue*pq){
	return pq->size;
}
void ClearQueue(Queue*pq){
	pq->front =0;
	pq->rear=-1;
	pq->size =0;
}
void TraverseQueue (Queue*pq,void (*pf)(QueueEntry)){
	int pos ,s;
	for(pos=pq->front , s=0 ;s<pq->size ;s++){
		(*pf)(pq->entry[pos]);
		pos=(pos+1)%MAXQUEUE;
	}
}
void Display(QueueEntry e){ //user level
	 printf("e is :%c\n",e);
 }