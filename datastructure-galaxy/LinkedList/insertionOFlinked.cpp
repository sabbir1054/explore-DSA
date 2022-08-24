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
// function declaration
void addTail(Node *&head, int val);
void addHead(Node *&head, int val);
void display(Node *n);
void insertValuePos(Node *&head, int val, int pos);

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
        /* code */
        cout << n->value << " ";
        n = n->Next;
    }
}

void insertValuePos(Node *&head, int val, int pos)
{

    int i = 0;
    Node *temp = head;

    while (i < pos - 2)
    {
        temp = temp->Next;
        i++;
    }

    Node *newNode = new Node(val);
    newNode->Next = temp->Next;
    temp->Next = newNode;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    cout << "Choice List option :" << endl
         << "1->Head Input" << endl
         << "2-> Tail Input " << endl
         << "3-> Insert element specific position: " << endl
         << "4->Exit" << endl
         << endl;
    int choice;
    cout << endl
         << "Choice :";
    cin >> choice;
    while (choice <=3)
    {
        int val;
        

        switch (choice)
        {
        case 1:
            cout << "Please input value :";
            cin >> val;
            addHead(head, val);
            break;
        case 2:
            cout << "Please input value :";
            cin >> val;
            addTail(head, val);
            break;
        case 3:
            int newVal;
            cout << "Enter value :";
            cin >> newVal;
            int pos;
            cout << "Enter position :";
            cin >> pos;
            insertValuePos(head, newVal, pos);
            break;

        default:
            break;
        }

        cout << endl
             << "Choice :";
        cin >> choice;
    }

    display(head);

    return 0;
}
