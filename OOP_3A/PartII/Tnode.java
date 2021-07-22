class Tnode{
    public Tnode left;
    public Tnode right;
    public int val;
    Tnode(){
        left = null;
        right = null;
        val = Integer.MIN_VALUE;
    }
    Tnode(int item)
    {
        val = item;
        left = null;
        right = null;
    }
}
