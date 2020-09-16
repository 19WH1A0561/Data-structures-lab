#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
int a[maxsize],top=-1;
void push(int item)
{
	top++;
	a[top]=item;
}
int pop()
{
	return a[top--];
}
int is_full()
{
	if(top==maxsize-1)
	return 1;
	else
	return 0;
}
int is_empty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int peek()
{
	return a[top];
}
void display()
{
	int i;
	for(i=top;i>=0;i--)
	{
     	printf("%d\n",a[i]);
    }
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("stack implementation using arrays\n");
		printf("1-push\n2-pop\n3-peek\n4-display\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(is_full())
			    printf("stack overflow\n");
			    else
			    {
			    	printf("enter data to push\n");
			    	scanf("%d",&x);
			    	push(x);
				}
				break;
			case 2:if(is_empty())
				printf("stack underflow\n");
				else
				{
					x=pop();
					printf("deleted element is %d\n",x);
				}
				break;
			case 3:display();
				break;
			case 4:printf("top most element on the stack is %d\n",peek());
				break;
				case 5:exit(0);
	    }
	}
}
