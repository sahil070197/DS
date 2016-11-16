#include<stdio.h>
#include<stdlib.h>
typedef struct{
int front,rear,size;
int capacity;
int *array;}queue;
queue *makequeue(int capacity)
{
    queue*q;
    q=(queue*)malloc(sizeof(queue));
    q->capacity=capacity;
    q->front=q->size=0;
    q->rear=capacity-1;
    q->array=(int*)malloc(sizeof(int)*q->capacity);
    return q;
}

int isempty(queue*q)
{
    return(q->size==0);
}
int isfull(queue*q)
{
    return(q->size==q->capacity);
}
void enqueue(queue*q,int item)
{
    if(isfull(q))
    printf("queue overflow");
    else
    {
    q->rear=(q->rear+1)%q->capacity;
    q->array[q->rear]=item;
    q->size=q->size+1;

}
}
int dequeue(queue *q)
{
    int item=0;
    if(isempty(q))
    printf("queue empty");

    else
    {
        item=q->array[q->front];

        q->front=(q->front+1)%q->capacity;
q->size=q->size-1;

    }
    return item;
}
void main()
{
    int x,n,m;
    unsigned cap;
    queue *q;
    printf("enter the capacity of queue\n");
    scanf("%d",&cap);
   q= makequeue(cap);
    do
    {
    printf("\nenter the opertation to be performed:\n1.insert\n2.delete\n3.end\n");
    scanf("%d",&n);
    if(n==1)
    {
      printf("\nenter the number to be entered");
      scanf("%d",&x);
      enqueue(q,x);
    }
    else if(n==2)
    {
        m=dequeue(q);
        printf("%d deleted from queue",m);

    }

}while(n!=3);
}
