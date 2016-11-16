#include<stdio.h>
#include<stdlib.h>

struct element
{
	int row,col,val;
};

struct element t[20],r[20],add[20];

void create(int a[][10],int n,int m,int ctr,element t[])
{
	int i,j,k=1;
	t[0].row=n;
	t[0].col=m;
	t[0].val=ctr;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]!=0)
			{
				t[k].val=a[i][j];
				t[k].row=i;
				t[k++].col=j;
			}
		}
	}
}
 
void add_sparse(element t[],element r[],int n,int m)
{
	int i,j,k=1,f;
	int *flag;
	flag=(int *)calloc(m,sizeof(int));
	add[0].row=t[0].row;
	add[0].col=t[0].col;
	for(i=1;i<=n;i++)
	{
		f=0;
		for(j=1;j<=m;j++)
		{
			if(t[i].row==r[j].row&&t[i].col==r[j].col)
			{
				add[k].row=t[i].row;
				add[k].col=t[i].col;
				add[k++].val=t[i].val+r[j].val;
				flag[j-1]=1;
				f=1;
			}
		}
		if(f==0)
		{
			add[k].row=t[i].row;
			add[k].col=t[i].col;
			add[k++].val=t[i].val;	
		}
	}
	for(j=1;j<=m;j++)
	{
		if(flag[j-1]==0)
		{
			add[k].row=r[j].row;
			add[k].col=r[j].col;
			add[k++].val=r[j].val;
		}
	}
	add[0].val=k-1;
}

int main()
{
	int n,m,i,j,ctr_1=0,ctr_2=0,p,q;
	int a[10][10],b[10][10];
	printf("Enter rows and columns in first matrix :");
	scanf("%d%d",&n,&m);
	printf("\nEnter size of second matrix :");
	scanf("%d%d",&p,&q);
	if(n==p&&m==q)
	{
		printf("Enter elements of first matrix :");
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]!=0)
					ctr_1++;
			}
		}
		create(a,n,m,ctr_1,t);
		printf("\nSparse Matrix form :\n");
		for(i=0;i<=ctr_1;i++)
		
		{
			printf("%d %d %d",t[i].row,t[i].col,t[i].val);
			printf("\n");
		}
		printf("\nEnter elements of second matrix :");
		for(i=0;i<n;i++)
		{	
			for(j=0;j<m;j++)
			{
				scanf("%d",&b[i][j]);
				if(a[i][j]!=0)
					ctr_2++;
			}
		}
		create(b,p,q,ctr_2,r);
		printf("\nSparse Matrix form :\n");
		for(i=0;i<=ctr_2;i++)
		{
			printf("%d %d %d",r[i].row,r[i].col,r[i].val);
			printf("\n");
		}
		add_sparse(t,r,ctr_1,ctr_2);
		printf("\nAddition :\n");
		for(i=0;i<=add[0].val;i++)
			printf("%d %d %d\n",add[i].row,add[i].col,add[i].val);
	}
	else
		printf("Matrices can not be added");
	return 0;
}
