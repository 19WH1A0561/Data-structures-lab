#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
int f=-1,r=-1,queue[maxsize];
int is_empty()
{
	if(f==-1)
	return 1;
	else
	return 0;
}
int is_full()
{
	if(r==maxsize-1)
	return 1;
	else
	return 0;
}
int enqueue(int x)
{
	if(f==-1)
		f=0;
	else
		queue[++r]=x;
}
int dequeue(int x)
{
	x=queue[f];
	if(f==r)
		f=r=-1;
	else
		f++;
	return x;
		
}
void display()
{
	int i;
	for(i=f;i<=r;i++)
	{
		printf("%d\t",queue[i]);
	}
	printf("\n");
	
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("queue implementation using array\n");
		printf("1-is_empty\n2-is_full\n3-display\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(is_full())
					printf("queue is overflow\n");
				   else
				   {
				   		printf("enter the element to insert\n");
				   		scanf("%d",&x);
				   		enqueue(x);
				   }
				   break;
			case 2:if(is_empty())
						printf("queue is underflow\n");
				   else
				   {
				   		printf("deleted element is %d\n",dequeue(x));
				   }
				   break;
			case 3:display();
					break;
			case 4:exit(0);
		}
	}
}
