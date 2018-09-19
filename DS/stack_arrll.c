#include <stdio.h>
#include <stdlib.h>


typedef struct NODE {
    int data;
    struct NODE* next;
}node;

node* top = NULL;
// Push Function
void push(int x)
{
    node *temp;
    temp = (node *) malloc(sizeof(node));
    temp -> data = x;
    temp -> next = top;
    top = temp;

}
// Pop function
int pop()
{
    node* temp;
    int num=0;
    temp = top;
    num = temp -> data;
    top = top -> next;
    free(temp);
    return num;
}

int Top()
{
    return top -> data;
}

void display(node *head)
{
    if(head == NULL) printf("NULL!\n");
    else
    {
        printf("%d\n", head -> data);
        display(head->next);
    }
}
int main() {
    int element,choice,val,tp;
    do
    {
	printf("---Stack Operations---\n");
	printf("1.PUSH\n");
	printf("2.POP\n");
	printf("3.DISPLAY\n");
    printf("4.Top element\n");
	printf("5.EXIT\n");
	printf("Enter an option\n");
	scanf("%d",&choice);

	switch(choice)
	{
	    case 1:
		printf("Enter the element to push\n");
		scanf("%d",&val);
		push(val);
		break;

	    case 2:
		element = pop();
		printf("Popped element is: %d\n",element);
		break;

	    case 3:
		display(top);
		break;

        case 4:
        tp = Top();
        printf("Top element is:%d\n",tp);
        break;

	    case 5:
		exit(0);
	    default:
		printf("Enter a valid option\n");
	    }
    }while(choice != 5);

}
