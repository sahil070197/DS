#include<stdio.h>
int strdel(char*s ,char c){
    int i=0,a=0,j;
    while(*(s+i)!='\0'){
        if((*(s+i)==c) && (a==0)){
            j=i;
            while(*(s+j)!='\0'){
                *(s+j)=*(s+j+1);
                j++;
            }
            a=a+1;
        }
        i++;
    }
    return a;
}
void main(){
    int t,a;
    char s[20],c;
    printf("enter the no of cases");
    scanf("%d",&t);
    while(t--){
        printf("enter the string and character to be removed\n");
        scanf("%s %c",&s,&c);
       a= strdel(&s,c);
        if(a==1)
        printf("%s\n",s);
        else
        printf("the character is not in the given string\n");
    }
}
