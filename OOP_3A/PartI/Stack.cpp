using namespace std;
#include "Node.h"
#include <iostream>
class Stack {
private:
    NodePtr top;
public:
    Stack()
    {
        top = nullptr;
    }
    void empty()
    {
        if(top == nullptr)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    void  push(int element)
    {
        if(top == nullptr) {
            Node *newNode = new Node(element,nullptr);
            top = newNode;
            cout<<"new node built"<<endl;
            return;
        }
        Node *newNode = new Node(element,top);
        top = newNode;
        cout<<"new element insert"<<endl;
    }
    int pop()
    {
        int item;
        if(top == nullptr)
        {
            cout<<"there is nothing to pop out"<<endl;
            return -100000 ;
        }
        NodePtr current = top;
        top = top->next;
        cout<<"pop out successfully,";
        item = current->item;
        delete current;
        return item;
    }
};
