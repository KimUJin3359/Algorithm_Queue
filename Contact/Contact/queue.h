#ifndef QUEUE_H
# define QUEUE_H

# include <stdio.h>
# pragma warning (disable : 4996)

typedef struct
{
	int dis;
	int par;
	int data;
}data;

template <typename T>
class Node
{
public:
	data content;
	Node<T>* next;

	Node(data content);
};

template <typename T>
class Queue
{
public:
	Node<T> *root;
	int front;
	int rear;

	Queue();
	void enqueue(T content);
	T dequeue();
	int size();
};

#endif
