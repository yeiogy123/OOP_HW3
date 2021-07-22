//
// Created by User on 2021/4/13.
//
#include <iostream>
using namespace std;
#ifndef OOP_HW03BB_LINKEDLIST_H
#define OOP_HW03BB_LINKEDLIST_H
//
// Created by User on 2021/4/13.
//
//
// Created by User on 2021/4/13.
//
//
// Created by User on 2021/4/13.
//
struct Point{
    int x;
    int y;
};
struct Node{
    Point pt;
    Node *prev,*next;
};
class LinkedList{
    Node* current_pointer;
public:
    LinkedList(){
     	cout<<"construct LinkedList"<<endl;
   	current_pointer = 0;
    }
    ~LinkedList() {
	cout<<"destruct LinkedList"<<endl;
        Node * ptr = current_pointer;
        while(ptr)
        {
            Node * qtr  = ptr->next;
            ptr->prev->next=0;
            //ptr->prev=ptr->next=nullptr;
            delete ptr;
            ptr = qtr;
            //cout<<"done"<<endl;
        }
        current_pointer = 0;
   	cout<<"finish"<<endl;
    }
    int getSize() const{
        int size = 0;
        Node * ptr = current_pointer;
        while(ptr->next != current_pointer){
            ptr = ptr->next;
            size++;
        }
        if(ptr->next == current_pointer)
            size++;
        //cout<<"size = "<<size<<endl;
        return size;
    }
    bool isEmpty(){
        if(current_pointer == 0)
            return true;
        return false;
    }
    void clear(){
        while(current_pointer){
            deleteCurrentNode();
        }
    }
    void deleteCurrentNode(){
        Node * Ptr = current_pointer;
        current_pointer->prev->next = current_pointer->next;
        current_pointer->next->prev = current_pointer->prev;
        current_pointer = current_pointer->next;
        Ptr->next = Ptr->prev=0;
        cout<<"delete current "<<"("<<Ptr->pt.x<<","<<Ptr->pt.y<<")"<<endl;
        delete Ptr;
    }
    void pointToNext(){
        cout<<"current_pointer ("<<current_pointer->pt.x<<","<<current_pointer->pt.y<<") to next"<<endl;
        current_pointer = current_pointer->next;
    }
    void pointToPrev(){
        cout<<"current_pointer to prev"<<endl;
        current_pointer = current_pointer->prev;
    }
    Point getCurrentPoint() const{
        cout<<"getCurrent"<<"("<<current_pointer->pt.x<<","<<current_pointer->pt.y<<")"<<endl;
        return current_pointer->pt;
    }
    void insertToNext(const Point& pt){
        if(isEmpty()){
            current_pointer = new Node;
            current_pointer->next = current_pointer->prev=current_pointer;
            current_pointer->pt = pt;
            cout<<"first node " <<"("<<current_pointer->pt.x<<","
                <<current_pointer->pt.y<<")"<<" insert to next successfully"<<endl;
            return;
        }
        Node *node = new Node;
        node->pt = pt;
        if(current_pointer->next == current_pointer){
            current_pointer->prev = node;
            node->next = current_pointer;
            current_pointer->next = node;
            node->prev = current_pointer;
            cout<<"second node "<<"("<<node->pt.x<<","
                <<node->pt.y<<")"<<" insert to next successfully"<<endl;
            // just two node
        }
        else{
            Node *ptr = current_pointer;
            while(ptr->prev != current_pointer)
                ptr = ptr->prev;
            ptr->prev = node;
            node->next = ptr;
            current_pointer->next = node;
            node->prev = current_pointer;
            cout<<"else node "<<"("<<node->pt.x<<","
                <<node->pt.y<<")"<<" insert to next successfully"<<endl;
        }
    }
    void insertToPrev(const Point& pt){
        if(isEmpty()){
            current_pointer = new Node;
            current_pointer->next = current_pointer->prev = current_pointer;
            current_pointer->pt = pt;
            cout<<"first node " <<"("<<current_pointer->pt.x<<","
                <<current_pointer->pt.y<<")"<<" insert to prev successfully"<<endl;
            return;
        }
        Node *node = new Node;
        node->pt = pt;
        if(current_pointer->prev == current_pointer){
            current_pointer->next = node;
            node->prev = current_pointer;
            node->next = current_pointer;
            current_pointer->prev = node;
            cout<<"second node "<<"("<<node->pt.x<<","
                <<node->pt.y<<")"<<" insert to prev successfully"<<endl;

        }else{
            Node * ptr = current_pointer;
            while(ptr->next != current_pointer){
                ptr = ptr->next;
            }
            ptr->next = node;
            node->prev = ptr;
            node->next = current_pointer;
            current_pointer->prev = node;
            cout<<"else node "<<"("<<node->pt.x<<","
                <<node->pt.y<<")"<<" insert to prev successfully"<<endl;
        }
    }
    void out(){
        Node * ptr = current_pointer;
        while(ptr->next != current_pointer) {
            cout << "node " <<"("<< ptr->pt.x << ","
                 << ptr->pt.y<<")"<< endl;
            ptr = ptr->next;
        }
        cout << "node " <<"("<< ptr->pt.x << ","
             << ptr->pt.y<<")"<< endl;
        current_pointer = ptr;
    }
};
#endif //OOP_HW03BB_LINKEDLIST_H
