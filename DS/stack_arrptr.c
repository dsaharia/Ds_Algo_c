#include <stdio.h>
#include <stdlib.h>

#define MAX 15
int size;

typedef struct stack{
    int arr[MAX];
    int top;
}stack;

void init_stack(stack *st)
{
    st -> top = -1;
}

void push(stack* st,int num)
{
    if(st -> top == size-1)
    {
	printf("Stack Overflow!\n");
	return;
    }
    st -> top++;
    st -> arr[st -> top] = num;

}
int pop(stack *st)
{
    int num;
    if(st -> top ==-1)
    {
	printf("Stack Underflow!\n");
	return -1;
    }
    num = st -> arr[st-> top];
    return num;
}
void display(stack *st)
{
    int i;
    printf("Elements of Stack: \n");
    for(i=st->top;i>=0;i++)
    {
	printf("%d ",st -> arr[i]);
    }
    printf("\n");

}
int main()
{
    int element,choice,val;
    stack ptr;
    init_stack(&ptr);
    printf("Enter the Stack Size\n");
    scanf("%d",&size);
    do
    {
	printf("Stack Operations\n");
	printf("1.PUSH\n");
	printf("2.POP\n");	 
	printf("3.DISPLAY\n");
	printf("4.EXIT\n");
	printf("Enter an option\n");
	scanf("%d",&choice);

	switch(choice)
	{
	    case 1:
		printf("Enter the element to push\n");
		scanf("%d",&val);
		push(&ptr,val);
		break;

	    case 2:
		element = pop(&ptr);
		printf("Popped element is: %d\n",element);
		break;

	    case 3:
		display(&ptr);
		break;

	    case 4:
		exit(0);
	    default:
		printf("Enter a valid option\n");
	    }
    }while(choice != 4);
	}
    
