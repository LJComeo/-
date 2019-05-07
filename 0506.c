#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node  *next;
}LinkStackNode;
typedef LinkStackNode  *LinkStack;

void InitStack1(LinkStack * S){
	*S = (LinkStackNode *)malloc(sizeof(LinkStackNode));
	(*S)->next = NULL;
}

int push1(LinkStack top, int x){
	LinkStackNode *temp;
	temp = (LinkStackNode *)malloc(sizeof(LinkStackNode));
	if (temp == NULL)
		return 0;
	temp->data = x;
	temp->next = top->next;
	top->next = temp;
	return 1;
}

int Pop1(LinkStack top, int* x){
	LinkStackNode *temp;
	temp = top->next;
	if (temp == NULL)
		return 0;
	top->next = temp->next;
	*x = temp->data;
	free(temp);
	return 1;
}

#define Stack_Size 50
#define StackElementType int
typedef struct {
	StackElementType elem[Stack_Size];
	int top;
}SeqStack;

void InitStack2(SeqStack * S){
	S->top = -1;
}

int Push2(SeqStack * S, StackElementType x){
	if (S->top == Stack_Size - 1)
		return 0;
	S->top++;
	S->elem[S->top] = x;
	return 1;
}

int Pop2(SeqStack * S, StackElementType * x){
	if (S->top == -1)
		return 0;
	else
	{
		*x = S->elem[S->top];
		S->top--;
		return 1;
	}
}
#define QueueElementType  int 
typedef struct Node
{
	int data;
	struct Node  * next;
}LinkQueueNode;

typedef struct {
	LinkQueueNode * front;
	LinkQueueNode * rear;
}LinkQueue;

int InitQueue(LinkQueue * Q){
	Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (Q->front != NULL){
		Q->rear = Q->front;
		Q->front->next = NULL;
		return 1;
	}
	else
		return 0;
}
int EnterQueue(LinkQueue * Q, QueueElementType x){
	LinkQueueNode * NewNode;
	NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL){
		NewNode->data = x;
		NewNode->next = NULL;
		Q->rear->next = NewNode;
		Q->rear = NewNode;
		return 1;
	}
	else
		return 0;
}

int DeleteQueue(LinkQueue * Q, QueueElementType * x){
	LinkQueueNode * p;
	if (Q->front == Q->rear)
		return 0;
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	*x = p->data;
	free(p);
	return 1;
}
#define MAXSIZE 50
typedef struct
{
	QueueElementType element[MAXSIZE];
	int front;
	int rear;
}SeqQueue;

void InitQueue1(SeqQueue * Q)
{
	Q->front = Q->rear = 0;
}

int EnterQueue1(SeqQueue * Q, QueueElementType x)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return 0;
	Q->element[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 0;
}

int DeleteQueue1(SeqQueue * Q, QueueElementType * x)
{
	if (Q->front == Q->rear)
		return 0;
	*x = Q->element[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return 1;
}

void main(){
	
	system("pause");
	return 0;
}