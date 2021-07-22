import java.io.*;
public class Main {
    public static void main(String[] args) throws IOException{
        Tnode root ;
        FileInputStream inputFile = new FileInputStream("treeNode.txt");
        FileOutputStream outputFile = new FileOutputStream("treeNode_javaResult.txt");
        int test = 1;
        System.out.println("program start");
        while (true) {
            root = construct(inputFile);
            if (root == null)
                break;
            else
                System.out.println("[test is " + test + " .]");
            Btree tree = new Btree(root);
            if (tree.isPalindromicTree()) {
                System.out.println("the tree is a PalindromicTree.");
                String result ="test "+test+" : the tree is a PalindromicTree.\n";
                PrintStream out = new PrintStream(outputFile);
                out.print(result);
            } else {
                System.out.println("the tree is not a PalindromicTree.");
                String result = "test "+test+" : the tree is not a PalindromicTree.\n";
                PrintStream out = new PrintStream(outputFile);
                out.print(result);
            }
            test++;

            root = null;
            tree = null;
        }
    }

    public static Tnode construct(InputStream inputFile) throws IOException{
        int item = inputFile.read();
        if(item == -1) //檔案結尾
            return null;
        if(item == 13)
            item = inputFile.read(); //行結尾
        if(item == 10)
            item = inputFile.read(); //換行
        if(item == 32)
            item = inputFile.read(); //空白
        if(item >= 48)
            item = item - 48; //ascii轉數字
        if (item == 45 ) {
            System.out.println("node is -1 that cannot be built.");
            item = inputFile.read();
            return null; //-1
        }
        Tnode root = new Tnode(item);
        System.out.println("root "+(item)+" new successfully.");
        root.left = construct(inputFile);
        root.right = construct(inputFile);
        return root;
    }
}

