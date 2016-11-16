//WAP to find the number of occurrence of all the elements in a linked list.
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

void display()
{
	node *s;
	s=p;
	while(s!=NULL)
	{
		printf("%d->",s->item);
		s=s->next;
	}
}

void count_elem(node *p)
{
	node *temp=p;
	int *a;
	int max=p->item;
	while(temp)
	{
		if(temp->item>max)
			max=temp->item;
		temp=temp->next;
	}
	a=(int *)calloc(max+1,sizeof(int));
	temp=p;
	while(temp)
	{
		a[temp->item]++;
		temp=temp->next;
	}
	for(int i=0;i<=max;i++)
		if(a[i]!=0)
			printf("\n%d occurs %d times",i,a[i]);
}

int main()
{
	p=(node *)malloc(sizeof(node));
	create();
	printf("The list is :");
	display();
	count_elem(p);
	return 0;
}
