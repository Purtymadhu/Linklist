#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
	
};
struct Node *head=NULL;
struct Node *point,*curr,*prev;
int d;
void create_node(int d);
void insert_at_begin(int d);
void insert_at_mid();
void insert_at_end(int d);
void del_at_first();
void del_at_mid();
void del_at_last();
void traverse();
void count();
void search(int d);
void reverse();
void find_middle();
int main()
{
	int ch;
	printf("-----------Enter a choice give below------------\n");
	while(1)
	{
		printf("Enter your choice:\n");
		printf("1: create a node with first element at begin:\n");
		printf("2: insert at begginning:\n");
		printf("3: insert after a given node:\n");
		printf("4: insert at end:\n");
		printf("5: delete at first\n");
		printf("6: delete a node after a given node\n");
		printf("7: delete at end:\n");
		printf("8: view the list:\n");
		printf("9: length of a list:\n");
		printf("10: search an element:\n");
		printf("11: reverse a link list:\n");
		printf("12: middle of a link list:\n");
		printf("13: Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element:=  ");
				printf(" ");
				scanf("%d",&d);
				create_node(d);
				printf("-----Node created successfully-----\n");
				printf("\n\n");
				break;
			case 2:
				printf("Enter the element:=  ");
				printf(" ");
				scanf("%d",&d);
				insert_at_begin(d);
				printf("-----Element successfully inserted at begining----\n");
				printf("\n");
				break;
			case 3:
				insert_at_mid();
				printf("------Element successfully inserted after a given Node-----:\n");
				printf("\n");
				break;
			case 4:
				printf("Enter the element:=  ");
				printf(" ");
				scanf("%d",&d);
				insert_at_end(d);
				printf("------Element successfully inserted at end-----:\n");
				printf("\n");
				break;
			case 5:
				del_at_first();
				printf("------ first Element successfully deleted-----:\n");
				printf("\n");
				break;
			case 6:
				del_at_mid();
				printf("------Element successfully deleted after a given Node-----:\n");
				printf("\n");
				break;
			case 7:	
			   del_at_last();
			   	printf("------Element successfully deleted a last Node-----:\n");
			   	printf("\n");
				break;
			case 8:
				traverse();
				break;
			case 9:
				count();
				break;
			case 10:
				printf("enter an element to be search:\n");
				scanf("%d",&d);
				search(d);
			case 11: 
			        reverse();
			        break;
			case 12:
				    find_middle();
				    break;
			case 13:
				exit(1);
				break;
			default: printf("\n entered a wrong choice:");
			
				
		}
	}
	getch();
}
void create_node(int d)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=d;
	temp->next=NULL;
	head=temp;
}
void insert_at_begin(int d)
{
	struct Node *temp1=(struct Node*)malloc(sizeof(struct Node));
	if(head==NULL)
	{
		temp1->data=d;
		temp1->next=NULL;
		head=temp1;
	}
	else
	{
		temp1->data=d;
		temp1->next=head;
		head=temp1;
	}
}
void insert_at_mid()
{
	int n,ele;
	printf("Enter element which u want to be insert:\n");
	scanf("%d",&n);
	struct Node* temp2=(struct Node*)malloc(sizeof(struct Node));
	temp2->data=n;
	point=head;
	printf("Enter a element after which you want to be insert:\n");
	scanf("%d",&ele);
	while(point!=NULL)
	{
		if(point->data==ele)
		{
			temp2->next=point->next;
			point->next=temp2;
			
		}
		point=point->next;
	}
}
void insert_at_end(int d)
{
	struct Node* temp3=(struct Node*)malloc(sizeof(struct Node));
	temp3->data=d;
	temp3->next=NULL;
	point=head;
	while(point->next!=NULL)
	{
		point=point->next;
	}
	point->next=temp3;
}
void del_at_first()
{
	struct Node *t=head;
	head=head->next;
	free(t);
}
void del_at_last()
{
	struct Node *te=head;
	struct Node *pr;
	while(te->next!=NULL)
	{
		pr=te;
		te=te->next;
	}
	free(te);
	pr->next=NULL;
}
void del_at_mid()
{
	int d;
	printf("Enter the element you want to be delete:");
	scanf("%d",&d);
	if(head->data==d)
	{
		del_at_first();
	}
	else
	{
		prev=NULL;
		curr=head;
		while(curr->data!=d)
		{
			prev=curr;
			curr=curr->next;
		}
		prev->next=curr->next;
		free(curr);
	}
}
void traverse()
{
	if(head==NULL)
	{
		printf("list is empty:");
	}
	else
	{
		struct Node *t=head;
		printf("list is=:");
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
			
		}
		printf("\n");
	}
}
void count()
{
	int count=0;
	struct Node *ptr=head;
	if(head==NULL)
	{
	  printf("No elements avilaible\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			count=count+1;
			ptr=ptr->next;
		}
		printf("length of a link list is= %d\t",count);
	printf("\n");
	}
} 
void search(int d)
{
	struct Node *s=head;
	while(s!=NULL)
	{
		if(s->data==d)
		{
			printf("searched element is present in a list %d\n",d);
			break;
		}
		s=s->next;
	}
}
void reverse()
{
	struct Node* next;
curr=head;
prev=NULL;
while(curr!=NULL)
{
next=curr->next;
curr->next=prev;
prev=curr;
curr=next;
}
head=prev;
traverse();
}
void find_middle()
{
	struct Node *slwptr=head;
    struct Node *fastptr=head;
	if(head!=NULL)
	{
	  while(fastptr!=NULL && fastptr->next!=NULL)
	  {
	  	fastptr=fastptr->next->next;
	  	slwptr=slwptr->next;
	  }	
	  printf("The middle element is [%d]\n\n",slwptr->data);
	}
}
