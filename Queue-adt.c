#include <stdlib.h>
#include "Queue.h"  /* file Queue-adt.c */
/* other includes such as stdio.h, stdlib.h, etc. */ 
typedef struct Node /* a private inner struct which is not exported */ 
{ 
   int data; 
   struct Node* next; 
} Node; 
 
typedef struct QueueStruct 
{ 
   Node* front; 
   Node* back; 
   int length; 
} QueueStruct; 
 
Node *NewNode(void) {
    Node* n;
    n = malloc(sizeof(Node));
    n -> data = 0;
    n -> next = NULL;
    return n;    
} 
void FreeNode(Node* ptrN) {
    free(ptrN);//
    ptrN = NULL;
}

/* Constructor-Destructor */ 
QueueHndl NewQueue(void) 
{ 
    QueueHndl Q; 
    Q = malloc(sizeof(QueueStruct)); 
    Q->front = Q->back = NULL; 
    Q->length = 0; 
    return(Q); 
} 
void FreeQueue(QueueHndl* ptrQ) {
    Node* head = (*ptrQ) -> front;//
    Node* tmp = head;
    for( ; head != NULL; head = head -> next){
        tmp = head;
        FreeNode(tmp);
    }
}
 
/* Access functions */ 
int getFront(QueueHndl Q) {
    if( (Q -> front) == NULL)
        return -100000000;
    else
        return (Q -> front) ->data;
} 
int getLength(QueueHndl Q) {
    return Q -> length;
    // int count = 0;
    // for( ; Q != NULL; Q = Q -> back){
    //     count ++;
    // }
    // return count;
} 

boolean isEmpty(QueueHndl Q) {
    if( Q -> front == NULL)
        return true;
    else
        return false;
} 
 
/* Manipulation procedures */ 
void Enqueue(QueueHndl Q, int data) {
    Node* n = NewNode();
    n -> data = data;
    if( (Q -> front) == NULL){
        Q -> front = Q -> back = n;
    }
    else{
        (Q -> back) -> next = n;
        Q -> back = n;
    }
    Q -> length += 1;
} 

void Dequeue(QueueHndl Q) {
    Node* tmp = Q -> front;
    Q -> front = (Q -> front) -> next;
    if( (Q -> front) == NULL)
        Q -> back = NULL;
    FreeNode(tmp);
} 
