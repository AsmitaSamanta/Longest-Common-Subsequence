#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
int i,j,k,m,n,**a;
int *x,*y;
printf("\nEnter the length of the strings x and y :");
scanf("%d%d",&m,&n);
x=(int *)malloc(m*(sizeof(int)));
y=(int *)malloc(n*(sizeof(int)));
printf("\nEnter the string x :");
for(i=0;i<m;i++)
	scanf("%d",&x[i]);

printf("\nEnter the string y :");
for(i=0;i<n;i++)
	scanf("%d",&y[i]);

printf("\ncheck\n");

a=(int **)malloc((m+1)*(sizeof(int *)));
for(i=0;i<=m;i++)
	a[i]=(int *)malloc((n+1)*(sizeof(int)));
for(i=0;i<=m;i++)
	for(j=0;j<=n;j++)
	{
		if(i==0 || j==0)
			a[i][j]=0;
		else
		{
			if(x[i-1]==y[j-1])
				a[i][j]=a[(i-1)][(j-1)]+1;
			else
			{
				if(a[i][(j-1)]<a[(i-1)][j])
					a[i][j]=a[(i-1)][j];
				else
					a[i][j]=a[i][(j-1)];
				
			}
		}
	}

for(i=0;i<=m;i++)
{
	for(j=0;j<=n;j++)
		printf("%d\t",a[i][j]);
	printf("\n");
}

printf("\nThe length of the longest subsequence is %d.\n",a[m][n]);

i=m;
j=n;
for(k=a[m][n];k>0;k--)
{
	while(x[i-1]!=y[j-1])
	{
		if(a[i-1][j]<a[i][j-1])
			j--;
		else
			i--;
	}
	printf("%d  ",x[i-1]);
	i--;
	j--;
}

}










