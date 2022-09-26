
#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void spacePrint(int level)
{
    for (int i = 0; i < level; i++)
    {
        cout << "\t";
    }
}

// in order
void inOrder(treeNode *root, string &check)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->leftChild, check);
    check += (to_string(root->data))+" ";
    inOrder(root->rightChild, check);
}



//
treeNode *insertionBST(treeNode *root, int value)
{
    treeNode *newNode = new treeNode(value);

    if (root == NULL)
    {
        root = newNode;
        return root;
    }

    if (value < root->data)
    {
        root->leftChild = insertionBST(root->leftChild, value);
    }
    else if (value > root->data){
        root->rightChild = insertionBST(root->rightChild, value);
    }
    return root;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    treeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int value;
        cin >> value;
        root = insertionBST(root, value);
    }

    string inOrderTraversal = "";
    inOrder(root, inOrderTraversal);
    cout << endl
         << inOrderTraversal << endl;
    return 0;
}

/*

9
11 5 9 43 34 1 2 7 21

 */