#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev,*next;
};
struct node *head==NULL,*last==NULL;
void create()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	int n;
	printf("Enter an element to create");
	scanf("%d",&n);
	temp->data=n;
	temp->prev=NULL;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		last=temp;
	}
	else
	{
			last->next=temp;
			temp->prev=last;
			last=temp;
	}
}
void insert()
{
	struct node *old,*cur,*temp;
	old=NULL;
	cur=head;
	int count=0,pos,ch,n;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter an element to insert\n");
	scanf("%d",&n);
	temp->data=n;
	temp->prev=NULL;
	temp->next=NULL;
	printf("\nInsert at\n1:First Node\n2:Last Node\n3:In between first and last node\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			temp->next=head;
			head->prev=temp;
			head=temp;
			break;
		case 2:
			last->next=temp;
			temp->prev=last;
			last=temp;
			break;
		case 3:
			printf("\nEnter the position to insert:");
			scanf("%d",&pos);
			while(count!=pos)
			{
				old=cur;
				cur=cur->next;
				count++;
			}
			if(count==pos)
			{
				temp->next=cur;
				cur->prev=temp;
				old->next=temp;
				temp->prev=old;
			}
			else
				printf("Not able to insert\n");
			break;
	}
}
void delete()
{
	struct node *old=NULL,*cur=head;
	int count=1,pos,ch;
	printf("\nDelete at \n1:First node\n2:Last node\n3:In between first and last node\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			if(head==NULL)
				printf("Not able to delete\n");
			else
			{
				printf("Deleted element is %d",head->data);
				if(head==last)
				{
					head=NULL;
					last=NULL;
				}
				else
				{
					head=head->next;
					head->prev=NULL;
				}
			}
			break;
		case 2:
			if(head==NULL)
				printf("Not able to delete\n");
			else
			{
				while(cur!=last)
				{
					old=cur;
					cur=cur->next;
				}
				if (cur==last)
				{
					printf("Deleted element is %d",cur->data);
					if(old==NULL)
						head=NULL;
					else
					{
						old->next=NULL;
						last=old;
					}
				}
			}
			break;
		case 3:
			printf("Enter position to delete\n");
			scanf("%d",&pos);
			if(head==NULL)
				printf("\nNot able to delete");
			else
			{
				while(count!=pos)
				{
					old=cur;
					cur=cur->next;
					count++;
				}
				if(count==pos)
				{
					printf("Deleted element is %d",cur->data);
					old->next=cur->next;
					(cur->next)->prev=old;
				}
			}
			break;
	}
}
void display()
{
	struct node *temp=head;
	if(temp=NULL)
		printf("\n List is empty");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		printf("-->");
		temp=temp->next;
	}
	printf("NULL");
}
void search()
{
	int value,pos=0;
	int flag=0;
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	printf("Enter the value to be searched:");
	scanf("%d",&value);
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		pos++;
		if(temp->data==value)
		{
			flag=1;
			printf("Element %d is Found at %d position",value,pos);
			return;
		}
		temp=temp->next;
	}
	if(!flag)
		printf("Element %d not Found in the List",value);
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n****MENU****");
		printf("\n1:Create\n2:Insert\n3:Delete\n4:Search\n5:Display\n6:Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
				
			case 2:
				insert();
				break;
				
			case 3:
				delete();
				break;
				
			case 4:
				search();
				break;
				
			case 5:
				display();
				break;
			case 6:
				return 0;
		}
	}
}
