#include <stdio.h>
#pragma warning (disable:4996)

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;

	Node(T data)
	{
		this->data = data;
		this->next = NULL;
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

	void enqueue(T data)
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

	T dequeue()
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

	int size()
	{
		return (rear - front);
	}

	void free()
	{
		Node<T> *temp;

		while (root)
		{
			temp = root->next;
			delete root;
			root = temp;
		}
	}
};

int main()
{
	int test_c = 1;
	char map[16][16];
	int py[4] = { -1, 1, 0, 0 };
	int px[4] = { 0, 0, -1, 1 };

	while (test_c <= 10)
	{
		Queue<int> queue;
		int flag = 0;
		scanf("%d", &test_c);
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				scanf(" %c ", &map[i][j]);
				if (map[i][j] == '2')
				{
					queue.enqueue(i);
					queue.enqueue(j);
					map[i][j] = 1;
				}
			}
		}
		while (queue.size() && !flag)
		{
			int temp_r = queue.dequeue();
			int temp_c = queue.dequeue();
			for (int i = 0; i < 4; i++)
			{
				if (temp_r + py[i] >= 0 && temp_r + py[i] <= 15 && temp_c + px[i] >= 0 && temp_c + px[i] <= 15 && map[temp_r + py[i]][temp_c + px[i]] != '1')
				{
					if (map[temp_r + py[i]][temp_c + px[i]] == '3')
						flag = 1;
					queue.enqueue(temp_r + py[i]);
					queue.enqueue(temp_c + px[i]);
					map[temp_r + py[i]][temp_c + px[i]] = '1';
				}
			}
		}
		if (flag == 1)
			printf("#%d 1\n", test_c);
		else
			printf("#%d 0\n", test_c);
		queue.free();
		test_c++;
	}
}