#include<stdio.h>
void swap(char *x,char *y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
quicksort(char *c,int left,int right)
{
    int i,j,pivot;
    if(left<right)
    {
        i=left;
        j=right+1;
        pivot=*(c+left);

        do{
            do{ i++;}
            while(*(c+i)<pivot);
            do {j--;}
            while(*(c+j)>pivot);

            if(i<j)
                swap((c+i),(c+j));
        }while(i<j);

        swap((c+left),(c+j));

        quicksort(c,left,j-1);
        quicksort(c,j+1,right);
    }
}
void main()
{
    int i,n;
    char c[10];

    printf("\nenter the no of characters: ");
    scanf("%d",&n);

    printf("\nenter the characters: ");

    for(i=0;i<n;i++)
        scanf("%c%c",&c[i],&c[i]);

    quicksort(c,0,n-1);

    printf("\nsorted sequence would be: ");

     for(i=0;i<n;i++)
        printf("\n%c",c[i]);
}
