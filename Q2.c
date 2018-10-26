#include<stdio.h>
#include<stdlib.h>

void increment(int *a,int k,int n)
{
	for(int i=0;i<n;++i)
	{
		if(a[i]==-1)
		{
			continue;
		}
		a[i]=a[i]+k;
	}
}

void inorder_print(int *a,int n,int i)
{
	//printf("n: %d; i: %d;\n", n, i);
	if(i<n)
	{
		inorder_print(a,n,2*i+1);
		if(a[i]!=-1)
		{
			printf(" %d ",a[i]);
		}
		inorder_print(a,n,2*i+2);
	}
}
void main(int argc,char *argv[])
{	
	int *a;
	int n,k;	
	char c;
	FILE *f;
	
	f=fopen(argv[1],"r");
	
	while(1)
	{
		fscanf(f,"%c",&c);
		if(feof(f))
		{
			break;
		}
		if(c == '\n' || c==' ')
			continue;
		if(c == 'c')	
		{
			fscanf(f,"%d",&n);
			a=(int *)malloc(n*sizeof(int));
			for(int i=0;i<n;++i)
			{
				fscanf(f,"%d",&a[i]);
			}
		}
		else if(c == 'p')
		{
			printf("\n");
			for(int i=0;i<n;++i)
			{
				printf(" %d ",a[i]);
			}
		}
		else if(c == 'a')
		{
			fscanf(f,"%d",&k);
			increment(a,k,n);
		}
		else if(c == 'i')
		{
			inorder_print(a,n,0);
		}
		else
		{
			printf("\nPlease enter a valid character\n");
		}
	}
	fclose(f);
}
