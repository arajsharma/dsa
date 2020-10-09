#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}Node;
Node *create(Node * head,int n);
Node *insertfirst(Node *head);
Node *deletefirst(Node *head);
Node *insertlast(Node *head);
Node *deletelast(Node *head);
Node *search(Node *head,int item);

void display(Node *head);
int main()
{
	Node *head=NULL;
	int n,item,ch;
	while(ch!=10)
	{
		printf("1.creation of linked list \n2.insertion of node at the beginning ");
		printf("\n3.deletion of node at the beginning \n4.insert the node at last ");
		printf("\n5.delete the node at the last \n6.search the data value");
		printf("\n7.display of linked list \n10.Quit  ");
		printf("\nenter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the num of node : ");
				scanf("%d",&n);
				head = create(head,n);
				break;
			case 2:
				head = insertfirst(head);
				printf("inserted!\n");
				break;
			case 3:
				head = deletefirst(head);
				printf("deleted !\n");
				break;
			case 4:
				head = insertlast(head);
				printf("inserted the node at last ! \n");
				break;
			case 5:
				deletelast(head);
				printf("deleted the last node !\n");
				break;	
			case 6:
				int item;
				printf("enter the no. for search : ");
				scanf("%d",&item);
				search(head,item);
				break;
			case 7:
				printf("list is : ");
				display(head);
				printf("\n");		
				break;
			case 10:
				printf("Quit ");
				break;
			default:
				break;
		}
	}
}
Node * create(Node *head,int n)
{
	Node *p,*curr;
	int i;
	for(i=0;i<n;i++)
	{
		curr= (Node *)malloc(sizeof(Node));
		if(curr==NULL)
		{
			printf("memory allocation fail ");
			return 0;
		}
		else
		{
			printf("enter the value of node : ");
			scanf("%d",&curr->data); 
		}
		if(head == NULL)
		{
			head = curr;
		}
		else
		{
			p->next=curr;
		}
		p=curr;
	}
	p->next=NULL;
	return head;
}
Node* insertfirst(Node * head )
{
	Node *curr;
	curr=(Node*)malloc(sizeof(Node));
	printf("enter the value for insertion : ");
	scanf("%d",&curr->data);
	curr->next=head;
	head = curr;
	return head;
	
}
Node *deletefirst(Node *head)
{
	Node * p;
	if(head == NULL)
	{
		printf("list is empty !");
	}
	else
	{
		p=head;
		head = head->next;
		p->next =NULL;
		free(p);
	}
	return head;
}
Node *insertlast(Node *head)
{
	Node * curr,*p;
	curr=(Node *)malloc(sizeof(Node));
	printf("enter the value of the node : ");
	scanf("%d",&curr->data);
	curr->next=NULL;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=curr;
	
	return head;
}
Node *deletelast(Node *head)
{
	Node *p,*tmp;
	p = head;
	while(p->next!=NULL)
	{
		tmp = p;
		p=p->next;
	}
	tmp->next=NULL;
	free(p);
	
	return head;
}
Node * search(Node *head,int item)
{
	Node *tmp,*p;
	int i;
	if(head ==NULL)
	{
		printf("list is empty .\n");
	}
	for(p=head;p!=NULL;p=p->next)
	{
		if(p->data==item)
			break;
	}
	if(p==NULL)
	{
		printf("item not found in the list .\n");
	}
	else
	{
		printf("item found!\n");
	}
	
}
void display(Node *head)
{
	Node * p;
	if(head == NULL)
	{
		printf("list is empty ! ");
	}
	for(p=head;p->next!=NULL;p=p->next)
	{
		printf(" %d ",p->data);
	}
	printf(" %d ",p->data);
}
