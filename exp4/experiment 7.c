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
        printf("%d\t     ",a[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("\n");
    printf("\nIn row major format:\n");
    for(i=0;i<n;i++)
    {   for(j=0;j<n;j++){
        if(a[i][j]==0){
            continue;
        }

        printf(" %d",a[i][j]);
    }
    }
    printf("\n");
    printf("\n In column major format:\n");
    for(i=0;i<n;i++)
    {   for(j=0;j<n;j++){
        if(a[j][i]==0){
            continue;
        }

        printf(" %d",a[j][i]);
    }
    }


    printf("\n");

    return 0;
}

