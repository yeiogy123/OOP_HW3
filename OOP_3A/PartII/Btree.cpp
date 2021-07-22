#include"Tnode.h"
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