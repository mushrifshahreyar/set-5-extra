#include<stdio.h>
#include<stdlib.h>

int parent(int i)
{
	return i/2;
}
int left(int i)
{
	return 2*i;
}
int right(int i)
{
	return 2*i+1;
}

void m_heapify(int a[],int i, int heapify)
{
	int l=left(i);
	int r=right(i);
	int largest=i;
	if(l<heapify && a[l]>a[largest])
	{
		largest=l;
	}
	if(r<heapify && a[r]>a[largest])
	{
		largest=r;
	}
	if(largest != i)
	{
		int swap=a[largest];
		a[largest]=a[i];
		a[i]=swap;
	
		m_heapify(a,largest,heapify);
	}
}

void build_max_heap(int a[],int n)
{
	int heapify=n;
	for(int i=n/2;i>=1;--i)
	{
		m_heapify(a,i,heapify);
	}
}
void heap_sort(int a[],int n)
{
	int heapify=n;
	build_max_heap(a,n);
	for(int i=n;i>=2;--i)
	{
		int swap=a[i];
		a[i]=a[1];
		a[1]=swap;
		
		heapify=heapify-1;
		m_heapify(a,1,heapify);
	}
}
	
void main()
{
	int n;
	int a[100];
	printf("\n n: ");
	scanf("%d",&n);
	
	printf("\nA :\n");
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	heap_sort(a,n);
	printf("\n");
	for(int i=1;i<=n;++i)
	{
		printf(" %d ",a[i]);
	}
}
