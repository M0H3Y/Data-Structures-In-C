#include <stdio.h>
#include <stdlib.h>

typedef int QueueEntry; //default type of Queue entry
#define MAXQUEUE 100    // default Maximum size of the queue 


typedef struct queue {
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
} Queue;


void InitializeQueue(Queue *pq) {
    pq->front= 0;
	pq->rear = -1;
	pq->size = 0;
}


void Append(QueueEntry e , Queue *pq) {
    pq->rear = (pq->rear+1)%MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}


void Serve(QueueEntry *pe , Queue *pq) {
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) %MAXQUEUE;
    pq->size--;
}

int QueueEmpty(Queue *pq) {
    return !pq->size;
}

int QueueFull(Queue *pq) {
    return pq->size == MAXQUEUE;

}

int QueueSize(Queue *pq) {
    return pq->size;
}

void ClearQueue(Queue *pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void TraverseQueue(Queue *pq,void (*pf)(QueueEntry)) {
    int pos = pq->front;
    for(int i = 0 ;i<pq->size;i++) {
        (*pf)(pq->entry[pos]);
        pos = (pos+1)% MAXQUEUE;
    }
}

void display(QueueEntry e) {
    printf("E is : %d \n" , e);
}

int main()
{
    Queue q;

    InitializeQueue(&q);

    Append(5,&q);

    Append(6,&q);

    TraverseQueue(&q,&display);

    int a;

    Serve(&a,&q);

    printf("%d\n",a);

    TraverseQueue(&q,&display);
    return 0;
}
