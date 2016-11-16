#include<stdio.h>
#include<stdlib.h>
 struct faculty{
        int id,code;
        char n[20],clas[5];
};
 struct node{
       struct faculty data;
       struct node *next;
};
void display(struct node *head)
{
   struct node * t;
    if(head==NULL)
        printf("no data");
        t=head;
        printf(" ID\tNAME\tCODES\tCLASSES\n");
    while(t!=NULL)
    {
        printf(" %d\t%s\t%d\t%s\n",t->data.id,t->data.n,t->data.code,t->data.clas);
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
    printf("\nenter the faculty's name,ID,subject codes and class names: ");
    scanf("%s%d%d%s",&f->data.n,&f->data.id,&f->data.code,&f->data.clas);
    f->next=NULL;
    while(1)
    {
        printf("\ndo you want to insert more (1),display(2) or exit(0)?");
        scanf("%d",&i);

        if(i==1)
        {
            f=( struct node*)malloc(sizeof(struct node));
            temp->next=f;
            printf("\nenter the faculty's name,ID,subject codes and class names: ");
            scanf("%s%d%d%s",&f->data.n,&f->data.id,&f->data.code,&f->data.clas);
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
