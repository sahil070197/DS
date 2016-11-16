#include<stdio.h>
#include<string.h>
void strndel(char*s,int strt,int len){
    int i;
    while(len--){
        i=strt-1;
        while(s[i]!='\0'){
            s[i]=s[i+1];
            i++;
        }
    }
}
void main(){
    int t,strt,len;
    char s[30];
    printf("enter the no of cases");
    scanf("%d",&t);
    while(t--){
        printf("enter the string, start and length\n");
        scanf("%s%d%d",s,&strt,&len);
        strndel(s,strt,len);
        printf("\n%s",s);
    }
}
