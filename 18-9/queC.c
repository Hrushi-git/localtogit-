#include<stdio.h>
#define MAX 10
typedef struct queue
{
	int A[MAX],r,f;
	
}queue;
void init(queue *q)
{
	q->r=q->f=-1;
}
int full(queue *Q)
{
	if(Q->r==MAX-1)
	return 1;
	return 0;
}
int empty(queue *Q)
{
	if(Q->r==-1)
	return 1;
	return 0;
}
void enque(queue *q,int x)
{
	if(full(q))
	{
		printf("Full\n");
		return;
	}
	if(empty(q))
	{
		(q->f)++;
	}
	(q->r)++;
	q->A[q->r]=x;
}
int deque(queue *q)
{
	if(empty(q))
	{
		printf("Empty\n");
		return ;
	}
	int x=q->A[q->f];
}
int main()
{
	queue Q;
	init(&Q);
	int y;
	do
	{
		printf("1.enque\n2.deque\n3.disp\n");
		printf("Choice :");scanf("%d",&y);
		switch(y)
		{
			case 1:
			{
				printf("Enter :");
				int x;
				scanf("%d",&x);
				enque(&Q,x);
			}break;
			case 2:
			{
			
			}break;
			case 3:
			{
			
			}break;
		}
	}while(y);	
}
