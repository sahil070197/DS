#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void push(int);
int pop(void);
int preced(char);

int top=-1;
char infix[10],postfix[10],stacks[10];
void main()
{
    int i=0,a,b,c,d,j=0,e;

    printf("enter the infix expression\n");
    gets(infix);


    while(infix[i]!='\0')
    {
        if((infix[i]>='0')&&(infix[i]<='9'))
            postfix[j++]=infix[i];
        else
        {
            if(top==-1)
                push(infix[i]);
                else
                {

           if(preced(infix[i])>preced(stacks[top]))
           push(infix[i]);
           else
           {
               if(postfix[i]==')')
               {
                   while(stacks[top]!='(')
                   postfix[j++]=pop();
                   e=pop();
               }
               else
              {

              postfix[j++]=pop();
               push(infix[i]);
              }
           }
                }
        }
        i++;
    }
    while(top!=-1)
        postfix[j++]=pop();
    puts(postfix);
}
void push(int x)
{
    if(top==10)
        printf("stack is full");
    stacks[++top]=x;
}
int pop()
{
    if(top==-1)
        printf("stack is empty");
    return (stacks[top--]);
}
int preced(char z)
{
    if((z=='*')||(z=='/'))
        return 2;
    else if((z=='-')||(z=='+'))
        return 1;
        return 0;
}
