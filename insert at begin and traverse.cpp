#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *head;
int main()
{
	void insert(int x);
	void print();
	head=NULL;
	int n,i,x;
	printf("How many numbers you may want to insert in link list");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the numbers:");
		scanf("%d",&x);
		insert(x);
		print();
	}
	
}
void insert(int x)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	if(head==NULL)
	{
	temp->data=x;
	temp->next=NULL;
	head=temp;
    }
    else
    {
    	temp->data=x;
    	temp->next=head;
    	head=temp;
    }
	
}
void print()
{
	struct Node *link;
	link=head;
	printf("List is:");
	while(link!=NULL)
	{
		printf("%d\t",link->data);
		link=link->next;
	}
	printf("\n");
}
