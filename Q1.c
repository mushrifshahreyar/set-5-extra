#include<stdio.h>
#include<stdlib.h>

struct Linked_List
{	
	int data;
	struct Linked_List *next;
};

typedef struct Linked_List *node;

node Create_node()
{
	node temp;
	temp=(node)malloc(sizeof(struct Linked_List));
	if(temp == NULL)
	{
		printf("\nMemory not alloted");
		exit(0);
	}
	temp->next = NULL;
	return temp;
}

node push(node head, int n)
{
	node array;	
	if(head == NULL)
	{
		head=Create_node();
		array=head;
		array->data=n;
	}
	else
	{
		array=head;
		while(array->next != NULL)
		{
			array=array->next;
		}
		array->next=Create_node();
		array=array->next;
		array->data=n;

	}
	return head;
}

node pull(node head,char *new)
{
	node array=head;
	
	FILE *f;
	f=fopen(new,"a");
	fprintf(f,"\n");
	if(array == NULL)
	{
		fprintf(f,"UNDERFLOW");
		return NULL;
	}
	if(head->next == NULL)
	{
		head = NULL;
	}
	else
	{
		while(array->next->next != NULL)
		{
			array=array->next;
		}
		array->next = NULL;
		return head;
	}
	fclose(f);
}
void print(node head,char *new)
{
	FILE *fp;
	fp=fopen(new,"a");
	node t=head;
	fprintf(fp,"\n");
	if(head == NULL)
	{
		//printf("\n-1");
		fprintf(fp,"EMPTY LIST");
		return;
	}
	else
	{
		while(t != NULL)
		{
			//printf(" %d ",t->data);
			fprintf(fp," %d ",t->data);
			t=t->next;
		}
	}
	fclose(fp);
}
		
void main(int argc,char *argv[])
{
	FILE *f;
	node head=NULL;
	f=fopen(argv[1],"r");
	char c;
	int n;
	while(1)
	{
		if(feof(f))
		{
			break;
		}
		fscanf(f,"%c",&c);
		if(c == '\n'||c==' ')
		{
			continue;
		}
		printf("\nc =%c",c);
		if(c == 'e')
		{
			fscanf(f,"%d",&n);
			head=push(head,n);
		}
		else if(c == 'd')
		{
			head=pull(head,argv[2]);
		}
		else if(c == 'p')
		{
			print(head,argv[2]);
		}
		else if(c =='s')
		{
			printf("\nThank you for using the program\n");
			break;
		}
		else
		{
			printf("\nPlease enter a valid value");
		}
	}
}
