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
        cout << temp ->getData() << " ";
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

void Queue::printQueue()
{
    Node * temp = top;
    while (temp != nullptr)
    {
        cout << temp ->getData() << " ";
        temp = temp ->getNext();                // display function show whole Queue
    }
    cout << endl;
}

 //                 ======================  linked list fucntions =======================

bool List::isEmpty()
{
    if(head == NULL && tail == NULL){
        return true;
    }
    return false;
}

void List::append(int data)
{
    // create Node 
    Node * temp = new Node(data);
    // for empty linked list 
    if(isEmpty()){
        head = temp;
    }else{
        tail->setNext(temp);
    }
    // update tail 
    tail = temp;
    count++;
}

void List::prepend(int data)
{
    // create Node 
    Node * temp = new Node(data);
    // for empty linked list 
    if(isEmpty()){
        tail = temp;
    }

   temp->setNext(head);
    // update head 
    head = temp;   
    count++;
}

void List::insertAtIndex(int data, int index)
{   Node * node_to_insert = new Node(data);
    if(index < 0 || index > count){
        throw invalid_argument("Invalid index");
        return ;
    }
    else if(index == 0){
        // function ot put value at first 
        prepend(data);
        
    }else if(index == count ){
        // call funtion to insert value at last 
        append(data);
    }else{
        int cnt = 0;
        Node * temp = head;
        while(temp->getNext() != NULL && cnt != index - 1){
            temp = temp->getNext();
            cnt++;
        }

        node_to_insert->setNext(temp->getNext());
        temp->setNext(node_to_insert);
        count++;
    }
}

void List::deleteFromEnd()
{
    // is empty
    if(isEmpty()){
        throw invalid_argument("list is empty");

    }// for single node case
    else if(head ->getNext() == NULL){
        delete head;
        tail = NULL;
        head = tail;
    }else{
        Node * temp = head;
        // move upto 2nd last index
        while(temp->getNext()->getNext() != NULL ){
            temp = temp->getNext();
        }
        Node * node_to_delete = tail;
        tail = temp;
        tail->setNext(NULL);
        delete node_to_delete;
    }
    count--;

}

void List::deleteFromStart()
{
    // is empty
    if(isEmpty()){
        throw invalid_argument("list is empty");
    }
    else{
        Node * temp = head;
        // update head
        head = head->getNext();
        delete temp;
    }
    // if after delete single node update head and  tail both
    if(head == nullptr){
        tail = head;
    }
    count--;
}

void List::deleteFromIndex(int index)
{
    if(index < 0 || index >= count){
        throw invalid_argument("Invalid index");
    }else if(index == 0){
        deleteFromStart();
    }else if(index == count - 1){
        deleteFromEnd();
    }else{
        int cnt = 0;
        Node * temp = head;
        while(temp->getNext() != NULL && cnt != index - 1){
            temp = temp->getNext();
            cnt++;
        }
        Node * node_to_delete = temp->getNext();
        temp->setNext(node_to_delete->getNext());
        delete node_to_delete;
        count--;
    }
}

Node *List::getHead()
{
    return head;
}

Node *List::getTail()
{
    return tail;
}

void List::printList()
{
    Node * temp = head;
    while(temp != NULL){
        cout << temp->getData() <<"\t";
        temp = temp->getNext();
    }

}


