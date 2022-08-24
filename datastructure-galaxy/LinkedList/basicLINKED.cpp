#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node *Next;
};
void display(Node * n){

    while (n!=NULL)
    {
        cout << n->value << " -> ";
        n = n->Next;
    }
    
}
int main(int argc, char const *argv[])
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    head->value = 1;
    second->value = 2;
    third->value = 3;
    fourth->value = 4;

    head->Next = second;
    second->Next = third;
    third->Next = fourth;
    fourth->Next = NULL;
                   
      display(head);
  return 0;
}
