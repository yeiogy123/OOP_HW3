class Btree{
    private  Tnode root;
    Boolean areMirrors(Tnode root1,Tnode root2){
        if(root1.left!=null  && root2.right!=null){
            if(root1.left.val == root2.right.val) {
                if (!areMirrors(root1.left, root2.right))
                    return false;
            }
            else
                return false;
        }else if(root1.right!=null  && root2.left!=null ){
            if(root1.right.val == root2.left.val) {
                if (!areMirrors(root1.right, root2.left))
                    return false;
            }
            else
                return false;
        }else if(root1.left !=null || root1.right!=null
                ||root2.left!=null|| root2.right!=null)
            return false;
        return true;
    }

    public boolean isPalindromicTree(){
        return areMirrors(root, root);
    }
    Btree(Tnode node)
    {
        root = node;
    }
}
