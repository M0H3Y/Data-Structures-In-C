#include <stdio.h>
#include <stdlib.h>

typedef int QueueEntry; //default type of queue entry 
#define MAXQUEUE 100    // default max size of the queue

typedef struct queuenode {
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;

typedef struct queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
}Queue;

void InitializeQueue(Queue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}
void Append(QueueEntry e , Queue *pq) {
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    if(!pn) {
        return 0;
    }
    else {
        pn->next = NULL;
        pn->entry = e;
        if (!pq->rear) pq->front = pn;
        else pq->rear->next = pn;
        pq->rear = pn;
        pq->size++;

    }
}

void Serve(QueueEntry *pe , Queue *pq) {
    QueueNode *pn = pq->front;
    *pe = pq->front->entry;
    free(pn);
    if(!pq->front)
        pq->rear = NULL;
    pq->size--;
}
int QueueEmpty(Queue *pq) {
    return !pq->size;
}
int QueueFull(Queue *pq) {
    return 0;
}

int QueueSize(Queue *pq) {
    return pq->size;
}

void ClearQueue(Queue *pq) {
    while(pq->front){
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    pq->size = 0;
}
void TraverseQueue(Queue *pq, void (*pf) (QueueEntry)) {
    QueueNode *pn = pq->front;
    while(pn) {
        (*pf)(pn->entry);
        pn = pn->next;
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
