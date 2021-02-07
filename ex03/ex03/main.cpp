#include <stdio.h>
#pragma warning (disable:4996)

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

	Node(data content)
	{
		this->content.dis = content.dis;
		this->content.par = content.par;
		this->content.data = content.data;
	}
};

template <typename T>
class Queue
{
public:
	Node<T> *root;
	int front;
	int rear;

	Queue<T>()
	{
		root = NULL;
		front = -1;
		rear = -1;
	}

	void enqueue(T content)
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

	T dequeue()
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

	int size()
	{
		return (rear - front);
	}
};

int main()
{
	Queue<data> queue;
	data content;
	bool map[7][7];
	bool visited[7] = { false, };
	int flag = 1;

	map[0][1] = true;
	map[0][2] = true;
	map[1][3] = true;
	map[1][4] = true;
	map[3][5] = true;
	map[4][5] = true;
	map[5][6] = true;
	map[2][6] = true;

	content.data = 1;
	content.dis = 0;
	content.par = 0;
	visited[0] = true;
	queue.enqueue(content);

	while (queue.size() && flag)
	{
		flag = 0;
		data temp = queue.dequeue();
		printf("data : %d, parent : %d, distance : %d\n", temp.data, temp.par, temp.dis);
		for (int i = 0; i < 7; i++)
		{
			if (map[temp.data - 1][i] == true && !visited[i])
			{
				data res;
				res.par = temp.data;
				res.data = i + 1;
				res.dis = temp.dis + 1;
				queue.enqueue(res);
				visited[i] = true;
			}
		}
		for (int i = 0; i < 7; i++)
		{
			if (visited[i] == true)
				flag = 1;
		}
	}
}