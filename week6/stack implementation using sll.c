#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*top,*cur;
void push()
{
	int i,n;
	printf("enter number of nodes to push\n ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("enter the node to push\n");
		scanf("%d",&cur->data);
		cur->link=top;
		top=cur;
	}	
}
void pop()
{
	cur=top;
	top=cur->link;
	printf("deleted element is: %d\n",cur->data);
	cur->link=NULL;
	free(cur);
}
void display()
{
	if(top==NULL)
		printf("stack is underflow\n");
	else
		cur=top;
		while(cur!=NULL)
		{
			printf("%d\t",cur->data);
			cur=cur->link;
		}
		printf("\n");	
}
void peek()
{
	if(top!=NULL)
		printf("The peek element is %d\n",top->data);
	else
		exit(0);
}
int main()
{
	int ch;
	while(1)
	{
		printf("stack implementation using single linked list\n");
		printf("1-push\n2-pop\n3-peek\n4-display\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
				break;
			case 2:pop();       
				break;
			case 3:peek();
				break;
			case 4:display();
				break;
			case 5:exit(0);
		}
   }
}




