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


void replaceAndDisplay(Node *n)
{
    while (n != NULL)
    {
        /* Replace the even number */
        if (n->value%2==0)
        {
            cout << -1;
        }else{
            cout << n->value;
        }
        
        if (n->Next!=NULL)
        {
           cout << " -> ";
        }
        
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
    replaceAndDisplay(head);

    return 0;
}
