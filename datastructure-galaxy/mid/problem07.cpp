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
//add value to list
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

//print the list
void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next!=NULL)
        {
            cout << " -> ";
        }
        
        n = n->Next;
    }
}

// reverse with non recursive
Node *reverse(Node *&head,int k)
{
    
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;
    

    if (head == NULL)
    {
        return head;
    }

    while (current != NULL && count < k)
    {
        next = current->Next;
        current->Next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next!=NULL){
        head->Next = reverse(next, k);
    }

    return prev;
}




int main(int argc, char const *argv[])
{
    Node *head = NULL;
    int size, k;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        addTail(head, val);
    }
    cin >> k;

    head=reverse(head, k);
    display(head);

    return 0;
}
