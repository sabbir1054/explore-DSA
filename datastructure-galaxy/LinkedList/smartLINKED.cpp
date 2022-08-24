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


int main(int argc, char const *argv[])
{
    Node *head = NULL;
    cout << "Choice 1->Head Input 2-> Tail Input 3-> Exit: ";
    int choice;
    cout << endl
         << "Choice :";
    cin >> choice;
    while (choice==1||choice==2)
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

    return 0;
}
