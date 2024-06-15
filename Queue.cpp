// Queues follow FIFO approch: First In First Out
#include <iostream>
#include <queue>
using namespace std;

template <typename T> class Queue {
    private:
        T* arr;
        int size;
        int left = 0 , right = -1;

    public:
        Queue(int s) {
            arr = new T[s];
            size = s;
        }

        void push(T value) {
            if(right == size - 1) {
                cout << "Queue is full !!" << endl;
            }
            arr[++right] = value;
        }

        T pop() {
            if(right == -1){ 
                cout << "Queue is empty !!" << endl;
            }
            return arr[left++];
        }

        void showQ() {
            for(int i = 0; i < size ; i++){
                cout << arr[i] << endl;
            }
        }

        bool isEmpty() {
            return (left == size - 1);
        }

        T front(){
            return arr[left];
        }

        T back(){
            return arr[right];
        }
};

int main() {
    Queue<int> qu(12);
    for(int i = 1; i <= 12 ; i++){
        qu.push(i);
    }

    cout << "Queue is: " << endl;
    while(!qu.isEmpty()){
        cout << qu.front() << endl;
        qu.pop();
    }

    return 0;
}