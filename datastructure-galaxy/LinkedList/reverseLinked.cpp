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

void addHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}

void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value << " ";
        n = n->Next;
    }
}

// reverse with non recursive
Node *reverse1(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;

    if (head==NULL)
    {
        cout << "List is empty " << endl;
        return head;
    }
    Node *next = head->Next;

    while (true)
    {
        /* code */
        current->Next = prev;
        prev = current;
        current = next;
        if (current == NULL)
        {
            break;
        }
        next = next->Next;
    }

    return prev;
}
//reverse with recursive
Node* reverse2(Node *&head){
    if (head==NULL||head->Next==NULL)
    {
        if (head==NULL)
        {
            /* code */
            cout << "List is empty";
        }
        
        return head;
    }
    Node *newHead=reverse2(head->Next);
    head->Next->Next = head;
    head->Next = NULL;

    return newHead;
}
int main(int argc, char const *argv[])
{
    Node *head = NULL;
    cout << "Enter Choice number :" << endl
         << "01 . Insert Head " << endl
         << "02 . Insert Tail " << endl
         << "03 . Display and Exit" << endl;
    int choice;
    cout << "Enter your choice :";
    cin >> choice;
    while (choice < 3)
    {
        int val;
        cout << "Enter value :";
        cin >> val;
        if (choice == 1)
        {
            addHead(head, val);
        }
        else if (choice == 2)
        {
            addTail(head, val);
        }
        cout << "Enter your choice :";
        cin >> choice;
    }
    // normal list
    display(head);
    cout << endl
         << endl
         << "Reverse List " << endl;
    // reverse list
    head = reverse2(head);
    display(head);

    return 0;
}
