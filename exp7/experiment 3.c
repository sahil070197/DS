#include<stdio.h>
#include<stdlib.h>
typedef struct matrix
 {
 	int row,col;
 	long value;
 	struct matrix *next;
 }matrix;
 typedef matrix * matrixpointer;
 matrixpointer m=NULL,n=NULL,p=NULL;
 void create(matrixpointer *a)
  {
  	 matrixpointer node,temp;
  	 int r,c;
  	 long v;
	 printf("\n\t Entry in following form :- Row Col Value");
  	 printf("\n\t Press -1's to stop");
  	 while(1)
  	 {
	    fflush(stdin);
		scanf("%d%d%ld",&r,&c,&v);
        if((r==-1)||(c==-1))
		  break;
	    node=(matrixpointer)malloc(sizeof(matrix));
		node->col=c;
		node->row=r;
		node->value=v;
		node->next=NULL;
	    if((*a)==NULL)
		 (*a)=node;
		else
		{ temp=*a;
          while(temp->next!=NULL)
		   temp=temp->next;		
          temp->next=node;		
     	 }
			}     
	 printf("\nMatrix created successfully!!!!");
   }
   
void store(int a,int b,long c)
 {
 	matrixpointer node,temp;
 	node=(matrixpointer)malloc(sizeof(matrix));
 	node->row=a;
 	node->col=b;
 	node->value=c;
 	node->next=NULL;
 	if(p==NULL)
 	 p=node;
 	else
 	 {
 	 	temp=p;
 	 	while(temp->next!=NULL)
 	 	 temp=temp->next;
 	 	temp->next=node;
	  }
 }
void disp()
 {
 	matrixpointer temp;
	printf("\n\n");
	temp=p;
 	while(temp!=NULL)
 	 {
 	 	printf("%d  %d  %ld\n",temp->row,temp->col,temp->value);
 	 	temp=temp->next;
	  }
 }
void add()
 {
 	matrixpointer node,temp,a,b;
 	a=m;
 	b=n;
 	while((a!=NULL)&&(b!=NULL))
 	 {
 	 	if(a->row==b->row)
 	 	  {
 	 	  	if(a->col==b->col)
 	 	  	  {
			     if(a->value+b->value) 
				  store(a->row,a->col,a->value+b->value);
			      b=b->next;
			      a=a->next;
			  }	
			else if(a->col>b->col)
			  {
			  	 store(b->row,b->col,b->value);
			  	 b=b->next;
			  }
			else
			  {
			  	 store(a->row,a->col,a->value);
			  	 a=a->next;
			  }
		   }
		 else if(a->row>b->row)
		   {
		   	 store(b->row,b->col,b->value);
		   	 b=b->next;
		   }
		 else
		   {
		   	 store(a->row,a->col,a->value);
		   	 a=a->next;
		   }
     }
     if(a==NULL)
      {
      	while(b!=NULL)
      	 {
      	 	store(b->row,b->col,b->value);
      	 	b=b->next;
		   }
	  }
	  if(b==NULL)
	   {
	   	 while(a!=NULL)
	   	   {
	   	   	  store(a->row,a->col,a->value);
	   	   	  a=a->next;
			  }
	   }
	disp();
 }
int main()
{
    printf("\n First matrix :---");
    create(&m);
    printf("\n Second matrix :---");
    create(&n);
    printf("\n Sum :---");
    add();
	return 0;
}
