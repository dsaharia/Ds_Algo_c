#include <iostream>
#include <vector>
#include "my_queue.h"
using namespace std;
int main(int argc, const char *argv[]) {
   MyQueue q;
   q.my_enqueue(4);
   q.my_enqueue(2);
   q.my_enqueue(6);
   q.my_enqueue(7);
   q.print();
   q.my_dequeue();
   cout << "--Deque--" << "\n";
   q.print();
}

