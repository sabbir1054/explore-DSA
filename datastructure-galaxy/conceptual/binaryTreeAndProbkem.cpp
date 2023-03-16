# include<bits/stdc++.h>
using namespace std;

class treeNode{
    public:
        int val;
        treeNode *left;
        treeNode *right;
        treeNode(int value){
            value = val;
            left = NULL;
            right = NULL;
        }

};
void print(treeNode *root){
    if(root==NULL)
        return;

    print(root->left);
    cout << root->val;
    print(root->right);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
}

int main(int argc, char const *argv[])
{
    treeNode *root = new treeNode(1);
    treeNode *a = new treeNode(2);
    treeNode *b = new treeNode(3);
    treeNode *c = new treeNode(4);
    treeNode *d = new treeNode(5);
    treeNode *e = new treeNode(6);
    treeNode *f = new treeNode(7);

    root->left = a;
    root->right = a;
    // root->right->left = ;

    // treeNode
    return 0;
}
