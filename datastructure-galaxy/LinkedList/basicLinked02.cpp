
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

void insertAtTail(Node* &head, int val){
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
void display(Node * n){

    while (n!=NULL)
    {
        cout << n->value << "  ";
        n = n->Next;
    }
    
}
int main(int argc, char const *argv[])
{
    Node *head = NULL;
    
    char choice = 'Y';
    while (choice=='Y'||choice=='y')
    {

        int num;
        cin >> num;
        insertAtTail(head, num);
        cout << "Do you want to add more value (Y/N) ? : ";
        cin >> choice;
   }
 
   display(head);
   return 0;
}
