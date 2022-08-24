#include<bits/stdc++.h>
using namespace std;

class doublyNode{
    public:
        int value;
        doublyNode *prev;
        doublyNode *next;

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
        /* code */
        head = newNode;
        return;
    }

    doublyNode *temp = head;

    while (temp->next!=NULL)
    {
        /* code */
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}


void addHead(doublyNode* &head,int val){
    doublyNode *newNode = new doublyNode(val);
    if (head == NULL)
    {
        /* code */
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}


void display(doublyNode *n)
{
    while (n != NULL)
    {
        cout << n->value << " ";
        n = n->next;
    }
}

// void displayReverse(doublyNode *&head){
//     doublyNode *temp = head;

//     while (temp=)
//     {
//         /* code */
//     }
    
// }

int main(int argc, char const *argv[])
{
    doublyNode *head = NULL;
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

    display(head);
    return 0;
}
