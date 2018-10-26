#include<stdio.h>
#include<stdlib.h>

int partition(int a[],int p,int r)
{
	int swap;
	int x=a[r];
	int i=p-1;
	for(int j=p;j<r;++j)
	{
		if(a[j]<=x)
		{
			i=i+1;
			swap=a[j];
			a[j]=a[i];
			a[i]=swap;
		}
	}
	swap=a[i+1];
	a[i+1]=a[r];
	a[r]=swap;
	
	return i+1;
}
void quick_sort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}
	
void main()
{
	int n;
	int a[100];
	printf("\n n: ");
	scanf("%d",&n);
	printf("\nA: \n");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	quick_sort(a,0,n-1);
	printf("\nA: \n");

	for(int i=0;i<n;++i)
	{
		printf(" %d ",a[i]);
	}

}
