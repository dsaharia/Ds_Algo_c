#include <iostream>
using namespace std;

class MyCircularQueue {
    int size, cap;
    int front, rear;
    int* queue;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        this -> cap = k;
	this -> front = -1;
	this -> rear = -1;
	this -> size = 0;
	this -> queue = new int[this -> cap];
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isEmpty()){
	    front = 0;
	    rear = 0;
	    ++size;
	    queue[rear] = value;
	    return true;
	}
	else if(isFull()){
	    return false;
	}
	else{
	    rear = (rear+1) % cap;
	    queue[rear] = value;
	    ++size;
	}
	return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
       if(isEmpty()){
	   return false;
       }

       front = (front + 1) % cap;
       --size;

       return true;

    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty() ? -1 : queue[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty() ? -1 : queue[rear];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
	return size==0 ? true : false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return cap == size;
    }
};

/*int main(){
    MyCircularQueue object will be instantiated and called as such:
    MyCircularQueue* obj = new MyCircularQueue(3);
    bool param_1 = obj->enQueue(2);
    bool param_2 = obj->deQueue();
    int param_3 = obj->Front();
    int param_4 = obj->Rear();
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
    cout << param_1 << " "<< param_2 << " "<< param_3 << " "<< param_4 << " "<< param_5 << " "<< param_5 << "\n"; 
 }*/
