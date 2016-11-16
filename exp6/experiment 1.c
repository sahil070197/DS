//WAP to construct simple linear linked list using dynamic memory allocation for the given elements with the given functions with elements as strings.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	char item[10];
	node *next;
}node;

node *p;

void display(node *x)
{
	node *s;
	s=x;
	if(p==NULL)
	{
		printf("Empty List");
	}
	while(s!=NULL)
	{
		printf("%s->",s->item);
		s=s->next;
	}
}

void insert()
{
	node *r,*q;
	int ch;
	printf("Enter data to be inserted :");
	scanf("%s",&p->item);
	p->next=NULL;
	r=p;
	printf("Press 1 to insert more...");
	scanf("%d",&ch);
	while(ch==1)
	{
		q=(node *)malloc(sizeof(node));
		printf("Enter data to be inserted :");
		scanf("%s",&q->item);
		r->next=q;
		q->next=NULL;
		printf("Press 1 to insert more...");
		scanf("%d",&ch);
		r=q;
	}
	
}

int find_pos(char str[])
{
	node *temp;
	temp=p;
	int ctr=1;
	if(strcmp(temp->item,str)==0)
		return ctr;
	else
	{
		temp=temp->next;
		while(temp!=NULL)
		{
			ctr++;
			if(strcmp(temp->item,str)==0)
				break;
			temp=temp->next;
		}
		return ctr;
	}
}


void complete_del()
{
	node *temp,*x;
	temp=p;
	while(p!=NULL)
	{
		x=p->next;
		free(p);
		p=x;
	}
	printf("List :");
	display(p);
}

void del(char str[])
{
	node *temp,*x;
	temp=p;
	if(strcmp(temp->item,str)==0)
	{
		x=temp;
		temp=x->next;
		p=temp;
		free(x);
		printf("\nDeleted Successfully");
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(strcmp(temp->next->item,str)==0)
				break;
			temp=temp->next;
		}
		if(temp->next==NULL)
			printf("Elemnt not found");
		else
		{
			x=temp->next;
			temp->next=x->next;
			free(x);
			printf("\nDeleted Successfully");
		}
	}
}

node *copy(node *p)
{
	node *x,*temp,*t,*y;
	temp=p;
	x=(node *)malloc(sizeof(node));
	if(temp==p)
	{
		strcpy(x->item,temp->item);
		x->next=NULL;
		temp=temp->next;
		t=x;
	}
	while(temp!=NULL)
	{
		y=(node *)malloc(sizeof(node));
		strcpy(y->item,temp->item);
		y->next=NULL;
		t->next=y;
		temp=temp->next;
		t=t->next;
	}
	return x;
}

int main()
{
	node *x;
	char str[20];
	int ch,pos,c=1,d;
	p=(node *)malloc(sizeof(node));
	x=(node *)malloc(sizeof(node));
	while(c==1)
	{
	printf("MENU");
	printf("\n1. Insert node");
	printf("\n2. Find the position wrt header");
	printf("\n3. Delete a node with particular key value");
	printf("\n4. Complete deletion of linked list");
	printf("\n5. Display");
	printf("\n6. Copy the list and return the pointer");
	printf("\n7. Exit");
	printf("\nEnter your choice :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:	insert();
				break;
		case 2:	printf("Enter data :");
				scanf("%s",str);
				d=find_pos(str);
				printf("%s is present at position %d",str,d);
				break;
		case 3:	printf("Enter data of node to delete :");
				scanf("%s",str);				
				del(str);
				break;
		case 4: complete_del();
				break;
		case 5:	printf("\nList\t:");
				display(p);
				break;
		case 6:	x=copy(p);
				printf("\nNew list after copying :");
				display(x); 
				break;
		case 7: exit(0);
				break;
		default: printf("Wrong choice");
				 exit(0);
	}
	printf("\nPress 1 to continue :");
	scanf("%d",&c);
	}
	return 0;
}
