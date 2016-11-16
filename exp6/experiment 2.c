//WAP to reverse a singly linked list using one auxillary pointer.
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
	printf("Press 1 to insert more nodes");
	scanf("%d",&ch);
	while(ch==1)
	{
		q=(node *)malloc(sizeof(node));
		printf("Enter data to be inserted :");
		scanf("%d",&q->item);
		r->next=q;
		q->next=NULL;
		printf("Press 1 to insert more nodes :");
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
		printf("\n");
		printf("%10u %5d %10u",s,s->item,s->next);
		
		s=s->next;
	}
}

node *rev(node *p)
{
	node *x;
	x=p;
	node *q,*r;
	q=NULL;
	r=x->next;
	while(x->next!=NULL)
	{
		x->next=q;
		q=x;
		x=r;
		r=x->next;
	}
	x->next=q;
	return x;
}

int main()
{
	p=(node *)malloc(sizeof(node));
	create();
	printf("\n");
	printf("List\t:");
	display(p);
	node *a;
	printf("\nReversed List\t:");
	a=rev(p);
	display(a);
	printf("\n");
	display(p);
	return 0;
}
