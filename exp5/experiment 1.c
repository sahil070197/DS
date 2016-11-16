#include <stdio.h>
int top,n;
void isFull(){
    if(top==n-1)
        printf("the stack is full\n");
    else
        printf("the stack isnt yet full\n");


}
void isEmpty(){
    if(top==-1)
        printf("the stack is empty\n");
    else
        printf("the stack isnt yet empty\n");
}
int pop(int s[]){
    if(top==-1){
        printf("the stack is empty!!");
        return 0;
    }
    printf("the topmost element was:%d\n",s[top]);
    return s[top--];
}
void push(int s[]){
    if(top==n-1)
        printf("stack if full!!\n");
    else
        printf("enter the element:");
        scanf("%d",&s[++top]);

}
void create(){

    int temp;
    top=-1;
    printf("enter the maximum size of stack:");
    scanf("%d",&n);
    int s[n];
    while(1)
    {
        printf("press\n 1 if you want to push element in stack \n  0 to pop the topmost element of stack \n press 9 to exit:");
        scanf("%d",&temp);
        if(temp==9)
            break;
        else{
            if(temp==1)
            push(s);
            else
                pop(s);
        }
    }

}
int main(){
    int temp,temp2=1;
    printf("if you want to create a stack press 1 :");
    scanf("%d",&temp);
    if(temp==1)
    { create();
            printf("to check whether the stack is empty press 1,the stack is full pr22 2 :");
            scanf("%d",&temp2);

            if(temp2==1)
                isEmpty();
            if(temp2==2)
                isFull();
    }

    return 0;
}
