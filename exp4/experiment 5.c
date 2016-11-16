#include<stdio.h>
void main()
{
    int n,i,j,k,h[10],p[10];

    printf("\nenter the order : ");
    scanf("%d",&n);

    int a[n][n];

     printf("\n enter the matrix: ");
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

    printf("\n\nupper left triangular");

    k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n-1-i;j++)
            h[k++]=a[i][j];
    }
    k=0;
    for(j=0;j<n;j++)
    {
        for(i=0;i<=n-1-j;i++)
            p[k++]=a[i][j];
    }

     printf("\n\naccording to row major");
    for(i=0;i<k;i++)
        printf(" %d",h[i]);

    printf("\naccording to column major");
    for(i=0;i<k;i++)
        printf(" %d",p[i]);
}
