#include<stdio.h>
#include<stdlib.h>
struct tree{
        int data;
        struct tree *rchild;
        struct tree *lchild;
        };

struct tree *stacks[10],*queue[10];
int top=-1,f =-1,rear=-1;

void add(struct tree* temp)
{
    f +=1;
    queue[f]=temp;
}
struct tree *delqueue()
{
    rear+=1;
    return queue[rear];

}
struct tree * creation()
{
  struct tree *y;
  int i;

  y=(struct tree *)malloc(sizeof(struct tree));
  printf("\nenter data: ");
  scanf("%d",&y->data);

  printf("\npress 1 to insert as left child: ");
  scanf("%d",&i);

  if(i==1)
    y->lchild=creation();
  else
    y->lchild=NULL;

 printf("press 1 to insert as right child: ");
 scanf("%d",&i);

    if(i==1)
        y->rchild=creation();
    else
        y->rchild=NULL;
    return y;

}

void inorder(struct tree *root)
{
    if(root)
    {
        inorder(root->lchild);
        printf(" %d",root->data);
        inorder(root->rchild);
    }
}
void preorder(struct tree *root)
{
    if(root)
    {
        printf(" %d",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(struct tree *root)
{
    if(root)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf(" %d",root->data);
    }
}
struct tree * pop()
{
    if(top==-1)
        return NULL;
    return stacks[top--];

}
void push(struct tree *root)
{
    top=top+1;
    stacks[top]=root;
}

void itrpreorder(struct tree *root)
{
    struct tree *temp;
    temp=root;

    while(1)
    {
        for(;temp;temp=temp->lchild)
        {
            printf(" %d",temp->data);
            if(temp->rchild!=NULL)
                push(temp->rchild);
        }
        temp=pop();
        if(!temp)
            break;
    }

}
void itrpostorder(struct tree *root)
{
    struct tree *temp;
    temp=root;

    while(1)
    {
        for(;temp;temp=temp->lchild)
            push(temp);

                if(top==-1)
                break;

                 if(stacks[top]->rchild!=NULL)
                 temp=stacks[top]->rchild;
                 else{
                 temp=pop();
                 printf(" %d",temp->data);

                while((top!=-1)&&(temp==stacks[top]->rchild)){
                        temp=pop();
                printf(" %d",temp->data);
                }
                temp=NULL;
                 }

    }
}
void itrinorder(struct tree *root)
{
    struct tree *temp;
    temp=root;
    while(1)
    {
        for(;temp;temp=temp->lchild)
        push(temp);

        temp=pop();
        if(temp==NULL)
            break;
        printf(" %d",temp->data);
        temp=temp->rchild;
    }
}
void levelorder(struct tree *root)
{
    struct tree *temp;
    temp=root;
    add(temp);
    while(1)
    {
        temp=delqueue();
        if(temp==NULL)
            break;
        printf(" %d",temp->data);
        if(temp->lchild)
            add(temp->lchild);
        if(temp->rchild)
            add(temp->rchild);
    }

}
int ancestors(struct tree *root,int n)
{
    if(root=='\0')
        return 0;
    if(root->data==n||ancestors(root->lchild,n)||ancestors(root->rchild,n)){
        printf(" %d",root->data);
        return 1;
    }
    return 0;
}


void main()
{
    int i=1,n=4;
    struct tree *root;

    root=creation();

    printf("\n");

  // inorder(root);
    printf("\n");
  // preorder(root);
    printf("\n");
   postorder(root);
    printf("\n");
   // itrpreorder(root);
    printf("\n");
    top=-1;
    itrpostorder(root);
    printf("\n");
   // itrinorder(root);
    printf("\n");
  // levelorder(root);
   n=4;
  // ancestors(root,n);
}
