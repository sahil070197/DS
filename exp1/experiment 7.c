#include<stdio.h>
#include<string.h>
void swap(char *x,char*y){
    char temp;
    int i=0;
    while(*(x+i)!='\0'){
        temp=*(x+i);
        *(x+i)=*(y+i);
        *(y+i)=temp;
        i++;
    }
    *(y+i)=NULL;
}
void main (){
    char s1[20],s2[20];
    printf("enter the two strings\n");
    scanf("%s%s",&s1,&s2);
    printf("string 1 is \n %s\n",s1);
    printf("string 2 is \n %s\n",s2);
    if(strlen(s1)>strlen(s2))
    swap(&s1[0],&s2[0]);
    else
    swap(&s2[0],&s1[0]);
    printf("\n\n\n\n");
    printf("string 1 is \n %s\n",s1);
    printf("string 2 is \n %s\n",s2);
}

