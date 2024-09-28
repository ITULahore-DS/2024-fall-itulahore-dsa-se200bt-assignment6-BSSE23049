#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
using namespace std;

class Node{
    int data;
    Node *next;
public:
    Node(int val = 0){
        data = val;
        next = nullptr;
    }
    ~Node();
    void setNext(Node* val);
    Node* getNext();
    void setData(int data);
    int getData();
};



class Stack{
    int count;
    Node * top;
public:
    Stack(int value);
    Stack();
    ~Stack();
    bool isEmpty();
    void push(int data);
    void pop();
    int peek();
    int size();
    void clear();
    void printStack();

};



class Queue{
    int count;
    Node * top;
public:
    Queue(int value);
    Queue();
    ~Queue();
    bool isEmpty();
    void enqueue(int data);
    void dequeue();
    int peek();
    int size();
    void printQueue();
};






class List{
    Node * head;
    Node * tail;
    int count;
public:
List(){
    head = NULL;
    tail = NULL;
    count = 0;
}
~List(){
    while(head != NULL){
        Node * temp = head;
        head = head ->getNext();
        delete temp;
    }
}
    bool isEmpty();
    void append(int data);
    void prepend(int data);
    void insertAtIndex(int data, int index);
    void deleteFromEnd();
    void deleteFromStart();
    void deleteFromIndex(int index);
    Node* getHead();
    Node* getTail();
    void printList();
};
#endif
