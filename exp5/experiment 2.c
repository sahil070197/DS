#include<stdio.h>
#include<string.h>
int top;
char pop(char s[]){
    if(top==-1){
        printf("the stack is empty!!");
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
    int k=0,len;
    top=-1;
    char s[20],temp[10],s2[20],c;

    printf("enter the string: ");
    gets(temp);

    len=strlen(temp);

    while(k<len){
        push(s,temp[k++]);

    }
    int i=0;
    while(top!=-1){
       s2[i++]= pop(s);
    }
    int j=0;
    while(j<i && s[j]==s2[j]){
        j++;

    }
    if(j!=i){
        printf("the string isnt palindrome\n");
    }
    else
        printf("the string is palindrome\n");

    return 0;
}
