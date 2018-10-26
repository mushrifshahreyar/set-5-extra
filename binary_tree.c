#include<stdio.h>
#include<stdlib.h>

struct Linked_List
{
	int data;
	struct Linked_List *left;
	struct Linked_List *right;
};

typedef struct Linked_List *node;

int left(int i)
{
	return 2*i;
}
int right(int i)
{
	return 2*i+1;
}

node Create_node()
{
	node temp;
	temp=(node)malloc(sizeof(struct Linked_List));
	if(temp == NULL)
	{
		printf("\nMemory not alloted");
		exit(0);
	}
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node insert(node head,int a[],int start,int end)
{
	printf("start: %d; end: %d;\n", start, end);
	if(start>end)
	{
		return NULL;
	}
	head=Create_node();
	head->data=a[start];
	if(left(start)<=end)
	{
		head->left=Create_node();
		head->left->data=a[left(start)];
	}
	else if(right(start)<=end)
	{
		head->right=Create_node();
		head->right->data=a[right(start)];
	}
	head->left=insert(head->left,a,left(start),end);
	head->right=insert(head->right,a,right(start),end);
	return head;
}
		
void in_order_print(node head)
{
	if(head!=NULL)
	{
		in_order_print(head->left);
		printf("%d ",head->data);
		in_order_print(head->right);
	}
}		

int main()
{
	int n;
	int a[100];
	node head=NULL;
	printf("\nn: ");
	scanf("%d",&n);	
	printf("\nA:\n");
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	//node array;
	head=insert(head,a,1,n);
	in_order_print(head);
}	
