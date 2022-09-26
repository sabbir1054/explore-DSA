
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
    check += (to_string(root->data)) + " ";
    inOrder(root->rightChild, check);
}

// insert
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
    else if (value > root->data)
    {
        root->rightChild = insertionBST(root->rightChild, value);
    }
    return root;
}

// search a node

treeNode *searchBST(treeNode *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == value)
    {
        /* code */
        cout << root->data << " ";
        return root;
    }
    else if (value < root->data)
    {
        cout << root->data << "->";
        searchBST(root->leftChild, value);
    }
    else
    {
        cout << root->data << "->";
        searchBST(root->rightChild, value);
    }
}
// search inOrder succeser
treeNode *inOrderSucc(treeNode *root)
{
    treeNode *curr = root;

    while (curr->leftChild != NULL)
    {
        /* code */
        curr = curr->leftChild;
    }
    return curr;
}
// delete bst
treeNode *deleteBST(treeNode *root, int value)
{
    if (value < root->data)
    {
        root->leftChild = deleteBST(root->leftChild, value);
    }
    else if (value > root->data)
    {
        root->rightChild = deleteBST(root->rightChild, value);
    }
    else
    {
        // Implementation of 3 cases

        if (root->leftChild == NULL)
        {
            treeNode *temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            treeNode *temp = root->leftChild;
            free(root);
            return temp;
        }
        else
        {
            treeNode *temp = inOrderSucc(root->rightChild);
            root->data = temp->data;
            root->rightChild = deleteBST(root->rightChild, temp->data);
        }
    }
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

    // int searchValue;
    // cout << "Enter value for search: ";
    // cin >> searchValue;
    // if (searchBST(root, searchValue) == NULL)
    // {
    //     cout << "\nValue does not exist";
    // }
    // else
    // {
    //     cout << "Value Exist .\n";
    // }
    int deletedValue;
    cout << "Enter value for delete: ";
    cin >> deletedValue;
    root = deleteBST(root, deletedValue);

    string after = "";
    inOrder(root, after);
    cout << endl
         << after << endl;

    return 0;
}

/*

9
11 5 9 43 34 1 2 7 21

 */