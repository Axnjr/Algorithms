#include <iostream> 

class Node { 
    public: 
        int data; 
        Node* next; 
        Node(int data);
};

// template <typename T> inline Node<T>::Node(T data) {}
