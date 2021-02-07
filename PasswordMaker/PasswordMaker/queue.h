#ifndef QUEUE_H
# define QUEUE_H

# include <stdio.h>
# pragma warning (disable : 4996)

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;

	Node(T data);
};

template <typename T>
class Queue
{
public:
	Node<T> *root;
	int front;
	int rear;

	Queue();
	void enqueue(T data);
	T dequeue();
	int size();
	void free();
};

#endif
