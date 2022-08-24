
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
// insert value in tail
void insertAtTail(Node *&head, int val)
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
// insert value in head
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}

// display list
void display(Node *n)
{

    while (n != NULL)
    {
        cout << n->value << "  ";
        n = n->Next;
    }
}
// display list in reverse way
void reverseListPrint(Node *n) // n!= null
{                               //
    if (n == NULL)
    {
        return;
    }
    //
    cout << "step " <<n->value << " ";
    reverseListPrint(n->Next);
    cout << n->value << " ";
}
int main(int argc, char const *argv[])
{
    Node *head = NULL;
    int choice = 2, num;
    while (choice == 1 || choice == 2)
    {
        cout << "Enter the value :";
        cin >> num;
        if (choice == 1)
        {
            insertAtHead(head, num);
        }
        else if (choice == 2)
        {
            insertAtTail(head, num);
        }
        cout << "Next choice (1 for Head input , 2 for tail input, 3 for exit): ";
        cin >> choice;
    }

    cout << "Normal print" << endl;
    display(head);
    cout << endl;
    cout << "Reverse Print" << endl;
    reverseListPrint(head);
    return 0;
}
