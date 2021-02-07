#include "queue.h"

template <typename T>
Node<T>::Node(data content)
{
	this->content.dis = content.dis;
	this->content.par = content.par;
	this->content.data = content.data;
}

template <typename T>
Queue<T>::Queue()
{
	root = NULL;
	front = 0;
	rear = 0;
}

template <typename T>
void Queue<T>::enqueue(T content)
{
	Node<T> *newN;
	Node<T> *temp;

	newN = new Node<T>(content);
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
	data res;
	int flag = 0;

	if (root->next)
		temp = root->next;
	else
	{
		flag = 1;
		temp = root;
	}
	res.data = root->content.data;
	res.dis = root->content.dis;
	res.par = root->content.par;
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