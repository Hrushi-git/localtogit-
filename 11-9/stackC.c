#include <stdio.h>
#define MAX 10
typedef struct
{
    int top;
    int arr[MAX];
}stack;
int init()
{
    return -1;
}
void push(stack *S,int x)
{
    S->arr[++S->top]=x;
}
int pop(stack *S)
{
    return S->arr[S->top--];
}
void disp(stack *S)
{
    int i=-1;
    while(++i<=S->top)
    printf("%d  ",S->arr[i]);
    printf("\n");
}
int main()
{
    stack S; 
    S.top=init();  
    push(&S,12);
    push(&S,41);
    push(&S,182);
    push(&S,85);
    disp(&S);
    printf("Poped out :%d  %d  %d\n",pop(&S),pop(&S),pop(&S));
    disp(&S);
	return 0;
}
