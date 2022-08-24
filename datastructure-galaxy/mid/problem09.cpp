#include <bits/stdc++.h>
using namespace std;

// singly linked list part
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
//singly linked list tail input
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

// doubly linked list part
class doublyNode
{
public:
    int value;
    doublyNode *next;
    doublyNode *prev;

    doublyNode(int val)
    {
        value = val;
        prev = NULL;
        next = NULL;
    }
};
//doubly linked list tail input
void addTailD(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    doublyNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
//doubly linked list head input
void addHeadD(doublyNode *&head, int val)
{
    doublyNode *newNode = new doublyNode(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
// display previous and next value
void display(doublyNode *n, int val)
{
    while (n->value != val)
    {
        n = n->next;
    }
    if (n->prev == NULL)
    {
        cout << 0 << " " << n->next->value << endl;
    }
    else if (n->next == NULL)
    {
        cout << n->prev->value << " " << 0 << endl;
    }
    else
    {
        cout << n->prev->value << " " << n->next->value << endl;
    }
}
//main function
int main(int argc, char const *argv[])
{

    doublyNode *head = NULL;
    Node *headN1 = NULL;
    Node *headN2 = NULL;
    int size;
    cin >> size;
// make singly linked list
    for (int i = 0; i < size; i++)
    {
        int p, q;
        cin >> p >> q;
        addTail(headN1, p);
        addTail(headN2, q);
    }
// make doubly linked list
    int i = 1;
    while (headN1 != NULL)
    {
        if (headN1->Next == NULL)
        {
            addTailD(head, headN1->value);
            addTailD(head, i);
        }
        if (headN1->value == 0)
        {
            if (headN2->value == 0)
            {
                addHeadD(head, i);
            }
            else
            {
                addTailD(head, i);
                addTailD(head, headN2->value);
            }
        }
        headN1 = headN1->Next;
        headN2 = headN2->Next;
        i++;
    }
//display function call
    for (int k = 1; k <= size; k++)
    {
        display(head, k);
    };

    return 0;
}
