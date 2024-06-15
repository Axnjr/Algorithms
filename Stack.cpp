#include <iostream> 
#include <stack>
using namespace std;

int main() {
	stack<int> intStack;
    stack<char> strStack;
	for(int i = 0; i < 5; i++) {
		intStack.push(i);
        strStack.push('a' + i);
	}
    cout << "Stack in int form: ";
    while(!intStack.empty()) {
        cout << intStack.top() << " ";
        intStack.pop();
    }
    cout << endl;
    cout << "Stack in char form: ";
    while(!strStack.empty()) {
        cout << strStack.top() << " ";
        strStack.pop();
    }
    return 0;
}
