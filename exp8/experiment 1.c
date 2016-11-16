#include<stdio.h>
#include<stdlib.h>
struct tree{
           int data;
           struct tree * lchild;
           struct tree *rchild;
           };

struct tree* insertion(struct tree *root,struct tree *y)
{
    if(!root)
        return y;
    else{
        if(y->data<root->data)
          root->lchild=insertion(root->lchild,y);
            else
       root->rchild=insertion(root->rchild,y);
    }
    return root;
}
struct tree *searching(struct tree *root,int key)
{
    struct tree *node;
    if(root==NULL)
        return NULL;
    if(root->data==key)
            return root;
    if(key<root->data)
      node=  searching(root->lchild,key);
    else
      node=  searching(root->rchild,key);
    return node;

}
struct tree *minimum(struct tree *root)
{
    if(root->lchild==NULL)
        return root;
    root=minimum(root->lchild);
    return root;

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
struct tree *parent(struct tree *root,struct tree *child)
{
    struct tree *t1,*t2;
    if(root)
    {
      if(root->lchild==child||root->rchild==child)
            return root;
      t1=parent(root->lchild,child);
      t2=parent(root->rchild,child);
      if(t1==NULL)
        return t2;
      return t1;
    }
    else return NULL;

}
struct tree * successor(struct tree *root,struct tree *temp)
{
    struct tree *t;
    if(temp->rchild!=NULL)
    return minimum(temp->rchild);
    t=parent(root,temp);
    while(t->data<=temp->data)
     t= parent(root,t);
    return t;
}
void deletion(struct tree *root,struct tree *key)
{
    struct tree *p,*c1,*c2,*temp,*s;
    if(key->lchild==NULL && key->rchild==NULL)
    {
        p=parent(root,key);
        if(p->lchild==key)
            p->lchild==NULL;
        else
            p->rchild==NULL;
        return;
    }
    if(key->lchild==NULL||key->rchild==NULL)
    {
        p=parent(root,key);

       if(key->lchild==NULL)
            c1=key->rchild;
       else
        c1=key->lchild;

        if(p->lchild==key)
        p->lchild=c1;
        else
            p->rchild=c1;
        return;
    }
    else
    {
        s=successor(root,key);
         key->data=s->data;

        if(s->lchild==NULL && s->rchild==NULL){
            p=parent(root,s);
            if(p->lchild==s)
                p->lchild=NULL;
            else
                p->rchild=NULL;
            return;
        }
        else{
             p=parent(root,s);
             p->lchild=s->rchild;
             return;
        }

    }
}
void main()
{
    struct tree *root,*y,*t;
    root=NULL;
    int i=1,d;

    while(i==1)
    {
        printf("\npress 1 to insert: ");
        scanf("%d",&i);
        if(i==1){
          printf("\nenter data: ");
          scanf("%d",&d);
           y=(struct tree*)malloc(sizeof(struct tree));
           y->data=d;
           y->lchild=NULL;
           y->rchild=NULL;
          root=insertion(root,y);
        }
    }
    printf("%d",parent(root,root)->data);
    //inorder(root);
    //y=searching(root,8);
    //deletion(root,y);
   // inorder(root);
  // y= searching(root ,8);
 //* y=minimum(root);

  // t=successor(root,y);
  // printf("\n%d",t->data);

}
