#include<stdio.h>
#include<string.h>
void main()
{
    int n,i,j,min;
    char v[10];

    printf("\nenter the no of strings: ");
    scanf("%d",&n);

    char s[n][10];

    printf("\nenter the strings: ");

    for(i=0;i<=n;i++)
        gets(s[i]);

    printf("\nby insertion sort: \n");

    for(i=0;i<=n;i++)
    {
        strcpy(v,s[i]);
        j=i;
        while((j>0)&&(strcmp(s[j-1],v)>0))
        {
            strcpy(s[j],s[j-1]);
            j--;
        }
        strcpy(s[j],v);
    }
    for(i=0;i<=n;i++)
        puts(s[i]);

    printf("\nby selection sort: \n");

    for(i=0;i<=n;i++)
    { min=i;
        for(j=i+1;j<=n;j++)
        {
            if(strcmp(s[j],s[min])<0)
                min=j;
        }
        strcpy(v,s[i]);
        strcpy(s[i],s[min]);
        strcpy(s[min],v);

    }
    for(i=0;i<=n;i++)
        puts(s[i]);

}

