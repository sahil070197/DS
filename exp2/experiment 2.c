
#include<stdio.h>
#include<stdlib.h>
struct student{
    char n[20];
    int roll;
    int marks;
};
struct node{
    struct student data;
    struct node* next;
};
void print(struct node *head){
    struct node *temp;
    if(head==NULL)
        printf("no data entered");
    else{
    temp=head;

    printf("\n\n");
    while(temp!=NULL)
        {
        printf(" %d %s %d\n",temp->data.roll,temp->data.n,temp->data.marks);
        temp=temp->next;

        }
    }
}
void main(){
    struct node* s;
    struct node *head=NULL;
    struct node * temp2;
    int temp;

    printf("press 1 if you want to enter data:");
    scanf("%d",&temp);

    if(temp==1)
        {
        s=(struct node *)malloc(sizeof(struct node));
        head=s;
        temp2=s;

        printf("enter the student's roll no ,name and marks:");
        scanf("%d%s%d",&s->data.roll,&s->data.n,&s->data.marks);
        s->next=NULL;
        }
    else
     print(head);
    while(1)
        {
        printf("press 1 if you want to enter more records or press 0 to view already entered records and press 9 to exit:");
        scanf("%d",&temp);

        if(temp==9)
            break;
        if(temp==0)
        {
            temp2->next=NULL;
            print(head);
            continue;
        }
        s=(struct node *)malloc(sizeof(struct node));
        temp2->next=s;
        printf("enter the student's roll no, name and marks:");
        scanf("%d%s%d",&s->data.roll,&s->data.n,&s->data.marks);
        temp2=temp2->next;
    }
}
