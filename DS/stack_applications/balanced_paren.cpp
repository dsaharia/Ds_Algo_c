#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkParentheses(string str, stack<char> s) {
    int flag = 0;
    char top;
    for(int i=0;i<str.length();i++) {
	if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
	    s.push(str[i]);
	}
	else {
	    if(s.empty()) {
		flag = 1;
		break;
	    }
	    else {
		top = s.top();
	    }
	    if(str[i] == ')' && top == '('){
		s.pop();
	    }
	    else if(str[i] == '}' && top == '{'){
		s.pop();
	    }
	    else if(str[i] == ']' && top == '['){
		s.pop();
	    }
	    else {
		flag = 1;
		break;
	    }

	}

    }
    if(s.empty() && flag == 0) {
	return true;
    }
    else if (flag == 1) {
	return false;
    }
    else {
	return false;
    }


}



int main() { 
    stack <char> s;
    string str;
    cout << "Enter an expression with brackets: " << endl;
    cin >> str;
    cout << str << endl;
    if(checkParentheses(str, s)) {
	cout << "Expression is valid!" << endl;
    }
    else {
	cout << "Expression is not valid" << endl;
    }
}
