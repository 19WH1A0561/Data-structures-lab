#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*f=NULL,*r=NULL,*cur;
void enqueue()
{
	int i,n;
	printf("enter the no of nodes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("enter the node to push\n");
		scanf("%d",&cur->data);
		cur->link=NULL;
		if(f==NULL)
			f=r=cur;
		else
		{
			r->link=cur;
			r=cur;
		}
	}
}
void dequeue()
{
	if(f==NULL)
		printf("queue is underflow\n");
	else if(f==r)
	{
		printf("deleted data is %d\n",f->data);
		f=r=NULL;
	}
	else
	{
		cur=f;
		f=f->link;
		printf("deleted data is %d\n",cur->data);
		free(cur);
	}
}
void display()
{
	if(f==NULL)
		printf("queue is empty\n");
	else
	{
		cur=f;
		while(cur!=NULL)
		{
			printf("%d->",cur->data);
			cur=cur->link;
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("queue implementation using sll\n");
		printf("1-enqueue\n2-dequeue\n3-display\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	enqueue();
				break;
			case 2:dequeue();
				break;
			case 3:display();
				break;
			case 4:exit(0);
	    }
	}
}
