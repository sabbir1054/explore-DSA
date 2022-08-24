#include<bits/stdc++.h>
using namespace std;

class doublyNode{
    public:
        int value;
        doublyNode *next;
        doublyNode *prev;

        doublyNode(int val){
            value = val;
            prev = NULL;
            next = NULL;
        }
};

void addTail(doublyNode *&head,int val){
    doublyNode *newNode = new doublyNode(val);

    if (head==NULL)
    {
        head = newNode;
        return;
    }

    doublyNode *temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void addHead(doublyNode *&head,int val){
    doublyNode *newNode = new doublyNode(val);
    if (head==NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void display(doublyNode *n){
    while (n!=NULL)
    {
        cout << n->value << " ";
        n = n->next;
    }
    
}

void reverseDoubly(doublyNode *&head){
    doublyNode* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp!=NULL)
    {
        cout << temp->value<<" ";
       
            temp = temp->prev;
    }
    
}

int main(int argc, char const *argv[])
{

    doublyNode *head = NULL;
    cout << "Enter Choice number :" << endl
         << "01 . Insert Head " << endl
         << "02 . Insert Tail " << endl
         << "03 . Display and Exit" << endl;
    int choice;
    cout << "Enter choice number : ";
    cin >> choice;
    while (choice!=3)
    {
        int val;
        cout << "Input value :" << endl;
        cin >> val;

        switch (choice)
        {
        case 1:
            /* code */
            addHead(head, val);
            break;
        case 2:
            /* code */
            addTail(head, val);
            break;
        
        default:
            break;
        }

        cout << "Enter choice number : ";
        cin >> choice;
    }
    display(head);
    cout << "\n Reverse \n";
    reverseDoubly(head);

    return 0;
}
