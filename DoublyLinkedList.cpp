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
    //dtor
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
T DoublyLinkedList<T>::Remove()
{
    T ret;
    if (head == NULL)
    {
        return -1;
    }
    if (head == tail)
    {

        ret = head -> data;
        delete head;
        head = tail = NULL;

    }
    else if(head != NULL)
    {
        ret = head -> data;
        head = head -> next;
        delete head -> prev;
        head -> prev = NULL;
    }
    return ret;
}
