// Stack follows LIFO approch: `Last in First Out`
#include <iostream> 
#include <stack>
using namespace std;

template <typename T>

class Stack {

    private:
        int size;
        int top;
        T* arr;

    public:

        Stack(int s) {
            size = s;
            arr = new int[s];
            top = -1;
        }

        void push(T x){
            if(top == size - 1) {
                cout << "Error: Stack Overflow" << endl;
                return;
            }
            arr[++top] = x; // if top = -1; then it will be arr[0] and top will be 0 before only
        }

        T pop() {
            if(top == -1) {
                cout << "Error: Stack Underflow" << endl;
                return -1;
            }
            delete arr[top--]; // use the previous value of top for indexing `arr` and then decrement it
            return arr[top];
        }

        int peek();
        bool isEmpty();
};

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
