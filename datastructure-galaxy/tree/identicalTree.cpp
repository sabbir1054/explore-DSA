// C++ program to see if two trees are identical
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
public:
    int data;
    node *left;
    node *right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

/* Given two trees, return true if they are
structurally identical */
bool isSame(node *root1, node *root2)
{

    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 != NULL && root2 != NULL)
    {
        return (root1->data == root2->data && isSame(root1->left, root2->left) && isSame(root1->right, root2->right));
    }

    return false;
}

/* Driver code*/
int main()
{
    node *root1 = newNode(1);
    node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    // Function call
    if (isSame(root1, root2))
        cout << "Both trees are identical.";
    else
        cout << "Trees are not identical.";

    return 0;
}

// This code is contributed by rathbhupendra
