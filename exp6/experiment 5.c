//WAP to concatenate two singly linked list in sorted order either ascending or descending.   
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int item;
	node *next;
};

node *x=NULL,*y=NULL;

node *create()
{
	int ch;
	node *q,*r,*p;
	p=(node *)malloc(sizeof(node));
	printf("\nEnter data to be inserted :");
	scanf("%d",&p->item);
	p->next=NULL;
	r=p;
	printf("\nPress 1 to insert more nodes :");
	scanf("%d",&ch);
	while(ch==1)
	{
		q=(node *)malloc(sizeof(node));
		printf("\nEnter data to be inserted :");
		scanf("%d",&q->item);
		r->next=q;
		q->next=NULL;
		printf("\nPress 1 to insert more nodes :");
		scanf("%d",&ch);
		r=q;
	}
	return p;
}

void display(node *x)
{
	node *s;
	s=x;
	while(s!=NULL)
	{
		printf("%d->",s->item);
		s=s->next;
	}
}

void sort(node **p)
{
	node *temp,*nxt;
	temp=*p;
	int data;
	while(temp!=NULL)
	{
		nxt=temp->next;
		while(nxt!=NULL)
		{
			if(temp->item>nxt->item)
			{
				data=nxt->item;
				nxt->item=temp->item;
				temp->item=data;
			}
			nxt=nxt->next;
		}
		temp=temp->next;
	}
}


void concat(node **p,node *q)
{
	node *temp=*p;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=q;
	printf("\n");
	sort(&*p);
}

int main()
{
	x=(node *)malloc(sizeof(node));
	y=(node *)malloc(sizeof(node));
	printf("Create the first linked list :");
	x=create();
	printf("Create the second linked list :");
	y=create();
	printf("\nList 1 :");
	display(x);
	printf("\nList 2 :");
	display(y);
	concat(&x,y);
	printf("\nConcatenated List sorted in ascending order :");
	display(x);
}
