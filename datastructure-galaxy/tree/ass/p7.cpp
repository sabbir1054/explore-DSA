// CPP Program to find Tilt of Binary Tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to
left child and a pointer to right child */
struct Node
{
    int val;
    struct Node *left, *right;
};

/* Recursive function to calculate Tilt of
whole tree */
int traverse(Node *root, int *tilt)
{
    if (!root)
        return 0;

    // Compute tilts of left and right subtrees
    // and find sums of left and right subtrees
    int left = traverse(root->left, tilt);
    int right = traverse(root->right, tilt);

    // Add current tilt to overall
    *tilt += abs(left - right);

    // Returns sum of nodes under current tree
    return left + right + root->val;
}

/* Driver function to print Tilt of whole tree */
int Tilt(Node *root)
{
    int tilt = 0;
    traverse(root, &tilt);
    return tilt;
}

/* Helper function that allocates a
new node with the given data and
NULL left and right pointers. */
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver code
int main()
{
    /* Let us construct a Binary Tree
        4
    / \
    2 9
    / \ \
    3 5 7 */

    Node *root = NULL;
    root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(9);
    root->left->left = newNode(3);
    root->left->right = newNode(8);
    root->right->right = newNode(7);
    cout << "The Tilt of whole tree is " << Tilt(root);
    return 0;
}
