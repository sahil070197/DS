#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct student
     {
         char  name[10];
         int roll_no;
         int marks;

     };
    struct student *s;
    struct temp
    {
        char name[10];
        int roll_no;
        int marks;
    };
    struct temp *b;

 void merge(int low,int mid,int high)
{
    int i=low,j=mid+1,k,h=low;

    while((h<=mid)&&(j<=high))
    {
        if((s+h)->roll_no<=(s+j)->roll_no)
        {
            (b+i)->roll_no=(s+h)->roll_no;
           strcpy( (b+i)->name ,(s+h)->name);
            (b+i)->marks=(s+h)->marks;
            h++;
        }
        else
       {
        (b+i)->roll_no=(s+j)->roll_no;
        strcpy( (b+i)->name ,(s+j)->name);
        (b+i)->marks=(s+j)->marks;
        j++;

       }
        i++;

    }

    if(h>mid)
    {
        for(k=j;k<=high;k++)
           {
               (b+i)->roll_no=(s+k)->roll_no;
               strcpy( (b+i)->name ,(s+k)->name);
               (b+i)->marks=(s+k)->marks;
               i++;
           }
    }
    else
    {
        for(k=h;k<=mid;k++)
       {
        (b+i)->roll_no=(s+k)->roll_no;
        strcpy( (b+i)->name ,(s+k)->name);
        (b+i)->marks=(s+k)->marks;
        i++;
       }

    }
    for(k=low;k<=high;k++)
    {
        (s+k)->roll_no=(b+k)->roll_no;
        strcpy( (s+k)->name ,(b+k)->name);
        (s+k)->marks=(b+k)->marks;
    }

}
void merge_sort( int low,int high)
{
    int mid ;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}
void main()
{

     int i,n,low,high;

    printf("enter the no of students");
    scanf("%d",&n);

    s=(struct student*)malloc(n*sizeof(struct student));
    b=(struct temp*)malloc(n*sizeof(struct temp));

    printf("enter the student's name,roll no and marks");

    for(i=0;i<n;i++)
        scanf("%s%d%d",&(s+i)->name,&(s+i)->roll_no,&(s+i)->marks);

    low=0;
    high=n-1;

    merge_sort(low ,high);

    printf("\nROLL_NO\tNAME\tMARKS\n");

     for(i=0;i<n;i++)
    {
        printf("%d\t%s\t%d",(s+i)->roll_no,(s+i)->name,(s+i)->marks);
        printf("\n");
    }
}
