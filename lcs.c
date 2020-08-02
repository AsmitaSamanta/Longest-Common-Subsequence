

	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	int main()
	{
		int i,j,k,l,m,n,**a;
		int *x,*y,*b;
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
		printf("\nThe computation matrix is :\n\n");
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
				printf("%d\t",a[i][j]);
			printf("\n\n");
		}
		printf("\nThe length of the longest subsequence is %d.\n",a[m][n]);
		i=m;
		j=n;
		l=a[m][n];
		b=(int *)malloc(l*(sizeof(int)));
		for(k=l;k>0;k--)
		{
			while(x[i-1]!=y[j-1])
			{
				if(a[i-1][j]<a[i][j-1])
					j--;
				else
					i--;
			}
			b[k-1]=x[i-1];
			i--;
			j--;
		}
		printf("One of the longest common subsequnce is : \t");
		for(i=0;i<l;i++)
			printf("%d  ",b[i]);
		printf("\n\n");
	}
	









