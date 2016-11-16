#include<stdio.h>
void main()
{
    int n,i,j,k,b[10],c[10];

    printf("\nenter the order of matrix: ");
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

     printf("\n\nlower left triangular");
    k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            b[k]=a[i][j];
            k++;
        }
    }
    k=0;
    for(j=0;j<n;j++)
    {
        for(i=j;i<n;i++)
        {
            c[k]=a[i][j];
            k++;
        }
    }
    printf("\n\naccording to row major:");
    for(i=0;i<k;i++)
        printf(" %d",b[i]);

    printf("\nacoording to column major:");
    for(i=0;i<k;i++)
        printf(" %d",c[i]);


}
