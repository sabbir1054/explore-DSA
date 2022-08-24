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


struct Test
{
    int pos[1000];
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

void addHead(Node *&head, int val){
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}

Test searchValueDuplicateReturn(Node *&head,int val){
    Node *temp = head;
    Test T;
    int k = 1;
    int count = 1;

    while (temp!=NULL)
    {
        if (temp->value==val)
        {
            T.pos[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.pos[0] = k;
    return T;
}





void display(Node *n){
    while (n!=NULL)
    {
        cout << n->value << " ";
        n = n->Next;
    }

    
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    int choice=1;
    cout << "1: Input Head" << endl
         << "2: Input Tail" << endl
         << "3:Search duplicate " << endl
         << "4: Exit" << endl;

    while (choice<=3)
    {
        cout << "Press :";
        cin >> choice;
        int val;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin>> val;
            addHead(head, val);
            break;
        case 2:
            cout << "Enter value: ";
            cin>> val;
            addTail(head, val);
            break;
        case 3:
            cout << "Enter desired value: ";
            cin>> val;
            Test T;
            T = searchValueDuplicateReturn(head, val);
            if (T.pos[0]==1)
            {
                cout << "Not found";
            }else{
                int size = T.pos[0];

                for (int i = 1; i < size; i++)
                {
                    cout << T.pos[i] << " ";
                }
                

            }
            
            break;
        
        default:
            break;
        }

    }
    
    return 0;
}
