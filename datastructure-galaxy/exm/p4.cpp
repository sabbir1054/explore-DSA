#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    int value;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(int val)
    {
        value = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void insert(treeNode *root, int value);
treeNode *deletion(treeNode *root, int key);
int getMaximum(treeNode *root);


void insert(treeNode *root, int value)
{
    if (root == NULL)
    {
        root = new treeNode(value);
        return;
    }
    queue<treeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        treeNode *currentNode = q.front();
        q.pop();

        if (currentNode->leftChild != NULL)
        {
            q.push(currentNode->leftChild);
        }
        else
        {
            currentNode->leftChild = new treeNode(value);
            return;
        }

        if (currentNode->rightChild != NULL)
        {
            q.push(currentNode->rightChild);
        }
        else
        {
            currentNode->rightChild = new treeNode(value);
            return;
        }
    }
}

int getMaximum(treeNode *root)
{

    // Base case

    if (root == NULL)
    {
        return INT_MIN;
    }

    int res = root->value;

    int leftRes = getMaximum(root->leftChild);

    int rightRes = getMaximum(root->rightChild);

    if (leftRes > res)

        res = leftRes;

    if (rightRes > res)

        res = rightRes;

    return res;
}

treeNode *deletion(treeNode *root, int key)
{

    if (root == NULL)

        return NULL;

    if (root->leftChild == NULL && root->rightChild == NULL)
    {

        if (root->value == key)

            return NULL;

        else

            return root;
    }

    treeNode *key_treeNode = NULL;

    treeNode *temp;

    treeNode *last;

    queue<treeNode *> q;

    q.push(root);


    while (!q.empty())
    {

        temp = q.front();

        q.pop();

        if (temp->value == key)

            key_treeNode = temp;

        if (temp->leftChild)
        {

            last = temp; // storing the parent treeNode

            q.push(temp->leftChild);
        }

        if (temp->rightChild)
        {

            last = temp; // storing the parent treeNode

            q.push(temp->rightChild);
        }
    }

    if (key_treeNode != NULL)
    {

        key_treeNode->value = temp->value;
        // replacing key_treeNode's data to deepest treeNode's data

        if (last->rightChild == temp)

            last->rightChild = NULL;

        else

            last->leftChild = NULL;

        delete (temp);
    }

    return root;
}




int main()
{
    int r;
    cin >> r;
    treeNode *root = NULL;
    root = new treeNode(r);
    queue<treeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        treeNode *currentNode = q.front();
        q.pop();
        int l,
            r;
        cin >> l >> r;
        treeNode *n1 = NULL,
             *n2 = NULL;
        if (l != -1)
        {
            n1 = new treeNode(l);
        }

        if (r != -1)
        {
            n2 = new treeNode(r);
        }

        currentNode->leftChild = n1;
        currentNode->rightChild = n2;

        if (n1 != NULL)
        {
            q.push(n1);
        }
        if (n2 != NULL)
        {
            q.push(n2);
        }
    }
    string output = "";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        int max;
        if (q == 2)
        {
            max = getMaximum(root);
            output += to_string(max) + "\n";
            treeNode *DeletedNode = deletion(root, max);
        }
        else
        {
            int val;
            cin >> val;
            insert(root, val);
        }
    }
    cout << output;
    return 0;
}
