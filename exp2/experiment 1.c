#include <stdio.h>
int main(){
    int n;
    printf("enter the size of arrays:");
    scanf("%d",&n);
    int i=0,a[n],b[n],c[2*n];
    printf("enter the elements of first array:\n");
    while(i<n)
        scanf("%d",&a[i++]);
    i=0;
    printf("enter the elements of second array:\n");
    while(i<n)
        scanf("%d",&b[i++]);
    int j=0,k=0;
    i=0;
    while(i<n && j<n){
        if(a[i]<b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }
    while(j<n)
        c[k++]=b[j++];
    while(i<n)
        c[k++]=a[i++];
    float med;
    i=0;
    while(i<2*n)
        printf("%d ",c[i++]);
    printf("\n");
    med=(float)(c[n]+c[n-1])/2;
    printf("the median of the sorted array would be:%f\n",med);
    return 0;
}
