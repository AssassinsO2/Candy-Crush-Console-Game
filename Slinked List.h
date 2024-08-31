#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include<iostream>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node* next;
    node(T d);
    node(const node& Obj);
};

template <typename T>
class Slist
{
private:
    node<T>* head;

public:
    Slist();

    void insert(T value);
    void display();
    ~Slist();
    bool search(T& value);
};

#endif