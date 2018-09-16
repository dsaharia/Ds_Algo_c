#include <stdio.h>

#define MAX_SIZE 101

int top = -1;
int a[MAX_SIZE];

void push(int x)
{
    if(top == MAX_SIZE -1)
    {
	printf("Stack Overflow\n");
	return;
    }
    a[++top] = x;
}

void pop()
{
    if(top == -1)
    {
	printf("No elements to pop(UNDERFLOW)");
	return;
    }
    top--;  // --top ?
}
int Top()
{
    return (a[top]);
}
void print()
{
    int i=0;
    printf("Stack is : \n");
    for(i=0;i<=top;i++)
    {
	printf("%d ",a[i]);
    }
    printf("\n");
}


int main()
{
    printf("Pushed 2\n");
    push(2);
    print();
    printf("Pushed 4\n");
    push(4);
    print();
    printf("Popped\n");
    pop();
    print();

}

