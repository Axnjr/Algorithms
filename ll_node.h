#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T> class Node {
public:
    T data;
    Node* next;
    Node(T data);
};

template <typename T> Node<T>::Node(T data) : data(data), next(nullptr) {}

#endif