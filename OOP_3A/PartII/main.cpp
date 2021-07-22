#include <iostream>
#include <fstream>
#include"Btree.h"
using namespace std;
TnodePtr construct(ifstream &input);
int main() {
    TnodePtr root = nullptr;
    ifstream inputFile;
    inputFile.open("treeNode.txt",ios::in);
    ofstream outputFile;
    outputFile.open("treeNode_result.cpp.txt",ios::in);
    int test =  1;
    while(true) {
        if(inputFile.eof()){
            inputFile.close();
            break;
        }
        cout<<"[test is "<<test<<" .]"<<endl;
        root = construct(inputFile);
        if(root==nullptr)
            break;
        Btree *tree = new Btree(root);
        if (tree->isPalindromicTree()) {
            cout << "the tree is a PalindromicTree." << endl;
            outputFile<<"test "<<test<<" : the tree is a PalindromicTree." << endl;
        }
        else {
            cout << "the tree is not a PalindromicTree." << endl;
            outputFile<<"test "<<test<<" : the tree is not a PalindromicTree." << endl;
        }
        test++;

        delete root;
        delete tree;
    }
    return 0;
}
TnodePtr construct(ifstream &input) {
    int item;
    input>>item;
    if(item == -1) {
        cout << "node is -1 that cannot be built."<<endl;
        return nullptr;
    }
    Tnode *root = new Tnode(item);
    cout << "root "<<item<<" new successfully."<<endl;
    root->left = construct(input);
    root->right = construct(input);
    return root;

}