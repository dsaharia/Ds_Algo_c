#include <iostream>
#include <vector>

class MyQueue {
    private:
	int front;
	std::vector<int> queue;
    public:
	MyQueue();
	bool my_enqueue(int data);
	bool my_dequeue();
	bool is_empty();
	int peek();
	void print();

};

MyQueue::MyQueue(){
    front = 0;
}

bool MyQueue::my_enqueue(int data){
    queue.push_back(data);
    return true;
}

bool MyQueue::my_dequeue(){
    if(is_empty()){
	return false;
    }
    front++;
    return true;
}

bool MyQueue::is_empty(){
    return front >= queue.size();
}

int MyQueue::peek(){
    return queue[front];
}

void MyQueue::print(){
    std::cout << "--- Elements inside queue ---" << "\n";
    for(int i=front;i<queue.size();++i){
	std::cout << queue[i] << " ";
    }
    std::cout << "\n";
}
