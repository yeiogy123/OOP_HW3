//
// Created by User on 2021/4/6.
//

#ifndef OOP_HW03B_BTREE_H
#define OOP_HW03B_BTREE_H
#include"Tnode.h"
#include<iostream>
using namespace std;
class Btree{
private:
    TnodePtr root;
    bool areMirrors(TnodePtr root1,TnodePtr root2){
        if(root1->left  && root2->right ){
            if(root1->left->val == root2->right->val) {
                if (!areMirrors(root1->left, root2->right))
                    return false;
            }
            else
                return false;
        }else if(root1->right  && root2->left ){
            if(root1->right->val == root2->left->val) {
                if (!areMirrors(root1->right, root2->left))
                    return false;
            }
            else
                return false;
        }else if(root1->left || root1->right
        ||root2->left|| root2->right)
            return false;
        return true;
    }

public:
    bool isPalindromicTree(){
        return areMirrors(root, root);
    }
    Btree(TnodePtr node)
    {
        root = node;
    }
};
#endif //OOP_HW03B_BTREE_H
