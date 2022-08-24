#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node *Next;
        Node(int val){
            value = val;
            Next = NULL;
        }
    
};

void addTail(Node *&head,int val){
    Node *newNode = new Node(val);
    if (head==NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next!=NULL)
    {
        temp = temp->Next;
        
    }
    temp->Next = newNode;
}
void addHead(Node *&head,int val){
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}

void display(Node *n){
    while (n!=NULL)
    {
        /* code */
        cout << n->value << " ";
        n = n->Next;
    }
    
}

void length(Node *n){
    int count = 0;
    while (n!=NULL)
    {
        count++;
        n = n->Next;
    }
    cout << endl
         << count;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;

    int choice = 2;
    while (choice==1||choice==2)
    {
        int val;
        cout << "Please input value :";
        cin >> val;
        if (choice==1)
        {
            addHead(head, val);

        }else if (choice==2)
        {
            addTail(head, val);
        }
        cout << "Press 1->Head Input 2-> Tail Input 3-> Exit: ";
        cin >> choice;
    }

    display(head);
    length(head);
    return 0;
}
