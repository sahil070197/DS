#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list
 {
 	char str[100];
 	struct list *next;
 }list;
list *header=NULL;
void initialise()
{
	header=(list *)malloc(sizeof(list));
	strcpy(header->str,"Names");
	header->next=header;
}
void insert(int status,char gkey[],char key[])  // Status =0 for before and 1 for after
{
	list *node,*p,*temp;
	node=(list *)malloc(sizeof(list));
	strcpy(node->str,key);
	node->next=header;
	if(header->next==header)
	  {
	  	printf("\n List is empty");
	  	header->next=node;
	  	node->next=header;
	  	printf("\n Node inserted");
	    return;
	  }
	p=header->next;
	if((strcmp(p->str,gkey)==0)&&(status==0))
	 {
	 	node->next=p;
	 	header->next=node;
	 	printf("\n Node inserted successfully!!");
	 	return;
	 }
   if(status==0)
   {
 	while(p!=header)
	 {
        temp=p->next;
	 	if(strcmp(temp->str,gkey)==0)
	 	 {
	 	 	node->next=p->next;
	 	 	p->next=node;
	 	 	printf("\n Node inserted successfully");
	 	 	return;
		  }
	 }
	printf("\n Key not found");
	return;
   }
   while(p!=header)
	 {
 	 	if(strcmp(p->str,gkey)==0)
	 	 {
	 	 	node->next=p->next;
	 	 	p->next=node;
	 	 	printf("\n Node inserted successfully");
	 	 	return;
		  }
	 }
	printf("\n Key not found");
	return;
}
void display()
{
	list *node;
	node=header->next;
	printf("\n\n\n");
	while(node!=header)
	 {
	 	puts(node->str);
	 	node=node->next;
	 }
}
void access(int pos)
{
	list *p=header->next;
    printf("\n");
    if(pos==1)
     {
     	puts(p->str);
     	return;
	 }
	while(p!=header)
	 {
	 	if(pos==1)
         {
         	puts(p->str);
         	return;
   		 }
       pos--;
       p=p->next;
	 }
	printf("\n Position exceeded");
}
void remov(char str[])
{
	list *p,*temp;
	p=header->next;
	if(strcmp(p->str,str)==0)
	 {
	 	header->next=p->next;
	 	free(p);
	 	printf("\n Node deleted");
	 	return;
	 }
	while(p!=header)
	 {
	 	temp=p->next;
	 	if(strcmp(temp->str,str)==0)
	 	 {
	 	 	p->next=temp->next;
	 	 	free(temp);
	 	 	printf("\nNode deleted");
	 	 	return;
		  }
		p=p->next;
	 }
	printf("\nNode not found");
}
void del()
{
	list *p,*temp;
	p=header->next;
	while(p->next!=header)
	 {
	 	temp=p;
	 	p=p->next;
	 	free(temp);
	 }
	header->next=header;
	printf("\n List removed completely");
}
void sort()
{
	list *p,*temp;
	char str[100];
	p=header->next;
	while(p!=header)
	{
	  temp=p->next;
	  while(temp!=header)
	   {
	   	 if(strcmp(p->str,temp->str)>0)
	   	   {
	   	   	  strcpy(str,p->str);
			  strcpy(p->str,temp->str);
			  strcpy(temp->str,str);         
			  }
		 temp=temp->next;
	   }
	  p=p->next;
	}
	printf("\nList sorted");
}
int main()
{
    int pos;
	char str1[100],str2[100],ch1,ch2;
	initialise();
  do{
    printf("\n\t1.Insert node before a given key");
    printf("\n\t2.Insert node after a given key");
    printf("\n\t3.Accessing a node");
    printf("\n\t4.Remove a node");
    printf("\n\t5.Deletion of complete list");
    printf("\n\t6.Displaying list");
    printf("\n\t7.Sorting list");
    printf("\n\t Enter your choice  :");
    fflush(stdin);
    ch1=getchar();
    fflush(stdin);
    switch(ch1)
     {
     	case '1' : printf("\n\tEnter given key :");
     	           gets(str1);
				   printf("\n\tEnter key you want to insert :");
				   gets(str2);
				   insert(0,str1,str2);
				   break;
		case '2' : printf("\n\tEnter given key :");
     	           gets(str1);
				   printf("\n\tEnter key you want to insert :");
				   gets(str2);
				   insert(1,str1,str2);
				   break;  
        case '3' : printf("\n\t Enter position :");
                   scanf("%d",&pos);
                   access(pos);
                   break;
        case '4' : printf("\n\tEnter key you want to delete: ");
                   gets(str1);
                   remov(str1);
                   break;
        case '5' : del();
                   break;
		case '6' : display();
		           break;
		case '7' : sort();
		           break;
	    default  : printf("\n Invalid choice");    	     
	 }
	printf("\n\tWant to continue (y/n) :");
    fflush(stdin);
	ch2=getchar();
  }while(ch2=='y');
	return 0;
}
