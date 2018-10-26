#include<stdio.h>
#include<stdlib.h>

struct Linked_List
{
	char c;
	int x;
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

void main(int argc,char *argv[])
{
	int n;
	char c;
	node head=NULL;
	node array=NULL;
	head=Create_node();
	array=head;
	FILE *fp;
	fp=fopen(argv[1],"r");
	while(1)
	{
		fscanf(fp,"%c",&c);
		if(feof(fp))
		{
			break;
		}
		if(c == '\n'||c == ' ')
		{
			continue;
		}
		
		fscanf(fp,"%d",&n);
		array->next=Create_node();
		array=array->next;
		array->c=c;
		array->x=n;
	}
	head=head->next;
	array=head;
	while(array!=NULL)
	{
		printf("%c %d\n",array->c,array->x);
		array=array->next;
	}
}
