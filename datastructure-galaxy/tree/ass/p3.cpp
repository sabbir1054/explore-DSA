// A recursive C++ program to print
// REVERSE level order traversal
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left and right child */
class node
{
public:
    int data;
    node *left;
    node *right;
};

/*Function prototypes*/
void printGivenLevel(node *root, int level);
int height(node *node);
node *newNode(int data);

/* Function to print REVERSE
level order traversal a tree*/
// calculate height of tree
int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* calculate subtree height*/
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        /* use the larger one */
        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}
/* Print nodes at a given level */
void printGivenLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

// level order traversal function
void level_order_reverse(node *root)
{
    int h = height(root);
    int i;
    for (i = h; i >= 1; i--)
    { 
        printGivenLevel(root, i);
    }
}




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

/* Driver code*/
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    level_order_reverse(root);

    return 0;
}

// This code is contributed by rathbhupendra
