#include<stdio.h>
#include<stdlib.h>
 struct employee{
        int no;
        int salary;
        char n[20];
};
 struct node{
       struct employee data;
       struct node *next;
};
void display(struct node *head)
{
   struct node * t;
    if(head==NULL)
        printf("no data");
        t=head;
        printf(" NO\tNAME\tSALARY\n");
    while(t!=NULL)
    {
        printf(" %d\t%s\t%d\n",t->data.no,t->data.n,t->data.salary);
        t=t->next;

    }
}
void main()
{
    struct  node *f;
    struct  node *head=NULL;
    struct node *temp;
    int i;
    f=(struct node*)malloc(sizeof( struct node));
    head=f;
    temp=f;
    printf("\nenter the employee's number,name and salary");
    scanf("%d%s%d",&f->data.no,&f->data.n,&f->data.salary);
    f->next=NULL;
    while(1)
    {
        printf("\ndo you want to insert more (1),display(2) or exit(0)?");
        scanf("%d",&i);

        if(i==1)
        {
            f=( struct node*)malloc(sizeof(struct node));
            temp->next=f;
            printf("\nenter the employee's number,name and salary");
            scanf("%d%s%d",&f->data.no,&f->data.n,&f->data.salary);
            temp=temp->next;
        }
        if(i==0)
            break;
        if(i==2)
        {
            temp->next=NULL;
            display(head);
        }

        if((i!=0)&&(i!=1)&&(i!=2))
            printf("enter the choice again");
    }
}
