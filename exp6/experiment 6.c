//WAP to sort singly linked list. 
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int item;
	node *next;
};

node *p;

void create()
{
	int ch;
	node *q,*r;
	printf("Enter data to be inserted :");
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

void sort(node *p)
{
	node *temp,*nxt;
	temp=p;
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


int main()
{
	int ctr=0;
	p=(node *)malloc(sizeof(node));
	printf("Create the linked list :");
	create();
	printf("\nEntered list :");
	display(p);
	node *temp=p;
	sort(p);
	printf("\nSorted List :");
	display(p);
}
