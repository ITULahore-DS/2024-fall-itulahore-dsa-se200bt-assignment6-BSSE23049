#include <iostream>
#include "functions.h"
using namespace std;

void menuStack()
{

    Stack s;
    int num = -1, value;
    while (num != 0)
    {
        cout << "\n1.Push\n2.Pop\n3.Check Empty\n4.print\n5.top/peek\n0. Exit\nEnter :";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << "Enter value :";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            if (s.isEmpty())
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                cout << "Stack is not Empty" << endl;
            }
            break;
        case 4:
            s.printStack();
            break;
        case 5:
            cout << "Top / Peek of stack is : " << s.peek() << endl;
            break;
        case 0:
            cout << "Exiting...." << endl;
            break;
        default:
            cout << "Invalid number" << endl;
            break;
        }
    }
}

void menuQueue()
{
    Queue q;
    int num = -1, value;
    while (num != 0)
    {
        cout << "\n1.Push\n2.Pop\n3.Check Empty\n4.print\n0. Exit\nEnter :";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << "Enter value :";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            if (q.isEmpty())
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                cout << "Stack is not Empty" << endl;
            }
            break;
        case 4:
            q.printQueue();
            break;
        case 5:
            cout << "Top / Peek of queue is : " << q.peek() << endl; 
            break;
        case 0:
            cout << "Exiting...." << endl;
            break;
        default:
            cout << "Invalid number" << endl;
            break;
        }
    }
}

int main()
{
    int num;
    cout << "\n1.Stack\n2.Queue\nEnter :";
    cin >> num;
    if (num == 1)
    {
        menuStack();
    }
    else if (num == 2)
    {
        menuQueue();
    }
    else
    {
        cout << "Invalid index" << endl;
    }

    return 0;
}
