#include<stdio.h>
#include<stdlib.h>
typedef struct student
 {
 	char sname[100];
 	float marks;
 	long rollno;
 	struct student *left,*right;
 }student;
student *m=NULL;
void insert(int status,long key,char name[],long n,float marks)  // Status =0 for before and 1 for after
{
	student *node,*p,*temp;
	node=(student *)malloc(sizeof(student));
	strcpy(node->sname,name);
	node->rollno=n;
	node->marks=marks;
	node->left=NULL;
	node->right=NULL;
	if(m==NULL)
	  {
	  	m=node;
	  	printf("\nNode inserted");
	  	return;
	  }
	p=m;
	if((key==p->rollno)&&(status==0))
	 {
	 	node->right=p;
	 	p->left=node;
	    m=node;
	 	printf("\n Node inserted successfully!!");
	 	return;
	 }
   if(status==0)
   {
   	p=m;
 	while(p->right!=NULL)
	 {
        temp=p->right;
	 	if(key==temp->rollno)
	 	 {
	 	 	node->right=temp;
	 	 	temp->left=node;
	 	 	node->left=p;
	 	 	p->right=node;
	 	 	printf("\n Node inserted successfully");
	 	 	return;
		  }
		p=p->right;
	 }
	printf("\n Key not found");
	return;
   }
   p=m;
   if((p->right==NULL)&&(status==1))
    {
    	p->right=node;
    	node->left=p;
    	printf("\nNode inserted successfully!!");
    	return;
	}
   while(p->right!=NULL)
	 {
 	 	if(key==p->rollno)
	 	 {
	 	 	temp=p->right;
	 	 	node->right=p->right;
	 	 	node->left=p;
	 	 	p->right=node;
	 	 	temp->left=node;
	 	 	printf("\n Node inserted successfully");
	 	 	return;
		  }
		p=p->right;
	 }
	printf("\n Key not found");
	return;
}
void insertatpos(int pos,char name[],long rno,float mr)
 {
 	student *node,*p,*temp;
 	node=(student *)malloc(sizeof(student));
 	strcpy(node->sname,name);
 	node->rollno=rno;
 	node->marks=mr;
 	node->left=NULL;
 	node->right=NULL;
	 if(pos==1)
 	 {
 	   	node->right=m;
 	   	m->left=node;
 	   	m=node;
 	   	printf("\nNode inserted successfully!!");
 	   	return;
	  }
	 if(m==NULL)
	  {
	  	m=node;
	  	printf("\nNode inserted successfully!!!");
	  	return;
	  }
	 p=m;
	 pos--;
	 while(p->right!=NULL)
	  {
	  	pos--;
		if(pos==1)
	  	 {
	  	   temp=p->right;
	       node->right=p->right;
		   node->left=p;
		   temp->left=node;
		   p->right=node;
		   printf("\nNode inserted successfully!!");	   
		   return;
		   }
		 p=p->right;
	  }
	  printf("\nPosition exceeded");
}
void access(int pos)
{
	student *p=m;
    printf("\n");
    if(pos==1)
     {
        printf("\nName : %s",p->sname);
	 	printf("\nRoll Number : %ld",p->rollno);
	 	printf("\nMarks :%f",p->marks);	
     	return;
	 }
	while(p!=NULL)
	 {
	 	if(pos==1)
         {
        	printf("\nName : %s",p->sname);
	 	    printf("\nRoll Number : %ld",p->rollno);
	 	    printf("\nMarks :%f",p->marks);
		  	return;
   		 }
       pos--;
       p=p->right;
	 }
	printf("\n Position exceeded");
}
void remov(long key)
{
	student *p,*temp,*x;
	p=m->right;
	if(m->rollno==key)
	 {
	 	p->left=NULL;
	 	free(m);
	 	m=NULL;
	 	m=p;
	 	printf("\n Node deleted");
	 	return;
	 }
	while(p!=NULL)
	 {
	 	temp=p->right;
	 	if(temp->rollno==key)
	 	 {
	 	 	p->right=temp->right;
	 	 	x=temp->right;
	 	 	x->left=p;
	 	 	free(temp);
	 	 	printf("\nNode deleted");
	 	 	return;
		  }
		p=p->right;
	 }
	printf("\nNode not found");
}
void del()
{
	student *p,*temp;
	p=m;
	while(p!=NULL)
	 {
	 	temp=p;
	 	p=p->right;
	 	free(temp);
	 }
	m=NULL;
	printf("\n List removed completely");
}
void sort()
{
	student *p,*temp;
	char str[100];
	long n;
	float s;
	p=m;
	while(p!=NULL)
	{
	  temp=p->right;
	  while(temp!=NULL)
	   {
	   	 if(p->rollno>temp->rollno)
	   	   {
              strcpy(str,p->sname);
			  strcpy(p->sname,temp->sname);
			  strcpy(temp->sname,str);
			  n=p->rollno;
			  p->rollno=temp->rollno;
			  temp->rollno=n;
			  s=p->marks;
			  p->marks=temp->marks;
		      temp->marks=s;	  	   	   	         
		   }
		 temp=temp->right;
	   }
	  p=p->right;
	}
	printf("\nList sorted");
}
void display(int status)
{
	student *node=m;
	printf("\n\n");
	if(status==0)
	 {
	   while(node!=NULL)
	 {
	 	printf("\nName : %s",node->sname);
	 	printf("\nRoll Number : %ld",node->rollno);
	 	printf("\nMarks :%f",node->marks);
	 	node=node->right;
	 	printf("\n\n\n");
	 }	
	   return;
	 }
	if(status==1)
	{
		node=m;
		while(node->right!=NULL)
		 node=node->right;
		while(node!=NULL)
		 {
		 	printf("\nName : %s",node->sname);
	 	    printf("\nRoll Number : %ld",node->rollno);
	 	    printf("\nMarks :%f",node->marks);
	 	    node=node->left;
	 	    printf("\n\n\n");
		 }
		return;
	}
}
int main()
{
	char ch1,ch2,str[100];
	long rno1,rno2;
	int pos;
	float m;
 do{
    printf("\n\t1.Insert a node before given key");
    printf("\n\t2.Insert a node after given key");
    printf("\n\t3.Insert a node at given position");
    printf("\n\t4.Accessing a node");
    printf("\n\t5.Remove a given node");
    printf("\n\t6.Completely delete a list");
    printf("\n\t7.Display");
    printf("\n\t8.Display in reverse manner");
    printf("\n\t9.Sorting");
    printf("\n\tEnter your choice :");
    fflush(stdin);
    ch1=getchar();
    switch(ch1)
    {
    	case '1' :   printf("\n\tEnter succeeding student roll no.  :");
    	             scanf("%ld",&rno1);
    	             fflush(stdin);
    	             printf("\n\tEnter student name :");
    	             gets(str);
    	             printf("\n\tEnter roll number :");
    	             scanf("%ld",&rno2);
    	             printf("\n\tEnter marks :");
    	             scanf("%f",&m);
    	             insert(0,rno1,str,rno2,m);
    	             break;
        case '2' :   printf("\n\tEnter preceding student roll no.  :");
    	             scanf("%ld",&rno1);
    	             fflush(stdin);
    	             printf("\n\tEnter student name :");
    	             gets(str);
    	             fflush(stdin);
    	             printf("\n\tEnter roll number :");
    	             scanf("%ld",&rno2);
    	             printf("\n\tEnter marks :");
    	             scanf("%f",&m);
    	             insert(1,rno1,str,rno2,m);
    	             break;
        case '3' :   printf("\n\tEnter position  :");
    	             scanf("%d",&pos);
    	             fflush(stdin);
    	             printf("\n\tEnter student name :");
    	             gets(str);
    	             fflush(stdin);
    	             printf("\n\tEnter roll number :");
    	             scanf("%ld",&rno2);
    	             printf("\n\tEnter marks :");
    	             scanf("%f",&m);
    	             insertatpos(pos,str,rno2,m);
    	             break;
    	case '4' :   printf("\n\t Enter position :");
                     scanf("%d",&pos);
                     access(pos);
                     break;
	    case '5' :   printf("\n\tEnter student roll number you want to delete: ");
                     scanf("%ld",&rno1);
                     remov(rno1);
                     break;
        case '6' :   del();
                     break;
        case '7' :   display(0);
                     break;
        case '8' :   display(1);
                     break;
        case '9' :   sort();
                     break;
        default  :   printf("\nInvalid choice");
	}
    printf("\n\tWant to exit(y/n)  :");
    fflush(stdin);
    ch2=getchar();
  }while(ch2=='n');
   del();
  return 0;
}
