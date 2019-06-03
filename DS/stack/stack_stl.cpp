#include <iostream>
#include <stack>
using namespace std;

void show(stack <int> s){
    cout << "Stack contents are: " << endl;
    while(!s.empty()){
	cout << s.top() << endl;
	s.pop();

    }


}
int main(){
    stack <int> s;
    cout << "--Stack using STL--" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    show(s);
    cout << "Top is: " << s.top() << endl;
    s.pop();
    show(s);


}
