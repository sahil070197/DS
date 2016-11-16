#include<stdio.h>
swap(int *a,int *b)
{
    int i,temp;
    for(i=0;i<10;i++)
    {
        temp=*(a+i);
        *(a+i)=*(b+i);
        *(b+i)=temp;
    }

}
void main()
{
    int a[10],b[10],i;
    for(i=0;i<10;i++)
    {
        a[i]=i;
        b[i]=10+i;
    }
     printf("\narray A is\n");
    for(i=0;i<10;i++)
        printf(" %d",a[i]);
        printf("\narray B is\n");
    for(i=0;i<10;i++)
        printf(" %d",b[i]);
        swap(&a[0],&b[0]);
         printf("\narray A is\n");
    for(i=0;i<10;i++)
        printf(" %d",a[i]);
        printf("\narray B is\n");
    for(i=0;i<10;i++)
        printf(" %d",b[i]);
}
