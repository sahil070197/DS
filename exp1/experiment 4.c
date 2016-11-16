#include<stdio.h>
void swap(int *x, int *y){
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
}
void main(){
    int a=10,b=20;
    printf("a=%d \n b=%d \n",a,b);
    swap(&a,&b);
     printf("a=%d \n b=%d \n",a,b);
}
