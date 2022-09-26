/* 
PreOrder and InOrder is given make tree formatting 
 */

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
    check += to_string(root->data);
    inOrder(root->rightChild, check);
}
// pre order
void preOrder(treeNode *root, string &check)
{
    if (root == NULL)
    {
        return;
    }
    check += to_string(root->data);
    preOrder(root->leftChild, check);
    preOrder(root->rightChild, check);
}

// post order
void postOrder(treeNode *root, string &check)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->leftChild, check);
    postOrder(root->rightChild, check);
    check += to_string(root->data);
}
// normal tree print
void printTree(treeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        cout << root->data << endl;
        return;
    }
    else
    {
        cout << endl;
        spacePrint(level);
        cout << "Root : " << root->data << endl;
    }

    if (root->leftChild != NULL)
    {
        spacePrint(level);
        cout << "Left : ";
        printTree(root->leftChild, level + 1);
    }

    if (root->rightChild != NULL)
    {
        spacePrint(level);
        cout << "Right : ";
        printTree(root->rightChild, level + 1);
    }
}
int searchInOrder(int inOrder[],int current, int start,int end){
    for (int i = start; i <=end; i++)
    {
        if (inOrder[i]==current)
        {
            return i;
        }
        
    }
    return -1;
}

treeNode* buildTreePreIn(int preOrder[],int inOrder[], int start,int end){
    static int id = 0;


    int current = preOrder[id];
    id++;
    treeNode* newNode = new treeNode(current);
    
    if (start==end)
    {
        return newNode;
    }
    int pos = searchInOrder(inOrder, current, start, end);
    newNode->leftChild = buildTreePreIn(preOrder, inOrder, start, pos - 1);
    newNode->rightChild = buildTreePreIn(preOrder, inOrder, pos + 1, end);
    return newNode;
}


int main(int argc, char const *argv[])
{
    // int n;
    // cin >> n;

    // treeNode *allNodes[n];
    // for (int i = 0; i < n; i++)
    // {
    //     allNodes[i] = new treeNode(-1);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     int value, left, right;
    //     cin >> value >> left >> right;

    //     allNodes[i]->data = value;

    //     if (left != -1)
    //     {
    //         allNodes[i]->leftChild = allNodes[left];
    //     }
    //     if (right != -1)
    //     {
    //         allNodes[i]->rightChild = allNodes[right];
    //     }
    // }

    // printTree(allNodes[0], 0);
    // string inOrderTraversal = "";
    // string preOrderTraversal = "";
    // string postOrderTraversal = "";
    // inOrder(allNodes[0], inOrderTraversal);
    // cout << endl
    //      << "InOrder Traversal :" << inOrderTraversal << endl;
    // preOrder(allNodes[0], preOrderTraversal);
    // cout << endl
    //      << "PreOrder Traversal :" << preOrderTraversal << endl;
    // postOrder(allNodes[0], postOrderTraversal);
    // cout << endl
    //      << "PostOrder Traversal :" << postOrderTraversal << endl;

    int n;
    cin>>n;
    int preOrderA[n],inOrderA[n];
    for (int i = 0; i < n; i++)
    {
        cin >> preOrderA[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inOrderA[i];
    }

    treeNode *root = buildTreePreIn(preOrderA,inOrderA,0,n-1);
    string preOrderTraversal = "";
    preOrder(root, preOrderTraversal);
    cout << "\n " << preOrderTraversal << endl;
    return 0;
}

/*
Preorder + InOrder

Preorder => select the Node
InOrder  =>  TAKE NODE POSITION


PRE-> 0 1 3 4 2 5 7 8 6
In->  3 1 4 0 7 5 8 2 6

input:

9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6

 */