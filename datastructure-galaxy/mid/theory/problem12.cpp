#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

void addTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void display(Node *n)
{
    while (n != NULL)
    {

        // int checkedValue = n->value;
        // Node *newNode = n;
        // while (newNode != NULL)
        // {
        //     int pass = 0;
        //     if (newNode->value == checkedValue)
        //     {
        //         pass = 1;
        //         newNode = newNode->Next;
        //     }
        //     else
        //     {
        //         if (checkedValue + newNode->value == 0)
        //         {
        //             newNode = newNode->Next;
        //         }
        //         else
        //         {
        //             cout << checkedValue + newNode->value << " ";
        //             newNode = newNode->Next;
        //         }
        //     }
        // }
        // cout << endl;

        cout << n->value;

        // if (n->Next != NULL)
        // {
        //     cout << " -> ";
        // }

        n = n->Next;
    }
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;

    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        addTail(head, val);
    }
    display(head);

    return 0;
}

/*
8
6 -6 8 4 -12 9 8 -8

 */

