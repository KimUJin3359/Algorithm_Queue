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

	Queue<T>()
	{
		root = NULL;
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
	}

	T dequeue()
	{
		Node<T> *temp;
		int res;
		int flag = 0;

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

		return (res);
	}

	int size()
	{
		Node<T> *temp;
		int i = 0;

		temp = root;
		while (temp)
		{
			i++;
			temp = temp->next;
		}

		return (i);
	}
};

int main()
{
	int test_c = 1;
	int flag = 0;
	int data;
	
	while (test_c <= 10)
	{
		Queue<int> queue;

		scanf("%d", &test_c);
		for (int i = 0; i < 8; i++)
		{
			scanf("%d", &data);
			queue.enqueue(data);
		}
		while (!flag)
		{
			for (int i = 1; i <= 5; i++)
			{
				int deq = queue.dequeue() - i;
				if (deq <= 0)
				{
					deq = 0;
					flag = 1;
				}
				queue.enqueue(deq);
				if (flag)
					break;
			}
		}
		printf("#%d ", test_c);
		while (queue.size())
			printf("%d ", queue.dequeue());
		printf("\n");
		test_c++;
		flag = 0;
	}
}


