#include <stdio.h>
#include <stdlib.h>
#define pf(x) printf("%d  ",x)

typedef struct node
{
    int data;
    struct node *next;
}node;
node* init()
{
    return 0;
}
void push(node**t,int x)
{
    node*p=(node*)malloc(sizeof(node));
    p->data=x;
    p->next=*t;
    *t=p;
}
int pop(node **t)
{
    node *p=*t;
    int x=p->data;
    *t=(*t)->next;
    free(p);
    return x;
}
void disp(node*t)
{
    if(!t)
    return;
    {
        disp(t->next);
        pf(t->data);
       
    }
}

int main()
{
	node *top=init();
	node **add=&top;
	push(add,15);
	push(add,26);
	push(add,72);
	push(add,34);
	disp(top);
	pf(pop(add));
	pf(pop(add));
	disp(top);
	
	
	return 0;
}
