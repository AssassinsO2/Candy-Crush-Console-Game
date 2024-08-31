#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;

template<class T>
class queue
{
	static const int max = 15;
	T array[max];
	int front, rear;
public:
	queue();
	void enqueue(T v);
	void dequeue();
	bool isEmpty();
	bool isFull();
	int GetCurrentSize();
	T peek();
};
#endif