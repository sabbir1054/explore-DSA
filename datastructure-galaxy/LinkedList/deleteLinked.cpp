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
// function initialization
void insertHead(Node *&head, int val);
void insertTail(Node *&head, int val);
int searchValueUnique(Node *&head, int val);
void searchValueDuplicate(Node *&head, int val);
void display(Node *n);

// functions definations
void insertHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}
void insertTail(Node *&head, int val)
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
        cout << n->value << " ";
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

// searching from uniq list
int searchValueUnique(Node *&head, int val)
{
    Node *temp = head;
    int count = 1;

    if (temp == NULL)
    {
        return -1;
    }

    while (temp->value != val)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }

        temp = temp->Next;
        count++;
    }

    return count;
}

// searching in duplicate value
void searchValueDuplicate(Node *&head, int val)
{
    Node *temp = head;
    int size;
    size = length(head);
    int position[size + 1], k = 1;
    int count = 1;
    int flag = 0;

    while (temp != NULL)
    {
        if (temp->value == val)
        {
            position[k] = count;
            k++;
            flag = 1;
        }

        temp = temp->Next;
        count++;
    }

    cout << endl;
    if (flag == 0)
    {
        cout << "Value not found " << endl;
    }
    else
    {
        position[0] = k;
        for (int i = 1; i < position[0]; i++)
        {
            cout << position[i];
            if (i < position[0] - 1)
            {
                cout << ",";
            }
        }
    }
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
        if (temp->Next!=NULL)
        {
            while (temp->Next->Next != NULL)
            {
                temp = temp->Next;
            }
            Node *delNode = temp->Next;
            temp->Next = NULL;
            delete delNode;
        }else{
            cout << "There are only one value so delete that";
            deleteHead(head);
        }
        
        
    }
    else
    {
        cout << "Not value in list";
    }
}



//delete specific position
void deletePosition(Node *&head,int pos){
    int lengthList = length(head);
    Node *temp = head;
    int i=1;
   if (temp!=NULL)
   {
       if(pos>lengthList){
           cout << "Position is out of range";
       }
       else if (pos == 1)
       {
           deleteHead(head);
         
       }
       else if (lengthList==pos)
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

    cout << "Choice List :" << endl
         << "1 = Input Head" << endl
         << "2 = Input Tail" << endl
         << "3 = Delete 1st element " << endl
         << "4 = Delete last element " << endl
         << "5 = Delete desired position " << endl
         << "6 = Exit program ";
    int choice = 1;
    while (choice <= 5)
    {
        // take choice
        cout << endl
             << "Enter Choice Number :";
        cin >> choice;
        int val;
        int pos;
        switch (choice)
        {
        case 1:

            cout << "Input value :";
            cin >> val;
            insertHead(head, val);
            break;
        case 2:

            cout << "Input value :";
            cin >> val;
            insertTail(head, val);
            break;
        case 3:

            deleteHead(head);

            break;
        case 4:

            deleteTail(head);
            break;
        case 5:
            
           
            cout << "Inter position ";
            cin >> pos;
            //past list
            cout << endl
                 << "Past List  :";
            display(head);
            // delete
            deletePosition(head, pos);
            //present list
            cout << endl
                 << "Present List :";
            display(head);

            break;

        default:
            break;
        }
    }

    cout << endl
         << "List is :";
    display(head);

    return 0;
}
