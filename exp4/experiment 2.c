#include<stdio.h>
void main()
{
    int n,i,j,k,d[20],e[20];

    printf("\nenter the order of matrix: ");
    scanf("%d",&n);

    int a[n][n];

    printf("\nenter the matrix: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf(" %d",a[i][j]);
        printf("\n");
    }

     printf("\n\nupper right triangular");

    k=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
            d[k++]=a[i][j];
    }
    k=0;
    for(j=0;j<n;j++)
    {
        for(i=0;i<=j;i++)
            e[k++]=a[i][j];

    }

    printf("\n\naccording to row major");
    for(i=0;i<k;i++)
        printf(" %d",d[i]);
    printf("\naccording to column major");
    for(i=0;i<k;i++)
        printf(" %d",e[i]);


}
