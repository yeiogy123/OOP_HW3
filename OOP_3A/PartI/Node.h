//
// Created by User on 2021/4/2.
//

#ifndef OOP_HW03_NODE_H
#define OOP_HW03_NODE_H

typedef class Node* NodePtr;

class Node {
public:
    int item;
    NodePtr next;
    Node()
    {
        item = 0;
        next = nullptr;
    }
    Node(int x, NodePtr t){
        item = x;
        next = t;
    }
};


#endif //OOP_HW03_NODE_H
