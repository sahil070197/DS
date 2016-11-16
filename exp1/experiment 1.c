#include<stdio.h>
void strcount(void)
{
    char s[20];
    int i=0,a=1,j=0,k;

    printf("enter the string");
    scanf("%s",&s);

    while(s[i]!='\0')
    {
        j=i+1;
        while(s[j]!='\0')
        {
            if(s[i]==s[j])
               {
                   a=a+1;
                   k=j;
                   while(s[k]!='\0')
                   {
                       s[k]=s[k+1];
                       k++;
                   }
                   j--;


               }
                j++;
        }
        printf("The character %c appears %d times\n",s[i],a);
        a=1;
        i++;
    }


}
void main()
{
    int t;

    prinf("enter the no of cases");
    scanf("%d",&t);

    while(t--)
    strcount();

}
