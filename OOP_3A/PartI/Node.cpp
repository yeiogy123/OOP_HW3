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
