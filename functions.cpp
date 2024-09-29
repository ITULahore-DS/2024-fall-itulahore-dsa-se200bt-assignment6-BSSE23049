#include <iostream>
#include "functions.h"
using namespace std;

void Node::setNext(Node *val)
{
    next = val;
}

 Node* Node::getNext()
{
    return next;
}

void Node::setData(int data)
{
    this->data = data;
}

int Node::getData()
{
    return data;
}
Node::~Node()
{
    cout << "Destructor for data " << data <<" called." << endl;
}
 //                 ======================  Stack fucntions ===========================

Stack::Stack(int value)
{
    top = new Node(value);
    count = 1;                          // 1 when value assign to top
}

Stack::Stack()
{
    top = nullptr;
    count = 0;                          // 0 when top is nullptr
}

Stack::~Stack()
{
    while(top != nullptr){
        Node * temp = top;
        top = top->getNext();
        delete temp;                        // delete previous index top move to next one
    }
}

bool Stack::isEmpty()
{
    if(!top)                                // when top is nullptr return true that its empty
        return true;
    return false;
}

void Stack::push(int data)                          // this fucntion push value always at head
{
    Node * node_to_insert = new Node(data);
    node_to_insert ->setNext(top);                  // insert previous head at next of new node and update top
    top = node_to_insert;
    count++;
}

void Stack::pop()                           // this fucntion always remove form top
{
    if(!isEmpty()){
        Node * new_top = top ->getNext();
        delete top;
        top = new_top;                         // update top after delete start node
        count--;                               // also decrement the count by 1 after deleting the node 
        return;
    }
    cerr  << "Stack is Empty pop function not performed." << endl;
}

int Stack::peek()
{
    if(!isEmpty()) return top->getData();                   // reutrn top when list is not empty 
    cerr << "Stack is Empty." << endl;
    return -1;
}

int Stack::size()
{
    return count;
}

void Stack::clear()
{
    while(top->getNext() != nullptr){
        Node * temp = top;
        top = top->getNext();
        delete temp;                        // delete previous index top move to next one
    }
    top = nullptr;                          // update the member variable to default
    count = 0;   
}

void Stack::printStack()
{
    Node * temp = top;
    while (temp != nullptr)
    {
        cout << temp ->getData() << "  ";
        temp = temp ->getNext();                    // dispaly function show each node
    }
    cout << endl;
}

 //                 ======================  Queue fucntions ============================


 Queue::Queue(int value)
{
    top = new Node(value);
    count = 1;                          // 1 when value assign to top   
}

Queue::Queue()
{
    top = nullptr;
    count = 0;                          // 0 when top is nullptr
}

Queue::~Queue()
{
    while(top != nullptr){
        Node * temp = top;
        top = top->getNext();
        delete temp;                        // delete previous index top move to next one
    }
}

bool Queue::isEmpty()
{
    if(!top)                                // when top is nullptr return true that its empty
        return true;
    return false;
}

void Queue::enqueue(int data)
{
    Node * node_to_insert = new Node(data);
    if(isEmpty()){
        top = node_to_insert;
    }else{                                      // mode to last index then insert node node at last 
        Node * temp = top;
        while(temp ->getNext() != nullptr){
            temp = temp->getNext();
        }
        temp->setNext(node_to_insert);
    }
    count++;                                            // update the count in each case
}

void Queue::dequeue()
{
    if(!isEmpty()){
        Node * new_top = top ->getNext();
        delete top;
        top = new_top;                         // update top after delete start node
        count--;                               // also decrement the count by 1 after deleting the node 
        return;
    }
    cerr << "Queue is Empty pop function not performed." << endl; 
}

int Queue::peek()
{
    if(!isEmpty()) return top->getData();                   // reutrn top when list is not empty 
    cerr << "Queue is Empty." << endl;
    return -1;
}

int Queue::size()
{
    return count;
}

void Queue::clear()
{
    while(top->getNext() != nullptr){
        Node * temp = top;
        top = top->getNext();
        delete temp;                        // delete previous index top move to next one
    }
    top = nullptr;                          // update the member variable to default
    count = 0;  
}

void Queue::printQueue()
{
    Node * temp = top;
    while (temp != nullptr)
    {
        cout << temp ->getData() << "  ";
        temp = temp ->getNext();                // display function show whole Queue
    }
    cout << endl;
}

