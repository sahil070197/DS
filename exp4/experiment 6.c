#include<stdio.h>
void main()
{
    int n,i,j,k,r[20],q[20],o;

    printf("enter the order: ");
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

      printf("\n\n in c shape");

        k=0;
        for(i=0;i<n;i++)
        {
            if((i==0)||(i==n-1))
                o=n-1;
            else
                o=0;
            for(j=0;j<=o;j++)
                r[k++]=a[i][j];
        }

        k=0;
        for(j=0;j<n;j++)
        {
            if(j==0)
            {
                for(i=0;i<n;i++)
                    q[k++]=a[i][j];
            }
            else
           {

            q[k++]=a[0][j];
            q[k++]=a[n-1][j];
           }

        }

         printf("\n\naccording to row major");
    for(i=0;i<k;i++)
        printf(" %d",r[i]);

    printf("\naccording to column major");
    for(i=0;i<k;i++)
        printf(" %d",q[i]);

}
