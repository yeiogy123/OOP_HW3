public class Node {
    public int item;
    public Node next;
    Node()
    {
        this.item = 0;
        this.next = null;
    }
    Node(int item, Node Node){
        this.item = item;
        this.next = Node;
    }
}
