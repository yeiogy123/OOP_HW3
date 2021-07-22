//
// Created by User on 2021/4/6.
//

#ifndef OOP_HW03B_TNODE_H
#define OOP_HW03B_TNODE_H
typedef class Tnode* TnodePtr;
class Tnode{
public:
    TnodePtr left;
    TnodePtr right;
    int val;
    Tnode(){
        left = nullptr;
        right = nullptr;
        val = 0;
    }
    Tnode(int item)
    {
        val = item;
        left = nullptr;
        right = nullptr;
    }
};

#endif //OOP_HW03B_TNODE_H
