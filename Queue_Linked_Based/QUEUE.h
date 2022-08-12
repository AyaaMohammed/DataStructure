#define QueueEntry char
typedef struct queuenode{
	QueueEntry entry;
	struct queuenode *next;
}QueueNode;
typedef struct queue{
	QueueNode*front;
	QueueNode*rear;
	int size;
}Queue;
void CreateQueue(Queue*pq);
int Append(QueueEntry e,Queue*pq);
void Serve(QueueEntry*pe,Queue*pq);
int QueueEmpty (Queue*pq);
int QueueFull (Queue*pq);
int QueueSize (Queue*pq);
void ClearQueue(Queue*pq);
void TraverseQueue (Queue*pq,void (*pf)(QueueEntry));
void Display(QueueEntry);