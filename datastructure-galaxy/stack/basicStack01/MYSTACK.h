#include <bits/stdc++.h>
using namespace std;

template <typename N> class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template <typename S>class Stack
{
    Node <S> *head;
    Node <S> *top;
    Node <S> *middle = NULL;
    int count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }
    // push
    void push(int val)
    {
        Node <S> *newNode = new Node<S>(val);

        if (head == NULL)
        {
            head = top = newNode;
            count++;
            middle = newNode;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        if (count % 2 == 1)
        {
            middle = middle->next;
        }

        count++;
    }

    // pop
    S pop()
    {
        Node <S> *delNode;
        delNode = top;
        if (head == NULL)
        {
            cout << "Stack underflow " << endl;
            return -1;
        }

        if (top == head)
        {
            head = top = NULL;
            middle == NULL;
        }
        else
        {
            top = delNode->prev;
            top->next = NULL;
            if (count % 2 == 0)
            {
                middle = middle->prev;
            }
        }
        int check = delNode->value;
        delete delNode;
        count--;
        return check;
    }
    // empty
    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // top
    S Top()
    {
        S check;
        if (top == NULL)
        {
            cout << "There is no elements " << endl;
            check = -1;
        }
        else
        {
            check = top->value;
        }
        return check;
    }

    // size
    int size()
    {
        return count;
    }

    // middle
    S mid()
    {

        if (count == 0)
        {
            return -1;
        }
        return middle->value;
    }
};
