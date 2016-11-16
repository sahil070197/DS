//WAP to find second last node of the given linked list. 
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

int main()
{
	p=(node *)malloc(sizeof(node));
	create();
	node *temp=p;
	printf("\nData of second last node :");
	while(temp->next->next!=NULL)
		temp=temp->next;
	printf("%d",temp->item);
	return 0;
}
