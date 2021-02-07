#include "queue.h"

template <typename T>
Node<T>::Node(T data)
{
	this->data = data;
	this->next = NULL;
}

template <typename T>
Queue<T>::Queue()
{
	root = NULL;
	front = 0;
	rear = 0;
}

template <typename T>
void Queue<T>::enqueue(T data)
{
	Node<T> *newN;
	Node<T> *temp;

	newN = new Node<T>(data);
	temp = root;
	if (!root)
		root = newN;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = newN;
	}
	rear++;
}

template <typename T>
T Queue<T>::dequeue()
{
	Node<T> *temp;
	int flag = 0;
	T res;

	if (root->next)
		temp = root->next;
	else
	{
		flag = 1;
		temp = root;
	}
	res = root->data;
	delete root;
	if (flag)
		root = NULL;
	else
		root = temp;
	rear--;

	return (res);
}

template <typename T>
int Queue<T>::size()
{
	return (rear - front);
}

template <typename T>
void Queue<T>::free()
{
	Node<T> *temp;

	while (root)
	{
		temp = root->next;
		delete root;
		root = temp;
	}
}