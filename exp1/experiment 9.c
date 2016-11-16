#include<stdio.h>
void missing(int n){
    int a[n-1],i,k=0,b[n-1],j,m=1;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++,m++){
        if(a[i]!= m){
                b[k++]=m;
                m++;
            }
    }
    printf("\n\n\n\n");
    printf("the missing no are\n");
    for(j=0;j<k;j++)
        printf("%d\n",b[j]);
}
void main(){
    int n;
    printf("enter the value of n");
    scanf("%d",&n);
    missing(n);
}
