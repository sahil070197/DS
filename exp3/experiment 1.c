#include<stdio.h>
int binsearch(int *a,int left,int right,int key)
{
    int mid;
    mid=(left+right)/2;
    if(left<right)
    {
        if(*(a+mid)==key)
            return 0;
        if(key<*(a+mid))
            return binsearch(a,left,mid-1,key);
        else
            return binsearch(a,mid+1,right,key);
    }
    return -1;
}
void main()
{
    int i,key,n,t=0;

    printf("\nenter the no of integers: ");
    scanf("%d",&n);
    int a[n];

    printf("\nenter the integers: ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    printf("\nenter the integer you want to search: ");
    scanf("%d",&key);

    printf("\nby linear search: ");

    for(i=0;i<n;i++)
    {
        if(a[i]==key){
            t=1;
            break;
        }

    }
    if(t==1)
        printf("%d",key);
    else
        printf("-1");

    printf("\nby binary search: ");
    t=binsearch(a,0,n-1,key);

    if(t==0)
        printf("%d",key);
    else
        printf("-1");



}
