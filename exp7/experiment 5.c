#include<stdio.h>
#include<stdlib.h>
typedef struct faculty
 {
 	char fname[100];
 	long scode;
 	char cnames[20];
 	long fid;
 	struct student *left,*right;
 }faculty;
faculty *m=NULL;
void insert(int status,long key,char name[],long n,char cname[],long code)  // Status =0 for before and 1 for after
{
	faculty *node,*p,*temp;
	node=(student *)malloc(sizeof(student));
	strcpy(node->fname,name);
	node->fid=n;
	node->scode=code;
	strcpy(node->cnames,cname);
	node->left=NULL;
	node->right=NULL;
	if(m==NULL)
	  {
	  	m=node;
	  	printf("\nNode inserted");
	  	return;
	  }
	p=m;
	if((key==p->fid)&&(status==0))
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
	 	if(key==temp->fid)
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
 	 	if(key==p->fid)
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
void insertatpos(int pos,char name[],long n,long code,char cname[])
 {
 	faculty *node,*p,*temp;
 	node=(student *)malloc(sizeof(student));
 	strcpy(node->cnames,cname);
 	node->fid=n;
 	strcpy(node->fname,name);
 	node->scode=code;
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
	faculty *p=m;
    printf("\n");
    if(pos==1)
     {
        printf("\nName : %s",p->fname);
	 	printf("\nID : %ld",p->fid);
	 	printf("\nSubject code :%ld",p->scode);	
     	printf("\nClass name : %s",p->cnames);
		return;
	 }
	while(p!=NULL)
	 {
	 	if(pos==1)
         {
        	printf("\nName : %s",p->fname);
	 	    printf("\nID : %ld",p->fid);
	 	    printf("\nSubject code :%ld",p->scode);
	 	    printf("\nClass name :%s",p->cnames);
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
	if(m->fid==key)
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
	 	if(temp->fid==key)
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
	faculty *p,*temp;
	char str[100];
	long n;
	p=m;
	while(p!=NULL)
	{
	  temp=p->right;
	  while(temp!=NULL)
	   {
	   	 if(p->fid>temp->fid)
	   	   {
              strcpy(str,p->cnames);
			  strcpy(p->cnames,temp->cnames);
			  strcpy(temp->cnames,str);
			  n=p->fid;
			  p->fid=temp->fid;
			  temp->fid=n;
			  n=p->scode;
			  p->scode=temp->scode;
			  temp->scode=n;
			  strcpy(str,p->fname);
			  strcpy(p->fname,temp->fname);
			  strcpy(temp->fname,str);
			  	   	   	         
		   }
		 temp=temp->right;
	   }
	  p=p->right;
	}
	printf("\nList sorted");
}
void display(int status)
{
	faculty *node=m;
	printf("\n\n");
	if(status==0)
	 {
	   while(node!=NULL)
	 {
	 	printf("\nName : %s",node->fname);
	 	printf("\nID : %ld",node->fid);
	 	printf("\nSubject code :%ld",node->scode);
	 	printf("\nClass name : %s",node->cnames);
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
		 	printf("\nName : %s",node->fname);
	 	    printf("\nID : %ld",node->fid);
	 	    printf("\nSubject code :%ld",node->scode);
	 	    printf("\nClass name : %s",node->cnames);
            node=node->left;
	 	    printf("\n\n\n");
		 }
		return;
	}
}
int main()
{
	char ch1,ch2,str1[100],str2[20];
	long id1,sc,id2;
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
    	case '1' :   printf("\n\tEnter succeeding faculty id :");
    	             scanf("%ld",&id1);
    	             fflush(stdin);
    	             printf("\n\tEnter faculty name :");
    	             gets(str1);
    	             printf("\n\tEnter Id :");
    	             scanf("%ld",&id2);
    	             printf("\n\tEnter subject code :");
    	             scanf("%f",&sc);
    	             fflush(stdin);
    	             printf("\n\tEnter class name :");
    	             gets(str2);
    	             insert(0,id1,str1,id2,str2,sc);
    	             break;
        case '2' :   printf("\n\tEnter preceding faculty id  :");
    	             scanf("%ld",&id1);
    	             fflush(stdin);
    	             printf("\n\tEnter faculty name :");
    	             gets(str1);
    	             fflush(stdin);
    	             printf("\n\tEnter ID :");
    	             scanf("%ld",&id2);
    	             printf("\n\tEnter subject code :");
    	             scanf("%f",&sc);
                     fflush(stdin);
    	             printf("\n\tEnter class name :");
    	             gets(str2);
    	             insert(1,id1,str1,id2,str2,sc);
    	             break;
        case '3' :   printf("\n\tEnter position  :");
    	             scanf("%d",&pos);
    	             fflush(stdin);
    	             printf("\n\tEnter faculty name :");
    	             gets(str1);
    	             fflush(stdin);
    	             printf("\n\tEnter ID :");
    	             scanf("%ld",&id1);
    	             printf("\n\tEnter subject code :");
    	             scanf("%f",&sc);
    	             fflush(stdin);
    	             printf("\n\tEnter class name :");
    	             gets(str2);
    	             insertatpos(pos,str1,id1,sc,str2);
    	             break;
    	case '4' :   printf("\n\t Enter position :");
                     scanf("%d",&pos);
                     access(pos);
                     break;
	    case '5' :   printf("\n\tEnter faculty ID you want to delete: ");
                     scanf("%ld",&id1);
                     remov(id1);
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
