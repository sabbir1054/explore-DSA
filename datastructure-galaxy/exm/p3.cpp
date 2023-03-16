#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
    char value;
    treeNode *left, *right;
    treeNode(char val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

void searchPath(treeNode *root, string &output, int &total)
{
    if (root == NULL)
        return;
    output += root->value;

    searchPath(root->left, output, total);
    searchPath(root->right, output, total);

    if (root->left == NULL && root->right == NULL)
    {
        string st = output;
        reverse(st.begin(), st.end());
        if (st == output)
        {
            total++;
        }
    }

    output.pop_back();
}

int main()
{
    string str;
    cin >> str;

    int r;
    cin >> r;

    treeNode *root = NULL;
    root = new treeNode(str[r]);
    queue<treeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        treeNode *currentNode = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        treeNode *leftNode = NULL;
        treeNode *rightNode = NULL;

        if (l != -1)
        {
            leftNode = new treeNode(str[l]);
        }

        if (r != -1)
        {
            rightNode = new treeNode(str[r]);
        }

        currentNode->left = leftNode;
        currentNode->right = rightNode;

        if (leftNode != NULL)
        {
            q.push(leftNode);
        }

        if (rightNode != NULL)
        {
            q.push(rightNode);
        }
    }

    string output = "";
    int total = 0;

    searchPath(root, output, total);
    cout << total << endl;
}