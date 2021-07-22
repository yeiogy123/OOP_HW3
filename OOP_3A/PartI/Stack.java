class Stack {
    private Node top;

    public Stack() {
        top = null;
    }

    void empty() {
        if (top == null)
            System.out.println("true");
        else
            System.out.println("false");
    }

    void push(int element) {
        if (top == null) {
            Node newNode = new Node(element, null);
            top = newNode;
            System.out.println("new node built");
            return;
        }
        Node newNode = new Node(element, top);
        top = newNode;
        System.out.println("new element insert");
    }

    int pop() {
        int item;
        if (top == null) {
            System.out.println("there is nothing to pop out");
            return Integer.MIN_VALUE;
        }
        Node current = top;
        top = top.next;
        System.out.println("pop out successfully,");
        item = current.item;
        current = null;
        return item;
    }
}