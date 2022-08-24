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
        cout << n->value;
        if (n->Next != NULL)
        {
            cout << " -> ";
        }
        n = n->Next;
    }
}

// count list
int length(Node *n)
{
    int count = 0;
    while (n != NULL)
    {
        count++;
        n = n->Next;
    }
    return count;
}

// delete at head
void deleteHead(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "Nothing to delete";
    }
    else
    {
        head = temp->Next;
        delete temp;
    }
}

// delete at tail
void deleteTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL)
    {
        if (temp->Next != NULL)
        {
            while (temp->Next->Next != NULL)
            {
                temp = temp->Next;
            }
            Node *delNode = temp->Next;
            temp->Next = NULL;
            delete delNode;
        }
        else
        {
            cout << "There are only one value so delete that";
            deleteHead(head);
        }
    }
    else
    {
        cout << "Not value in list";
    }
}

// delete specific position
void deletePosition(Node *&head, int pos)
{
    int lengthList = length(head);
    Node *temp = head;
    int i = 1;
    if (temp != NULL)
    {
        if (pos > lengthList)
        {
            cout << "Position is out of range";
        }
        else if (pos == 1)
        {
            deleteHead(head);
        }
        else if (lengthList == pos)
        {
            deleteTail(head);
        }
        else
        {
            while (i < pos - 1)
            {
                temp = temp->Next;
                i++;
            }

            Node *delNode = temp->Next;
            temp->Next = delNode->Next;

            delete delNode;
        }
    }
    else
    {
        cout << "No data in list" << endl;
    }
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    int size, num_of_tra, num_of_delete;
    cin >> size >> num_of_tra >> num_of_delete;

    // make list
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        addTail(head, val);
    }

    // traversing and deleting
    int pos = num_of_tra;
    int newSize = length(head);
    while (pos < newSize)
    {
        for (int i = 0; i < num_of_delete; i++)
        {
            deletePosition(head, pos + 1);
            newSize = length(head);
        }
        pos = pos + num_of_tra;
    }

    // after delete new list
    display(head);

    return 0;
}
