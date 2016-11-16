#include<stdio.h>
void main(){
    int n,*a,i,j,k,m=0,*b,p;
    printf("enter the size of array");
    scanf("%d",&n);
    a=(int*) malloc(n*(sizeof(int)));
    b=(int*) malloc(n*(sizeof(int)));
    for(i=0;i<n;i++)
        scanf("%d",(a+i));
    for(i=0;i<n;i++){
        p=0;
        for(j=i+1;j<n;j++){
            if(*(a+i)==*(a+j)){
                p=p+1;
                for(k=j;k<n;k++)
                    *(a+k)=*(a+k+1);
                n--;
            }
        }
        if(p==0){
             *(b+m)=*(a+i);
             m++;
           }
    }
    printf("\n\n");
    printf("the no of non repeated elements in the array are %d\n ",m);
    printf("and they are\n");
    for(k=0;k<m;k++)
        printf("%d\n",*(b+k));
}
