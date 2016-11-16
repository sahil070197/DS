#include<stdio.h>
#include<string.h>
int top;
char pop(char s[]){
    if(top==-1){
        return '!';
    }
    return s[top--];
}
void push(char s[],char c){
    if(top<20){
        s[++top]=c;
    }
}
int main(){
    int k=0,i;
    top=-1;
    char s[20],temp[20];
    printf("enter the expression:");
    scanf("%s",&temp);
    i=strlen(temp);
    while(k<i){
        if(temp[k]=='(')
            push(s,'(');
        if(temp[k]==')'){
            if(top==-1){
                top=0;
                break;
            }
            else
                pop(s);
        }
        k++;

    }

    if(top==-1)
        printf("paired");
    else
        printf("not correct");

    return 0;
}
