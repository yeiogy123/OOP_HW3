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
