#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};
struct Node *head;
int d;
void Getnewnode(int d);
void insertAtHead(int d);
void insertAtEnd(int d);
void aftergivenNode();
void beforegiveNode();
void print();
void reverseprint();
int main()
{
	int ch;
	while(1)
	{
		printf("Enter your choice:\n");
		printf("1: create a node with first element at begin:\n");
		printf("2: insert at begin\n");
		printf("3: insert at end:\n");
		printf("4: insert after a given node\n");
		printf("5: insert before given node:\n");
		printf("6: print the element:\n");
		printf("7: Reverse the element:\n");
		printf("8: exit:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element=:\n ");
				printf(" ");
				scanf("%d",&d);
				Getnewnode(d);
				break;
			case 2:
				printf("Enter the element:=\n");
				printf(" ");
				scanf("%d",&d);
				insertAtHead(d);
				break;
				
			case 3:
			    printf("Enter the element:\n");
				printf(" ");
				scanf("%d",&d);
				insertAtEnd(d);
				break;
				
			case 4:
			    aftergivenNode();
			    break;
				
			case 5:
				 beforegiveNode();
					break;
			case 6:
				print();
				break;
			case 7:
			    reverseprint();
				break;
			
			case 8:
				exit(1);
				break;
				
			default: printf("you entered a wrong choice:");
		}
		
	}
	getch();
}
void  Getnewnode(int x)
{
	struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=x;
	newnode->prev=NULL;
	newnode->next=NULL;
	head=newnode;
}
void insertAtHead(int x)
{
	struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
	if(head==NULL)
	{
     printf("no element available");
    }
    else
    {
    	newnode->data=x;
    	head->prev=newnode;
    	newnode->next=head;
    	head=newnode;
    }
}

void insertAtEnd(int x)
{
	struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
	struct Node* temp=head;
	newnode->data=x;
	newnode->next=NULL;
	if(head==NULL)
	{
		newnode->prev=NULL;
		head=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
	}
}
	
void aftergivenNode()
{
		int n,ele;
		struct Node*point=head;
				printf("Enter a element which you want to insert:\n");
				scanf("%d",&n);
				struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
				temp->data=n;
				printf("Enter element after which you want to be insert:\n");
				scanf("%d",&ele);
			if(point==NULL)
			{
				printf("No Node available:");
			}
			else
			{
				while(point!=NULL)
				{
					if(point->data==ele)
					{
					temp->next=point->next;
					point->next=temp;
					temp->prev=point;
					}
					else if(temp->next!=NULL)
					{
						temp->next->prev=temp;
					}
					point=point->next;
					
				}
			}
}
void beforegiveNode()
{
	int n,ele;
	printf("Enter element you want to be insert:\n");
	scanf("%d",&n);
	printf("Enter element before you want to be insert:\n");
	scanf("%d",&ele);
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=n;
	struct Node* point=head;
		if(point==NULL)
			{
				printf("No Node available:");
			}
     	else
     	{
     		
	    while(point!=NULL)
	    {
		if(point->data==ele)
		{
			temp->prev=point->prev;
			temp->next=point;
			point->prev=temp;
		}
		else if(temp->prev!=NULL)
		{
			temp->prev->next=temp;
		}
		point=point->next;
  		}
 }
}

void print()
{
	struct Node *temp=head;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void reverseprint()
{
	struct Node* temp=head;
	if(temp==NULL)
	printf("Element is not avlbl");
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	printf("Reverse\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->prev;
	}
}
