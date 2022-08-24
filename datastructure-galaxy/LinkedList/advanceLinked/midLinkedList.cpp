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
        /* code */
        cout << n->value << " ";
        n = n->Next;
    }
}

int findMid(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while (fast->Next!=NULL)
    {
        slow = slow->Next;
        fast = fast->Next->Next;
    }
    return slow->value;
}


int main(int argc, char const *argv[])
{
    Node *head = NULL;
    cout << "Choice \n1->Head Input \n2-> Tail Input \n3-> Exit\n Enter Choice number : ";
    int choice;
    cout << endl
         << "Choice :";
    cin >> choice;
    while (choice == 1 || choice == 2)
    {
        int val;
        cout << "Please input value :";
        cin >> val;

        switch (choice)
        {
        case 1:
            addHead(head, val);
            break;
        case 2:
            addTail(head, val);
            break;

        default:
            break;
        }

        cout << endl
             << "Choice :";
        cin >> choice;
    }

    display(head);
    cout << endl;
    int mid=findMid(head);
    cout << mid;

    return 0;
}
