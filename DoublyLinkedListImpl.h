#include <iostream>
#include <cstdlib>
#include "DoublyLinkedList.h"

using namespace std;

template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
}


template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
}



template<class T>
void DoublyLinkedList<T>::Add(T val)
{
    if (head == NULL)
    {
        head = new Node;
        head -> prev = NULL;
        head -> data = val;
        head -> next = NULL;
        tail = head;
    }
    else
    {
        tail -> next = new Node;
        tail -> next -> prev = tail;
        tail -> next -> next = NULL;
        tail -> next -> data = val;
        tail = tail -> next;
    }
}


template<class T>
void DoublyLinkedList<T>::Remove()
{
    if (head == NULL)
    {
        return;
    }
    if (head == tail)
    {

        delete head;
        head = tail = NULL;

    }
    else if(head != NULL)
    {
        head = head -> next;
        delete head -> prev;
        head -> prev = NULL;
    }
}

template<class T>
void DoublyLinkedList<T>::Show()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << endl;
        temp = temp -> next;
    }
}
