#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    public:
	Stack(){
	    top = -1; // Constructor
	}
	int stack[MAX]; //stack created
	void push(int data);
	int pop();
	int peek();
	bool isEmpty();
	void display() const;

};

void Stack::push(int data){
    if(top >= MAX - 1)
	cout << "STACK OVERFLOW" << endl;
    else{
	stack[++top] = data;
	cout << data << " Pushed" << endl;
    }
}

int Stack::pop(){
    if(top < 0){
	cout << "No items to pop" << endl;
	return -1;
    }
    else
	return stack[top--];
    
}

int Stack::peek(){
     if(top < 0){
	cout << "No items to peek" << endl;
	return -1;
    }
    else
	return stack[top];   
}

bool Stack::isEmpty(){
    if(top >= 0)
	return false;
    else
	return true;
}

void Stack::display() const{
    cout << "Stack contents are: " << endl;
    for(int i=0;i < top;i++){
	cout << stack[i] << " ";

    }
    cout << endl;



}
int main(){
    Stack newstack;
    int choice,data;
    do{
	cout << "Enter a Choice: " << endl;
	cout << "1. PUSH an element\n" << "2. POP an element\n" << "3. PEEK top element\n" << "4. Is stack empty\n";
	cout << "5. Display\n" << "6. QUIT\n";
	cin >> choice;
	switch(choice){
	    case 1:
		cout << "Enter the element: " << endl;
		cin >> data;
		newstack.push(data);
		break;
	    case 2:
		cout << "Popped element is: " << newstack.pop() << endl;
		break;
	    case 3:
		cout << "Top is " << newstack.peek() << endl;
		break;
	    case 4:
		if(newstack.isEmpty())
		    cout << "Stack is empty" << endl;
		else
		    cout << "Stack is not empty" << endl;
		break;
	    case 5:
		newstack.display();
		break;
	    case 6:
		break;
	}

    }while( choice != 6);



}
