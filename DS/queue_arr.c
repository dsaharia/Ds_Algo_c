#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

int is_full()
{
    if(rear == MAX-1)
	return 1;
    else
	return 0;
}

int is_empty()
{
    if(front == -1 && rear == -1)
	return 1;
    else
	return 0;

}

void enqueue(int data)
{
    if (is_full())
	return;
    else if(is_empty())
    {
	front = 0;
	rear = 0;
    }
    else
	rear += 1;

    queue[rear] = data;
}

int dequeue()
{
    int temp;
    temp = queue[front];
   if(is_empty())
       return -1;
   else if(front == rear)
   {
	front -= 1;
	rear -= 1;

   }
   else
       front += 1;
   return temp;
}
void display()
{
    printf("Queue Front to Rear :--> \n");
    for(int i=front;i<= rear;i++)
    {
	printf("%d  ",queue[i]);
    }

}
int peek()
{
    if(!is_empty())
	return (queue[front]);
    else
    {
	printf("Queue is Empty\n");
	return -1;
    }
}


int main()
{
    printf("---Queue Using Array---\n");
    int choice=0,data=0,deq=0,front=0;
    do {
    printf("Enter a Choice:\n");
    printf(" 1.Enqueue\n 2.Dequeue\n 3.Display\n 4. Front\n 5.Exit\n");
    scanf("%d",&choice);
   
    
	switch(choice){
	    case 1:
		printf("Enter the data to enqueue\n");
		scanf("%d",&data);
		enqueue(data);
		break;
	    case 2:
		deq = dequeue();
		printf("Dequeued Element is:%d\n",deq);
		break;
	    case 3:
		display();
		break;
	    case 4:
		front = peek();
		printf("Front is : %d\n",front);
		break;
	    case 5:
		exit(0);
	}
    } while(choice != 5);


}
