//WAP to find first common element between two linked list. 
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

void display(node *p)
{
	node *s;
	s=p;
	while(s!=NULL)
	{
		printf("%d->",s->item);
		s=s->next;
	}
}

int common_first(node *p,node *q)
{
	node *t1,*t2;
	for(t1=p;t1!=NULL;t1=t1->next)
	{
		for(t2=q;t2!=NULL;t2=t2->next)
			if(t1->item==t2->item)
				return t1->item;
	}
	return -1;
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
	int a;
	a=common_first(x,y);
	if(a!=-1)
		printf("\nFirst Common Element = %d",a);
	else
		printf("\nNo common Element");
	return 0;
}
