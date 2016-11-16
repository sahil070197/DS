#include<stdio.h>
int main(){
    int n,i,j;
    printf("enter the order of matrix:");
    scanf("%d",&n);
    int a[n][n];
    printf("enter the elements of matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
    {   for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("the tri diagonal elements in row major format:\n");
    for(i=0;i<n;i++)
        for(j=i-1;j<=i+1;j++)
        {if( (j==-1) || (j==n))
            continue;
            printf("%d ",a[i][j]);
        }
    printf("\n");
    printf("the tri diagonal elements in column major format:\n");
    for(i=0;i<n;i++)
        for(j=i-1;j<=i+1;j++)
        {if( (j==-1) || (j==n))
            continue;
            printf("%d ",a[j][i]);
        }
    printf("\n");

    return 0;
}
