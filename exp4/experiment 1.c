#include<stdio.h>
void main()
{
    int n,i,j,k,f[20],g[20];

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

    printf("\n\nlower right triangular");

    k=0;
    for(i=0;i<n;i++)
    {
        for(j=n-1-i;j<n;j++)
            f[k++]=a[i][j];
    }

    k=0;
    for(j=0;j<n;j++)
    {
        for(i=n-1-j;i<n;i++)
        g[k++]=a[i][j];

    }

    printf("\n\naccording to row major");
    for(i=0;i<k;i++)
        printf(" %d",f[i]);

    printf("\naccording to column major");
    for(i=0;i<k;i++)
        printf(" %d",g[i]);


}
