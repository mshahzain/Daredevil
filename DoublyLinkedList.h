#include <iostream>
#include <cstdlib>
#pragma once
using namespace std;

template <class T>
class DoublyLinkedList
{
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void Add(T);
        void Remove();
        T RemoveVal(T);
        void Show();

    private:
        struct Node
        {
            T data;
            Node* next;
            Node* prev;
        };
        int length;
        Node* head;
        Node* tail;
};
