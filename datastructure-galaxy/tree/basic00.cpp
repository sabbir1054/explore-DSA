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

treeNode* invert_tree(treeNode *root)
{
    if (root == NULL)
        return root;
    else
    {
        treeNode *temp;

        /* do the subtrees */
        invert_tree(root->leftChild);
        invert_tree(root->rightChild);

        /* swap the pointers in this node */
        temp = root->leftChild;
        root->leftChild = root->rightChild;
        root->rightChild = temp;
    }
    return root;
}

/* Recursive function to calculate Tilt of
whole tree */
int traverse(treeNode *root, int *tilt)
{
    if (!root)
        return 0;

    int left = traverse(root->leftChild, tilt);
    int right = traverse(root->rightChild, tilt);
    *tilt += abs(left - right);

    // Returns sum of nodes under current tree
    return left + right + root->data;
}
/* Driver function to print Tilt of whole tree */
int findTilt(treeNode *root)
{
    int tilt = 0;
    traverse(root, &tilt);
    return tilt;
}

void average_level(treeNode *root)
{

    // Traversing level by level
    queue<treeNode *> q;
    q.push(root);

    while (!q.empty())
    {

        // Compute sum of nodes and
        // count of nodes in current
        // level.
        int sum = 0, count = 0;
        queue<treeNode *> temp;
        while (!q.empty())
        {
            treeNode *n = q.front();
            q.pop();
            sum += n->data;
            count++;
            if (n->leftChild != NULL)
                temp.push(n->leftChild);
            if (n->rightChild != NULL)
                temp.push(n->rightChild);
        }
        q = temp;
        cout << (sum * 1.0 / count) << " ";
    }
}
bool is_unival(treeNode *root)
{
    if (!root)
    {
        return true;
    }
    if (root->leftChild != NULL && root->data != root->leftChild->data)
    {
        return false;
    }

    if (root->rightChild != NULL && root->data != root->rightChild->data)
    {
        return false;
    }

    return is_unival(root->leftChild) && is_unival(root->rightChild);
}
int second_Minimum(treeNode *root)
{
    // When the root is null
    if (!root)
    {
        return -1;
    }

    if (!root->leftChild && !root->rightChild)
    {
        return -1;
    }
    // Storing the Node value of the left
    // child of the Node
    auto left = root->leftChild->data;

    // Storing the Node value of the right
    // child of the Node
    auto right = root->rightChild->data;

    if (root->data == root->leftChild->data)
    {
        left = second_Minimum(root->leftChild);
    }

    if (root->data == root->rightChild->data)
    {
        right = second_Minimum(root->rightChild);
    }

    if (left != -1 && right != -1)
    {
        return min(left, right);
    }

    else if (left != -1)
    {
        return left;
    }

    else
    {
        return right;
    }
}
// function to print the zigzag traversal
void zigzag_order(treeNode *root)
{
    // if null then return
    if (!root)
        return;

    // declare two stacks
    stack<treeNode *> currentlevel;
    stack<treeNode *> nextlevel;

    // push the root
    currentlevel.push(root);

    // check if stack is empty
    bool lefttoright = true;
    while (!currentlevel.empty())
    {

        // pop out of stack
        treeNode *temp = currentlevel.top();
        currentlevel.pop();

        // if not null
        if (temp)
        {

            // print the data in it
            cout << temp->data << " ";

            // store data according to current
            // order.
            if (lefttoright)
            {
                if (temp->leftChild)
                    nextlevel.push(temp->leftChild);
                if (temp->rightChild)
                    nextlevel.push(temp->rightChild);
            }
            else
            {
                if (temp->rightChild)
                    nextlevel.push(temp->rightChild);
                if (temp->leftChild)
                    nextlevel.push(temp->leftChild);
            }
        }

        if (currentlevel.empty())
        {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}
int main(int argc, char const *argv[])
{

    treeNode *root = new treeNode(4);
    root->leftChild = new treeNode(2);
    root->rightChild = new treeNode(7);
    root->leftChild->leftChild = new treeNode(1);
    root->leftChild->rightChild = new treeNode(3);
    root->rightChild->leftChild = new treeNode(6);
    root->rightChild->rightChild = new treeNode(9);
    /*
        root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
     */
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
    // inOrder(root, inOrderTraversal);
    // cout << endl
    //      << "InOrder Traversal :" << inOrderTraversal << endl;
    // invert_tree(root);
    // string check = "";
    // inOrder(root, check);
    // cout << endl
    //      << check;

    // preOrder(allNodes[0], preOrderTraversal);
    // cout << endl
    //      << "PreOrder Traversal :" << preOrderTraversal << endl;
    // postOrder(allNodes[0], postOrderTraversal);
    // cout << endl
    //      << "PostOrder Traversal :" << postOrderTraversal << endl;
    // int sum = findTilt(root);
    // cout << "Sum is " << sum;
    // average_level(root);

    // if (is_unival(root) == 1)
    // {

    //     cout << "YES";
    // }
    // else
    // {

    //     cout << "NO";
    // }
    // int SecondMinimumValue = second_Minimum(root);
    // cout << SecondMinimumValue << endl;
    cout << "ZigZag Order traversal of binary tree is \n";

    // zigzag_order(allNodes[0]);
    invert_tree(root);
    string inOrderTraversal = "";
    inOrder(root, inOrderTraversal);
    cout << endl
         << "InOrder Traversal :" << inOrderTraversal << endl;

    return 0;
}

/*


10 
11 5 9 43 34 1 2 7 8 21






5
1 3 2
3 -1 -1
2 5 4
5 -1 -1
4 -1 -1


9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

Root : 0
Left :
        Root : 1
        Left : 3
        Right : 4
Right :
        Root : 2
        Left :
                Root : 5
                Left : 7
                Right : 8
        Right : 6


InOrder Traversal :314075826

PreOrder Traversal :013425786

PostOrder Traversal :341785620
 */
