#include"Slinked List.h"

template <typename T>
node<T>::node(T d)
{
    data = d;
    next = nullptr;
}

template <typename T>
node<T>::node(const node& Obj)
{
    data = Obj.data;
}

template <typename T>
Slist<T>::Slist()
{
    head = nullptr;
}

template <typename T>
void Slist<T>::insert(T value)
{
    node<T>* newNode = new node<T>(value);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template <typename T>
void Slist<T>::display()
{
    node<T>* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
Slist<T>::~Slist()
{
    node<T>* temp = head;
    while (temp)
    {
        node<T>* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}

template <typename T>
bool Slist<T>::search(T& value)
{
    node<T>* temp = head;
    while (temp)
    {
        if (temp->data == value)
        {
            return true; // Value found
        }
        temp = temp->next;
    }
    return false; // Value not found
}