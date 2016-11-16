#include<stdio.h>
void main(){
    int *a,i ,j,n;
     printf("enter the size of array\n");
     scanf("%d",&n);
     a= (int*) malloc(n*sizeof(int));
     for(i=0;i<n;i++)
     *(a+i)=i;
     printf("The original array is\n");
     for(i=0;i<n;i++)
     printf(" %d",*(a+i));
     printf("\n");
     j=n-1;
     for(i=0;i<n/2;i++,j--){
         *(a+i)=*(a+i)+*(a+j);
         *(a+j)=*(a+i)-*(a+j);
         *(a+i)=*(a+i)-*(a+j);
     }
     printf("The reversed array is\n");
     for(i=0;i<n;i++)
     printf(" %d",*(a+i));
}
