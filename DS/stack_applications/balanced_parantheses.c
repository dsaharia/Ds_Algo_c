#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25

int top = -1;
char stack[MAX];

void push(char x)
{
    if(top == MAX - 1){
	printf("Stack Overflow\n");
	return;
    }
    stack[++top] = x;
}

char pop()
{
    char popped;
    if(top == -1) {
	printf("Stack Underflow\n");
	return 0;
    }
    popped = stack[top];
    --top;
    return popped;
}
char Top()
{
    return (stack[top]);

}
int arePair(char opening,char closing)
{
    if(opening =='(' && closing == ')') return 1;
    else if((opening =='{' && closing == '}')) return 1;
    else if (opening =='[' && closing == ']') return 1;
    return 0;
}

int paranthesesBalanced(char *exp,int size)
{
   for (int i=0;i<size;i++)
   {
	if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
	    push(exp[i]);
	else if (exp[i] == ')' || exp[i] == '}'|| exp[i] == ']') 
	{
	    if(top == -1 || !arePair(Top(),exp[i]))
		return 0;
	    else
		pop();
	}
   
   }
    return (top == -1 ? 1:0);

}


int main()
{
    char exp[25];
    int size=0;
    printf("Enter the size of expression\n");
    scanf("%d",&size);
    printf("Enter the expression(Less than 25 characters): \n");
    //scanf("%[ˆ\n]%",exp);
    for (int i=0;i<size;i++)
    {
	scanf("%c",&exp[i]);
    }
    if(paranthesesBalanced(exp,size))
	printf("Balanced!\n");
    else
	printf("Not Balanced!\n");

}
