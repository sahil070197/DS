//WAP for polynomial addition and multiplication. Represent polynomial in linked list form with suitable data structure. 
#include<stdio.h>
#include<stdlib.h>

typedef struct poly
{
	int coeff,expo;
	poly *link;
}p1,p2;

poly *create_poly()
{
	poly *p,*r,*q;
	int ch;
	p=(poly *)malloc(sizeof(poly));
	printf("Enter coefficient :");
	scanf("%d",&p->coeff);
	printf("Enter power :");
	scanf("%d",&p->expo);
	p->link=NULL;
	r=p;
	printf("\nPress 1 to insert more :");
	scanf("%d",&ch);
	while(ch==1)
	{
		q=(poly *)malloc(sizeof(poly));
		printf("Enter coefficient :");
		scanf("%d",&q->coeff);
		printf("Enter power :");
		scanf("%d",&q->expo);
		q->link=NULL;
		r->link=q;
		r=q;
		printf("\nPress 1 to insert more :");
		scanf("%d",&ch);
	}
	return p;
}

void insert(poly **p3,poly *p)
{
	poly *temp;
	if(*p3==NULL)
	{
		*p3=p;
	}
	else
	{
		temp=*p3;
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=p;
	}
}

poly *padd(poly *p1,poly *p2)
{
	poly *temp,*p3,*p_sum,*t1,*t2;
	t1=p1;
	t2=p2;
	p3=(poly *)malloc(sizeof(poly));
	p3=NULL;
	int sum;
	while(t1!=NULL&&t2!=NULL)
	{
		p_sum=(poly *)malloc(sizeof(poly));
		if(t1->expo==t2->expo)
		{	
			sum=t1->coeff+t2->coeff;
			if(sum!=0)
			{
				p_sum->coeff=sum;
				p_sum->expo=t1->expo;
				p_sum->link=NULL;
				insert(&p3,p_sum);
				t1=t1->link;
				t2=t2->link;
			}
		}
		else if(t1->expo>t2->expo)
		{
			//printf("2");
			p_sum->coeff=t1->coeff;
			p_sum->expo=t1->expo;
			p_sum->link=NULL;
			insert(&p3,p_sum);	
			t1=t1->link;
		}
		else
		{
			//printf("3");
			p_sum->coeff=t2->coeff;
			p_sum->expo=t2->expo;
			p_sum->link=NULL;
			insert(&p3,p_sum);	
			t2=t2->link;
		}
	}
	while(t1!=NULL)
	{
		//printf("4");
		p_sum->coeff=t1->coeff;
		p_sum->expo=t1->expo;
		p_sum->link=NULL;
		insert(&p3,p_sum);	
		t1=t1->link;
	}
	while(t2!=NULL)
	{
		p_sum->coeff=t2->coeff;
		p_sum->expo=t2->expo;
		p_sum->link=NULL;
		insert(&p3,p_sum);	
		t2=t2->link;
	}
	return p3;
}

void attach(poly **p3,poly *p)
{
	poly *temp;
	if(*p3==NULL)
		*p3=p;
	else
	{
		temp=*p3;
		while(temp->link!=NULL)
		{
			if(p->expo==temp->coeff)
			{
				temp->coeff+=p->coeff;
			}
			else if(temp->link!=NULL&&p->coeff>temp->coeff&&p->coeff<temp->link->coeff)
			{
				p->link=temp->link;
				temp->link=p;
	
			}
			temp=temp->link;
		}
		if(temp->link==NULL)
		{
			temp->link=p;
		}
	}
}

poly *pmultiply(poly *p1,poly *p2)
{
	poly *t1,*t2,*p3,*mul;
	p3=(poly *)malloc(sizeof(poly));
	p3=NULL;
	t1=p1;
	while(t1!=NULL)
	{
		mul=(poly *)malloc(sizeof(poly));
		t2=p2;
		while(t2!=NULL)
		{
			mul->coeff=t1->coeff*t2->coeff;
			mul->expo=t1->expo+t2->expo;
			mul->link=NULL;
			if(mul->coeff!=0)
				attach(&p3,mul);
			t2=t2->link;
		}
		t1=t1->link;
	}
	return p3;
}

void display(poly *p)
{
	poly *temp;
	temp=p;
	while(temp!=NULL)
	{
		printf("%dx^%d",temp->coeff,temp->expo);
		if(temp->link!=NULL)
			printf("+");
		temp=temp->link;
	}
	printf("\n");
}

int main()
{
	poly *p1,*p2,*p3,*p4;
	printf("Enter polynomial 1:\n");
	p1=create_poly();
	printf("Enter polynomial 2:\n");
	p2=create_poly();
	printf("Polynomial 1:");
	display(p1);
	printf("Polynomial 2:");
	display(p2);
	p4=padd(p1,p2);
	printf("\nSum = ");
	display(p4);
	printf("\nProduct =");
	p3=pmultiply(p1,p2);
	display(p3);
	return 0;
}
