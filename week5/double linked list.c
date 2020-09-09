#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next,*prev;
};
struct node*head=NULL,*tail=NULL,*cur,*t1,*t2;
void create()
{
    int i,n;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("enter current node data\n");
		scanf("%d",&cur->data);
		cur->prev=NULL;
		cur->next=NULL;
		if(head==NULL)
			head=tail=cur;
		else
		{
			tail->next=cur;
			cur->prev=tail;
			tail=cur;
		}
	}
}
void insert_at_begin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the data to insert at begin\n");
	scanf("%d",&cur->data);
	cur->prev=NULL;
	cur->next=head;
	head->prev=cur;
	head=cur;
}
void insert_at_end()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the data to insert at end\n");
	scanf("%d",&cur->data);
	cur->next=NULL;
	cur->prev=tail;
	tail->next=cur;
	tail=cur;
}
void insert_at_given_pos()
{
	int pos,c=1;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the data to insert at position\n");
	scanf("%d",&cur->data);
	printf("enter the pos\n");
	scanf("%d",&pos);
	t1=head;
	while(c<pos&&t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
		c++;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
}
void insert_before_given_node()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&cur->data);
	printf("enter the data to insert before which node\n");
	scanf("%d",&value);
	t1=head;
	while(t1->data!=value && t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next=cur;
	cur->prev=t2;
	cur->next=t1;
	t1->prev=cur;
}
void insert_after_given_node()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&cur->data);
	printf("enter the data to insert after given  node\n");
	scanf("%d",&value);
	t1=head;
	while(t1->data!=value && t1!=NULL)
	{
		t1=t1->next;
	}
	cur->next=t1->next;
	t1->next->prev=cur;
	t1->next=cur;
	cur->prev=t1;
}
void deletion_at_begin()
{
	printf("enter the data\n");
	cur=head;
	head->prev=NULL;
	printf("deleted elementis %d\n",cur->data);
	cur->next=NULL;
	free(cur);
}
void deletion_at_end()
{
	printf("enter the data\n");
	cur=tail;
	tail=tail->prev;
	tail->next=NULL;
	cur->prev=NULL;
	printf("deleted data is %d\n",cur->data);
	free(cur);
}

void deletion_at_given_pos()
{
	int c=1,pos;
	printf("enter the position of deletioin\n");
	scanf("%d",&pos);
	t1=head;
	while(c<pos&&t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
		c++;
	}
	t2->next=t1->next;
	t1->next->prev=t2;
	printf("deleted element is %d\n",t1->data);
	free(t1);
}
void deletion_after_given_node()
{
	int value;
	printf("enter the data after which node to be delete\n");
	scanf("%d",&value);
	t1=head;
	while(t1!=NULL&&t1->data!=value)
	{
		t1=t1->next;
	}
	t2=t1->next;
	t1->next=t2->next;
	t2->next->prev=t1;
	printf("deleted element is %d\n",t2->data);
	free(t2);
	
}

void deletion_before_given_node()
{
	int value;
	printf("enter the data before which node to be delete\n");
	scanf("%d",&value);
	t1=head;
	while(t1->next->data!=value&&t1->next!=NULL)
	{
		t2=t1;
		t1=t1->next;	
	}
	t2->next=t1->next;
	t1->next->prev=t2;
	printf("deleted element is %d\n",t1->data);
	free(t1);
}
void display_in_forward()
{
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		cur=head;
		while(cur!=NULL)
		{
			printf("%d<->",cur->data);
			cur=cur->next;
		}
	}
}
void display_in_reverse(struct node*head)
{
	if(head==NULL)
	{
			printf("list is empty\n");
	}
	else
	{
		cur=tail;
		while(cur!=NULL)
		{
			printf("%d<->",cur->data);
			cur=cur->prev;
		}
	}
}
void search()
{
	int value,flag=0,c=1;
	printf("enter the value to search\n");
	scanf("%d",&value);
	t1=head;
	while(t1!=NULL)
	{
		if(t1->data==value)
		{
			flag=1;
			break;
		}
		t1=t1->next;
		c++;
	}
	if(flag==1)
		printf("element present at %d position\n",c);
	else
		printf("element not found\n");
}
/*void sorting()
{
	int i,t;
	struct node*p1,*p2;
	p1=head;
	int c=0;
	while(p1!=NULL)
	{
		c++;
		p1=p1->link;
	}
	for(i=0;i<c;i++)
	{
		p2=head;
		while(p2->link!=NULL)
		{
		
			if(p2->data>p2->link->data)
			{	
				t=p2->data;
				p2->data=p2->link->data;
				p2->link->data=t;
			}	
			p2=p2->link;
    	}
	}
}*/
int main()
{
	int ch;
	while(1)
	{
		printf("program for double linked list\n");
		printf("1-create\n2-insert_at_begin\n3-insert_at_end\n4-insert_at_given_pos\n5-insert_before_given_node\n6-insert_after_given_node\n");
		printf("7-deletion_at_begin\n8-deletion_at_end\n9-deletion_at_given_pos\n10-deletion_before_given_node\n11-deletion_after_given_node\n");
		printf("12-display\n13-display_in_reverse\n14-search\n15-sorting\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: insert_at_begin();
				break;
			case 3: insert_at_end();
				break;
			case 4: insert_at_given_pos();
				break;
			case 5: insert_before_given_node();
				break;
			case 6: insert_after_given_node();
				break;
			case 7: deletion_at_begin();
				break;
			case 8: deletion_at_end();
				break;
			case 9: deletion_at_given_pos();
				break;
			case 10: deletion_before_given_node();
				break;
			case 11: deletion_after_given_node();
				break;
			case 12: display_in_forward();
				break;
			case 13: display_in_reverse(head);
				break;
			case 14: search();
				break;
			case 15: exit(0);
		}
		}
}
	
